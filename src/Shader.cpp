#include "Shader.h"

#include <fstream>
#include <sstream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Logger.h"
#include "Buffer.h"
#include "Uniform.h"
#include "GeneralUtil.h"

#define INCLUDE_DIRECTIVE ("#include ")
#define VERSION_DIRECTIVE ("#version ")

/* static */ std::vector<Shader *> Shader::createdShaders{};
/* static */ GLuint Shader::currentlyBoundShaderProgram{ 0 };
/* static */ int Shader::maxNumberOfUniformBufferBindings{ -1 };

Shader::Shader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath, const std::string& definitions)
	: vertexShaderFilePath(vertexShaderFilePath)
	, fragmentShaderFilePath(fragmentShaderFilePath)
	, definitions(definitions)
{
	Reload();
	createdShaders.push_back(this);
}

Shader::~Shader()
{
	if (glIsProgram(handle))
	{
		glDeleteProgram(handle);
	}
}

void Shader::Reload()
{
	GLuint program = glCreateProgram();

	GLuint vertexShader = ReadAndCompileShader(vertexShaderFilePath, GL_VERTEX_SHADER, definitions);
	GLuint fragmentShader = ReadAndCompileShader(fragmentShaderFilePath, GL_FRAGMENT_SHADER, definitions);
	bool compilationSuccess = vertexShader != 0 && fragmentShader != 0;

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);
	bool linkSuccess = CheckShaderProgramErrors(program, GL_LINK_STATUS);

	glDetachShader(program, vertexShader);
	glDetachShader(program, fragmentShader);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	if (compilationSuccess && linkSuccess)
	{
		if (glIsProgram(handle))
		{
			glDeleteProgram(handle);
		}
		handle = program;
		LocateAndRegisterUniforms();
	}
	else
	{
		Logger::Log("NOTE: Did not (re)load shader since there were errors!");
	}
}

/*static*/ void Shader::ReloadAll()
{
	for (Shader *shader : createdShaders)
	{
		if (shader != nullptr)
		{
			shader->Reload();
		}
	}
}

bool Shader::Validate() const
{
	glValidateProgram(handle);
	return CheckShaderProgramErrors(handle, GL_VALIDATE_STATUS);
}

void Shader::Bind() const
{
	if (handle != currentlyBoundShaderProgram)
	{
		glUseProgram(handle);
		assert(glIsProgram(handle));
		currentlyBoundShaderProgram = handle;
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

bool Shader::SetUniform(const std::string& uniformName, const glm::vec4& vector4) const
{
	if (auto uniform = GetUniformWithName(uniformName))
	{
		uniform->Set(vector4);
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
	return handle;
}

GLuint Shader::ReadAndCompileShader(const std::string& filePath, GLenum shaderType, const std::string& definitions)
{
	std::string source = ReadShaderSourceFile(filePath, definitions);
	GLuint shader = glCreateShader(shaderType);

	const GLchar *rawSource = source.c_str();
	glShaderSource(shader, 1, &rawSource, nullptr);
	glCompileShader(shader);

	GLint compilationSuccess;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compilationSuccess);
	if (compilationSuccess == GL_FALSE)
	{
		static GLchar errorMessage[2048];
		glGetShaderInfoLog(shader, sizeof(errorMessage), nullptr, errorMessage);

		Logger::Log("Error: shader file '%s' could not be compiled: %s", filePath.c_str(), errorMessage);
	}

	if (compilationSuccess)
	{
		return shader;
	}
	else
	{
		glDeleteShader(shader);
		return 0;
	}
}

std::string Shader::ReadShaderSourceFile(const std::string & filePath, const std::string& definitions)
{
	static const std::string pathPrefix = "shaders/";
	const std::string fullFilePath = pathPrefix + filePath;

	std::ifstream file{ fullFilePath };
	if (!file.is_open())
	{
		Logger::Log("Error: could not open shader source file with name '%s'", filePath.c_str());
	}

	std::stringstream result;
	std::string line;
	while (std::getline(file, line))
	{
		if (line.find(VERSION_DIRECTIVE) != std::string::npos)
		{
			result << line << std::endl;
			result << definitions << std::endl;
		}
		else if (line.find(INCLUDE_DIRECTIVE) != std::string::npos)
		{
			std::string fileName = GetFileNameFromIncludeLine(line);
			result << ReadShaderSourceFile(fileName, definitions);
		}
		else
		{
			result << line << std::endl;
		}
	}

	if (file.bad())
	{
		Logger::Log("Error: some error while reading shader source file '%s'", filePath.c_str());
	}

	return result.str();
}

std::string Shader::GetFileNameFromIncludeLine(const std::string& line)
{
	// Trim whitespace from initial string
	std::string trimmed = nonstd::trim_whitespace(line);

	// Remove include directive, leaving only the filename and decorations
	std::string decoratedFilename = trimmed.substr(strlen(INCLUDE_DIRECTIVE));

	// Replace any quotation marks, tabs, and semicolons with spaces
	std::replace(decoratedFilename.begin(), decoratedFilename.end(), ';',  ' ');
	std::replace(decoratedFilename.begin(), decoratedFilename.end(), '"',  ' ');
	std::replace(decoratedFilename.begin(), decoratedFilename.end(), '\t', ' ');

	// Trim whitespace
	return nonstd::trim_whitespace(decoratedFilename);
}

bool Shader::CheckShaderProgramErrors(GLuint shaderProgram, GLenum stage)
{
	assert(stage == GL_LINK_STATUS || stage == GL_VALIDATE_STATUS);

	GLint success;
	glGetProgramiv(shaderProgram, stage, &success);
	if (success == GL_FALSE)
	{
		static GLchar errorMessage[2048] = {0};
		glGetProgramInfoLog(shaderProgram, sizeof(errorMessage), nullptr, errorMessage);

		if (stage == GL_LINK_STATUS)
		{
			Logger::Log("Error: shader program could not be linked: %s", errorMessage);
		}
		else if (stage == GL_VALIDATE_STATUS)
		{
			Logger::Log("Error: shader program could not be validated: %s", errorMessage);
		}
	}

	return success;
}

void Shader::LocateAndRegisterUniforms()
{
	static const int NAME_BUFFER_LENGTH = 512;

	// If a reload these will be filled and the old values serve no purpose.
	uniforms.clear();
	uniformBlockIndicies.clear();

	Bind();

	int activeUniformCount = 0;
	glGetProgramiv(handle, GL_ACTIVE_UNIFORMS, &activeUniformCount);

	for (int i = 0; i < activeUniformCount; ++i)
	{
		// Get uniform name
		char uniformName[NAME_BUFFER_LENGTH];
		int uniformNameLength;
		glGetActiveUniformName(handle, GLuint(i), NAME_BUFFER_LENGTH - 1, &uniformNameLength, uniformName);
		uniformName[uniformNameLength] = '\0';
		std::string name{uniformName};

		// Get uniform location
		GLint location = glGetUniformLocation(handle, uniformName);

		// There should definitly be no uniform name duplicates
		assert(uniforms.find(name) == uniforms.end());

		if (location != -1)
		{
			Uniform uniform{*this, name, static_cast<GLuint>(location)};
			uniforms.emplace(std::make_pair(name, uniform));
		}
		else
		{
			Logger::Log("Tried to add uniform with name '%s' which isn't active / doesn't exist!", name.c_str());
		}
	}
	
	int activeUniformBlockCount = 0;
	glGetProgramiv(handle, GL_ACTIVE_UNIFORM_BLOCKS, &activeUniformBlockCount);

	for (int i = 0; i < activeUniformBlockCount; ++i)
	{
		char uniformBlockName[NAME_BUFFER_LENGTH];
		int uniformBlockNameLength;
		glGetActiveUniformBlockName(handle, GLuint(i), NAME_BUFFER_LENGTH - 1, &uniformBlockNameLength, uniformBlockName);
		uniformBlockName[uniformBlockNameLength] = '\0';

		GLuint blockIndex = glGetUniformBlockIndex(handle, uniformBlockName);
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
