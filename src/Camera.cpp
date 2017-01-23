#include "Camera.h"

#include "Window.h"

CameraComponent::CameraComponent(float aspectRatio, float nearPlane, float farPlane, float fovOrSize, CameraComponent::CameraType type)
	: Component{}
	, aspectRatio{ aspectRatio }
	, nearClippingPlane{ nearPlane }
	, farClippingPlane{ farPlane }
	, fovOrSize{ fovOrSize }
	, type{ type }
{
	assert(farClippingPlane > nearClippingPlane);
	assert(fovOrSize > 0.0f);
}

glm::mat4 CameraComponent::GetViewMatrix() const
{
	const Transform& transform = GetOwnerEntity().GetTransform();
	glm::mat4 negativePosition = glm::translate(glm::mat4(1.0), -transform.GetPositionInWorld());
	glm::mat4 negativeRotation = glm::toMat4(glm::conjugate(transform.GetOrientationInWorld()));

	return negativeRotation * negativePosition;
}

glm::mat4 CameraComponent::GetProjectionMatrix() const
{
	glm::mat4 projection = glm::mat4(0.0);

	switch (this->type)
	{
		case CameraType::PERSPECTIVE:
		{
			// glm::perspective uses a right handed coordinate system
			// which I don't want, so below is my own version in
			// a left handed coordinate system.

			float const tanHalfFovY = tanf(fovOrSize / 2.0f);

			projection[0][0] = 1.0f / (aspectRatio * tanHalfFovY);
			projection[1][1] = 1.0f / (tanHalfFovY);
			projection[2][2] = (nearClippingPlane + farClippingPlane) / (farClippingPlane - nearClippingPlane);
			projection[2][3] = 1.0f;
			projection[3][2] = -(2.0f * farClippingPlane * nearClippingPlane) / (farClippingPlane - nearClippingPlane);
			
		} break;

		case CameraType::ORTHOGRAPHIC:
		{
			float halfVerticalSize = fovOrSize;
			float halfDepth = (farClippingPlane - nearClippingPlane) * 0.5f;

			projection[0][0] = 1.0f / halfVerticalSize * aspectRatio;
			projection[1][1] = 1.0f / halfVerticalSize;
			projection[2][2] = 1.0f / halfDepth;
			projection[3][3] = 1.0f;

		} break;
	}

	return projection;
}


Camera::Camera()
	: Camera{glm::vec3{0, 0, 0}, glm::quat{}}
{
}

Camera::Camera(glm::vec3 position, glm::quat orientation)
	: Camera{position, orientation, Window::GetLastCreated().GetAspectRatio(), 0.1f, 1000.0f, glm::radians(75.0f), CameraComponent::CameraType::PERSPECTIVE}
{
}

Camera::Camera(glm::vec3 position, glm::quat orientation, float aspectRatio, float nearPlane, float farPlane, float fovOrSize, CameraComponent::CameraType type)
{
	GetTransform().SetPosition(position).SetOrientation(orientation);

	AddComponent(
		std::make_shared<CameraComponent>(aspectRatio, nearPlane, farPlane, fovOrSize, type)
	);
}

void Camera::Update(float deltaTime, const Window& window)
{
	// Move the camera (for now in this very temporary solution)
	glm::vec3 movement = glm::vec3();
	const float baseSpeed = 4.0f; /* m/s */
	const float speed = baseSpeed * deltaTime;

	auto& keyboard = window.GetKeyboard();

	if (keyboard.IsKeyDown(GLFW_KEY_W) || keyboard.IsKeyDown(GLFW_KEY_UP))    movement.z += speed;
	if (keyboard.IsKeyDown(GLFW_KEY_S) || keyboard.IsKeyDown(GLFW_KEY_DOWN))  movement.z -= speed;
	if (keyboard.IsKeyDown(GLFW_KEY_A) || keyboard.IsKeyDown(GLFW_KEY_LEFT))  movement.x -= speed;
	if (keyboard.IsKeyDown(GLFW_KEY_D) || keyboard.IsKeyDown(GLFW_KEY_RIGHT)) movement.x += speed;
	if (keyboard.IsKeyDown(GLFW_KEY_SPACE) || keyboard.IsKeyDown(GLFW_KEY_RIGHT_SHIFT))    movement.y += speed;
	if (keyboard.IsKeyDown(GLFW_KEY_LEFT_SHIFT) || keyboard.IsKeyDown(GLFW_KEY_RIGHT_ALT)) movement.y -= speed;

	// Rotate translation to model space and translate
	movement = GetTransform().RotateVector(movement);
	GetTransform().Translate(movement);

	// If cursor is hidden, rotate the camera like an fps camera
	if (window.IsCursorHidden())
	{
		const float baseMouseSensitivity = 0.1f;
		const float mouseSensitivity = baseMouseSensitivity * deltaTime;

		glm::vec2 mouseDelta = window.GetMouse().GetMouseDelta();

		GetTransform().Rotate(glm::vec3(0, 1, 0), mouseDelta.x * mouseSensitivity);
		GetTransform().Rotate(GetTransform().GetRight(), mouseDelta.y * mouseSensitivity);
	}
}

glm::mat4 Camera::GetViewMatrix() const
{
	// Simply delegate to the CameraComponent
	return GetComponent<CameraComponent>()->GetViewMatrix();
}

glm::mat4 Camera::GetProjectionMatrix() const
{
	// Simply delegate to the CameraComponent
	return GetComponent<CameraComponent>()->GetProjectionMatrix();
}
