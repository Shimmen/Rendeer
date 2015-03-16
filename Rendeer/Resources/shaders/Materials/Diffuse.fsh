#version 420 core

#include "functions.glsl"

layout(location=0) out vec3 o_fragment_color;
layout(location=1) out vec3 o_normal;

smooth in vec2 v_tex_coord;
smooth in vec3 v_normal;

uniform sampler2D u_diffuse;

void main()
{
  // Must normalize after vertex->fragment lerp
	vec3 normal = normalize(v_normal);
	o_normal = encodeNormal(normal);

  o_fragment_color = texture(u_diffuse, v_tex_coord).rgb;
}
