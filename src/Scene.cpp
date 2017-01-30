#include "Scene.h"

#include "Renderable.h"

Scene::Scene()
{
}

std::shared_ptr<CameraComponent> Scene::GetMainCamera() const
{
	std::vector<std::shared_ptr<Entity>> cameras{};
	GetEntities<CameraComponent>(cameras);

	std::shared_ptr<CameraComponent> mainCamera;
	for (auto entity : cameras)
	{
		auto cameraComp = entity->GetComponent<CameraComponent>();
		if (cameraComp && cameraComp->GetTarget() == nullptr)
		{
			if (mainCamera != nullptr)
			{
				Logger::GetDefaultLogger().Log("More than one camera without target exist. Main camera not ambiguous!");
			}

			mainCamera = cameraComp;
		}
	}

	if (mainCamera == nullptr)
	{
		Logger::GetDefaultLogger().Log("No camera without target exist. No main camera available!");
	}

	return mainCamera;
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
