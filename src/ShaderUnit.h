#pragma once

#include <string>

#include <glad/glad.h>

#define INCLUDE_DIRECTIVE (std::string("#include "))

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

	// Non-copyable
	ShaderUnit(ShaderUnit& other) = delete;
	ShaderUnit& operator=(ShaderUnit& other) = delete;

private:

	// Reads and preprocesses a shader source file into a string
	static std::string ReadShaderSourceFile(const std::string& filePath);

	static bool IsIncludeLine(const std::string& line);
	static std::string GetFileNameFromIncludeLine(const std::string& line);

private:

	GLuint shaderUnitHandle;
	ShaderUnit::Type type;

	// Store the path of the source file to be able to keep track of loaded shaders
	const std::string sourceFilePath;

	// Only shader is allowed to access the shaderUnitHandle for compiling
	friend class Shader;

};

