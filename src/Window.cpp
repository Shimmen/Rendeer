#include "Window.h"

#include "Logger.h"
#include "GLState.h"
#include "FrameBuffer.h"
#include "ImGuiAdapter.h"

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
			Logger::Log("Error: could not initialize glfw! Application must terminate.");
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
				Logger::Log("Error: primary video mode could not be accessed for primary monitor.");
			}
		}
		else
		{
			Logger::Log("Error: primary monitor could not be accessed.");
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

	glfwSetKeyCallback(glfwWindow, Window::KeyEventCallback);
	glfwSetCharModsCallback(glfwWindow, Window::CharEventCallback);
	glfwSetMouseButtonCallback(glfwWindow, Window::MouseButtonEventCallback);
	glfwSetCursorPosCallback(glfwWindow, Window::MouseMovementEventCallback);
	glfwSetScrollCallback(glfwWindow, Window::MouseScrollEventCallback);
}

Window::~Window()
{
	glfwDestroyWindow(glfwWindow);

	// Destroy GLFW context if there are no more windows
	//glfwTerminate();
}

/*static*/ const Window *Window::CurrentWindow()
{
	return currentWindow;
}

void Window::PollEvents()
{
	// Reset keyboard pressed & released keys for this frame
	memset(wasKeyPressed, false, KEYBOARD_KEY_COUNT * sizeof(bool));
	memset(wasKeyReleased, false, KEYBOARD_KEY_COUNT * sizeof(bool));

	// Reset & update mouse
	memset(wasButtonPressed, false, MOUSE_BUTTON_COUNT * sizeof(bool));
	memset(wasButtonReleased, false, MOUSE_BUTTON_COUNT * sizeof(bool));
	lastXPosition = currentXPosition;
	lastYPosition = currentYPosition;
	lastScrollOffset = currentScollOffset;

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

void Window::GetWindowSize(int *width, int *height) const
{
	glfwGetWindowSize(glfwWindow, width, height);
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

void Window::Focus() const
{
	glfwFocusWindow(glfwWindow);
}

bool Window::IsFocused() const
{

	return glfwGetWindowAttrib(glfwWindow, GLFW_FOCUSED);
}

const char *Window::GetClipboardText() const
{
	return glfwGetClipboardString(glfwWindow);
}

void Window::SetClipboardText(const std::string& text) const
{
	SetClipboardText(text.c_str());
}

void Window::SetClipboardText(const char *text) const
{
	glfwSetClipboardString(glfwWindow, text);
}

bool Window::IsKeyDown(int key) const
{
	return isKeyDown[key];
}

bool Window::WasKeyPressed(int key) const
{
	return wasKeyPressed[key];
}

bool Window::WasKeyReleased(int key) const
{
	return wasKeyPressed[key];
}

/*static*/ void Window::KeyEventCallback(GLFWwindow *glfwWindow, int key, int scancode, int action, int mods)
{
	void *windowUserPtr = glfwGetWindowUserPointer(glfwWindow);
	auto window = static_cast<Window *>(windowUserPtr);

	switch (action)
	{
		case GLFW_PRESS:
			window->wasKeyPressed[key] = true;
			window->isKeyDown[key] = true;
			break;

		case GLFW_RELEASE:
			window->wasKeyReleased[key] = true;
			window->isKeyDown[key] = false;
			break;

		case GLFW_REPEAT:
		default:
			break;
	}

	// Make sure the GUI gets key info
	if (!window->IsCursorHidden())
	{
		ImGuiAdapter::KeyCallback(key, action);
	}
}

/*static*/ void Window::CharEventCallback(GLFWwindow *glfwWindow, unsigned int codepoint, int mods)
{
	void *windowUserPtr = glfwGetWindowUserPointer(glfwWindow);
	auto window = static_cast<Window *>(windowUserPtr);

	if (!window->IsCursorHidden())
	{
		ImGuiAdapter::CharCallback(codepoint);
	}
}

bool Window::IsButtonDown(int button) const
{
	return isButtonDown[button];
}

bool Window::WasButtonPressed(int button) const
{
	return wasButtonPressed[button];
}

bool Window::WasButtonReleased(int button) const
{
	return wasButtonReleased[button];
}

glm::vec2 Window::GetMousePosition() const
{
	double x, y;
	glfwGetCursorPos(glfwWindow, &x, &y);
	return glm::vec2(static_cast<float>(x), static_cast<float>(y));
}

glm::vec2 Window::GetMouseDelta() const
{
	return glm::vec2(currentXPosition - lastXPosition, currentYPosition - lastYPosition);
}

float Window::GetScrollDelta() const
{
	return static_cast<float>(currentScollOffset - lastScrollOffset);
}

/*static*/ void Window::MouseButtonEventCallback(GLFWwindow *glfwWindow, int button, int action, int mods)
{
	void *windowUserPtr = glfwGetWindowUserPointer(glfwWindow);
	auto window = static_cast<Window *>(windowUserPtr);

	switch (action)
	{
		case GLFW_PRESS:
			window->wasButtonPressed[button] = true;
			window->isButtonDown[button] = true;
			break;

		case GLFW_RELEASE:
			window->wasButtonReleased[button] = true;
			window->isButtonDown[button] = false;
			break;

		case GLFW_REPEAT:
		default:
			break;
	}
}

/*static*/ void Window::MouseMovementEventCallback(GLFWwindow *glfwWindow, double xPos, double yPos)
{
	void *windowUserPtr = glfwGetWindowUserPointer(glfwWindow);
	auto window = static_cast<Window *>(windowUserPtr);

	window->currentXPosition = xPos;
	window->currentYPosition = yPos;
}

/*static*/ void Window::MouseScrollEventCallback(GLFWwindow *glfwWindow, double xOffset, double yOffset)
{
	void *windowUserPtr = glfwGetWindowUserPointer(glfwWindow);
	auto window = static_cast<Window *>(windowUserPtr);

	// Ignore x-offset for now...
	window->currentScollOffset += yOffset;
}
