#pragma once

#include <iostream>
#include <string>

#include <glad/glad.h>
#include <SDL.h>

#include "Input.h"

class Display
{
public:
	Display(const std::string& title = "Default title",
		int width = 1280, int height = 720, bool fullscreen = false);
	~Display();

	// Don't implement these, default behaviour is desired
	// Display(const Display& source);
	// Display& operator=(const Display& source);

	void PollEvents();

	inline const Input& GetInput() const
	{
		return input;
	}

	inline bool IsCloseRequested() const
	{
		return isCloseRequested;
	}

	inline void BindAsDrawFrameBuffer() const
	{
		// The display is only for drawing on (not reading)
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	}

	inline float GetAspectRatio() const
	{
		return (float)GetWidth() / (float)GetHeight();
	}

	inline int GetWidth() const
	{
		int width;
		SDL_GetWindowSize(window, &width, NULL);
		return width;
	}

	inline int GetHeight() const
	{
		int height;
		SDL_GetWindowSize(window, NULL, &height);
		return height;
	}

	inline void SwapBuffers() const
	{
		SDL_GL_SwapWindow(window);
	}

private:
	SDL_Window *window;
	SDL_GLContext glContext;

	bool isCloseRequested;
	Input input;
};
