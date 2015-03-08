
#include <string>
#include <vector>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <SDL.h>

#include "Mesh.h"
#include "Model.h"
#include "Shader.h"
#include "Entity.h"
#include "Texture.h"
#include "Display.h"
#include "DiffuseMaterial.h"
#include "DirectionalLight.h"
#include "DeferredRenderer.h"
#include "PerspectiveCamera.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

extern "C" int main(int argc, char *argv[])
{
	// DISPLAY & RENDERER
	Display display("Rendeer", WINDOW_WIDTH, WINDOW_HEIGHT, false);
	DeferredRenderer deferredRenderer(display);

	// CAMERA
	PerspectiveCamera camera(glm::vec3(0, 3, -4), glm::angleAxis(0.5f, glm::vec3(1, 0, 0)),
		45.0f, 0.1f, 1000.0f, display.GetAspectRatio());

	// TEAPOT
	Model teapotModel("models/teapot/teapot.obj");
	Mesh teapotMesh(teapotModel);
	Texture teapotTexture("textures/default.png");
	DiffuseMaterial teapotMaterial;
	teapotMaterial.diffuseTexture = &teapotTexture;
	Entity teapot(teapotMesh, teapotMaterial);
	teapot.GetTransform()->SetScale(0.01f);
	teapot.GetTransform()->SetPosition(glm::vec3(0, 1.4, 0));

	// ENTITIES
	std::vector<Entity *> entities;
	entities.push_back(&teapot);

	// DIRECTIONAL LIGHT
	DirectionalLight directionalLight(glm::quat(0.655617990970857f, 0.055478958634923616f, -0.7025613967450166f, 0.08004676010739724f), // just some random stuff
		glm::vec3(1.0f, 0.95f, 0.88f), 0.5f);

	// LIGHTS
	std::vector<DirectionalLight *> lights;
	lights.push_back(&directionalLight);

	//////////
	// LOOP //
	//////////

	deferredRenderer.BindForUsage();

	float timer = 0.0f;

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

		timer += 0.3f;
		teapot.GetTransform()->SetRotation(glm::vec3(0, 1, 0), timer * 0.2f);
		teapot.GetTransform()->SetPosition(glm::vec3(sinf(timer / 10) * 2, 1.4, 0));

		// Try rotating it properly. Quaternions are complicated...
		//directionalLight.GetTransform()->Rotate ...;

		deferredRenderer.Render(entities, lights, camera);
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

#if 0
// MESH
Vertex vertices[6] = {
	Vertex(glm::vec3(-1, -1, 0), glm::vec2(0.0, 0.0)),  // bot left
	Vertex(glm::vec3(-1, +1, 0), glm::vec2(0.0, 1.0)),  // top left

	Vertex(glm::vec3(+0, -1, -1), glm::vec2(1.0, 0.0)), // bot mid
	Vertex(glm::vec3(+0, +1, -1), glm::vec2(1.0, 1.0)), // top mid

	Vertex(glm::vec3(+1, -1, 0), glm::vec2(2.0, 0.0)),  // bot right
	Vertex(glm::vec3(+1, +1, 0), glm::vec2(2.0, 1.0))   // top right
};
int indices[12] = { 0, 1, 2, 1, 3, 2, 2, 3, 5, 2, 5, 4 };

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
#endif