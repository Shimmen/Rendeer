#include "Component.h"

Entity& Component::GetOwnerEntity()
{
	return *ownerEntity;
}

const Entity& Component::GetOwnerEntity() const
{
	return *ownerEntity;
}

void Component::SetOwnerEntity(Entity *ownerEntity)
{
	if (this->ownerEntity == nullptr)
	{
		this->ownerEntity = ownerEntity;
		Init();
	}
	else
	{
		Logger::GetDefaultLogger().Log("SetOwnerEntity called for Component that already has a owner set. Function call ignored.");
	}
}
