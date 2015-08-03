#pragma once

#include <vector>

#include "Shader.h"
#include "Entity.h"
#include "GBuffer.h"
#include "PerspectiveCamera.h"
#include "ScreenAlignedQuad.h"

class Window;
class ILight;

class DeferredRenderer
{
public:
	
	DeferredRenderer(Window& display);
	~DeferredRenderer();

	void BindForUsage() const;
	void Render(const std::vector<Entity *>& entities, const std::vector<ILight *>& lights, PerspectiveCamera& camera);

	// Default textures etc.
	Texture defaultNormalMap{"textures/default_normal.jpg", false};

private:

	GBuffer gBuffer;
	ScreenAlignedQuad quad;
	
	Shader shadowMapGenerator{"Lighting/ShadowMapGenerator.vsh", "Lighting/ShadowMapGenerator.fsh"};
	Texture shadowMap{1024, 1024, GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT16, GL_CLAMP_TO_BORDER, GL_NEAREST, GL_NEAREST};
	FrameBuffer shadowMapFramebuffer{};

	const Window& window;

	// Debug stuff etc.
	void RenderTextureToScreen(const Texture& texture);
	Shader renderTextureShader{"postprocess.vsh", "render_texture.fsh"};

};

