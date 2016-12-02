#pragma once

#include "Shader.h"

#include <memory>

class Transform;
class DeferredRenderer;
class CameraComponent;

class IMaterial
{
public:

	IMaterial(Shader *shader)
		: shader{ shader }
	{
	}

	virtual ~IMaterial()
	{
	}

	virtual void UpdateUniforms(const DeferredRenderer& renderer,
	                            const Transform& transform,
	                            const CameraComponent& camera) const = 0;

protected:

	const std::shared_ptr<Shader> shader;

};
