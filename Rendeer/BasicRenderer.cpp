#include "BasicRenderer.h"


BasicRenderer::BasicRenderer(Display& display)
	: shader("shaders/ambient.vsh", "shaders/ambient.fsh")
{
	this->display = &display;
}

void BasicRenderer::Render(/*const PerspectiveCamera& camera,*/RenderObject *objects, int objectCount)
{
	display->Clear(0, 0, 0, 1);

	shader.Bind();

	for (int i = 0; i < objectCount; ++i)
	{
		RenderObject object = objects[i];

		// The object has its own:
		// - Transform (to convert it to world space)
		// - Material (things like textures etc.)
		// - Mesh (the actual vertex array to render)
		object.Render(shader);
	}

	display->SwapBuffers();
}