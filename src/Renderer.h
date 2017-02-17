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
	void GenerateBloom();

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
	Texture2D shadowMap;
	FrameBuffer shadowMapFramebuffer;
	Shader shadowMapGenerator{ "Shadowing/ShadowMapGenerator.vsh", "Shadowing/ShadowMapGenerator.fsh" };

	// Skybox
	Shader skyboxShader{"Generic/Skybox.vsh", "Generic/Skybox.fsh"};

	// Bloom
	static const int numBloomBlurs{ 2 };
	int numPassesPerBlur{ 4 };
	Texture2D bloomBlurs[2 * Renderer::numBloomBlurs];
	FrameBuffer bloomBlurFBs[2 * Renderer::numBloomBlurs];
	Texture2D bloomBrightPass;
	FrameBuffer bloomBrightPassFB{};
	glm::vec2 bloomWeights{0.17f, 0.37f};
	float bloomMasterWeight{0.5f};

	// Final post-process
	Shader postProcessShader{ "Generic/ScreenSpaceQuad.vsh", "Postprocess/Postprocess.fsh" };

	// Debug stuff etc.
public: void RenderTextureToScreen(const Texture2D& texture, bool alphaBlending = false, bool setViewport = true);
	Shader nofilterFilter{"Generic/ScreenSpaceQuad.vsh", "Filtering/Nofilter.fsh"};

};
