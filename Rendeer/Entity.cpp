#include "Entity.h"

#include "Component.h"

const Transform& Entity::GetTransform() const
{
	// TODO: Calculate the global transform and return that!!!
	auto& localTransform = this->transform;

	return localTransform;
}

Entity& Entity::AddComponent(const std::shared_ptr<Component> component)
{
	components.push_back(component);
	component->SetOwnerEntity(this);
	return *this;
}
