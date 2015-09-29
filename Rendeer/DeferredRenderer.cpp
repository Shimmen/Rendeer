#include "DeferredRenderer.h"

#include "Window.h"
#include "Entity.h"
#include "Lighting.h"
#include "Texture2D.h"
#include "DiffuseMaterial.h"

DeferredRenderer::DeferredRenderer(const Window& window)
	: window(window)
	, gBuffer(window.GetFramebufferWidth(), window.GetFramebufferHeight())
{
	shadowMap.SetBorderColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	shadowMapFramebuffer.AttachTexture(shadowMap, GL_DEPTH_ATTACHMENT);
	assert(shadowMapFramebuffer.IsComplete());
}

DeferredRenderer::~DeferredRenderer()
{
}

void DeferredRenderer::BindForUsage() const
{
	glClearColor(0, 0, 0, 1);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);

	glDepthFunc(GL_LEQUAL);
	
	glEnable(GL_FRAMEBUFFER_SRGB);
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

	window.BindAsDrawFramebuffer();
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

		window.BindAsDrawFramebuffer();
		
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

#if 0
	RenderTextureToScreen(shadowMap);
#endif

	window.SwapBuffers();
}

void DeferredRenderer::RenderTextureToScreen(const Texture2D& texture)
{
	window.BindAsDrawFramebuffer();
	renderTextureShader.Bind();

	texture.Bind(0);
	renderTextureShader.SetUniform("u_texture", 0);

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT);
	quad.Render();
}
