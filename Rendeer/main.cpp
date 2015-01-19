
#include <iostream>
#include <fstream>
#include <string>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <SDL.h>
#include <GL/glew.h>

#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "BasicRenderer.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

extern "C" int main(int argc, char *argv[])
{
	Display display("Rendeer", WINDOW_WIDTH, WINDOW_HEIGHT);
	Shader ambientShader("shaders/ambient.vsh", "shaders/ambient.fsh");

	Vertex vertices[3] = {
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f),   glm::vec2(0.5, 1.0)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f),  glm::vec2(1.0, 0.0))
	};
	int indices[3] = { 0, 1, 2 };

	Mesh triangle(vertices, 3, indices, 3);
	Texture dogTexture("textures/dog.png");

	//BasicRenderer renderer(&display);

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

		// TODO: Get this working.
		//renderer.Render(&triangle, 1);
		
		dogTexture.Bind(0);
		GLuint uniformLocation = glGetUniformLocation(ambientShader.GetHandle(), "u_diffuse");
		glUniform1i(uniformLocation, 0);

		ambientShader.Bind();
		triangle.Render();

		display.SwapBuffers();
		display.Clear(0, 0, 0, 1);
	}

	return 0;
}