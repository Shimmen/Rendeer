#pragma once

#include <vector>

#include "Shader.h"
#include "Entity.h"

class PerspectiveCamera;
class Display;
class Entity;
class Shader;
class Mesh;

/*
Defines a renderer that renders objects without any lights.
As for now (it might get changed for performace) you are allowed to create more
than one renderer and switch between them. All of the gl-state that is required
should be set every frame in the Render function.
*/

class BasicRenderer
{
public:
	BasicRenderer(Display& display);
	
	// Isn't needed since display is not owned by this class
	//~BasicRenderer();

	void Bind() const;

	void Render(const PerspectiveCamera& camera, const std::vector<Entity *> entities);

private:
	Display& display;

	Shader shader;
};

