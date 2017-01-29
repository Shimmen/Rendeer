#version 330

#include "Filtering/Filtering.glsl"

layout(location=0) out vec4 o_fragment_color;

noperspective in vec2 v_tex_coord;

uniform sampler2D u_texture;
uniform float u_threshold; // lower values -> more passes through

void main()
{
	vec4 texture = texture(u_texture, v_tex_coord);
	float luminance = luminance(texture.rgb);
	o_fragment_color = step(u_threshold, luminance) * texture;
}
