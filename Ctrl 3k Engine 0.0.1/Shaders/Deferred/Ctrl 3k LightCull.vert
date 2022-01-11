#version 430 core

//struct def
struct pointLight
{
	vec3 vsPos;
	vec3 attenuations;
	float radius;
	vec4 lightColour;
};

struct directionalLight
{
	vec3 vsNormal;
	vec4 lightColour;
};

struct plane
{
	vec3 vsNormal;
	float d;
}

//more setup stuff
uniform vec2 windowDimensions;
uniform vec4 lightColour; //light's colour.
uniform vec4 vsLightPos; //light's position.
uniform vec4 vsEyePos = vec4(0.0, 0.0, 0.0, 1.0);

uniform float projectionConstantA; //f / (f - n)
uniform float projectionConstantB; //(-f * n) / (f - n)

uniform sampler2D depthSampler;
uniform sampler2D normalSampler;

uniform uint numOfPointLights;
uniform pointLight pLights[];
uniform bool numOfDirectionalLights;
uniform directionalLight dLight;

uniform vec3 mainFrustrumBL; //bottom left corner of main frustrum clipped to z = 1
uniform vec2 mainFrustrumXY; //length width of main frustrum
uniform float minDepth;

layout(local_size_variable) in; //16 x 16 x 1

layout(binding = 0, rgba8) uniform writeonly out_diffuseAccumulation;
layout(binding = 0, rgba8) uniform writeonly out_specularAccumulation;

layout(shared) float maxDepth = 0.0;
layout(shared) plane tileFrustrum[6]; //front back left right top bottom(front being closer to camera)
layout(shared) uint pointIndices[numOfPointLights];

plane getPlane(vec3 vsNorm, vec3 vsPoint)
{
	return plane(vsNorm, - dot(vsNorm, vsPoint));
}

vec3 getNormal(vec3 a, vec3 b, vec3 c)
{
	return cross(a - b, c - b);
}

void main()
{
	//basic stuff
	ivec2 pixel = ivec2(gl_GlobalInvocationID.xy);
	vec2 tile = vec2(gl_WorkGroupID / gl_NumWorkGroups); //range 0 1 bottom left corner of tile
	
	vec3 vsViewRay = vec3(mainFrustrumBL.xy + mainFrustrumXY * (vec2(pixel) / windowDimensions), mainFrustrumBL.z);
	vec2 vf_texcoord = float(pixel) / float(windowDimensions);

	//gets vsPosition and vsNormals
	float depth = texture(depthSampler, vf_texcoord).r;
	depth = projectionConstantB / (depth - projectionConstantA);
	vec4 vsPosition = vec4(vsViewRay * depth, 1.0);
	vsPosition.z *= -1;
	maxDepth = max(maxDepth, depth);

	vec4 normal = texture(normalSampler, vf_texcoord) * 2.0 - 1.0;
	normal.z = sqrt(1.0 - pow(normal.x, 2) - pow(normal.y, 2)) * normal.w;
	normal.w = 0.0;
	
	//diffuse term.
	vec4 N = normalize(normal);
	vec4 L = normalize(vsLightPos - vsPosition);
	float NdotL = max(dot(N, L), 0.0);
	out_diffuseAccumulation = NdotL * lightColour;

	//specular term
	vec4 V = normalize(vsEyePos - vsPosition);
	vec4 H = normalize(L + V); //Blinn-Phong Lighting Model.
	float NdotH = 1.0 - acos(max(dot(N, H), 0.0)) / 1.570796;
	out_specularAccumulation = texture(specularShape, vec2(1.0 - NdotH, 0.36)) * lightColour;
	
	/*
	memory_barrier_shared();
	barrier();
	//splits image into tiles and calculates frustrum equations for each
	tileFrustrum[0] = getPlane(vec3(0.0, 0.0, -1.0), vec3(0.0, 0.0, minDepth));
	tileFrustrum[1] = getPlane(vec3(0.0, 0.0, 1.0), vec3(0.0, 0.0, maxDepth));
	vec3 fourCorners[4]; //clipped to z = 1(bl, br, tr, tl)
	fourCorners[0] = vec3(mainFrustrumBL.xy + mainFrustrumXY * (tile / windowDimensions), 1.0);
	fourCorners[1] = vec3(mainFrustrumBL.xy + mainFrustrumXY * ((tile + vec2(uvec2(gl_WorkGroupID.x + 1, gl_WorkGroupID.y) / gl_NumWorkGroups))/ windowDimensions), 1.0);
	fourCorners[2] = vec3(mainFrustrumBL.xy + mainFrustrumXY * ((tile + vec2(gl_WorkGroupID + uvec2(1) / gl_NumWorkGroups))/ windowDimensions), 1.0);
	fourCorners[3] = vec3(mainFrustrumBL.xy + mainFrustrumXY * ((tile + vec2(uvec2(gl_WorkGroupID.x, gl_WorkGroupID.y + 1) / gl_NumWorkGroups))/ windowDimensions), 1.0);
	
	
	memory_barrier_shared();
	barrier();
	//culls lights to each frustrum;
	
	memory_barrier_shared();
	barrier();
	//performs lighting equations in indivdual tiles and writes to out buffer
	*/
}