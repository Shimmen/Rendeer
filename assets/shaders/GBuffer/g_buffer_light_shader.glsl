uniform sampler2D u_albedo;
uniform sampler2D u_normals;
uniform sampler2D u_material;
uniform sampler2D u_depth;

// Required for getting position from depth
uniform mat4  u_inverse_projection_matrix;

GBuffer extractGBufferData(in vec2 texCoord)
{
	vec4 albedo = texture(u_albedo, texCoord);

	vec4 encodedNormal = texture(u_normals, texCoord);
	vec3 normal = normalize(decodeNormal(encodedNormal.xyz));

	vec4 material = texture(u_material, texCoord);

	// Get view space position of fragment by un-projecting the sceen-space position
	// and the depth from the depth buffer into the linear view space.
	float nonLinearDepth = texture(u_depth, texCoord).x;
	float normalizedNonLinearDepth = nonLinearDepth * 2.0 - 1.0;
	vec2 screenSpacePosition = texCoord * 2.0 - 1.0;
	vec4 projectedPosition = vec4(screenSpacePosition, normalizedNonLinearDepth, 1.0);
	vec4 viewSpacePosition = u_inverse_projection_matrix * projectedPosition;
	viewSpacePosition /= viewSpacePosition.w;

	GBuffer gBuffer;
	gBuffer.albedo = albedo.xyz;
	gBuffer.normal = normal;
	gBuffer.specularIntensity = material.x;
	gBuffer.shininess = material.y;
	gBuffer.emissive = material.z;
	gBuffer.position = viewSpacePosition.xyz;
	return gBuffer;
}

GBuffer extractGBufferDataFromWindowCoords()
{
	vec2 texCoord = gl_FragCoord.xy / textureSize(u_albedo, 0);
	return extractGBufferData(texCoord);
}
