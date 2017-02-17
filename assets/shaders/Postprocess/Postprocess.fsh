#version 330

#include "Filtering/Filtering.glsl"
#include "Filtering/ToneMapping.glsl"

layout(location=0) out vec4 o_fragment_color;

noperspective in vec2 v_tex_coord;

uniform sampler2D u_texture;

uniform vec2 u_bloom_weights;
uniform sampler2D u_bloom_1;
uniform sampler2D u_bloom_2;
uniform float u_bloom_master_weight;

uniform float u_chroma_ab_amount;

//
// Offset outwards from the center, more or less depending on the distance from center.
// This is similar to what would happen in a curved camera lens, but of course it's
// completly fake, since there is no actual refraction calculations taking place.
//
vec3 sampleChromaticAberration(in sampler2D tex, in vec2 uv, in float amount)
{
	const vec2 center = vec2(0.5);
	const vec2 shape = vec2(0.64, 0.30); // less y-axis impact
	const vec3 weights = vec3(0.07, 0.0, 0.12);

	vec2 fromCenter = (center - uv) * shape;
	float chromAb = pow(min(length(fromCenter), 1.0), 2.8);

	vec2 offsetR = chromAb * normalize(fromCenter) * weights.r * amount;
	vec2 offsetG = chromAb * normalize(fromCenter) * weights.g * amount;
	vec2 offsetB = chromAb * normalize(fromCenter) * weights.b * amount;

	float r = texture(tex, uv + offsetR).r;
	float g = texture(tex, uv + offsetG).g;
	float b = texture(tex, uv + offsetB).b;

	vec3 color = vec3(r, g, b);
	return color;
}

void main()
{
	vec3 fragment = sampleChromaticAberration(u_texture, v_tex_coord, u_chroma_ab_amount);

	// Add weighted blur into image
	vec4 bloom = vec4(0.0);
	bloom += texture(u_bloom_1, v_tex_coord) * u_bloom_weights.x;
	bloom += texture(u_bloom_2, v_tex_coord) * u_bloom_weights.y;
	fragment += bloom.rgb * u_bloom_master_weight;

	vec3 ldrFragment = uncharted2_ToneMap(fragment);

	// Write out color value
	o_fragment_color = vec4(ldrFragment, 1.0);
}
