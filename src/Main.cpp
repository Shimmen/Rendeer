
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

	Window window{ 1280, 720, false, false };
	Renderer renderer{ &window };

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

	glfwSetTime(0.0);
	double currentTime = 0.0;
	double previousTime = glfwGetTime();

	double fpsTimer = 0.0;
	int fpsTimerCount = 0;

	float animation = 0.0f;

	bool stickDirectionalLightToCamera = false;

	while (!window.IsCloseRequested())
	{
		currentTime = glfwGetTime();
		const double dt = currentTime - previousTime;
		const float deltaTime = static_cast<float>(dt);
		previousTime = currentTime;

		fpsTimer += dt;
		fpsTimerCount += 1;
		if (fpsTimer > 1.0 /* every ~1 second */)
		{
			// If time granularity is low (frame time is long), count is not enough for precision
			int fps = static_cast<int>((fpsTimerCount / fpsTimer) + 0.5);
			double averageMs = (fpsTimer / fpsTimerCount) * 1000.0;
			printf("Avg frame time: %.2f ms, %d fps\n", averageMs, fps);
			fpsTimer = 0.0;
			fpsTimerCount = 0;
		}

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

		animation += deltaTime;

		teapot->GetTransform()
			.SetOrientation(glm::vec3(0, 1, 0), 0.7f * animation)
			.SetPosition(0, 0.4f + 0.2f * cosf(2.0f * animation), 0);

		pointLight->GetTransform().SetPosition(
			6.0f * cosf(1.3f * animation),
			1.4f + 0.6f * cosf(sinf(animation)),
			6.0f * sinf(1.3f * animation)
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

		renderer.Render(scene);
	}

	logger.LogSubheading("Render loop end");
	logger.LogTimestamp();

	return 0;
}
