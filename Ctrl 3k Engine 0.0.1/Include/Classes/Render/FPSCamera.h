#pragma once

/*

Optimized First Person Shooter Camera

uses degrees and euler angles to control view matrix
able to offer easy view limiters

*/
class FPSCamera : public Camera
{
public:
	FPSCamera(
			bool fly,
			float xConstraint = 85.0f,
			glm::vec2 rotation = {0, 0}, 
			glm::vec3 position = { 0, 0, 0 },
			int sensitivity = 1,
			int fov = 45,
			float renderF = 300.0f,
			float renderN = 0.2f
			);
	virtual ~FPSCamera();

private:
	float m_yAngle{0.0f}; //rotation on y-axis(degrees)
	float m_xAngle{0.0f}; //rotation on x-axis(degrees)
	float m_xAxisConstraint{85.0f}; //how far one can look straight up or down(degrees)

	//for calculating view matrix, also need m_direction, m_top, and m_right
	float m_sinPitch{0.0f};
	float m_sinYaw{0.0f};
	float m_cosPitch{0.0f};
	float m_cosYaw{0.0f};

	glm::vec3 m_eyePos{ 0, 0, 0 }; //camera position without w factor
	void updateCameraAngles();

public:
	virtual void computeViewMatrix();
	virtual void updateCameraPos();
	virtual void updateCameraRot();

};
/*

end FirstPersonShooterCamera

*/