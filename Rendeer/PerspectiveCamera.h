#pragma once

#include <glm/glm.hpp>

#include "Transform.h"

/*
A perspective camera looking down the +Z axis.
*/

class PerspectiveCamera
{
public:

	PerspectiveCamera(const glm::vec3& position, const glm::quat& rotation,
		float fov, float near, float far, float aspectRatio);

	inline Transform& GetTransform() { return transform; }

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;

	float GetFov() const { return fov; }
	void SetFov(float fov) { this->fov = fov; }

private:

	Transform transform;

	float fov;
	float nearClippingPlane;
	float farClippingPlane;
	float aspectRatio;

};
