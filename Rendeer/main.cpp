
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
#include "RenderObject.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

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
	Mesh triangleMesh(vertices, 3, indices, 3);
	RenderObject triangleObject(triangleMesh);

	Texture dogTexture("textures/dog.png");

	BasicRenderer renderer(display);

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

		// TODO: Get this working. (It requires a RenderObject with a material so that it can encapsulate its own texture etc.)
		//renderer.Render(&triangleObject, 1);
		
		dogTexture.Bind(0);
		GLuint uniformLocation = glGetUniformLocation(ambientShader.GetHandle(), "u_diffuse");
		glUniform1i(uniformLocation, 0);

		ambientShader.Bind();
		triangleObject.Render(ambientShader);

		display.SwapBuffers();
		display.Clear(0, 0, 0, 1);
	}

	return 0;
}