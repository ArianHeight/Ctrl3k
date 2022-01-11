#version 330 core

in vec2 vf_texcoord;

uniform sampler2D diffuseAccumulation;
uniform sampler2D specularAccumulation;

uniform sampler2D albedoSampler;

uniform float overExposedThreshold = 1.0; //threshold for what gets drawn onto the over_exposure buffer

layout(location = 0) out vec4 out_colour;
layout(location = 1) out vec4 over_exposed;

void main()
{
	vec4 albedoColour = texture(albedoSampler, vf_texcoord);
	vec4 specularColour = vec4(1.0);
	specularColour = vec4((albedoColour.rgb * specularColour.a) + specularColour.rgb, 1.0);
	
	vec4 diffuseContribution = vec4(texture(diffuseAccumulation, vf_texcoord).rgb * albedoColour.a * albedoColour.rgb, 1.0);
	vec4 specularContribution = texture(specularAccumulation, vf_texcoord) * specularColour;

	out_colour = diffuseContribution + specularContribution;

	vec3 luma = vec3(0.299, 0.587, 0.114);
	float lumanosity = dot(out_colour.rgb, luma);
	over_exposed = vec4(out_colour.rgb * (lumanosity > overExposedThreshold ? 1.0 : 0.0), 1.0);
}