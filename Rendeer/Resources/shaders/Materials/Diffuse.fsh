#version 420 core

#define MATERIAL_SHADER
#include "GBuffer/g_buffer.glsl"

#include "Generic/GenericFunctions.glsl"

smooth in vec2 v_tex_coord;
smooth in vec3 v_normal;
smooth in vec3 v_tangent;

uniform sampler2D u_diffuse;
uniform sampler2D u_normal_map;
uniform float u_specular_intensity;
uniform float u_shininess;

void main()
{
	GBuffer gBuffer;

	gBuffer.albedo = texture(u_diffuse, v_tex_coord).rgb;

	// Must normalize after vertex->fragment lerp
	vec3 normal = normalize(v_normal);
	vec3 tangent = normalize(v_tangent);

	// Rotate normal from normal map with TBN-matrix into view-space
	vec3 normalMapNormal = decodeNormal(texture(u_normal_map, v_tex_coord).rgb);
	gBuffer.normal = normalize(makeTbnMatrix(normal, tangent) * normalMapNormal);

	gBuffer.specularIntensity = u_specular_intensity;
	gBuffer.shininess = u_shininess;

	writeGBufferData(gBuffer);
}
