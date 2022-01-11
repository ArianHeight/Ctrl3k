#include <Ctrl 3kPCH.h>
#include <classes/Render/Frustrum.h>

/*

Frustrum Class
for view culling

*/
Frustrum::Frustrum(Camera &cam)
{
	//cstr
	this->cam_fov = &cam.m_fov;
	this->cam_aspectRatio = cam.aspectRatio;
	this->cam_nearDist = &cam.m_renderN;
	this->cam_farDist = &cam.m_renderF;

	this->cam_direction = &cam.m_direction;
	this->cam_right = &cam.m_right;
	this->cam_top = &cam.m_top;

	this->changeFrustrumDimensions();
}

void Frustrum::changeFrustrumDimensions()
{
	float tangent = (float)tan(glm::radians(*this->cam_fov * 0.5f)); //tan ratio of half angle of field of view

	this->m_nearHeight_2 = *this->cam_nearDist * tangent;
	this->m_nearWidth_2 = this->m_nearHeight_2 * *this->cam_aspectRatio;
	this->m_farHeight_2 = *this->cam_farDist * tangent;
	this->m_farWidth_2 = this->m_farHeight_2 * *this->cam_aspectRatio;

	this->m_nearHeight = this->m_nearHeight_2 * 2;
	this->m_nearWidth = this->m_nearWidth_2 * 2;
	this->m_farHeight = this->m_farHeight_2 * 2;
	this->m_farWidth = this->m_farWidth_2 * 2;

	this->updatePoints();
}

void Frustrum::updatePoints()
{
	this->m_centerPoints[0] = glm::vec3(0, 0, -1) * *this->cam_nearDist; //near center
	this->m_centerPoints[1] = glm::vec3(0, 0, -1) * *this->cam_farDist; //far center

	this->m_points[0] = this->m_centerPoints[1] + (glm::vec3(0, 1, 0) * this->m_farHeight_2) + (glm::vec3(-1, 0, 0) * (-this->m_farWidth_2)); //FarTopLeft
	this->m_points[1] = this->m_points[0] + (glm::vec3(-1, 0, 0) * this->m_farWidth); //FarTopRight
	this->m_points[2] = this->m_points[1] + (glm::vec3(0, 1, 0) * (-this->m_farHeight)); //FarBottomRight
	this->m_points[3] = this->m_points[0] + (glm::vec3(0, 1, 0) * (-this->m_farHeight)); //FarBottomLeft

	this->m_points[4] = this->m_centerPoints[0] + (glm::vec3(0, 1, 0) * this->m_nearHeight_2) + (glm::vec3(-1, 0, 0) * (-this->m_nearWidth_2)); //NearTopLeft
	this->m_points[5] = this->m_points[4] + (glm::vec3(-1, 0, 0) * this->m_nearWidth); //NearTopRight
	this->m_points[6] = this->m_points[5] + (glm::vec3(0, 1, 0) * (-this->m_nearHeight)); //NearBottomRight
	this->m_points[7] = this->m_points[4] + (glm::vec3(0, 1, 0) * (-this->m_nearHeight)); //NearBottomLeft

	glm::vec3 distanceVector = this->m_points[0] - this->m_points[6];
	this->m_longestDistance = sqrt(pow(distanceVector[0], 2) + pow(distanceVector[1], 2) + pow(distanceVector[2], 2));

	this->updatePlanes();
}

void Frustrum::updatePlanes()
{
	this->m_cullPlanes[0] = { glm::vec3(0, 0, -1), this->m_centerPoints[0] }; //Near Plane
	this->m_cullPlanes[0].m_D = -glm::dot(this->m_cullPlanes[0].m_normal, this->m_cullPlanes[0].m_point);

	this->m_cullPlanes[1] = { glm::vec3(0, 0, 1), this->m_centerPoints[1] }; //Far Plane
	this->m_cullPlanes[1].m_D = -glm::dot(this->m_cullPlanes[1].m_normal, this->m_cullPlanes[1].m_point);

	//this->tempDir = glm::normalize(glm::cross((this->m_points[3] - this->m_points[7]), (this->m_points[4] - this->m_points[7]))); //Left Plane
	this->tempDir = glm::normalize(glm::cross(this->m_points[2], glm::vec3(0.0, 1.0, 0.0))); //Left Plane
	this->m_cullPlanes[2] = { this->tempDir, this->m_points[2] };
	this->m_cullPlanes[2].m_D = -glm::dot(this->m_cullPlanes[2].m_normal, this->m_cullPlanes[2].m_point);

	//this->tempDir = glm::normalize(glm::cross((this->m_points[6] - this->m_points[2]), (this->m_points[1] - this->m_points[2]))); //Right Plane
	this->tempDir = glm::normalize(glm::cross(glm::vec3(0.0, 1.0, 0.0), this->m_points[0])); //Right Plane
	this->m_cullPlanes[3] = { this->tempDir, this->m_points[0] };
	this->m_cullPlanes[3].m_D = -glm::dot(this->m_cullPlanes[3].m_normal, this->m_cullPlanes[3].m_point);

	//this->tempDir = glm::normalize(glm::cross((this->m_points[1] - this->m_points[0]), (this->m_points[4] - this->m_points[0]))); //Top Plane
	this->tempDir = glm::normalize(glm::cross(this->m_points[1], glm::vec3(1.0, 0.0, 0.0))); //Top Plane
	this->m_cullPlanes[4] = { this->tempDir, this->m_points[1] };
	this->m_cullPlanes[4].m_D = -glm::dot(this->m_cullPlanes[4].m_normal, this->m_cullPlanes[4].m_point);

	//this->tempDir = glm::normalize(glm::cross((this->m_points[2] - this->m_points[7]), (this->m_points[6] - this->m_points[7]))); //Bottom Plane
	this->tempDir = glm::normalize(glm::cross(glm::vec3(1.0, 0.0, 0.0), this->m_points[3])); //Bottom Plane
	this->m_cullPlanes[5] = { this->tempDir, this->m_points[3] };
	this->m_cullPlanes[5].m_D = -glm::dot(this->m_cullPlanes[5].m_normal, this->m_cullPlanes[5].m_point);

	this->updateTiledPlanes();
}

void Frustrum::updateTiledPlanes()
{
	glm::vec3 bottomLeft = this->m_points[2];
	bottomLeft /= bottomLeft.z;
	bottomLeft *= -1;
	glm::vec3 temp[2];
	temp[0] = this->m_points[3];
	temp[1] = this->m_points[1];
	for (int i = 0; i < 2; ++i)
	{
		temp[i] /= temp[i].z;
		temp[i] *= -1;
	}
	glm::vec2 dimensions = glm::vec2(temp[0].x - bottomLeft.x, temp[1].y - bottomLeft.y);
	glm::vec3 frust[4];
	for (int i = 0; i < 32; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			frust[0] = glm::vec3(glm::vec2(bottomLeft.x, bottomLeft.y) + (dimensions * (glm::vec2(i, j) / glm::vec2(32, 16))), bottomLeft.z);
			frust[1] = glm::vec3(glm::vec2(bottomLeft.x, bottomLeft.y) + (dimensions * (glm::vec2(i + 1, j) / glm::vec2(32, 16))), bottomLeft.z);
			frust[2] = glm::vec3(glm::vec2(bottomLeft.x, bottomLeft.y) + (dimensions * ((glm::vec2(i, j) + glm::vec2(1)) / glm::vec2(32, 16))), bottomLeft.z);
			frust[3] = glm::vec3(glm::vec2(bottomLeft.x, bottomLeft.y) + (dimensions * (glm::vec2(i, j + 1) / glm::vec2(32, 16))), bottomLeft.z);

			this->m_tiledPlanes[i][j][0].m_normal = glm::normalize(glm::cross(frust[0], glm::vec3(0.0, 1.0, 0.0)));
			this->m_tiledPlanes[i][j][0].m_point = frust[0];
			this->m_tiledPlanes[i][j][0].m_D = -glm::dot(this->m_tiledPlanes[i][j][0].m_normal, this->m_tiledPlanes[i][j][0].m_point);

			this->m_tiledPlanes[i][j][1].m_normal = glm::normalize(glm::cross(glm::vec3(0.0, 1.0, 0.0), frust[2]));
			this->m_tiledPlanes[i][j][1].m_point = frust[2];
			this->m_tiledPlanes[i][j][1].m_D = -glm::dot(this->m_tiledPlanes[i][j][1].m_normal, this->m_tiledPlanes[i][j][1].m_point);

			this->m_tiledPlanes[i][j][2].m_normal = glm::normalize(glm::cross(frust[3], glm::vec3(1.0, 0.0, 0.0)));
			this->m_tiledPlanes[i][j][2].m_point = frust[3];
			this->m_tiledPlanes[i][j][2].m_D = -glm::dot(this->m_tiledPlanes[i][j][2].m_normal, this->m_tiledPlanes[i][j][2].m_point);

			this->m_tiledPlanes[i][j][3].m_normal = glm::normalize(glm::cross(glm::vec3(1.0, 0.0, 0.0), frust[1]));
			this->m_tiledPlanes[i][j][3].m_point = frust[1];
			this->m_tiledPlanes[i][j][3].m_D = -glm::dot(this->m_tiledPlanes[i][j][3].m_normal, this->m_tiledPlanes[i][j][3].m_point);
		}
	}
}

void Frustrum::getFarPoints(glm::vec3 *in)
{
	in[0] = this->m_points[0];
	in[1] = this->m_points[1];
	in[2] = this->m_points[2];
	in[3] = this->m_points[3];
}

void Frustrum::cullPointLights(std::vector<pointLight> &lights, std::vector<glm::vec4> &lightVsPos, std::vector<glm::vec4> &outPos, std::vector<glm::vec4> &outAtt, std::vector<glm::vec4> &outColour)
{
	int size = lights.size();
	bool temp;
	float tempRad;
	float tempDist;
	glm::vec3 tempPos;
	for (int i = 0; i < size; ++i)
	{
		temp = true;
		tempRad = lights[i].attenuations.w;
		tempPos = glm::vec3(lightVsPos[i]);
		for (int count = 0; count < 6; ++count)
		{
			tempDist = glm::dot(this->m_cullPlanes[count].m_normal, tempPos) + this->m_cullPlanes[count].m_D;
			if (tempDist < -tempRad)
			{
				temp = false;
			}
		}
		if (temp)
		{
			outPos.push_back(lightVsPos[i]);
			outAtt.push_back(lights[i].attenuations);
			outColour.push_back(lights[i].lightColour);
		}
	}
}
/*
void Frustrum::cullTiledPL(int i, int j, std::vector<glm::vec4> &lightVsPos, std::vector<glm::vec4> &lightAtt, std::vector<glm::vec4> &lightColour, std::vector<glm::vec4> &outPos, std::vector<glm::vec4> &outAtt, std::vector<glm::vec4> &outColour)
{
	glm::vec3 tempLightPos;
	float tempLightRadius;
	float tempDist;
	bool temp;
	int size = lightVsPos.size();
	for (int count = 0; count < size; ++count)
	{
		tempLightPos = glm::vec3(lightVsPos[count]);
		tempLightRadius = lightAtt[count].z;
		temp = true;

		for (int c = 0; c < 4; ++c)
		{
			tempDist = glm::dot(this->m_tiledPlanes[i][j][c].m_normal, tempLightPos) + this->m_tiledPlanes[i][j][c].m_D;
			if (tempDist < -tempLightRadius);
			{
				temp = false;
			}
		}

		if (temp)
		{
			outPos.push_back(lightVsPos[count]);
			outAtt.push_back(lightAtt[count]);
			outColour.push_back(lightColour[count]);
		}
	}
}
*/
Frustrum::~Frustrum()
{
	//dstr
}
/*

end Frustrum Class

*/
