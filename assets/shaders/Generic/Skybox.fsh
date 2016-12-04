#version 330

smooth in vec3 v_tex_coord;

uniform samplerCube u_skybox_texture;

// Output/fragment color
out vec4 o_color;

void main()
{
	o_color = texture(u_skybox_texture, v_tex_coord);
}
