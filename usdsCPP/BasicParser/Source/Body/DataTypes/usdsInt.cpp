#include "body\dataTypes\usdsInt.h"

using namespace usds;

UsdsInt::UsdsInt(BodyObjectPool* object_pool) : UsdsBaseType(object_pool)
{
}

UsdsInt::~UsdsInt()
{
}

void UsdsInt::clear()
{


};

void UsdsInt::setValue(int value) throw (...)
{
	
	objectValue = value;
};

int UsdsInt::getIntValue() throw (...)
{

	return objectValue;
};