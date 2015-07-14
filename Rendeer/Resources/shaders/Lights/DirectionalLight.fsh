#version 420 core

#include "functions.glsl"
#include "convenience.glsl"

#define LIGHT_SHADER
#include "g_buffer.glsl"

layout(location=0) out vec4 o_fragment_color;

noperspective in vec2 v_tex_coord;

uniform vec3  u_light_direction;
uniform vec3  u_light_color;
uniform float u_light_intensity;

void main()
{
	GBuffer gBuffer = extractGBufferData(v_tex_coord);

	vec3 lightDirection = normalize(u_light_direction);

	// Calculate diffuse light
	float diffuseIntensity = u_light_intensity * lambertianFactor(gBuffer.normal, lightDirection);
	vec4 diffuseColor = vec4(gBuffer.albedo, 1.0) * vec4(u_light_color, 1.0) * diffuseIntensity;

	// Calculate specular light
	vec3 fragPos = gBuffer.position;
	vec3 fragToCamera = normalize(-fragPos);
	vec3 lightToFrag = normalize(u_light_direction);
	vec3 reflectedLight = normalize(reflect(lightToFrag, gBuffer.normal));
	float specularFactor = max(dot(reflectedLight, fragToCamera), 0.0);
	specularFactor = pow(specularFactor, 100);
	vec4 specularColor =  vec4(u_light_color, 1.0) * specularFactor;

	// Calculate the final fragment color
	o_fragment_color = diffuseColor + specularColor;
}
