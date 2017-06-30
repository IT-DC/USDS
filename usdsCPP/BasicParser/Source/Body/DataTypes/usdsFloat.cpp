#include "body\dataTypes\usdsFloat.h"

#include "dictionary\dataTypes\dictionaryFloat.h"

using namespace usds;

UsdsFloat::UsdsFloat(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsFloat::~UsdsFloat()
{
}


void UsdsFloat::additionalInitObject()
{


};

void UsdsFloat::setValue(float value) throw (...)
{
	objectValue = value;
};

void UsdsFloat::getValue(double* value) throw (...)
{

	*value = objectValue;
};

void UsdsFloat::getValue(float* value) throw (...)
{

	*value = objectValue;
};

void UsdsFloat::set(float value) throw (...)
{
	objectValue = value;
};

float UsdsFloat::get()
{
	return objectValue;
}

bool UsdsFloat::isBigendian()
{
	return ((DictionaryFloat*)parentDictionaryObject)->getBigendian();
}


