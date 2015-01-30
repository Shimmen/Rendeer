#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Shader;

class Transform
{
public:
	Transform(
		glm::vec3 position = glm::vec3(0.0, 0.0, 0.0),
		glm::vec3 rotation = glm::vec3(0.0, 0.0, 0.0),
		glm::vec3 scale    = glm::vec3(1.0, 1.0, 1.0)
	);

	glm::mat4 GetModelMatrix() const;

	// TODO: Getters and setters!

private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};
