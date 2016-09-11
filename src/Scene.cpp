#include "Scene.h"

Scene::Scene()
{
}

std::shared_ptr<const CameraComponent> Scene::GetMainCamera() const
{
	// TODO: Maybe check if it's null. If it's null, maybe try to find some arbitrary camera to use,
	// or make some own default camera. Also warn about that...
	assert(mainCamera.expired() == false);
	return mainCamera.lock();
}

void Scene::SetMainCamera(std::shared_ptr<const CameraComponent> cameraComponent)
{
	this->mainCamera = cameraComponent;
}
