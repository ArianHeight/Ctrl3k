#pragma once

/*

General Camera Parent Class

includes all necessary function names for basic 3D camera
as well as all necessary varying function names for different subclasses of 3D cameras

*/
class Camera
{
	friend class Frustrum;
public:
	Camera(bool fly, glm::vec3 position, int sensitivity, int fov, float renderF, float renderN);
	virtual ~Camera();

protected:
	bool m_fly{false};

	glm::vec4 m_position{0}; //camera's current location
	glm::vec3 m_right = { 1, 0, 0 }; //camera's right
	glm::vec3 m_top = { 0, 1, 0 }; //camera's up
	glm::vec3 m_direction = { 0, 0, -1 }; //camera's front

	int m_senstivity{1}; //sensitivity of the camera
	int m_fov{45}; //field of view of the camera
	float m_renderF{200.0f}; //max render distance
	float m_renderN{0.2f}; //min render distance

	float *x_diff, *y_diff, *z_diff, *mouseX_diff, *mouseY_diff, *mouseZ_diff, *aspectRatio; //pointers to player inupt values

	glm::mat4 m_view = { glm::vec4(0, 0, 0, 0), glm::vec4(0, 0, 0, 0), glm::vec4(0, 0, 0, 0), glm::vec4(0, 0, 0, 1) }; //view matrix
	glm::mat4 m_proj; //projection matrix
	glm::mat4 m_vp = { glm::vec4(0, 0, 0, 0), glm::vec4(0, 0, 0, 0), glm::vec4(0, 0, 0, 0), glm::vec4(0, 0, 0, 0) }; //View * Projection

public:
	void setupCamera(float *x, float *y, float *z, float *mouseX, float *mouseY, float *mouseZ, float *ar);

	void setViewPort(int x, int y, int width, int height);
	virtual void computeViewMatrix(); //computes view matrix (varies depending on subclass)
	void computeProjectionMatrix();
	void computeVP();
	void updateVP();
	virtual void updateCameraPos(); //updates camera position (varies depending on subclass)
	virtual void updateCameraRot(); //updates camera rotation (varies depending on subclass)

	void mainUpdates();

	//accessors
	glm::mat4 getViewMatrix();
	glm::mat4 getProjMatrix();
	glm::mat4 getVP();
	glm::vec4 getPosition();
	glm::vec4 getDirection();
	int getSensitivity();
	int getFOV();
	float getRenderF();
	float getRenderN();

	//mutators
	void setSensitivity(int sensitivity);
	void setFOV(int fov);
	void setRenderF(float renderF);
	void setRenderN(float renderN);
};
/*

end General Camera Parent Class

*/