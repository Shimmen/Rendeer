#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <map>

#include <GL/glew.h>
#include <glm/glm.hpp>

class Transform;
class Texture;
struct Material;


#define SHADER_ALWAYS_BIND_WHEN_NEEDED

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
	
	bool HasUniformWithName(const std::string& uniformName);
	
	// It is your own responsibility to keep track of the types of the uniforms
	void SetUniform(const std::string& uniformName, int intValue);
	void SetUniform(const std::string& uniformName, float floatValue);
	void SetUniform(const std::string& uniformName, const glm::vec2& vector2);
	void SetUniform(const std::string& uniformName, const glm::vec3& vector3);
	void SetUniform(const std::string& uniformName, const glm::mat3& matrix3);
	void SetUniform(const std::string& uniformName, const glm::mat4& matrix4);

	// TODO: Remove this, shader handles should be abstracted away for outside this class
	inline GLuint GetHandle() { return shaderProgram; }

private:
	GLuint shaderProgram;
	std::map<std::string, GLuint> uniformLocations;

	// Uniform "finding"
	void LocateAndRegisterUniforms();

	// Shader creation
	std::string ReadFile(const std::string& filePath);
	GLuint CreateShaderComponent(const std::string& source, GLenum shaderType);
	void CheckShaderErrors(GLuint shader, int isProgram, GLuint stageFlag,
		const std::string& customMessage);
};

