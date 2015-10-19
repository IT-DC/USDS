#include "dictionary\dataTypes\dictionaryString.h"

using namespace usds;

DictionaryString::DictionaryString()
{


};

void DictionaryString::clear()
{
	isDefault = false;
	defaultEncode = USDS_NO_ENCODE;

};

void DictionaryString::setDefault(const char* value)
{
	isDefault = true;
	defaultValue = value;
};

void DictionaryString::setEncode(usdsEncodes encode) throw(...)
{
	defaultEncode = encode;
};

usdsEncodes DictionaryString::getEncode() throw(...)
{

	return defaultEncode;
};