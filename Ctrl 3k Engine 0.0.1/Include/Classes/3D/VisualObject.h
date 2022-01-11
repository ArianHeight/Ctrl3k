#pragma once

/*

Visual Object

object class containing all necessary mesh, material, and textures for rendering a visible object

*/
class VisualObject
{
public:
	VisualObject(std::string &objectSourceFilePath, bool &success);
	virtual ~VisualObject();

public:
	std::string m_name;

	std::vector<TriMesh*> m_meshGroups;
	std::vector<int> m_materials;

	//glm::mat4 m_worldTransform{glm::vec4(0), glm::vec4(0), glm::vec4(0), glm::vec4(0, 0, 0, 1)};
};
/*

end Visual Object

*/