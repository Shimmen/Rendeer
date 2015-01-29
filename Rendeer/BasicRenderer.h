#pragma once

#include <GL/glew.h>
#include <SDL.h>

#include "PerspectiveCamera.h"
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "RenderObject.h"

class BasicRenderer
{
public:
	BasicRenderer(Display& display);
	
	// Isn't needed since display is unowned by this class
	//~BasicRenderer();

	void Render(/*const PerspectiveCamera& camera,*/RenderObject *objects, int objectCount);

private:
	Display* display;

	Shader shader;
};

