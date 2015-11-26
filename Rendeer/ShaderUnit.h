#pragma once

#include <string>

#include <glad/glad.h>

class ShaderUnit
{
public:

	enum class Type
	{
		VERTEX_SHADER = GL_VERTEX_SHADER,
		FRAGMENT_SHADER = GL_FRAGMENT_SHADER
		// Add more as they are supported/required
	};

public:

	ShaderUnit(const std::string& shaderSourcePath, ShaderUnit::Type type);
	~ShaderUnit();

	ShaderUnit::Type GetType() const;
	const std::string& GetSourceFilePath() const;

private:

	// Reads in a shader source file and includes "#included" files.
	static std::string ReadShaderSourceFile(const std::string& filePath);
	static const std::string INCLUDE_DIRECTIVE;

	// Non-copyable
	ShaderUnit(const ShaderUnit& other) = delete;
	ShaderUnit& operator=(ShaderUnit& other) = delete;

private:

	GLuint shaderUnitHandle;
	ShaderUnit::Type type;

	// Store the path of the source file to be able to keep track of loaded shaders
	const std::string sourceFilePath;

	// Only shader is allowed to access the shaderUnitHandle for compiling
	friend class Shader;

};

