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

Transform::Transform(glm::vec3 position, glm::quat orientation, float scale)
	: position(position)
	, orientation(orientation)
	, scale(scale)
{
}

glm::mat4 Transform::GetModelMatrix() const
{
	glm::mat4 scaleMatrix = glm::mat4(scale);
	scaleMatrix[3][3] = 1.0f;

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