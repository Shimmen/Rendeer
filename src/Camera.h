#pragma once

#include <glm/fwd.hpp>

#include "Component.h"

class Window;
class FrameBuffer;

class CameraComponent: public Component
{
public:

	enum class CameraType
	{
		PERSPECTIVE,
		ORTHOGRAPHIC
	};

public:

	CameraComponent(float aspectRatio, float nearPlane, float farPlane, float fovOrSize, CameraType type = CameraType::PERSPECTIVE);

	virtual void Init() {};

	std::shared_ptr<FrameBuffer> GetTarget() const;
	void SetTarget(std::shared_ptr<FrameBuffer> target);
	void SetAsMainCamera();

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;
	glm::mat4 GetViewProjection() const;

	float GetNear() const { return nearClippingPlane; };

private:

	std::shared_ptr<FrameBuffer> target;
	float aspectRatio;
	
	float nearClippingPlane;
	float farClippingPlane;
	
	CameraType type;
	float fovOrSize;

	// Cache
	mutable bool invalidateProjection = true;
	mutable glm::mat4 projectionCache{};

};

//
// An entity containing a CameraComponent that encapsulates all camera behaviour (like movement and view/projection)
//
class CameraEntity: public Entity
{
public:

	CameraEntity();
	CameraEntity(glm::vec3 position, glm::quat orientation);
	CameraEntity(glm::vec3 position, glm::quat orientation,
		float aspectRatio, float nearPlane, float farPlane, float fovOrSize, CameraComponent::CameraType type = CameraComponent::CameraType::PERSPECTIVE);

	void Update(float deltaTime, const Window& window);

	// Delegates to the CameraComponent
	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;
	glm::mat4 GetViewProjection() const;

};
