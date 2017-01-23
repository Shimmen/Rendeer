#pragma once

#include "Shader.h"

#include <memory>

class Transform;
class DeferredRenderer;
class CameraComponent;

class Material
{
public:

	Material(std::shared_ptr<Shader> shader) : shader{shader} {}
	virtual ~Material() {}

	virtual void UpdateUniforms(const DeferredRenderer& renderer, const Transform& transform, const CameraComponent& camera) const = 0;

protected:

	const std::shared_ptr<Shader> shader;

};
