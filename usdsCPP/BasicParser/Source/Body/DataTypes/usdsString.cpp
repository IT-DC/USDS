#include "body\dataTypes\usdsString.h"

#include "dictionary\dataTypes\dictionaryString.h"

#pragma warning (disable : 4996)

using namespace usds;

UsdsString::UsdsString(Body* parent_body) : UsdsBaseType(parent_body)
{
	buffSize = 16;
	valueSize = 0;
	objectValue = new char[buffSize];
}

UsdsString::~UsdsString()
{
	delete[] objectValue;
}

void UsdsString::additionalInitObject()
{


};

void UsdsString::setValue(const char* value) throw (...)
{
	valueSize = strlen(value);
	if (valueSize >= buffSize)
	{
		delete[] objectValue;
		buffSize = valueSize + 1;
		objectValue = new char[buffSize];
	}
	strncpy(objectValue, value, valueSize);
	objectValue[valueSize] = 0;
};

void UsdsString::setValue(const char* value, size_t size) throw (...)
{
	valueSize = size;
	if (valueSize >= buffSize)
	{
		delete[] objectValue;
		buffSize = valueSize + 1;
		objectValue = new char[buffSize];
	}
	strncpy(objectValue, value, valueSize);
	objectValue[valueSize] = 0;

};

const char* UsdsString::getValue() throw (...)
{

	return objectValue;
};

size_t UsdsString::getSize() throw (...)
{

	return valueSize;
};