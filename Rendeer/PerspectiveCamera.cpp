#include "PerspectiveCamera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

PerspectiveCamera::PerspectiveCamera(const glm::vec3& position, const glm::vec3& rotation,
	float aspectRatio, float fov = 45.0, float near = 1.0, float far = 1000.0) :
	position(position),
	rotation(rotation),
	aspectRatio(aspectRatio),
	fov(fov),
	nearClippingPlane(near),
	farClippingPlane(far)
{
}


PerspectiveCamera::~PerspectiveCamera()
{
}

glm::mat4 PerspectiveCamera::GetViewMatrix() const
{
	glm::mat4 view;

	view = glm::translate(view, -position);

	// TODO: Should I move straight to quaternions?
	//glm::rotate(&view, glm::radians(), rotation);

	return view;
}

glm::mat4 PerspectiveCamera::GetProjectionMatrix() const
{
	glm::mat4 projection = glm::perspective(fov, aspectRatio,
		nearClippingPlane, farClippingPlane);

	return projection;
}