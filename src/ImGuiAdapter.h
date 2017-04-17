#pragma once

#include <imgui.h>

#include "Shader.h"
#include "Buffer.h"
#include "Texture2D.h"
#include "VertexArray.h"

class Window;

namespace ImGuiAdapter
{

	void Init(const Window *const window);

	void NewFrame(float deltaTime);
	void RenderDrawLists(ImDrawData *data);

	// Call these functions from the actual key/char callbacks to be able to handle keyboard input
	void KeyCallback(int key, int action);
	void CharCallback(unsigned int codepoint);

};
