#version 420 core

#include "functions.glsl"

layout(location=0) out vec3 o_albedo;
layout(location=1) out vec3 o_normal;
layout(location=2) out vec3 o_position; // TODO

smooth in vec2 v_tex_coord;
smooth in vec3 v_normal;
smooth in vec3 v_position; // TODO

uniform sampler2D u_diffuse;

void main()
{
	// Must normalize after vertex->fragment lerp
	vec3 normal = normalize(v_normal);
	o_normal = encodeNormal(normal);

	// TODO: Only for debugging, position will be calculated from depth
	o_position = v_position;

	o_albedo = texture(u_diffuse, v_tex_coord).rgb;
}
