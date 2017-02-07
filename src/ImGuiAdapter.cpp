#include "ImGuiAdapter.h"

#include <GLFW/glfw3.h>

#include "Window.h"
#include "GLState.h"

//
// Static data
//

static const Window *window;

static Shader *guiShader;
static Texture2D *fontTexture;

static VertexArray *guiGeometry;
static Buffer *vertices;
static Buffer *indices;

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

	guiShader = new Shader{"ImGui/Gui.vsh", "ImGui/Gui.fsh"};

	vertices = new Buffer();
	indices = new Buffer();

#define OFFSET_OF(type, element) ((size_t)&(((type *)0)->element))
	guiGeometry = new VertexArray();
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
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height); // TODO: Optimize storage!
	fontTexture = new Texture2D(width, height, 4, pixels);
	io.Fonts->TexID = (void *)(intptr_t)fontTexture->GetTextureHandle();

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

void ImGuiAdapter::Deinit()
{
	delete guiShader;
	delete fontTexture;
	delete guiGeometry;
	delete vertices;
	delete indices;
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

	//
	// TODO: Handle inputs!
	//
	auto& mouse = window->GetMouse();

	if (window->IsFocused() && !window->IsCursorHidden())
	{
		glm::vec2 mousePos = mouse.GetMousePosition();
		io.MousePos = ImVec2(mousePos.x, mousePos.y);
	}
	else
	{
		io.MousePos = ImVec2(-1, -1);
	}

	for (int i = 0; i < 3; i++)
	{
		io.MouseDown[i] = mouse.WasButtonPressed(GLFW_MOUSE_BUTTON_1 + i) || mouse.IsButtonDown(GLFW_MOUSE_BUTTON_1 + i);
	}

	io.MouseWheel = 0.0f; // TODO: Implement!

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
	guiShader->SetUniform("u_texture", fontTexture->Bind(0));
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
				// TODO: Handle different textures for different calls, etc. Currently every call has only access to the default font texture.
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
