#include "Scene.h"

#include "Renderable.h"

Scene::Scene()
{
}

std::shared_ptr<const CameraComponent> Scene::GetMainCamera() const
{
	// TODO: Maybe check if it's null. If it's null, maybe try to find some arbitrary camera to use,
	// or make some own default camera. Also warn about that...
	assert(!mainCamera.expired());
	return mainCamera.lock();
}

void Scene::SetMainCamera(std::shared_ptr<const CameraComponent> cameraComponent)
{
	this->mainCamera = cameraComponent;
}

void Scene::GetEntities(std::vector<std::shared_ptr<Entity>>& entities) const
{
	for (auto child : GetDirectChildren())
	{
		entities.emplace_back(child);

		auto childAsScene = static_cast<Scene *>(child.get());
		childAsScene->GetEntities(entities);
	}	
}
