
#include <string>
#include <vector>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"
#include "Model.h"
#include "Shader.h"
#include "Entity.h"
#include "Window.h"
#include "Texture.h"
#include "Lighting.h"
#include "DiffuseMaterial.h"
#include "DeferredRenderer.h"
#include "PerspectiveCamera.h"

#define WINDOW_WIDTH 950
#define WINDOW_HEIGHT 600

int main(int argc, char *argv[])
{
	// DISPLAY & RENDERER
	Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "Rendeer", false, true);
	DeferredRenderer deferredRenderer(window);

	// CAMERA
	PerspectiveCamera camera(glm::vec3(0, 1.5f, -2.8f), glm::angleAxis(0.5f, glm::vec3(1, 0, 0)),
		glm::radians(70.0f), 1.0f, 1000.0f, window.GetAspectRatio());

	// TEAPOT
	Model teapotModel("models/teapot/teapot.obj");
	Mesh teapotMesh(teapotModel);
	Texture teapotTexture("textures/default.png");
	DiffuseMaterial teapotMaterial;
	teapotMaterial.diffuseTexture = &teapotTexture;
	Entity teapot(teapotMesh, teapotMaterial);
	teapot.GetTransform().SetScale(0.01f);
	teapot.GetTransform().SetPosition(glm::vec3(0, 0, 0));

	// TABLE
	Model tableModel("models/table/table.3ds");
	Mesh tableMesh(tableModel);
	//Texture tableTexture("models/table/wood.jpg");
	Texture tableTexture("textures/default.png");
	DiffuseMaterial tableMaterial;
	tableMaterial.diffuseTexture = &tableTexture;
	Entity table(tableMesh, tableMaterial);
	table.GetTransform().SetScale(60.0f);
	table.GetTransform().SetRotation(glm::angleAxis(1.57f /* PI/2.0 == 90 deg */, glm::vec3(1, 0, 0)));
	
	// PANEL
	Model floorModel("models/floor.obj");
	Mesh floorMesh(floorModel);
	Texture floorTexture("textures/wood1.diffuse.png");
	DiffuseMaterial floorMaterial;
	floorMaterial.diffuseTexture = &floorTexture;
	Entity floor(floorMesh, floorMaterial);
	floor.GetTransform().SetScale(1.0f);
	floor.GetTransform().SetPosition(glm::vec3(0, -1, 10.0f));

	// ENTITIES
	std::vector<Entity *> entities;
	entities.push_back(&teapot);
	entities.push_back(&table);
	entities.push_back(&floor);

	// DIRECTIONAL LIGHT
	DirectionalLight directionalLight(glm::quat(1, 1, 0, 1), glm::vec3(1.0f, 0.95f, 0.88f), 0.5f);

	// POINT LIGHT
	PointLight pointLight(glm::vec3(0, 0.1f, 0), glm::vec3(1.0f, 0.1f, 0.15f), 1.0f);

	// LIGHTS
	std::vector<ILight *> lights;
	lights.push_back(&directionalLight);
	//lights.push_back(&pointLight);

	//////////
	// LOOP //
	//////////

	deferredRenderer.BindForUsage();

	float timer = 0.0f;

	while (!window.IsCloseRequested())
	{
		// Start every frame by polling events
		window.PollEvents();

		// Make the escape button quit the app/close the window
		if (window.GetKeyboard().WasKeyPressed(GLFW_KEY_ESCAPE))
		{
			break;
		}



		
		// Move the camera (for now in this very temporary solution)
		glm::vec3 translation = glm::vec3();
		float yRotation = 0;
		float speed = 0.08f;

		const Keyboard keyboard = window.GetKeyboard();
		if (keyboard.IsKeyDown(GLFW_KEY_W))
		{
			translation.z += speed;
		}
		if (keyboard.IsKeyDown(GLFW_KEY_S))
		{
			translation.z -= speed;
		}
		if (keyboard.IsKeyDown(GLFW_KEY_A))
		{
			translation.x -= speed;
		}
		if (keyboard.IsKeyDown(GLFW_KEY_D))
		{
			translation.x += speed;
		}
		if (keyboard.IsKeyDown(GLFW_KEY_SPACE))
		{
			translation.y += speed;
		}
		if (keyboard.IsKeyDown(GLFW_KEY_LEFT_SHIFT))
		{
			translation.y -= speed;
		}
		if (keyboard.IsKeyDown(GLFW_KEY_Q))
		{
			yRotation -= speed * 0.14f;
		}
		if (keyboard.IsKeyDown(GLFW_KEY_E))
		{
			yRotation += speed * 0.14f;
		}

		camera.GetTransform().
			Translate(translation)->
			Rotate(glm::vec3(0, 1, 0), yRotation);


		timer += 0.3f;
		teapot.GetTransform().SetRotation(glm::vec3(0, 1, 0), timer * 0.1f);
		teapot.GetTransform().SetPosition(glm::vec3(sinf(timer / 10), 0, 0));

		//pointLight.GetTransform()->SetPosition(glm::vec3(0, 2, 0));

		//table.GetTransform()->SetScale(timer * 0.3f);
		//printf("%f\n", timer * 0.3f);

		table.GetTransform().SetPosition(glm::vec3(0, 0, sinf(timer / 15) * 4 + 2.5));

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