
//
// This file contains convenience functions that will do stuff like interacting with
// samplers and perform multiple steps and calculations. For purely functional functions
// and reuse calculations, look in functions.glsl.
//

#ifndef _CONVENIENCE_GLSL
#define _CONVENIENCE_GLSL

#include "functions.glsl"

vec3 getViewSpaceNormal(in sampler2D normalMap, in vec2 textureCoordinate)
{
	vec3 encodedNormal = texture(normalMap, textureCoordinate).xyz;
	return normalize(decodeNormal(encodedNormal));
}

#endif // _CONVENIENCE_GLSL
