#version 420 core

layout(location=0) in vec3 a_position;
layout(location=1) in vec3 a_normal;
layout(location=2) in vec3 a_tangent;
layout(location=3) in vec2 a_tex_coord;

uniform mat4 u_model_view_matrix;
uniform mat4 u_projection_matrix;

smooth out vec2 v_tex_coord;
smooth out vec3 v_normal;
smooth out vec3 v_tangent;

void main()
{
	v_tex_coord = a_tex_coord;

	// Only uniform scaling (i.e. same for x, y, and z) is supported for now.
	v_normal = mat3(u_model_view_matrix) * a_normal;
	v_tangent = mat3(u_model_view_matrix) * a_tangent;

	gl_Position = u_projection_matrix * u_model_view_matrix * vec4(a_position, 1.0);
}
