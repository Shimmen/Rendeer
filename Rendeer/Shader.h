#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>

class Transform;
class Texture;
class Material;
class Buffer;

#ifndef SHADER_INCLUDE_DIRECTIVE
#define SHADER_INCLUDE_DIRECTIVE "#include"
#endif

class Shader
{
public:
	
	Shader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
	~Shader();

	void Bind() const;

	bool HasUniformWithName(const std::string& uniformName) const;

	void SetUniform(const std::string& uniformName, int intValue) const;
	void SetUniform(const std::string& uniformName, float floatValue) const;
	void SetUniform(const std::string& uniformName, const glm::vec2& vector2) const;
	void SetUniform(const std::string& uniformName, const glm::vec3& vector3) const;
	void SetUniform(const std::string& uniformName, const glm::mat3& matrix3) const;
	void SetUniform(const std::string& uniformName, const glm::mat4& matrix4) const;

	void SetUniformBlock(const std::string& uniformBlockName, const Buffer& buffer) const;

private:
	
	void LocateAndRegisterUniforms();

	std::string ReadFile(const std::string& filePath);
	GLuint CreateShaderComponent(const std::string& source, GLenum shaderType);
	void CheckShaderErrors(GLuint shader, int isProgram, GLuint stageFlag, const std::string& customMessage);

private:
	
	GLuint shaderProgram;
	std::map<std::string, bool> uniformExists;
	std::map<std::string, GLuint> uniformLocations;
	std::map<std::string, GLuint> uniformBlockIndicies;
	mutable int nextUniformBlockBinding;

};
