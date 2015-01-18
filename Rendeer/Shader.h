#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include <GL/glew.h>

class Shader
{
public:
	Shader(const std::string& vertexShaderFilePath,
		const std::string& fragmentShaderFilePath);
	~Shader();

	void Bind();

	inline GLuint GetHandle() { return shaderProgram; }

private:
	GLuint shaderProgram;


	GLuint CreateShaderComponent(const std::string& source, GLenum shaderType);

	void CheckShaderErrors(GLuint shader, int isProgram, GLuint stageFlag,
		const std::string& customMessage);

	std::string ReadFile(const std::string& filePath);
};

