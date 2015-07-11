#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

#include "Keyboard.h"
#include "Mouse.h"

class Window
{
public:
	Window(int width, int height, const std::string& title, bool fullResolutionFullscreen = false, bool vSync = true);
	~Window();

	inline static Window& FromGlfwWindow(GLFWwindow *glfwWindowPointer)
	{
		return *static_cast<Window *>(glfwGetWindowUserPointer(glfwWindowPointer));
	}


	// Returns the size of the framebuffer in pixels
	inline void GetFramebufferSize(int *widthPixels, int * heightPixels) const
	{
		glfwGetFramebufferSize(windowHandle, widthPixels, heightPixels);
	}

	inline int GetFramebufferWidth() const
	{
		int width;
		GetFramebufferSize(&width, NULL);
		return width;
	}

	inline int GetFramebufferHeight() const
	{
		int height;
		GetFramebufferSize(NULL, &height);
		return height;
	}

	inline void SetWindowPosition(int xPos, int yPos) const
	{
		glfwSetWindowPos(windowHandle, xPos, yPos);
	}

	inline float GetAspectRatio() const
	{
		int width, height;
		GetFramebufferSize(&width, &height);

		return (float)width / (float)height;
	}

	inline void BindAsDrawFramebuffer() const
	{
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	}

	inline void SetVsyncEnabled(bool enabled) const
	{
		int interval = enabled ? 1 : 0;
		glfwSwapInterval(interval);
	}

	inline void SwapBuffers() const
	{
		glfwSwapBuffers(windowHandle);
	}

	inline bool IsCloseRequested() const
	{
		return (glfwWindowShouldClose(windowHandle) != 0);
	}

	inline bool IsFullscreen() const
	{
		return isFullscreen;
	}

	inline void SetCursorHidden(bool hidden) const
	{
		int mode = (hidden) ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL;
		glfwSetInputMode(windowHandle, GLFW_CURSOR, mode);
		this->cursorIsHidden = hidden;
	}

	inline bool IsCursorHidden() const
	{
		return this->cursorIsHidden;
	}

	inline const Keyboard& GetKeyboard() const
	{
		return *keyboard;
	}

	inline const Mouse& GetMouse() const
	{
		return *mouse;
	}

	void PollEvents() const;

private:
	GLFWwindow *windowHandle;

	// You should be able to change this, given a const Window.
	// The state if this isnt really a big deal really.
	mutable bool cursorIsHidden;

	bool isFullscreen;

	// The input classes and their callbacks require
	//access to certain members of the Window class
	friend class Keyboard;
	friend class Mouse;

	Keyboard *keyboard;
	Mouse *mouse;

};
