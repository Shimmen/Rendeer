#pragma once

#include "Shader.h"

class Transform;
class DeferredRenderer;
class PerspectiveCamera;

class IMaterial
{
public:
	IMaterial(const Shader& shader)
		: shader(shader) {}

	virtual ~IMaterial() {}

	virtual void UpdateUniforms(const DeferredRenderer& renderer,
		const Transform& transform, const PerspectiveCamera& camera) = 0;

// Visible for main function access
//protected:
	Shader shader;
};

