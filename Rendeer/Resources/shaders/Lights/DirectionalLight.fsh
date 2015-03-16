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


uniform vec3  u_light_direction;
uniform vec3  u_light_color = vec3(1.0, 1.0, 1.0);
uniform float u_light_intensity = 1.0;

void main()
{
	// Get surface normal (in view space)
	vec3 encodedNormal = texture(u_normals, v_tex_coord).xyz;
	vec3 normal = normalize(decodeNormal(encodedNormal));

	// Make sure light direction is normalized
	vec3 lightDirection = normalize(u_light_direction);

	// Calculate the lambertian factor for the fragment
	float lambertianFactor = dot(-lightDirection, normal);
	lambertianFactor = max(lambertianFactor, 0.0);

	// Calculate the the light's influence on the fragment's color
	vec3 lightInfluence = u_light_color * u_light_intensity * lambertianFactor;

	// Calculate the final fragment color
	o_fragment_color = texture(u_albedo, v_tex_coord) * vec4(lightInfluence, 1.0);
}
