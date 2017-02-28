#include "Light.h"

Light::Light()
	: color(glm::vec3{ 1, 1, 1 })
	, intensity(1.0f)
	, type(Type::POINT)
{
}

Light::Light(const glm::vec3& color, float intensity, Light::Type type)
	: color(color)
	, intensity(intensity)
	, type(type)
{
}

/*static*/ std::shared_ptr<Light> Light::Directional(const glm::vec3& color, float intensity)
{
	auto directionalLight = std::make_shared<Light>(color, intensity, Type::DIRECTIONAL);
	return directionalLight;
}

/*static*/ std::shared_ptr<Light> Light::Point(const glm::vec3& color, float intensity)
{
	auto pointLight = std::make_shared<Light>(color, intensity, Type::POINT);
	return pointLight;
}

/*static*/ std::shared_ptr<Light> Light::Spot(const glm::vec3& color, float intensity, float angleOuter, float angleInner)
{
	auto spotLight = std::make_shared<Light>(color, intensity, Type::SPOT);
	spotLight->coneOuterAngle = angleOuter;
	spotLight->coneInnerAngle = angleInner;
	return spotLight;
}
