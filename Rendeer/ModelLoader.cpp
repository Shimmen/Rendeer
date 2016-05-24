#include "ModelLoader.h"

#include <memory>

#include "Entity.h"
#include "Renderable.h"
#include "DiffuseMaterial.h"

/* static */ Entity ModelLoader::Load(const std::string & filename)
{
	// TODO: Implement!

	Entity entity;
	entity.AddComponent(std::make_shared<Renderable>(Mesh{ "Test" }, DiffuseMaterial{}));

	return entity;
}
