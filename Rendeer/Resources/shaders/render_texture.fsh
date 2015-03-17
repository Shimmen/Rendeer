#version 420 core

layout(location=0) out vec4 o_fragment_color;

noperspective in vec2 v_tex_coord;

uniform sampler2D u_texture;

/*
   This shader will just render any texture without
   any effects or lighting calculations.
*/

void main()
{
	o_fragment_color = texture(u_texture, v_tex_coord);
}
