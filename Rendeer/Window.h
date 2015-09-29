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


	void GetFramebufferSize(int *widthPixels, int * heightPixels) const;
	int GetFramebufferWidth() const;
	int GetFramebufferHeight() const;
	float GetAspectRatio() const;

	void BindAsDrawFramebuffer() const;
	void SetVsyncEnabled(bool enabled) const;
	void SwapBuffers() const;

	void PollEvents() const;
	
	bool IsCloseRequested() const;
	bool IsFullscreen() const;
	bool IsCursorHidden() const;
	void SetCursorHidden(bool hidden) const;
	void SetWindowPosition(int xPos, int yPos) const;

	inline const Keyboard& GetKeyboard() const { return *keyboard; }
	inline const Mouse& GetMouse() const { return *mouse; }

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
