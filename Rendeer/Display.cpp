#include "Display.h"

#include <assert.h>

Display::Display(const std::string& title,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
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

	// Must be done after gl context is aquired
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "GLEW Error!" << std::endl;
		exit(1);
	}
}

Display::~Display()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Display::SetClearColor(float r, float g, float b, float a) const
{
	assert(r >= 0 && r <= 1 &&
		g >= 0 && g <= 1 &&
		b >= 0 && b <= 1 &&
		a >= 0 && a <= 1);

	glClearColor(r, g, b, a);
}

void Display::SetClearDepth(double depth) const
{
	assert(depth >= 0 && depth <= 1);

	glClearDepth(depth);
}

void Display::Clear(GLenum buffersToClearMask) const
{
	assert((buffersToClearMask & GL_COLOR_BUFFER_BIT) != 0 ||
		(buffersToClearMask & GL_DEPTH_BUFFER_BIT) != 0 ||
		(buffersToClearMask & GL_STENCIL_BUFFER_BIT) != 0);

	glClear(buffersToClearMask);
}

