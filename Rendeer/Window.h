#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

#include "Keyboard.h"

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

	inline void PollEvents() const
	{
		glfwPollEvents();
	}

	inline bool IsCloseRequested() const
	{
		return (glfwWindowShouldClose(windowHandle) != 0);
	}

	
	inline const Keyboard& GetKeyboard() const
	{
		return *keyboard;
	}
	
	
private:
	GLFWwindow * windowHandle;

	// The input classes and their callbacks need to access certain members of the Window class
	friend class Keyboard;

	Keyboard *keyboard;

};

