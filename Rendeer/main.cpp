
#include <iostream>
#include <fstream>
#include <string>

#include <SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Display.h"
#include "Shader.h"
#include "Mesh.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

extern "C" int main(int argc, char *argv[])
{
	Display display("Rendeer", WINDOW_WIDTH, WINDOW_HEIGHT);
	Shader ambientShader("ambient.vsh", "ambient.fsh");

	Vertex vertices[3] = { Vertex(glm::vec3(-0.5f, -0.5f, 0.0f)),
							  Vertex(glm::vec3(0.0f, 0.5f, 0.0f)),
							  Vertex(glm::vec3(0.5f, -0.5f, 0.0f)) };
	int indices[3] = { 0, 1, 2 };

	Mesh triangle(vertices, indices, 3);

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

		ambientShader.Bind();
		triangle.Render();

		display.SwapBuffers();
		display.Clear(0, 0, 0, 1);
	}

	return 0;
}