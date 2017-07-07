#include "dictionary\dataTypes\dictionaryUShort.h"

using namespace usds;

DictionaryUShort::DictionaryUShort(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryUShort::additionalInitType()
{
	isBigendian = false;
	isDefault = false;
};

void DictionaryUShort::setDefaultValue(uint16_t value)
{
	isDefault = true;
	defaultValue = value;
};

uint16_t DictionaryUShort::getDefaultValue()
{
	return defaultValue;
}

bool DictionaryUShort::hasDefaultValue()
{
	return isDefault;
}

