#version 420 core

#include "functions.glsl"
#include "convenience.glsl"

#define LIGHT_SHADER
#include "g_buffer.glsl"

layout(location=0) out vec4 o_fragment_color;

noperspective in vec2 v_tex_coord;

uniform vec3  u_light_position;
uniform vec3  u_light_direction;
uniform float u_light_outer_cone_angle;
uniform float u_light_inner_cone_angle;
uniform vec3  u_light_color;
uniform float u_light_intensity;

void main()
{
	GBuffer gBuffer = extractGBufferData(v_tex_coord);

	vec3 lightToFrag = gBuffer.position - u_light_position;
	float lightToFragDistance = length(lightToFrag);

	if(lightToFragDistance > ATTENUATION_MAX_LIGHT_RANGE)
	{
		o_fragment_color = vec4(0.0);
	}
	else
	{
		// Compare the angle direction of the light to the actual direct from the fragment and the light
		vec3 actualLightDirection = normalize(lightToFrag);
		float angleOfDeviation = dot(normalize(u_light_direction), actualLightDirection);

		if(angleOfDeviation > u_light_outer_cone_angle)
		{
			float attenuationFactor = attenuation(lightToFragDistance);

			// Calculate diffuse light
			float diffuseIntensity = u_light_intensity * lambertianFactor(gBuffer.normal, actualLightDirection) * attenuationFactor;
			diffuseIntensity *= smoothstep(u_light_outer_cone_angle, u_light_inner_cone_angle, angleOfDeviation);
			vec4 diffuseColor = vec4(gBuffer.albedo, 1.0) * vec4(u_light_color, 1.0) * diffuseIntensity;

			// Calculate specular light
			vec3 fragToCamera = normalize(-gBuffer.position);
			vec3 reflectedLight = normalize(reflect(actualLightDirection, gBuffer.normal));
			float specularFactor = max(dot(reflectedLight, fragToCamera), 0.0);
			specularFactor = pow(specularFactor, 100);
			vec4 specularColor =  vec4(u_light_color, 1.0) * specularFactor * attenuationFactor;

			o_fragment_color = diffuseColor + specularColor;
		}
		else
		{
			o_fragment_color = vec4(0.0);
		}
	}
}
