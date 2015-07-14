#version 420 core

#include "functions.glsl"
#include "convenience.glsl"

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
uniform vec3  u_light_color;
uniform float u_light_intensity;

uniform mat4  u_projection_matrix;
uniform mat4  u_inverse_projection_matrix;

void main()
{
	// Get fragment view space position
	vec3 fragmentPosition = texture(u_position, v_tex_coord).xyz;
	//float nonLinearDepth = texture(u_depth, v_tex_coord).r;
	//float linearDepth = linearDepth(nonLinearDepth, u_projection_matrix);
	//vec3 fragmentPosition = viewSpacePosition(v_tex_coord, linearDepth, u_inverse_projection_matrix);

	vec3 lightToFragment = fragmentPosition - u_light_position;
	float lightToFragDistance = length(lightToFragment);

	if(lightToFragDistance > ATTENUATION_MAX_LIGHT_RANGE)
	{
		o_fragment_color = vec4(0.0);
	}
	else
	{
		vec3 normal = getViewSpaceNormal(u_normals, v_tex_coord);
		vec3 lightDirection = normalize(lightToFragment);
		float attenuationFactor = attenuation(lightToFragDistance);

		// Calculate diffuse light
		vec4 albedoColor = texture(u_albedo, v_tex_coord);
		float diffuseIntensity = u_light_intensity * lambertianFactor(normal, lightDirection) * attenuationFactor;
		vec4 diffuseColor = albedoColor * vec4(u_light_color, 1.0) * diffuseIntensity;

		// Calculate specular light
		vec3 fragToCamera = normalize(-fragmentPosition);
		vec3 reflectedLight = normalize(reflect(lightDirection, normal));
		float specularFactor = max(dot(reflectedLight, fragToCamera), 0.0);
		specularFactor = pow(specularFactor, 100);
		vec4 specularColor =  vec4(u_light_color, 1.0) * specularFactor * attenuationFactor;

		// Calculate the final fragment color
		o_fragment_color = diffuseColor + specularColor;
	}
}
