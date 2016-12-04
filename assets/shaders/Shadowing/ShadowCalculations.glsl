
/*
 * This file only contains functions and constants related to shadows.
 */

#ifndef _SHADOW_CALCULATIONS_GLSL
#define _SHADOW_CALCULATIONS_GLSL

//
// Constants
//

const bool SAMPLE_SHADOW_MAP_LINEAR = false;
const bool USE_PCF_SHADOWS = true;

const float SHADOW_MAP_BIAS = 0.0025;

const int PCF_KERNEL_SIZE = 2;
const float PCF_SAMPLE_COUNT = pow(PCF_KERNEL_SIZE, 2.0);
const float PCF_SAMPLE_LOOP_EDGE = (float(PCF_KERNEL_SIZE) - 1.0) / 2.0;

//
// Functions
//

float sampleShadowMapNearest(in sampler2D shadowMap, in vec2 uv, in float comparisonDepth)
{
	float shadowMapDepth = texture(shadowMap, uv).r;
	return step(comparisonDepth, shadowMapDepth + SHADOW_MAP_BIAS);
}

float sampleShadowMapLinear(in sampler2D shadowMap, in vec2 uv, in float comparisonDepth, in vec2 texelSize)
{
	vec2 pixelPosition = uv / texelSize + vec2(0.5);
	vec2 fractionalPart = fract(pixelPosition);
	vec2 startTexel = (pixelPosition - fractionalPart) * texelSize;

	float blTexel = sampleShadowMapNearest(shadowMap, startTexel, comparisonDepth);
	float brTexel = sampleShadowMapNearest(shadowMap, startTexel + vec2(texelSize.x, 0.0), comparisonDepth);
	float tlTexel = sampleShadowMapNearest(shadowMap, startTexel + vec2(0.0, texelSize.y), comparisonDepth);
	float trTexel = sampleShadowMapNearest(shadowMap, startTexel + texelSize, comparisonDepth);

	float mixLeft = mix(blTexel, tlTexel, fractionalPart.y);
	float mixRight = mix(brTexel, trTexel, fractionalPart.y);

	return mix(mixLeft, mixRight, fractionalPart.x);
}

float sampleShadowMap(in sampler2D shadowMap, in vec2 uv, in float comparisonDepth, in vec2 texelSize)
{
	if(SAMPLE_SHADOW_MAP_LINEAR)
	{
		return sampleShadowMapLinear(shadowMap, uv, comparisonDepth, texelSize);
	}
	else
	{
		return sampleShadowMapNearest(shadowMap, uv, comparisonDepth);
	}
}

float sampleShadowMapPcf(in sampler2D shadowMap, in vec2 uv, in float comparisonDepth, in vec2 texelSize)
{
	float shadowInfluence = 0.0;

	for(float y = -PCF_SAMPLE_LOOP_EDGE; y <= PCF_SAMPLE_LOOP_EDGE; y += 1.0)
	{
		for(float x = -PCF_SAMPLE_LOOP_EDGE; x <= PCF_SAMPLE_LOOP_EDGE; x += 1.0)
		{
			vec2 uvOffset = vec2(x, y) * texelSize;
			shadowInfluence += sampleShadowMap(shadowMap, uv + uvOffset, comparisonDepth, texelSize);
		}
	}

	return shadowInfluence / PCF_SAMPLE_COUNT;
}

float calculateShadowMapInfluence(in vec3 viewSpacePosition,
                                  in mat4 inverseViewSpace,
                                  in mat4 lightViewProjection,
                                  in sampler2D shadowMap)
{
	// Transform view-space to world-space
	vec4 worldSpacePosition = inverseViewSpace * vec4(viewSpacePosition, 1.0);

	// Transform world-space to light-space
	vec4 lightSpacePosition = lightViewProjection * worldSpacePosition;
	lightSpacePosition.xyz /= lightSpacePosition.w;

	// Transform to light-space to screen-space
	vec4 screenSpace = lightSpacePosition * 0.5 + 0.5;

	// Clamp projected depth, since if a fragment is outside the light camera area
	// it should not be in shadow: i.e. projecteddepth <= shadow map depth. For it
	// to be that, it can't be outside the shadow map range.
	// This has the same effect as "if(screenSpace.z > 1.0) return 0.0;"
	float currentFragmentDepth = min(screenSpace.z, 1.0);

	vec2 texelSize = vec2(1.0) / textureSize(shadowMap, 0);

	if(USE_PCF_SHADOWS)
	{
		return sampleShadowMapPcf(shadowMap, screenSpace.xy, currentFragmentDepth, texelSize);
	}
	else
	{
		return sampleShadowMap(shadowMap, screenSpace.xy, currentFragmentDepth, texelSize);
	}
}

#endif // _SHADOW_CALCULATIONS_GLSL
