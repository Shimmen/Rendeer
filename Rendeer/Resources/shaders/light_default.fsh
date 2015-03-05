#version 420 core

layout(location=0) out vec4 o_fragment_color;



noperspective in vec2 v_tex_coord;

// TODO: This will be accessed by all of the different light passes
// in the same way since this is the components of the gBuffer.
// So therefore: pack it up with a uniform block!
uniform sampler2D u_albedo;
uniform sampler2D u_normals;
uniform sampler2D u_depth;

void main()
{
	// All this light code is very temp!
	const vec3 directionalLightDirection = normalize(vec3(1.0, -0.2, 0.5));

	vec3 packedNormal = texture(u_normals, v_tex_coord).xyz;
	vec3 normal = packedNormal * vec3(2.0) - vec3(1.0);
	float lambertianFactor = dot(-directionalLightDirection, normal);
	lambertianFactor = max(lambertianFactor, 0.0);

	o_fragment_color = texture(u_albedo, v_tex_coord) * lambertianFactor;
}
