#include "Entity.h"

#include "Scene.h"

Entity& Entity::AddComponent(std::shared_ptr<Component> component)
{
	components.push_back(component);
	component->SetOwnerEntity(this);
	return *this;
}

std::shared_ptr<Entity> Entity::AddChild(const std::shared_ptr<Entity> child)
{
	children.push_back(child);
	child->transform.SetParent(&this->transform);
	return child;
}

std::shared_ptr<Entity> Entity::NewChild()
{
	auto child = std::make_shared<Entity>();
	return AddChild(child);
}

const std::vector<std::shared_ptr<Entity>>& Entity::GetDirectChildren() const
{
	return this->children;
}

