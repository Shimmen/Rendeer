#pragma once

#include <glm/fwd.hpp>

#include "Transform.h"
#include "Component.h"

class Camera: Component
{
public:

	enum class CameraType
	{
		PERSPECTIVE,
		ORTHOGRAPHIC
	};

public:

	Camera(const glm::vec3 position, const glm::quat& orientation,
		float aspectRatio, float nearPlane, float farPlane, float fovOrSize, CameraType type = CameraType::PERSPECTIVE);

	virtual void Init();

	Transform& GetTransform();
	const Transform& GetTransform() const;

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;

private:

	// TODO: Remove this, it exists in the component owner
	Transform transform;
	// -----------------------------------------------------

	float aspectRatio;
	
	float nearClippingPlane;
	float farClippingPlane;
	
	CameraType type;
	float fovOrSize;

};
