#version 330

in vec2 v_tex_coord;
in vec4 v_frag_color;

uniform sampler2D u_texture;

uniform bool u_flip_texture;
uniform bool u_grayscale;

out vec4 o_color;

void main()
{
	vec2 texCoord = v_tex_coord;

	if (u_flip_texture)
	{
		texCoord.y = 1.0 - texCoord.y;
	}

	o_color = v_frag_color * texture(u_texture, texCoord);

	// All info is in red channel, display it as grayscale
	if (u_grayscale)
	{
		o_color = vec4(vec3(1.0 - o_color.r), 1.0);
	}
}
