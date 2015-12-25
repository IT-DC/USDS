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

void UsdsInt::setValue(int value) throw (...)
{
	
	objectValue = value;
};

int UsdsInt::getIntValue() throw (...)
{

	return objectValue;
};