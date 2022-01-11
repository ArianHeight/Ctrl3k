#version 330 core

layout(location = 0) in vec3 in_position;
layout(location = 2) in vec3 in_normal;
layout(location = 8) in vec2 in_texcoord;
layout(location = 14) in vec3 in_tangent;
layout(location = 15) in vec3 in_biTangent;

out vec3 wPosition;
out vec2 texcoord;
out vec4 tLightPos;
out vec4 tEyePos;
out vec4 tPosition;

//Projection * View Matrix, and Model Matrix.
uniform mat4 MVP;
uniform mat4 M;

uniform vec4 wEyePos; //eye's position in world space.

uniform vec4 wLightPos; //light's position in world space.

void main()
{
	gl_Position = MVP * vec4(in_position, 1.0);
	wPosition = vec3(M * vec4(in_position, 1.0));
	texcoord = in_texcoord;

	vec3 T = normalize(vec3(M * vec4(in_tangent, 0.0)));
	vec3 N = normalize(vec3(M * vec4(in_normal, 0.0)));
	T = normalize(T - dot(T, N) * N);
	vec3 B = cross(T, N);

	mat3 TBN = transpose(mat3(T, B, N));
	tLightPos = vec4(TBN * vec3(wLightPos), 1);
	tEyePos = vec4(TBN * vec3(wEyePos), 1);
	tPosition = vec4(TBN * wPosition, 1);
}