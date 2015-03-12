
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
