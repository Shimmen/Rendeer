#pragma once

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <SDL.h>

class Display
{
public:
	Display::Display(const std::string& title, int width, int height);
	~Display();

	void Clear(float r, float g, float b, float a);
	void SwapBuffers();

private:
	SDL_GLContext glContext;
	SDL_Window *window;
};

