#include "DeferredRenderer.h"

#include "Display.h"
#include "Entity.h"
#include "Texture.h"
#include "Material.h"
#include "PerspectiveCamera.h"

DeferredRenderer::DeferredRenderer(Display& display)
	: display(display)
	, plainShader("shaders/BasicRenderer/no_light.vsh", "shaders/BasicRenderer/no_light.fsh")
	, screenSpaceShader("shaders/DeferredRenderer/screen_aligned_quad.vsh", "shaders/DeferredRenderer/texturize.fsh")
	, gBufferAlbedo(display.GetWidth(), display.GetHeight(), GL_RGB, GL_CLAMP_TO_BORDER, GL_LINEAR, GL_LINEAR)
	, gBufferDepth(display.GetWidth(), display.GetHeight(), GL_DEPTH_COMPONENT, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST)
{
	gBuffer.AttachTexture(gBufferAlbedo, GL_COLOR_ATTACHMENT0);
	gBuffer.AttachTexture(gBufferDepth, GL_DEPTH_ATTACHMENT);

	GLenum reason = 0;
	if (!gBuffer.IsComplete(&reason))
	{
		std::cout << "Error: G Buffer is incomplete!\nReason: " << reason << std::endl;
	}
}

void DeferredRenderer::Render(const PerspectiveCamera& camera, Entity *entities, int entityCount)
{
	glClearColor(0, 0, 0, 1);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);


	// Render to G-Buffer
	gBuffer.Bind();
	glViewport(0, 0, display.GetWidth(), display.GetHeight());
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	plainShader.Bind();

	for (int i = 0; i < entityCount; ++i)
	{
		Entity entity = entities[i];

		entity.GetMaterial()->diffuseTexture->Bind(0);
		plainShader.SetUniform("u_diffuse", 0);

		glm::mat4 mvpMatrix = camera.GetProjectionMatrix() * camera.GetViewMatrix() * entity.GetTransform()->GetModelMatrix();
		plainShader.SetUniform("u_mvp_matrix", mvpMatrix);

		entity.GetMesh()->Render();
	}


	// Render to screen
	display.BindAsFrameBuffer();
	glViewport(0, 0, display.GetWidth(), display.GetHeight());
	glDisable(GL_DEPTH_TEST);
	display.Clear(GL_COLOR_BUFFER_BIT);

	screenSpaceShader.Bind();

	gBufferAlbedo.Bind(10);
	gBufferDepth.Bind(11);
	screenSpaceShader.SetUniform("u_texture", 10);
	quad.Render();

	display.SwapBuffers();
}