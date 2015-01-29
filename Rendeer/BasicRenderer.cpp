#include "BasicRenderer.h"


BasicRenderer::BasicRenderer(Display& mainDisplay)
	: shader("shaders/ambient.vsh", "shaders/ambient.fsh")
{
	this->mainDisplay = &mainDisplay;
}

BasicRenderer::~BasicRenderer()
{
}

/*
void BasicRenderer::Render(const PerspectiveCamera& camera, RenderableObject *objects, int objectCount)
{
	shader->Bind();

	for (int i = 0; i < objectCount; ++i)
	{
		RenderableObject object = objects[i];

		// The object has its own:
		// - Transform (to convert it to world space)
		// - Material (things like textures etc.)
		// - Mesh (the actual vertex array to render)
		object.Render();
	}

	display.SwapBuffers();
	display.Clear(0, 0, 0, 1);
}
*/