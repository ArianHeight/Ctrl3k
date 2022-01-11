#pragma once

struct VertexXYZColour //struct for storing interleaved vertex data arrays
{
	glm::vec3 m_pos; //position of vertex
	glm::vec3 m_colour; //colour of vertex
};

struct Plane //struct for plane object for view frustrum culling
{
	glm::vec3 m_normal; //direction of plane
	glm::vec3 m_point; //point on the plane
	float m_D; //D = -m_normal dot m_point
};

struct Texture
{
	Texture(std::string& name, GLuint texture) : m_name(name), m_texture(texture) {};
	std::string m_name; //name of the file
	GLuint m_texture; //openGL texture ID
};

struct pointLight
{
	glm::vec4 wPos;
	glm::vec4 attenuations; //constant, linear, quadratic, radius(light's cutoff)
	glm::vec4 lightColour;
};

struct directionalLight
{
	glm::vec4 wNormal; //front
	glm::vec4 wTangent; //right
	glm::vec4 lightColour;
};

enum class illum : int //namespace illum used for illumination modelling
{
	COLOUR_ON_AMBIENT_OFF, //0
	COLOUR_ON_AMBIENT_ON, //1
	HIGHLIGHT_ON, //2
	REFLECTION_ON_RAYTRACE_ON, //3
	TRANSPARENCY_GLASS_ON_REFLECTION_RAYTRACE_ON, //4
	REFLECTION_FRESNEL_ON_RAYTRACE_ON, //5
	TRANSPARENCY_REFRACTION_ON_REFLECTION_FRESNEL_OFF_RAYTRACE_ON, //6
	TRANSPARENCY_REFRACTION_ON_REFLECTION_FRESNEL_ON_RAYTRACE_ON, //7
	REFLECTION_ON_RAYTRACE_OFF, //8
	TRANSPARENCY_GLASS_ON_REFLECTION_RAYTRACE_OFF, //9
	CAST_SHADOWS_ON_INVISIBLE_SURFACES //10
};