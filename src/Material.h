#pragma once

#include "Shader.h"

#include <memory>

class Renderer;
class Transform;
class CameraComponent;

class Material
{
public:

	Material(std::shared_ptr<Shader> shader) : shader{shader} {}
	virtual ~Material() {}

	virtual void UpdateUniforms(const Renderer& renderer, const Transform& transform, const CameraComponent& camera) const = 0;

protected:

	const std::shared_ptr<Shader> shader;

};
