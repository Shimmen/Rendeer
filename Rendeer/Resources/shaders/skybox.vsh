#version 420 core

layout(location=0) in vec3 a_position;

uniform mat4 u_view_matrix;
uniform mat4 u_projection_matrix;

smooth out vec3 v_tex_coord;

void main()
{
	// Firstly, only transform position for camera without the translation.
	vec3 viewRotatedPosition = vec3(u_view_matrix) * a_position;
	gl_Position = u_projection_matrix * vec4(viewRotatedPosition, 1.0);

	// The texture coordinates for a textureCube is the vector from the center
	// of the cube, pointing out towards some point on the inside of the cube.
	v_tex_coord = a_position;
}
