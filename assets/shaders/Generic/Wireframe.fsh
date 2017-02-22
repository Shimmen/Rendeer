#version 330

out vec4 o_color;

uniform vec4 u_color = vec4(1, 1, 1, 1);

void main()
{
	o_color = u_color;
}
