#version 330

#define LIGHT_SHADER
#include "GBuffer/g_buffer.glsl"

layout(location=0) out vec4 o_fragment_color;

noperspective in vec2 v_tex_coord;

uniform float u_intensity;

void main()
{
	GBuffer gBuffer = extractGBufferData(v_tex_coord);
	o_fragment_color = vec4(gBuffer.albedo, 1.0) * u_intensity;
}
