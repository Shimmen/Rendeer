#pragma once

#include <glm/fwd.hpp>

#include "Transform.h"

class Camera
{
public:

	enum CameraType
	{
		PERSPECTIVE,
		ORTHOGRAPHIC
	};

public:

	Camera(const glm::vec3& position, const glm::quat& rotation, float aspectRatio,
		   float nearPlane, float farPlane, float fovOrSize, CameraType type = PERSPECTIVE);

	inline Transform& GetTransform() { return transform; }

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;

private:

	Transform transform;

	float aspectRatio;
	
	float nearClippingPlane;
	float farClippingPlane;
	
	CameraType type;
	float fovOrSize;

};
