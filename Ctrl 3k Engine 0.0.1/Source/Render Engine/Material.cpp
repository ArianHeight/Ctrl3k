#include <Ctrl 3kPCH.h>

/*

Material Object
stores data from .mtl file given the file path

has all the material values needed for rendering

*/

//constructor : loads .mtl given file path, sets the success bool to true or false depending on loading success
Material::Material(std::string &name) : m_name(name.c_str())
{
	//cstr
}

//activates findTexture(), if texture is found, then set the corresponding m_map value to the texture index and return true, if not return false
bool Material::requestFile(std::string &fileName, int map)
{
	int texture = findTexture(fileName.c_str());
	this->m_maps[map] = texture;

	if (texture != -1)
	{
		return true;
	}
	return false;
}

//iterates through m_mapPaths and loads any texture that has not been loaded in yet
void Material::fillFiles(std::string &materialSourceFilePath)
{
	//finds filepath sans filename of the .mtl file
	unsigned int index = materialSourceFilePath.find_last_of('/');
	std::string path = materialSourceFilePath.substr(0, index + 1); //index + 1 because we need that last /

	std::string search; //temp variable used to hold final path passed to loadTextureObject()
	for (int i = 0; i < 9; ++i)
	{
		if (!this->mapPaths[i].empty())
		{
			search = path + this->mapPaths[i]; //search is set to final path by combining .mtl path and the texture's relative path

			this->m_maps[i] = loadTextureObject(search);
			this->mapPaths[i].clear();
		}
	}
}

//destructor
Material::~Material()
{
	
}
/*

end Material Object

*/