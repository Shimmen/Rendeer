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

	// Shorthand for using in all the passes below
	typedef std::vector<std::shared_ptr<Entity>> EntityList;

	void GeometryPass(const EntityList& entities, const CameraComponent& camera);
	void ShadowMapGenerationPass(const EntityList& geometry, const EntityList& lights);
	void LightPass(const Scene& scene, const EntityList& geometry, const EntityList& lights, const CameraComponent& camera);
	void LightPassNew(const Scene& scene, const EntityList& geometry, const EntityList& lights, const CameraComponent& camera);
	void DrawSkybox(const CameraComponent& camera, const TextureCube& skyboxTexture);
	void GenerateBloom();
	void PostProcessPass();

	void RenderCameras(EntityList cameras);

private:

	const Window *const window;

	// Deferred pipeling default frame buffers and textures
	GBuffer gBuffer;
	Texture2D lightAccumulationTexture;
	Texture2D lightAccumulationDepth;
	FrameBuffer lightAccumulationBuffer{};

	// Light relating
	Shader ambientShader{ "Generic/ScreenSpaceQuad.vsh", "Lighting/AmbientLight.fsh" };
	Shader pointLightVolumeShader{ "Lighting/PointLight.vsh", "Lighting/PointLight.fsh" };
	Shader pointLightNearShader{ "Generic/ScreenSpaceQuad.vsh", "Lighting/PointLight.fsh"};
	Shader spotLightShader{ "Generic/ScreenSpaceQuad.vsh", "Lighting/SpotLight.fsh" };
	Shader directionalLightShader{ "Generic/ScreenSpaceQuad.vsh", "Lighting/DirectionalLight.fsh" };

	// Shadow mapping
	Texture2D shadowMap;
	FrameBuffer shadowMapFramebuffer;
	Shader shadowMapGenerator{ "Shadowing/ShadowMapGenerator.vsh", "Shadowing/ShadowMapGenerator.fsh" };

	static constexpr int numShadowMaps = 4;
	Texture2D shadowMaps[numShadowMaps];
	FrameBuffer shadowMapFBs[numShadowMaps];

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

	// UI Helpers
	void DrawUIImage(const Texture2D& image) const;

	// Debug stuff etc.
	void RenderTextureToScreen(const Texture2D& texture, bool alphaBlending = false, bool setViewport = true);
	Shader nofilterFilter{"Generic/ScreenSpaceQuad.vsh", "Filtering/Nofilter.fsh"};
	Shader wireframeShader{"Generic/Wireframe.vsh", "Generic/Wireframe.fsh"};

};
