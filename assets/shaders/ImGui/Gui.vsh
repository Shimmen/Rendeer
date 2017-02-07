#version 330

layout(location=0) in vec2 a_position;
layout(location=1) in vec2 a_tex_coord;
layout(location=2) in vec4 a_color;

uniform mat4 u_projection;

out vec2 v_tex_coord;
out vec4 v_frag_color;

void main()
{
	v_tex_coord = a_tex_coord;
	v_frag_color = a_color;
	gl_Position = u_projection * vec4(a_position.xy, 0, 1);
}
