#include "Transform.h"

#include "Shader.h"

Transform::Transform(
	glm::vec3 position,	glm::vec3 rotation,	glm::vec3 scale)
	: position(position)
	, rotation(rotation)
	, scale(scale)
{
}

void Transform::UpdateUniforms(const Shader& shader)
{
	// TODO: Set uniform for ModelMatrix!
}

glm::mat4 Transform::GetModelMatrix() const
{
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0), scale);

	// FIXME: This is incorrect, right?
	//glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0), rotation.x, glm::vec3(1, 0, 0));
	//rotationMatrix =           glm::rotate(rotationMatrix, rotation.y, glm::vec3(0, 1, 0));
	//rotationMatrix =           glm::rotate(rotationMatrix, rotation.z, glm::vec3(0, 0, 1));

	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0), position);

	return translationMatrix * /*rotationMatrix **/ scaleMatrix;
}