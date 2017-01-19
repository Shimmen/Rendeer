#include "ShaderUnit.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Logger.h"
#include "GeneralUtil.h"

ShaderUnit::ShaderUnit(const std::string& shaderSourcePath, ShaderUnit::Type type)
	: type{ type }
	, sourceFilePath{ shaderSourcePath }
{
	std::string source = ReadShaderSourceFile(shaderSourcePath);

	GLenum shaderType = static_cast<GLenum>(type);
	handle = glCreateShader(shaderType);

	const GLchar *rawSource = source.c_str();
	glShaderSource(handle, 1, &rawSource, nullptr);
	glCompileShader(handle);
	
	GLint compilationSuccess;
	glGetShaderiv(handle, GL_COMPILE_STATUS, &compilationSuccess);
	if (compilationSuccess == GL_FALSE)
	{
		GLchar errorMessage[2048];
		memset(errorMessage, '\0', sizeof(errorMessage));
		glGetShaderInfoLog(handle, sizeof(errorMessage), nullptr, errorMessage);

		const Logger& logger = Logger::GetDefaultLogger();
		logger.Log("Shader error: shader loaded with file path \"" + shaderSourcePath + "\" could not be compiled.");
		logger.Log("\tcompiler error message:" + std::string(errorMessage));
	}
}

ShaderUnit::~ShaderUnit()
{
	glDeleteShader(handle);
}

ShaderUnit::Type ShaderUnit::GetType() const
{
	return this->type;
}

const std::string & ShaderUnit::GetSourceFilePath() const
{
	return this->sourceFilePath;
}

/* static */ std::string ShaderUnit::ReadShaderSourceFile(const std::string & filePath)
{
	static const std::string pathPrefix = "shaders/";
	const std::string fullFilePath = pathPrefix + filePath;

	std::ifstream file{ fullFilePath };
	if (!file.is_open())
	{
		std::stringstream description;
		description << "Error: could not open shader source file with name: \"" << filePath << "\"";
		Logger::GetDefaultLogger().Log(description.str());
	}

	std::string result;
	std::string line;
	while (std::getline(file, line))
	{
		if (IsIncludeLine(line))
		{
			std::string fileName = GetFileNameFromIncludeLine(line);
			result.append(ReadShaderSourceFile(fileName));
		}
		else
		{
			result.append(line + "\n");
		}
	}
	
	if (file.bad())
	{
		Logger::GetDefaultLogger().Log("Some error while reading the file!");
	}

	return result;
}

/* static */ bool ShaderUnit::IsIncludeLine(const std::string& line)
{
	size_t foundPosition = line.find(INCLUDE_DIRECTIVE);
	return foundPosition != std::string::npos;
}

/* static */ std::string ShaderUnit::GetFileNameFromIncludeLine(const std::string& line)
{
	// Trim whitespace from initial string
	std::string trimmed = nonstd::trim_whitespace(line);

	// Remove include directive, leaving only the filename and decorations
	std::string decoratedFilename = trimmed.substr(INCLUDE_DIRECTIVE.length());
	
	// Replace any quotation marks, tabs, and semicolons with spaces
	std::replace(decoratedFilename.begin(), decoratedFilename.end(), ';',  ' ');
	std::replace(decoratedFilename.begin(), decoratedFilename.end(), '"',  ' ');
	std::replace(decoratedFilename.begin(), decoratedFilename.end(), '\t', ' ');

	// Trim whitespace
	return nonstd::trim_whitespace(decoratedFilename);
}
