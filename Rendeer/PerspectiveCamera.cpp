#include "PerspectiveCamera.h"

#include <assert.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

PerspectiveCamera::PerspectiveCamera(const glm::vec3& position, const glm::vec3& rotation,
	float fov, float near, float far, float aspectRatio)
	: transform(position, rotation, glm::vec3())
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

	// TODO: Quaternions! If transform was defined with quaternions, getting the negative
	// rotation is as easy as transform.GetRotation().Conjugate();

	/*
	glm::mat4 negativeXRotation = glm::rotate(glm::mat4(1.0), transform.GetRotation().x, glm::vec3(1, 0, 0));
	glm::mat4 negativeYRotation = glm::rotate(glm::mat4(1.0), transform.GetRotation().y, glm::vec3(0, 1, 0));
	glm::mat4 negativeZRotation = glm::rotate(glm::mat4(1.0), transform.GetRotation().z, glm::vec3(0, 0, 1));
	glm::mat4 negativeRotation = negativeXRotation * negativeYRotation * negativeZRotation;
	*/

	return /*negativeRotation */ negativePosition;
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
	projection[2][2] = (-nearClippingPlane - farClippingPlane) / (nearClippingPlane - farClippingPlane);
	projection[2][3] = 1.0f;
	projection[3][2] = (2.0f * farClippingPlane * nearClippingPlane) / (nearClippingPlane - farClippingPlane);

	return projection;
}