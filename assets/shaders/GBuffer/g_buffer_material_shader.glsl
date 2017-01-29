layout(location=0) out vec3 o_albedo;
layout(location=1) out vec3 o_normal;
layout(location=2) out vec4 o_material;

void writeGBufferData(in GBuffer gBuffer)
{
	o_albedo = gBuffer.albedo;

	vec3 encodedNormal = encodeNormal(gBuffer.normal);
	o_normal = encodedNormal;

	o_material = vec4(gBuffer.specularIntensity, gBuffer.shininess, gBuffer.emissive, 0.0);
}
