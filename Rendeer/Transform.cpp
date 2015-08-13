#include "Transform.h"

#include "Shader.h"

/*
Transform::Transform(glm::vec3 position, glm::vec3 rotation, float scale)
{
	glm::quat quaternionRotation;
	// TODO: Create quaternion from Euler angles

	Transform(position, quaternionRotation, scale);
}
*/

Transform::Transform(glm::vec3 position, glm::quat orientation, glm::vec3 scale)
	: position(position)
	, orientation(orientation)
	, scale(scale)
{
}

glm::mat4 Transform::GetModelMatrix() const
{
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), this->scale);
	//scaleMatrix[3][3] = 1.0f;

	glm::mat4 rotationMatrix = glm::toMat4(glm::normalize(orientation));

	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0), position);

	return translationMatrix * rotationMatrix * scaleMatrix;
}

glm::vec3 Transform::RotateVector(const glm::vec3& vector3) const
{
	return RotateVector(glm::vec4(vector3, 0));
}

glm::vec3 Transform::RotateVector(const glm::vec4& vector) const
{
	return glm::vec3(glm::rotate(this->orientation, vector));
}

glm::vec3 Transform::GetRight() const
{
	return glm::normalize(RotateVector(glm::vec4(1, 0, 0, 0)));
}

glm::vec3 Transform::GetForward() const
{
	return glm::normalize(RotateVector(glm::vec4(0, 0, 1, 0)));
}

glm::vec3 Transform::GetUp() const
{
	return glm::normalize(RotateVector(glm::vec4(0, 1, 0, 0)));
}

Transform Transform::GetInverse() const
{
	auto inversePosition = -this->position;
	auto conjugateOrientation = glm::conjugate(this->orientation);
	auto inverseScale = 1.0f / this->scale;
	return Transform(inversePosition, conjugateOrientation, inverseScale);
}
