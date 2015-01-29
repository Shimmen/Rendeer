#pragma once

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <SDL.h>

class Display
{
public:
	Display(const std::string& title, int width, int height);
	~Display();

	// Don't implement these, default behaviour is desireable
	// Display(const Display& source);
	// Display& operator=(const Display& source);

	void Clear(float r, float g, float b, float a);
	void SwapBuffers();

private:
	SDL_Window *window;
	SDL_GLContext glContext;
};
