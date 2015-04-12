#include "Keyboard.h"

#include "Window.h"

Keyboard::Keyboard(GLFWwindow *glfwWindow)
{
	// Set all keys to false
	memset(isKeyDown, 0, KEYBOARD_KEY_COUNT * sizeof(bool));
	ResetPressedAndReleasedKeys();

	glfwSetKeyCallback(glfwWindow, Keyboard::KeyEventCallback);
}

/* static */ void Keyboard::KeyEventCallback(GLFWwindow *glfwWindow, int key, int scancode, int action, int mods)
{
	Window& window = Window::FromGlfwWindow(glfwWindow);

	switch (action)
	{
	case GLFW_PRESS:
		window.keyboard->SetKeyPressed(key);
		break;

	case GLFW_RELEASE:
		window.keyboard->SetKeyReleased(key);
		break;

	case GLFW_REPEAT:
	default:
		break;
	}
}