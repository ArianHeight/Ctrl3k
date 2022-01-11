#version 330 core

layout(location = 0) in vec3 in_ndcPosition;
layout(location = 1) in vec2 in_texcoord;

uniform vec2 texelOffset;

out vec2 vf_texcoord;
out vec4 vf_extraSamples[8];

/*
02
11
20
1-1
0-2
-1-1
-20
-11

04
33
40
3-3
0-4
-3-3
-40
-33
*/

void main()
{
	gl_Position = vec4(in_ndcPosition, 1.0);
	vf_texcoord = in_texcoord;
	
	vf_extraSamples[0].xy = in_texcoord + (vec2(0.0, 2.0) * texelOffset);
	vf_extraSamples[0].zw = in_texcoord + (vec2(1.0, 1.0) * texelOffset);
	vf_extraSamples[1].xy = in_texcoord + (vec2(2.0, 0.0) * texelOffset);
	vf_extraSamples[1].zw = in_texcoord + (vec2(1.0, -1.0) * texelOffset);
	vf_extraSamples[2].xy = in_texcoord + (vec2(0.0, -2.0) * texelOffset);
	vf_extraSamples[2].zw = in_texcoord + (vec2(-1.0, -1.0) * texelOffset);
	vf_extraSamples[3].xy = in_texcoord + (vec2(-2.0, 0.0) * texelOffset);
	vf_extraSamples[3].zw = in_texcoord + (vec2(-1.0, 1.0) * texelOffset);
	
	vf_extraSamples[4].xy = in_texcoord + (vec2(0.0, 4.0) * texelOffset);
	vf_extraSamples[4].zw = in_texcoord + (vec2(3.0, 3.0) * texelOffset);
	vf_extraSamples[5].xy = in_texcoord + (vec2(4.0, 0.0) * texelOffset);
	vf_extraSamples[5].zw = in_texcoord + (vec2(3.0, -3.0) * texelOffset);
	vf_extraSamples[6].xy = in_texcoord + (vec2(0.0, -4.0) * texelOffset);
	vf_extraSamples[6].zw = in_texcoord + (vec2(-3.0, -3.0) * texelOffset);
	vf_extraSamples[7].xy = in_texcoord + (vec2(-4.0, 0.0) * texelOffset);
	vf_extraSamples[7].zw = in_texcoord + (vec2(-3.0, 3.0) * texelOffset);
}