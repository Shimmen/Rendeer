#version 330

#include "Generic/GenericFunctions.glsl"

#define LIGHT_SHADER
#include "GBuffer/g_buffer.glsl"

#include "Shadowing/ShadowCalculations.glsl"

layout(location=0) out vec4 o_fragment_color;

noperspective in vec2 v_tex_coord;

uniform vec3  u_light_direction;
uniform vec3  u_light_color;
uniform float u_light_intensity;

uniform sampler2D u_shadow_map;
uniform mat4 u_inverse_view_matrix;
uniform mat4 u_light_view_projection;

void main()
{
	GBuffer gBuffer = extractGBufferData(v_tex_coord);

	vec3 lightDirection = normalize(u_light_direction);

	// Calculate diffuse light
	float diffuseIntensity = u_light_intensity * lambertianFactor(gBuffer.normal, lightDirection);
	vec3 diffuseColor = gBuffer.albedo * u_light_color * diffuseIntensity;

	// Calculate specular light
	vec3 fragPos = gBuffer.position;
	vec3 fragToCamera = normalize(-fragPos);
	vec3 lightToFrag = normalize(u_light_direction);
	vec3 reflectedLight = normalize(reflect(lightToFrag, gBuffer.normal));
	float specularFactor = max(dot(reflectedLight, fragToCamera), 0.0);
	specularFactor = pow(specularFactor, gBuffer.shininess);
	vec3 specularColor =  u_light_color * specularFactor * gBuffer.specularIntensity;

	float shadowMapInfluence = calculateShadowMapInfluence(gBuffer.position, u_inverse_view_matrix,
	                                                       u_light_view_projection, u_shadow_map);

	// Calculate the final fragment color
	o_fragment_color = vec4((diffuseColor + specularColor) * shadowMapInfluence, 1.0);
}
