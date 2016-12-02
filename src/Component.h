#pragma once

#include "Entity.h"
#include "Logger.h"

class Component
{
public:

	// Entity and Component are tightly coupled in terms of behaviour and it makes
	// sense for Entity to have special access to Component members and methods
	// that should otherwise be private. This includes methods like SetOwnerEntity.
	friend class Entity;

public:

	Component();
	virtual ~Component() {};

	Entity& GetOwnerEntity();
	const Entity& GetOwnerEntity() const;

private:

	// Called after owner entity is set
	virtual void Init() = 0;

	virtual void SetOwnerEntity(Entity *ownerEntity) final;
	Entity *ownerEntity{ nullptr };

};
