#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <memory>

#include "Keyboard.h"
#include "Mouse.h"

class Window
{
public:

	Window(int width, int height, bool fullscreen = false, bool vSync = true);
	~Window();

	static const Window *FromGlfwWindow(GLFWwindow *glfwWindow);
	static const Window *CurrentWindow();

	// Will poll window events and make sure the mouse & keyboard are up to date
	void PollEvents();

	void SwapBuffers() const;
	bool IsCloseRequested() const;

	void MakeCurrent() const;

	void BindAsDrawFrameBuffer() const;
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

	const Keyboard& GetKeyboard() const;
	const Mouse& GetMouse() const;

private:

	Window(Window& other) = delete;
	Window& operator=(Window& other) = delete;

private:

	GLFWwindow *glfwWindow;
	bool fullscreen;
	bool vsyncEnabled;

	// The input classes and their callbacks require access to certain members of the Window class
	friend class Keyboard;
	friend class Mouse;

	// Pointer types to initialization can be deferred to the constructor body
	std::unique_ptr<Keyboard> keyboard;
	std::unique_ptr<Mouse> mouse;

private:

	static const Window *currentWindow;

};
