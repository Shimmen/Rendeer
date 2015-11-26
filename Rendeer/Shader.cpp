#include "Shader.h"

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Logger.h"
#include "Buffer.h"
#include "Texture2D.h"
#include "ShaderUnit.h"

Shader::Shader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath)
{
	// Create shader components/units
	ShaderUnit vertexShader{ vertexShaderFilePath, ShaderUnit::Type::VERTEX_SHADER };
	ShaderUnit fragmentShader{ fragmentShaderFilePath, ShaderUnit::Type::FRAGMENT_SHADER };

	// Create program and attach components
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader.shaderUnitHandle);
	glAttachShader(shaderProgram, fragmentShader.shaderUnitHandle);

	// Link program
	glLinkProgram(shaderProgram);
	CheckShaderErrors(shaderProgram, GL_LINK_STATUS);

	// Validate program
	glValidateProgram(shaderProgram);
	CheckShaderErrors(shaderProgram, GL_VALIDATE_STATUS);

	// Release shader components from the program
	glDetachShader(shaderProgram, vertexShader.shaderUnitHandle);
	glDetachShader(shaderProgram, fragmentShader.shaderUnitHandle);
	
	LocateAndRegisterUniforms();
}

Shader::~Shader()
{
	glDeleteProgram(shaderProgram);
}

void Shader::Bind() const
{
	glUseProgram(shaderProgram);
}

bool Shader::HasUniformWithName(const std::string& uniformName) const
{
	return uniformExists.at(uniformName);
}

void Shader::SetUniform(const std::string& uniformName, int intValue) const
{
	glUniform1i(uniformLocations.at(uniformName), intValue);
}

void Shader::SetUniform(const std::string& uniformName, float floatValue) const
{
	glUniform1f(uniformLocations.at(uniformName), floatValue);
}

void Shader::SetUniform(const std::string& uniformName, const glm::vec2& vector2) const
{
	glUniform2fv(uniformLocations.at(uniformName), 1, glm::value_ptr(vector2));
}

void Shader::SetUniform(const std::string& uniformName, const glm::vec3& vector3) const
{
	glUniform3fv(uniformLocations.at(uniformName), 1, glm::value_ptr(vector3));
}

void Shader::SetUniform(const std::string& uniformName, const glm::mat3& matrix3) const
{
	glUniformMatrix3fv(uniformLocations.at(uniformName), 1, GL_FALSE, glm::value_ptr(matrix3));
}

void Shader::SetUniform(const std::string& uniformName, const glm::mat4& matrix4) const
{
	glUniformMatrix4fv(uniformLocations.at(uniformName), 1, GL_FALSE, glm::value_ptr(matrix4));
}

void Shader::SetUniformBlock(const std::string& uniformBlockName, const Buffer& buffer) const
{
	buffer.Bind(GL_UNIFORM_BUFFER);

	// Bind the uniform buffer to a unique binding. It's possible that the binding will not be unique,
	// but it's unlikely, since GL_MAX_UNIFORM_BUFFER_BINDINGS is quite large.
	GLuint binding = nextUniformBlockBinding;
	glBindBufferBase(GL_UNIFORM_BUFFER, binding, buffer.GetBufferHandle());

	// Connect the shader's uniform block index to the binding
	glUniformBlockBinding(shaderProgram, uniformBlockIndicies.at(uniformBlockName), binding);

	// Calculate next uniform binding
	nextUniformBlockBinding = (nextUniformBlockBinding + 1) % GetMaxNumberOfUniformBufferBindings();
}

void Shader::CheckShaderErrors(GLuint shaderProgram, GLenum stage) const
{
	assert(stage == GL_LINK_STATUS || stage == GL_VALIDATE_STATUS);

	GLint success;
	glGetProgramiv(shaderProgram, stage, &success);
	if (success == GL_FALSE)
	{
		const Logger& logger = Logger::GetDefaultLogger();
		if (stage == GL_LINK_STATUS)
		{
			logger.Log("Shader error: shader program could not be liked.");
		}
		else if (stage == GL_VALIDATE_STATUS)
		{
			logger.Log("Shader error: shader program could not be validated.");
		}

		GLchar errorMessage[2048];
		memset(errorMessage, '\0', sizeof(errorMessage));
		glGetProgramInfoLog(shaderProgram, sizeof(errorMessage), nullptr, errorMessage);

		logger.Log("\terror message:" + std::string(errorMessage));
	}
}

void Shader::LocateAndRegisterUniforms()
{
	static const int NAME_BUFFER_LENGTH = 512;

	this->Bind();

	int activeUniformCount = 0;
	glGetProgramiv(shaderProgram, GL_ACTIVE_UNIFORMS, &activeUniformCount);

	for (int i = 0; i < activeUniformCount; ++i)
	{
		char uniformName[NAME_BUFFER_LENGTH];
		int uniformNameLength;
		glGetActiveUniformName(shaderProgram, GLuint(i), NAME_BUFFER_LENGTH - 1, &uniformNameLength, uniformName);
		uniformName[uniformNameLength] = '\0';

		GLuint location = glGetUniformLocation(shaderProgram, uniformName);
		uniformLocations[uniformName] = location;
		uniformExists[uniformName] = true;
	}
	
	int activeUniformBlockCount = 0;
	glGetProgramiv(shaderProgram, GL_ACTIVE_UNIFORM_BLOCKS, &activeUniformBlockCount);

	for (int i = 0; i < activeUniformBlockCount; ++i)
	{
		char uniformBlockName[NAME_BUFFER_LENGTH];
		int uniformBlockNameLength;
		glGetActiveUniformBlockName(shaderProgram, GLuint(i), NAME_BUFFER_LENGTH - 1, &uniformBlockNameLength, uniformBlockName);
		uniformBlockName[uniformBlockNameLength] = '\0';

		GLuint blockIndex = glGetUniformBlockIndex(shaderProgram, uniformBlockName);
		uniformBlockIndicies[uniformBlockName] = blockIndex;
		uniformExists[uniformBlockName] = true;
	}
}

int Shader::GetMaxNumberOfUniformBufferBindings()
{
	if (Shader::maxNumberOfUniformBufferBindings == -1)
	{
		GLint64 count;
		glGetInteger64v(GL_MAX_UNIFORM_BUFFER_BINDINGS, &count);
		Shader::maxNumberOfUniformBufferBindings = static_cast<int>(count);
	}

	return Shader::maxNumberOfUniformBufferBindings;
}

/* static */ int Shader::maxNumberOfUniformBufferBindings{ -1 };
