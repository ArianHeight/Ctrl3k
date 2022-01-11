#pragma once

class Material
{
	friend class TriMesh;
	friend class VisualObject;
public:
	Material(std::string &name);
	virtual ~Material();

public:

	bool requestFile(std::string &fileName, int map);
	void fillFiles(std::string &materialSourceFilePath);

	std::string m_name;

	glm::vec4 m_ambient;
	glm::vec4 m_diffuse;
	glm::vec4 m_specular;
	glm::vec4 m_emissive;
	float m_shininess;

	glm::vec3 m_transmissionFilter;
	float m_sharpness;
	float m_dissolve;
	bool m_dissolveHalo;
	float m_opticalDensity;

	illum m_illuminationModel; //ambient, diffuse, specular, shininess, dissolve, displacement, decal, bump, reflection
	/*
	std::string m_ambientMapPath; //0
	std::string m_diffuseMapPath; //1
	std::string m_specularMapPath; //2
	std::string m_shininessMapPath; //3
	std::string m_dissolveMapPath; //4
	std::string m_displacementMapPath; //5
	std::string m_decalMapPath; //6
	std::string m_bumpMapPath; //7
	std::string m_reflectionMapPath; //8
	*/
	GLint m_maps[9]{-1, -1, -1, -1, -1, -1, -1, -1, -1};
	std::string mapPaths[9];
};