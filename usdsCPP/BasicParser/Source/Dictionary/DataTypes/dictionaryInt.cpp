#include "dictionary\dataTypes\dictionaryInt.h"

using namespace usds;

DictionaryInt::DictionaryInt(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryInt::additionalInitType()
{
	isDefault = false;
};

void DictionaryInt::setDefault(int32_t value)
{
	isDefault = true;
	defaultValue = value;
};