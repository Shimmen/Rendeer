
#include <string>
#include <vector>
#include <memory>

#include <glm/glm.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"
#include "Scene.h"
#include "Window.h"
#include "Renderer.h"
#include "Renderable.h"
#include "ModelLoader.h"
#include "DiffuseMaterial.h"

int main(int argc, char *argv[])
{
	//
	// Setup
	//
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

	auto camera = std::make_shared<Camera>(
		glm::vec3{ 0, 1.7f, -5.0f },
		glm::angleAxis(0.15f, glm::vec3{ 1, 0, 0 })
	);
	scene.AddChild(camera);
	// TODO: Make it so that the main camera is automatically set if a new entity with a camera component is added to the scene(-graph)!
	scene.SetMainCamera(camera->GetComponent<CameraComponent>());

	auto teapot = ModelLoader::Load("models/teapot/teapot.obj");
	scene.AddChild(teapot)->GetTransform().SetScale(0.032f);

	auto sponza = ModelLoader::Load("models/dabrovic-sponza/sponza.obj");
	scene.AddChild(sponza);

	//auto directionalLight = scene.NewChild();
	//directionalLight->GetTransform().SetOrientation(glm::quat{ 0.00873f, 0.0f, 0.0f, 0.99996f });
	//directionalLight->AddComponent(std::make_shared<DirectionalLight>(glm::vec3{ 0.92f, 0.95f, 0.88f }, 1.5f));

	auto pointLight = scene.NewChild();
	pointLight->AddComponent(std::make_shared<PointLight>(glm::vec3{ 1.0f, 0.1f, 0.15f }, 1.35f));

	auto spotLight = scene.NewChild();
	spotLight->GetTransform()
		.SetPosition(glm::vec3{ 0, 10.0f, 0 })
		.SetOrientation(glm::angleAxis(3.141592f / 2.0f, glm::vec3{1, 0, 0 }));
	spotLight->AddComponent(std::make_shared<SpotLight>(glm::vec3{ 1.0f, 0.6f, 0.6f }, 12.0f, glm::radians(40.0f), glm::radians(5.0f)));

	//
	// Render/game loop
	//

	logger.LogSubheading("Render loop begin");
	logger.LogTimestamp();
	logger.LogEmptyLine();

	// Will set up the renderer for rendering
	deferredRenderer.BindForUsage();

	float timer = 0.0f;
	bool stickDirectionalLightToCamera = false;

	while (!window.IsCloseRequested())
	{
		// TODO: Calculate
		const float deltaTime = 1.0f / 60.0f;

		// Start every frame by polling events
		window.PollEvents();

		camera->Update(deltaTime, window);

		if (window.GetKeyboard().WasKeyPressed(GLFW_KEY_ESCAPE) || window.GetMouse().WasButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
		{
			window.SetCursorHidden(false);
		}
		if (window.GetMouse().WasButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			window.SetCursorHidden(true);
		}

		// Just for keeping track of animations
		timer += deltaTime;

		teapot->GetTransform()
			.SetOrientation(glm::vec3(0, 1, 0), 0.7f * timer)
			.SetPosition(0, 0.4f + 0.2f * cosf(2.0f * timer), 0);

		pointLight->GetTransform().SetPosition(
			6.0f * cosf(1.3f * timer),
			1.4f + 0.6f * cosf(sinf(timer)),
			6.0f * sinf(1.3f * timer)
		);

		if (window.GetKeyboard().WasKeyPressed(GLFW_KEY_LEFT_CONTROL))
		{
			stickDirectionalLightToCamera = !stickDirectionalLightToCamera;
		}

		if (stickDirectionalLightToCamera)
		{
			// (Spot light must be attached directly to root node / scene for this to work properly)
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
