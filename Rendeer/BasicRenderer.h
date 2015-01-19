#pragma once

#include <GL/glew.h>
#include <SDL.h>

#include "PerspectiveCamera.h"
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"

class BasicRenderer
{
public:
	BasicRenderer(Display* mainDisplay);
	~BasicRenderer();

	// TODO: Wrap Mesh in some object that holds things like a material and a transform!
	//void Render(Mesh *meshes, int meshCount) const;

	inline PerspectiveCamera *GetCamera() const { return camera; }

private:
	PerspectiveCamera *camera;
	Shader *shader;

	Display *mainDisplay;
};

