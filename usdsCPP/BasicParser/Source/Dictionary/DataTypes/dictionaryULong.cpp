#include "dictionary\dataTypes\dictionaryULong.h"

using namespace usds;

DictionaryULong::DictionaryULong(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryULong::additionalInitType()
{
	isBigendian = false;
	isDefault = false;
};

void DictionaryULong::setDefaultValue(uint64_t value)
{
	isDefault = true;
	defaultValue = value;
};

uint64_t DictionaryULong::getDefaultValue()
{
	return defaultValue;
}

bool DictionaryULong::hasDefaultValue()
{
	return isDefault;
}

