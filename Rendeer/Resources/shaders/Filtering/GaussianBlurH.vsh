#version 420 core

layout(location=0) in vec2 a_position;

noperspective out vec2 v_tex_coord;
noperspective out vec2 v_blur_tex_coords[14];

void main()
{
	gl_Position = vec4(a_position, 0.0, 1.0);
	v_tex_coord = a_position * vec2(0.5) + vec2(0.5);

	v_blur_tex_coords[ 0] = v_tex_coord + vec2(-0.028, 0.0);
	v_blur_tex_coords[ 1] = v_tex_coord + vec2(-0.024, 0.0);
	v_blur_tex_coords[ 2] = v_tex_coord + vec2(-0.020, 0.0);
	v_blur_tex_coords[ 3] = v_tex_coord + vec2(-0.016, 0.0);
	v_blur_tex_coords[ 4] = v_tex_coord + vec2(-0.012, 0.0);
	v_blur_tex_coords[ 5] = v_tex_coord + vec2(-0.008, 0.0);
	v_blur_tex_coords[ 6] = v_tex_coord + vec2(-0.004, 0.0);
	v_blur_tex_coords[ 7] = v_tex_coord + vec2( 0.004, 0.0);
	v_blur_tex_coords[ 8] = v_tex_coord + vec2( 0.008, 0.0);
	v_blur_tex_coords[ 9] = v_tex_coord + vec2( 0.012, 0.0);
	v_blur_tex_coords[10] = v_tex_coord + vec2( 0.016, 0.0);
	v_blur_tex_coords[11] = v_tex_coord + vec2( 0.020, 0.0);
	v_blur_tex_coords[12] = v_tex_coord + vec2( 0.024, 0.0);
	v_blur_tex_coords[13] = v_tex_coord + vec2( 0.028, 0.0);
}
