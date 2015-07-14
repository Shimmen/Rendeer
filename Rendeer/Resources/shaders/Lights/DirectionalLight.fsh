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

uniform vec3  u_light_direction;
uniform vec3  u_light_color;
uniform float u_light_intensity;

void main()
{
	vec3 normal = getViewSpaceNormal(u_normals, v_tex_coord);
	vec3 lightDirection = normalize(u_light_direction);

	// Calculate diffuse light
	vec4 albedoColor = texture(u_albedo, v_tex_coord);
	float diffuseIntensity = u_light_intensity * lambertianFactor(normal, lightDirection);
	vec4 diffuseColor = albedoColor * vec4(u_light_color, 1.0) * diffuseIntensity;

	// Calculate specular light
	vec3 fragPos = texture(u_position, v_tex_coord).xyz;
	vec3 fragToCamera = normalize(-fragPos);
	vec3 lightToFrag = normalize(u_light_direction);
	vec3 reflectedLight = normalize(reflect(lightToFrag, normal));
	float specularFactor = max(dot(reflectedLight, fragToCamera), 0.0);
	specularFactor = pow(specularFactor, 100);
	vec4 specularColor =  vec4(u_light_color, 1.0) * specularFactor;

	// Calculate the final fragment color
	o_fragment_color = diffuseColor + specularColor;
}
