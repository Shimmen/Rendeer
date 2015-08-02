#pragma once

#include <vector>

#include "Shader.h"
#include "Entity.h"
#include "GBuffer.h"
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
	Texture defaultNormalMap;

private:
	
	void RenderGeometryPass(const std::vector<Entity *>& entities, PerspectiveCamera& camera);
	void RenderLightPass(const std::vector<ILight *>& lights, PerspectiveCamera& camera);

	
	GBuffer gBuffer;
	ScreenAlignedQuad quad;

	Window& window;

	// Debug stuff etc.
	void RenderTextureToScreen(const Texture& texture);
	Shader *renderTextureShader;

};

