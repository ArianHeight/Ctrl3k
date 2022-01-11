#version 330 core

in vec2 vf_texcoord;
in vec4 vf_extraSamples[8];

uniform sampler2D depthTexture;

uniform float projectionConstantA; //f / (f - n)
uniform float projectionConstantB; //(-f * n) / (f - n)

layout(location = 0) out vec4 out_colour;

float linearizeDepth(float depth)
{
	return (projectionConstantB / (depth - projectionConstantA));
}

void main()
{
	//ratios
	float nearFactor = 0.7;
	float farFactor = 1.0 - nearFactor;
	
	//base
	float pixelDepth = linearizeDepth(texture2D(depthTexture, vf_texcoord).r);
	
	//near
	float NTDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[0].xy).r);
	float NTRDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[0].zw).r);
	float NRDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[1].xy).r);
	float NBRDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[1].zw).r);
	float NBDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[2].xy).r);
	float NBLDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[2].zw).r);
	float NLDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[3].xy).r);
	float NTLDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[3].zw).r);
	
	//far
	float FTDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[4].xy).r);
	float FTRDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[4].zw).r);
	float FRDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[5].xy).r);
	float FBRDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[5].zw).r);
	float FBDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[6].xy).r);
	float FBLDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[6].zw).r);
	float FLDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[7].xy).r);
	float FTLDepth = linearizeDepth(texture2D(depthTexture, vf_extraSamples[7].zw).r);
	
	//calc
	float totalOcclusion = 0.0;
	float occluding = 0.0;
	
	occluding += NTDepth <= pixelDepth ? 1.0, 0.0;
	occluding += NTRDepth <= pixelDepth ? 1.0, 0.0;
	occluding += NRDepth <= pixelDepth ? 1.0, 0.0;
	occluding += NBRDepth <= pixelDepth ? 1.0, 0.0;
	occluding += NBDepth <= pixelDepth ? 1.0, 0.0;
	occluding += NBLDepth <= pixelDepth ? 1.0, 0.0;
	occluding += NLDepth <= pixelDepth ? 1.0, 0.0;
	occluding += NTLDepth <= pixelDepth ? 1.0, 0.0;
	occluding /= 8.0;
	
	totalOcclusion += (occluding * nearFactor);
	occluding = 0.0;
	
	occluding += FTDepth <= pixelDepth ? 1.0, 0.0;
	occluding += FTRDepth <= pixelDepth ? 1.0, 0.0;
	occluding += FRDepth <= pixelDepth ? 1.0, 0.0;
	occluding += FBRDepth <= pixelDepth ? 1.0, 0.0;
	occluding += FBDepth <= pixelDepth ? 1.0, 0.0;
	occluding += FBLDepth <= pixelDepth ? 1.0, 0.0;
	occluding += FLDepth <= pixelDepth ? 1.0, 0.0;
	occluding += FTLDepth <= pixelDepth ? 1.0, 0.0;
	occluding /= 8.0;
	
	totalOcclusion += (occluding * farFactor);
	
	out_colour.r = totalOcclusion;
}