#include "PerspectiveCamera.h"

#include <assert.h>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

PerspectiveCamera::PerspectiveCamera(const glm::vec3& position, const glm::quat& rotation,
	float fov, float near, float far, float aspectRatio)
	: transform(position, rotation, 1)
	, fov(fov)
	, nearClippingPlane(near)
	, farClippingPlane(far)
	, aspectRatio(aspectRatio)
{
	assert(farClippingPlane > nearClippingPlane);
}

glm::mat4 PerspectiveCamera::GetViewMatrix() const
{
	glm::mat4 negativePosition = glm::translate(glm::mat4(1.0), -transform.GetPosition());
	glm::mat4 negativeRotation = glm::toMat4(glm::conjugate(transform.GetOrientation()));

	return negativeRotation * negativePosition;
}

glm::mat4 PerspectiveCamera::GetProjectionMatrix() const
{
	// glm::perspective uses a right handed coordinate system
	// which I don't want, so below is my own version in
	// a left handed coordinate system.

	// All cleared to zero.
	glm::mat4 projection = glm::mat4(0.0);

	float const tanHalfFovY = tan(fov / 2.0f);

	projection[0][0] = 1.0f / (aspectRatio * tanHalfFovY);
	projection[1][1] = 1.0f / (tanHalfFovY);
	projection[2][2] = (nearClippingPlane + farClippingPlane) / (farClippingPlane - nearClippingPlane);
	projection[2][3] = 1.0f;
	projection[3][2] = - (2.0f * farClippingPlane * nearClippingPlane) / (farClippingPlane - nearClippingPlane);

	return projection;
}
