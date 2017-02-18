#pragma once

#include <string>
#include <vector>

#include <glad/glad.h>

#include "GLResource.h"

#define INCLUDE_DIRECTIVE std::string("#include ")
#define VERSION_DIRECTIVE std::string("#version ")

class ShaderUnit: public GLResource
{
public:

	enum class Type
	{
		VERTEX_SHADER = GL_VERTEX_SHADER,
		FRAGMENT_SHADER = GL_FRAGMENT_SHADER
		// Add more as they are supported/required
	};

public:

	ShaderUnit(const std::string& shaderSourcePath, ShaderUnit::Type type, const std::vector<std::string>& definitions);
	~ShaderUnit();

	ShaderUnit::Type GetType() const;
	const std::string& GetSourceFilePath() const;

private:

	// Reads and preprocesses a shader source file into a string
	static std::string ReadShaderSourceFile(const std::string& filePath, const std::vector<std::string>& definitions);

	static std::string GetFileNameFromIncludeLine(const std::string& line);

private:

	ShaderUnit::Type type;

	// Store the path of the source file to be able to keep track of loaded shaders
	const std::string sourceFilePath;

	// Only shader is allowed to access the handle (for compiling and stuff)
	friend class Shader;
	GLuint getHandle() const { return handle; }


};

