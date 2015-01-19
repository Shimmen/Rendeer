#include "BasicRenderer.h"


BasicRenderer::BasicRenderer(Display* mainDisplay)
{
	this->mainDisplay = mainDisplay;

	this->shader = new Shader("shaders/ambient.vsh", "shaders/ambient.fsh");
}

BasicRenderer::~BasicRenderer()
{
	delete shader;
}

/*
void BasicRenderer::Render(RenderableObject *objects, int objectCount) const
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