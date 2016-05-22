#include "Camera.h"

#include <assert.h>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(const glm::vec3 position, const glm::quat& orientation,
	float aspectRatio, float nearPlane, float farPlane, float fovOrSize, Camera::CameraType type)
	: transform{ position, orientation }
	, aspectRatio{ aspectRatio }
	, nearClippingPlane{ nearPlane }
	, farClippingPlane{ farPlane }
	, fovOrSize{ fovOrSize }
	, type{ type }
{
	assert(farClippingPlane > nearClippingPlane);
	assert(fovOrSize > 0.0f);
}

void Camera::Init()
{

}

Transform& Camera::GetTransform()
{
	// TODO: Use this!
	//return GetOwnerEntity().GetTransform();
	// ---------------

	return transform;
}

const Transform& Camera::GetTransform() const
{
	// TODO: Use this!
	//return GetOwnerEntity().GetTransform();
	// ---------------

	return transform;
}

glm::mat4 Camera::GetViewMatrix() const
{
	// TODO: Use correct transform!
	const Transform& transform = /*GetOwnerEntity().*/GetTransform();
	glm::mat4 negativePosition = glm::translate(glm::mat4(1.0), -transform.GetPosition());
	glm::mat4 negativeRotation = glm::toMat4(glm::conjugate(transform.GetOrientation()));

	return negativeRotation * negativePosition;
}

glm::mat4 Camera::GetProjectionMatrix() const
{
	glm::mat4 projection = glm::mat4(0.0);

	switch (this->type)
	{
		case CameraType::PERSPECTIVE:
		{
			// glm::perspective uses a right handed coordinate system
			// which I don't want, so below is my own version in
			// a left handed coordinate system.

			float const tanHalfFovY = tan(fovOrSize / 2.0f);

			projection[0][0] = 1.0f / (aspectRatio * tanHalfFovY);
			projection[1][1] = 1.0f / (tanHalfFovY);
			projection[2][2] = (nearClippingPlane + farClippingPlane) / (farClippingPlane - nearClippingPlane);
			projection[2][3] = 1.0f;
			projection[3][2] = -(2.0f * farClippingPlane * nearClippingPlane) / (farClippingPlane - nearClippingPlane);
			
		} break;

		case CameraType::ORTHOGRAPHIC:
		{
			float halfVerticalSize = fovOrSize;
			float halfDepth = (farClippingPlane - nearClippingPlane) * 0.5f;

			projection[0][0] = 1.0f / halfVerticalSize * aspectRatio;
			projection[1][1] = 1.0f / halfVerticalSize;
			projection[2][2] = 1.0f / halfDepth;
			projection[3][3] = 1.0f;

		} break;

		default:
		{
			assert(false);
			break;
		}
	}

	return projection;
}
