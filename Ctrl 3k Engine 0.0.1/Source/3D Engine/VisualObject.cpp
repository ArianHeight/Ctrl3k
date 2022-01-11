#include <Ctrl 3kPCH.h>

/*

Visual Object

*/

//constructor
VisualObject::VisualObject(std::string &objectSourceFilePath, bool &success)
{
	success = loadObj(objectSourceFilePath, *this);
}

//destructor
VisualObject::~VisualObject()
{
	//dstr
}
/*

end Visual Object

*/