#pragma once

#include <vector>

#include "Scene.h"
#include "Shader.h"
#include "Entity.h"
#include "Camera.h"
#include "Window.h"
#include "Bitmap.h"
#include "GBuffer.h"
#include "Texture2D.h"
#include "TextureCube.h"
#include "PrimitiveDrawables.h"

class ILight;

class DeferredRenderer
{
public:
	
	DeferredRenderer(const Window *display);
	~DeferredRenderer();

	void BindForUsage() const;
	void Render(const std::vector<ILight *>& lights, const Scene& scene);

	// Default textures etc.
	Texture2D defaultNormalMap{"textures/default_normal.jpg", false};

private:

	void GeometryPass(const std::vector<std::shared_ptr<Entity>>& entities, const CameraComponent& camera) const;

private:

	// Reference to the Window in which this renderer renders into
	const Window *window;

	ScreenAlignedQuad quad;

	// Deferred pipeling default frame buffers and textures
	GBuffer gBuffer;
	FrameBuffer lightAccumulationBuffer;
	Texture2D lightAccumulationTexture;

	// Extra frame buffers and textures
	Texture2D auxTexture1;
	FrameBuffer auxFramebuffer1;
	Texture2D auxTextureLow1;
	FrameBuffer auxFramebufferLow1;
	Texture2D auxTextureLow2;
	FrameBuffer auxFramebufferLow2;

	// Shadow map related
	Texture2D shadowMap{ 2048, 2048, GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT16, GL_CLAMP_TO_BORDER, GL_NEAREST, GL_NEAREST };
	FrameBuffer shadowMapFramebuffer;
	Shader shadowMapGenerator{ "Shadowing/ShadowMapGenerator.vsh", "Shadowing/ShadowMapGenerator.fsh" };

	// Skybox related
	Shader skyboxShader{"Generic/Skybox.vsh", "Generic/Skybox.fsh"};
	SkyboxCube skyboxMesh;
	//TextureCube hdrSkyboxTexture{ Bitmap{ "textures/grove.env.hdr" } };
	TextureCube skyboxTexture{
		Bitmap{"textures/skybox_sunset/left.png"},
		Bitmap{"textures/skybox_sunset/right.png"},
		Bitmap{"textures/skybox_sunset/bottom.png"},
		Bitmap{"textures/skybox_sunset/top.png"},
		Bitmap{"textures/skybox_sunset/front.png"},
		Bitmap{"textures/skybox_sunset/back.png"}
	};

	// Filters and general shaders, etc.
	//Shader highPassFilter{"Generic/ScreenSpaceQuad.vsh", "Filtering/HighPassFilter.fsh"};
	//Shader gaussianBlurVertical{"Filtering/GaussianBlurV.vsh", "Filtering/GaussianBlur.fsh"};
	//Shader gaussianBlurHorizontal{"Filtering/GaussianBlurH.vsh", "Filtering/GaussianBlur.fsh"};
	Shader postProcessShader{ "Generic/ScreenSpaceQuad.vsh", "Postprocess/Postprocess.fsh" };

	// Debug stuff etc.
	void RenderTextureToScreen(const Texture2D& texture);
	Shader nofilterFilter{"Generic/ScreenSpaceQuad.vsh", "Filtering/Nofilter.fsh"};

};
