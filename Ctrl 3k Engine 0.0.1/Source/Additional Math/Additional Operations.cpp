#include <Ctrl 3kPCH.h>

//sets in vector3 to magnitude of itself
float magnitude3(glm::vec3 &in)
{
	return (sqrtf((in[0] * in[0]) + (in[1] * in[1]) + (in[2] * in[2])));
}

//returns true if the vector3 does not have a vector3 counterpart in the std::vector with exact same values, sets firstPos to the position of the counterpart if so
bool isInVector(glm::uvec3 &in, std::vector<glm::uvec3> &vect, int &firstPos)
{
	int size = vect.size();
	for (int i = 0; i < size; ++i)
	{
		if (vect[i] == in)
		{
			firstPos = i;
			return true;
		}
	}
	return false;
}