#version 420

out vec4 fragment_color;



in vec2 v_tex_coord;

uniform sampler2D u_texture;

void main()
{
	fragment_color = texture(u_texture, v_tex_coord);// * sin(v_tex_coord.x * 400) * cos(v_tex_coord.y * 400);
}