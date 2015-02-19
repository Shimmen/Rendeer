#include "DeferredRenderer.h"

#include "Display.h"
#include "Entity.h"
#include "Texture.h"
#include "Material.h"
#include "PerspectiveCamera.h"

DeferredRenderer::DeferredRenderer(Display& display)
	: display(display)
	, plainShader("shaders/DeferredRenderer/render_to_gbuffer.vsh", "shaders/DeferredRenderer/render_to_gbuffer.fsh")
	, screenSpaceShader("shaders/DeferredRenderer/screen_aligned_quad.vsh", "shaders/DeferredRenderer/texturize.fsh")
	, gBufferAlbedo(display.GetWidth(), display.GetHeight(), GL_RGB, GL_CLAMP_TO_BORDER, GL_LINEAR, GL_LINEAR)
	, gBufferNormal(display.GetWidth(), display.GetHeight(), GL_RGB, GL_CLAMP_TO_BORDER, GL_NEAREST, GL_NEAREST)
	, gBufferDepth(display.GetWidth(), display.GetHeight(), GL_DEPTH_COMPONENT, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST)
{
	gBuffer.AttachTexture(gBufferAlbedo, GL_COLOR_ATTACHMENT0);
	gBuffer.AttachTexture(gBufferNormal, GL_COLOR_ATTACHMENT1);
	gBuffer.AttachTexture(gBufferDepth, GL_DEPTH_ATTACHMENT);

	GLenum reason = 0;
	if (!gBuffer.IsComplete(&reason))
	{
		std::cout << "Error: G Buffer is incomplete!\nReason: " << reason << std::endl;
	}
}

void DeferredRenderer::Bind() const
{
	glClearColor(0, 0, 0, 1);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
}

void DeferredRenderer::Render(const PerspectiveCamera& camera, const std::vector<Entity *> entities)
{
	// Render to G-Buffer
	gBuffer.Bind();
	glViewport(0, 0, display.GetWidth(), display.GetHeight());
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	static const GLenum drawBuffers[2] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1 };
	glDrawBuffers(2, drawBuffers);
	plainShader.Bind();

	for (auto it = entities.begin(); it != entities.end(); ++it)
	{
		Entity *entity = *it;

		entity->GetMaterial()->diffuseTexture->Bind(0);
		plainShader.SetUniform("u_diffuse", 0);

		glm::mat4 modelViewMatrix = camera.GetViewMatrix() * entity->GetTransform()->GetModelMatrix();
		glm::mat4 projectionMatrix = camera.GetProjectionMatrix();
		plainShader.SetUniform("u_model_view_matrix", modelViewMatrix);
		plainShader.SetUniform("u_projection_matrix", projectionMatrix);

		entity->GetMesh()->Render();
	}


	// Render to screen
	display.BindAsFrameBuffer();
	glViewport(0, 0, display.GetWidth(), display.GetHeight());
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	display.Clear(GL_COLOR_BUFFER_BIT);

	screenSpaceShader.Bind();

	gBufferAlbedo.Bind(10);
	screenSpaceShader.SetUniform("u_albedo", 10);
	gBufferNormal.Bind(11);
	screenSpaceShader.SetUniform("u_normals", 11);
	//gBufferDepth.Bind(20);
	
	quad.Render();

	display.SwapBuffers();
}