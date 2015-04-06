#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

class Keyboard
{
public:

	inline bool IsKeyDown(int key) const { return isKeyDown[key]; }
	inline bool WasKeyPressed(int key) const { return wasKeyPressed[key]; }
	inline bool WasKeyReleased(int key) const { return wasKeyReleased[key]; }

	Keyboard(GLFWwindow *glfwWindow);

	// The reseting of the key callback is done by the Window
	// when it's destroyed. If a new keyboard handler is set
	// and the initial keyboard handler gets detructed, the
	// window shouldn't loose it's 
	//~Keyboard();

	static void keyEventCallback(GLFWwindow *glfwWindow, int key, int scancode, int action, int mods);

private:

	// Will reset the arrays wasPressedKeys and wasReleasedKeys to false.
	inline void ResetPressedAndReleasedKeys()
	{
		// Set all bytes to false (i.e. 0).
		memset(wasKeyPressed, 0, KEYBOARD_KEY_COUNT * sizeof(bool));
		memset(wasKeyReleased, 0, KEYBOARD_KEY_COUNT * sizeof(bool));
	}

	inline void SetKeyPressed(int key)
	{
		wasKeyPressed[key] = true;
		isKeyDown[key] = true;
	}

	inline void SetKeyReleased(int key)
	{
		wasKeyReleased[key] = true;
		isKeyDown[key] = false;
	}


	// The highest possible KeyCode is GLFW_KEY_LAST.
	static const int KEYBOARD_KEY_COUNT = GLFW_KEY_LAST;

	bool isKeyDown[KEYBOARD_KEY_COUNT];
	bool wasKeyPressed[KEYBOARD_KEY_COUNT];
	bool wasKeyReleased[KEYBOARD_KEY_COUNT];

};
