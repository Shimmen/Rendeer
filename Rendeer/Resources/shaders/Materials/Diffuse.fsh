#version 420 core

#define MATERIAL_SHADER
#include "g_buffer.glsl"
#include "functions.glsl"

smooth in vec2 v_tex_coord;
smooth in vec3 v_normal;
smooth in vec3 v_tangent;

uniform sampler2D u_diffuse;
uniform float u_specular_intensity;
uniform float u_shininess;

void main()
{
	GBuffer gBuffer;

	gBuffer.albedo = texture(u_diffuse, v_tex_coord).rgb;

	// Must normalize after vertex->fragment lerp
	vec3 normal = normalize(v_normal);
	vec3 tangent = normalize(v_tangent);

	//
	// 1. Generate TBN-matrix (in a separate function)
	//   - 1. Perform Gram-Schmidt's re-ortogonalization (in a separate function)
	//   - 2. Assemble TBN-matrix
	//   - 3. Return TBN-matrix
	// 2. Encode normal from normal map sampler.
	//   - 1. Read swizzled xyz value from sampler
	//   - 2. Transform from [0, 1] to [-1, 1]
	// 3. Rotate normal map normal with TBN-matrix
	//   - 1. vec3 rotatedNormal = tbnMatrix * normalMapNormal;
	// 4. Assign rotated normal map normal into gBuffer.normal
	//   - gBuffer.normal = rotatedNormal;
	//

	gBuffer.normal = normal;

	gBuffer.specularIntensity = u_specular_intensity;
	gBuffer.shininess = u_shininess;

	writeGBufferData(gBuffer);
}
