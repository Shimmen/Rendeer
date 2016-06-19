#include "Transform.h"

#include <glm/gtc/quaternion.hpp>

#include "Shader.h"

Transform::Transform(glm::vec3 position, glm::vec3 eulerAngles)
	: Transform{ position, glm::quat{ eulerAngles } }
{
}

Transform::Transform(glm::vec3 position, glm::quat orientation, glm::vec3 scale)
	: position{ position }
	, orientation{ orientation }
	, scale{ scale }
{
}

const Transform* Transform::GetParent() const
{
	return this->parent;
}

void Transform::SetParent(const Transform *parent)
{
	this->parent = parent;
}

glm::vec3 Transform::GetRight() const
{
	return glm::normalize(RotateVector(glm::vec3{ 1, 0, 0 }, true));
}

glm::vec3 Transform::GetForward() const
{
	return glm::normalize(RotateVector(glm::vec3{ 0, 0, 1 }, true));
}

glm::vec3 Transform::GetUp() const
{
	return glm::normalize(RotateVector(glm::vec3{ 0, 1, 0 }, true));
}

glm::mat4 Transform::GetMatrix() const
{
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), this->scale);
	glm::mat4 rotationMatrix = glm::toMat4(glm::normalize(this->orientation));
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), this->position);

	// TODO: Don't forget about the parent matrix!
	return translationMatrix * rotationMatrix * scaleMatrix;
}

glm::vec3 Transform::RotateVector(const glm::vec3& vector, bool local) const
{
	auto quaternionToUse = /*(local) ? */GetOrientation()/* : GetOrientationInScene()*/;
	return glm::rotate(quaternionToUse, vector);
}
