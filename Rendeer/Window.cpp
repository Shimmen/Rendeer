#include "Window.h"

Window::Window(int width, int height, const std::string& title, bool fullResolutionFullscreen, bool vSync)
{
	if (!glfwInit())
	{
		printf("Error: could not initialize glfw!");
	}

	// Set window related hints
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_VISIBLE, GL_TRUE);
	glfwWindowHint(GLFW_FLOATING, GL_FALSE /*GL_TRUE*/); // always on top

	// Set context related hints
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
	//glfwWindowHint(GLFW_SRGB_CAPABLE, GL_TRUE); later maybe?
	glfwWindowHint(GLFW_RED_BITS, 8);
	glfwWindowHint(GLFW_GREEN_BITS, 8);
	glfwWindowHint(GLFW_BLUE_BITS, 8);
	glfwWindowHint(GLFW_ALPHA_BITS, 8);
	glfwWindowHint(GLFW_DEPTH_BITS, 24);
	glfwWindowHint(GLFW_STENCIL_BITS, 8);

	if (fullResolutionFullscreen)
	{
		GLFWmonitor *primaryMonitor = glfwGetPrimaryMonitor();
		const GLFWvidmode *currentVideoMode = glfwGetVideoMode(primaryMonitor);

		// Create a fullscreen window with the size of the sceen, and ignore whatever was requested.
		windowHandle = glfwCreateWindow(currentVideoMode->width, currentVideoMode->height, title.c_str(), primaryMonitor, NULL);
	}
	else
	{
		// Create a windowed window with the requested size.
		windowHandle = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	}

	glfwMakeContextCurrent(windowHandle);

	// Store a pointer to the screen in the user pointer of the window.
	glfwSetWindowUserPointer(windowHandle, (void *)this);

	// Load OpenGL extentions etc. Use the glfw loader with glad.
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	SetVsyncEnabled(vSync);

	// Create input handlers
	keyboard = new Keyboard(windowHandle);
}

Window::~Window()
{
	// Make sure no key callbacks will be sent out to
	// classes that 
	glfwSetKeyCallback(windowHandle, NULL);

	delete keyboard;

	// Only one window is "allowed" at the moment.
	glfwDestroyWindow(windowHandle);
	glfwTerminate();
}
