#pragma once

#include <vector>

#include "Shader.h"
#include "Texture.h"
#include "FrameBuffer.h"
#include "ScreenAlignedQuad.h"

class PerspectiveCamera;
class FrameBuffer;
class Display;
class Entity;
class Shader;
class Mesh;

class DeferredRenderer
{
public:
	DeferredRenderer(Display& display);

	void Bind() const;

	void Render(const PerspectiveCamera& camera, const std::vector<Entity *> entities);

private:
	FrameBuffer gBuffer;
	Texture gBufferAlbedo;
	Texture gBufferNormal;
	Texture gBufferDepth;

	Shader plainShader;
	Shader screenSpaceShader;
	ScreenAlignedQuad quad;

	Display& display;
};

