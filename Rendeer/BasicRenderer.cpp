#include "BasicRenderer.h"

#include <GL/glew.h>

#include "Display.h"
#include "Entity.h"
#include "Texture.h"
#include "PerspectiveCamera.h"

BasicRenderer::BasicRenderer(Display& display)
	: display(display)
	, shader("shaders/BasicRenderer/no_light.vsh", "shaders/BasicRenderer/no_light.fsh")
{
}

void BasicRenderer::Bind() const
{
	display.BindAsFrameBuffer();
	glClearColor(0, 0, 0, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDepthMask(GL_TRUE);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
}

void BasicRenderer::Render(const PerspectiveCamera& camera, const std::vector<Entity *> entities)
{
	display.Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader.Bind();

	for (auto it = entities.begin(); it != entities.end(); ++it)
	{
		Entity *entity = *it;

		entity->GetMaterial()->diffuseTexture->Bind(0);
		shader.SetUniform("u_diffuse", 0);

		glm::mat4 mvpMatrix = camera.GetProjectionMatrix() * camera.GetViewMatrix() * entity->GetTransform()->GetModelMatrix();
		shader.SetUniform("u_mvp_matrix", mvpMatrix);

		entity->GetMesh()->Render();
	}

	display.SwapBuffers();
}