#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

#include <glm/glm.hpp>

class Mouse
{
public:

	Mouse(GLFWwindow *glfwWindow);

	// The reseting of the mouse callback is done by the Window
	// when it's destroyed. If a new mouse handler is set
	// and the initial mouse handler gets detructed, the
	// window shouldn't loose its callback.
	//~Mouse();

	inline bool IsButtonDown(int key) const { return isButtonDown[key]; }
	inline bool WasButtonPressed(int key) const { return wasButtonPressed[key]; }
	inline bool WasButtonReleased(int key) const { return wasButtonReleased[key]; }

	inline glm::vec2 GetMousePosition() const
	{
		return glm::vec2((float)currentXPosition, (float)currentYPosition);
	}

	inline glm::vec2 GetMouseDelta() const
	{
		return glm::vec2(currentXPosition - lastXPosition, currentYPosition - lastYPosition);
	}

	inline void Update()
	{
		ResetPressedAndReleasedButtons();

		lastXPosition = currentXPosition;
		lastYPosition = currentYPosition;
	}

	static void MouseMovementEventCallback(GLFWwindow *glfwWindow, double xPos, double yPos);
	static void MouseButtonEventCallback(GLFWwindow *glfwWindow, int button, int action, int mods);

private:

	inline void ResetPressedAndReleasedButtons()
	{
		// Set all bytes to false (i.e. 0).
		memset(wasButtonPressed, 0, MOUSE_BUTTON_COUNT * sizeof(bool));
		memset(wasButtonReleased, 0, MOUSE_BUTTON_COUNT * sizeof(bool));
	}

	inline void SetButtonPressed(int key)
	{
		wasButtonPressed[key] = true;
		isButtonDown[key] = true;
	}

	inline void SetButtonReleased(int key)
	{
		wasButtonReleased[key] = true;
		isButtonDown[key] = false;
	}


	// The highest possible button count is GLFW_MOUSE_BUTTON_LAST.
	static const int MOUSE_BUTTON_COUNT = GLFW_MOUSE_BUTTON_LAST;

	bool isButtonDown[MOUSE_BUTTON_COUNT];
	bool wasButtonPressed[MOUSE_BUTTON_COUNT];
	bool wasButtonReleased[MOUSE_BUTTON_COUNT];


	double lastXPosition = 0;
	double lastYPosition = 0;

	double currentXPosition = 0;
	double currentYPosition = 0;

};
