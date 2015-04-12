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

/* static */ void Mouse::MouseButtonEventCallback(GLFWwindow *glfwWindow, int button, int action, int mods)
{
	Window& window = Window::FromGlfwWindow(glfwWindow);

	switch (action)
	{
	case GLFW_PRESS:
		window.mouse->SetButtonPressed(button);
		break;

	case GLFW_RELEASE:
		window.mouse->SetButtonReleased(button);
		break;

	default:
		break;
	}
}

/* static */ void Mouse::MouseMovementEventCallback(GLFWwindow *glfwWindow, double xPos, double yPos)
{
	Window& window = Window::FromGlfwWindow(glfwWindow);
	Mouse *mouse = window.mouse;

	mouse->currentXPosition = xPos;
	mouse->currentYPosition = yPos;
}
