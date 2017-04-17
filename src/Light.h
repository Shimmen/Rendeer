#pragma once

#include <memory>

#include <glm/fwd.hpp>

#include "Component.h"

class Light: public Component
{
public:

	enum class Type
	{
		DIRECTIONAL,
		POINT,
		SPOT
	};

public:

	Light(); // deafult to a white point light
	Light(const glm::vec3& color, float intensity, Type type);
	~Light() {};

	static std::shared_ptr<Light> Directional(const glm::vec3& color, float intensity);
	static std::shared_ptr<Light> Point(const glm::vec3& color, float intensity);
	static std::shared_ptr<Light> Spot(const glm::vec3& color, float intensity, float angleOuter, float angleInner);

	inline Light::Type GetType() const { return type; }

	glm::vec3 color;
	float intensity;

	// For spot light
	float coneOuterAngle{ 0 };
	float coneInnerAngle{ 0 };

protected:

	// Required for Component compability
	virtual void Init() {};

	Type type;

};

/*
 
 TODO (next steps):
 
  - Redo light system
  - Redo material system. (maybe not, maybe do it later? But at least move out shader from the class. So essentially yes...)
  - Static environment mapping
	  1. skybox reflections
      2. single environment probe (renderered at startup)
      3. multiple environment probes, blend at probe intersections, i.e. (   A      (blend)      B   )
  - ?

*/
