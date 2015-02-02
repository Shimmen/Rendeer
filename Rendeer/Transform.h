#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Shader;

/*
Defines a left-handed coordinate system.
*/

class Transform
{
public:
	Transform(
		glm::vec3 position = glm::vec3(0.0, 0.0, 0.0),
		glm::vec3 rotation = glm::vec3(0.0, 0.0, 0.0),
		glm::vec3 scale    = glm::vec3(1.0, 1.0, 1.0)
	);

	glm::mat4 GetModelMatrix() const;

	// TODO: Modifiers (like translate)!

	inline glm::vec3 GetPosition() const
	{
		return position;
	}
	
	inline glm::vec3 GetRotation() const
	{
		return rotation;
	}

	inline glm::vec3 GetScale() const
	{
		return scale;
	}

	inline Transform* SetPosition(const glm::vec3& newPosition)
	{
		this->position = newPosition;
		return this;
	}
	
	inline Transform* SetRotation(const glm::vec3& newRotation)
	{
		this->rotation = glm::radians(newRotation);
		return this;
	}
	
	inline Transform* SetScale(const glm::vec3& newScale)
	{
		this->scale = newScale;
		return this;
	}

private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};
