#version 330 core

#define MAX_DPL 1024

struct plane
{
	vec3 vsNormal;
	float d;
};

layout(location = 0) in vec3 in_ndcPosition;
layout(location = 1) in vec2 in_texcoord;

out vec2 vf_texcoord;
out vec3 vsViewRay;
flat out int pointLCount;
flat out ivec4 pointLIndices[8];

uniform vec4 tilePosDimensions;
uniform vec3 mainFrustrumCBL;
uniform vec2 frustrumDimensions;
uniform vec2 numTiles;
uniform vec4 cullPlanes[4];

uniform samplerBuffer pLightPosition;
uniform samplerBuffer pLightAttenuation; //constant linear quadratic radius
uniform int numPLights;

plane getPlane(vec3 vsNorm, vec3 vsPoint)
{
	return plane(vsNorm, - dot(vsNorm, vsPoint));
}

float signedDistance(vec3 vsPos, plane cullPlane)
{
	return (dot(cullPlane.vsNormal, vsPos) + cullPlane.d);
}

void main()
{
	vec2 tileBL = tilePosDimensions.xy * tilePosDimensions.zw;
	vf_texcoord = tileBL + in_texcoord * tilePosDimensions.zw;
	gl_Position = vec4((tileBL + ((in_ndcPosition.xy + 1.0) / 2.0) * tilePosDimensions.zw) * 2.0 - 1.0, in_ndcPosition.z, 1.0);
	vsViewRay = vec3(mainFrustrumCBL.xy + (frustrumDimensions * vf_texcoord), mainFrustrumCBL.z);
	/*
	ivec2 tile = ivec2(tilePosDimensions.xy);
	vec3 frustC[4]; //00 10 11 01
	frustC[0] = vec3(mainFrustrumCBL.xy + (frustrumDimensions * (tile / numTiles)), mainFrustrumCBL.z);
	frustC[1] = vec3(mainFrustrumCBL.xy + (frustrumDimensions * (vec2(tile.x + 1, tile.y) / numTiles)), mainFrustrumCBL.z);
	frustC[2] = vec3(mainFrustrumCBL.xy + (frustrumDimensions * ((tile + vec2(1)) / numTiles)), mainFrustrumCBL.z);
	frustC[3] = vec3(mainFrustrumCBL.xy + (frustrumDimensions * (vec2(tile.x, tile.y + 1) / numTiles)), mainFrustrumCBL.z);
	*/
	plane frustrum[4]; //l r t d
	/*
	frustrum[0] = getPlane(normalize(cross(frustC[0], vec3(0.0, 1.0, 0.0))), frustC[0]);
	frustrum[1] = getPlane(normalize(cross(vec3(0.0, 1.0, 0.0), frustC[2])), frustC[2]);
	frustrum[2] = getPlane(normalize(cross(frustC[3], vec3(1.0, 0.0, 0.0))), frustC[3]);
	frustrum[3] = getPlane(normalize(cross(vec3(1.0, 0.0, 0.0), frustC[1])), frustC[1]);*/

	frustrum[0] = plane(cullPlanes[0].rgb, cullPlanes[0].w);
	frustrum[1] = plane(cullPlanes[1].rgb, cullPlanes[1].w);
	frustrum[2] = plane(cullPlanes[2].rgb, cullPlanes[2].w);
	frustrum[3] = plane(cullPlanes[3].rgb, cullPlanes[3].w);
	
	int pointLCountT = 0;
	for(int count = 0; count < numPLights; ++count)
	{
		bool temp = true;
		vec3 tempPos = texelFetch(pLightPosition, count).rgb;
		float tempRad = texelFetch(pLightAttenuation, count).w;
		for(int i = 0; i < 4; ++i)
		{
			if ((dot(frustrum[i].vsNormal, tempPos) + frustrum[i].d) < -tempRad)
			{
				temp = false;
			}
		}
		if (temp && pointLCountT < 64)
		{
			pointLIndices[pointLCountT / 4][pointLCountT % 4] = count;
			++pointLCountT;
		}
	}
	pointLCount = pointLCountT;
}