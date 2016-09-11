
/*
 * This file contains functions related to image filtering.
 */

#ifndef _FILTERING_GLSL
#define _FILTERING_GLSL

// Calculate luminance value from given rgb-color.
float luminance(in vec3 rgbColor)
{
	const vec3 luminanceWeight = vec3(0.2126, 0.7152, 0.0722);
	return dot(rgbColor, luminanceWeight);
}

// Performs a high-pass filter of color (cut of lows are represented as vec4(0,0,0,0)).
// Threshold is used as following:
//   threshold=0 - everything passes through
//   threshold>0 - less passes through as threshold increases.
vec4 highPass(in vec4 color, in float threshold)
{
	float fragmentLuminance = luminance(color.rgb);
	float multiplier = step(threshold, fragmentLuminance);
	return color * vec4(multiplier, multiplier, multiplier, 1.0);
}

// Sigma value used for the weights in GaussianBlur.fsh.
// This should be used in GaussianBlurH/V.vsh aswell to match.
const float GAUSSIAN_BLUR_SIGMA = 2.5;

#endif // _FILTERING_GLSL
