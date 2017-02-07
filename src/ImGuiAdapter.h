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
	void Deinit();

	void NewFrame(float deltaTime);
	void RenderDrawLists(ImDrawData *data);

};
