#include "Transform.h"

#include "Shader.h"

#include <glm/gtx/quaternion.hpp>

/*
Transform::Transform(glm::vec3 position, glm::vec3 rotation, float scale)
{
	glm::quat quaternionRotation;
	// TODO: Create quaternion from Euler angles

	Transform(position, quaternionRotation, scale);
}
*/

Transform::Transform(glm::vec3 position, glm::quat rotation, float scale)
	: position(position)
	, rotation(rotation)
	, scale(scale)
{
}

glm::mat4 Transform::GetModelMatrix() const
{
	glm::mat4 scaleMatrix = glm::mat4(scale);
	scaleMatrix[3][3] = 1.0f; // must be 1!

	glm::mat4 rotationMatrix = glm::toMat4(glm::normalize(rotation));

	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0), position);

	return translationMatrix * rotationMatrix *scaleMatrix;
}