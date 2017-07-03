#include "dictionary\dataTypes\dictionaryString.h"

using namespace usds;

DictionaryString::DictionaryString(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryString::additionalInitType()
{
	defaultEncode = USDS_NO_DEFAULT_ENCODE;

};

void DictionaryString::setDefaultEncode(usdsEncodes value) throw(...)
{
	defaultEncode = value;
};

usdsEncodes DictionaryString::getDefaultEncode() throw(...)
{

	return defaultEncode;
};

void DictionaryString::finalize() throw (...)
{

}