#include "dictionary\dataTypes\dictionaryString.h"
#include  "dictionary/usdsDictionary.h"

#pragma warning (disable : 4996)

using namespace usds;

DictionaryString::DictionaryString(Dictionary* dict) : DictionaryBaseType(dict)
{
	defaultValue = 0;
};

DictionaryString::~DictionaryString()
{
	if (defaultValue != 0)
		delete[] defaultValue;
};


void DictionaryString::additionalInitType()
{
	if (dictionary != 0)
		defaultEncode = dictionary->getDefaultStringEncode();
	else
		defaultEncode = USDS_NO_DEFAULT_ENCODE;
	isDefault = false;
};

void DictionaryString::setDefaultEncode(usdsEncode value) throw(...)
{
	defaultEncode = value;
};

usdsEncode DictionaryString::getDefaultEncode() throw(...)
{
	return defaultEncode;
};

void DictionaryString::setDefaultValueFromUTF8(const char* value)
{
	isDefault = true;
	size_t size = strlen(value) + 1;
	if (defaultValue == 0)
	{
		defaultValueBufferSize = size;
		defaultValue = new char[defaultValueBufferSize];
	}
	else
	{
		if (size > defaultValueBufferSize)
		{
			delete[] defaultValue;
			defaultValueBufferSize = size;
			defaultValue = new char[defaultValueBufferSize];
		}
	}
	strcpy(defaultValue, value);
};

void DictionaryString::setDefaultValueFromUTF8(const char* value, size_t byte_size)
{
	isDefault = true;

	if (byte_size == 0)
	{
		byte_size = 1;
	}
	else
	{
		if (value[byte_size - 1] != 0)
			byte_size++;
	}
	if (defaultValue == 0)
	{
		defaultValueBufferSize = byte_size;
		defaultValue = new char[defaultValueBufferSize];
	}
	else
	{
		if (byte_size > defaultValueBufferSize)
		{
			delete[] defaultValue;
			defaultValueBufferSize = byte_size;
			defaultValue = new char[defaultValueBufferSize];
		}
	}
	
	memcpy(defaultValue, value, byte_size - 1);
	defaultValue[byte_size - 1] = 0;
};

const char* DictionaryString::getUTF8DefaultValue()
{
	return defaultValue;
};

bool DictionaryString::hasDefaultValue()
{
	return isDefault;
};

void DictionaryString::finalize() throw (...)
{

}