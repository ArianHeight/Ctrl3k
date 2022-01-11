#version 330 core

in vec2 vf_texcoord;
in vec3 vf_vsWorld;
in vec3 vf_vsNormal;
in mat3 vf_vsTBN;

//uniform float matID;

uniform sampler2D normalSampler;
uniform sampler2D displaceSampler;
uniform sampler2D diffuseSampler;

uniform float heightWeight = 0.05;
uniform bool parallaxMap;

//parallax occlusion mapping params
uniform float minSamples = 8.0;
uniform float maxSamples = 20.0;

layout(location = 0) out vec4 out_albedo;
layout(location = 1) out vec4 normalEnc;

vec2 parallaxOcclusionMap()
{
	vec3 view = normalize(transpose(vf_vsTBN) * (-vf_vsWorld));
	view.y *= -1;
	//view.z = max(view.z, 0.3) * (abs(view.z) / view.z);
	//view = normalize(view);
	
	float layers = mix(maxSamples, minSamples, abs(dot(vec3(0.0, 0.0, 1.0), view))); //adjust actual number of samples with steepness of viewing angle
	float layerDepth =  1.0 / layers;
	float currentDepth = 0.0;
	vec2 p = view.xy / view.z * heightWeight; //scaling "normal" (normalized to where z = 1)
	vec2 shiftCoord = p / layers; //amount to shift texcoord by

	vec2 currentCoord = vf_texcoord; //current texture coordinate 
	float currentMapDepth = 1.0 - texture(displaceSampler, currentCoord).r; //current depth in the displacement map
	while (currentDepth < currentMapDepth) //gets steep parallax mapping texcoords
	{
		currentCoord -= shiftCoord; //shift coordinates
		float currentMapDepth = 1.0 - texture(displaceSampler, currentCoord).r; //updates mapDepth value
		currentDepth += layerDepth; //next layer
	}

	//linear interpolation
	vec2 prevCoord = currentCoord + shiftCoord; //shifts back up one layer
	float firstDepth = 1.0 - texture(displaceSampler, prevCoord).r - currentDepth + layerDepth; //depth value before hitting target point relative to ITS sample layer (hence adding one layerDepth)
	float secondDepth = currentMapDepth - currentDepth; //depth value after hitting target point relative to its sample layer

	//texcoord interpolation
	float linearWeight = secondDepth / (secondDepth - firstDepth);
	vec2 interpolatedCoords = prevCoord * linearWeight + currentCoord * (1.0 - linearWeight);
	
	return interpolatedCoords;
	/*
	vec2 coord = vf_texcoord + view.xy / view.z * (heightWeight * texture(displaceSampler, vf_texcoord).r);
	return coord;*/
}

void main()
{
	vec3 vsNormal = vf_vsNormal;
	vec2 texcoord = vf_texcoord;

	if (parallaxMap)
	{
		texcoord = parallaxOcclusionMap(); //parallaxMaps
	}/*
	if (texcoord.x > 1.0 || texcoord.x < 0.0 || texcoord.y > 1.0 || texcoord.y < 0.0)
	{
		discard; //discard fragment if sampling outside texture
	}*/
	
	vsNormal = normalize(vf_vsTBN * (texture(normalSampler, texcoord).rgb * 2.0 - vec3(1.0))); //normal mapping

	vec4 enc = vec4(vsNormal.xy, 0.0, 0.0);
	enc.w = vsNormal.z < 0 ? -1.0 : 1.0;
	/*
	if (vf_vsNormal.z < 0)
	{
		enc.w = -1;
	}
	else
	{
		enc.w = 1;
	}*/
	normalEnc = (enc + vec4(1.0)) / 2.0;

	out_albedo = texture(diffuseSampler, texcoord); //missing ambient occlusion factor
}