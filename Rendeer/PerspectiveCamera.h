#pragma once

#include <glm/glm.hpp>

#include "Transform.h"

/*
A perspective camera looking down the +Z axis.
*/

class PerspectiveCamera
{
public:
	PerspectiveCamera(const glm::vec3& position, const glm::vec3& rotation,
		float fov, float near, float far, float aspectRatio);

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;

private:
	Transform transform;

	float fov;
	float nearClippingPlane, farClippingPlane;
	float aspectRatio;
};

