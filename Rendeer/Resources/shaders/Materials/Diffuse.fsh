#version 420 core

layout(location=0) out vec3 o_fragment_color;
layout(location=1) out vec3 o_normal;

noperspective in vec2 v_tex_coord;
smooth in vec3 v_normal;

uniform sampler2D u_diffuse;

void main()
{
	// stb loads the image upside down -> invert y-axis for now
	vec2 inverted_tex_coord = vec2(0.0, 1.0) - v_tex_coord;

	// Must normalize after vertex->fragment lerp
	vec3 normal = normalize(v_normal);
	vec3 packedNormal = normal * vec3(0.5) + vec3(0.5);
	o_normal = packedNormal;

  o_fragment_color = texture(u_diffuse, inverted_tex_coord).rgb;
}
