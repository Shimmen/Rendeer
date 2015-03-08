#version 420 core

layout(location=0) out vec4 o_fragment_color;

noperspective in vec2 v_tex_coord;

// TODO: This will be accessed by all of the different light passes
// in the same way since this is the components of the gBuffer.
// So therefore: pack it up with a uniform block!
uniform sampler2D u_albedo;
uniform sampler2D u_normals;
uniform sampler2D u_depth;


uniform vec3  u_light_direction;
uniform vec3  u_light_color = vec3(1.0, 1.0, 1.0);
uniform float u_light_intensity = 1.0;


// Used for getting the linear depth
uniform mat4 u_projection_matrix;

float linearDepth(in float nonLinearDepth, in mat4 projectionMatrix)
{
	return projectionMatrix[3][2] / (nonLinearDepth - projectionMatrix[2][2]);
}

vec3 viewSpacePosition(in vec2 screenSpacePosition, in float linearDepth, in mat4 inverseProjection)
{
	// TODO: Do we need to make y=1-y?
	vec2 xy = screenSpacePosition * 2.0 - 1.0;
	vec4 projectedPosition = vec4(xy, linearDepth, 1.0);

	// Transform back to view space with the inverse projection
	vec4 viewSpacePosition = inverseProjection * projectedPosition;

	// Divide by w to get the real view space position
	return viewSpacePosition.xyz / viewSpacePosition.w;
}

vec3 encodeNormal(in vec3 normal)
{
	return normal * 0.5 + 0.5;
}

vec3 decodeNormal(in vec3 encodedNormal)
{
	return encodedNormal * 2.0 - 1.0;
}



void main()
{
	// Get surface normal (in world space)
	vec3 encodedNormal = texture(u_normals, v_tex_coord).xyz;
	vec3 normal = normalize(decodeNormal(encodedNormal));

	// Make sure light direction is normalized
	vec3 lightDirection = normalize(u_light_direction);

	// Calculate the lambertian factor for the fragment
	float lambertianFactor = dot(-lightDirection, normal);
	lambertianFactor = max(lambertianFactor, 0.0);

	// Calculate the the light's influence on the fragment color
	vec3 lightInfluence = u_light_color * u_light_intensity * lambertianFactor;

	// Calculate the final fragment color
	o_fragment_color = texture(u_albedo, v_tex_coord) * vec4(lightInfluence, 1.0);
}
