
#include <string>
#include <vector>
#include <memory>

#include <glm/glm.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"
#include "Scene.h"
#include "Window.h"
#include "Renderable.h"
#include "ModelLoader.h"
#include "DiffuseMaterial.h"
#include "DeferredRenderer.h"

int main(int argc, char *argv[])
{
	// DISPLAY & RENDERER
	const int WINDOW_WIDTH = 1280;
	const int WINDOW_HEIGHT = 720;
	Window window{ WINDOW_WIDTH, WINDOW_HEIGHT, "Rendeer", true };
	DeferredRenderer deferredRenderer{ &window };
	window.BindAsDrawFramebuffer();

	// Log default startup stuff
	Logger& logger = Logger::GetDefaultLogger();
#if defined(_DEBUG)
	logger.LogHeading("Rendeer - debug build");
#else
	logger.LogHeading("Rendeer - release build");
#endif
	logger.Log("Starting session with:");
	logger.Log("\t- fullscreen " + Logger::GetStateDescription(window.IsFullscreen()));
	logger.Log("\t- vsync " + Logger::GetStateDescription(window.IsVsyncEnabled()));

	logger.LogSubheading("Scene setup begin");
	logger.LogTimestamp();
	logger.LogEmptyLine();

	//
	// Define scene
	//
	Scene scene;

	auto camera = scene.AddChild(std::make_shared<Camera>(
		glm::vec3{ 0, 1.7f, -5.0f },
		glm::angleAxis(0.15f, glm::vec3{ 1, 0, 0 })
	));

	// TODO: Make syntax better for these things.
	scene.SetMainCamera(camera->GetComponent<CameraComponent>());

	auto teapot = ModelLoader::Load("models/teapot/teapot.obj");
	scene.AddChild(teapot)->GetTransform().SetScale(0.032f);

	auto sponza = ModelLoader::Load("models/dabrovic-sponza/sponza.obj");
	scene.AddChild(sponza);

	// DIRECTIONAL LIGHT
	//auto directionalLight = scene.NewChild();
	//directionalLight->GetTransform().SetOrientation(glm::quat{ 0.00873f, 0.0f, 0.0f, 0.99996f });
	//directionalLight->AddComponent(std::make_shared<DirectionalLight>(glm::vec3{ 0.92f, 0.95f, 0.88f }, 1.5f));

	// POINT LIGHT
	auto pointLight = scene.NewChild();
	pointLight->AddComponent(std::make_shared<PointLight>(glm::vec3{ 1.0f, 0.1f, 0.15f }, 1.35f));

	// SPOT LIGHT
	auto spotLight = scene.NewChild();
	spotLight->GetTransform()
		.SetPosition(glm::vec3{ 0, 10.0f, 0 })
		.SetOrientation(glm::angleAxis(3.141592f / 2.0f, glm::vec3{1, 0, 0 }));
	spotLight->AddComponent(std::make_shared<SpotLight>(glm::vec3{ 1.0f, 0.6f, 0.6f }, 12.0f, glm::radians(40.0f), glm::radians(5.0f)));

	//////////
	// LOOP //
	//////////

	logger.LogSubheading("Render loop begin");
	logger.LogTimestamp();
	logger.LogEmptyLine();

	// Will set up the renderer for rendering
	deferredRenderer.BindForUsage();

	float timer = 0.0f;
	bool stickDirectionalLightToCamera = false;

	while (!window.IsCloseRequested())
	{
		// Start every frame by polling events
		window.PollEvents();

		// Make the escape button quit the app/close the window
		if (window.GetKeyboard().WasKeyPressed(GLFW_KEY_ESCAPE) || window.GetMouse().WasButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
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

		auto& keyboard = window.GetKeyboard();
		if (keyboard.IsKeyDown(GLFW_KEY_W) || keyboard.IsKeyDown(GLFW_KEY_UP))
		{
			translation.z += speed;
		}
		if (keyboard.IsKeyDown(GLFW_KEY_S) || keyboard.IsKeyDown(GLFW_KEY_DOWN))
		{
			translation.z -= speed;
		}
		if (keyboard.IsKeyDown(GLFW_KEY_A) || keyboard.IsKeyDown(GLFW_KEY_LEFT))
		{
			translation.x -= speed;
		}
		if (keyboard.IsKeyDown(GLFW_KEY_D) || keyboard.IsKeyDown(GLFW_KEY_RIGHT))
		{
			translation.x += speed;
		}
		if (keyboard.IsKeyDown(GLFW_KEY_SPACE) || keyboard.IsKeyDown(GLFW_KEY_RIGHT_SHIFT))
		{
			translation.y += speed;
		}
		if (keyboard.IsKeyDown(GLFW_KEY_LEFT_SHIFT) || keyboard.IsKeyDown(GLFW_KEY_RIGHT_ALT))
		{
			translation.y -= speed;
		}

		// Rotate translation to model space and translate
		translation = camera->GetTransform().RotateVector(translation);
		camera->GetTransform().Translate(translation);

		// If cursor is hidden, rotate camera
		if (window.IsCursorHidden())
		{
			float mouseSensitivity = 0.0005f;
			glm::vec2 mouseDelta = window.GetMouse().GetMouseDelta();

			camera->GetTransform().Rotate(glm::vec3(0, 1, 0), mouseDelta.x * mouseSensitivity);
			camera->GetTransform().Rotate(camera->GetTransform().GetRight(), mouseDelta.y * mouseSensitivity);
		}

		timer += 0.03f;

		teapot->GetTransform()
			.SetOrientation(glm::vec3(0, 1, 0), 0.7f * timer)
			.SetPosition(0, 0.4f + 0.2f * cosf(2.0f * timer), 0);

		pointLight->GetTransform().SetPosition(
			6.0f * cosf(1.3f * timer),
			1.4f + 0.6f * cosf(sinf(timer)),
			6.0f * sinf(1.3f * timer)
		);

		if (keyboard.WasKeyPressed(GLFW_KEY_LEFT_CONTROL))
		{
			stickDirectionalLightToCamera = !stickDirectionalLightToCamera;
		}

		if (stickDirectionalLightToCamera)
		{
			// Spot light must be attached directly to root node
			auto cameraPosition = camera->GetTransform().GetPositionInWorld();
			auto cameraOrientation = camera->GetTransform().GetOrientationInWorld();
			spotLight->GetTransform().SetPosition(cameraPosition).SetOrientation(cameraOrientation);
		}

		deferredRenderer.Render(scene);

	}

	logger.LogSubheading("Render loop end");
	logger.LogTimestamp();

	return 0;
}
