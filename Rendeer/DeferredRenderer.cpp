#include "DeferredRenderer.h"

#include "Window.h"
#include "Entity.h"
#include "Texture.h"
#include "Lighting.h"
#include "DiffuseMaterial.h"

DeferredRenderer::DeferredRenderer(Window& window)
	: window(window)
	, gBuffer(window.GetFramebufferWidth(), window.GetFramebufferHeight())
{
	shadowMapFramebuffer.AttachTexture(shadowMap, GL_DEPTH_ATTACHMENT);
	assert(shadowMapFramebuffer.IsComplete());
}

DeferredRenderer::~DeferredRenderer()
{
}

void DeferredRenderer::BindForUsage() const
{
	int width, height;
	window.GetFramebufferSize(&width, &height);

	glViewport(0, 0, width, height);
	glClearColor(0, 0, 0, 1);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);

	glDepthFunc(GL_LEQUAL);
	
	glEnable(GL_FRAMEBUFFER_SRGB);
}


void DeferredRenderer::Render(const std::vector<Entity *>& entities, const std::vector<ILight *>& lights, PerspectiveCamera& camera)
{
	// 
	// Set state for geometry rendering
	// 

	gBuffer.BindAsRenderTarget();

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_CULL_FACE);

	for (auto entity = entities.begin(); entity != entities.end(); ++entity)
	{
		(*entity)->Render(*this, camera);
	}

	// 
	// Set up the gl state to render the light pass
	// 

	window.BindAsDrawFramebuffer();
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto light = lights.begin(); light != lights.end(); ++light)
	{
		if ((*light)->CastsShadows())
		{
			shadowMapFramebuffer.BindAsDrawFrameBuffer();
			glEnable(GL_DEPTH_TEST);
			glDepthMask(GL_TRUE);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_CULL_FACE);

			shadowMapGenerator.Bind();

			auto lightCamera = (*light)->GetLightCamera();
			auto viewProjectionMatrix = lightCamera.GetProjectionMatrix() * lightCamera.GetViewMatrix();
			shadowMapGenerator.SetUniform("u_view_projecion_matrix", viewProjectionMatrix);

			for (auto entity = entities.begin(); entity != entities.end(); ++entity)
			{
				shadowMapGenerator.SetUniform("u_model_matrix", (*entity)->GetTransform().GetModelMatrix());
				(*entity)->GetMesh()->Render();
			}
		}
		
		window.BindAsDrawFramebuffer();
		glEnable(GL_BLEND);
		glBlendEquation(GL_FUNC_ADD);
		glBlendFunc(GL_ONE, GL_ONE);
		glDisable(GL_DEPTH_TEST);
		glDepthMask(GL_FALSE);
		glDisable(GL_CULL_FACE);

		const Shader& lightShader = (*light)->GetShader();

		// Bind the gBuffer related uniforms
		gBuffer.BindAsUniform(lightShader);

		// Ask the light to sets its shader's uniforms
		(*light)->SetUniforms(*this, camera);

		quad.Render();
	}

	glDisable(GL_BLEND);

#if 0
	RenderTextureToScreen(shadowMap);
#endif

	window.SwapBuffers();
}

void DeferredRenderer::RenderTextureToScreen(const Texture& texture)
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
