
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

// from https://imdoingitwrong.wordpress.com/2011/01/31/light-attenuation/
const float cutoff = 0.024;
float attenuation(float distance, float intensity)
{
	float r = intensity; // use intensity as the radius
	float d = max(distance - r, 0);

	// calculate basic attenuation
	float denom = d/r + 1;
	float attenuation = 1 / (denom*denom);

	// scale and bias attenuation such that:
	//   attenuation == 0 at extent of max influence
	//   attenuation == 1 when d == 0
	attenuation = (attenuation - cutoff) / (1 - cutoff);
	attenuation = max(attenuation, 0);

	return attenuation;
}

#endif // _GENERIC_FUNCTIONS_GLSL
