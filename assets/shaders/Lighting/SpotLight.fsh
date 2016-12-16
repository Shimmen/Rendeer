#version 330

#include "Generic/GenericFunctions.glsl"

#define LIGHT_SHADER
#include "GBuffer/g_buffer.glsl"

#include "Shadowing/ShadowCalculations.glsl"

layout(location=0) out vec4 o_fragment_color;

noperspective in vec2 v_tex_coord;

uniform vec3  u_light_position;
uniform vec3  u_light_direction;
uniform float u_light_outer_cone_angle_cos;
uniform float u_light_inner_cone_angle_cos;
uniform vec3  u_light_color;
uniform float u_light_intensity;

uniform sampler2D u_shadow_map;
uniform mat4 u_inverse_view_matrix;
uniform mat4 u_light_view_projection;

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

		if(angleOfDeviation > u_light_outer_cone_angle_cos)
		{
			float attenuationFactor = attenuation(lightToFragDistance);
			float coneDeviationFactor = smoothstep(u_light_outer_cone_angle_cos, u_light_inner_cone_angle_cos, angleOfDeviation);

			// Calculate diffuse light
			float diffuseIntensity = u_light_intensity * lambertianFactor(gBuffer.normal, actualLightDirection) * attenuationFactor * coneDeviationFactor;
			vec3 diffuseColor = gBuffer.albedo * u_light_color * diffuseIntensity;

			// Calculate specular light
			vec3 fragToCamera = normalize(-gBuffer.position);
			vec3 reflectedLight = normalize(reflect(actualLightDirection, gBuffer.normal));
			float specularFactor = max(dot(reflectedLight, fragToCamera), 0.0);
			specularFactor = pow(specularFactor, gBuffer.shininess);
			vec3 specularColor =  u_light_color * specularFactor * attenuationFactor * coneDeviationFactor * gBuffer.specularIntensity;

			float shadowMapInfluence = calculateShadowMapInfluence(gBuffer.position, u_inverse_view_matrix,
			                                                       u_light_view_projection, u_shadow_map);

			o_fragment_color = vec4((diffuseColor + specularColor) * shadowMapInfluence, 1.0);
		}
		else
		{
			o_fragment_color = vec4(0.0);
		}
	}
}
