#include "Renderer.h"

#include <memory>

#include <imgui.h>

#include <glm/gtc/type_ptr.hpp>

#include "Light.h"
#include "GLState.h"
#include "Renderable.h"

Renderer::Renderer(const Window *const window)
	: window{ window }
	, gBuffer{ window->GetFramebufferWidth(), window->GetFramebufferHeight() }
{
	assert(window != nullptr);

	int w, h;
	window->GetFramebufferSize(&w, &h);

	lightAccumulationTexture.Make(w, h, GL_RGBA, GL_RGBA16F);
	lightAccumulationTexture.SetFilter(GL_NEAREST);
	lightAccumulationBuffer.Attach(&lightAccumulationTexture, GL_COLOR_ATTACHMENT0);
	lightAccumulationBuffer.Attach(&gBuffer.depth, GL_DEPTH_ATTACHMENT);
	assert(lightAccumulationBuffer.IsComplete());

	// Make bloom bright pass 2x downsampled from main image
	int ww = w / 2;
	int hh = h / 2;
	bloomBrightPass.Make(ww, hh, GL_RGB, GL_RGB16F);
	bloomBrightPass.SetFilter(GL_LINEAR);
	bloomBrightPassFB.Attach(&bloomBrightPass, GL_COLOR_ATTACHMENT0);

	// Generate bloom blur textures, starting at 4x downsample from bright pass
	ww /= 4;
	hh /= 4;
	for (int i = 0; i < numBloomBlurs; i++)
	{
		int fst = 2 * i;
		int snd = 2 * i + 1;

		// Set up two textures per size to be able to do V+H blur pass per size
		bloomBlurs[fst].Make(ww, hh, GL_RGB, GL_RGB16F);
		bloomBlurs[snd].Make(ww, hh, GL_RGB, GL_RGB16F);

		bloomBlurFBs[fst].Attach(&bloomBlurs[fst], GL_COLOR_ATTACHMENT0);
		assert(bloomBlurFBs[fst].IsComplete());

		bloomBlurFBs[snd].Attach(&bloomBlurs[snd], GL_COLOR_ATTACHMENT0);
		assert(bloomBlurFBs[snd].IsComplete());

		ww /= 2;
		hh /= 2;
	}

	shadowMap.Make(2048, 2048, GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT16);
	shadowMap.SetFilter(GL_NEAREST);
	shadowMap.SetWrap(GL_CLAMP_TO_BORDER);
	shadowMap.SetBorderColor(1, 1, 1, 1);
	shadowMapFramebuffer.Attach(&shadowMap, GL_DEPTH_ATTACHMENT);
	assert(shadowMapFramebuffer.IsComplete());
}

void Renderer::Render(const Scene& scene)
{
	static bool first = true;
	if (first)
	{
		GL::FetchCurrentGLState();

		GL::SetFrontFace(GL_CW);
		GL::SetCullFace(GL_BACK);

		GL::Enable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
		GL::Enable(GL_FRAMEBUFFER_SRGB);

		first = false;
	}

	// All entities that are renderable are considered to be geometry (for now)
	EntityList geometry{};
	scene.GetEntities<Renderable>(geometry);

	EntityList lights{};
	scene.GetEntities<LightComponent>(lights);

	EntityList lightsNew{};
	scene.GetEntities<Light>(lightsNew);

	EntityList cameras{};
	scene.GetEntities<CameraComponent>(cameras);

	RenderCameras(cameras);

	auto mainCamera = scene.GetMainCamera();

	GeometryPass(geometry, *mainCamera);
	//LightPass(scene, geometry, lights, *mainCamera);
	ShadowMapGenerationPass(geometry, lightsNew);
	LightPassNew(scene, geometry, lightsNew, *mainCamera);

	if (scene.GetSkybox())
	{
		DrawSkybox(*mainCamera, *scene.GetSkybox());
	}

	GenerateBloom();

	// Render light accumulation buffer onto screen with final post processing step(like tone mapping etc.)
	window->BindAsDrawFrameBuffer();
	GL::SetDepthTest(false);
	GL::SetBlending(false);

	postProcessShader.Bind();
	postProcessShader.SetUniform("u_texture", lightAccumulationTexture.Bind(0));

	static bool useChromaAb = true;
	static float chromaAbAmount = 2.5f;

	if (ImGui::CollapsingHeader("Final post-process"))
	{
		ImGui::Checkbox("Chromatic Aberration", &useChromaAb);
		ImGui::SliderFloat("Amount", &chromaAbAmount, 0.0f, 20.0f);
	}

	postProcessShader.SetUniform("u_bloom_weights", bloomWeights);
	postProcessShader.SetUniform("u_bloom_1", bloomBlurs[1].Bind(1));
	postProcessShader.SetUniform("u_bloom_2", bloomBlurs[3].Bind(2));
	postProcessShader.SetUniform("u_bloom_master_weight", bloomMasterWeight);

	postProcessShader.SetUniform("u_chroma_ab_amount", (useChromaAb) ? chromaAbAmount : 0.0f);

	ScreenAlignedQuad::Render();
}

void Renderer::GeometryPass(const EntityList& entities, const CameraComponent& camera) const
{
	gBuffer.BindAsRenderTarget();
	GL::SetClearDepth(1.0f);
	GL::SetClearColor(0, 0, 0, 0);
	GL::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GL::SetDepthTest(true);
	GL::SetDepthFunction(GL_LEQUAL);
	GL::SetDepthMask(true);

	GL::SetFaceCulling(true);
	GL::SetBlending(false);

	for (auto entity : entities)
	{
		if (auto renderable = entity->GetComponent<Renderable>())
		{
			auto& transform = entity->GetTransform();

			auto& material = renderable->GetMaterial();
			material->UpdateUniforms(*this, transform, camera);

			renderable->GetMesh()->Render();
		}
	}
}

void Renderer::ShadowMapGenerationPass(const EntityList& geometry, const EntityList& lights)
{

}

void Renderer::LightPass(const Scene& scene, const EntityList& geometry, const EntityList& lights, const CameraComponent& camera) const
{
	lightAccumulationBuffer.BindAsDrawFrameBuffer();

	// Ambient light pass (could be optimized to be done while filling g-buffer)
	ambientShader.Bind();
	ambientShader.SetUniform("u_color", scene.GetAmbientColor());
	gBuffer.BindAsUniform(ambientShader);
	GL::SetDepthTest(false);
	ScreenAlignedQuad::Render();

	for (auto lightEntity : lights)
	{
		auto light = lightEntity->GetComponent<LightComponent>();

		auto lightCamera = light->GetLightCamera(camera, shadowMap.GetSize());
		glm::mat4 lightViewProjection = lightCamera.GetProjectionMatrix() * lightCamera.GetViewMatrix();

		// Render shadow maps if applicable
		if (light->CastsShadows())
		{
			shadowMapFramebuffer.BindAsDrawFrameBuffer();
			GL::SetClearDepth(1.0f);
			GL::Clear(GL_DEPTH_BUFFER_BIT);

			GL::SetDepthMask(true);
			GL::SetDepthTest(true);
			GL::SetDepthFunction(GL_LEQUAL);
			GL::SetFaceCulling(true);

			shadowMapGenerator.Bind();
			shadowMapGenerator.SetUniform("u_view_projecion_matrix", lightViewProjection);

			for (auto entity : geometry)
			{
				shadowMapGenerator.SetUniform("u_model_matrix", entity->GetTransform().GetWorldMatrix());
				entity->GetComponent<Renderable>()->GetMesh()->Render();
			}
		}

		lightAccumulationBuffer.BindAsDrawFrameBuffer();

		// TODO: Logically the depth mask should be false, since I don't want to touch the depth at all from the lights, but I get really strage results if it's false!
		// So I'm not sure... It might be some strange behaviour related to one texture in multiple frame buffers. Find out, somehow...
		// HOWEVER, since depth test is disabled, depth writing is always disabled too, and this works.
		GL::SetDepthTest(false);

		GL::SetFaceCulling(false);

		GL::SetBlending(true);
		GL::SetBlendEquation(GL_FUNC_ADD, GL_FUNC_ADD);
		GL::SetBlendFunction(GL_ONE, GL_ONE, GL_ONE, GL_ONE);

		// TODO: If the light is a point light, bind the close or near point light shader, set its uniforms and render the light...
		// And later, don't give the lights their own shader, let those details be renderer specific (deferred in this case) and make
		// the light struct real simple and data based. Probably do the same with materials, but that's an even later problem!
		auto& lightShader = light->GetShader();
		gBuffer.BindAsUniform(lightShader);
		light->SetUniforms(*this, camera);

		if (light->CastsShadows())
		{
			this->shadowMap.Bind(8);
			lightShader.SetUniform("u_shadow_map", 8);
			lightShader.SetUniform("u_inverse_view_matrix", glm::inverse(camera.GetViewMatrix()));
			lightShader.SetUniform("u_light_view_projection", lightViewProjection);
		}

		ScreenAlignedQuad::Render();

		GL::SetBlending(false);
	}

	static bool drawPointLightWireframes = true;
	if (ImGui::CollapsingHeader("Light pass"))
	{
		ImGui::Checkbox("Draw point light wireframes", &drawPointLightWireframes);
	}

	if (drawPointLightWireframes)
	{
		GL::SetFaceCulling(false);
		GL::SetDepthTest(true);
		GL::SetDepthFunction(GL_LEQUAL);

		wireframeShader.Bind();
		GL::SetPolygonMode(GL_LINE);

		glm::mat4 viewProjection = camera.GetProjectionMatrix() * camera.GetViewMatrix();
		wireframeShader.SetUniform("u_view_projection", viewProjection);

		for (auto& light : lights)
		{
			// TODO: Redo light class to avoid all this crap.
			auto pointLight = light->GetComponent<PointLight>();
			if (pointLight != nullptr)
			{
				float radius = pointLight->intensity * 6.5f; // TODO: Get a proper radius!
				glm::vec3 position = pointLight->GetOwnerEntity().GetTransform().GetPositionInWorld();

				glm::mat4 scale = glm::scale(glm::mat4{ 1.0f }, glm::vec3{radius, radius, radius});
				glm::mat4 translation = glm::translate(glm::mat4{ 1.0f }, position);

				wireframeShader.SetUniform("u_model_matrix", translation * scale);

				Sphere::Render();
			}
		}

		GL::SetPolygonMode(GL_FILL);
		GL::SetFaceCulling(true);
	}
}

float CalculatePointLightRadius(const Light& light)
{
	//
	// TODO: Implement properly!
	//
	return light.intensity * 6.5f;
}

void SetCommmonLightUniforms(const Light& light, const Shader& lightShader, const CameraComponent& camera, const GBuffer& gBuffer)
{
	// TODO: (can be optimized considering redundancy, i.e. inv-proj & g-buffer are same for all lights this frame)

	lightShader.SetUniform("u_light_color", light.color);
	lightShader.SetUniform("u_light_intensity", light.intensity);
	lightShader.SetUniform("u_inverse_projection_matrix", glm::inverse(camera.GetProjectionMatrix()));
	gBuffer.BindAsUniform(lightShader);
}

void SetShadowRelatedLightUniforms(const Light& light, const Shader& lightShader, const Texture2D& shadowMap, const CameraComponent& camera)
{
	const Transform& lightTransform = light.GetOwnerEntity().GetTransform();
	Camera lightCamera{ lightTransform.GetPositionInWorld(), lightTransform.GetOrientationInWorld() };
	glm::mat4 lightViewProjection = lightCamera.GetProjectionMatrix() * lightCamera.GetViewMatrix();

	shadowMap.Bind(8);
	lightShader.SetUniform("u_shadow_map", 8);
	lightShader.SetUniform("u_inverse_view_matrix", glm::inverse(camera.GetViewMatrix()));
	lightShader.SetUniform("u_light_view_projection", lightViewProjection);
}

void Renderer::LightPassNew(const Scene& scene, const EntityList& geometry, const EntityList& lights, const CameraComponent& camera) const
{
	lightAccumulationBuffer.BindAsDrawFrameBuffer();

	// Ambient light pass (could be optimized to be done while filling g-buffer)
	ambientShader.Bind();
	ambientShader.SetUniform("u_color", scene.GetAmbientColor());
	gBuffer.BindAsUniform(ambientShader);
	GL::SetDepthTest(false);
	ScreenAlignedQuad::Render();

	for (auto lightEntity : lights)
	{
		auto light = lightEntity->GetComponent<Light>();
		Light::Type lightType = light->GetType();
		bool renderShadows = (lightType == Light::Type::SPOT);

		// Render shadow maps if applicable (spot light only for now)
		if (renderShadows)
		{
			shadowMapFramebuffer.BindAsDrawFrameBuffer();
			GL::SetClearDepth(1.0f);
			GL::Clear(GL_DEPTH_BUFFER_BIT);

			GL::SetDepthMask(true);
			GL::SetDepthTest(true);
			GL::SetDepthFunction(GL_LEQUAL);
			GL::SetFaceCulling(true);

			shadowMapGenerator.Bind();

			const Transform& lightTransform = light->GetOwnerEntity().GetTransform();
			Camera lightCamera{ lightTransform.GetPositionInWorld(), lightTransform.GetOrientationInWorld() };
			glm::mat4 lightViewProjection = lightCamera.GetProjectionMatrix() * lightCamera.GetViewMatrix();
			shadowMapGenerator.SetUniform("u_view_projecion_matrix", lightViewProjection);

			for (auto entity : geometry)
			{
				shadowMapGenerator.SetUniform("u_model_matrix", entity->GetTransform().GetWorldMatrix());
				entity->GetComponent<Renderable>()->GetMesh()->Render();
			}
		}

		lightAccumulationBuffer.BindAsDrawFrameBuffer();

		// TODO: Logically the depth mask should be false, since I don't want to touch the depth at all from the lights, but I get really strage results if it's false!
		// So I'm not sure... It might be some strange behaviour related to one texture in multiple frame buffers. Find out, somehow...
		// HOWEVER, since depth test is disabled, depth writing is always disabled too, and this works.
		GL::SetDepthTest(false);

		GL::SetFaceCulling(false);

		GL::SetBlending(true);
		GL::SetBlendEquation(GL_FUNC_ADD, GL_FUNC_ADD);
		GL::SetBlendFunction(GL_ONE, GL_ONE, GL_ONE, GL_ONE);

		if (lightType == Light::Type::POINT)
		{

			float distance = glm::length(light->GetOwnerEntity().GetTransform().GetPositionInWorld() - camera.GetOwnerEntity().GetTransform().GetPositionInWorld());
			float radius = CalculatePointLightRadius(*light);
			float cameraNear = camera.GetNear();

			auto viewSpacePos = glm::vec3(camera.GetViewMatrix() * glm::vec4(light->GetOwnerEntity().GetTransform().GetPositionInWorld(), 1.0f));

			if (distance > radius + cameraNear)
			{
				pointLightVolumeShader.Bind();
				SetCommmonLightUniforms(*light, pointLightVolumeShader, camera, gBuffer);
				pointLightVolumeShader.SetUniform("u_light_position", viewSpacePos);
				pointLightVolumeShader.SetUniform("u_light_world_position", light->GetOwnerEntity().GetTransform().GetPositionInWorld());
				pointLightVolumeShader.SetUniform("u_view_projection_matrix", camera.GetProjectionMatrix() * camera.GetViewMatrix());

				GL::SetDepthTest(true);
				GL::SetDepthMask(false);
				Sphere::Render();
			}
			else
			{
				pointLightNearShader.Bind();
				SetCommmonLightUniforms(*light, pointLightNearShader, camera, gBuffer);
				pointLightNearShader.SetUniform("u_light_position", viewSpacePos);
				pointLightNearShader.SetUniform("u_view_projection_matrix", camera.GetProjectionMatrix() * camera.GetViewMatrix());

				GL::SetDepthTest(false);
				ScreenAlignedQuad::Render();
			}
		}
		else if (lightType == Light::Type::SPOT)
		{
			spotLightShader.Bind();

			auto viewSpacePos = glm::vec3(camera.GetViewMatrix() * glm::vec4(light->GetOwnerEntity().GetTransform().GetPositionInWorld(), 1.0f));
			auto lightForward = light->GetOwnerEntity().GetTransform().GetForward();

			glm::quat conjugateCameraOrientation = glm::conjugate(camera.GetOwnerEntity().GetTransform().GetOrientationInWorld());
			auto viewSpaceLightForward = glm::rotate(conjugateCameraOrientation, lightForward);

			SetCommmonLightUniforms(*light, spotLightShader, camera, gBuffer);
			SetShadowRelatedLightUniforms(*light, spotLightShader, this->shadowMap, camera);
			spotLightShader.SetUniform("u_light_position", viewSpacePos);
			spotLightShader.SetUniform("u_light_direction", viewSpaceLightForward);
			spotLightShader.SetUniform("u_light_outer_cone_angle_cos", cosf(light->coneOuterAngle / 2.0f));
			spotLightShader.SetUniform("u_light_inner_cone_angle_cos", cosf(light->coneInnerAngle / 2.0f));

			GL::SetDepthTest(false);
			ScreenAlignedQuad::Render();
		}
		else if (lightType == Light::Type::DIRECTIONAL)
		{
			directionalLightShader.Bind();

			SetCommmonLightUniforms(*light, directionalLightShader, camera, gBuffer);
			SetShadowRelatedLightUniforms(*light, directionalLightShader, this->shadowMap, camera);
			// TODO: Implement! Set light specific uniforms.

			GL::SetDepthTest(false);
			ScreenAlignedQuad::Render();
		}
		else
		{
			Logger::Log("Error: Tried to render light with unknown type.");
		}

		GL::SetBlending(false);
	}


	static bool drawPointLightWireframes = true;
	if (ImGui::CollapsingHeader("Light pass"))
	{
		ImGui::Checkbox("Draw point light wireframes", &drawPointLightWireframes);
	}

	if (drawPointLightWireframes)
	{
		GL::SetFaceCulling(false);
		GL::SetDepthTest(true);
		GL::SetDepthFunction(GL_LEQUAL);

		wireframeShader.Bind();
		GL::SetPolygonMode(GL_LINE);

		glm::mat4 viewProjection = camera.GetProjectionMatrix() * camera.GetViewMatrix();
		wireframeShader.SetUniform("u_view_projection", viewProjection);

		for (auto& light : lights)
		{
			auto pointLight = light->GetComponent<Light>();
			if (pointLight != nullptr && pointLight->GetType() == Light::Type::POINT)
			{
				float radius = CalculatePointLightRadius(*pointLight);
				glm::vec3 position = pointLight->GetOwnerEntity().GetTransform().GetPositionInWorld();

				glm::mat4 scale = glm::scale(glm::mat4{ 1.0f }, glm::vec3{radius, radius, radius});
				glm::mat4 translation = glm::translate(glm::mat4{ 1.0f }, position);

				wireframeShader.SetUniform("u_model_matrix", translation * scale);

				Sphere::Render();
			}
		}

		GL::SetPolygonMode(GL_FILL);
		GL::SetFaceCulling(true);
	}
}

void Renderer::DrawSkybox(const CameraComponent& camera, const TextureCube& skyboxTexture) const
{
	lightAccumulationBuffer.BindAsDrawFrameBuffer();

	// Depth map is cleared to 1.0, skybox shader fixes depth to 1.0
	GL::SetDepthTest(true);
	GL::SetDepthFunction(GL_EQUAL);
	GL::SetDepthMask(true);

	skyboxShader.Bind();
	skyboxShader.SetUniform("u_view_rotation_matrix", glm::mat4(glm::mat3(camera.GetViewMatrix()))); // remove translation part
	skyboxShader.SetUniform("u_projection_matrix", camera.GetProjectionMatrix());
	skyboxTexture.Bind(35);
	skyboxShader.SetUniform("u_skybox_texture", 35);
	SkyboxCube::Render();
}

void Renderer::GenerateBloom()
{
	static float brightPassFilterThreshold = 0.1f;
	if (ImGui::CollapsingHeader("Bloom"))
	{
		ImGui::SliderFloat("Luminance threshold", &brightPassFilterThreshold, 0.0f, 3.0f);
		ImGui::SliderFloat("Bloom master weight", &bloomMasterWeight, 0.0f, 1.0f);
		ImGui::SliderFloat2("Bloom weights", glm::value_ptr(bloomWeights), 0.0f, 1.0f);
		ImGui::SliderInt("Blur passes per bloom", &numPassesPerBlur, 1, 20);
	}

	GL::SetBlending(false);
	GL::SetDepthTest(false);

	static const Shader highPass{"Generic/ScreenSpaceQuad.vsh", "Filtering/HighPassFilter.fsh"};
	highPass.Bind();
	highPass.SetUniform("u_threshold", brightPassFilterThreshold);
	highPass.SetUniform("u_texture", lightAccumulationTexture.Bind(0));
	bloomBrightPassFB.BindAsDrawFrameBuffer();
	ScreenAlignedQuad::Render();
	
	// Generate mipmaps/downsamples that will be available for the blur passes
	bloomBrightPass.GenerateMipmaps();

	static const Shader gaussianBlurV{"Generic/ScreenSpaceQuad.vsh", "Filtering/GaussianBlur.fsh", std::vector<std::string>{"VERTICAL_PASS"}};
	static const Shader gaussianBlurH{"Generic/ScreenSpaceQuad.vsh", "Filtering/GaussianBlur.fsh", std::vector<std::string>{"HORIZONTAL_PASS"}};

	for (int blur = 0; blur < numBloomBlurs; blur++)
	{
		int fst = 2 * blur;
		int snd = 2 * blur + 1;

		for (int pass = 0; pass < numPassesPerBlur; pass++)
		{
			bloomBlurFBs[fst].BindAsDrawFrameBuffer();
			gaussianBlurV.Bind();
			if (pass == 0)
			{
				// The bloom blurs have the same aspect ratio as the bloom bright pass and
				// width & heights are power-of-two subdivisions of the bright pass size
				float relSize = roundf(bloomBrightPass.GetWidth() / bloomBlurs[fst].GetWidth());
				int exp = static_cast<int>(log2f(relSize));

				gaussianBlurV.SetUniform("u_texture_lod", exp);
				gaussianBlurV.SetUniform("u_texture", bloomBrightPass.Bind(0));
			}
			else
			{
				gaussianBlurV.SetUniform("u_texture_lod", 0);
				gaussianBlurV.SetUniform("u_texture", bloomBlurs[snd].Bind(0));
			}
			ScreenAlignedQuad::Render();

			bloomBlurFBs[snd].BindAsDrawFrameBuffer();
			gaussianBlurH.Bind();
			gaussianBlurH.SetUniform("u_texture_lod", 0);
			gaussianBlurH.SetUniform("u_texture", bloomBlurs[fst].Bind(0));
			ScreenAlignedQuad::Render();
		}
	}
}

void Renderer::RenderCameras(EntityList cameras) const
{
	for (auto camera : cameras)
	{
		auto cameraComp = camera->GetComponent<CameraComponent>();
		if (cameraComp->GetTarget() != nullptr)
		{
			// TODO: Simply render every geometry object into the target with some ambient component for now
			// (later we could do possibly do the whole Geometry+Light pass into the camera target

			// Since the extra camera is placed at the same place as the main camera, this neat trick works!
			cameraComp->GetTarget()->BindAsDrawFrameBuffer();
			auto window = Window::CurrentWindow();
			window->BindAsReadFrameBuffer();
			glBlitFramebuffer(0, 0, window->GetFramebufferWidth(), window->GetFramebufferHeight(), 0, 0, 853, 480, GL_COLOR_BUFFER_BIT, GL_LINEAR); // HACK: Hardcoded sizes!
		}
	}
}

void Renderer::RenderTextureToScreen(const Texture2D& texture, bool alphaBlending, bool setViewport)
{
	window->BindAsDrawFrameBuffer(setViewport);
	nofilterFilter.Bind();

	texture.Bind(0);
	nofilterFilter.SetUniform("u_texture", 0);

	float r, g, b, a;
	GL::GetClearColor(&r, &g, &b, &a);
	bool faceCulling = GL::IsFaceCulling();
	bool depthTest = GL::IsDepthTesting();
	bool depthMask = GL::GetDepthMask();
	GLenum eqRGB, eqA;
	GL::GetBlendEquation(&eqRGB, &eqA);
	GLenum fnSrcRGB, fnDstRGB, fnSrcA, fnDstA;
	GL::GetBlendFunction(&fnSrcRGB, &fnDstRGB, &fnSrcA, &fnDstA);

	GL::SetFaceCulling(false);
	GL::SetDepthTest(false);
	GL::SetDepthMask(false);
	GL::SetClearColor(1, 0, 1, 1);
	GL::Clear(GL_COLOR_BUFFER_BIT);

	GL::SetBlending(alphaBlending);
	if (alphaBlending)
	{
		GL::SetBlendEquation(GL_FUNC_ADD, GL_FUNC_ADD);
		GL::SetBlendFunction(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	ScreenAlignedQuad::Render();

	GL::SetClearColor(r, g, b, a);
	GL::SetFaceCulling(faceCulling);
	GL::SetDepthMask(depthMask);
	GL::SetDepthTest(depthTest);
	GL::SetBlendEquation(eqRGB, eqA);
	GL::SetBlendFunction(fnSrcRGB, fnDstRGB, fnSrcA, fnDstA);
}
