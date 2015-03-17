#include "DeferredRenderer.h"

#include "Display.h"
#include "Entity.h"
#include "Texture.h"
#include "Lighting.h"
#include "DiffuseMaterial.h"
#include "PerspectiveCamera.h"

DeferredRenderer::DeferredRenderer(Display& display)
	: display(display)
	, gBuffer(display.GetWidth(), display.GetHeight())
{
	// This really shouldn't need to be here,
	// since the GBuffer is its own class now
	GLenum reason = 0;
	if (!gBuffer.IsComplete(&reason))
	{
		std::cout << "Error: G Buffer is incomplete!\nReason: " << reason << std::endl;
	}

	renderTextureShader = new Shader("postprocess.vsh", "render_texture.fsh");
}

DeferredRenderer::~DeferredRenderer()
{
	delete renderTextureShader;
}

void DeferredRenderer::BindForUsage() const
{
	glViewport(0, 0, display.GetWidth(), display.GetHeight());
	glClearColor(0, 0, 0, 1);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);

	glDepthFunc(GL_LEQUAL);
}


void DeferredRenderer::Render(const std::vector<Entity *>& entities, const std::vector<ILight *>& lights, PerspectiveCamera& camera)
{
	RenderGeometryPass(entities, camera);

#if 1
	RenderLightPass(lights, camera);
#else
	RenderTextureToScreen(gBuffer.GetDepthTexture());
#endif

	display.SwapBuffers();
}

void DeferredRenderer::RenderGeometryPass(const std::vector<Entity *>& entities, PerspectiveCamera& camera)
{
	// Set state for geometry rendering
	gBuffer.BindAsDrawFrameBuffer();
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto it = entities.begin(); it != entities.end(); ++it)
	{
		Entity *entity = (*it);
		entity->Render(*this, camera);
	}
}

void DeferredRenderer::RenderLightPass(const std::vector<ILight *>& lights, PerspectiveCamera& camera)
{
	// Set up the gl state to render the light pass
	display.BindAsDrawFrameBuffer();
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT);

	// TODO: Enable blending!

	gBuffer.GetAlbedoTexture().Bind(10);
	gBuffer.GetNormalTexture().Bind(11);
	gBuffer.GetDepthTexture().Bind(12);

	for (auto it = lights.begin(); it != lights.end(); ++it)
	{
		ILight *light = (*it);

		// Ask the light to sets its shader's uniforms (except the gBuffer related
		// ones, since they are set here)
		light->SetUniforms(*this, camera);

		quad.Render();
	}
}

void DeferredRenderer::RenderTextureToScreen(const Texture& texture)
{
	display.BindAsDrawFrameBuffer();
	renderTextureShader->Bind();

	texture.Bind(0);
	renderTextureShader->SetUniform("u_texture", 0);

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT);
	quad.Render();
}
