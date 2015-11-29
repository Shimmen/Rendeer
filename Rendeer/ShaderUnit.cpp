#include "ShaderUnit.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <sys/stat.h>

#include "Logger.h"
#include "GeneralUtil.h"

ShaderUnit::ShaderUnit(const std::string& shaderSourcePath, ShaderUnit::Type type)
	: type{ type }
	, sourceFilePath{ shaderSourcePath }
{
	std::string source = ReadShaderSourceFile(shaderSourcePath);

	GLenum shaderType = static_cast<GLenum>(type);
	this->shaderUnitHandle = glCreateShader(shaderType);

	const GLchar *rawSource = source.c_str();
	glShaderSource(this->shaderUnitHandle, 1, &rawSource, nullptr);
	glCompileShader(this->shaderUnitHandle);
	
	GLint compilationSuccess;
	glGetShaderiv(this->shaderUnitHandle, GL_COMPILE_STATUS, &compilationSuccess);
	if (compilationSuccess == GL_FALSE)
	{
		GLchar errorMessage[2048];
		memset(errorMessage, '\0', sizeof(errorMessage));
		glGetShaderInfoLog(this->shaderUnitHandle, sizeof(errorMessage), nullptr, errorMessage);

		const Logger& logger = Logger::GetDefaultLogger();
		logger.Log("Shader error: shader loaded with file path \"" + shaderSourcePath + "\" could not be compiled.");
		logger.Log("\tcompiler error message:" + std::string(errorMessage));
	}
}

ShaderUnit::~ShaderUnit()
{
	glDeleteShader(this->shaderUnitHandle);
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

	std::ifstream inputFileStream;

	try
	{
		inputFileStream.open(fullFilePath);
		inputFileStream.exceptions(std::ifstream::failbit);
	}
	catch (std::ios_base::failure& failure)
	{
		std::stringstream description;
		description
			<< "Error: could not open shader source file with name: \""
			<< filePath << "\" (error code " << failure.code() << "). "
			<< "Reason: " << failure.what() << ".";

		Logger::GetDefaultLogger().Log(description.str());
	}

	if (inputFileStream.is_open() == false)
	{
		Logger::GetDefaultLogger().Log("Error: shader source file should be opened, but is not.");
	}

	std::string result;

	while (inputFileStream.good())
	{
		std::string line;
		
		try
		{
			std::getline(inputFileStream, line);
		}
		catch (std::ios_base::failure& _)
		{
			// Nothing more to read, leave parsing loop
			break;
		}

		// If the line is a shader include directive, include that file
		size_t foundPosition = line.find(ShaderUnit::INCLUDE_DIRECTIVE + " ");
		if (foundPosition != std::string::npos)
		{
			const char *DELIMITERS = " ";

			// Get non-const char * from string
			const size_t lineBufferLength = line.length() + 1;
			char *lineChars = new char[lineBufferLength];
			strcpy_s(lineChars, lineBufferLength, line.c_str());

			// Extract tokens into string vector
			std::vector<std::string> tokens;
			char *context = nullptr;
			char *currentToken = strtok_s(lineChars, DELIMITERS, &context);
			while (currentToken != nullptr)
			{
				tokens.push_back(std::string(currentToken));
				currentToken = strtok_s(nullptr, DELIMITERS, &context);
			}

			delete lineChars;

			// If there are two tokens, assume the second is the path.
			if (tokens.size() == 2)
			{
				// Extract the path from inside the quotation marks
				std::string includedFilePath = tokens[1];
				includedFilePath = includedFilePath.substr(1, includedFilePath.length() - 2);

				// Check if file exists (no need to open a file to just check its exisitance)
				if (nonstd::file_is_readable(pathPrefix + includedFilePath))
				{
					// Append the contents recursivly, then continue with the next line.
					result.append(ReadShaderSourceFile(includedFilePath));
					continue;
				}
				else
				{
					Logger::GetDefaultLogger().Log("Error: shader includes a non-readable/non-existent file with the path \"" + includedFilePath + "\".");
				}
			}
			else
			{
				Logger::GetDefaultLogger().Log("Error: shader include syntax is as follows: \'#include \"path/to/resource.vsh\"\'.");
			}
		}
		
		result.append(line + '\n');
	}
	
	inputFileStream.close();

	return result;
}

/* static */ const std::string ShaderUnit::INCLUDE_DIRECTIVE{ "#include" };