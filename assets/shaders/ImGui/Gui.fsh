#version 330

in vec2 v_tex_coord;
in vec4 v_frag_color;

uniform sampler2D u_texture;

out vec4 o_color;

void main()
{
	o_color = v_frag_color * texture(u_texture, v_tex_coord);
}
