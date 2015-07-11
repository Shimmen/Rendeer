#version 420 core

#include "functions.glsl"

layout(location=0) out vec4 o_fragment_color;

noperspective in vec2 v_tex_coord;

// TODO: This will be accessed by all of the different light passes
// in the same way since this is the components of the gBuffer.
// So therefore: pack it up with a uniform block!
uniform sampler2D u_albedo;
uniform sampler2D u_normals;
uniform sampler2D u_depth;
uniform sampler2D u_position; // TODO


uniform vec3  u_light_position;
uniform vec3  u_light_color = vec3(1.0, 1.0, 1.0);
uniform float u_light_intensity = 1.0;

uniform mat4  u_projection_matrix;
uniform mat4  u_inverse_projection_matrix;

void main()
{
	// Get surface normal (in view space)
	vec3 encodedNormal = texture(u_normals, v_tex_coord).xyz;
	vec3 normal = normalize(decodeNormal(encodedNormal));

	// Get fragment view space position
	/*
	float nonLinearDepth = texture(u_depth, v_tex_coord).r;
	float linearDepth = linearDepth(nonLinearDepth, u_projection_matrix);
	vec3 viewSpacePos = viewSpacePosition(v_tex_coord, linearDepth, u_inverse_projection_matrix);
	*/

	// TODO: Only for debugging, position will be calculated from depth
	vec3 fragPos = texture(u_position, v_tex_coord).xyz;

	// Get vector (and distance) from light to fragment
	vec3 lightToFrag = fragPos - u_light_position;
	float lightToFragDistance = length(lightToFrag);

	// "Discard" fragment if it's too far away for the light
	// TODO: Handle without branching in some way?
	if(lightToFragDistance > ATTENUATION_MAX_LIGHT_RANGE)
	{
		o_fragment_color = vec4(0, 0, 0, 1);
		return;
	}

	vec3 lightDirection = normalize(lightToFrag);

	// Calculate the lambertian factor for the fragment
	float lambertianFactor = dot(-lightDirection, normal);
	lambertianFactor = max(lambertianFactor, 0.0);

	// Calculate attenuation factor
	float attenuationFactor = attenuation(lightToFragDistance);

	// Calculate the the light's influence on the fragment's color
	vec3 lightInfluence = u_light_color * u_light_intensity * lambertianFactor * attenuationFactor;

	// Calculate the final fragment color
	o_fragment_color = texture(u_albedo, v_tex_coord) * vec4(lightInfluence, 1.0);
}
