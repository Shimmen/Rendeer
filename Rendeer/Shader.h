#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <map>

#include <glad/glad.h>
#include <glm/glm.hpp>

class Transform;
class Texture;
class Material;


#define SHADER_ALWAYS_CHECK_IF_UNIFORM_EXISTS


class Shader
{
public:
	Shader(const std::string& vertexShaderFilePath,
		const std::string& fragmentShaderFilePath);
	~Shader();

	inline void Bind() const
	{
		glUseProgram(shaderProgram);
	}

	inline void Unbind() const
	{
		glUseProgram(0);
	}

	bool HasUniformWithName(const std::string& uniformName);

	// It is your own responsibility to keep track of the types of the uniforms
	void SetUniform(const std::string& uniformName, int intValue);
	void SetUniform(const std::string& uniformName, float floatValue);
	void SetUniform(const std::string& uniformName, const glm::vec2& vector2);
	void SetUniform(const std::string& uniformName, const glm::vec3& vector3);
	void SetUniform(const std::string& uniformName, const glm::mat3& matrix3);
	void SetUniform(const std::string& uniformName, const glm::mat4& matrix4);

private:
	GLuint shaderProgram;
	std::map<std::string, GLuint> uniformLocations;
	std::map<std::string, bool> uniformExist;

	// Uniform "finding"
	void LocateAndRegisterUniforms();

	// Shader creation
	const std::string INCLUDE_DIRECTIVE = "#include";

	std::string ReadFile(const std::string& filePath);
	GLuint CreateShaderComponent(const std::string& source, GLenum shaderType);
	void CheckShaderErrors(GLuint shader, int isProgram, GLuint stageFlag,
		const std::string& customMessage);
};
