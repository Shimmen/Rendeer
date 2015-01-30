#version 420

out vec4 fragment_color;



in vec2 v_tex_coord;

uniform sampler2D u_diffuse;

void main()
{
	// stb loads the image upside down -> invert y-axis for now
	vec2 inverted_tex_coord = vec2(0.0, 1.0) - v_tex_coord;

    fragment_color = texture(u_diffuse, inverted_tex_coord);
}
