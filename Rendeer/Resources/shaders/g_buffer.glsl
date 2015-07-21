
#ifndef _G_BUFFER_GLSL
#define _G_BUFFER_GLSL

#include "functions.glsl"


// Defines a GBuffer for a specific fragment.
struct GBuffer
{
	vec3 albedo;
	vec3 normal;
	vec3 position;

#ifdef LIGHT_SHADER
	// In light shaders the depth can also be relevant to know/use
	float linearDepth;
#endif
};



#ifdef MATERIAL_SHADER

layout(location=0) out vec3 o_albedo;
layout(location=1) out vec3 o_normal;

void writeGBufferData(in GBuffer gBuffer)
{
	o_albedo = gBuffer.albedo;

	vec3 encodedNormal = encodeNormal(gBuffer.normal);
	o_normal = encodedNormal;
}

#endif // MATERIAL_SHADER



#ifdef LIGHT_SHADER

// TODO: Use uniform block
uniform sampler2D u_albedo;
uniform sampler2D u_normals;
uniform sampler2D u_depth;

uniform mat4  u_inverse_projection_matrix;

vec3 getPositionFromLinearDepth(in vec2 texCoord, in float linearDepth, in mat4 inverseProjection)
{
	vec2 screenSpacePosition = texCoord * 2.0 - 1.0;
	vec4 projectedPosition = vec4(screenSpacePosition, linearDepth, 1.0);

	vec4 viewSpacePosition = inverseProjection * projectedPosition;
	viewSpacePosition /= viewSpacePosition.w;

	return viewSpacePosition.xyz;
}

GBuffer extractGBufferData(in vec2 texCoord)
{
	vec4 albedo = texture(u_albedo, texCoord);

	vec4 encodedNormal = texture(u_normals, texCoord);
	vec3 normal = normalize(decodeNormal(encodedNormal.xyz));

	float nonLinearDepth = texture(u_depth, texCoord).x;
	float normalizedNonLinearDepth = nonLinearDepth * 2.0 - 1.0;
	//float near = 1.0;
	//float far  = 1000.0;
	//float linearDepth = 2.0 * near * far / (far + near - normalizedNonLinearDepth * (far - near));

	vec3 position = getPositionFromLinearDepth(texCoord, normalizedNonLinearDepth, u_inverse_projection_matrix);

	GBuffer gBuffer;
	gBuffer.albedo = albedo.xyz;
	gBuffer.normal = normal;
	gBuffer.position = position;
	//gBuffer.linearDepth = linearDepth;
	return gBuffer;
}

#endif // LIGHT_SHADER



#endif // _G_BUFFER_GLSL
