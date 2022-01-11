#pragma once

/*

Triangle Mesh Object
stores mesh data which are rendered with GL_TRIANGLES

uses a Triple Index System!!!!!
can output in Single Index System by use of computeOpenGLQuadBufferData() or computeOpenGLTriBufferData()

*/
class TriMesh
{
	friend class Material;
	friend class VisualObject;
public:
	TriMesh(std::string &typeName, TriMesh *&pointer);
	virtual ~TriMesh();

public:
	//void computeOpenGLQuadBufferData(std::vector<glm::vec3> &vert, std::vector<glm::vec2> &tex, std::vector<glm::vec3> &norm, std::vector<GLuint> &index); //position, texcoord, normal, index, tangent, bitangent
	/*
	void getLargestMag();
	void normalizeVertices();
	float m_largestMag;
	/*
	void calcVertexNormals();
	glm::vec3 calcFaceNormal(int zero, int one, int two);
	
	void normalizeNormals();
	*/
	
	GLuint *m_GLvao = new GLuint; //OpenGL Vertex Array Object
	GLuint *m_vertexBufferObjects = new GLuint[6]; //OpenGL Vertex Buffer Object[vertex buffer, texcoords buffer, normal buffer, index buffer, tangent buffer, bitangent buffer]

	int *m_indexCount = new int;
	/*
	int *m_vertCount = new int; //number of vertices
	int *m_texCount = new int; //number of texcoords
	int *m_normCount = new int; //number of normals
	int *m_indexCount = new int; //number of indices
	glm::vec3 *m_verticesPointer = NULL;
	glm::vec2 *m_vertexTexcoordsPointer = NULL;
	glm::vec3 *m_vertexNormalsPointer = NULL;
	glm::uvec3 *m_indicesPointer = NULL; // vertex/texcoord/normal
	*/
	std::string m_name;
	std::vector<glm::uvec3> m_faces;
};
/*

end Triangle Mesh Object

*/