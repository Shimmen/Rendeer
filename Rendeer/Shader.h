#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include <glad/glad.h>
#include <glm/fwd.hpp>

class Transform;
class Texture;
class Material;
class Buffer;

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
	
	void CheckShaderErrors(GLuint shaderProgram, GLenum stage) const;
	void LocateAndRegisterUniforms();

	Shader(Shader&) = delete;
	Shader& operator=(Shader&) = delete;

private:

	GLuint shaderProgram;

	std::map<std::string, bool> uniformExists;
	std::map<std::string, GLuint> uniformLocations;
	std::map<std::string, GLuint> uniformBlockIndicies;
	mutable int nextUniformBlockBinding;

public:

	static int GetMaxNumberOfUniformBufferBindings();

private:

	static int maxNumberOfUniformBufferBindings;

};
