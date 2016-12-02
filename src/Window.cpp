#include "Window.h"

#include "Logger.h"

/* static */ int Window::windowCount{ 0 };
/* static */ const Window *Window::lastCreatedWindow;

Window::Window(int width, int height, const std::string & title, bool vSync)
	: isFullscreen{ false }
	, isVsyncEnabled{ vSync }
{
	InitializeGlfwIfNeeded();
	SetUpGlobalWindowHints();

	// Create a windowed window with the requested size.
	this->windowHandle = CreateWindowedWindow(width, height, title);
	windowCount++;
	lastCreatedWindow = this;

	MakeContextCurrent();
	LoadOpenGLForCurrentContext();
	SetUpWindowUserPointer(this->windowHandle);

	SetVsyncEnabled(vSync);
	SetCursorHidden(false);

	CreateInputHandlers(this->windowHandle);
}

Window::Window(const std::string & title, bool vSync)
	: isFullscreen{ true }
	, isVsyncEnabled{ vSync }
{
	InitializeGlfwIfNeeded();
	SetUpGlobalWindowHints();

	// Create a fullscreen window with the size of the sceen.
	this->windowHandle = CreateFullscreenWindow(title);
	windowCount++;
	lastCreatedWindow = this;

	MakeContextCurrent();
	LoadOpenGLForCurrentContext();
	SetUpWindowUserPointer(this->windowHandle);

	SetVsyncEnabled(vSync);
	SetCursorHidden(false);

	CreateInputHandlers(this->windowHandle);
}

Window::~Window()
{
	glfwSetKeyCallback(windowHandle, nullptr);
	glfwSetMouseButtonCallback(windowHandle, nullptr);
	glfwSetCursorPosCallback(windowHandle, nullptr);
	glfwDestroyWindow(windowHandle);

	windowCount--;
	if (windowCount <= 0)
	{
		// Destroy GLFW context if there are no more windows
		glfwTerminate();
	}
}

/* static */ const Window& Window::FromGlfwWindow(GLFWwindow *glfwWindowPointer)
{
	return *static_cast<Window *>(glfwGetWindowUserPointer(glfwWindowPointer));
}

/* static */ const Window& Window::GetLastCreated()
{
	assert(lastCreatedWindow != nullptr);
	return *lastCreatedWindow;
}

void Window::PollEvents() const
{
	// Very important that these get called BEFORE polling new events
	// If not, the wasPressed/Released arrays will be cleared as soon
	// as they get filled in by glfwPollEvents().
	keyboard->Update();
	mouse->Update();

	glfwPollEvents();
}

void Window::SwapBuffers() const
{
	glfwSwapBuffers(this->windowHandle);
}

bool Window::IsCloseRequested() const
{
	return (glfwWindowShouldClose(this->windowHandle) != 0);
}

void Window::MakeContextCurrent() const
{
	glfwMakeContextCurrent(this->windowHandle);
}

void Window::BindAsDrawFramebuffer() const
{
	// Bind framebuffer 0, i.e. the window for this context
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

	int width, height;
	GetFramebufferSize(&width, &height);
	glViewport(0, 0, width, height);
}

bool Window::IsFullscreen() const
{
	return this->isFullscreen;
}

void Window::SetWindowPosition(int xPos, int yPos) const
{
	glfwSetWindowPos(this->windowHandle, xPos, yPos);
}

void Window::GetFramebufferSize(int *widthPixels, int * heightPixels) const
{
	glfwGetFramebufferSize(this->windowHandle, widthPixels, heightPixels);
}

int Window::GetFramebufferWidth() const
{
	int width;
	GetFramebufferSize(&width, nullptr);
	return width;
}

int Window::GetFramebufferHeight() const
{
	int height;
	GetFramebufferSize(nullptr, &height);
	return height;
}

float Window::GetAspectRatio() const
{
	int width, height;
	GetFramebufferSize(&width, &height);

	return (float)width / (float)height;
}

bool Window::IsVsyncEnabled() const
{
	return isVsyncEnabled;
}

void Window::SetVsyncEnabled(bool enabled)
{
	int interval = enabled ? 1 : 0;
	glfwSwapInterval(interval);
	this->isVsyncEnabled = enabled;
}

bool Window::IsCursorHidden() const
{
	int cursorMode = glfwGetInputMode(this->windowHandle, GLFW_CURSOR);
	return (cursorMode == GLFW_CURSOR_DISABLED);
}

void Window::SetCursorHidden(bool hidden) const
{
	int mode = (hidden) ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL;
	glfwSetInputMode(this->windowHandle, GLFW_CURSOR, mode);
}

const Keyboard& Window::GetKeyboard() const
{
	return *this->keyboard;
}

const Mouse& Window::GetMouse() const
{
	return *this->mouse;
}

GLFWwindow *Window::CreateWindowedWindow(int width, int height, const std::string& title) const
{
	return glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);;
}

GLFWwindow *Window::CreateFullscreenWindow(const std::string& title) const
{
	GLFWmonitor *primaryMonitor = glfwGetPrimaryMonitor();
	if (primaryMonitor != nullptr)
	{
		const GLFWvidmode *currentVideoMode = glfwGetVideoMode(primaryMonitor);
		if (currentVideoMode != nullptr)
		{
			const int width = currentVideoMode->width;
			const int height = currentVideoMode->height;

			return glfwCreateWindow(width, height, title.c_str(), primaryMonitor, nullptr);
			
		}
		else
		{
			Logger::GetDefaultLogger().Log("Error: primary video mode could not be accessed for primary monitor.");
			return nullptr;
		}
	}
	else
	{
		Logger::GetDefaultLogger().Log("Error: primary monitor could not be accessed.");
		return nullptr;
	}
}

void Window::InitializeGlfwIfNeeded() const
{
	if (windowCount == 0)
	{
		int result = glfwInit();
		if (result == GL_FALSE)
		{
			Logger::GetDefaultLogger().Log("Error: could not initialize glfw! Application must terminate.");
		}
	}
}

void Window::LoadOpenGLForCurrentContext() const
{
	// Use the glfw loader with glad (this way the glad source doesn't need to include its own loader).
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

void Window::SetUpGlobalWindowHints() const
{
	// Set window related hints
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_VISIBLE, GL_TRUE);
	glfwWindowHint(GLFW_FLOATING, GL_FALSE);
	
	// Set context related hints
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
	glfwWindowHint(GLFW_SRGB_CAPABLE, GL_TRUE);
	glfwWindowHint(GLFW_RED_BITS, 8);
	glfwWindowHint(GLFW_GREEN_BITS, 8);
	glfwWindowHint(GLFW_BLUE_BITS, 8);
	glfwWindowHint(GLFW_ALPHA_BITS, 8);
	glfwWindowHint(GLFW_DEPTH_BITS, 24);
	glfwWindowHint(GLFW_STENCIL_BITS, 8);
}

void Window::SetUpWindowUserPointer(GLFWwindow *window)
{
	// Store a pointer to the C++ Window instance in the user pointer of the GLFW window handle.
	glfwSetWindowUserPointer(window, static_cast<void *>(this));
}

void Window::CreateInputHandlers(GLFWwindow *window)
{
	keyboard.reset(new Keyboard(window));
	mouse.reset(new Mouse(window));
}
