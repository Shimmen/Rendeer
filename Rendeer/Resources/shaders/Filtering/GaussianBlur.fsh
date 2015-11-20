#version 420 core

// Filter output color
layout(location=0) out vec4 o_fragment_color;

// Texture to filter
uniform sampler2D u_texture;

noperspective in vec2 v_tex_coord;
noperspective in vec2 v_blur_tex_coords[14];

void main()
{
	// Calculate the lookup positions in the vertex shaders so they are predetermined
	// for the fragment shader. This heavily increases performance, since the fragments
	// can be looked up before executing this shader for a specific fragment by the runtime.

	o_fragment_color = vec4(0.0);
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[ 0]) * 0.0044299121055113265;
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[ 1]) * 0.00895781211794;
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[ 2]) * 0.0215963866053;
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[ 3]) * 0.0443683338718;
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[ 4]) * 0.0776744219933;
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[ 5]) * 0.115876621105;
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[ 6]) * 0.147308056121;
	o_fragment_color += texture2D(u_texture, v_tex_coord          ) * 0.159576912161;
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[ 7]) * 0.147308056121;
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[ 8]) * 0.115876621105;
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[ 9]) * 0.0776744219933;
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[10]) * 0.0443683338718;
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[11]) * 0.0215963866053;
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[12]) * 0.00895781211794;
	o_fragment_color += texture2D(u_texture, v_blur_tex_coords[13]) * 0.0044299121055113265;
}
