#include <Ctrl 3kPCH.h>

/*

Triangle Mesh

*/

//constructor : loads .obj from filepath, initializes m_name with name, and normalizes all vertices in the mesh
TriMesh::TriMesh(std::string &typeName, TriMesh *&pointer) : m_name{typeName.c_str()}
{
	pointer = this;
}
/*
//returns pointer to vertices in the mesh
glm::vec3* TriMesh::getVertices()
{
	return this->m_verticesPointer;
}

//returns pointer to texcoords in the mesh
glm::vec2* TriMesh::getTexcoords()
{
	return this->m_vertexTexcoordsPointer;
}

//returns pointer to normals in the mesh
glm::vec3* TriMesh::getNormals()
{
	return this->m_vertexNormalsPointer;
}

//returns pointer to indices in the mesh
glm::uvec3* TriMesh::getIndices()
{
	return this->m_indicesPointer;
}
*/
/*
//sets input std::vectors to the values of the mesh's data converted to a Single Index System through index checking
void TriMesh::computeOpenGLQuadBufferData(std::vector<glm::vec3> &vert, std::vector<glm::vec2> &tex, std::vector<glm::vec3> &norm, std::vector<GLuint> &index)
{
	std::vector<glm::uvec3> indexBuffer; //temp std::vector for index checking
	int temp = 0; //temp value used to hold a repeated index's first appearance location
	int newIndex = 0; //count for rising index

	for (int i = 0; i < *this->m_indexCount; ++ i)
	{
		if (isInVector(this->m_indicesPointer[i], indexBuffer, temp)) //index check
		{
			index.push_back(temp); //give index the value of the location of the first instance of current index
		}
		else
		{
			//sets all values
			vert.push_back(this->m_verticesPointer[this->m_indicesPointer[i][0]]);
			tex.push_back(this->m_vertexTexcoordsPointer[this->m_indicesPointer[i][1]]);
			norm.push_back(this->m_vertexNormalsPointer[this->m_indicesPointer[i][2]]);
			index.push_back(newIndex);

			//add new index to temp buffer and increments newIndex
			indexBuffer.push_back(this->m_indicesPointer[i]);
			++ newIndex;
		}
	}
}
*/
/*
//gets the largest magnitude of all vertices in the mesh
void TriMesh::getLargestMag()
{
	float mag = 0; //temp value holder

	for (int i = 0; i < *this->m_vertCount; ++i)
	{
		if (magnitude3(this->m_verticesPointer[i]) > mag)
		{
			mag = magnitude3(this->m_verticesPointer[i]); //sets mag to new magnitude if it is larger
		}
	}

	this->m_largestMag = mag;
}

//normalizes vertices(dividing all vertices by the largest magnitude)
void TriMesh::normalizeVertices()
{
	if (this->m_largestMag != 1)
	{
		for (int i = 0; i < *this->m_vertCount; ++i)
		{
			this->m_verticesPointer[i] = this->m_verticesPointer[i] / this->m_largestMag;
		}

		this->getLargestMag();
	}
}
*/
/*
void TriMesh::calcVertexNormals()
{
	glm::vec3 temp;
	int zero, one, two;

	for (int i = 0; i < this->m_indexCount; i += 3)
	{
		zero = this->m_indicesPointer[i];
		one = this->m_indicesPointer[i + 1];
		two = this->m_indicesPointer[i + 2];

		temp = this->calcFaceNormal(zero, one, two);

		this->m_vertexNormalsPointer[zero] += temp;
		this->m_vertexNormalsPointer[one] += temp;
		this->m_vertexNormalsPointer[two] += temp;
	}

	this->normalizeNormals();
}

glm::vec3 TriMesh::calcFaceNormal(int zero, int one, int two)
{
	//return glm::cross((this->m_verticesPointer[zero] - this->m_verticesPointer[one]), (this->m_verticesPointer[two] - this->m_verticesPointer[one]));
	return glm::cross((this->m_verticesPointer[two] - this->m_verticesPointer[one]), (this->m_verticesPointer[zero] - this->m_verticesPointer[one]));
}
*/
/*
void TriMesh::normalizeNormals()
{
	for (int i = 0; i < *this->m_vertCount; ++i)
	{
		this->m_vertexNormalsPointer[i] = glm::normalize(this->m_vertexNormalsPointer[i]);
	}
}
*/
//destructor
TriMesh::~TriMesh()
{
	//clean up
	delete this->m_GLvao;
	delete[] this->m_vertexBufferObjects;
	delete this->m_indexCount;
	/*
	delete this->m_vertCount;
	delete this->m_texCount;
	delete this->m_normCount;
	delete this->m_indexCount;

	delete[] this->m_verticesPointer;
	delete[] this->m_vertexNormalsPointer;
	delete[] this->m_vertexTexcoordsPointer;
	delete[] this->m_indicesPointer;
	*/

	//fixes hanging pointers
	this->m_GLvao = NULL;
	this->m_vertexBufferObjects = NULL;
	this->m_indexCount = NULL;
	/*
	this->m_vertCount = NULL;
	this->m_texCount = NULL;
	this->m_normCount = NULL;
	this->m_indexCount = NULL;

	this->m_verticesPointer = NULL;
	this->m_vertexNormalsPointer = NULL;
	this->m_vertexTexcoordsPointer = NULL;
	this->m_indicesPointer = NULL;
	*/
}

/*

end Triangle Mesh

*/