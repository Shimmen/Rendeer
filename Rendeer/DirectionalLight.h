#pragma once

#include <glm/fwd.hpp>

#include "Transform.h"

class DirectionalLight
{
public:
	DirectionalLight(const Transform& transform, glm::vec3 color, float intensity)
		: transform(transform)
		, color(color)
		, intensity(intensity) {}
	virtual ~DirectionalLight();

// Let's keep it public for now
//private:
	Transform transform;
	
	glm::vec3 color;
	float intensity;
};

