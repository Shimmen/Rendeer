#include "Renderer.h"

#include <imgui.h>

#include <glm/gtc/type_ptr.hpp>

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

	int ww = w / 2;
	int hh = h / 2;
	bloomBrightPass.Make(ww, hh, GL_RGB, GL_RGB16F);
	bloomBrightPass.SetFilter(GL_NEAREST);
	bloomBrightPassFB.Attach(&bloomBrightPass, GL_COLOR_ATTACHMENT0);
	for (int i = 0; i < numBloomBlurs; i++)
	{
		int fst = 2 * i;
		int snd = 2 * i + 1;

		// Set up two textures per size to be able to do V+H blur pass per size
		bloomBlurs[fst].Make(ww, hh, GL_RGB, GL_RGB16F);
		bloomBlurs[snd].Make(ww, hh, GL_RGB, GL_RGB16F);

		bloomBlurs[fst].SetWrap(GL_CLAMP_TO_EDGE);
		bloomBlurs[snd].SetWrap(GL_CLAMP_TO_EDGE);

		bloomBlurFBs[fst].Attach(&bloomBlurs[2 * i + 0], GL_COLOR_ATTACHMENT0); assert(bloomBlurFBs[2 * i + 0].IsComplete());
		bloomBlurFBs[snd].Attach(&bloomBlurs[2 * i + 1], GL_COLOR_ATTACHMENT0); assert(bloomBlurFBs[2 * i + 1].IsComplete());

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
	std::vector<std::shared_ptr<Entity>> geometry{};
	scene.GetEntities<Renderable>(geometry);

	std::vector<std::shared_ptr<Entity>> lights{};
	scene.GetEntities<LightComponent>(lights);

	std::vector<std::shared_ptr<Entity>> cameras{};
	scene.GetEntities<CameraComponent>(cameras);

	RenderCameras(cameras);

	auto mainCamera = scene.GetMainCamera();

	GeometryPass(geometry, *mainCamera);
	LightPass(scene, geometry, lights, *mainCamera);

	if (scene.GetSkybox())
	{
		DrawSkybox(*mainCamera, *scene.GetSkybox());
	}

	GenerateBloom();

	//RenderTextureToScreen(bloomBrightPass); return;

	// Render light accumulation buffer onto screen with final post processing step(like tone mapping etc.)
	window->BindAsDrawFrameBuffer();
	GL::SetDepthTest(false);
	GL::SetBlending(false);

	postProcessShader.Bind();
	lightAccumulationTexture.Bind(0);
	postProcessShader.SetUniform("u_texture", 0);

	static bool useChromaAb = true;
	static float chromaAbAmount = 2.5f;

	if (ImGui::CollapsingHeader("Final post-process"))
	{
		ImGui::Checkbox("Chromatic Aberration", &useChromaAb);
		ImGui::SliderFloat("Amount", &chromaAbAmount, 0.0f, 20.0f);
	}

	postProcessShader.SetUniform("u_chroma_ab_amount", (useChromaAb) ? chromaAbAmount : 0.0f);

	ScreenAlignedQuad::Render();
}

void Renderer::GeometryPass(const std::vector<std::shared_ptr<Entity>>& entities, const CameraComponent& camera) const
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

void Renderer::LightPass(const Scene& scene, const std::vector<std::shared_ptr<Entity>>& geometry, const std::vector<std::shared_ptr<Entity>>& lights, const CameraComponent& camera) const
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

	static const Shader gaussianBlurV{ "Filtering/GaussianBlurV.vsh", "Filtering/GaussianBlur.fsh" };
	static const Shader gaussianBlurH{ "Filtering/GaussianBlurH.vsh", "Filtering/GaussianBlur.fsh" };

	for (int i = 0; i < numBloomBlurs; i++)
	{
		bloomBlurFBs[2 * i].BindAsDrawFrameBuffer();
		gaussianBlurV.Bind();
		gaussianBlurV.SetUniform("u_texture_lod", i); // Sample from i:th mip level (i.e. downsample bright pass)
		gaussianBlurV.SetUniform("u_texture", bloomBrightPass.Bind(0));
		ScreenAlignedQuad::Render();

		bloomBlurFBs[2 * i + 1].BindAsDrawFrameBuffer();
		gaussianBlurH.Bind();
		gaussianBlurH.SetUniform("u_texture_lod", 0); // Sampling from same size texture
		gaussianBlurH.SetUniform("u_texture", bloomBlurs[2 * i].Bind(0));
		ScreenAlignedQuad::Render();
	}
}

void Renderer::RenderCameras(std::vector<std::shared_ptr<Entity>> cameras) const
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

void Renderer::RenderTextureToScreen(const Texture2D& texture, bool alphaBlending)
{
	window->BindAsDrawFrameBuffer();
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
