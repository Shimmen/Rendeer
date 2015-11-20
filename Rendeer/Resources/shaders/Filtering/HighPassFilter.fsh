#version 420 core

#include "Filtering/Filtering.glsl"

// Filter output color
layout(location=0) out vec4 o_fragment_color;

// Texture sampling coordinate
noperspective in vec2 v_tex_coord;

// Texture to filter
uniform sampler2D u_texture;

/*
 * This filter perform a high-pass filter.
*/

// High pass threshold
// Value 0 - nothing passes
// Value 1 - everything passes
uniform float u_threshold;

void main()
{
	vec4 unfiltered = texture(u_texture, v_tex_coord);
	o_fragment_color = highPass(unfiltered, u_threshold);
}
