#pragma once

#include <memory>
#include <vector>

#include <glm/fwd.hpp>

#include "Entity.h"
#include "Camera.h"
#include "Lighting.h"

/*
 *
 * Scene is the root entity of the scene graph and it defines the world origin
 *
 */
class Scene: public Entity
{
public:

	Scene();

	std::shared_ptr<const CameraComponent> GetMainCamera() const;
	void SetMainCamera(std::shared_ptr<const CameraComponent> cameraComponent);

	// Collect all entities into a flat list of items
	void GetEntities(std::vector<std::shared_ptr<Entity>>& entities) const;

private:

	std::weak_ptr<const CameraComponent> mainCamera;

	// Add scene related items like:
	//  - Skybox
	//  - Ambient light
	//  - ?

};

