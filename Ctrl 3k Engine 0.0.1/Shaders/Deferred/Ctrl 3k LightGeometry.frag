#version 330 core

#define MAX_DYNAMIC_POINT_LIGHTS 1024
//#define MAX_DPL_PER_TILE 32

//struct def
struct pointLight
{
	vec3 vsPos;
	vec3 attenuations; //constant, linear, quadratic
	float radius; //light's cutoff
	vec3 lightColour;
};

struct directionalLight
{
	vec3 vsNormal;
	vec4 lightColour;
	float intensity;
};

in vec2 vf_texcoord;
in vec3 vsViewRay;
flat in int pointLCount;
flat in ivec4 pointLIndices[8];

uniform float projectionConstantA; //f / (f - n)
uniform float projectionConstantB; //(-f * n) / (f - n)

uniform samplerBuffer pLightPos;
uniform samplerBuffer pLightAtt; //constant linear quadratic radius
uniform samplerBuffer pLightColour;

uniform vec4 dLightNC[2];
uniform bool dLight;
uniform mat4 dLightSpaceTrans;

uniform sampler2D specularShape;

uniform sampler2D dLightMap;

uniform sampler2D depthSampler;
uniform sampler2D normalSampler;

layout(location = 0) out vec4 out_diffuseAccumulation;
layout(location = 1) out vec4 out_specularAccumulation;

float calcShadows(vec4 fragLsPos, vec4 normal)
{
	vec3 coords = fragLsPos.xyz / fragLsPos.w;
	coords = coords * 0.5 + 0.5;
	float closest = texture(dLightMap, coords.xy).r;
	float current = coords.z;
	float bias = max(0.045 * (1.0 - dot(normal.xyz, dLightNC[0].xyz)), 0.004);
	float shadow = current - bias > closest ? 1.0 : 0.0;
	shadow = coords.z > 1.0 ? 0.0 : shadow;
	return shadow;
}

void calcLighting(vec4 normal, vec3 vsPosition, int ind)
{
	int count = 0;
	int temp;
	if (ind * 4 + count < pointLCount)
	{
		int index = pointLIndices[ind][count];
		pointLight currentLight = pointLight(texelFetch(pLightPos, index).rgb,texelFetch(pLightAtt, index).rgb, texelFetch(pLightAtt, index).a, texelFetch(pLightColour, index).rgb);
		vec3 lP = currentLight.vsPos - vsPosition;
		float distance = length(lP);

		temp = int(distance <= currentLight.radius);
		//diffuse term.
		vec3 N = normal.xyz;
		vec3 L = normalize(lP);
		float attenuation = 1.0 / (currentLight.attenuations.x + currentLight.attenuations.y * distance + currentLight.attenuations.z * distance * distance);
		float NdotL = max(dot(N, L), 0.0);
		out_diffuseAccumulation.rgb += NdotL * currentLight.lightColour * attenuation * temp;

		//specular term
		vec3 V = normalize(vec3(0.0) - vsPosition);
		vec3 R = reflect(-L, N); //Phong Lighting Model.
		float RdotV = 1.0 - acos(max(dot(R, V), 0.0)) / 1.570796;

		out_specularAccumulation.rgb += texture(specularShape, vec2(1.0 - RdotV, 0.8)).rgb * currentLight.lightColour * attenuation * temp;
	}
	count = 1;
	if (ind * 4 + count < pointLCount)
	{
		int index = pointLIndices[ind][count];
		pointLight currentLight = pointLight(texelFetch(pLightPos, index).rgb,texelFetch(pLightAtt, index).rgb, texelFetch(pLightAtt, index).a, texelFetch(pLightColour, index).rgb);
		vec3 lP = currentLight.vsPos - vsPosition;
		float distance = length(lP);

		temp = int(distance <= currentLight.radius);
		//diffuse term.
		vec3 N = normal.xyz;
		vec3 L = normalize(lP);
		float attenuation = 1.0 / (currentLight.attenuations.x + currentLight.attenuations.y * distance + currentLight.attenuations.z * distance * distance);
		float NdotL = max(dot(N, L), 0.0);
		out_diffuseAccumulation.rgb += NdotL * currentLight.lightColour * attenuation * temp;

		//specular term
		vec3 V = normalize(vec3(0.0) - vsPosition);
		vec3 R = reflect(-L, N); //Phong Lighting Model.
		float RdotV = 1.0 - acos(max(dot(R, V), 0.0)) / 1.570796;

		out_specularAccumulation.rgb += texture(specularShape, vec2(1.0 - RdotV, 0.8)).rgb * currentLight.lightColour * attenuation * temp;
	}
	count = 2;
	if (ind * 4 + count < pointLCount)
	{
		int index = pointLIndices[ind][count];
		pointLight currentLight = pointLight(texelFetch(pLightPos, index).rgb,texelFetch(pLightAtt, index).rgb, texelFetch(pLightAtt, index).a, texelFetch(pLightColour, index).rgb);
		vec3 lP = currentLight.vsPos - vsPosition;
		float distance = length(lP);

		temp = int(distance <= currentLight.radius);
		//diffuse term.
		vec3 N = normal.xyz;
		vec3 L = normalize(lP);
		float attenuation = 1.0 / (currentLight.attenuations.x + currentLight.attenuations.y * distance + currentLight.attenuations.z * distance * distance);
		float NdotL = max(dot(N, L), 0.0);
		out_diffuseAccumulation.rgb += NdotL * currentLight.lightColour * attenuation * temp;

		//specular term
		vec3 V = normalize(vec3(0.0) - vsPosition);
		vec3 R = reflect(-L, N); //Phong Lighting Model.
		float RdotV = 1.0 - acos(max(dot(R, V), 0.0)) / 1.570796;

		out_specularAccumulation.rgb += texture(specularShape, vec2(1.0 - RdotV, 0.8)).rgb * currentLight.lightColour * attenuation * temp;
	}
	count = 3;
	if (ind * 4 + count < pointLCount)
	{
		int index = pointLIndices[ind][count];
		pointLight currentLight = pointLight(texelFetch(pLightPos, index).rgb,texelFetch(pLightAtt, index).rgb, texelFetch(pLightAtt, index).a, texelFetch(pLightColour, index).rgb);
		vec3 lP = currentLight.vsPos - vsPosition;
		float distance = length(lP);

		temp = int(distance <= currentLight.radius);
		//diffuse term.
		vec3 N = normal.xyz;
		vec3 L = normalize(lP);
		float attenuation = 1.0 / (currentLight.attenuations.x + currentLight.attenuations.y * distance + currentLight.attenuations.z * distance * distance);
		float NdotL = max(dot(N, L), 0.0);
		out_diffuseAccumulation.rgb += NdotL * currentLight.lightColour * attenuation * temp;

		//specular term
		vec3 V = normalize(vec3(0.0) - vsPosition);
		vec3 R = reflect(-L, N); //Phong Lighting Model.
		float RdotV = 1.0 - acos(max(dot(R, V), 0.0)) / 1.570796;

		out_specularAccumulation.rgb += texture(specularShape, vec2(1.0 - RdotV, 0.8)).rgb * currentLight.lightColour * attenuation * temp;
	}
}

void calcDirectionalLighting(vec4 normal, vec3 vsPos)
{
	if (dLight)
	{		
		float shadow = 1.0 - calcShadows(dLightSpaceTrans * vec4(vsPos, 1.0), normal);

		//diffuse term.
		vec3 N = normal.xyz;
		vec3 L = -dLightNC[0].xyz;
		float NdotL = max(dot(N, L), 0.0);
		out_diffuseAccumulation.rgb += shadow * NdotL * dLightNC[1].rgb;

		//specular term
		vec3 V = normalize(vec3(0.0) - vsPos);
		vec3 R = reflect(-L, N); //Phong Lighting Model.
		float RdotV = 1.0 - acos(max(dot(R, V), 0.0)) / 1.570796;

		out_specularAccumulation.rgb += shadow * texture(specularShape, vec2(1.0 - RdotV, 0.8)).rgb * dLightNC[1].rgb;
	}
}

void doCalculations(float depth)
{
	depth = projectionConstantB / (depth - projectionConstantA);
	vec3 vsPosition = vsViewRay * depth;
	//vsPosition.z *= -1;

	vec4 normal = texture(normalSampler, vf_texcoord) * 2.0 - vec4(1.0);
	normal.z = sqrt(1.0 - pow(normal.x, 2.0) - pow(normal.y, 2.0));
	normal.z = max(normal.z, 0.0) * normal.w;
	normal.w = 0.0;
	normal = normalize(normal);

	out_diffuseAccumulation = vec4(0.09, 0.09, 0.09, 1.0);
	out_specularAccumulation = vec4(0.0, 0.0, 0.0, 1.0);
	calcDirectionalLighting(normal, vsPosition);
	int index;
	index = 0;
	calcLighting(normal, vsPosition, index);
	index = 1;
	calcLighting(normal, vsPosition, index);
	index = 2;
	calcLighting(normal, vsPosition, index);
	index = 3;
	calcLighting(normal, vsPosition, index);
	index = 4;
	calcLighting(normal, vsPosition, index);
	index = 5;
	calcLighting(normal, vsPosition, index);
	index = 6;
	calcLighting(normal, vsPosition, index);
	index = 7;
	calcLighting(normal, vsPosition, index);
	index = 8;
	/*
	calcLighting(normal, vsPosition, index);
	index = 9;
	calcLighting(normal, vsPosition, index);
	index = 10;
	calcLighting(normal, vsPosition, index);
	index = 11;
	calcLighting(normal, vsPosition, index);*/
}

void main()
{	
	float depth = texture(depthSampler, vf_texcoord).r;
	if (depth == 1.0)
	{
		discard;
	}
	else
	{
		doCalculations(depth);
	}
}