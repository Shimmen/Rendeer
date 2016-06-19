#include "Scene.h"

Scene::Scene()
{
}

std::weak_ptr<CameraComponent> Scene::GetMainCamera() const
{
	// TODO: Maybe check if it's null. If it's null, maybe try to find some arbitrary camera to use,
	// or make some own default camera. Also warn about that...
	return mainCamera;
}
