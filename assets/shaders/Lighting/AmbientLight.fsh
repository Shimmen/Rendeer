#version 330

#define LIGHT_SHADER
#include "GBuffer/g_buffer.glsl"

layout(location=0) out vec4 o_fragment_color;

noperspective in vec2 v_tex_coord;

uniform vec3 u_color;

void main()
{
	GBuffer gBuffer = extractGBufferData(v_tex_coord);
	o_fragment_color = vec4(gBuffer.albedo * u_color, 1.0);
}
