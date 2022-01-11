#include <Ctrl 3kPCH.h>
#include <classes/Render/Camera.h>

/*

Camera Parent Class

*/

//constructor
Camera::Camera(bool fly, glm::vec3 position, int sensitivity, int fov, float renderF, float renderN) : 
	m_fly(fly), m_position{glm::vec4(position, 1)}, m_senstivity{sensitivity}, m_fov{fov}, m_renderF{renderF}, m_renderN{renderN}
{
	//cstr
}

//sets up pointers to player inupt values
void Camera::setupCamera(float *x, float *y, float *z, float *mouseX, float *mouseY, float *mouseZ, float *ar)
{
	this->x_diff = x;
	this->y_diff = y;
	this->z_diff = z;
	this->mouseX_diff = mouseX;
	this->mouseY_diff = mouseY;
	this->mouseZ_diff = mouseZ;
	this->aspectRatio = ar;

	this->updateCameraPos();
	this->updateCameraRot();
	this->computeProjectionMatrix();
	this->updateVP();
}

//sets the openGL window viewport
void Camera::setViewPort(int x, int y, int width, int height)
{
	glViewport(x, y, width, height);
	this->computeProjectionMatrix();
	this->updateVP();
}

//varies
void Camera::computeViewMatrix()
{
	//do nothing
}

//computes perspective projection matrix
void Camera::computeProjectionMatrix()
{
	this->m_proj = glm::perspective(glm::radians((float)this->m_fov), *this->aspectRatio, this->m_renderN, this->m_renderF);
}

//proj * view
void Camera::computeVP()
{
	this->m_vp = this->m_proj * this->m_view;
}

//computes view matrix and p * v
void Camera::updateVP()
{
	this->computeViewMatrix();
	this->computeVP();
}

//varies
void Camera::updateCameraPos()
{
	//do nothing
}

//varies
void Camera::updateCameraRot()
{
	//do nothing
}

//getters
glm::mat4 Camera::getViewMatrix()
{
	return this->m_view;
}

glm::mat4 Camera::getProjMatrix()
{
	return this->m_proj;
}

glm::mat4 Camera::getVP()
{
	return this->m_vp;
}

glm::vec4 Camera::getPosition()
{
	return this->m_position;
}

glm::vec4 Camera::getDirection()
{
	return glm::vec4(this->m_direction, 0);
}

int Camera::getSensitivity()
{
	return this->m_senstivity;
}

int Camera::getFOV()
{
	return this->m_fov;
}

float Camera::getRenderF()
{
	return this->m_renderF;
}

float Camera::getRenderN()
{
	return this->m_renderN;
}

//setters
void Camera::setSensitivity(int sensitivity)
{
	this->m_senstivity = sensitivity;
}

void Camera::setFOV(int fov)
{
	this->m_fov = fov;
}

void Camera::setRenderF(float renderF)
{
	this->m_renderF = renderF;
}

void Camera::setRenderN(float renderN)
{
	this->m_renderN = renderN;
}

//main updates for all code
void Camera::mainUpdates()
{
	/*
	this->updateCameraPos();
	this->updateCameraRot();
	this->updateVP();
	*/
}

//destructor
Camera::~Camera()
{
	//dstr
}

/*

end Camera Parent Class

*/