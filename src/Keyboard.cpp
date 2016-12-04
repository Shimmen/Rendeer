#include "Keyboard.h"

#include "Window.h"

Keyboard::Keyboard(GLFWwindow *glfwWindow)
{
	// Set all keys to false
	memset(isKeyDown, 0, KEYBOARD_KEY_COUNT * sizeof(bool));
	ResetPressedAndReleasedKeys();

	glfwSetKeyCallback(glfwWindow, Keyboard::KeyEventCallback);
}

Keyboard::~Keyboard()
{
	// The reseting of the key callback is done by the Window
	// when it's destroyed. If a new keyboard handler is set
	// and the initial keyboard handler gets detructed, the
	// window shouldn't loose its callback
}

bool Keyboard::IsKeyDown(int key) const
{
	return isKeyDown[key];
}

bool Keyboard::WasKeyPressed(int key) const
{
	return wasKeyPressed[key];
}

bool Keyboard::WasKeyReleased(int key) const
{
	return wasKeyReleased[key];
}

void Keyboard::Update()
{
	ResetPressedAndReleasedKeys();
}

/* static */ void Keyboard::KeyEventCallback(GLFWwindow *glfwWindow, int key, int scancode, int action, int mods)
{
	const Window& window = Window::FromGlfwWindow(glfwWindow);

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

void Keyboard::ResetPressedAndReleasedKeys()
{
	// Set all bytes to false (i.e. 0).
	memset(wasKeyPressed, false, KEYBOARD_KEY_COUNT * sizeof(bool));
	memset(wasKeyReleased, false, KEYBOARD_KEY_COUNT * sizeof(bool));
}

void Keyboard::SetKeyPressed(int key)
{
	wasKeyPressed[key] = true;
	isKeyDown[key] = true;
}

void Keyboard::SetKeyReleased(int key)
{
	wasKeyReleased[key] = true;
	isKeyDown[key] = false;
}
