#pragma once

#include <vector>

#include "Scene.h"
#include "Shader.h"
#include "Entity.h"
#include "Camera.h"
#include "Window.h"
#include "Bitmap.h"
#include "GBuffer.h"
#include "Drawables.h"
#include "Texture2D.h"
#include "TextureCube.h"

class LightComponent;

class Renderer
{
public:
	
	Renderer(const Window *const window);
	virtual ~Renderer() {}

	void Render(const Scene& scene);

	// Default textures etc.
	Texture2D defaultNormalMap{"textures/default_normal.jpg", false};
	Texture2D defaultDiffuse{"textures/default.png", true};

private:

	void GeometryPass(const std::vector<std::shared_ptr<Entity>>& entities, const CameraComponent& camera) const;
	void LightPass(const Scene& scene, const std::vector<std::shared_ptr<Entity>>& geometry, const std::vector<std::shared_ptr<Entity>>& lights, const CameraComponent& camera) const;
	void DrawSkybox(const CameraComponent& camera, const TextureCube& skyboxTexture) const;
	void GenerateBloom() const;

	void RenderCameras(std::vector<std::shared_ptr<Entity>> cameras) const;

private:

	const Window *const window;

	// Deferred pipeling default frame buffers and textures
	GBuffer gBuffer;
	Texture2D lightAccumulationTexture;
	FrameBuffer lightAccumulationBuffer{};

	// Ambient light
	Shader ambientShader{ "Generic/ScreenSpaceQuad.vsh", "Lighting/AmbientLight.fsh" };

	// Shadow mapping
	Texture2D shadowMap{ 2048, 2048, GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT16, GL_CLAMP_TO_BORDER, GL_NEAREST, GL_NEAREST };
	FrameBuffer shadowMapFramebuffer;
	Shader shadowMapGenerator{ "Shadowing/ShadowMapGenerator.vsh", "Shadowing/ShadowMapGenerator.fsh" };

	// Skybox
	Shader skyboxShader{"Generic/Skybox.vsh", "Generic/Skybox.fsh"};

	// Postprocess
	Texture2D bloomTexture;
	FrameBuffer bloomFB{};
	Texture2D bloomBlur256, bloomBlur128, bloomBlur64, bloomBlur32;
	FrameBuffer bloomBlur256FB{}, bloomBlur128FB{}, bloomBlur64FB{}, bloomBlur32FB{};

	Shader postProcessShader{ "Generic/ScreenSpaceQuad.vsh", "Postprocess/Postprocess.fsh" };

	// Debug stuff etc.
	void RenderTextureToScreen(const Texture2D& texture);
	Shader nofilterFilter{"Generic/ScreenSpaceQuad.vsh", "Filtering/Nofilter.fsh"};

};
