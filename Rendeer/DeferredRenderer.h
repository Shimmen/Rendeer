#pragma once

#include <vector>

#include "Shader.h"
#include "Entity.h"
#include "GBuffer.h"
#include "ScreenAlignedQuad.h"

class Display;
class DirectionalLight;

class DeferredRenderer
{
public:
	DeferredRenderer(Display& display);

	void BindForUsage() const;
	void Render(const std::vector<Entity *>& entities, const std::vector<DirectionalLight *>& lights, const PerspectiveCamera& camera);

private:
	
	void RenderGeometryPass(const std::vector<Entity *>& entities, const PerspectiveCamera& camera);
	void RenderLightPass(const std::vector<DirectionalLight *>& lights, const PerspectiveCamera& camera);


	GBuffer gBuffer;
	ScreenAlignedQuad quad;

	Display& display;
};

