#pragma once

#include <string>
#include <vector>
#include <memory>
#include <type_traits>

#include "Transform.h"

class Component;
class Scene;

class Entity
{
public:
	
	Entity(const Transform& transform = Transform(glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 0, 0 }))
		: transform{ transform }
	{
	}

	inline Transform& GetTransform() { return transform; }
	inline const Transform& GetTransform() const { return transform; }

	// Add the component and return this.
	Entity& AddComponent(const std::shared_ptr<Component> component);

	template<typename T>
	std::shared_ptr<const T> GetComponent() const;

	// Add the child entity and return the added child.
	std::shared_ptr<Entity> AddChild(const std::shared_ptr<Entity> child);

private:

	Transform transform;
	std::vector<std::shared_ptr<Component>> components;

	std::vector<std::shared_ptr<Entity>> children;

};

template<typename T>
inline std::shared_ptr<const T> Entity::GetComponent() const
{
	// Assert that T is a Component or a type derived from Component
	constexpr bool typeParameterIsComponent = std::is_base_of<Component, T>::value;
	static_assert(typeParameterIsComponent, "Entity::GetComponent<T>() called with type T that is not a Component!");
	
	// Iterate all components (the list probably will never be longer than 10 or so)
	for (std::shared_ptr<Component> component : components)
	{
		// Try to cast the component to the specific component. If successful, return it.
		std::shared_ptr<const T> correctType = std::dynamic_pointer_cast<const T>(component);
		if (correctType != nullptr)
		{
			return correctType;
		}
	}
	
	// No appropriate component found, return nullptr
	return std::shared_ptr<const T>();
}
