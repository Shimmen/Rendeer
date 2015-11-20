
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

#endif // _FILTERING_GLSL
