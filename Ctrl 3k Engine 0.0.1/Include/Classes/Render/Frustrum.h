#pragma once

//Frustrum class for view culling **MUST BE FRIEND CLASS OF CAMERA!!!!
class Frustrum
{
public:
	Frustrum(Camera &cam);
	virtual ~Frustrum();

private:
	int *cam_fov;
	float *cam_aspectRatio, *cam_nearDist, *cam_farDist;
	glm::vec3 *cam_direction, *cam_right, *cam_top;

	glm::vec3 tempDir; //as temporary direcitonal vector for plane calculation

	float m_nearWidth_2, m_nearHeight_2, m_farWidth_2, m_farHeight_2;
	float m_nearWidth, m_nearHeight, m_farWidth, m_farHeight;
	glm::vec3 m_centerPoints[2] = {
		glm::vec3(), // 0 = near center
		glm::vec3()  // 1 = far center
	};

	glm::vec3 m_points[8] = {
		glm::vec3(), // 0 = Far Top Right
		glm::vec3(), // 1 = Far Top Left
		glm::vec3(), // 2 = Far Bottom Left
		glm::vec3(), // 3 = Far Bottom Right
		glm::vec3(), // 3 = Near Top Right
		glm::vec3(), // 4 = Near Top Left
		glm::vec3(), // 5 = Near Bottom Left
		glm::vec3()  // 6 = Near Bottom Right
	};

	Plane m_cullPlanes[6] = {
		{ glm::vec3(), glm::vec3() }, // 0 = near plane
		{ glm::vec3(), glm::vec3() }, // 1 = far plane
		{ glm::vec3(), glm::vec3() }, // 2 = left plane
		{ glm::vec3(), glm::vec3() }, // 3 = right plane
		{ glm::vec3(), glm::vec3() }, // 4 = top plane
		{ glm::vec3(), glm::vec3() }  // 5 = bottom plane
	};

public:
	void changeFrustrumDimensions(); //updates frustrum dimensions and calls updateFrustrum()
	void updatePoints(); //updates points and planes
	void updatePlanes(); //updates planes only
	void updateTiledPlanes();
	void cullPointLights(std::vector<pointLight> &lights, std::vector<glm::vec4> &lightVsPos, std::vector<glm::vec4> &outPos, std::vector<glm::vec4> &outAtt, std::vector<glm::vec4> &outColour);
	void getFarPoints(glm::vec3 *in);
	//void cullTiledPL(int i, int j, std::vector<glm::vec4> &lightVsPos, std::vector<glm::vec4> &lightAtt, std::vector<glm::vec4> &lightColour, std::vector<glm::vec4> &outPos, std::vector<glm::vec4> &outAtt, std::vector<glm::vec4> &outColour);

	//std::vector<std::vector<std::vector<Plane>>> m_tiledPlanes[32][16][4];
	Plane m_tiledPlanes[32][16][4]; //x, y, left right top bottom

	float m_longestDistance;
};
//end Frustrum Class