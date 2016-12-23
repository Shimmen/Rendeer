#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Logger.h"
#include "Buffer.h"
#include "Uniform.h"
#include "ShaderUnit.h"
#include "TextureBase.h"

/* static */ int Shader::maxNumberOfUniformBufferBindings{ -1 };
/* static */ GLuint Shader::currentlyBoundShaderProgram{ 0 };

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
	//glValidateProgram(shaderProgram);
	//CheckShaderErrors(shaderProgram, GL_VALIDATE_STATUS);

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
	if (this->shaderProgram != currentlyBoundShaderProgram)
	{
		glUseProgram(shaderProgram);
		currentlyBoundShaderProgram = this->shaderProgram;
	}
}

bool Shader::HasUniformWithName(const std::string& uniformName) const
{
	return uniforms.find(uniformName) != uniforms.end();
}

const Uniform *Shader::GetUniformWithName(const std::string& uniformName) const
{
	auto foundUniforms = uniforms.find(uniformName);
	if (foundUniforms != uniforms.end())
	{
		return &foundUniforms->second;
	}
	else
	{
		return nullptr;
	}
}

bool Shader::SetUniform(const std::string& uniformName, int intValue) const
{
	if (auto uniform = GetUniformWithName(uniformName))
	{
		uniform->Set(intValue);
		return true;
	}
	else
	{
		return false;
	}
}

bool Shader::SetUniform(const std::string& uniformName, float floatValue) const
{
	if (auto uniform = GetUniformWithName(uniformName))
	{
		uniform->Set(floatValue);
		return true;
	}
	else
	{
		return false;
	}
}

bool Shader::SetUniform(const std::string& uniformName, const glm::vec2& vector2) const
{
	if (auto uniform = GetUniformWithName(uniformName))
	{
		uniform->Set(vector2);
		return true;
	}
	else
	{
		return false;
	}
}

bool Shader::SetUniform(const std::string& uniformName, const glm::vec3& vector3) const
{
	if (auto uniform = GetUniformWithName(uniformName))
	{
		uniform->Set(vector3);
		return true;
	}
	else
	{
		return false;
	}
}

bool Shader::SetUniform(const std::string& uniformName, const glm::mat3& matrix3) const
{
	if (auto uniform = GetUniformWithName(uniformName))
	{
		uniform->Set(matrix3);
		return true;
	}
	else
	{
		return false;
	}
}

bool Shader::SetUniform(const std::string& uniformName, const glm::mat4& matrix4) const
{
	if (auto uniform = GetUniformWithName(uniformName))
	{
		uniform->Set(matrix4);
		return true;
	}
	else
	{
		return false;
	}
}

/*
bool Shader::SetUniform(const std::string& uniformName, const TextureBase& texture, int binding) const
{
    if (auto uniform = GetUniformWithName(uniformName))
    {
        // TODO: Make texture binding more generic (or similar) so that we can bind from the base class!
        texture.Bind(binding);
        uniform->Set(binding);
        return true;
    }
    else
    {
        return false;
    }
}
*/

bool Shader::SetUniformBlock(const std::string& uniformBlockName, const Buffer& buffer) const
{
	if (auto uniform = GetUniformWithName(uniformBlockName))
	{
		uniform->SetBlock(buffer);
		return true;
	}
	else
	{
		return false;
	}
}

GLuint Shader::GetNextUniformBlockBinding() const
{
	GLuint binding = nextUniformBlockBinding;

	// Calculate next binding
	nextUniformBlockBinding = (nextUniformBlockBinding + 1) % GetMaxNumberOfUniformBufferBindings();

	return binding;
}

GLuint Shader::GetProgramHandle() const
{
	return shaderProgram;
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
			logger.Log("Shader error: shader program could not be linked.");
		}
		else if (stage == GL_VALIDATE_STATUS)
		{
			logger.Log("Shader error: shader program could not be validated.");
		}

		GLchar errorMessage[2048];
		memset(errorMessage, '\0', sizeof(errorMessage));
		glGetProgramInfoLog(shaderProgram, sizeof(errorMessage), nullptr, errorMessage);

		logger.Log("\terror message: " + std::string(errorMessage));
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
		// Get uniform name
		char uniformName[NAME_BUFFER_LENGTH];
		int uniformNameLength;
		glGetActiveUniformName(shaderProgram, GLuint(i), NAME_BUFFER_LENGTH - 1, &uniformNameLength, uniformName);
		uniformName[uniformNameLength] = '\0';
		std::string name{uniformName};

		// Get uniform location
		GLint location = glGetUniformLocation(shaderProgram, uniformName);

		// There should definitly be no uniform name duplicates
		assert(uniforms.find(name) == uniforms.end());

		if (location != -1)
		{
			Uniform uniform{*this, name, static_cast<GLuint>(location)};
			uniforms.emplace(std::make_pair(name, uniform));
		}
		else
		{
			Logger::GetDefaultLogger().Log("Tried to add uniform with name '" + name + "' which isn't active / doesn't exist!");
		}
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
