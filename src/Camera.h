#pragma once

#include <glm/fwd.hpp>

#include "Component.h"

class Window;

class CameraComponent: public Component
{
public:

	enum class CameraType
	{
		PERSPECTIVE,
		ORTHOGRAPHIC
	};

public:

	CameraComponent(float aspectRatio, float nearPlane, float farPlane, float fovOrSize, CameraType type = CameraType::PERSPECTIVE);

	virtual void Init() {};

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;

private:

	float aspectRatio;
	
	float nearClippingPlane;
	float farClippingPlane;
	
	CameraType type;
	float fovOrSize;

};

//
// An entity containing a CameraComponent that encapsulates all camera behaviour (like movement and view/projection)
//
class Camera: public Entity
{
public:

	Camera();
	Camera(glm::vec3 position, glm::quat orientation);
	Camera(glm::vec3 position, glm::quat orientation,
		float aspectRatio, float nearPlane, float farPlane, float fovOrSize, CameraComponent::CameraType type = CameraComponent::CameraType::PERSPECTIVE);

	void Update(float deltaTime, const Window& window);

	// Delegates to the CameraComponent
	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;

};
