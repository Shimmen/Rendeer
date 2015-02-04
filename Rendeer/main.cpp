
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
#include "PerspectiveCamera.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

extern "C" int main(int argc, char *argv[])
{
	// DISPLAY & RENDERER
	Display display("Rendeer", WINDOW_WIDTH, WINDOW_HEIGHT, false);
	BasicRenderer renderer(display);

	// MESH
	Vertex vertices[6] = {
		Vertex(glm::vec3(-1, -1, 0), glm::vec2(0.0, 0.0)),  // bot left
		Vertex(glm::vec3(-1, +1, 0), glm::vec2(0.0, 1.0)),  // top left

		Vertex(glm::vec3(+0, -1, -1), glm::vec2(1.0, 0.0)), // bot mid
		Vertex(glm::vec3(+0, +1, -1), glm::vec2(1.0, 1.0)), // top mid
		
		Vertex(glm::vec3(+1, -1, 0), glm::vec2(2.0, 0.0)),  // bot right
		Vertex(glm::vec3(+1, +1, 0), glm::vec2(2.0, 1.0))   // top right
	};
	int indices[12] = { 0, 1, 2,  1, 3, 2,  2, 3, 5,  2, 5, 4 };
	Mesh triangleMesh(vertices, 6, indices, 12);

	// DOG MATERIAL
	Texture dogTexture("textures/dog.png", GL_LINEAR, GL_REPEAT);
	Material dogMaterial;
	dogMaterial.diffuseTexture = &dogTexture;

	// BLUE MATERIAL
	unsigned char bluePixels[4 * 4 * 3] = {
		47, 12, 255, 0, 143, 255, 10, 20, 200, 100, 85, 240,
		0, 143, 255, 10, 20, 200, 100, 85, 240, 47, 12, 255,
		10, 20, 200, 100, 85, 240, 47, 12, 255, 0, 143, 255,
		100, 85, 240, 47, 12, 255, 0, 143, 255, 10, 20, 200
	};
	Texture blueTexture(4, 4, GL_RGB, GL_REPEAT,
		GL_NEAREST, GL_NEAREST_MIPMAP_NEAREST, bluePixels);
	Material blueMaterial;
	blueMaterial.diffuseTexture = &blueTexture;

	// ENTITY
	Entity angleEntity(triangleMesh, dogMaterial /*blueMaterial*/);
	angleEntity.GetTransform()->SetPosition(glm::vec3(0, 0, 0));

	// CAMERA
	PerspectiveCamera camera(glm::vec3(0, 0, -3.5), glm::vec3(0, 0, 0),
		45.0f, 0.1f, 1000.0f, display.GetAspectRatio());

	//////////
	// LOOP //
	//////////

	float rotation = 0;
	float rotationCamY = 0;
	float rotationCamX = 0;

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

		//angleEntity.GetTransform()->SetRotation(glm::vec3(0, rotation * 3, 0));
		//rotation += 1.0f;

		//camera.GetTransform()->SetRotation(glm::vec3(rotationCamX, rotationCamY, 0));
		//rotationCamY = sinf(rotation / 40.0f) * 40.0f;
		//rotationCamX = cosf(rotation / 40.0f) * 40.0f;

		renderer.Render(camera, &angleEntity, 1);
	}

	return 0;
}