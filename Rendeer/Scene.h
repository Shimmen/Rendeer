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

	std::weak_ptr<CameraComponent> GetMainCamera() const;

private:

	std::weak_ptr<CameraComponent> mainCamera;

	// Add scene related items like:
	//  - Skybox
	//  - Ambient light
	//  - ?

};

