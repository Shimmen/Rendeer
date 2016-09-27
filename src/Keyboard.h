#pragma once

#include <glad2/glad.h>
#include <GLFW/glfw3.h>

#include <string>

class Keyboard
{
public:

	Keyboard(GLFWwindow *glfwWindow);
	~Keyboard();

	bool IsKeyDown(int key) const;
	bool WasKeyPressed(int key) const;
	bool WasKeyReleased(int key) const;

	void Update();

public:

	static void KeyEventCallback(GLFWwindow *glfwWindow, int key, int scancode, int action, int mods);

private:

	void ResetPressedAndReleasedKeys();
	void SetKeyPressed(int key);
	void SetKeyReleased(int key);

private:

	// The highest possible KeyCode is GLFW_KEY_LAST.
	static const int KEYBOARD_KEY_COUNT{ GLFW_KEY_LAST };

	bool isKeyDown[KEYBOARD_KEY_COUNT];
	bool wasKeyPressed[KEYBOARD_KEY_COUNT];
	bool wasKeyReleased[KEYBOARD_KEY_COUNT];

};
