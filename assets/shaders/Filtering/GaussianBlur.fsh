#version 330

// Filter output color
layout(location=0) out vec4 o_fragment_color;

// Texture to filter
uniform sampler2D u_texture;

noperspective in vec2 v_tex_coord;
noperspective in vec2 v_blur_tex_coords[4];

void main()
{
	// Calculate the lookup positions in the vertex shaders so they are predetermined
	// for the fragment shader. This heavily increases performance, since the fragments
	// can be looked up before executing this shader for a specific fragment by the runtime.

	// Wrights based on a sigma can be calculated here:
	// http://dev.theomader.com/gaussian-kernel-calculator/

	o_fragment_color = vec4(0.0);

	// Based on a sigma value of 2.5. This seems like a good balance between the two below.
	o_fragment_color += texture(u_texture, v_blur_tex_coords[0]) * 0.169327;
	o_fragment_color += texture(u_texture, v_blur_tex_coords[1]) * 0.214574;
	o_fragment_color += texture(u_texture, v_tex_coord         ) * 0.232198;
	o_fragment_color += texture(u_texture, v_blur_tex_coords[2]) * 0.214574;
	o_fragment_color += texture(u_texture, v_blur_tex_coords[3]) * 0.169327;

/*
	// Based on a sigma value of 5.0. This is basically a box blur.
	o_fragment_color += texture(u_texture, v_blur_tex_coords[0]) * 0.192077;
	o_fragment_color += texture(u_texture, v_blur_tex_coords[1]) * 0.203914;
	o_fragment_color += texture(u_texture, v_tex_coord         ) * 0.208019;
	o_fragment_color += texture(u_texture, v_blur_tex_coords[2]) * 0.203914;
	o_fragment_color += texture(u_texture, v_blur_tex_coords[3]) * 0.192077;
*/

/*
	// Based on a sigma value of 1.67 (kernel size / 3). Mild but most gaussian-like behaviour.
	// Used in a GPU gem: http://http.developer.nvidia.com/GPUGems3/gpugems3_ch40.html
	o_fragment_color += texture(u_texture, v_blur_tex_coords[0]) * 0.135561;
	o_fragment_color += texture(u_texture, v_blur_tex_coords[1]) * 0.228485;
	o_fragment_color += texture(u_texture, v_tex_coord         ) * 0.271908;
	o_fragment_color += texture(u_texture, v_blur_tex_coords[2]) * 0.228485;
	o_fragment_color += texture(u_texture, v_blur_tex_coords[3]) * 0.135561;
*/

}
