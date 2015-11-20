
/*
 * This file only contains purely functional functions. The functions are simply
 * helper functions that performs some calculation that should be consistent
 * between different shaders.
 */

#ifndef _FUNCTIONS_GLSL
#define _FUNCTIONS_GLSL

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

// Calculate luminance value from given rgb-color.
float luminance(in vec3 rgbColor)
{
	const vec3 luminanceWeight = vec3(0.2126, 0.7152, 0.0722);
	return dot(rgbColor, luminanceWeight);
}

vec3 simpleReinhardToneMap(in vec3 hdrColor)
{
	return (hdrColor / (hdrColor + vec3(1.0)));
}

vec3 uncharted2_ToneMap(in vec3 hdrColor)
{
    const float A = 0.15;
	const float B = 0.50;
	const float C = 0.10;
	const float D = 0.20;
	const float E = 0.02;
	const float F = 0.30;

    return ((hdrColor * (A * hdrColor + C * B) + D * E) / (hdrColor * (A * hdrColor + B) + D * F)) - E / F;
}

#endif // _FUNCTIONS_GLSL
