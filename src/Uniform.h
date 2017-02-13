#pragma once

#include <string>

#include <glad/glad.h>
#include <glm/fwd.hpp>

class Shader;
class Buffer;

class Uniform
{
public:

	Uniform(Shader& shader, const std::string& name, GLuint location);
	~Uniform();

	void Set(int intValue) const;
	void Set(float floatValue) const;
	void Set(const glm::vec2& vector2) const;
	void Set(const glm::vec3& vector3) const;
	void Set(const glm::vec4& vector4) const;
	void Set(const glm::mat3& matrix3) const;
	void Set(const glm::mat4& matrix4) const;
	
	void SetBlock(const Buffer& buffer) const;

private:

	Shader& shader;

	std::string name;
	GLuint location;

};

