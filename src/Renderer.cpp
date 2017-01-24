#include "Renderer.h"

#include "GLState.h"
#include "Renderable.h"

DeferredRenderer::DeferredRenderer(const Window *window)
	: window{ window }
	, gBuffer{ window->GetFramebufferWidth(), window->GetFramebufferHeight() }
	, lightAccumulationTexture{window->GetFramebufferWidth(), window->GetFramebufferHeight(), GL_RGBA, GL_RGBA16F, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST}
/*	, auxTexture1{ window->GetFramebufferWidth(), window->GetFramebufferHeight(), GL_RGBA, GL_RGBA16F, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR }
	, auxTextureLow1{ window->GetFramebufferWidth() / 2, window->GetFramebufferHeight() / 2, GL_RGBA, GL_RGBA16F, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR }
	, auxTextureLow2{ window->GetFramebufferWidth() / 2, window->GetFramebufferHeight() / 2, GL_RGBA, GL_RGBA16F, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR } */
	, shadowMap{ 2048, 2048, GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT16, GL_CLAMP_TO_BORDER, GL_NEAREST, GL_NEAREST }
	, shadowMapGenerator{ "Shadowing/ShadowMapGenerator.vsh", "Shadowing/ShadowMapGenerator.fsh" }
	, postProcessShader{ "Generic/ScreenSpaceQuad.vsh", "Postprocess/Postprocess.fsh" }
	, defaultNormalMap{"textures/default_normal.jpg", false}
{
	assert(window != nullptr);

	lightAccumulationBuffer.Attach(&lightAccumulationTexture, GL_COLOR_ATTACHMENT0);
	lightAccumulationBuffer.Attach(&gBuffer.depth, GL_DEPTH_ATTACHMENT);
	assert(lightAccumulationBuffer.IsComplete());
/*
	auxFramebuffer1.AttachTexture(&auxTexture1, GL_COLOR_ATTACHMENT0);
	assert(auxFramebuffer1.IsComplete());

	auxFramebufferLow1.AttachTexture(&auxTextureLow1, GL_COLOR_ATTACHMENT0);
	assert(auxFramebufferLow1.IsComplete());

	auxFramebufferLow2.AttachTexture(&auxTextureLow2, GL_COLOR_ATTACHMENT0);
	assert(auxFramebufferLow2.IsComplete());
*/
	shadowMap.Bind(0);
	shadowMap.SetBorderColor(1.0f, 1.0f, 1.0f, 1.0f);
	shadowMapFramebuffer.Attach(&shadowMap, GL_DEPTH_ATTACHMENT);
	assert(shadowMapFramebuffer.IsComplete());
}

DeferredRenderer::~DeferredRenderer()
{
}

void DeferredRenderer::Render(const Scene& scene)
{
	static bool first = true;
	if (first)
	{
		GL::FetchCurrentGLState();

		//GL::SetFaceCullingEnabled(true);
		glFrontFace(GL_CW); //GL::SetFrontFace(GL_CW);
		glCullFace(GL_BACK); //GL::CullFace(GL_BACK);

		glEnable(GL_FRAMEBUFFER_SRGB);
		glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

		first = false;
	}

	auto camera = scene.GetMainCamera();

	// All entities that are renderable are considered to be geometry (for now)
	std::vector<std::shared_ptr<Entity>> geometry{};
	scene.GetEntities<Renderable>(geometry);

	std::vector<std::shared_ptr<Entity>> lights{};
	scene.GetEntities<LightComponent>(lights);

	GeometryPass(geometry, *camera);
	LightPass(geometry, lights, *camera);
	DrawSkybox(*camera);
	GenerateBloom();

	//
	// Final post-processing
	//

	//RenderTextureToScreen(gBuffer.depth); window->SwapBuffers(); return;

	// Render light accumulation buffer onto screen with final post processing step(like tone mapping etc.)
	window->BindAsDrawFramebuffer();
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

	postProcessShader.Bind();
	//auxTexture1.Bind(0);
	lightAccumulationTexture.Bind(0);
	postProcessShader.SetUniform("u_texture", 0);
	ScreenAlignedQuad::Render();

	window->SwapBuffers();
}

void DeferredRenderer::GeometryPass(const std::vector<std::shared_ptr<Entity>>& entities, const CameraComponent& camera) const
{
	gBuffer.BindAsRenderTarget();
	glClearDepth(1.0);
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDepthMask(GL_TRUE);

	glEnable(GL_CULL_FACE);
	glDisable(GL_BLEND);

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

void DeferredRenderer::LightPass(const std::vector<std::shared_ptr<Entity>>& geometry, const std::vector<std::shared_ptr<Entity>>& lights, const CameraComponent& camera) const
{
	lightAccumulationBuffer.BindAsDrawFrameBuffer();
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Ambient light pass (could be optimized to be done while filling g-buffer)
	ambientShader.Bind();
	ambientShader.SetUniform("u_intensity", ambientIntensity);
	gBuffer.BindAsUniform(ambientShader);
	glDisable(GL_DEPTH_TEST);
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
			glClearDepth(1.0);
			glClear(GL_DEPTH_BUFFER_BIT);

			glDepthMask(GL_TRUE);
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LEQUAL);
			glEnable(GL_CULL_FACE);

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
		glDisable(GL_DEPTH_TEST);

		glDisable(GL_CULL_FACE);

		glEnable(GL_BLEND);
		glBlendEquation(GL_FUNC_ADD);
		glBlendFunc(GL_ONE, GL_ONE);

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

		glDisable(GL_BLEND);
	}
}

void DeferredRenderer::DrawSkybox(const CameraComponent& camera) const
{
	lightAccumulationBuffer.BindAsDrawFrameBuffer();

	// Depth map is cleared to 1.0, skybox shader fixes depth to 1.0
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_EQUAL);
	glDepthMask(GL_TRUE);

	skyboxShader.Bind();
	skyboxShader.SetUniform("u_view_rotation_matrix", glm::mat4(glm::mat3(camera.GetViewMatrix()))); // remove translation part
	skyboxShader.SetUniform("u_projection_matrix", camera.GetProjectionMatrix());
	skyboxTexture.Bind(35);
	skyboxShader.SetUniform("u_skybox_texture", 35);
	SkyboxCube::Render();
}

void DeferredRenderer::GenerateBloom() const
{
/*
	const int numBlurPasses = 7;
	const float brightPassFilterThreshold = 1.4f;

	// Downsample current render
	auxFramebufferLow1.BindAsDrawFrameBuffer();
	glClear(GL_COLOR_BUFFER_BIT);
	auxTexture1.Bind(0);
	nofilterFilter.Bind();
	nofilterFilter.SetUniform("u_texture", 0);
	quad.Render();

	// Extract bright spots through a bright-pass filter
	auxFramebufferLow2.BindAsDrawFrameBuffer();
	glClear(GL_COLOR_BUFFER_BIT);
	auxTextureLow1.Bind(0);
	highPassFilter.Bind();
	highPassFilter.SetUniform("u_texture", 0);
	highPassFilter.SetUniform("u_threshold", brightPassFilterThreshold);
	quad.Render();

	// Blur downsampled and high-passed render
	for (int i = 0; i < numBlurPasses; i++)
	{
		auxFramebufferLow1.BindAsDrawFrameBuffer();
		glClear(GL_COLOR_BUFFER_BIT);
		auxTextureLow2.Bind(0);
		gaussianBlurVertical.Bind();
		gaussianBlurVertical.SetUniform("u_texture", 0);
		quad.Render();

		auxFramebufferLow2.BindAsDrawFrameBuffer();
		glClear(GL_COLOR_BUFFER_BIT);
		auxTextureLow1.Bind(0);
		gaussianBlurHorizontal.Bind();
		gaussianBlurHorizontal.SetUniform("u_texture", 0);
		quad.Render();
	}

	// Additivly blend the bloom result on top of the default render
	auxFramebuffer1.BindAsDrawFrameBuffer();
	auxTextureLow2.Bind(0);
	nofilterFilter.Bind();
	nofilterFilter.SetUniform("u_texture", 0);
	glEnable(GL_BLEND);
	glBlendEquation(GL_FUNC_ADD);
	glBlendFunc(GL_ONE, GL_ONE);
	quad.Render();
	glDisable(GL_BLEND);
*/
}

void DeferredRenderer::RenderTextureToScreen(const Texture2D& texture)
{
	window->BindAsDrawFramebuffer();
	nofilterFilter.Bind();

	texture.Bind(0);
	nofilterFilter.SetUniform("u_texture", 0);

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);
	glClear(GL_COLOR_BUFFER_BIT);
	ScreenAlignedQuad::Render();
}
