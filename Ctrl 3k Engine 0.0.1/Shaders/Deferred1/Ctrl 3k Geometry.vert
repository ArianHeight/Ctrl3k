#version 330 core

layout(location = 0) in vec3 in_position;
layout(location = 2) in vec3 in_normal;
layout(location = 8) in vec2 in_texcoord;
layout(location = 14) in vec3 in_tangent;
layout(location = 15) in vec3 in_biTangent;

out vec2 vf_texcoord;
out vec3 vf_vsWorld;
out vec3 vf_vsNormal;
out mat3 vf_vsTBN;

//Projection, View Matrix, and Model Matrix.
uniform mat4 P;
uniform mat4 V;
uniform mat4 M;

void main()
{
	mat4 modelView = V * M;

	vf_vsWorld = (modelView * vec4(in_position, 1.0)).xyz;
	gl_Position = P * vec4(vf_vsWorld, 1.0);
	vf_texcoord = in_texcoord;

	vec3 T = normalize(vec3(modelView * vec4(in_tangent, 0.0)));
	vec3 N = normalize(vec3(modelView * vec4(in_normal, 0.0)));
	T = normalize(T - dot(T, N) * N);
	vec3 B = cross(T, N);

	vf_vsTBN =  mat3(T, B, N);
	vf_vsNormal = N;
}