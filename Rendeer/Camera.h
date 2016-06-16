#pragma once

#include <glm/fwd.hpp>

#include "Transform.h"
#include "Component.h"

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

class Camera: public Entity
{
public:

	Camera();
	Camera(glm::vec3 position, glm::quat orientation);
	Camera(glm::vec3 position, glm::quat orientation,
		float aspectRatio, float nearPlane, float farPlane, float fovOrSize, CameraComponent::CameraType type = CameraComponent::CameraType::PERSPECTIVE);

	// Delegates to the CameraComponent
	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;

};