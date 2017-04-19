
/*
 * This file contains functions related to tone mapping.
 */

#ifndef _TONE_MAPPING_GLSL
#define _TONE_MAPPING_GLSL

vec3 simpleReinhardToneMap(in vec3 hdrColor)
{
	return (hdrColor / (hdrColor + vec3(1.0)));
}

// from	http://filmicworlds.com/blog/filmic-tonemapping-operators/
vec3 uncharted2_ToneMap(in vec3 x)
{
	const float A = 0.15;
	const float B = 0.50;
	const float C = 0.10;
	const float D = 0.20;
	const float E = 0.02;
	const float F = 0.30;

	return ((x*(A*x+C*B)+D*E)/(x*(A*x+B)+D*F))-E/F;
}

#endif // _TONE_MAPPING_GLSL
