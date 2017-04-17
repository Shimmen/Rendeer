#version 330

layout(location=0) in vec3 a_position;

uniform vec3 u_light_world_position;
uniform float u_light_radius;
uniform mat4 u_view_projection_matrix;


//
// Draws a point-light light volume. Don't use this if the distance from the light to the camera
// is less than (or equal) to the light radius + camera z-near. In that case, draw the light as
// a full screen quad, so that we wont be inside the volume and cull the whole light.
//

void main()
{
	vec4 worldPos = vec4(u_light_radius * a_position + u_light_world_position, 1.0);
	gl_Position = u_view_projection_matrix * worldPos;
}
