#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include <glad/glad.h>
#include <glm/fwd.hpp>

#include "GLResource.h"

class Transform;
class Material;
class TextureBase;
class Uniform;
class Buffer;

class Shader: public GLResource
{
public:
	
	Shader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
	~Shader();

	void Bind() const;

	bool HasUniformWithName(const std::string& uniformName) const;
	const Uniform *GetUniformWithName(const std::string& uniformName) const;

	bool SetUniform(const std::string& uniformName, int intValue) const;
	bool SetUniform(const std::string& uniformName, float floatValue) const;
	bool SetUniform(const std::string& uniformName, const glm::vec2& vector2) const;
	bool SetUniform(const std::string& uniformName, const glm::vec3& vector3) const;
	bool SetUniform(const std::string& uniformName, const glm::mat3& matrix3) const;
	bool SetUniform(const std::string& uniformName, const glm::mat4& matrix4) const;

	/* TODO: Implement!
	bool SetUniform(const std::string& uniformName, const TextureBase& texture, int binding) const;
	*/

	bool SetUniformBlock(const std::string& uniformBlockName, const Buffer& buffer) const;
	GLuint GetNextUniformBlockBinding() const;

	GLuint GetProgramHandle() const;

private:
	
	void CheckShaderErrors(GLuint shaderProgram, GLenum stage) const;
	void LocateAndRegisterUniforms();

private:

	std::map<std::string, Uniform> uniforms;
	std::map<std::string, GLuint> uniformBlockIndicies;
	mutable GLuint nextUniformBlockBinding;

public:

	static int GetMaxNumberOfUniformBufferBindings();

private:

	static int maxNumberOfUniformBufferBindings;
	static GLuint currentlyBoundShaderProgram;

};
