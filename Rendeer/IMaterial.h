#pragma once

#include "Shader.h"

class Transform;
class DeferredRenderer;
class Camera;

class IMaterial
{
public:

	IMaterial(Shader *shader)
		: shader(shader)
	{
	}

	virtual ~IMaterial()
	{
		delete shader;
	}

	virtual void UpdateUniforms(const DeferredRenderer& renderer,
	                            const Transform& transform,
	                            const Camera& camera) = 0;

protected:

	Shader *shader;

};
