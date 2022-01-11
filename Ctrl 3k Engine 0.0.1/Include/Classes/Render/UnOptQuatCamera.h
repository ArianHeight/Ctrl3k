#pragma once

/*

Unoptimized  Quaternion-Based Camera

able to calculate rotation on all 3 axis

*/
class UnOptQuatCamera : public Camera
{
public:
	UnOptQuatCamera(
		bool fly, 
		glm::quat rotation = { 1, 0, 0, 0 },
		glm::vec3 position = { 0, 0, 0 },
		int sensitivity = 1,
		int fov = 45,
		float renderF = 500.0f,
		float renderN = 0.2f);
	virtual ~UnOptQuatCamera();

private:
	glm::mat4 m_mIRotation = {
		glm::vec4(1, 0, 0, 0),
		glm::vec4(0, 1, 0, 0),
		glm::vec4(0, 0, 1, 0),
		glm::vec4(0, 0, 0, 1)
	}; //camera's inverse rotational matrix
	glm::mat4 m_mIPosition = {
		glm::vec4(1, 0, 0, 0),
		glm::vec4(0, 1, 0, 0),
		glm::vec4(0, 0, 1, 0),
		glm::vec4(0, 0, 0, 1)
	}; //camera's inverse translational matrix

	glm::quat m_rotateY; //change in rotation of the y axis
	glm::quat m_rotateX; //change in rotation of the x axis
	glm::quat m_rotateZ; //change in rotation of the z axis
	glm::quat m_rotation = glm::quat(1, 0, 0, 0); //camera's current rotation

public:
	virtual void computeViewMatrix();
	virtual void updateCameraPos();
	virtual void updateCameraRot();
};
/*

end Unoptimized  Quaternion-Based Camera

*/