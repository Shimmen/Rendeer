#include "Uniform.h"

#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "Buffer.h"

Uniform::Uniform(Shader& shader, const std::string& name, GLuint location)
	: shader(shader)
	, name(name)
	, location(location)
{
}

Uniform::~Uniform()
{
}

void Uniform::Set(int intValue) const
{
	shader.Bind();
	glUniform1i(location, intValue);
}

void Uniform::Set(float floatValue) const
{
	shader.Bind();
	glUniform1f(location, floatValue);
}

void Uniform::Set(const glm::vec2& vector2) const
{
	shader.Bind();
	glUniform2fv(location, 1, glm::value_ptr(vector2));
}

void Uniform::Set(const glm::vec3& vector3) const
{
	shader.Bind();
	glUniform3fv(location, 1, glm::value_ptr(vector3));
}

void Uniform::Set(const glm::mat3& matrix3) const
{
	shader.Bind();
	glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix3));
}

void Uniform::Set(const glm::mat4& matrix4) const
{
	shader.Bind();
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix4));
}

void Uniform::SetBlock(const Buffer& buffer) const
{
	// Location in this case refers to the uniform block index
	const GLuint blockIndex = this->location;

	GLuint binding = shader.GetNextUniformBlockBinding();

	buffer.BindAsUniformBuffer(binding);
	glUniformBlockBinding(shader.GetProgramHandle(), blockIndex, binding);
}
