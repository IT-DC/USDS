#include "dictionary\dataTypes\dictionaryString.h"

using namespace usds;

DictionaryString::DictionaryString(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryString::additionalInitType()
{
	isDefault = false;
	encode = USDS_NO_ENCODE;

};

void DictionaryString::setDefault(const char* value)
{
	isDefault = true;
	defaultValue = value;
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

	if (encode == USDS_NO_ENCODE)
		throw ErrorStack("DictionaryString::finalize") << ErrorMessage(DIC_STRING__ERROR_ENCODE, "Encode was not set");
}