
#include <iostream>

#include <SDL.h>
#include <GL\glew.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

extern "C" int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);


	SDL_Window *window = SDL_CreateWindow("Test window",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	// Must be done after gl context is aquired
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "GLEW Error!" << std::endl;
		return 1;
	}

	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	float vertices[3][2] = { {-1.0f, -1.0f}, {0.0f, 1.0f}, {1.0f, -1.0f} };
	float indices[3] = { 0, 1, 2 };

	//GLuint triangleBuffer;
	//glCreateBuffers(1, &triangleBuffer);
	//glBindBuffer(GL_ARRAY_BUFFER, triangleBuffer);
	////glBufferData(GL_ARRAY_BUFFER, )

	SDL_GL_SwapWindow(window);

	SDL_GL_DeleteContext(glContext);
	SDL_Quit();

	return 0;
}