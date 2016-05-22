#include "ModelLoader.h"

#include "Entity.h"
#include "DiffuseMaterial.h"

/* static */ Entity ModelLoader::Load(const std::string & filename)
{
	// TODO: Implement!

	return Entity{ Mesh{"test"}, DiffuseMaterial{} };
}
