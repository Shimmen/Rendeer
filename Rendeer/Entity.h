#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Mesh.h"
#include "Transform.h"
#include "IMaterial.h"

class Component;

class Entity
{
public:

	Entity(Mesh& mesh, IMaterial& material)
		: transform{}
		, material{material}
		, mesh{mesh}
	{
	}
	
/*	TODO: Replace the above CTOR with this!

	Entity(const Transform& transform)
		: transform{ transform }
	{
	}
*/

	inline Transform& GetTransform() { return transform; }
	inline const Transform& GetTransform() const { return transform; }

	inline IMaterial& GetMaterial() { return material; }
	inline Mesh& GetMesh() { return mesh; }

	// Add the component and return this.
	Entity& AddComponent(const std::shared_ptr<Component> component);

private:

	Transform transform;

	// List of entity components
	std::vector<std::shared_ptr<Component>> components;


	// TODO: Move these to a Renderable component or similar
	IMaterial& material;
	Mesh& mesh;

};
