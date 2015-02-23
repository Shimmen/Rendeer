#pragma once

#include <vector>

#include "Shader.h"
#include "GBuffer.h"
#include "ScreenAlignedQuad.h"

class Display;

class DeferredRenderer
{
public:
	DeferredRenderer(Display& display);

	void Bind() const;
	void BindForObjectPass() const;
	void RenderLightPass();

private:
	GBuffer gBuffer;

	Shader screenSpaceShader;
	ScreenAlignedQuad quad;

	Display& display;
};

