
#include <string>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <SDL.h>

#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "BasicRenderer.h"
#include "Entity.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

extern "C" int main(int argc, char *argv[])
{
	// DISPLAY & RENDERER
	Display display("Rendeer", WINDOW_WIDTH, WINDOW_HEIGHT, false);
	BasicRenderer renderer(display);

	// MESH
	Vertex vertices[4] = {
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0, 0.0)), // bot left
		Vertex(glm::vec3(-0.5f, +0.5f, 0.0f), glm::vec2(0.0, 1.0)), // top left
		Vertex(glm::vec3(+0.5f, +0.5f, 0.0f), glm::vec2(1.0, 1.0)), // top right
		Vertex(glm::vec3(+0.5f, -0.5f, 0.0f), glm::vec2(1.0, 0.0)), // bot right
	};
	int indices[6] = { 0, 1, 2,  0, 2, 3 };
	Mesh triangleMesh(vertices, 4, indices, 6);

	// DOG MATERIAL
	Texture dogTexture("textures/dog.png", GL_LINEAR);
	Material dogMaterial;
	dogMaterial.diffuseTexture = &dogTexture;

	// BLUE MATERIAL
	unsigned char bluePixels[4 * 4 * 3] = {
		47, 12, 255, 0, 143, 255, 10, 20, 200, 100, 85, 240,
		0, 143, 255, 10, 20, 200, 100, 85, 240, 47, 12, 255,
		10, 20, 200, 100, 85, 240, 47, 12, 255, 0, 143, 255,
		100, 85, 240, 47, 12, 255, 0, 143, 255, 10, 20, 200
	};
	Texture blueTexture(4, 4, GL_RGB, GL_REPEAT, GL_NEAREST, bluePixels);
	Material blueMaterial;
	blueMaterial.diffuseTexture = &blueTexture;

	// ENTITY
	Entity triangleEntity(triangleMesh, dogMaterial /*blueMaterial*/);

	//////////
	// LOOP //
	//////////

	bool shouldExit = false;
	while (!shouldExit)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
			{
				shouldExit = true;
			}
		}

		renderer.Render(&triangleEntity, 1);
	}

	return 0;
}