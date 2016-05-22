#include "Entity.h"

#include "Component.h"

Entity& Entity::AddComponent(const std::shared_ptr<Component> component)
{
	components.push_back(component);
	component->SetOwnerEntity(this);
	return *this;
}
