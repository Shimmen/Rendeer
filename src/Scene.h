#pragma once

#include <memory>
#include <vector>

#include <glm/fwd.hpp>

#include "Entity.h"
#include "Camera.h"
#include "Lighting.h"

class TextureCube;

//
// Scene is the root entity of the scene graph and it defines the world origin
//
class Scene: public Entity
{
public:

	Scene();

	std::shared_ptr<CameraComponent> GetMainCamera() const;

	std::shared_ptr<TextureCube> GetSkybox() const;
	void SetSkybox(std::shared_ptr<TextureCube> skybox);

	glm::vec3 GetAmbientColor() const;
	void SetAmbientColor(glm::vec3 ambientColor);

	// Collect entities matching the filter (i.e. has the specified component) into a flat list of items
	template<typename Filter>
	void GetEntities(std::vector<std::shared_ptr<Entity>>& entities) const;

private:

	std::shared_ptr<TextureCube> skybox;
	glm::vec3 ambientColor;

};

template<typename Filter>
inline void Scene::GetEntities(std::vector<std::shared_ptr<Entity>>& entities) const
{
	for (auto child : GetDirectChildren())
	{
		if (child->GetComponent<Filter>() != nullptr)
		{
			entities.emplace_back(child);
		}

		auto childAsScene = static_cast<Scene *>(child.get());
		childAsScene->GetEntities<Filter>(entities);
	}
}
