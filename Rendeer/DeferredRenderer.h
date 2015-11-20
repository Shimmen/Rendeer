#pragma once

#include <vector>

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
	
	DeferredRenderer(const Window& display);
	~DeferredRenderer();

	void BindForUsage() const;
	void Render(const std::vector<Entity *>& entities, const std::vector<ILight *>& lights, Camera& camera);

	// Default textures etc.
	Texture2D defaultNormalMap{"textures/default_normal.jpg", false};

private:

	ScreenAlignedQuad quad;

	GBuffer gBuffer;
	
	FrameBuffer lightAccumulationBuffer;
	Texture2D lightAccumulationTexture;

	Shader shadowMapGenerator{ "Lighting/ShadowMapGenerator.vsh", "Lighting/ShadowMapGenerator.fsh" };
	Texture2D shadowMap{ 2048, 2048, GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT16, GL_CLAMP_TO_BORDER, GL_NEAREST, GL_NEAREST };
	FrameBuffer shadowMapFramebuffer;

	Shader postProcessShader{ "postprocess.vsh", "Postprocess/Postprocess.fsh" };

	Shader skyboxShader{"skybox.vsh", "skybox.fsh"};
	SkyboxCube skyboxMesh;
	TextureCube skyboxTexture{
		Bitmap{"textures/skybox_sunset_flip/left.png"},
		Bitmap{"textures/skybox_sunset_flip/right.png"},
		Bitmap{"textures/skybox_sunset_flip/bottom.png"},
		Bitmap{"textures/skybox_sunset_flip/top.png"},
		Bitmap{"textures/skybox_sunset_flip/front.png"},
		Bitmap{"textures/skybox_sunset_flip/back.png"}
	};

	// TODO: Should this really be a const-ref? Or should it be some kind of pointer value?
	const Window& window;

	// Debug stuff etc.
	void RenderTextureToScreen(const Texture2D& texture);
	Shader renderTextureShader{"postprocess.vsh", "render_texture.fsh"};

};
