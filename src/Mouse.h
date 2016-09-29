#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

#include <glm/glm.hpp>

class Mouse
{
public:

	Mouse(GLFWwindow *glfwWindow);
	~Mouse();

	bool IsButtonDown(int key) const;
	bool WasButtonPressed(int key) const;
	bool WasButtonReleased(int key) const;

	glm::vec2 GetMousePosition() const;
	glm::vec2 GetMouseDelta() const;

	void Update();

public:

	static void MouseButtonEventCallback(GLFWwindow *glfwWindow, int button, int action, int mods);
	static void MouseMovementEventCallback(GLFWwindow *glfwWindow, double xPos, double yPos);

private:

	void ResetPressedAndReleasedButtons();
	void SetButtonPressed(int key);
	void SetButtonReleased(int key);

private:

	// The highest possible button count is GLFW_MOUSE_BUTTON_LAST.
	static const int MOUSE_BUTTON_COUNT{ GLFW_MOUSE_BUTTON_LAST };

	bool isButtonDown[MOUSE_BUTTON_COUNT];
	bool wasButtonPressed[MOUSE_BUTTON_COUNT];
	bool wasButtonReleased[MOUSE_BUTTON_COUNT];

	double currentXPosition{ 0 };
	double currentYPosition{ 0 };

	double lastXPosition{0};
	double lastYPosition{0};

};
