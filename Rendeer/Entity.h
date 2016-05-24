#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Mesh.h"
#include "Transform.h"
#include "IMaterial.h"

class Component;
class Renderable;

class Entity
{
public:
	
	Entity(const Transform& transform = Transform())
		: transform{ transform }
	{
	}

	inline Transform& GetTransform() { return transform; }
	inline const Transform& GetTransform() const { return transform; }

	// Add the component and return this.
	Entity& AddComponent(const std::shared_ptr<Component> component);

	// TODO: Make generic
	std::shared_ptr<const Renderable> GetRenderableComponent() const;

private:

	Transform transform;

	// List of entity components
	std::vector<std::shared_ptr<Component>> components;

};
