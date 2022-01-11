#pragma once

/*


Includes:

Cube

*/

//A simple solid cube
class Cube
{
	friend TriMesh;
public:
	Cube(
			bool cStatic = true,
			glm::vec3 position = {0.0f, 0.0f, 0.0f},
			glm::quat rotation = {0.5f, 0.0f, 0.0f, 0.0f},
			float scale = 1.0f
			);
	virtual ~Cube();
	
	int m_mesh = 0;

	void initWorld();
	void updateWorld();

	glm::mat4 getWorld();

private:
	const std::string m_name = "cube";
	bool m_static;
	glm::vec4 m_position = glm::vec4(); //Center of cube
	glm::quat m_rotation = glm::quat();
	float m_scale = float(1.0f);
	glm::mat4 m_posTrans = glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, 1, 0, 0), glm::vec4(0, 0, 1, 0), glm::vec4(0, 0, 0, 1)); //translational matrix

	glm::mat4 m_world = glm::mat4(glm::vec4(0, 0, 0, 0), glm::vec4(0, 0, 0, 0), glm::vec4(0, 0, 0, 0), glm::vec4(0, 0, 0, 1)); //world transform matrix

};