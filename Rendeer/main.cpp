
#include <iostream>

#include <SDL.h>
#include <GL/glew.h>

#include "Display.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

extern "C" int main(int argc, char *argv[])
{
	Display display("Rendeer", WINDOW_WIDTH, WINDOW_HEIGHT);

	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	/////////////
	// SHADERS //
	/////////////

	// Vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	char *vertexSource = "TODO: Get from file";
	GLchar *vStrings[1];
	vStrings[0] = vertexSource;
	GLint vLengths[1];
	vLengths[0] = 1;
	glShaderSource(vertexShader, 1, vStrings, vLengths);

	glCompileShader(vertexShader);
	GLint vSuccess;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vSuccess);
	if (!vSuccess)
	{
		GLchar errorMessage[1024] = {};
		glGetShaderInfoLog(vertexShader, sizeof(errorMessage), NULL, errorMessage);
		std::cout << "Error compiling vertex shader: " << errorMessage << std::endl;
	}

	// Fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	char *fragmentSource = "TODO: Get from file";
	GLchar *fStrings[1];
	fStrings[0] = fragmentSource;
	GLint fLengths[1];
	fLengths[0] = 1;
	glShaderSource(fragmentShader, 1, fStrings, fLengths);

	glCompileShader(fragmentShader);
	GLint fSuccess;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fSuccess);
	if (!fSuccess)
	{
		GLchar errorMessage[1024] = {};
		glGetShaderInfoLog(fragmentShader, sizeof(errorMessage), NULL, errorMessage);
		std::cout << "Error compiling fragment shader: " << errorMessage << std::endl;
	}


	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glBindAttribLocation(shaderProgram, 0, "a_position");

	glLinkProgram(shaderProgram);
	// TODO: Error handling
	glValidateProgram(shaderProgram);
	GLint pSuccess;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &pSuccess);
	if (!pSuccess)
	{
		GLchar errorMessage[1024] = {};
		glGetProgramInfoLog(shaderProgram, sizeof(errorMessage), NULL, errorMessage);
		std::cout << "Error linking shader program: " << errorMessage << std::endl;
	}

	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	///////////////
	// RENDERING //
	///////////////

	float vertices[3][2] = { { -1.0f, -1.0f }, { 0.0f, 1.0f }, { 1.0f, -1.0f } };
	float indices[3] = { 0, 1, 2 };

	GLuint vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), (void *)vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	GLuint indexBuffer;
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), (void *)indices, GL_STATIC_DRAW);

	glBindVertexArray(0);

	//////////
	// LOOP //
	//////////

	bool shouldExit = false;
	while (!shouldExit)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				shouldExit = true;
			}
		}

		glUseProgram(shaderProgram);
		glBindVertexArray(vertexArray);
		// 3 -> number of indices, 0 -> ?
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		display.SwapBuffers();
	}

	// Shader cleanup
	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);
	glDeleteProgram(shaderProgram);

	return 0;
}