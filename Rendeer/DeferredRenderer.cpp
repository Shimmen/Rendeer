#include "DeferredRenderer.h"

#include "Window.h"
#include "Entity.h"
#include "Lighting.h"
#include "Texture2D.h"
#include "DiffuseMaterial.h"

DeferredRenderer::DeferredRenderer(const Window& window)
	: window{ window }
	, gBuffer{ window.GetFramebufferWidth(), window.GetFramebufferHeight() }
	, lightAccumulationTexture{window.GetFramebufferWidth(), window.GetFramebufferHeight(), GL_RGBA, GL_RGBA16F, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST}
	, auxTexture1{ window.GetFramebufferWidth(), window.GetFramebufferHeight(), GL_RGBA, GL_RGBA16F, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR }
	, auxTextureLow1{ window.GetFramebufferWidth() / 2, window.GetFramebufferHeight() / 2, GL_RGBA, GL_RGBA16F, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR }
	, auxTextureLow2{ window.GetFramebufferWidth() / 2, window.GetFramebufferHeight() / 2, GL_RGBA, GL_RGBA16F, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR }
{
	lightAccumulationBuffer.AttachTexture(lightAccumulationTexture, GL_COLOR_ATTACHMENT0);
	assert(lightAccumulationBuffer.IsComplete());

	auxFramebuffer1.AttachTexture(auxTexture1, GL_COLOR_ATTACHMENT0);
	assert(auxFramebuffer1.IsComplete());

	auxFramebufferLow1.AttachTexture(auxTextureLow1, GL_COLOR_ATTACHMENT0);
	assert(auxFramebufferLow1.IsComplete());

	auxFramebufferLow2.AttachTexture(auxTextureLow2, GL_COLOR_ATTACHMENT0);
	assert(auxFramebufferLow2.IsComplete());

	shadowMap.SetBorderColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	shadowMapFramebuffer.AttachTexture(shadowMap, GL_DEPTH_ATTACHMENT);
	assert(shadowMapFramebuffer.IsComplete());
}

DeferredRenderer::~DeferredRenderer()
{
}

void DeferredRenderer::BindForUsage() const
{
	glClearColor(0, 0, 0, 0);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);

	glDepthFunc(GL_LEQUAL);
	
	glEnable(GL_FRAMEBUFFER_SRGB);

	glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
}


void DeferredRenderer::Render(const std::vector<Entity *>& entities, const std::vector<ILight *>& lights, Camera& camera)
{
	// 
	// Render geometry
	// 

	gBuffer.BindAsRenderTarget();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDisable(GL_BLEND);

	for (auto entityIt = entities.begin(); entityIt != entities.end(); ++entityIt)
	{
		Entity *entity = (*entityIt);
		auto& transform = entity->GetTransform();
		auto& material = entity->GetMaterial();
		auto& mesh = entity->GetMesh();

		material.UpdateUniforms(*this, transform, camera);
		mesh.Render();
	}

	// 
	// Set up the gl state to render the light pass
	// 

	lightAccumulationBuffer.BindAsDrawFrameBuffer();
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto light = lights.begin(); light != lights.end(); ++light)
	{
		// 
		// Render geometry into shadow map
		// 

		shadowMapFramebuffer.BindAsDrawFrameBuffer();
		
		glClearDepth(1.0);
		glClear(GL_DEPTH_BUFFER_BIT);

		bool TEMP_usingShadowMap = false;
		assert(shadowMap.GetWidth() == shadowMap.GetHeight());
		auto lightCamera = (*light)->GetLightCamera(camera, shadowMap.GetWidth());
		glm::mat4 lightViewProjection = lightCamera.GetProjectionMatrix() * lightCamera.GetViewMatrix();

		if ((*light)->CastsShadows())
		{
			TEMP_usingShadowMap = true;

			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);

			shadowMapGenerator.Bind();
			shadowMapGenerator.SetUniform("u_view_projecion_matrix", lightViewProjection);

			for (auto entity = entities.begin(); entity != entities.end(); ++entity)
			{
				shadowMapGenerator.SetUniform("u_model_matrix", (*entity)->GetTransform().GetModelMatrix());
				(*entity)->GetMesh().Render();
			}

			glCullFace(GL_BACK);
		}
		
		// 
		// Render lights
		// 

		lightAccumulationBuffer.BindAsDrawFrameBuffer();
		
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_CULL_FACE);
		
		glEnable(GL_BLEND);
		glBlendEquation(GL_FUNC_ADD);
		glBlendFunc(GL_ONE, GL_ONE);

		auto& lightShader = (*light)->GetShader();

		// Bind the gBuffer related uniforms
		gBuffer.BindAsUniform(lightShader);

		// Ask the light to sets its shader's uniforms
		(*light)->SetUniforms(*this, camera);

		// Set shadow map related uniforms
		if (TEMP_usingShadowMap)
		{
			this->shadowMap.Bind(8);
			lightShader.SetUniform("u_shadow_map", 8);
			lightShader.SetUniform("u_inverse_view_matrix", glm::inverse(camera.GetViewMatrix()));
			lightShader.SetUniform("u_light_view_projection", lightViewProjection);
		}

		quad.Render();
	}

	glDisable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);

	// Render light accumulation buffer into auxTexture1
	auxFramebuffer1.BindAsDrawFrameBuffer();
	glClear(GL_COLOR_BUFFER_BIT);
	lightAccumulationTexture.Bind(0);
	nofilterFilter.Bind();
	nofilterFilter.SetUniform("u_texture", 0);
	quad.Render();

	// TODO: render skybox into light accumulation. However, this doesn't work *properly* until we make use of HDR skyboxes.
	/*
	glDisable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_GREATER);
	//glDepthMask(GL_FALSE);
	skyboxShader.Bind();
	skyboxShader.SetUniform("u_view_rotation_matrix", glm::mat4(glm::mat3(camera.GetViewMatrix()))); // remove translation part
	skyboxShader.SetUniform("u_projection_matrix", camera.GetProjectionMatrix());
	skyboxTexture.Bind(35);
	skyboxShader.SetUniform("u_skybox_texture", 35);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_FRONT);
	skyboxMesh.Render();
	glDepthMask(GL_TRUE);
	glCullFace(GL_BACK);
	glDepthFunc(GL_LEQUAL);
	*/

	//
	// Perform bloom
	//
	
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

	//
	// Final post-processing
	//

	// Render light accumulation buffer onto screen with final post processing step(like tone mapping etc.)
	window.BindAsDrawFramebuffer();
	postProcessShader.Bind();
	auxTexture1.Bind(0);
	postProcessShader.SetUniform("u_texture", 0);
	quad.Render();

	window.SwapBuffers();
}

void DeferredRenderer::RenderTextureToScreen(const Texture2D& texture)
{
	window.BindAsDrawFramebuffer();
	nofilterFilter.Bind();

	texture.Bind(0);
	nofilterFilter.SetUniform("u_texture", 0);

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT);
	quad.Render();
}
