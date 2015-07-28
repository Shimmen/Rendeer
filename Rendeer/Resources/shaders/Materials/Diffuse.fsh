#version 420 core

#define MATERIAL_SHADER
#include "g_buffer.glsl"
#include "functions.glsl"

smooth in vec2 v_tex_coord;
smooth in vec3 v_normal;

uniform sampler2D u_diffuse;
uniform float u_specular_intensity;
uniform float u_shininess;

void main()
{
	GBuffer gBuffer;

	gBuffer.albedo = texture(u_diffuse, v_tex_coord).rgb;

	// Must normalize after vertex->fragment lerp
	gBuffer.normal = normalize(v_normal);

	gBuffer.specularIntensity = u_specular_intensity;
	gBuffer.shininess = u_shininess;

	writeGBufferData(gBuffer);
}
