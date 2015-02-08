#version 420 core

layout(location=0) in vec3 a_position;
layout(location=1) in vec2 a_tex_coord;

uniform mat4 u_mvp_matrix;

out vec2 v_tex_coord;

void main()
{
	v_tex_coord = a_tex_coord;

    gl_Position = u_mvp_matrix * vec4(a_position, 1.0);
}
