#version 330

#define LIGHT_SHADER
#include "GBuffer/g_buffer.glsl"

layout(location=0) out vec4 o_fragment_color;

noperspective in vec2 v_tex_coord;

uniform vec3 u_color;

//
// Handles both ambient light AND emissive materials!
//

void main()
{
	GBuffer gBuffer = extractGBufferData(v_tex_coord);
	vec3 diffuse = gBuffer.albedo * u_color;
	vec3 emissive = gBuffer.albedo * gBuffer.emissive;
	o_fragment_color = vec4(diffuse + emissive, 1.0);
}
