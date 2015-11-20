
/*
 * This file only contains purely functional functions. The functions are simply
 * helper functions that performs some calculation that should be consistent
 * between different shaders.
 */

#ifndef _GENERIC_FUNCTIONS_GLSL
#define _GENERIC_FUNCTIONS_GLSL

float lambertianFactor(in vec3 surfaceNormal, in vec3 lightDirection)
{
	return max(dot(normalize(surfaceNormal), normalize(-lightDirection)), 0.0);
}

// Will make v1 ortagonal to v0. v1 will remain unchanged
void reortogonalize(in vec3 v0, inout vec3 v1)
{
	// Perform Gram-Schmidt's re-ortogonalization process
	v1 = normalize(v1 - dot(v1, v0) * v0);
}

mat3 makeTbnMatrix(in vec3 normal, in vec3 tangent)
{
	normalize(normal);
	normalize(tangent);
	reortogonalize(normal, tangent);
	vec3 biTangent = normalize(cross(normal, tangent));
	return mat3(tangent, biTangent, normal);
}

// TODO: How should this be handled?
//#define USE_MAX_LIGHT_RANGE

// Since we use 8-bit color depth, a value lower that 1/256 is not visible. Therefore
// we can find the max light range by solving x for:
// (1 / x*x) < (1.0 / 256.0) => +-16
#ifdef USE_MAX_LIGHT_RANGE
	#define ATTENUATION_MAX_LIGHT_RANGE 16.0
#else
	#define ATTENUATION_MAX_LIGHT_RANGE 999999.0
#endif

float attenuation(in float lightToFragDistance)
{
	return 1.0 / (lightToFragDistance * lightToFragDistance);
}

#endif // _GENERIC_FUNCTIONS_GLSL
