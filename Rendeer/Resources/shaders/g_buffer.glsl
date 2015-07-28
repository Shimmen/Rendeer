
#ifndef _G_BUFFER_GLSL
#define _G_BUFFER_GLSL

#include "functions.glsl"


// Defines a GBuffer for a specific fragment.
struct GBuffer
{
	vec3 albedo;
	vec3 normal;

	float specularIntensity;
	float shininess;

#ifdef LIGHT_SHADER
	vec3 position;
#endif
};



#ifdef MATERIAL_SHADER

layout(location=0) out vec3 o_albedo;
layout(location=1) out vec3 o_normal;
layout(location=2) out vec4 o_material;

void writeGBufferData(in GBuffer gBuffer)
{
	o_albedo = gBuffer.albedo;

	vec3 encodedNormal = encodeNormal(gBuffer.normal);
	o_normal = encodedNormal;

	o_material = vec4(gBuffer.specularIntensity, gBuffer.shininess, 0.0, 0.0);
}

#endif // MATERIAL_SHADER



#ifdef LIGHT_SHADER

uniform sampler2D u_albedo;
uniform sampler2D u_normals;
uniform sampler2D u_material;
uniform sampler2D u_depth;

// Required for getting position from depth
uniform mat4  u_inverse_projection_matrix;

GBuffer extractGBufferData(in vec2 texCoord)
{
	vec4 albedo = texture(u_albedo, texCoord);

	vec4 encodedNormal = texture(u_normals, texCoord);
	vec3 normal = normalize(decodeNormal(encodedNormal.xyz));

	vec4 material = texture(u_material, texCoord);

	// Get view space position of fragment by un-projecting the sceen-space position
	// and the depth from the depth buffer into the linear view space.
	float nonLinearDepth = texture(u_depth, texCoord).x;
	float normalizedNonLinearDepth = nonLinearDepth * 2.0 - 1.0;
	vec2 screenSpacePosition = texCoord * 2.0 - 1.0;
	vec4 projectedPosition = vec4(screenSpacePosition, normalizedNonLinearDepth, 1.0);
	vec4 viewSpacePosition = u_inverse_projection_matrix * projectedPosition;
	viewSpacePosition /= viewSpacePosition.w;

	GBuffer gBuffer;
	gBuffer.albedo = albedo.xyz;
	gBuffer.normal = normal;
	gBuffer.specularIntensity = material.x;
	gBuffer.shininess = material.y;
	gBuffer.position = viewSpacePosition.xyz;
	return gBuffer;
}

#endif // LIGHT_SHADER



#endif // _G_BUFFER_GLSL
