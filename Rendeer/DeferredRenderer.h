#pragma once

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

	void Render(const PerspectiveCamera& camera, Entity *entities, int entityCount);

private:
	FrameBuffer gBuffer;
	Texture gBufferAlbedo;
	Texture gBufferDepth;

	Shader plainShader;
	Shader screenSpaceShader;
	ScreenAlignedQuad quad;

	Display& display;
};

