#include "Display.h"

#include <assert.h>

Display::Display(const std::string& title,
	int width, int height, bool fullscreen)
	: isCloseRequested(false)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "SDL_Init video error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	Uint32 windowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
	if (fullscreen)
	{
		windowFlags |= SDL_WINDOW_FULLSCREEN;
	}

	window = SDL_CreateWindow(title.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, windowFlags);

	glContext = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, glContext);

	// Load OpenGL extentions.
	// Must be done after gl context is aquired
	gladLoadGL();
}

Display::~Display()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Display::PollEvents()
{
	input.ResetPressedAndReleasedKeys();

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			isCloseRequested = true;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			if (event.key.repeat == 0)
			{
				input.SetKeyPressed(event.key.keysym.scancode);
			}
		}
		else if (event.type == SDL_KEYUP)
		{
			if (event.key.repeat == 0)
			{
				input.SetKeyReleased(event.key.keysym.scancode);
			}
		}
	}
}