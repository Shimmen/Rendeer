#pragma once

#include <glm/glm.hpp>

class PerspectiveCamera
{
public:
	PerspectiveCamera(const glm::vec3& position, const glm::vec3& rotation,
		float fov, float near, float far, float aspectRatio);
	~PerspectiveCamera();

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;

private:
	glm::vec3 position;
	glm::vec3 rotation;

	float fov;
	float nearClippingPlane, farClippingPlane;
	float aspectRatio;
};

