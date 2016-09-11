#version 420 core

#include "Filtering/Filtering.glsl"

layout(location=0) in vec2 a_position;

// Texture to filter
uniform sampler2D u_texture;

noperspective out vec2 v_tex_coord;
noperspective out vec2 v_blur_tex_coords[4];

void main()
{
	gl_Position = vec4(a_position, 0.0, 1.0);
	v_tex_coord = a_position * vec2(0.5) + vec2(0.5);

	// Gaussian blur sigma value is a texel based unit
	vec2 texelSize = vec2(1.0) / textureSize(u_texture, 0);

	v_blur_tex_coords[0] = v_tex_coord - vec2(0.0, GAUSSIAN_BLUR_SIGMA) * texelSize;
	v_blur_tex_coords[3] = v_tex_coord + vec2(0.0, GAUSSIAN_BLUR_SIGMA) * texelSize;

	v_blur_tex_coords[1] = v_tex_coord - vec2(0.0, GAUSSIAN_BLUR_SIGMA * 0.5) * texelSize;
	v_blur_tex_coords[2] = v_tex_coord + vec2(0.0, GAUSSIAN_BLUR_SIGMA * 0.5) * texelSize;
}
