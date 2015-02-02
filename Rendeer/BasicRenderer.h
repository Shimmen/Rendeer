#pragma once

#include "Shader.h"

class PerspectiveCamera;
class Display;
class Entity;
class Shader;
class Mesh;

class BasicRenderer
{
public:
	BasicRenderer(Display& display);
	
	// Isn't needed since display is not owned by this class
	//~BasicRenderer();

	void Render(const PerspectiveCamera& camera, Entity *entities, int entityCount);

private:
	Display* display;

	Shader shader;
};

