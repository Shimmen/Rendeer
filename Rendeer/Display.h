#pragma once

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <SDL.h>

class Display
{
public:
	Display(const std::string& title = "Default title",
		int width = 1280, int height = 720, bool fullscreen = false);
	~Display();

	// Don't implement these, default behaviour is desireable
	// Display(const Display& source);
	// Display& operator=(const Display& source);

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

	void SetClearColor(float r, float g, float b, float a) const;
	void SetClearDepth(double depth) const;
	void Clear(GLenum buffersToClearMask) const;

	inline void SwapBuffers() const
	{
		SDL_GL_SwapWindow(window);
	}

private:
	SDL_Window *window;
	SDL_GLContext glContext;
};
