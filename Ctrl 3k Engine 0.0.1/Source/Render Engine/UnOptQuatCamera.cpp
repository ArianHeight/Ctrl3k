#include <Ctrl 3kPCH.h>

/*

Unoptimized Quaternion-Based Camera

*/

//constructor : explicitly calls parent class's constructor to pass values for non-static member initialization
UnOptQuatCamera::UnOptQuatCamera(bool fly, glm::quat rotation, glm::vec3 position, int sensitivity, int fov, float renderF, float renderN) :
	m_rotation{ rotation }, Camera(fly, position, sensitivity, fov, renderF, renderN)
{
	//cstr
}

//updates camera position
void UnOptQuatCamera::updateCameraPos()
{
	if (this->m_fly)
	{
		this->m_position += glm::vec4((*this->x_diff * this->m_right + *this->y_diff * this->m_top + *this->z_diff * this->m_direction), 0);
	}
	else
	{
		glm::vec3 temp{this->m_direction.x, 0, this->m_direction.z};
		temp = glm::normalize(temp);
		this->m_position[1] += *this->y_diff;
		this->m_position += glm::vec4((*this->x_diff * glm::cross(temp, glm::vec3(0, 1, 0)) + *this->z_diff * temp), 0);
	}

	this->m_mIPosition[3] = -this->m_position;
	this->m_mIPosition[3][3] = 1;
}

//updates camera rotation
void UnOptQuatCamera::updateCameraRot()
{
	this->m_rotateZ = glm::quat(cosf(glm::radians(*this->mouseZ_diff * this->m_senstivity * 0.5f)), sinf(glm::radians(*this->mouseZ_diff * this->m_senstivity * 0.5f)) * this->m_direction);
	this->m_rotateY = glm::quat(cosf(glm::radians(*this->mouseX_diff * this->m_senstivity * 0.5f)), sinf(glm::radians(*this->mouseX_diff * this->m_senstivity * 0.5f)) * this->m_top);
	this->m_rotateX = glm::quat(cosf(glm::radians(*this->mouseY_diff * this->m_senstivity * 0.5f)), sinf(glm::radians(*this->mouseY_diff * this->m_senstivity * 0.5f)) * this->m_right);
	this->m_rotation = this->m_rotateX * this->m_rotateY * this->m_rotateZ * this->m_rotation;
	this->m_direction = this->m_rotation * glm::vec3(0.0f, 0.0f, -1.0f);
	this->m_top = this->m_rotation * glm::vec3(0.0f, 1.0f, 0.0f);
	this->m_right = glm::cross(this->m_direction, this->m_top);

	this->m_mIRotation = glm::transpose(glm::toMat4(this->m_rotation));
}

//calculates the camera's view matrix
void UnOptQuatCamera::computeViewMatrix()
{
	this->m_view = this->m_mIRotation * this->m_mIPosition;
}

//destructor
UnOptQuatCamera::~UnOptQuatCamera()
{
	//dstr

}
/*

end Unoptimized Quaternion-Based Camera

*/