
/*
 * This file contains everything related to the g-buffer, like encoding, and
 * decoding of the g-buffer and other auxiliary features.
 */

#ifndef _G_BUFFER_GLSL
#define _G_BUFFER_GLSL

#include "functions.glsl"

//
// G-buffer definition for a specific fragment.
//

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

//
// Normal encoding
//

vec3 encodeNormal(in vec3 normal)
{
	return normal * 0.5 + 0.5;
}

vec3 decodeNormal(in vec3 encodedNormal)
{
	return encodedNormal * 2.0 - 1.0;
}

//
// Shader type specific behaviour
//

#if defined(MATERIAL_SHADER)
  #include "GBuffer/g_buffer_material_shader.glsl"
#elif defined(LIGHT_SHADER)
  #include "GBuffer/g_buffer_light_shader.glsl"
#else
  #error "g_buffer.glsl error: neither MATERIAL_SHADER nor LIGHT_SHADER are defined: exactly one must be defined."
#endif

#endif // _G_BUFFER_GLSL
