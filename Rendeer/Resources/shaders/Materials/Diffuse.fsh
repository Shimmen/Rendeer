#version 420 core

#define MATERIAL_SHADER
#include "g_buffer.glsl"
#include "functions.glsl"

smooth in vec2 v_tex_coord;
smooth in vec3 v_normal;
smooth in vec3 v_position; // TODO

uniform sampler2D u_diffuse;

void main()
{
	GBuffer gBuffer;

	gBuffer.albedo = texture(u_diffuse, v_tex_coord).rgb;

	// Must normalize after vertex->fragment lerp
	gBuffer.normal = normalize(v_normal);

	// TODO: Only for debugging, position will be calculated from depth
	gBuffer.position = v_position;

	writeGBufferData(gBuffer);
}
