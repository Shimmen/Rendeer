#pragma once

#include <string>

#include "Transform.h"
#include "IMaterial.h"
#include "Mesh.h"

class Shader;
class DeferredRenderer;
class PerspectiveCamera;

class Entity
{
public:

	Entity(Mesh& mesh, IMaterial& material)
		: transform()
	{
		this->mesh = &mesh;
		this->material = &material;
	}
	
	inline Transform& GetTransform() { return transform; }
	inline IMaterial& GetMaterial() { return *material; }
	inline Mesh& GetMesh() { return *mesh; }

private:

	Transform transform;
	IMaterial *material;
	Mesh *mesh;

};
