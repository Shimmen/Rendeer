
#ifndef _G_BUFFER_GLSL
#define _G_BUFFER_GLSL

#include "functions.glsl"

// Defines a GBuffer for a specific fragment.
struct GBuffer
{
	vec3 albedo;
	vec3 normal;
	//float depth;
	vec3 position;
};

#ifdef MATERIAL_SHADER

layout(location=0) out vec3 o_albedo;
layout(location=1) out vec3 o_normal;
layout(location=2) out vec3 o_position; // TODO

void writeGBufferData(in GBuffer gBuffer)
{
	o_albedo = gBuffer.albedo;

	vec3 encodedNormal = encodeNormal(gBuffer.normal);
	o_normal = encodedNormal;

	o_position = gBuffer.position;
}

#endif // MATERIAL_SHADER

#ifdef LIGHT_SHADER

// TODO: Use uniform block
uniform sampler2D u_albedo;
uniform sampler2D u_normals;
//uniform sampler2D u_depth;
uniform sampler2D u_position; // TODO

GBuffer extractGBufferData(in vec2 texCoord)
{
	vec4 albedo = texture(u_albedo, texCoord);

	vec4 encodedNormal = texture(u_normals, texCoord);
	vec3 normal = normalize(decodeNormal(encodedNormal.xyz));

	vec4 position = texture(u_position, texCoord);

	GBuffer gBuffer;
	gBuffer.albedo = albedo.xyz;
	gBuffer.normal = normal;
	gBuffer.position = position.xyz;
	return gBuffer;
}

#endif // LIGHT_SHADER

#endif // _G_BUFFER_GLSL
