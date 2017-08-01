#include "dictionary\dataTypes\dictionaryShort.h"

using namespace usds;

DictionaryShort::DictionaryShort(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryShort::additionalInitType()
{
	isBigendian = false;
	isDefault = false;
};

void DictionaryShort::setDefaultValue(int16_t value)
{
	isDefault = true;
	defaultValue = value;
};

int16_t DictionaryShort::getDefaultValue()
{
	return defaultValue;
}

bool DictionaryShort::hasDefaultValue()
{
	return isDefault;
}


