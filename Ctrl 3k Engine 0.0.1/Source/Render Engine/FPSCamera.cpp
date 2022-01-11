#include <Ctrl 3kPCH.h>

/*

First Person Shooter Camera

*/

//constructor : explicitly calls parent class's constructor to pass values for non-static member initialization
FPSCamera::FPSCamera(bool fly, float xConstraint, glm::vec2 rotation, glm::vec3 position, int sensitivity, int fov, float renderF, float renderN) :
	m_xAngle{ rotation.x }, m_yAngle(rotation.y), m_xAxisConstraint(xConstraint), Camera(fly, position, sensitivity, fov, renderF, renderN)
{
	//cstr
}

void FPSCamera::updateCameraAngles()
{
	this->m_yAngle += *this->mouseX_diff;
	while (this->m_yAngle >= 360)
	{
		this->m_yAngle -= 360;
	}
	while (this->m_yAngle < 0)
	{
		this->m_yAngle += 360;
	}

	if (this->m_xAngle >= -this->m_xAxisConstraint && this->m_xAngle <= this->m_xAxisConstraint)
	{
		this->m_xAngle += *this->mouseY_diff;
	}
	if (this->m_xAngle < -this->m_xAxisConstraint)
	{
		this->m_xAngle = -this->m_xAxisConstraint;
	}
	else if (this->m_xAngle > this->m_xAxisConstraint)
	{
		this->m_xAngle = this->m_xAxisConstraint;
	}

}

void FPSCamera::computeViewMatrix()
{
	this->m_view[0] = {this->m_right.x, this->m_top.x, this->m_direction.x, 0.0f};
	this->m_view[1] = {this->m_right.y, this->m_top.y, this->m_direction.y, 0.0f};
	this->m_view[2] = {this->m_right.z, this->m_top.z, this->m_direction.z, 0.0f};
	this->m_view[3] = {-glm::dot(this->m_right, this->m_eyePos), -glm::dot(this->m_top, this->m_eyePos), -glm::dot(this->m_direction, this->m_eyePos), 1.0f};
}

void FPSCamera::updateCameraPos()
{
	if (this->m_fly)
	{
		this->m_eyePos += (*this->x_diff * this->m_right + *this->y_diff * this->m_top + *this->z_diff * this->m_direction);
	}
	else
	{
		glm::vec3 temp = { this->m_direction.x, 0, this->m_direction.z };
		temp = glm::normalize(temp);
		this->m_eyePos[1] += *this->y_diff;
		this->m_eyePos += (*this->x_diff * glm::cross(temp, glm::vec3(0, 1, 0)) + *this->z_diff * temp);
	}

	this->m_position = glm::vec4(this->m_eyePos, 1);
}

void FPSCamera::updateCameraRot()
{
	//updates rotation
	this->updateCameraAngles();

	//updates necessary info
	this->m_sinPitch = sin(glm::radians(this->m_xAngle));
	this->m_cosPitch = cos(glm::radians(this->m_xAngle));
	this->m_sinYaw = sin(glm::radians(this->m_yAngle));
	this->m_cosYaw = cos(glm::radians(this->m_yAngle));

	//object space x-axis
	this->m_right.x = this->m_cosYaw;
	this->m_right.y = 0.0f;
	this->m_right.z = -this->m_sinYaw;
	//object space y-axis
	this->m_top.x = this->m_sinYaw * this->m_sinPitch;
	this->m_top.y = this->m_cosPitch;
	this->m_top.z = this->m_cosYaw * this->m_sinPitch;
	//object space z-axis
	this->m_direction.x = this->m_sinYaw * this->m_cosPitch;
	this->m_direction.y = -this->m_sinPitch;
	this->m_direction.z = this->m_cosYaw * this->m_cosPitch;
}

FPSCamera::~FPSCamera()
{
	//dstr
}
/*

end First Person Shooter

*/