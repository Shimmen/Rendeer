
//
// This file only contains purely functional functions. The functions are simply
// helper functions that performs some calculation that should be consistent
// between different shaders.
//

#ifndef _FUNCTIONS_GLSL
#define _FUNCTIONS_GLSL

float linearDepth(in float nonLinearDepth, in mat4 projectionMatrix)
{
	return projectionMatrix[3][2] / (nonLinearDepth - projectionMatrix[2][2]);
}

vec3 viewSpacePosition(in vec2 screenSpacePosition, in float linearDepth, in mat4 inverseProjection)
{
	// TODO: Do we need to make y=1-y?
	vec2 xy = screenSpacePosition * 2.0 - 1.0;
	vec4 projectedPosition = vec4(xy, linearDepth, 1.0);

	// Transform back to view space with the inverse projection
	vec4 viewSpacePosition = inverseProjection * projectedPosition;

	// Divide by w to get the real view space position
	return viewSpacePosition.xyz / viewSpacePosition.w;
}

vec3 encodeNormal(in vec3 normal)
{
	return normal * 0.5 + 0.5;
}

vec3 decodeNormal(in vec3 encodedNormal)
{
	return encodedNormal * 2.0 - 1.0;
}

float lambertianFactor(in vec3 surfaceNormal, in vec3 lightDirection)
{
	return max(dot(normalize(surfaceNormal), normalize(-lightDirection)), 0.0);
}

#define ATTENUATION_CONSTANT 1.0
#define ATTENUATION_LINEAR 0.0
#define ATTENUATION_EXPONENT 1.0
// Currently, it's not possible to change the attenuation parameters (they default
// to a quite photorealistic attenuation curve), so for now we can make the max
// range a constant:
// Att(x) = 1/(1+x*x) = (1/256)
// (since we use 8-bit color depth, a value lower that 1/256 is not visible)
// x ~= 15.97
#define ATTENUATION_MAX_LIGHT_RANGE 16.0

float attenuation(in float lightToFragDistance)
{
	return 1.0 / (ATTENUATION_CONSTANT +
	              ATTENUATION_LINEAR * lightToFragDistance +
	              ATTENUATION_EXPONENT * lightToFragDistance * lightToFragDistance);
}

#endif // _FUNCTIONS_GLSL
