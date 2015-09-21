#include "tags\dicStructTag.h"

using namespace usds;

void DicStructTag::writeToBinary(BinaryOutput buff) throw(...)
{


};

void DicStructTag::clear()
{
	firstField = 0;
	lastField = 0;
};

DicBaseField* DicStructTag::getFirstField()
{

	return firstField;
};

DicBaseField* DicStructTag::getLastField()
{

	return lastField;
};

DicIntField* DicStructTag::addIntField(const char* name, int id, bool optional) throw(...)
{


};
DicIntField* DicStructTag::addIntField(const char* name, int id, int default_value) throw(...)
{


};