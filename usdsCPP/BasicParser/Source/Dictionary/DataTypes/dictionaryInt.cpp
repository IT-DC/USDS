#include "dictionary\dataTypes\dictionaryInt.h"

using namespace usds;

DictionaryInt::DictionaryInt(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryInt::additionalInitType()
{
	isBigendian = false;
	isDefault = false;
};

void DictionaryInt::setDefaultValue(int32_t value)
{
	isDefault = true;
	defaultValue = value;
};

int32_t DictionaryInt::getDefaultValue()
{
	return defaultValue;
}

bool DictionaryInt::hasDefaultValue()
{
	return isDefault;
}

