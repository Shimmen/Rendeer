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

std::shared_ptr<FrameBuffer> CameraComponent::GetTarget() const
{
	return target;
}

void CameraComponent::SetTarget(std::shared_ptr<FrameBuffer> target)
{
	this->target = target;
}

void CameraComponent::SetAsMainCamera()
{
	this->target = nullptr;
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


CameraEntity::CameraEntity()
	: CameraEntity{glm::vec3{0, 0, 0}, glm::quat{}}
{
}

CameraEntity::CameraEntity(glm::vec3 position, glm::quat orientation)
	: CameraEntity{position, orientation, Window::CurrentWindow()->GetAspectRatio(), 0.1f, 1000.0f, glm::radians(75.0f), CameraComponent::CameraType::PERSPECTIVE}
{
}

CameraEntity::CameraEntity(glm::vec3 position, glm::quat orientation, float aspectRatio, float nearPlane, float farPlane, float fovOrSize, CameraComponent::CameraType type)
{
	GetTransform().SetPosition(position).SetOrientation(orientation);

	AddComponent(
		std::make_shared<CameraComponent>(aspectRatio, nearPlane, farPlane, fovOrSize, type)
	);
}

void CameraEntity::Update(float deltaTime, const Window& window)
{
	// If the delta time is way to big, ignore it altogether
	if (deltaTime > 0.5f) return;

	// Move the camera (for now in this very temporary solution)
	glm::vec3 movement = glm::vec3();
	const float baseSpeed = 4.0f; /* m/s */
	const float speed = baseSpeed * deltaTime;

	if (window.IsKeyDown(GLFW_KEY_W) || window.IsKeyDown(GLFW_KEY_UP))    movement.z += speed;
	if (window.IsKeyDown(GLFW_KEY_S) || window.IsKeyDown(GLFW_KEY_DOWN))  movement.z -= speed;
	if (window.IsKeyDown(GLFW_KEY_A) || window.IsKeyDown(GLFW_KEY_LEFT))  movement.x -= speed;
	if (window.IsKeyDown(GLFW_KEY_D) || window.IsKeyDown(GLFW_KEY_RIGHT)) movement.x += speed;
	if (window.IsKeyDown(GLFW_KEY_SPACE) || window.IsKeyDown(GLFW_KEY_RIGHT_SHIFT))    movement.y += speed;
	if (window.IsKeyDown(GLFW_KEY_LEFT_SHIFT) || window.IsKeyDown(GLFW_KEY_RIGHT_ALT)) movement.y -= speed;

	// Rotate translation to model space and translate
	movement = GetTransform().RotateVector(movement);
	GetTransform().Translate(movement);

	// If cursor is hidden, rotate the camera like an fps camera
	if (window.IsCursorHidden())
	{
		const float baseMouseSensitivity = 0.1f;
		const float mouseSensitivity = baseMouseSensitivity * deltaTime;

		glm::vec2 mouseDelta = window.GetMouseDelta();

		GetTransform().Rotate(glm::vec3(0, 1, 0), mouseDelta.x * mouseSensitivity);
		GetTransform().Rotate(GetTransform().GetRight(), mouseDelta.y * mouseSensitivity);
	}
}

glm::mat4 CameraEntity::GetViewMatrix() const
{
	// Simply delegate to the CameraComponent
	return GetComponent<CameraComponent>()->GetViewMatrix();
}

glm::mat4 CameraEntity::GetProjectionMatrix() const
{
	// Simply delegate to the CameraComponent
	return GetComponent<CameraComponent>()->GetProjectionMatrix();
}
