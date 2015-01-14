#include "Display.h"

Display::Display(const std::string title = "Default title",
	int width = 1280, int height = 720)
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

	window = SDL_CreateWindow(title.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	glContext = SDL_GL_CreateContext(window);

	// Must be done after gl context is aquired
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "GLEW Error!" << std::endl;
		exit(1);
	}
}

void Display::SwapBuffers()
{
	SDL_GL_SwapWindow(window);
}

Display::~Display()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
