#include "RenderObject.h"

#include <glm/glm.hpp>

RenderObject::RenderObject(const Mesh& mesh)
	: transform()
	, mesh(mesh)
{
}

void RenderObject::Render(const Shader& shader)
{
	// TODO: Think about this!
	/*
	Two possible solutions:
	
	Solution 1:
	transform.UpdateUniforms(shader);
	material.UpdateUniforms(shader);

	Solution 2:
	shader.UpdateUniforms(transform, material);

	*/

	mesh.Render();
}