#include "dictionary\dataTypes\dictionaryString.h"

using namespace usds;

DictionaryString::DictionaryString(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryString::additionalInitType()
{
	encode = USDS_NO_DEFAULT_ENCODE;

};

void DictionaryString::setEncode(usdsEncodes value) throw(...)
{
	encode = value;
};

usdsEncodes DictionaryString::getEncode() throw(...)
{

	return encode;
};

void DictionaryString::finalize() throw (...)
{

}