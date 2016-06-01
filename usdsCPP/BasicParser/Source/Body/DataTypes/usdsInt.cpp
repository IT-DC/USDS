#include "body\dataTypes\usdsInt.h"

using namespace usds;

UsdsInt::UsdsInt(Body* parent_body) : UsdsBaseType(parent_body)
{
	objectType = USDS_INT;
}

UsdsInt::~UsdsInt()
{
}

void UsdsInt::initType()
{


};

void UsdsInt::setValue(int32_t value) throw (...)
{
	
	objectValue = value;
};

int32_t UsdsInt::getIntValue() throw (...)
{

	return objectValue;
};