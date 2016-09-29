#version 330

// Filter output color
layout(location=0) out vec4 o_fragment_color;

// Texture sampling coordinate
noperspective in vec2 v_tex_coord;

// Texture to filter
uniform sampler2D u_texture;

/*
 * This filter perform no filtering, and can act as a baseline for all other filters.
*/

void main()
{
	o_fragment_color = texture(u_texture, v_tex_coord);
}
