#include "body\dataTypes\usdsString.h"

#include "dictionary\dataTypes\dictionaryString.h"

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

void UsdsString::setValue(const char* value, size_t size) throw (...)
{
	objectValue.assign(value, size);

};

const char* UsdsString::getStringValue() throw (...)
{

	return objectValue.c_str();
};

const char* UsdsString::getStringValue(size_t* size) throw (...)
{
	*size = objectValue.size();
	return objectValue.c_str();
};