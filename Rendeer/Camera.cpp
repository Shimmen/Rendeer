#include "Camera.h"

#include <assert.h>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(const glm::vec3& position, const glm::quat& orientation, float aspectRatio, float nearPlane, float farPlane)
	: transform(position, orientation, 1)
	, aspectRatio(aspectRatio)
	, nearClippingPlane(nearPlane)
	, farClippingPlane(farPlane)
{
	assert(nearClippingPlane < farClippingPlane);
}

glm::mat4 Camera::GetViewMatrix() const
{
	glm::mat4 inverseTranslation = glm::translate(glm::mat4(1.0), -transform.GetPosition());
	glm::mat4 inverseOrientation = glm::toMat4(glm::conjugate(transform.GetOrientation()));

	return inverseOrientation * inverseTranslation;
}

PerspectiveCamera::PerspectiveCamera(const glm::vec3& position, const glm::quat& orientation,
									 float aspectRatio, float nearPlane, float farPlane, float fov)
	: Camera(position, orientation, aspectRatio, nearPlane, farPlane)
	, fov(fov)
{
	assert(fov > 0.0f && fov < glm::radians(180.0f));
}


glm::mat4 PerspectiveCamera::GetProjectionMatrix() const
{
	// glm::perspective uses a right handed coordinate system
	// which I don't want, so below is my own version in
	// a left handed coordinate system.

	glm::mat4 projection = glm::mat4(0.0);
	float const tanHalfFovY = tan(fov / 2.0f);

	projection[0][0] = 1.0f / (aspectRatio * tanHalfFovY);
	projection[1][1] = 1.0f / (tanHalfFovY);
	projection[2][2] = (nearClippingPlane + farClippingPlane) / (farClippingPlane - nearClippingPlane);
	projection[2][3] = 1.0f;
	projection[3][2] = -(2.0f * farClippingPlane * nearClippingPlane) / (farClippingPlane - nearClippingPlane);

	return projection;
}

OrthographicCamera::OrthographicCamera(const glm::vec3& position, const glm::quat& orientation,
				                       float aspectRatio, float nearPlane, float farPlane, float size)
	: Camera(position, orientation, aspectRatio, nearPlane, farPlane)
	, projectionSize(size)
{
	assert(projectionSize != 0.0f);
}

glm::mat4 OrthographicCamera::GetProjectionMatrix() const
{
	// TODO: Implement ortographic projection matrix based on projectionSize, near, and far.
	return glm::mat4(0.0f);
}