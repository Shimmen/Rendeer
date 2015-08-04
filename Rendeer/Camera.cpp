#include "Camera.h"

#include <assert.h>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(const glm::vec3& position, const glm::quat& rotation, float fov,
	           float near, float far, float aspectRatio, bool perspective)
	: transform(position, rotation, 1)
	, fov(fov)
	, nearClippingPlane(near)
	, farClippingPlane(far)
	, aspectRatio(aspectRatio)
	, isPerspective(perspective)
{
	assert(farClippingPlane > nearClippingPlane);
	assert(fov > 0.0f);
}

glm::mat4 Camera::GetViewMatrix() const
{
	glm::mat4 negativePosition = glm::translate(glm::mat4(1.0), -transform.GetPosition());
	glm::mat4 negativeRotation = glm::toMat4(glm::conjugate(transform.GetOrientation()));

	return negativeRotation * negativePosition;
}

glm::mat4 Camera::GetProjectionMatrix() const
{
	glm::mat4 projection = glm::mat4(0.0);
	float const tanHalfFovY = tan(fov / 2.0f);

	if (isPerspective)
	{
		// glm::perspective uses a right handed coordinate system
		// which I don't want, so below is my own version in
		// a left handed coordinate system.

		projection[0][0] = 1.0f / (aspectRatio * tanHalfFovY);
		projection[1][1] = 1.0f / (tanHalfFovY);
		projection[2][2] = (nearClippingPlane + farClippingPlane) / (farClippingPlane - nearClippingPlane);
		projection[2][3] = 1.0f;
		projection[3][2] = -(2.0f * farClippingPlane * nearClippingPlane) / (farClippingPlane - nearClippingPlane);
	}
	else // orthographic
	{
		float width  = tanHalfFovY * farClippingPlane * aspectRatio * 2.0f;
		float height = tanHalfFovY * farClippingPlane * 2.0f;
		float depth  = farClippingPlane - nearClippingPlane;

		projection[0][0] = 2.0f / width;
		projection[1][1] = 2.0f / height;
		projection[2][2] = 1.0f / depth;
		projection[3][2] = -nearClippingPlane / depth;
		projection[3][3] = 1.0f;
	}

	return projection;
}
