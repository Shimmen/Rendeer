#pragma once

#include <memory>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>

class Shader;

class Transform
{
public:

	Transform(
		glm::vec3 position = glm::vec3{ 0, 0, 0 },
		glm::vec3 eulerAngles = glm::vec3{ 0, 0, 0 }
	);

	Transform(
		glm::vec3 position = glm::vec3{ 0.0, 0.0, 0.0 },
		glm::quat orientation = glm::angleAxis(1.0f, glm::vec3{ 0.0 }),
		glm::vec3 scale = glm::vec3{ 1.0f, 1.0f, 1.0f }
	);

	glm::mat4 GetModelMatrix() const;

	inline glm::vec3 GetPosition() const
	{
		return position;
	}

	inline glm::quat GetOrientation() const
	{
		return orientation;
	}

	inline glm::vec3 GetScale() const
	{
		return scale;
	}

	inline Transform& SetPosition(const glm::vec3& newPosition)
	{
		this->position = newPosition;
		return *this;
	}

	inline Transform& SetOrientation(const glm::vec3 axis, float angle)
	{
		SetOrientation(glm::angleAxis(angle, glm::normalize(axis)));
		return *this;
	}

	inline Transform& SetOrientation(const glm::quat newRotation)
	{
		this->orientation = glm::normalize(newRotation);
		return *this;
	}

	inline Transform& SetScale(float newScale)
	{
		this->scale = glm::vec3(newScale);
		return *this;
	}

	inline Transform& SetScale(const glm::vec3& newScale)
	{
		this->scale = newScale;
		return *this;
	}

	inline Transform& Translate(const glm::vec3& translation)
	{
		this->position += translation;
		return *this;
	}

	inline Transform& Scale(float scaleFactor)
	{
		this->scale *= scaleFactor;
		return *this;
	}

	inline Transform& Scale(const glm::vec3& scaleFactor)
	{
		this->scale *= scaleFactor;
		return *this;
	}

	inline Transform& Rotate(const glm::vec3 axis, float angle)
	{
		glm::quat quaternionRotation = glm::angleAxis(angle, glm::normalize(axis));
		return Rotate(quaternionRotation);
	}

	inline Transform& Rotate(const glm::quat rotation)
	{
		this->orientation = glm::normalize(rotation * this->orientation);
		return *this;
	}

	glm::vec3 RotateVector(const glm::vec3& vector) const;
	glm::vec4 RotateVector(const glm::vec4& vector) const;

	glm::vec3 GetRight() const;
	glm::vec3 GetForward() const;
	glm::vec3 GetUp() const;

	Transform GetInverse() const;

	const Transform *GetParent() const;
	void SetParent(const Transform *parent);

private:

	glm::vec3 position;
	glm::quat orientation;
	glm::vec3 scale;

	// Could also be a weak_ptr, but since Transforms are stored as members, there are no shared_ptrs
	// to them anywhere and weak_ptrs can only be created from shared_ptr, not raw pointers.
	const Transform *parent;

};
