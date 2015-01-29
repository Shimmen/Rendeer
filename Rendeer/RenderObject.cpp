#include "RenderObject.h"

#include <glm/glm.hpp>

RenderObject::RenderObject(const Mesh& mesh)
	: transform()
	, mesh(mesh)
{
}

void RenderObject::Render(const Shader& shader)
{
	// TODO: Make material!
	//material.UpdateUniforms(shader);
	
	mesh.Render();
}