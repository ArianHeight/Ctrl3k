#include <Ctrl 3kPCH.h>
#include <classes/3D/Basic Geometry.h>

/*

Basic Cube

*/
Cube::Cube(bool cStatic, glm::vec3 position, glm::quat rotation, float scale)
{
	//cstr
	this->m_static = cStatic;
	this->m_position = glm::vec4(position, 1);
	this->m_rotation = rotation;
	this->m_scale = scale;

	if (!this->m_scale)
	{
		this->m_scale = 0.01f;
	}

	this->initWorld();
}

void Cube::initWorld()
{
	(this->m_posTrans)[3][0] = (this->m_position)[0];
	(this->m_posTrans)[3][1] = (this->m_position)[1];
	(this->m_posTrans)[3][2] = (this->m_position)[2];

	(this->m_world)[0][0] = this->m_scale;
	(this->m_world)[1][1] = this->m_scale;
	(this->m_world)[2][2] = this->m_scale;
	(this->m_world)[3][3] = 1;

	this->m_world = this->m_posTrans * this->m_world * glm::toMat4(this->m_rotation);
}

void Cube::updateWorld()
{

}

glm::mat4 Cube::getWorld()
{
	return this->m_world;
}

Cube::~Cube()
{
	
}
/*

End Basic Cube

*/