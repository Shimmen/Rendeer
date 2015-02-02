#include "BasicRenderer.h"

#include <GL/glew.h>

#include "Display.h"
#include "Entity.h"
#include "Texture.h"
#include "PerspectiveCamera.h"

BasicRenderer::BasicRenderer(Display& display)
	: shader("shaders/BasicRenderer/no_light.vsh", "shaders/BasicRenderer/no_light.fsh")
{
	this->display = &display;
}

void BasicRenderer::Render(const PerspectiveCamera& camera, Entity *entities, int entityCount)
{
	display->SetClearColor(0, 0, 0, 1);
	display->Clear(GL_COLOR_BUFFER_BIT);

	shader.Bind();

	for (int i = 0; i < entityCount; ++i)
	{
		Entity entity = entities[i];

		entity.GetMaterial()->diffuseTexture->Bind(0);
		shader.SetUniform("u_diffuse", 0);

		glm::mat4 mvpMatrix = camera.GetProjectionMatrix() * camera.GetViewMatrix() * entity.GetTransform()->GetModelMatrix();
		shader.SetUniform("u_mvp_matrix", mvpMatrix);

		entity.GetMesh()->Render();
	}

	display->SwapBuffers();
}