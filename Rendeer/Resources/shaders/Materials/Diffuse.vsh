#version 420 core

layout(location=0) in vec3 a_position;
layout(location=1) in vec2 a_tex_coord;
layout(location=2) in vec3 a_normal;

uniform mat4 u_model_matrix;
uniform mat4 u_view_projection_matrix;

smooth out vec2 v_tex_coord;
smooth out vec3 v_normal;
smooth out vec3 v_position; // TODO

void main()
{
	v_tex_coord = a_tex_coord;

	// Only uniform scaling (i.e. same for x, y, and z) is supported for now.
	v_normal = mat3(u_model_matrix) * a_normal;

	// TODO: Only for debugging, position will be calculated from depth
	v_position = (u_model_matrix * vec4(a_position, 1.0)).xyz;

  gl_Position = u_view_projection_matrix * u_model_matrix * vec4(a_position, 1.0);
}
