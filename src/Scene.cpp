#include "Scene.h"

#include "Renderable.h"

Scene::Scene()
{
}

std::shared_ptr<CameraComponent> Scene::GetMainCamera() const
{
	return mainCamera;
}

void Scene::SetMainCamera(std::shared_ptr<CameraComponent> cameraComponent)
{
	this->mainCamera = cameraComponent;
}

std::shared_ptr<TextureCube> Scene::GetSkybox() const
{
	return skybox;
}

void Scene::SetSkybox(std::shared_ptr<TextureCube> skybox)
{
	this->skybox = skybox;
}

glm::vec3 Scene::GetAmbientColor() const
{
	return ambientColor;
}

void Scene::SetAmbientColor(glm::vec3 ambientColor)
{
	this->ambientColor = ambientColor;
}
