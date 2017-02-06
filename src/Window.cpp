#include "Window.h"

#include "Logger.h"
#include "GLState.h"
#include "FrameBuffer.h"

/*static*/ const Window *Window::currentWindow;

Window::Window(int width, int height, bool fullscreen, bool vSync)
	: fullscreen{ fullscreen }
	, vsyncEnabled{ vSync }
{
	static bool firstWindow = true;
	if (firstWindow)
	{
		if (!glfwInit())
		{
			Logger::GetDefaultLogger().Log("Error: could not initialize glfw! Application must terminate.");
		}

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
		glfwWindowHint(GLFW_DEPTH_BITS, 16);
		glfwWindowHint(GLFW_STENCIL_BITS, 8);

		firstWindow = false;
	}

	const char *title = "Rendeer";
	if (fullscreen)
	{
		GLFWmonitor *primaryMonitor = glfwGetPrimaryMonitor();
		if (primaryMonitor != nullptr)
		{
			const GLFWvidmode *currentVideoMode = glfwGetVideoMode(primaryMonitor);
			if (currentVideoMode != nullptr)
			{
				const int width = currentVideoMode->width;
				const int height = currentVideoMode->height;

				this->glfwWindow = glfwCreateWindow(width, height, title, primaryMonitor, nullptr);
			}
			else
			{
				Logger::GetDefaultLogger().Log("Error: primary video mode could not be accessed for primary monitor.");
			}
		}
		else
		{
			Logger::GetDefaultLogger().Log("Error: primary monitor could not be accessed.");
		}
	}
	else
	{
		this->glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);;
	}

	MakeCurrent();

	// Store a pointer to the Window instance in the user pointer of the GLFW window handle
	glfwSetWindowUserPointer(glfwWindow, static_cast<void *>(this));

	SetVsyncEnabled(vSync);
	SetCursorHidden(false);

	keyboard.reset(new Keyboard(glfwWindow));
	mouse.reset(new Mouse(glfwWindow));
}

Window::~Window()
{
	glfwSetKeyCallback(glfwWindow, nullptr);
	glfwSetMouseButtonCallback(glfwWindow, nullptr);
	glfwSetCursorPosCallback(glfwWindow, nullptr);
	glfwDestroyWindow(glfwWindow);

	// Destroy GLFW context if there are no more windows
	//glfwTerminate();
}

/*static*/ const Window *Window::FromGlfwWindow(GLFWwindow *glfwWindow)
{
	void *windowUserPtr = glfwGetWindowUserPointer(glfwWindow);
	return static_cast<Window *>(windowUserPtr);
}

/*static*/ const Window *Window::CurrentWindow()
{
	return currentWindow;
}

void Window::PollEvents()
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
	glfwSwapBuffers(glfwWindow);
}

bool Window::IsCloseRequested() const
{
	return (glfwWindowShouldClose(glfwWindow) != 0);
}

void Window::MakeCurrent() const
{
	currentWindow = this;
	glfwMakeContextCurrent(glfwWindow);

	// Load GL functions after the first context is ready (and made current)
	static bool firstContextCreation = true;
	if (firstContextCreation)
	{
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		firstContextCreation = false;
	}
}

void Window::BindAsDrawFrameBuffer() const
{
	// Bind framebuffer 0, i.e. the window for this context. To be compatible with the FrameBuffer class, make sure to set
	// the last bound draw framebuffer to this one! This function is a friend function of the FrameBuffer class for this reason.
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	FrameBuffer::lastBoundDraw = 0;

	int width, height;
	GetFramebufferSize(&width, &height);
	GL::SetViewport(0, 0, width, height);

	// TODO: Should draw buffers reset to COLOR0 & DEPTH?
}

void Window::BindAsReadFrameBuffer() const
{
	// Bind framebuffer 0, i.e. the window for this context. To be compatible with the FrameBuffer class, make sure to set
	// the last bound read framebuffer to this one! This function is a friend function of the FrameBuffer class for this reason.
	glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
	FrameBuffer::lastBoundRead = 0;
}

bool Window::IsFullscreen() const
{
	return fullscreen;
}

void Window::GetFramebufferSize(int *width, int *height) const
{
	glfwGetFramebufferSize(glfwWindow, width, height);
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
	float ar = static_cast<float>(width) / static_cast<float>(height);
	return ar;
}

bool Window::IsVsyncEnabled() const
{
	return vsyncEnabled;
}

void Window::SetVsyncEnabled(bool enabled)
{
	int interval = (enabled) ? 1 : 0;
	glfwSwapInterval(interval);
	this->vsyncEnabled = enabled;
}

bool Window::IsCursorHidden() const
{
	int cursorMode = glfwGetInputMode(glfwWindow, GLFW_CURSOR);
	return (cursorMode == GLFW_CURSOR_DISABLED);
}

void Window::SetCursorHidden(bool hidden) const
{
	int mode = (hidden) ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL;
	glfwSetInputMode(glfwWindow, GLFW_CURSOR, mode);
}

const Keyboard& Window::GetKeyboard() const
{
	return *this->keyboard;
}

const Mouse& Window::GetMouse() const
{
	return *this->mouse;
}
