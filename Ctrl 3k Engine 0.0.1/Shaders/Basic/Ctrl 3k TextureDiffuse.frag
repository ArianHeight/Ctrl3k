#version 330 core

//Position, Normal, and Texcoord from vertex shader.
in vec4 vf_wPosition;
in vec4 vf_wNormal;
in vec2 vf_texcoord;

uniform vec4 wEyePos; //eye's position in world space.

uniform vec4 wLightPos; //light's position in world space.
uniform vec4 lightColour; //light's colour.

uniform vec4 materialEmissive;
uniform vec4 materialDiffuse;
uniform vec4 materialSpecular;
uniform float materialShininess;
uniform float materialSharpness;

uniform vec4 ambient;

uniform sampler2D diffuseSampler;

layout(location = 0) out vec4 out_colour;

void main()
{
	//diffuse term.
	vec4 N = normalize(vf_wNormal);
	vec4 L = normalize(wLightPos - vf_wPosition);
	float NdotL = max(dot(N, L), 0);
	vec4 diffuse = NdotL * lightColour * materialDiffuse;

	//specular term.
	vec4 V = normalize(wEyePos - vf_wPosition);

	//vec4 R = reflect(-L, N); //Phong Lighting Model.
	//float RdotV = max(dot(R, V), 0);
	//vec4 specular = pow(RdotV, materialShininess) * lightColour * materialSpecular * materialSharpness;

	vec4 H = normalize(L + V); //Blinn-Phong Lighting Model.
	float NdotH = max(dot(N, H), 0);
	vec4 specular = pow(NdotH, materialShininess) * lightColour * materialSpecular * materialSharpness;
	
	out_colour = (materialEmissive + ambient + diffuse + specular) * texture(diffuseSampler, vf_texcoord);
}