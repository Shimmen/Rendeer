#version 330

layout(location=0) in vec3 a_position;

uniform mat4 u_model_matrix;
uniform mat4 u_view_projecion_matrix;

void main()
{
	gl_Position = u_view_projecion_matrix * u_model_matrix * vec4(a_position, 1.0);
}
