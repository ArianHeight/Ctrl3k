#include <Ctrl 3kPCH.h>

/*

Data Block Object
a "block" of data, is able to tell what valid type of data it is

*/

//constructor
DataBlock::DataBlock(std::string &data) : m_data{data.c_str()}
{
	this->updateDataType();
}

//self-explanetory
void DataBlock::updateDataType()
{
	char type = ' ';

	for (char c : m_data) //test for type
	{
		switch (c)
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
		case '-':
			if (type != 'c' && type != 'f' && type != 'n') { type = 'i'; }
			break;
		case '.':
			if (type != 'c' && type != 'n') { type = 'f'; }
			break;
		case '/':
			type = 'n';
			break;
		default:
			if (type != 'n') { type = 'c'; }
			break;
		}
	}
	this->m_datatype = type;
}

//changes the data the block holds
void DataBlock::changeData(std::string &data)
{
	this->m_data.clear();
	this->m_data = data.c_str();

	this->updateDataType();
}

//sets m_data = ""
void DataBlock::clear()
{
	this->m_data.clear();
	this->m_datatype = ' ';
}

//destructor
DataBlock::~DataBlock()
{

}
