#include "Entity.h"

#include "Component.h"
// TODO: Remove import
#include "Renderable.h"
//        ^^^^^^^^^^^^

Entity& Entity::AddComponent(const std::shared_ptr<Component> component)
{
	components.push_back(component);
	component->SetOwnerEntity(this);
	return *this;
}

std::shared_ptr<const Renderable> Entity::GetRenderableComponent() const
{
	// TODO: Implement properly!
	auto component = components.front();
	auto renderable = std::dynamic_pointer_cast<Renderable>(component);
	assert(renderable);

	return renderable;
}