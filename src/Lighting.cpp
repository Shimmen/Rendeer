#include "Lighting.h"

#include "Uniform.h"

LightComponent::LightComponent(Shader *shader, glm::vec3 color, float intensity)
	: Component{}
	, shader{ shader }
	, color{ color }
	, intensity{ intensity }
{
	this->colorUniform = shader->GetUniformWithName("u_light_color");
	this->intensityUniform = shader->GetUniformWithName("u_light_intensity");
}

void LightComponent::SetUniforms(const Renderer& renderer, const CameraComponent& camera) const
{
	shader->Bind();

	colorUniform->Set(this->color);
	intensityUniform->Set(this->intensity);
}

DirectionalLight::DirectionalLight(glm::vec3 color, float intensity, bool usingDynamicCameraPositioning)
	: LightComponent{ new Shader{ "Generic/ScreenSpaceQuad.vsh", "Lighting/DirectionalLight.fsh" }
	, color, intensity }
	, usingDynamicCameraPositioning{ usingDynamicCameraPositioning }
{
	castsShadows = true;

	this->directionUniform = shader->GetUniformWithName("u_light_direction");
	this->inverseProjectionUniform = shader->GetUniformWithName("u_inverse_projection_matrix");
}

void DirectionalLight::SetUniforms(const Renderer& renderer, const CameraComponent& camera) const
{
	LightComponent::SetUniforms(renderer, camera);

	auto lightForward = GetOwnerEntity().GetTransform().GetForward();

	glm::quat conjugateCameraOrientation = glm::conjugate(camera.GetOwnerEntity().GetTransform().GetOrientationInWorld());
	auto viewSpaceLightForward = glm::rotate(conjugateCameraOrientation, lightForward);
	directionUniform->Set(viewSpaceLightForward);

	inverseProjectionUniform->Set(glm::inverse((camera.GetProjectionMatrix())));
}

CameraEntity DirectionalLight::GetLightCamera(const CameraComponent& mainCamera, int shadowMapSize) const
{
	const float cameraNear = 0.0f;
	const float cameraFar = 100.0f;
	const float cameraScale = 10.0f;

	glm::quat worldLightOrientation = GetOwnerEntity().GetTransform().GetOrientationInWorld();
	glm::vec3 worldLightPosition = GetOwnerEntity().GetTransform().GetPositionInWorld();

	if (usingDynamicCameraPositioning)
	{
		// Place the directional light camera at the main camera position and offset it by the looking direction
		// and the light camera near plane, so that the near plane essantially lies at the main camera.
		auto mainCameraTransform = mainCamera.GetOwnerEntity().GetTransform();
		worldLightPosition = mainCameraTransform.GetPositionInWorld() + mainCameraTransform.GetForwardInWorld() * -cameraNear;

		// Rotate position into light space
		glm::vec4 lightSpaceLightPosition = glm::rotate(glm::conjugate(worldLightOrientation), glm::vec4(worldLightPosition, 1.0f));

		// Quantize position to a light space shadow map texel size
		float lightSpaceTexelSize = (cameraScale * 2.0f) / float(shadowMapSize);
		lightSpaceLightPosition.x = lightSpaceTexelSize * floorf(lightSpaceLightPosition.x / lightSpaceTexelSize);
		lightSpaceLightPosition.y = lightSpaceTexelSize * floorf(lightSpaceLightPosition.y / lightSpaceTexelSize);

		// Rotate back into world space
		worldLightPosition = glm::vec3(glm::rotate(worldLightOrientation, lightSpaceLightPosition));
	}

	return CameraEntity(worldLightPosition, worldLightOrientation,
	              1.0f, cameraNear, cameraFar, cameraScale, CameraComponent::CameraType::ORTHOGRAPHIC);
}

PointLight::PointLight(glm::vec3 color, float intensity)
: LightComponent{ new Shader{ "Generic/ScreenSpaceQuad.vsh", "Lighting/PointLight.fsh" }, color, intensity }
{
	castsShadows = false;

	this->positionUniform = shader->GetUniformWithName("u_light_position");
	this->inverseProjectionUniform = shader->GetUniformWithName("u_inverse_projection_matrix");
}

void PointLight::SetUniforms(const Renderer& renderer, const CameraComponent& camera) const
{
	LightComponent::SetUniforms(renderer, camera);

	auto viewSpaceLightPosition = glm::vec3(camera.GetViewMatrix() * glm::vec4(GetOwnerEntity().GetTransform().GetPosition(), 1.0f));
	positionUniform->Set(viewSpaceLightPosition);

	inverseProjectionUniform->Set(glm::inverse((camera.GetProjectionMatrix())));
}

CameraEntity PointLight::GetLightCamera(const CameraComponent& mainCamera, int shadowMapSize) const
{
	// TODO: This doesn't make sense since it's omnidirectional
	return CameraEntity(GetOwnerEntity().GetTransform().GetPositionInWorld(),
	              GetOwnerEntity().GetTransform().GetOrientationInWorld(),
	              1.0f, 1.0f, 100.0f, glm::radians(90.0f), CameraComponent::CameraType::PERSPECTIVE);
}

SpotLight::SpotLight(glm::vec3 color, float intensity, float outerConeAngle, float innerConeAngle)
	: LightComponent{ new Shader{ "Generic/ScreenSpaceQuad.vsh", "Lighting/SpotLight.fsh" }	, color, intensity }
	, outerConeAngle{ outerConeAngle }
	, innerConeAngle{ innerConeAngle }
{
	assert(outerConeAngle >= innerConeAngle);
	assert(outerConeAngle >= 0);
	assert(innerConeAngle >= 0);

	castsShadows = true;

	this->positionUniform = shader->GetUniformWithName("u_light_position");
	this->directionUniform = shader->GetUniformWithName("u_light_direction");
	this->outerConeAngleUniform = shader->GetUniformWithName("u_light_outer_cone_angle_cos");
	this->innerConeAngleUniform = shader->GetUniformWithName("u_light_inner_cone_angle_cos");
	this->inverseProjectionUniform = shader->GetUniformWithName("u_inverse_projection_matrix");
}

void SpotLight::SetUniforms(const Renderer& renderer, const CameraComponent& camera) const
{
	LightComponent::SetUniforms(renderer, camera);

	auto viewSpaceLightPosition = glm::vec3(camera.GetViewMatrix() * glm::vec4(GetOwnerEntity().GetTransform().GetPosition(), 1.0f));

	auto lightForward = GetOwnerEntity().GetTransform().GetForward();

	glm::quat conjugateCameraOrientation = glm::conjugate(camera.GetOwnerEntity().GetTransform().GetOrientationInWorld());
	auto viewSpaceLightForward = glm::rotate(conjugateCameraOrientation, lightForward);

	positionUniform->Set(viewSpaceLightPosition);
	directionUniform->Set(viewSpaceLightForward);
	outerConeAngleUniform->Set(cosf(this->outerConeAngle / 2.0f));
	innerConeAngleUniform->Set(cosf(this->innerConeAngle / 2.0f));

	inverseProjectionUniform->Set(glm::inverse((camera.GetProjectionMatrix())));
}

CameraEntity SpotLight::GetLightCamera(const CameraComponent& mainCamera, int shadowMapSize) const
{
	return CameraEntity(GetOwnerEntity().GetTransform().GetPositionInWorld(),
	              GetOwnerEntity().GetTransform().GetOrientationInWorld(),
	              1.0f, 1.0f, 100.0f, outerConeAngle, CameraComponent::CameraType::PERSPECTIVE);
}
