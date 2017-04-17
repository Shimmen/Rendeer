#include "ImGuiAdapter.h"

#include <GLFW/glfw3.h>

#include "Window.h"
#include "GLState.h"

//
// Static data
//

#define SCROLL_SENSITIVITY (0.2f)

static const Window *window;

static std::shared_ptr<Shader> guiShader;
static std::shared_ptr<Texture2D> fontTexture;

static std::shared_ptr<VertexArray> guiGeometry;
static std::shared_ptr<Buffer> vertices;
static std::shared_ptr<Buffer> indices;

//
// Functions
//

static
const char *GetClipboardText()
{
	return window->GetClipboardText();
}

static
void SetClipboardText(const char *text)
{
	window->SetClipboardText(text);
}

void ImGuiAdapter::Init(const Window *wind)
{
	window = wind;

	guiShader = std::make_shared<Shader>("ImGui/Gui.vsh", "ImGui/Gui.fsh");

	vertices = std::make_shared<Buffer>();
	indices = std::make_shared<Buffer>();

#define OFFSET_OF(type, element) ((size_t)&(((type *)0)->element))
	guiGeometry = std::make_shared<VertexArray>();
	guiGeometry->Bind();

	vertices->Bind(GL_ARRAY_BUFFER);
	indices->Bind(GL_ELEMENT_ARRAY_BUFFER);

	guiGeometry->AddVertexAttribute(0, 2, GL_FLOAT, sizeof(ImDrawVert), (GLvoid *)OFFSET_OF(ImDrawVert, pos));
	guiGeometry->AddVertexAttribute(1, 2, GL_FLOAT, sizeof(ImDrawVert), (GLvoid *)OFFSET_OF(ImDrawVert, uv));
	guiGeometry->AddVertexAttribute(2, 4, GL_UNSIGNED_BYTE, sizeof(ImDrawVert), (GLvoid *)OFFSET_OF(ImDrawVert, col), GL_TRUE);
	guiGeometry->Unbind();
#undef OFFSET_OF

	auto& io = ImGui::GetIO();
	unsigned char *pixels;
	int width, height;
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
	fontTexture = std::make_shared<Texture2D>(width, height, 4, pixels);
	io.Fonts->TexID = (void *)(fontTexture.get()); // works fine, since it's only ever used here

	// Keyboard mapping. ImGui will use those indices to peek into the io.KeyDown[] array.
	io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
	io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
	io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
	io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
	io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
	io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
	io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
	io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
	io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
	io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
	io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
	io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
	io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
	io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
	io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
	io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
	io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
	io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
	io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

	io.RenderDrawListsFn = ImGuiAdapter::RenderDrawLists;

	io.SetClipboardTextFn = SetClipboardText;
	io.GetClipboardTextFn = GetClipboardText;
}

void ImGuiAdapter::NewFrame(float deltaTime)
{
	auto& io = ImGui::GetIO();

	int w, h;
	window->GetWindowSize(&w, &h);
	io.DisplaySize = ImVec2((float)w, (float)h);

	int fbw, fbh;
	window->GetFramebufferSize(&fbw, &fbh);
	io.DisplayFramebufferScale = ImVec2(w > 0 ? ((float)fbw / w) : 0, h > 0 ? ((float)fbh / h) : 0);

	io.DeltaTime = deltaTime;

	if (window->IsFocused() && !window->IsCursorHidden())
	{
		glm::vec2 mousePos = window->GetMousePosition();
		io.MousePos = ImVec2(mousePos.x, mousePos.y);
	}
	else
	{
		io.MousePos = ImVec2(-1, -1);
	}

	for (int i = 0; i < 3; i++)
	{
		io.MouseDown[i] = window->WasButtonPressed(GLFW_MOUSE_BUTTON_1 + i) || window->IsButtonDown(GLFW_MOUSE_BUTTON_1 + i);
	}

	io.MouseWheel += window->GetScrollDelta() * SCROLL_SENSITIVITY;

	// NOTE: Keyboard input is handled through a callback

	ImGui::NewFrame();
}

void ImGuiAdapter::RenderDrawLists(ImDrawData *drawData)
{
	// Avoid rendering when minimized, scale coordinates for retina displays (screen coordinates != framebuffer coordinates)
	ImGuiIO& io = ImGui::GetIO();
	int fb_width = (int)(io.DisplaySize.x * io.DisplayFramebufferScale.x);
	int fb_height = (int)(io.DisplaySize.y * io.DisplayFramebufferScale.y);
	if (fb_width == 0 || fb_height == 0) return;
	drawData->ScaleClipRects(io.DisplayFramebufferScale);

	GL::SetBlending(true);
	GL::SetBlendEquation(GL_FUNC_ADD, GL_FUNC_ADD);
	GL::SetBlendFunction(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	GL::SetFaceCulling(false);
	GL::SetDepthTest(false);
	GL::Enable(GL_SCISSOR_TEST);

	glViewport(0, 0, (GLsizei)fb_width, (GLsizei)fb_height);
	glm::mat4 projection = glm::mat4{
		2.0f/io.DisplaySize.x, 0.0f,                   0.0f, 0.0f,
		0.0f,                  2.0f/-io.DisplaySize.y, 0.0f, 0.0f,
		0.0f,                  0.0f,                  -1.0f, 0.0f,
		-1.0f,                 1.0f,                   0.0f, 1.0f
	};

	guiShader->Bind();

	// Projection stays the same during a frame
	guiShader->SetUniform("u_projection", projection);

	guiGeometry->Bind();
	for (int n = 0; n < drawData->CmdListsCount; n++)
	{
		const ImDrawList* cmd_list = drawData->CmdLists[n];
		const ImDrawIdx* idx_buffer_offset = 0;

		vertices->Bind(GL_ARRAY_BUFFER);
		vertices->SetData((const GLvoid *)cmd_list->VtxBuffer.Data, (GLsizeiptr)cmd_list->VtxBuffer.Size * sizeof(ImDrawVert), GL_STREAM_DRAW);

		indices->Bind(GL_ELEMENT_ARRAY_BUFFER);
		indices->SetData((const GLvoid *)cmd_list->IdxBuffer.Data, (GLsizeiptr)cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx), GL_STREAM_DRAW);

		for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++)
		{
			const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
			if (pcmd->UserCallback)
			{
				pcmd->UserCallback(cmd_list, pcmd);
			}
			else
			{
				Texture2D *texture = (Texture2D *)pcmd->TextureId;
				guiShader->SetUniform("u_texture", texture->Bind(0));

				// If not the font texture, assume it's a "standard" GL texture and flip the y-axis
				guiShader->SetUniform("u_flip_texture", texture != fontTexture.get());

				guiShader->SetUniform("u_grayscale", texture->GetNumComponents() == 1);

				glScissor((int)pcmd->ClipRect.x, (int)(fb_height - pcmd->ClipRect.w), (int)(pcmd->ClipRect.z - pcmd->ClipRect.x), (int)(pcmd->ClipRect.w - pcmd->ClipRect.y));
				guiGeometry->RenderWithElementArrayBuffer(GL_TRIANGLES, (GLsizei)pcmd->ElemCount, sizeof(ImDrawIdx) == 2 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT, idx_buffer_offset);
			}
			idx_buffer_offset += pcmd->ElemCount;
		}
	}
	guiGeometry->Unbind();

	// The rest should be okay
	GL::Disable(GL_SCISSOR_TEST);
}

void ImGuiAdapter::KeyCallback(int key, int action)
{
	auto& io = ImGui::GetIO();
	if (action == GLFW_PRESS) io.KeysDown[key] = true;
	if (action == GLFW_RELEASE) io.KeysDown[key] = false;

	// NOTE: Modifiers are not reliable across systems, so set them manually
	io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
	io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
	io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
	io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
}

void ImGuiAdapter::CharCallback(unsigned int codepoint)
{
	if (codepoint > 0 && codepoint < 0x10000)
	{
		ImGui::GetIO().AddInputCharacter((unsigned short)codepoint);
	}
}
