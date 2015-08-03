#pragma once

#include <glm/glm.hpp>

#include "Transform.h"

class Camera
{
public:

	Camera(const glm::vec3& position, const glm::quat& rotation, float fov,
	       float near, float far, float aspectRatio, bool perspective = true);

	inline Transform& GetTransform() { return transform; }

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;

private:

	Transform transform;

	float fov;
	float nearClippingPlane;
	float farClippingPlane;
	float aspectRatio;

	bool isPerspective;

};
