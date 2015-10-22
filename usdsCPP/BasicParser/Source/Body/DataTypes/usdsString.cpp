#include "body\dataTypes\usdsString.h"

using namespace usds;

UsdsString::UsdsString(BodyObjectPool* object_pool) : UsdsBaseType(object_pool)
{
}

UsdsString::~UsdsString()
{
}

void UsdsString::clear()
{


};

void UsdsString::setValue(const char* value) throw (...)
{

	objectValue = value;
};

const char* UsdsString::getStringValue() throw (...)
{

	return objectValue.c_str();
};