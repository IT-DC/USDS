#include "dictionary\dataTypes\dictionaryUInt.h"

using namespace usds;

DictionaryUInt::DictionaryUInt(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryUInt::additionalInitType()
{
	isBigendian = false;
	isDefault = false;
};

void DictionaryUInt::setDefaultValue(uint32_t value)
{
	isDefault = true;
	defaultValue = value;
};

uint32_t DictionaryUInt::getDefaultValue()
{
	return defaultValue;
}

bool DictionaryUInt::hasDefaultValue()
{
	return isDefault;
}

