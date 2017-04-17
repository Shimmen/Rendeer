#version 330

#include "Generic/GenericFunctions.glsl"

#define LIGHT_SHADER
#include "GBuffer/g_buffer.glsl"

#include "Shadowing/ShadowCalculations.glsl"

layout(location=0) out vec4 o_fragment_color;

uniform vec3  u_light_position;
uniform vec3  u_light_color;
uniform float u_light_intensity;

void main()
{
	// If rendering point lights as full screen quads we could use the interpolated tex-coords, but might as well always use window coords.
	GBuffer gBuffer = extractGBufferDataFromWindowCoords();

	vec3 lightToFragment = gBuffer.position - u_light_position;
	float lightToFragDistance = length(lightToFragment);

	vec3 lightDirection = normalize(lightToFragment);
	float attenuationFactor = attenuation(lightToFragDistance, u_light_intensity);

	// Calculate diffuse light
	float diffuseIntensity = u_light_intensity * lambertianFactor(gBuffer.normal, lightDirection) * attenuationFactor;
	vec3 diffuseColor = gBuffer.albedo * u_light_color * diffuseIntensity;

	// Calculate specular light
	vec3 fragToCamera = normalize(-gBuffer.position);
	vec3 reflectedLight = normalize(reflect(lightDirection, gBuffer.normal));
	float specularFactor = max(dot(reflectedLight, fragToCamera), 0.0);
	specularFactor = pow(specularFactor, gBuffer.shininess);
	vec3 specularColor =  u_light_color * specularFactor * attenuationFactor * gBuffer.specularIntensity;

	// Calculate the final fragment color
	o_fragment_color = vec4(diffuseColor + specularColor, 1.0);
}
