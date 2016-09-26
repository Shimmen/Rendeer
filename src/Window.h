#pragma once

//#define GLAD_IMPLEMENTATION
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <memory>

#include "Keyboard.h"
#include "Mouse.h"

class Window
{
public:

	Window(int width, int height, const std::string& title, bool vSync = true);
	Window(const std::string& title, bool vSync = true);

	~Window();

	static const Window& FromGlfwWindow(GLFWwindow *glfwWindowPointer);
	static const Window& GetLastCreated();

	void PollEvents() const;
	void SwapBuffers() const;
	bool IsCloseRequested() const;

	void MakeContextCurrent() const;
	void BindAsDrawFramebuffer() const;

	bool IsFullscreen() const;
	void SetWindowPosition(int xPos, int yPos) const;

	void GetFramebufferSize(int *widthPixels, int * heightPixels) const;
	int GetFramebufferWidth() const;
	int GetFramebufferHeight() const;
	float GetAspectRatio() const;

	bool IsVsyncEnabled() const;
	void SetVsyncEnabled(bool enabled);
	
	bool IsCursorHidden() const;
	void SetCursorHidden(bool hidden) const;

	const Keyboard& GetKeyboard() const;
	const Mouse& GetMouse() const;

private:

	Window(Window& other) = delete;
	Window& operator=(Window& other) = delete;

	GLFWwindow *CreateWindowedWindow(int width, int height, const std::string& title) const;
	GLFWwindow *CreateFullscreenWindow(const std::string& title) const;

	void InitializeGlfwIfNeeded() const;
	void LoadOpenGLForCurrentContext() const;
	void SetUpGlobalWindowHints() const;
	void SetUpWindowUserPointer(GLFWwindow *window);
	void CreateInputHandlers(GLFWwindow *window);

private:

	GLFWwindow *windowHandle;

	static int windowCount;
	static const Window *lastCreatedWindow;

	bool isFullscreen;
	bool isVsyncEnabled;

	// The input classes and their callbacks require access to certain members of the Window class
	friend class Keyboard;
	friend class Mouse;

	// Pointer types to initialization can be deferred to the constructor body
	std::unique_ptr<Keyboard> keyboard;
	std::unique_ptr<Mouse> mouse;

};
