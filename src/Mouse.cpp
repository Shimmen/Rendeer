#include "Mouse.h"

#include "Window.h"

Mouse::Mouse(GLFWwindow *glfwWindow)
{
	// Set all buttons to false
	memset(isButtonDown, 0, MOUSE_BUTTON_COUNT * sizeof(bool));
	ResetPressedAndReleasedButtons();

	glfwSetMouseButtonCallback(glfwWindow, Mouse::MouseButtonEventCallback);
	glfwSetCursorPosCallback(glfwWindow, Mouse::MouseMovementEventCallback);
}

Mouse::~Mouse()
{
	// The reseting of the mouse callback is done by the Window
	// when it's destroyed. If a new mouse handler is set
	// and the initial mouse handler gets detructed, the
	// window shouldn't loose its callback.
}

bool Mouse::IsButtonDown(int key) const
{
	return isButtonDown[key];
}

bool Mouse::WasButtonPressed(int key) const
{
	return wasButtonPressed[key];
}

bool Mouse::WasButtonReleased(int key) const
{
	return wasButtonReleased[key];
}

glm::vec2 Mouse::GetMousePosition() const
{
	return glm::vec2((float)currentXPosition, (float)currentYPosition);
}

glm::vec2 Mouse::GetMouseDelta() const
{
	return glm::vec2(currentXPosition - lastXPosition, currentYPosition - lastYPosition);
}

void Mouse::Update()
{
	ResetPressedAndReleasedButtons();

	lastXPosition = currentXPosition;
	lastYPosition = currentYPosition;
}

/* static */ void Mouse::MouseButtonEventCallback(GLFWwindow *glfwWindow, int button, int action, int mods)
{
	const Window *window = Window::FromGlfwWindow(glfwWindow);

	switch (action)
	{
	case GLFW_PRESS:
		window->mouse->SetButtonPressed(button);
		break;

	case GLFW_RELEASE:
		window->mouse->SetButtonReleased(button);
		break;

	default:
		break;
	}
}

/* static */ void Mouse::MouseMovementEventCallback(GLFWwindow *glfwWindow, double xPos, double yPos)
{
	const Window *window = Window::FromGlfwWindow(glfwWindow);

	window->mouse->currentXPosition = xPos;
	window->mouse->currentYPosition = yPos;
}

void Mouse::ResetPressedAndReleasedButtons()
{
	memset(wasButtonPressed, false, MOUSE_BUTTON_COUNT * sizeof(bool));
	memset(wasButtonReleased, false, MOUSE_BUTTON_COUNT * sizeof(bool));
}

void Mouse::SetButtonPressed(int key)
{
	wasButtonPressed[key] = true;
	isButtonDown[key] = true;
}

void Mouse::SetButtonReleased(int key)
{
	wasButtonReleased[key] = true;
	isButtonDown[key] = false;
}
