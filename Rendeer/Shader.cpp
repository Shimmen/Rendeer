#include "Shader.h"

#include <vector>

#include <glm/gtc/type_ptr.hpp>

#include "Texture2D.h"
#include "Buffer.h"

Shader::Shader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath)
{
	// Create shader components
	GLuint vertexShader = CreateShaderComponent(ReadFile(vertexShaderFilePath), GL_VERTEX_SHADER);
	GLuint fragmentShader = CreateShaderComponent(ReadFile(fragmentShaderFilePath), GL_FRAGMENT_SHADER);

	// Create program and attach components
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	// Link program
	glLinkProgram(shaderProgram);
	CheckShaderErrors(shaderProgram, true, GL_LINK_STATUS, "Error linking program: ");

	// Validate program
	glValidateProgram(shaderProgram);
	CheckShaderErrors(shaderProgram, true, GL_VALIDATE_STATUS, "Could not validate program!");

	// Release shader components
	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	
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
	// but it's unlikely, since GL_MAX_UNIFORM_BUFFER_BINDINGS is very large.
	GLuint binding = nextUniformBlockBinding;
	glBindBufferBase(GL_UNIFORM_BUFFER, binding, buffer.GetBufferHandle());

	// Connect the shader's uniform block index to the binding
	glUniformBlockBinding(shaderProgram, uniformBlockIndicies.at(uniformBlockName), binding);

	// Calculate next uniform binding
	nextUniformBlockBinding = (nextUniformBlockBinding + 1) % GL_MAX_UNIFORM_BUFFER_BINDINGS;
}

void Shader::LocateAndRegisterUniforms()
{
	static const int NAME_BUFFER_LENGTH = 200;

	this->Bind();

	int activeUniformCount = 0;
	glGetProgramiv(shaderProgram, GL_ACTIVE_UNIFORMS, &activeUniformCount);

	for (int i = 0; i < activeUniformCount; ++i)
	{
		char uniformName[NAME_BUFFER_LENGTH];
		int uniformNameLength = 0;
		glGetActiveUniformName(shaderProgram, GLuint(i), NAME_BUFFER_LENGTH - 1, &uniformNameLength, uniformName);
		uniformName[uniformNameLength] = 0;

		GLuint location = glGetUniformLocation(shaderProgram, uniformName);
		uniformLocations[uniformName] = location;
		uniformExists[uniformName] = true;
	}
	
	int activeUniformBlockCount = 0;
	glGetProgramiv(shaderProgram, GL_ACTIVE_UNIFORM_BLOCKS, &activeUniformBlockCount);

	for (int i = 0; i < activeUniformBlockCount; ++i)
	{
		char uniformBlockName[NAME_BUFFER_LENGTH];
		int uniformBlockNameLength = 0;
		glGetActiveUniformBlockName(shaderProgram, GLuint(i), NAME_BUFFER_LENGTH - 1, &uniformBlockNameLength, uniformBlockName);
		uniformBlockName[uniformBlockNameLength] = 0;

		GLuint blockIndex = glGetUniformBlockIndex(shaderProgram, uniformBlockName);
		uniformBlockIndicies[uniformBlockName] = blockIndex;
		uniformExists[uniformBlockName] = true;
	}
	
}

std::string Shader::ReadFile(const std::string& filePath)
{
	const std::string fullFilePath = "shaders/" + filePath;

	std::ifstream fileStream;
	fileStream.open(fullFilePath);

	std::string result;
	std::string line;

	if (fileStream.is_open())
	{
		while (fileStream.good())
		{
			getline(fileStream, line);

			//if (line begins with SHADER_INCLUDE_DIRECTIVE, find the second blank space-separated thing in the line and call this function recursively.
			// Append the result to this current string. Also, if it was an include directive, don't include the actual line.

			// If the line begins with the include directive plus one (or more blankspaces)
			if (line.find(std::string(SHADER_INCLUDE_DIRECTIVE) + " ") == 0)
			{
				const char * const DELIMITERS = " ";

				// get non-const char * from string
				const size_t lineBufferLength = line.length() + 1;
				char * lineChars = new char[lineBufferLength];
				strcpy_s(lineChars, lineBufferLength, line.c_str());

				char *context = NULL;
				std::vector<std::string> tokens;
				char *currentToken = strtok_s(lineChars, DELIMITERS, &context);

				while (currentToken != NULL)
				{
					tokens.push_back(std::string(currentToken));
					currentToken = strtok_s(NULL, DELIMITERS, &context);
				}

				delete lineChars;

				// Iff there are two tokens, assume the second is the path.
				if (tokens.size() == 2)
				{
					// Extract the path from inside the quotation marks
					// TODO: Handle relative paths (from the current file's context)
					std::string path = tokens[1].substr(1, tokens[1].length() - 2);

					// Append the contents, then continue on the next line.
					result.append(ReadFile(path));
					continue;
				}
				else
				{
					// Yep, I'm using goto.
					goto appendCurrentLine;
				}
			}
			else
			{
				goto appendCurrentLine;
			}

			appendCurrentLine:
			result.append(line + "\n");
		}
		fileStream.close();
	}
	else
	{
		std::cerr << "Error, could not load shader file with file path: "
			<< filePath << std::endl;
	}

	return result;
}

GLuint Shader::CreateShaderComponent(const std::string& source, GLenum shaderType)
{
	GLuint shaderObject = glCreateShader(shaderType);

	const GLchar *strings[1];
	strings[0] = (GLchar *)source.c_str();
	GLint lengths[1];
	lengths[0] = (GLint)source.length();

	glShaderSource(shaderObject, 1, strings, lengths);

	glCompileShader(shaderObject);
	CheckShaderErrors(shaderObject, false, GL_COMPILE_STATUS, "Error, could not compile shader: ");

	return shaderObject;
}

void Shader::CheckShaderErrors(GLuint shader, int isProgram, GLuint stageFlag, const std::string& customMessage)
{
	GLint success;

	if (isProgram)
	{
		glGetProgramiv(shader, stageFlag, &success);
	}
	else
	{
		glGetShaderiv(shader, stageFlag, &success);
	}

	if (success == GL_FALSE)
	{
		GLchar errorMessage[1024] = {0};

		if (isProgram)
		{
			glGetProgramInfoLog(shader, sizeof(errorMessage), NULL, errorMessage);
		}
		else
		{
			glGetShaderInfoLog(shader, sizeof(errorMessage), NULL, errorMessage);
		}

		std::cerr << customMessage << errorMessage << std::endl;
	}
}
