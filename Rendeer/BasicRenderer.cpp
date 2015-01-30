#include "BasicRenderer.h"

#include <GL/glew.h>

#include "Display.h"
#include "Entity.h"
#include "Texture.h"

BasicRenderer::BasicRenderer(Display& display)
	: shader("shaders/no_light.vsh", "shaders/no_light.fsh")
{
	this->display = &display;

	display.SetClearColor(0, 0, 0, 1);
}

void BasicRenderer::Render(/*const PerspectiveCamera& camera,*/Entity *entities, int entityCount)
{
	display->Clear(GL_COLOR_BUFFER_BIT);

	shader.Bind();

	for (int i = 0; i < entityCount; ++i)
	{
		Entity entity = entities[i];

		entity.GetMaterial()->diffuseTexture->Bind(0);
		shader.SetUniform("u_diffuse", 0);

		entity.GetMesh()->Render();
	}

	display->SwapBuffers();
}