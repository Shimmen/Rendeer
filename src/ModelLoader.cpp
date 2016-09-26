#include "ModelLoader.h"

#include <memory>

#include "Entity.h"
#include "Renderable.h"
#include "DiffuseMaterial.h"

/* static */ Entity ModelLoader::Load(const std::string & filename)
{
	// TODO: Implement!

	Entity entity;
	entity.AddComponent(std::make_shared<Renderable>(std::make_shared<Mesh>("Test"), std::make_shared<DiffuseMaterial>()));

	return entity;
}
