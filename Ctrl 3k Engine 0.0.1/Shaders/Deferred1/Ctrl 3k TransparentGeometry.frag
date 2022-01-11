#version 330 core

in vec3 wPosition;
in vec2 texcoord;
in vec4 tLightPos;
in vec4 tEyePos;
in vec4 tPosition;

uniform vec4 lightColour; //light's colour.

uniform vec4 materialEmissive;
uniform vec4 materialDiffuse;
uniform vec4 materialSpecular;
uniform float materialShininess;
uniform float materialSharpness;

uniform vec4 ambient;

uniform sampler2D diffuseSampler;
uniform sampler2D normalSampler;

layout(location = 0) out vec4 out_colour;

void main()
{
	//diffuse term.
	vec4 N = vec4(texture(normalSampler, texcoord).rgb, 0.0);
	N = normalize(N * 2.0 - 1.0);
	vec4 L = normalize(tLightPos - tPosition);
	float NdotL = max(dot(N, L), 0.0);
	vec4 diffuse = NdotL * lightColour * materialDiffuse;

	//specular term.
	vec4 V = normalize(tEyePos - tPosition);

	//vec4 R = reflect(-L, N); //Phong Lighting Model.
	//float RdotV = max(dot(R, V), 0.0);
	//vec4 specular = pow(RdotV, materialShininess) * lightColour * materialSpecular * materialSharpness;

	vec4 H = normalize(L + V); //Blinn-Phong Lighting Model.
	float NdotH = max(dot(N, H), 0.0);
	vec4 specular = pow(NdotH, materialShininess) * lightColour * materialSpecular * materialSharpness;
	
	out_colour = (materialEmissive + ambient + diffuse + specular) * texture(diffuseSampler, texcoord);
}