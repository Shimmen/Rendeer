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

	Shader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath, const std::string& definitions = "");
	~Shader();

	void Reload();
	static void ReloadAll();

	bool Validate() const;
	void Bind() const;

	bool HasUniformWithName(const std::string& uniformName) const;
	const Uniform *GetUniformWithName(const std::string& uniformName) const;

	bool SetUniform(const std::string& uniformName, int intValue) const;
	bool SetUniform(const std::string& uniformName, float floatValue) const;
	bool SetUniform(const std::string& uniformName, const glm::vec2& vector2) const;
	bool SetUniform(const std::string& uniformName, const glm::vec3& vector3) const;
	bool SetUniform(const std::string& uniformName, const glm::vec4& vector4) const;
	bool SetUniform(const std::string& uniformName, const glm::mat3& matrix3) const;
	bool SetUniform(const std::string& uniformName, const glm::mat4& matrix4) const;

	bool SetUniformBlock(const std::string& uniformBlockName, const Buffer& buffer) const;
	GLuint GetNextUniformBlockBinding() const;

	GLuint GetProgramHandle() const;

private:

	static GLuint ReadAndCompileShader(const std::string& filePath, GLenum shaderType, const std::string& definitions);
	static std::string ReadShaderSourceFile(const std::string& filePath, const std::string& definitions);
	static std::string GetFileNameFromIncludeLine(const std::string& line);
	static bool CheckShaderProgramErrors(GLuint shaderProgram, GLenum stage);

	void LocateAndRegisterUniforms();

private:

	std::string vertexShaderFilePath;
	std::string fragmentShaderFilePath;
	std::string definitions;

	std::map<std::string, Uniform> uniforms;
	std::map<std::string, GLuint> uniformBlockIndicies;
	mutable GLuint nextUniformBlockBinding;

	static std::vector<Shader *> createdShaders;

	static int GetMaxNumberOfUniformBufferBindings();
	static int maxNumberOfUniformBufferBindings;
	static GLuint currentlyBoundShaderProgram;

};
