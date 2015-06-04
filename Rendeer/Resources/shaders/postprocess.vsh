#version 420 core

layout(location=0) in vec2 a_position;

noperspective out vec2 v_tex_coord;

void main()
{
	v_tex_coord = a_position * vec2(0.5) + vec2(0.5);
   gl_Position = vec4(a_position, 0.0, 1.0);
}
