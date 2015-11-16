#version 420 core

#include "functions.glsl"

layout(location=0) out vec4 o_fragment_color;

noperspective in vec2 v_tex_coord;

uniform sampler2D u_texture;

void main()
{
	// Get fragment color value
	vec4 fragment = texture(u_texture, v_tex_coord);

	// Apply grayscale filter
	//float lum = luminance(fragment.rgb);
	//fragment = vec4(lum, lum, lum, 1.0);

  //vec3 ldrFragment = simpleReinhardToneMap(fragment.rgb);
	vec3 ldrFragment = uncharted2_ToneMap(fragment.rgb);

	// Write out color value
	o_fragment_color = vec4(ldrFragment, 1.0);
}
