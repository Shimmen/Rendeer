#pragma once

#include "Shader.h"

#include <memory>

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
	}

	virtual void UpdateUniforms(const DeferredRenderer& renderer,
	                            const Transform& transform,
	                            const Camera& camera) = 0;

protected:

	const std::shared_ptr<Shader> shader;

};
