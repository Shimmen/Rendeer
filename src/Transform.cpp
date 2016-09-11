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

glm::mat4 Transform::GetWorldMatrix() const
{
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), GetScaleInWorld());
	glm::mat4 rotationMatrix = glm::toMat4(glm::normalize(GetOrientationInWorld()));
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), GetPositionInWorld());

	return translationMatrix * rotationMatrix * scaleMatrix;
}

glm::vec3 Transform::GetPositionInWorld() const
{
	glm::vec3 worldPosition = GetPosition();

	const Transform *currentParent = GetParent();
	while (currentParent != nullptr)
	{
		worldPosition += currentParent->GetPosition();
		currentParent = currentParent->GetParent();
	}

	return worldPosition;
}

glm::quat Transform::GetOrientationInWorld() const
{
	glm::quat worldOrientation = GetOrientation();

	const Transform *currentParent = GetParent();
	while (currentParent != nullptr)
	{
		worldOrientation = currentParent->GetOrientation() * worldOrientation;
		currentParent = currentParent->GetParent();
	}

	return worldOrientation;
}

glm::vec3 Transform::GetScaleInWorld() const
{
	glm::vec3 worldScale = GetScale();

	const Transform *currentParent = GetParent();
	while (currentParent != nullptr)
	{
		worldScale *= currentParent->GetScale();
		currentParent = currentParent->GetParent();
	}

	return worldScale;
}

glm::vec3 Transform::GetRightInWorld() const
{
	return glm::normalize(RotateVector(glm::vec3{ 1, 0, 0 }, false));
}

glm::vec3 Transform::GetForwardInWorld() const
{
	return glm::normalize(RotateVector(glm::vec3{ 0, 0, 1 }, false));
}

glm::vec3 Transform::GetUpInWorld() const
{
	return glm::normalize(RotateVector(glm::vec3{ 0, 1, 0 }, false));
}

glm::vec3 Transform::RotateVector(const glm::vec3& vector, bool local) const
{
	auto quaternionToUse = (local) ? GetOrientation() : GetOrientationInWorld();
	return glm::rotate(quaternionToUse, vector);
}
