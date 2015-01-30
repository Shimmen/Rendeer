#pragma once

#include <string>

#include "Transform.h"
#include "Material.h"
#include "Mesh.h"

class Shader;

class Entity
{
public:
	//RenderObject(const std::string& fileName);
	Entity(Mesh& mesh, Material& material)
		: transform()
	{
		this->mesh = &mesh;
		this->material = &material;
	}

	inline Transform* GetTransform() { return &transform; }
	inline Material* GetMaterial() { return material; }
	inline Mesh* GetMesh() { return mesh; }

private:
	Transform transform;
	Material *material;
	Mesh *mesh;
};
