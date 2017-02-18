#include "ShaderUnit.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Logger.h"
#include "GeneralUtil.h"

ShaderUnit::ShaderUnit(const std::string& shaderSourcePath, ShaderUnit::Type type, const std::vector<std::string>& definitions)
	: type{ type }
	, sourceFilePath{ shaderSourcePath }
{
	std::string source = ReadShaderSourceFile(shaderSourcePath, definitions);

	GLenum shaderType = static_cast<GLenum>(type);
	handle = glCreateShader(shaderType);

	const GLchar *rawSource = source.c_str();
	glShaderSource(handle, 1, &rawSource, nullptr);
	glCompileShader(handle);
	
	GLint compilationSuccess;
	glGetShaderiv(handle, GL_COMPILE_STATUS, &compilationSuccess);
	if (compilationSuccess == GL_FALSE)
	{
		static GLchar errorMessage[2048];
		glGetShaderInfoLog(handle, sizeof(errorMessage), nullptr, errorMessage);

		Logger::Log("Error: shader file '%s' could not be compiled: %s", shaderSourcePath.c_str(), errorMessage);
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

/* static */ std::string ShaderUnit::ReadShaderSourceFile(const std::string & filePath, const std::vector<std::string>& definitions)
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
			for (auto definition : definitions)
			{
				result << DEFINE_DIRECTIVE << definition << std::endl;
			}
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

/* static */ std::string ShaderUnit::GetFileNameFromIncludeLine(const std::string& line)
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
