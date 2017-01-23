#pragma once

#include <memory>
#include <vector>

#include <glm/fwd.hpp>

#include "Entity.h"
#include "Camera.h"
#include "Lighting.h"

//
// Scene is the root entity of the scene graph and it defines the world origin
//
class Scene: public Entity
{
public:

	Scene();

	std::shared_ptr<const CameraComponent> GetMainCamera() const;
	void SetMainCamera(std::shared_ptr<const CameraComponent> cameraComponent);

	// Collect entities matching the filter (i.e. has the specified component) into a flat list of items
	template<typename Filter>
	void GetEntities(std::vector<std::shared_ptr<Entity>>& entities) const;

private:

	std::weak_ptr<const CameraComponent> mainCamera;

	// TODO: Add scene related items like:
	//  - Skybox
	//  - Ambient light
	//  - ?

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
