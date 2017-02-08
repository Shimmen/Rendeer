
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
#include "ImGuiAdapter.h"
#include "DiffuseMaterial.h"

int main(int argc, char *argv[])
{
	//
	// Setup
	//

	Window window{ 1280, 720, false, false };
	Renderer renderer{ &window };
	ImGuiAdapter::Init(&window);

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

	scene.SetSkybox(std::make_shared<TextureCube>(
		Bitmap{"textures/skybox_sunset/left.png"},
		Bitmap{"textures/skybox_sunset/right.png"},
		Bitmap{"textures/skybox_sunset/bottom.png"},
		Bitmap{"textures/skybox_sunset/top.png"},
		Bitmap{"textures/skybox_sunset/front.png"},
		Bitmap{"textures/skybox_sunset/back.png"}
	));

	scene.SetAmbientColor(glm::vec3{ 0.02f, 0.02f, 0.02f });

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

	// Set up the extra camera
	auto extraCamera = std::make_shared<CameraComponent>(16.0f / 9.0f, 0.1f, 1000.0f, glm::radians(50.0f));
	auto extraCameraTexture = std::make_shared<Texture2D>(853, 480, GL_RGBA, GL_RGBA8, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST);
	auto extraCameraTarget = std::make_shared<FrameBuffer>();
	extraCameraTarget->Attach(extraCameraTexture.get(), GL_COLOR_ATTACHMENT0);
	extraCamera->SetTarget(extraCameraTarget);
	spotLight->NewChild()->AddComponent(extraCamera);

	// Set up the extra camera target model
	auto tv = ModelLoader::Load("models/cube.obj");
	tv->GetTransform()
		.SetPosition(15.0f, 2.3f, 0)
		.SetScale(1.8f).Scale(0.05f, 16.0f / 9.0f, 1) // TODO: Fix mirroring etc.
		.Rotate(glm::vec3{1,0,0}, 3.1415f / 2.0f);
	scene.AddChild(tv);
	{
		// HACK!!! There needs to be a real nice way to search for a component in a scene graph!
		auto renderable = tv->GetDirectChildren().front()->GetComponent<Renderable>();
		auto mat = std::dynamic_pointer_cast<DiffuseMaterial>(renderable->GetMaterial());
		mat->diffuseTexture = extraCameraTexture;
		mat->specularIntensity = 0.0f;
		mat->emissive = 0.25f;
	}

	//
	// Render/game loop
	//

	logger.LogSubheading("Render loop begin");
	logger.LogTimestamp();
	logger.LogEmptyLine();

	glfwSetTime(0.0);
	double currentTime = 0.0;
	double previousTime = glfwGetTime();

	float animation = 0.0f;

	bool stickDirectionalLightToCamera = false;

	window.Focus();
	while (!window.IsCloseRequested())
	{
		currentTime = glfwGetTime();
		const double dt = currentTime - previousTime;
		const float deltaTime = static_cast<float>(dt);
		previousTime = currentTime;

		window.PollEvents();
		ImGuiAdapter::NewFrame(deltaTime);

		if (window.IsCursorHidden())
		{
			camera->Update(deltaTime, window);
		}

		if (window.WasKeyPressed(GLFW_KEY_LEFT_ALT))
		{
			window.SetCursorHidden(!window.IsCursorHidden());
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

		if (window.WasKeyPressed(GLFW_KEY_LEFT_CONTROL))
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

		ImGui::ShowTestWindow();
		ImGui::Render();

		window.SwapBuffers();
	}

	logger.LogSubheading("Render loop end");
	logger.LogTimestamp();

	ImGuiAdapter::Deinit();

	return 0;
}
