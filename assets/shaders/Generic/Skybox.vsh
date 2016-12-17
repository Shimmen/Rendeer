#version 330

layout(location=0) in vec3 a_position;

uniform mat4 u_view_rotation_matrix;
uniform mat4 u_projection_matrix;

smooth out vec3 v_tex_coord;

void main()
{
	// Only transform with the rotation of the camera without the translation.
    gl_Position = (u_projection_matrix * u_view_rotation_matrix * vec4(a_position, 1.0));//.xyww;

	// The texture coordinates for a textureCube is the vector from the center
	// of the cube, pointing out towards some point on the inside of the cube.
	v_tex_coord = a_position;
}
