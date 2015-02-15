#include "Shader.h"

#include <glm/gtc/type_ptr.hpp>

#include "Uniform.h"
#include "Texture.h"

Shader::Shader(const std::string& vertexShaderFilePath,
	const std::string& fragmentShaderFilePath)
{
	// Create shader components
	GLuint vertexShader =
		CreateShaderComponent(ReadFile(vertexShaderFilePath), GL_VERTEX_SHADER);
	GLuint fragmentShader =
		CreateShaderComponent(ReadFile(fragmentShaderFilePath), GL_FRAGMENT_SHADER);

	// Create program and attach components
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	// Link program
	glLinkProgram(shaderProgram);
	CheckShaderErrors(shaderProgram, true, GL_LINK_STATUS, "Error linking program: ");
	
	// Validate program
	glValidateProgram(shaderProgram);
	CheckShaderErrors(shaderProgram, true, GL_VALIDATE_STATUS, "Could not validate program: ");
	
	// Release shader components
	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// Populate the uniformLocations map
	LocateAndRegisterUniforms();
}

Shader::~Shader()
{
	glDeleteProgram(shaderProgram);
}

/* TODO: Remove!
void Shader::UpdateUniforms(const Transform& transform, const Material& material) const
{
	Update transform based uniforms (modelMatrix)
	

	// If the shader has a diffuse texture
	// we will need to bind SOMETHING to it
	if (shader.HasDiffuseTexture())
	{
		// Tell the shader that the diffuse texture
		// will be bound at texture unit 0
		glUniform1i(shader.GetDiffuseTexture().GetHandle(), 0);

		// If this material has a diffuse texture,
		// bind it at the apropriate texture unit,
		// which is 0 for diffuse textures.
		if (diffuseTexture != NULL)
		{
			diffuseTexture->Bind(0);
		}
		// If this material doesn't specify a diffuse
		// texture, bind the default diffuse texture
		else
		{
			// Get default diffuse texture.
			// Should probably be defined as globals
			// or more safe alternative in Texture.h
			Texture *defaultDiffuse = 0;
			defaultDiffuse->Bind(0);
		}
	}

	// Repeat the above method for all members
	// that should be set to uniforms in the shader.
	// Things like other textures (normalMap etc.),
	// and other uniform stuff
}
*/


bool Shader::HasUniformWithName(const std::string& uniformName)
{
	return (uniformLocations[uniformName] != NULL);
}

// It is your own responsibility to keep track of the types of the uniforms
void Shader::SetUniform(const std::string& uniformName, int intValue)
{
#ifdef SHADER_ALWAYS_BIND_WHEN_NEEDED
	Bind();
#endif

	glUniform1i(uniformLocations[uniformName], intValue);
}

void Shader::SetUniform(const std::string& uniformName, float floatValue)
{
#ifdef SHADER_ALWAYS_BIND_WHEN_NEEDED
	Bind();
#endif

	glUniform1f(uniformLocations[uniformName], floatValue);
}

void Shader::SetUniform(const std::string& uniformName, const glm::vec2& vector2)
{
#ifdef SHADER_ALWAYS_BIND_WHEN_NEEDED
	Bind();
#endif

	glUniform2fv(uniformLocations[uniformName], 1, glm::value_ptr(vector2));
}

void Shader::SetUniform(const std::string& uniformName, const glm::vec3& vector3)
{
#ifdef SHADER_ALWAYS_BIND_WHEN_NEEDED
	Bind();
#endif

	glUniform3fv(uniformLocations[uniformName], 1, glm::value_ptr(vector3));
}

void Shader::SetUniform(const std::string& uniformName, const glm::mat3& matrix3)
{
#ifdef SHADER_ALWAYS_BIND_WHEN_NEEDED
	Bind();
#endif

	glUniformMatrix3fv(uniformLocations[uniformName], 1, GL_FALSE, glm::value_ptr(matrix3));
}

void Shader::SetUniform(const std::string& uniformName, const glm::mat4& matrix4)
{
#ifdef SHADER_ALWAYS_BIND_WHEN_NEEDED
	Bind();
#endif

	glUniformMatrix4fv(uniformLocations[uniformName], 1, GL_FALSE, glm::value_ptr(matrix4));
}


void Shader::LocateAndRegisterUniforms()
{
	static const int NAME_BUFFER_LENGTH = 70;

	this->Bind();

	int activeUniformCount = 0;
	glGetProgramiv(shaderProgram, GL_ACTIVE_UNIFORMS, &activeUniformCount);

	for (int i = 0; i < activeUniformCount; ++i)
	{
		// unused but needed so the driver doesn't write to NULL
		GLint elementCount;
		GLenum type;

		char uniformName[NAME_BUFFER_LENGTH];
		int uniformNameLength = 0;

		glGetActiveUniform(shaderProgram, GLuint(i), NAME_BUFFER_LENGTH - 1, &uniformNameLength, &elementCount, &type, uniformName);
		
		// End the string with a null-terminator.
		uniformName[uniformNameLength] = 0;

		GLuint location = glGetUniformLocation(shaderProgram, uniformName);

		// Add uniform to the map
		uniformLocations[uniformName] = location;
	}
}

// Shader creation

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

GLuint Shader::CreateShaderComponent(const std::string& source, GLenum shaderType)
{
	GLuint shaderObject = glCreateShader(shaderType);

	GLchar *strings[1];
	strings[0] = (GLchar *)source.c_str();
	GLint lengths[1];
	lengths[0] = (GLint)source.length();

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
