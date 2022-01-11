#version 330 core

layout(location = 0) in vec3 in_position;
layout(location = 2) in vec3 in_normal;
layout(location = 8) in vec2 in_texcoord;
layout(location = 14) in vec3 in_tangent;
layout(location = 15) in vec3 in_biTangent;

out vec4 vf_wPosition;
out vec4 vf_wNormal;
out vec2 vf_texcoord;

//Projection, View Matrix and Model Matrix.
uniform mat4 P;
uniform mat4 V;
uniform mat4 M;

void main()
{
	gl_Position = P * V * M * vec4(in_position, 1);

	vf_wPosition = M * vec4(in_position, 1);
	vf_wNormal = M * vec4(in_normal, 0);
	vf_texcoord = in_texcoord;
}