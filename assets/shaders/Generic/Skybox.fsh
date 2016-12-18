#version 330

smooth in vec3 v_tex_coord;

uniform samplerCube u_skybox_texture;

// Output/fragment color
out vec4 o_color;

void main()
{
	vec3 tex_coord_fix = v_tex_coord;
	tex_coord_fix.y *= -1; // FIXME: why is everything reversed?!
	o_color = texture(u_skybox_texture, tex_coord_fix);
}
