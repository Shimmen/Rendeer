#include "Shader.h"

Shader::Shader(const std::string& vertexShaderFilePath,
	const std::string& fragmentShaderFilePath)
{
	GLuint vertexShader =
		CreateShaderComponent(ReadFile(vertexShaderFilePath), GL_VERTEX_SHADER);
	GLuint fragmentShader =
		CreateShaderComponent(ReadFile(fragmentShaderFilePath), GL_FRAGMENT_SHADER);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);
	CheckShaderErrors(shaderProgram, true, GL_LINK_STATUS, "Error linking program: ");
	
	glValidateProgram(shaderProgram);
	CheckShaderErrors(shaderProgram, true, GL_VALIDATE_STATUS, "Could not validate program: ");

	
	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
	glDeleteProgram(shaderProgram);
}

void Shader::Bind()
{
	glUseProgram(shaderProgram);
}

GLuint Shader::CreateShaderComponent(const std::string& source, GLenum shaderType)
{
	GLuint shaderObject = glCreateShader(shaderType);

	GLchar *strings[1];
	strings[0] = (GLchar *)source.c_str();
	GLint lengths[1];
	lengths[0] = source.length();

	glShaderSource(shaderObject, 1, strings, lengths);

	glCompileShader(shaderObject);
	CheckShaderErrors(shaderObject, false, GL_COMPILE_STATUS,
		"Error, could not compile shader: ");

	return shaderObject;
}

void Shader::CheckShaderErrors(GLuint shader, int isProgram, GLuint stageFlag,
	const std::string& customMessage)
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
		GLchar errorMessage[1024] = {};
		
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

std::string Shader::ReadFile(const std::string& filePath)
{
	std::ifstream fileStream;
	fileStream.open(filePath);

	std::string result;
	std::string line;

	if (fileStream.is_open())
	{
		while (fileStream.good())
		{
			getline(fileStream, line);
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