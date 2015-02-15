#version 420 core

layout(location=0) out vec3 fragment_color;
// TODO: Use glDrawBuffers() (or glNamedFramebufferDrawBuffers()) to make sure
// we draw into the correct locations!


noperspective in vec2 v_tex_coord;

uniform sampler2D u_diffuse;

void main()
{
	// stb loads the image upside down -> invert y-axis for now
	vec2 inverted_tex_coord = vec2(0.0, 1.0) - v_tex_coord;

    fragment_color = texture(u_diffuse, inverted_tex_coord).rgb;
}
