#version 330

layout(location=0) in vec3 a_position;

uniform mat4 u_model_matrix;
uniform mat4 u_view_projection;

smooth out vec3 v_tex_coord;

void main()
{
	gl_Position = u_view_projection * u_model_matrix * vec4(a_position, 1.0);
}
