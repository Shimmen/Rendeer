#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include <memory>

class Window
{
public:

	Window(int width, int height, bool fullscreen = false, bool vSync = true);
	~Window();

	static const Window *CurrentWindow();

	void PollEvents();
	void SwapBuffers() const;
	bool IsCloseRequested() const;

	void MakeCurrent() const;

	void BindAsDrawFrameBuffer(bool setViewport = true) const;
	void BindAsReadFrameBuffer() const;

	bool IsFullscreen() const;

	void GetFramebufferSize(int *width, int *height) const;
	int GetFramebufferWidth() const;
	int GetFramebufferHeight() const;
	float GetAspectRatio() const;
	void GetWindowSize(int *width, int *height) const;

	bool IsVsyncEnabled() const;
	void SetVsyncEnabled(bool enabled);
	
	bool IsCursorHidden() const;
	void SetCursorHidden(bool hidden) const;

	void Focus() const;
	bool IsFocused() const;

	const char *GetClipboardText() const;
	void SetClipboardText(const std::string& text) const;
	void SetClipboardText(const char *text) const;

	//
	// Keyboard related
	//

	bool IsKeyDown(int key) const;
	bool WasKeyPressed(int key) const;
	bool WasKeyReleased(int key) const;

	static void KeyEventCallback(GLFWwindow *glfwWindow, int key, int scancode, int action, int mods);
	static void CharEventCallback(GLFWwindow *glfwWindow, unsigned int codepoint, int mods);

	//
	// Mouse related
	//

	bool IsButtonDown(int button) const;
	bool WasButtonPressed(int button) const;
	bool WasButtonReleased(int button) const;

	glm::vec2 GetMousePosition() const;
	glm::vec2 GetMouseDelta() const;
	float GetScrollDelta() const;

	static void MouseButtonEventCallback(GLFWwindow *glfwWindow, int button, int action, int mods);
	static void MouseMovementEventCallback(GLFWwindow *glfwWindow, double xPos, double yPos);
	static void MouseScrollEventCallback(GLFWwindow *glfwWindow, double xOffset, double yOffset);

private:

	Window(Window& other) = delete;
	Window& operator=(Window& other) = delete;

private:

	GLFWwindow *glfwWindow;
	bool fullscreen;
	bool vsyncEnabled;

	//
	// Keyboard related
	//

	static const int KEYBOARD_KEY_COUNT{ GLFW_KEY_LAST };

	bool isKeyDown[KEYBOARD_KEY_COUNT] = { 0 };
	bool wasKeyPressed[KEYBOARD_KEY_COUNT] = { 0 };
	bool wasKeyReleased[KEYBOARD_KEY_COUNT] = { 0 };

	//
	// Mouse related
	//

	static const int MOUSE_BUTTON_COUNT{ GLFW_MOUSE_BUTTON_LAST };

	bool isButtonDown[MOUSE_BUTTON_COUNT] = { 0 };
	bool wasButtonPressed[MOUSE_BUTTON_COUNT] = { 0 };
	bool wasButtonReleased[MOUSE_BUTTON_COUNT] = { 0 };

	// Should only be used for getting the mouse delta etc. NOT for querying current position, since this accumulates errors and might "lag" behind.
	mutable double currentXPosition{0};
	mutable double currentYPosition{0};
	mutable double lastXPosition{0};
	mutable double lastYPosition{0};

	double currentScollOffset{0};
	double lastScrollOffset{0};

private:

	static const Window *currentWindow;

};
