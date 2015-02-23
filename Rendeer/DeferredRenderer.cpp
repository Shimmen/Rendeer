#include "DeferredRenderer.h"

#include "Display.h"
#include "Entity.h"
#include "Texture.h"
#include "DiffuseMaterial.h"
#include "PerspectiveCamera.h"

DeferredRenderer::DeferredRenderer(Display& display)
	: display(display)
	, gBuffer(display.GetWidth(), display.GetHeight())
	, screenSpaceShader("shaders/postprocess.vsh",
	                    "shaders/light_default.fsh")
{
	// This really shouldn't need to be here,
	// since the GBuffer is its own class now
	GLenum reason = 0;
	if (!gBuffer.IsComplete(&reason))
	{
		std::cout << "Error: G Buffer is incomplete!\nReason: " << reason << std::endl;
	}
}

void DeferredRenderer::Bind() const
{
	glViewport(0, 0, display.GetWidth(), display.GetHeight());
	glClearColor(0, 0, 0, 1);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);

	glDepthFunc(GL_LEQUAL);
}

void DeferredRenderer::BindForObjectPass() const
{
	// TODO: If this is bound as a READ frame buffer, it gets rendered.
	// However, it doesn't seem to animate (which could mean it doesn't redraw)
	// And it really should be DRAW
	gBuffer.BindAsDrawFrameBuffer();

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void DeferredRenderer::RenderLightPass()
{
	// Set up the gl state to render light pass
	display.BindAsDrawFrameBuffer();

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT);

	// Render the scene with a default light shader
	screenSpaceShader.Bind();

	gBuffer.GetAlbedoTexture().Bind(10);
	screenSpaceShader.SetUniform("u_albedo", 10);
	gBuffer.GetNormalTexture().Bind(11);
	screenSpaceShader.SetUniform("u_normals", 11);
	//gBuffer.GetDepthTexture().Bind(12);
	//screenSpaceShader.SetUniform("u_depth", 12);

	quad.Render();
}
