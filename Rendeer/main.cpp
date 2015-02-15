
#include <string>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <SDL.h>

#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "BasicRenderer.h"
#include "DeferredRenderer.h"
#include "Entity.h"
#include "PerspectiveCamera.h"
#include "Model.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

extern "C" int main(int argc, char *argv[])
{
	// DISPLAY & RENDERER
	Display display("Rendeer", WINDOW_WIDTH, WINDOW_HEIGHT, false);
	BasicRenderer renderer(display);
	DeferredRenderer deferredRenderer(display);



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

	Model angleModel;
	angleModel.positions.push_back(*vertices[0].GetPosition());
	angleModel.positions.push_back(*vertices[1].GetPosition());
	angleModel.positions.push_back(*vertices[2].GetPosition());
	angleModel.positions.push_back(*vertices[3].GetPosition());
	angleModel.positions.push_back(*vertices[4].GetPosition());
	angleModel.positions.push_back(*vertices[5].GetPosition());

	angleModel.texCoords.push_back(*vertices[0].GetTexCoord());
	angleModel.texCoords.push_back(*vertices[1].GetTexCoord());
	angleModel.texCoords.push_back(*vertices[2].GetTexCoord());
	angleModel.texCoords.push_back(*vertices[3].GetTexCoord());
	angleModel.texCoords.push_back(*vertices[4].GetTexCoord());
	angleModel.texCoords.push_back(*vertices[5].GetTexCoord());

	angleModel.indices.push_back(0); angleModel.indices.push_back(1); angleModel.indices.push_back(2);
	angleModel.indices.push_back(1); angleModel.indices.push_back(3); angleModel.indices.push_back(2);
	angleModel.indices.push_back(2); angleModel.indices.push_back(3); angleModel.indices.push_back(5);
	angleModel.indices.push_back(2); angleModel.indices.push_back(5); angleModel.indices.push_back(4);
	Mesh angleMesh(angleModel);

	// DOG MATERIAL
	Texture dogTexture("textures/dog.png", GL_LINEAR, GL_REPEAT);
	Material dogMaterial;
	dogMaterial.diffuseTexture = &dogTexture;

	// ENTITY
	Entity angleEntity(angleMesh, dogMaterial);
	angleEntity.GetTransform()->SetPosition(glm::vec3(0, 0, 0));

	// CAMERA
	PerspectiveCamera camera(glm::vec3(0, 2, -10.0), glm::vec3(0, 0, 0),
		45.0f, 0.1f, 1000.0f, display.GetAspectRatio());


	
	Model teapotModel("models/teapot.obj", true);
	Mesh teapotMesh(teapotModel);
	Texture teapotTexture("textures/metal3.diffuse.png");
	Material teapotMaterial;
	teapotMaterial.diffuseTexture = &teapotTexture;
	Entity teapot(teapotMesh, teapotMaterial);
	

	Entity entites[2] = { angleEntity, teapot };

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
		rotation += 1.0f;

		//angleEntity.GetTransform()->SetRotation(glm::vec3(0, 0, rotation));
		//angleEntity.GetTransform()->SetPosition(glm::vec3(-3, 0, 2));

		teapot.GetTransform()->SetRotation(glm::vec3(0, rotation, 0));
		teapot.GetTransform()->SetPosition(glm::vec3(0, 0, 0));

		//camera.GetTransform()->SetRotation(glm::vec3(rotationCamX, rotationCamY, 0));
		//rotationCamY = sinf(rotation / 40.0f) * 40.0f;
		//rotationCamX = cosf(rotation / 40.0f) * 40.0f;

		//deferredRenderer.Render(camera, entites, 2);
		

		renderer.Render(camera, &teapot, 1);
		//deferredRenderer.Render(camera, &teapot, 1);
	}

	return 0;
}









/*

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

*/