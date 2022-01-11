#include <Ctrl 3kPCH.h>

//uses SOIL to complete task
GLuint loadTexture(const std::string& file, bool mips)
{
	GLuint textureID;
	if (mips)
	{
		textureID = SOIL_load_OGL_texture(file.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y); //loads texture into OGL(openGL)
	}
	else
	{
		textureID = SOIL_load_OGL_texture(file.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y); //loads texture into OGL(openGL)
	}

	//sets texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//unbind texture
	glBindTexture(GL_TEXTURE_2D, 0);

	return textureID;
}

//splits using space delimiter line into datablocks using space delimiter
void getToken(std::vector<DataBlock> &out, std::string &line, std::string &work, int &index)
{
	//line is the line being split, out is the std::vector of DataBlocks where line will split into, work is the temp string which will hold data before block iteration is complete
	for (char c : line)
	{
		switch (c)
		{
		case ' ':
			if (!work.empty())
			{
				if (index >= out.size()) //if line has more blocks of data than the std::vector, then created a new DataBlock and add it to the vector
				{
					out.push_back(DataBlock(work));
					++index;
				}
				else //if line has less blocks of data than the std::vector, simply change the data in the DataBlocks in the std::vector
				{
					out[index].changeData(work);
					++index;
				}
			}
			work.clear();
			break;
		case '#': //breaks if sees comment
			if (!work.empty())
			{
				if (index >= out.size())
				{
					out.push_back(DataBlock(work));
					++index;
				}
				else
				{
					out[index].changeData(work);
					++index;
				}
			}
			work.clear();
			index = 0;
			return;
		default:
			work.push_back(c);
			break;
		}
	}
	if (!work.empty()) //puts into the std::vector the last datablock at the end of the line
	{
		if (index >= out.size())
		{
			out.push_back(DataBlock(work));
			++index;
		}
		else
		{
			out[index].changeData(work);
			++index;
		}
	}

	//cleans up temp strings and ints
	work.clear();
	index = 0;
}

//returns file name from file path
void getTokenPath(std::string &out, std::string &line)
{
	out.clear();
	unsigned int index = line.find_last_of("/\\");
	out = line.substr(index + 1);
}

void loadOpenGLHexaBuffer(TriMesh *mesh, std::vector<glm::vec3> &vertices, std::vector<glm::vec2> &texcoords, std::vector<glm::vec3> &normals)
{
	//creates VBO data
	std::vector<glm::vec3> vertexBufferD; //0
	std::vector<glm::vec2> texcoordBufferD; //1
	std::vector<glm::vec3> normalBufferD; //2
	std::vector<GLuint> indexBufferD; //3
	std::vector<glm::vec3> tangentBufferD; //4
	std::vector<glm::vec3> biTangentBufferD; //5

	std::vector<glm::uvec3> indexBuffer; //temp std::vector for index checking
	int temp = 0; //temp value used to hold a repeated index's first appearance location
	int newIndex = 0; //count for rising index

	float oneOverDeterminent = 0;
	glm::vec3 deltaPosOne(0);
	glm::vec3 deltaPosTwo(0);
	glm::vec2 deltaUVOne(0);
	glm::vec2 deltaUVTwo(0);
	glm::vec3 tan;
	glm::vec3 biTan;

	int sizeI = mesh->m_faces.size();

	for (int i = 0; i < sizeI; ++i)
	{
		if (isInVector(mesh->m_faces[i], indexBuffer, temp)) //index check
		{
			indexBufferD.push_back(temp); //give index the value of the location of the first instance of current index
		}
		else
		{
			//sets all values
			vertexBufferD.push_back(vertices[mesh->m_faces[i].x]);
			texcoordBufferD.push_back(texcoords[mesh->m_faces[i].y]);
			normalBufferD.push_back(normals[mesh->m_faces[i].z]);
			indexBufferD.push_back(newIndex);

			//add new index to temp buffer and increments newIndex
			indexBuffer.push_back(mesh->m_faces[i]);
			++newIndex;
		}
	}
	*mesh->m_indexCount = indexBufferD.size();
	mesh->m_faces.clear();
	mesh->m_faces.shrink_to_fit();

	//calculates tangent and bitangent buffers' data
	sizeI = normalBufferD.size();
	tangentBufferD.resize(sizeI);
	biTangentBufferD.resize(sizeI);
	sizeI = indexBufferD.size();
	for (int i = 0; i < sizeI; i += 3)
	{
		deltaPosOne = vertexBufferD[indexBufferD[i + 1]] - vertexBufferD[indexBufferD[i]];
		deltaPosTwo = vertexBufferD[indexBufferD[i + 2]] - vertexBufferD[indexBufferD[i]];
		deltaUVOne = texcoordBufferD[indexBufferD[i + 1]] - texcoordBufferD[indexBufferD[i]];
		deltaUVTwo = texcoordBufferD[indexBufferD[i + 2]] - texcoordBufferD[indexBufferD[i]];

		oneOverDeterminent = 1.0f / (deltaUVOne.x * deltaUVTwo.y - deltaUVOne.y * deltaUVTwo.x);

		tan = (deltaPosOne * deltaUVTwo.y - deltaPosTwo * deltaUVOne.y) * oneOverDeterminent;

		tangentBufferD[indexBufferD[i]] += tan;
		tangentBufferD[indexBufferD[i + 1]] += tan;
		tangentBufferD[indexBufferD[i + 2]] += tan;
		biTangentBufferD[indexBufferD[i]] += biTan;
		biTangentBufferD[indexBufferD[i + 1]] += biTan;
		biTangentBufferD[indexBufferD[i + 2]] += biTan;
	}
	sizeI = normalBufferD.size();
	for (int i = 0; i < sizeI; ++i)
	{
		tan = glm::normalize(biTangentBufferD[i]);

		if (glm::dot(glm::cross(normalBufferD[i], tangentBufferD[i]), biTangentBufferD[i]) < 0.0f)
		{
			tangentBufferD[i] = tan * -1.0f;
		}

		tangentBufferD[i] = glm::normalize(tangentBufferD[i] - normalBufferD[i] * glm::dot(tangentBufferD[i], normalBufferD[i]));
		biTan = glm::cross(tangentBufferD[i], normalBufferD[i]);
		biTangentBufferD[i] = biTan;
	}

	glGenVertexArrays(1, mesh->m_GLvao); //generates a VAO
	glBindVertexArray(*mesh->m_GLvao);
	
	glGenBuffers(6, mesh->m_vertexBufferObjects); //generates 6VBOs
	
	glBindBuffer(GL_ARRAY_BUFFER, mesh->m_vertexBufferObjects[0]); //vertex buffer
	glBufferData(GL_ARRAY_BUFFER, vertexBufferD.size() * sizeof(glm::vec3), vertexBufferD.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(POSITION_ATTRIB, 3, GL_FLOAT, false, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(POSITION_ATTRIB);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->m_vertexBufferObjects[1]); //texcoords buffer
	glBufferData(GL_ARRAY_BUFFER, texcoordBufferD.size() * sizeof(glm::vec2), texcoordBufferD.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(TEXCOORD0_ATTRIB, 2, GL_FLOAT, false, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(TEXCOORD0_ATTRIB);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->m_vertexBufferObjects[2]); //normal buffer
	glBufferData(GL_ARRAY_BUFFER, normalBufferD.size() * sizeof(glm::vec3), normalBufferD.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(NORMAL_ATTRIB, 3, GL_FLOAT, false, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(NORMAL_ATTRIB);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->m_vertexBufferObjects[3]); //index buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBufferD.size() * sizeof(GLuint), indexBufferD.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->m_vertexBufferObjects[4]); //tangent buffer
	glBufferData(GL_ARRAY_BUFFER, tangentBufferD.size() * sizeof(glm::vec3), tangentBufferD.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(TANGENT_ATTRIB, 3, GL_FLOAT, false, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(TANGENT_ATTRIB);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->m_vertexBufferObjects[5]); //bitangent buffer
	glBufferData(GL_ARRAY_BUFFER, biTangentBufferD.size() * sizeof(glm::vec3), biTangentBufferD.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(BINORMAL_ATTRIB, 3, GL_FLOAT, false, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(BINORMAL_ATTRIB);

	//unbinds and disables everything once we are done here
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glDisableVertexAttribArray(POSITION_ATTRIB);
	glDisableVertexAttribArray(NORMAL_ATTRIB);
	glDisableVertexAttribArray(TEXCOORD0_ATTRIB);
	glDisableVertexAttribArray(TANGENT_ATTRIB);
	glDisableVertexAttribArray(BINORMAL_ATTRIB);
}

//changes all "\" in a path to "/"
void pathToSlash(std::string &path)
{
	std::string temp;
	for (char c : path)
	{
		if (c != '\\')
		{
			temp.push_back(c);
		}
		else
		{
			temp.push_back('/');
		}
	}
	path.clear();
	path = temp;
}

//changes all "/" in a path to "\"
void pathToBackSlash(std::string &path)
{
	std::string temp;
	for (char c : path)
	{
		if (c != '/')
		{
			temp.push_back(c);
		}
		else
		{
			temp.push_back('\\');
		}
	}
	path.clear();
	path = temp;
}

//return 1 for success, 0 for fail, -1 for comment
int parseLine(std::vector<float> &out, std::vector<int> &out2, std::vector<std::string> &out3, std::vector<DataBlock> &block, std::string &work)
{
	//the 2 std::vectors are data output buffers, block is the datablock std::vector of the current line, work is temp string used for temporary mem storage
	if (block[0].m_data == "v" || block[0].m_data == "vn" || block[0].m_data == "vt") //vertex, texcoord, normal processing
	{
		for (int i = 1; i < block.size(); ++i)
		{
			if (block[i].m_datatype == 'f' || block[i].m_datatype == 'i') //outputs data to std::vector if the data type is correct
			{
				out.push_back(std::stof(block[i].m_data));
			}
			else
			{
				return 0;
			}
		}
	}
	else if (block[0].m_data == "f") //face processing
	{
		for (int i = 1; i < block.size(); ++i)
		{
			for (char c : block[i].m_data) //iterates through every face statement and splits it up into three index components, then outputs it to std::vector if data type is correct
			{
				switch (c)
				{
				case '/':
					if (!work.empty()) { out2.push_back(std::stoi(work)); }
					work.clear();
					break;
				default:
					work.push_back(c);
					break;
				}
			}
			if (!work.empty()) { out2.push_back(std::stoi(work)); }
			work.clear();
		}
		work.clear();
	}
	else if (block[0].m_data == "usemtl" || block[0].m_data == "mtllib" || block[0].m_data == "o" || block[0].m_data == "g") //links and whatnot
	{
		for (int i = 1; i < block.size(); ++i)
		{
			out3.push_back(block[i].m_data);
		}
	}

	return 1;
}

//return 1 for success, 0 for fail, -1 for comment (.mtl version of parseLine, basically does the same thing)
int parseLineMtl(std::vector<float> &out, std::vector<int> &out2, std::vector<std::string> &out3, std::vector<DataBlock> &block)
{
	//processes data that will only contain floats
	if (block[0].m_data == "Ka" || block[0].m_data == "Kd" || block[0].m_data == "Ks" || block[0].m_data == "Ke" || block[0].m_data == "Ns" || block[0].m_data == "Ni" || block[0].m_data == "d" || block[0].m_data == "Tr" || block[0].m_data == "sharpness" || block[0].m_data == "Tf")
	{
		for (int i = 1; i < block.size(); ++i)
		{
			if (block[i].m_datatype == 'f' || block[i].m_datatype == 'i')
			{
				out.push_back(std::stof(block[i].m_data));
			}
			else
			{
				out3.push_back(block[i].m_data);
			}
		}
	}
	else if (block[0].m_data == "illum") //processes illum's data, which are only ints
	{
		for (int i = 1; i < block.size(); ++i)
		{
			if (block[i].m_datatype == 'i')
			{
				out2.push_back(std::stoi(block[i].m_data));
			}
			else
			{
				return 0;
			}
		}
	}
	//processes the file path data
	else if (block[0].m_data == "map_Ka" || block[0].m_data == "map_Kd" || block[0].m_data == "map_Ks" || block[0].m_data == "map_Ns" || block[0].m_data == "map_d" || block[0].m_data == "map_Disp" || block[0].m_data == "map_Decal" || block[0].m_data == "map_Bump" || block[0].m_data == "map_Refl")
	{
		for (int i = 1; i < block.size(); ++i)
		{
			if (block[i].m_datatype == 'f' || block[i].m_datatype == 'i')
			{
				out.push_back(std::stof(block[i].m_data));
			}
			else if (block[i].m_datatype == 'c' || block[i].m_datatype == 'n')
			{
				out3.push_back(block[i].m_data);
			}
		}
	}

	return 1;
}

//loads .obj file given file path into target TriMesh object
bool loadObj(std::string& filePath, VisualObject &target)
{
	//vectors for data
	std::vector<glm::uvec3> faces; // vertex/texcoord/normal
	std::string mtlPath;
	TriMesh *currentMesh = NULL;

	std::vector<glm::vec3> vertices; //xyz
	std::vector<glm::vec2> texcoords; //UV
	std::vector<glm::vec3> normals; //xyz

	//setup mem storage
	std::ifstream file(filePath.c_str()); //file
	std::string currentLine;
	std::string currentHolder; //temporary data holder
	std::vector<DataBlock> block; //std::vector of datablocks of currentLine
	int slashes = 0; //used in second part of face proccessing to determine structure of face declaration (v/vt/vn, v/vt, v//vn, or v)
	int indexT = 0; //temporary mem storage

	//temporary memory storage for loading into vectors for data
	glm::vec3 tempThree;
	glm::vec2 tempTwo;

	//data containers for line outputs
	std::vector<float> dataHolder;
	std::vector<int> iDataHolder;
	std::vector<std::string> sDataHolder;

	//for face seperation
	std::string activeGroup = "";
	int activeMaterial = -1;
	bool groupChangeFlagged, materialChangeFlagged = false;

	if (!file.is_open()) //returns 0 if file did not open
	{
		return 0;
	}

	while (std::getline(file, currentLine))
	{
		if (currentLine[0] != '#') //filters out comments
		{
			getToken(block, currentLine, currentHolder, indexT); //loads data into blocks
			if (block.size() != 0) //does not run parse code if block is empty
			{
				parseLine(dataHolder, iDataHolder, sDataHolder, block, currentHolder); //process block data
				if (block[0].m_data == "v") //for vertex data
				{
					if (dataHolder.size() == 4) // v x y z w
					{
						if (dataHolder[3] != 1) //w divide to put world value of position to one
						{
							tempThree[0] = dataHolder[0] / dataHolder[3];
							tempThree[1] = dataHolder[1] / dataHolder[3];
							tempThree[2] = dataHolder[2] / dataHolder[3];
						}
						else
						{
							tempThree[0] = dataHolder[0];
							tempThree[1] = dataHolder[1];
							tempThree[2] = dataHolder[2];
						}
					}
					else //v x y z
					{
						tempThree[0] = dataHolder[0];
						tempThree[1] = dataHolder[1];
						tempThree[2] = dataHolder[2];
					}
					vertices.push_back(tempThree); //puts vertex data into std::vector
					dataHolder.clear(); //clears data container

					tempThree = { 0.0f, 0.0f, 0.0f }; //empties out temp mem storage
				}
				else if (block[0].m_data == "vn") //for vertex normals
				{
					tempThree[0] = dataHolder[0];
					tempThree[1] = dataHolder[1];
					tempThree[2] = dataHolder[2];

					normals.push_back(glm::normalize(tempThree)); //puts normal data into std::vector
					dataHolder.clear(); //clears data container

					tempThree = { 0.0f, 0.0f, 0.0f }; //empties temp mem storage
				}
				else if (block[0].m_data == "vt") //for UV coords
				{
					tempTwo[0] = dataHolder[0];
					tempTwo[1] = dataHolder[1];

					texcoords.push_back(tempTwo); //puts texcoord data into std::vector
					dataHolder.clear(); //clears data container

					tempTwo = { 0, 0 }; //empties temp mem storage
				}
				else if (block[0].m_data == "f") //for faces or indices, assuming all faces are triangulated properly
				{
					if (materialChangeFlagged || groupChangeFlagged)
					{
						target.m_meshGroups.push_back(new TriMesh(activeGroup, currentMesh));
						target.m_materials.push_back(activeMaterial);
						materialChangeFlagged = false;
						groupChangeFlagged = false;
					}

					if (block[1].m_datatype != 'i') //not f v v v
					{
						for (char c : block[1].m_data) //determine numbers of slashes
						{
							switch (c)
							{
							case '/':
								++slashes;
								break;
							}
						}

						if (slashes == 1) // f v/vt v/vt v/vt
						{
							currentMesh->m_faces.push_back(glm::uvec3(iDataHolder[0] - 1, iDataHolder[1] - 1, 0));
							currentMesh->m_faces.push_back(glm::uvec3(iDataHolder[2] - 1, iDataHolder[3] - 1, 0));
							currentMesh->m_faces.push_back(glm::uvec3(iDataHolder[4] - 1, iDataHolder[5] - 1, 0));
						}
						else if (slashes == 2 && iDataHolder.size() == 6) // f v//vn v//vn v//vn
						{
							currentMesh->m_faces.push_back(glm::uvec3(iDataHolder[0] - 1, 0, iDataHolder[1] - 1));
							currentMesh->m_faces.push_back(glm::uvec3(iDataHolder[2] - 1, 0, iDataHolder[3] - 1));
							currentMesh->m_faces.push_back(glm::uvec3(iDataHolder[4] - 1, 0, iDataHolder[5] - 1));
						}
						else // f v/vt/vn v/vt/vn v/vt/vn
						{
							currentMesh->m_faces.push_back(glm::uvec3(iDataHolder[0] - 1, iDataHolder[1] - 1, iDataHolder[2] - 1));
							currentMesh->m_faces.push_back(glm::uvec3(iDataHolder[3] - 1, iDataHolder[4] - 1, iDataHolder[5] - 1));
							currentMesh->m_faces.push_back(glm::uvec3(iDataHolder[6] - 1, iDataHolder[7] - 1, iDataHolder[8] - 1));
						}
						slashes = 0;
					}
					else //f v v v
					{
						currentMesh->m_faces.push_back(glm::uvec3(iDataHolder[0] - 1, 0, 0));
						currentMesh->m_faces.push_back(glm::uvec3(iDataHolder[1] - 1, 0, 0));
						currentMesh->m_faces.push_back(glm::uvec3(iDataHolder[2] - 1, 0, 0));
					}

					iDataHolder.clear(); //clears data container
				}
				else if (block[0].m_data == "o")
				{
					target.m_name = "";
					for (int count = 0; count < sDataHolder.size(); ++count)
					{
						target.m_name += sDataHolder[count];
						if (sDataHolder.size() - 1 != count)
						{
							target.m_name += " ";
						}
					}
					sDataHolder.clear();
				}
				else if (block[0].m_data == "g")
				{
					/*
					if (currentMesh == NULL)
					{
						target.m_meshGroups.push_back(new TriMesh((sDataHolder[0]), currentMesh));
					}
					else
					{
						if (faces.size() != 0)
						{
							target.m_materials.push_back(findMaterial(usemtl));
							loadOpenGLHexaBuffer(currentMesh, vertices, texcoords, normals, faces);
							faces.clear(); //for previous group
						}

						target.m_meshGroups.push_back(new TriMesh((sDataHolder[0]), currentMesh)); //for new group
					}
					*/
					activeGroup.clear();
					for (int count = 0; count < sDataHolder.size(); ++count)
					{
						activeGroup += sDataHolder[count];
						if (sDataHolder.size() - 1 != count)
						{
							activeGroup += " ";
						}
					}
					groupChangeFlagged = true;
					sDataHolder.clear();
				}
				else if (block[0].m_data == "mtllib")
				{
					mtlPath.clear();
					for (int count = 0; count < sDataHolder.size(); ++count)
					{
						mtlPath += sDataHolder[count];
						if (sDataHolder.size() - 1 != count)
						{
							mtlPath += " ";
						}
					}
					pathToSlash(mtlPath);
					loadMtl(filePath.substr(0, filePath.find_last_of('/') + 1) + mtlPath);
					mtlPath.clear();
					sDataHolder.clear();
				}
				else if (block[0].m_data == "usemtl")
				{
					//usemtl = (sDataHolder[0]);
					activeMaterial = findMaterial(sDataHolder[0]);
					materialChangeFlagged = true;
					sDataHolder.clear();
				}
				currentHolder.clear(); //clears temp data container
				for (int i = 0; i < block.size(); ++i) //DataBlock.clear() every datablock object in block
				{
					block[i].clear();
				}
			}
		} //ends comment filter
	}
	/*
	int size = vertices.size();
	float largestMag = 0.0f;
	for (int i = 0; i < size; ++i)
	{
		if (magnitude3(vertices[i]) > largestMag)
		{
			largestMag = magnitude3(vertices[i]); //sets mag to new magnitude if it is larger
		}
	}
	for (int i = 0; i < size; ++i)
	{
		vertices[i] = vertices[i] / largestMag;
	}
	
	size = normals.size();
	for (int i = 0; i < size; ++i)
	{
		normals[i] = glm::normalize(normals[i]);
	}
	*/
	for (TriMesh *mesh : target.m_meshGroups)
	{
		loadOpenGLHexaBuffer(mesh, vertices, texcoords, normals);
	}

	file.close();

	return 1;
}

//.mtl version of loadObj(), practically the same
bool loadMtl(std::string& filePath)
{
	//value holders
	int materialIndex = -1;
	Material *currentMaterial = NULL;
	/*
	glm::vec4 diffuse(0), specular(0), emissive(0), ambient(0);
	glm::vec3 transmissionFilter(0);
	float shininess, sharpness, dissolve, opticalDensity = 0;
	int illuminationModel = 0;
	bool dissolveHalo = false;
	std::string materialName, mapPath[9]; //ambient, diffuse, specular, shininess, dissolve, displacement, decal, bump, reflection*/

	//setup
	std::ifstream file(filePath.c_str());
	std::string currentLine;
	std::string currentHolder;
	std::vector<DataBlock> block;
	int index = 0;

	std::vector<float> dataHolder;
	std::vector<int> iDataHolder;
	std::vector<std::string> sDataHolder;
	std::string fileName; //temporary name for filename

	if (!file.is_open())
	{
		return 0;
	}

	while (std::getline(file, currentLine))
	{
		if (currentLine[0] != '#') //filters out comments
		{
			getToken(block, currentLine, currentHolder, index); //loads data into blocks
			if (block.size() != 0)
			{
				parseLineMtl(dataHolder, iDataHolder, sDataHolder, block); //process block data
				if (block[0].m_data == "newmtl") //for material name
				{
					/*
					if (currentMaterial != NULL) //for previous material
					{
						for (int i = 0; i < 9; ++i)
						{
							if (!currentMaterial->mapPaths[i].empty())
							{
								getTokenPath(fileName, currentMaterial->mapPaths[i]);
								if (currentMaterial->requestFile(fileName, i)) //texture loaded
								{
									currentMaterial->mapPaths[i].clear();
								}
							}
						}
						currentMaterial->fillFiles(filePath);
					}
					*/
					if (currentMaterial != NULL) //for previous material
					{
						currentMaterial->fillFiles(filePath);
					}
					materialIndex += 1;
					loadMaterial(block[1].m_data, currentMaterial);
				}
				else if (block[0].m_data == "Ka") //ambient value
				{
					currentMaterial->m_ambient[0] = dataHolder[0];
					currentMaterial->m_ambient[1] = dataHolder[1];
					currentMaterial->m_ambient[2] = dataHolder[2];
					currentMaterial->m_ambient[3] = 1.0f;
					if (dataHolder.size() == 4)
					{
						currentMaterial->m_ambient[3] = dataHolder[3];
					}
				}
				else if (block[0].m_data == "Kd") //diffuse value
				{
					currentMaterial->m_diffuse[0] = dataHolder[0];
					currentMaterial->m_diffuse[1] = dataHolder[1];
					currentMaterial->m_diffuse[2] = dataHolder[2];
					currentMaterial->m_diffuse[3] = 1.0f;
					if (dataHolder.size() == 4)
					{
						currentMaterial->m_diffuse[3] = dataHolder[3];
					}
				}
				else if (block[0].m_data == "Ks") //specular value
				{
					currentMaterial->m_specular[0] = dataHolder[0];
					currentMaterial->m_specular[1] = dataHolder[1];
					currentMaterial->m_specular[2] = dataHolder[2];
					currentMaterial->m_specular[3] = 1.0f;
					if (dataHolder.size() == 4)
					{
						currentMaterial->m_specular[3] = dataHolder[3];
					}
				}
				else if (block[0].m_data == "Ke") //emissive value
				{
					currentMaterial->m_emissive[0] = dataHolder[0];
					currentMaterial->m_emissive[1] = dataHolder[1];
					currentMaterial->m_emissive[2] = dataHolder[2];
					currentMaterial->m_emissive[3] = 1.0f;
					if (dataHolder.size() == 4)
					{
						currentMaterial->m_emissive[3] = dataHolder[3];
					}
				}
				else if (block[0].m_data == "Tf") //transmission filter values
				{
					currentMaterial->m_transmissionFilter[0] = dataHolder[0];
					currentMaterial->m_transmissionFilter[1] = dataHolder[1];
					currentMaterial->m_transmissionFilter[2] = dataHolder[2];
				}
				else if (block[0].m_data == "Ns") //specular exponent value
				{
					currentMaterial->m_shininess = dataHolder[0];
				}
				else if (block[0].m_data == "Ni") //sharpness value
				{
					currentMaterial->m_sharpness = dataHolder[0] + 1;
				}
				else if (block[0].m_data == "d" || block[0].m_data == "Tr") //dissolve or transparency value
				{
					if (block[0].m_data == "d")
					{
						currentMaterial->m_dissolve = dataHolder[0];
					}
					else
					{
						currentMaterial->m_dissolve = 1.0f - dataHolder[0];
					}

					if (sDataHolder.size() != 0) //checks if -halo option is one
					{
						if (sDataHolder[0] == "-halo")
						{
							currentMaterial->m_dissolveHalo = true;
						}
						else
						{
							currentMaterial->m_dissolveHalo = false;
						}
					}
					else
					{
						currentMaterial->m_dissolveHalo = false;
					}
				}
				else if (block[0].m_data == "Ni") //sets optical density value
				{
					currentMaterial->m_opticalDensity = dataHolder[0];
				}
				else if (block[0].m_data == "illum") //sets illumination value
				{
					currentMaterial->m_illuminationModel = illum(iDataHolder[0]);
				}
				else if (block[0].m_data == "map_Ka") //ambient map, maps  will change to interpret options -o
				{
					pathToSlash(sDataHolder[sDataHolder.size() - 1]);
					currentMaterial->mapPaths[0] = sDataHolder[sDataHolder.size() - 1];
					getTokenPath(fileName, currentMaterial->mapPaths[0]);
					if (currentMaterial->requestFile(fileName, 0)) //texture loaded
					{
						currentMaterial->mapPaths[0].clear();
					}
				}
				else if (block[0].m_data == "map_Kd") //diffuse map, maps  will change to interpret options -o
				{
					pathToSlash(sDataHolder[sDataHolder.size() - 1]);
					currentMaterial->mapPaths[1] = sDataHolder[sDataHolder.size() - 1];
					getTokenPath(fileName, currentMaterial->mapPaths[1]);
					if (currentMaterial->requestFile(fileName, 1)) //texture loaded
					{
						currentMaterial->mapPaths[1].clear();
					}
				}
				else if (block[0].m_data == "map_Ks") //specular map, maps  will change to interpret options -o
				{
					pathToSlash(sDataHolder[sDataHolder.size() - 1]);
					currentMaterial->mapPaths[2] = sDataHolder[sDataHolder.size() - 1];
					getTokenPath(fileName, currentMaterial->mapPaths[2]);
					if (currentMaterial->requestFile(fileName, 2)) //texture loaded
					{
						currentMaterial->mapPaths[2].clear();
					}
				}
				else if (block[0].m_data == "map_Ns") //shininess map, maps  will change to interpret options -o
				{
					pathToSlash(sDataHolder[sDataHolder.size() - 1]);
					currentMaterial->mapPaths[3] = sDataHolder[sDataHolder.size() - 1];
					getTokenPath(fileName, currentMaterial->mapPaths[3]);
					if (currentMaterial->requestFile(fileName, 3)) //texture loaded
					{
						currentMaterial->mapPaths[3].clear();
					}
				}
				else if (block[0].m_data == "map_d") //dissolve map, maps  will change to interpret options -o
				{
					pathToSlash(sDataHolder[sDataHolder.size() - 1]);
					currentMaterial->mapPaths[4] = sDataHolder[sDataHolder.size() - 1];
					getTokenPath(fileName, currentMaterial->mapPaths[4]);
					if (currentMaterial->requestFile(fileName, 4)) //texture loaded
					{
						currentMaterial->mapPaths[4].clear();
					}
				}
				else if (block[0].m_data == "map_Disp") //displacement map, maps  will change to interpret options -o
				{
					pathToSlash(sDataHolder[sDataHolder.size() - 1]);
					currentMaterial->mapPaths[5] = sDataHolder[sDataHolder.size() - 1];
					getTokenPath(fileName, currentMaterial->mapPaths[5]);
					if (currentMaterial->requestFile(fileName, 5)) //texture loaded
					{
						currentMaterial->mapPaths[5].clear();
					}
				}
				else if (block[0].m_data == "map_Decal") //decal map, maps  will change to interpret options -o
				{
					pathToSlash(sDataHolder[sDataHolder.size() - 1]);
					currentMaterial->mapPaths[6] = sDataHolder[sDataHolder.size() - 1];
					getTokenPath(fileName, currentMaterial->mapPaths[6]);
					if (currentMaterial->requestFile(fileName, 6)) //texture loaded
					{
						currentMaterial->mapPaths[6].clear();
					}
				}
				else if (block[0].m_data == "map_Bump") //bump map, maps  will change to interpret options -o
				{
					pathToSlash(sDataHolder[sDataHolder.size() - 1]);
					currentMaterial->mapPaths[7] = sDataHolder[sDataHolder.size() - 1];
					getTokenPath(fileName, currentMaterial->mapPaths[7]);
					if (currentMaterial->requestFile(fileName, 7)) //texture loaded
					{
						currentMaterial->mapPaths[7].clear();
					}
				}
				else if (block[0].m_data == "map_Refl") //maps  will change to interpret options -o
				{
					pathToSlash(sDataHolder[sDataHolder.size() - 1]);
					currentMaterial->mapPaths[8] = sDataHolder[sDataHolder.size() - 1];
					getTokenPath(fileName, currentMaterial->mapPaths[8]);
					if (currentMaterial->requestFile(fileName, 8)) //texture loaded
					{
						currentMaterial->mapPaths[8].clear();
					}
				}
				//clears data containers
				dataHolder.clear();
				sDataHolder.clear();
				iDataHolder.clear();
				currentHolder.clear();
				for (int i = 0; i < block.size(); ++i)
				{
					block[i].clear();
				}
			}
		} //ends comment filter
	}
	if (currentMaterial != NULL)
	{
		currentMaterial->fillFiles(filePath);
	}
	/*
	if (currentMaterial != NULL) //for previous material
	{
		for (int i = 0; i < 9; ++i)
		{
			if (!currentMaterial->mapPaths[i].empty())
			{
				getTokenPath(fileName, currentMaterial->mapPaths[i]);
				if (currentMaterial->requestFile(fileName, i)) //texture loaded
				{
					currentMaterial->mapPaths[i].clear();
				}
			}
		}
		currentMaterial->fillFiles(filePath);
	}
	*/
	file.close();

	return 1;
}