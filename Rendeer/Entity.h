#pragma once

#include <string>

#include "Mesh.h"
#include "Transform.h"
#include "IMaterial.h"
#include "DiffuseMaterial.h"

class Camera;
class Shader;
class DeferredRenderer;

class Entity
{
public:

	Entity(Mesh& mesh, IMaterial& material)
		: transform{}
		, material{material}
		, mesh{mesh}
	{
	}
	
	inline Transform& GetTransform() { return transform; }
	inline IMaterial& GetMaterial() { return material; }
	inline Mesh& GetMesh() { return mesh; }

private:

	Transform transform;

	// TODO: Make it possible to attach behaviour to an entity (like a list of behaviour impl. instances)

	IMaterial& material;
	Mesh& mesh;

};
