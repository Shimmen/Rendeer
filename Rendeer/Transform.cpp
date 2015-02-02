#include "Transform.h"

#include "Shader.h"

Transform::Transform(
	glm::vec3 position,	glm::vec3 rotation,	glm::vec3 scale)
	: position(position)
	, rotation(rotation)
	, scale(scale)
{
}

glm::mat4 Transform::GetModelMatrix() const
{
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0), scale);

	// TODO: Implement with quaternions!
	glm::mat4 xRotation = glm::rotate(glm::mat4(1.0), rotation.x, glm::vec3(1, 0, 0));
	glm::mat4 yRotation = glm::rotate(glm::mat4(1.0), rotation.y, glm::vec3(0, 1, 0));
	glm::mat4 zRotation = glm::rotate(glm::mat4(1.0), rotation.z, glm::vec3(0, 0, 1));
	glm::mat4 rotationMatrix = xRotation * yRotation * zRotation;

	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0), position);

	return translationMatrix * rotationMatrix * scaleMatrix;
}