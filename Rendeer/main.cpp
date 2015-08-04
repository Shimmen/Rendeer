
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
#include "Camera.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

int main(int argc, char *argv[])
{
	// DISPLAY & RENDERER
	Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "Rendeer", false, true);
	DeferredRenderer deferredRenderer(window);

	// CAMERA
	Camera camera(glm::vec3(0, 1.5f, -2.8f), glm::angleAxis(0.5f, glm::vec3(1, 0, 0)),
		glm::radians(75.0f), 1.0f, 1000.0f, window.GetAspectRatio());

	// TEAPOT
	Mesh teapotMesh("models/teapot.obj");
	Texture teapotTexture("textures/default.png", true);
	DiffuseMaterial teapotMaterial;
	teapotMaterial.diffuseTexture = &teapotTexture;
	teapotMaterial.specularIntensity = 1.0f;
	teapotMaterial.shininess = 100.0f;
	Entity teapot(teapotMesh, teapotMaterial);
	teapot.GetTransform().SetScale(0.01f);
	teapot.GetTransform().SetPosition(glm::vec3(0, 0, 1));

	// PANEL
	Mesh panelMesh("models/plane.obj", false);
	Texture panelTexture("textures/bricks.jpg", true);
	Texture panelNormalMap("textures/bricks_normal.jpg", false);
	DiffuseMaterial panelMaterial;
	panelMaterial.diffuseTexture = &panelTexture;
	panelMaterial.normalMap = &panelNormalMap;
	panelMaterial.specularIntensity = 0.05f;
	panelMaterial.shininess = 20.0f;
	Entity panel(panelMesh, panelMaterial);
	panel.GetTransform().SetScale(1.5f);
	
	// FLOOR
	Mesh floorMesh("models/curved_plane.obj");
	Texture floorTexture("textures/default.png", true);
	DiffuseMaterial floorMaterial;
	floorMaterial.diffuseTexture = &floorTexture;
	floorMaterial.specularIntensity = 0.05f;
	floorMaterial.shininess = 10.0f;
	Entity floor(floorMesh, floorMaterial);
	floor.GetTransform().SetPosition(glm::vec3(0, -0.5f, 4));

	// ENTITIES
	std::vector<Entity *> entities;
	entities.push_back(&teapot);
	entities.push_back(&panel);
	entities.push_back(&floor);

	// DIRECTIONAL LIGHT
	DirectionalLight directionalLight(glm::quat(1, 1, 0, 1), glm::vec3(0.92f, 0.95f, 0.88f), 0.05f);

	// POINT LIGHT
	PointLight pointLight(glm::vec3(0, 0.25f, 0), glm::vec3(1.0f, 0.1f, 0.15f), 0.35f);

	// SPOT LIGHT
	SpotLight spotLight(glm::vec3(0, -0.65f, 4), glm::quat(glm::normalize(glm::vec3(1, -3, 0))), glm::vec3(0, 0, 1), 2.0f, glm::radians(40.0f), glm::radians(30.0f));

	// LIGHTS
	std::vector<ILight *> lights;
	lights.push_back(&directionalLight);
	lights.push_back(&pointLight);
	lights.push_back(&spotLight);

	//////////
	// LOOP //
	//////////

	// Will set up the renderer for rendering
	deferredRenderer.BindForUsage();

	float timer = 0.0f;
	bool stickDirectionalLightToCamera = true;

	while (!window.IsCloseRequested())
	{
		// Start every frame by polling events
		window.PollEvents();

		// Make the escape button quit the app/close the window
		if (window.GetKeyboard().WasKeyPressed(GLFW_KEY_ESCAPE))
		{
			window.SetCursorHidden(false);
		}
		if (window.GetMouse().WasButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			window.SetCursorHidden(true);
		}

		// Move the camera (for now in this very temporary solution)
		glm::vec3 translation = glm::vec3();
		const float speed = 0.08f;

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

		// Rotate translation to model space and translate
		translation = camera.GetTransform().RotateVector(translation);
		camera.GetTransform().Translate(translation);

		// If cursor is hidden, rotate camera
		if (window.IsCursorHidden())
		{
			float mouseSensitivity = 0.0005f;
			glm::vec2 mouseDelta = window.GetMouse().GetMouseDelta();

			camera.GetTransform().Rotate(glm::vec3(0, 1, 0), mouseDelta.x * mouseSensitivity);
			camera.GetTransform().Rotate(camera.GetTransform().GetRight(), mouseDelta.y * mouseSensitivity);
		}

		timer += 0.03f;

		teapot.GetTransform().SetOrientation(glm::vec3(0, 1, 0), timer);
		panel.GetTransform().SetPosition(glm::vec3(0, 0, sinf(timer) * 0.9f + 0.9f));
		
		if (keyboard.WasKeyPressed(GLFW_KEY_LEFT_CONTROL))
		{
			stickDirectionalLightToCamera = !stickDirectionalLightToCamera;
		}

		if (stickDirectionalLightToCamera)
		{
			auto cameraPosition = camera.GetTransform().GetPosition();
			auto cameraOrientation = camera.GetTransform().GetOrientation();
			spotLight.GetTransform().SetPosition(cameraPosition).SetOrientation(cameraOrientation);
		}

		deferredRenderer.Render(entities, lights, camera);

	}

	return 0;
}
