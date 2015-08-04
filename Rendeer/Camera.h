#pragma once

#include <glm/glm.hpp>

#include "Transform.h"

class Camera
{
public:

	Camera(const glm::vec3& position, const glm::quat& orientation, float aspectRatio, float nearPlane, float farPlane);

	inline Transform& GetTransform() { return transform; }
	glm::mat4 GetViewMatrix() const;

	// Will be different for different camera types
	virtual glm::mat4 GetProjectionMatrix() const = 0;

protected:

	Transform transform;
	
	float aspectRatio;
	float nearClippingPlane;
	float farClippingPlane;

};

class PerspectiveCamera : public Camera
{
public:

	PerspectiveCamera(const glm::vec3& position, const glm::quat& orientation,
					  float aspectRatio, float nearPlane, float farPlane, float fov);

	glm::mat4 GetProjectionMatrix() const;

private:

	float fov;

};

class OrthographicCamera : public Camera
{
public:

	OrthographicCamera(const glm::vec3& position, const glm::quat& orientation,
					   float aspectRatio, float nearPlane, float farPlane, float size);

	glm::mat4 GetProjectionMatrix() const;

private:

	// Half of the vertical size of the viewing volume.
	float projectionSize;

};
