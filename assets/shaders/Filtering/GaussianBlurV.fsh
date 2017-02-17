#version 330

layout(location=0) out vec4 o_fragment_color;

uniform sampler2D u_texture;
uniform int u_texture_lod;

noperspective in vec2 v_tex_coord;

const float offset[3] = float[]( 0.0, 1.3846153846, 3.2307692308 );
const float weight[3] = float[]( 0.2270270270, 0.3162162162, 0.0702702703 );

//
// Inspired by:
// http://rastergrid.com/blog/2010/09/efficient-gaussian-blur-with-linear-sampling/
//
void main()
{
	o_fragment_color = textureLod(u_texture, v_tex_coord, u_texture_lod) * weight[0];

	for (int i = 1; i < 3; ++i)
	{
		// Offsets in array are defined in (sub-)pixel offsets
		vec2 offset = vec2(0, offset[i]) / textureSize(u_texture, u_texture_lod);

		o_fragment_color += textureLod(u_texture, v_tex_coord + offset, u_texture_lod) * weight[i];
		o_fragment_color += textureLod(u_texture, v_tex_coord - offset, u_texture_lod) * weight[i];
	}
}
