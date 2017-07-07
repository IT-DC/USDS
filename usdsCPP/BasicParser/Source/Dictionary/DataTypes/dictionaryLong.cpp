#include "dictionary\dataTypes\dictionaryLong.h"

using namespace usds;

DictionaryLong::DictionaryLong(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryLong::additionalInitType()
{
	isBigendian = false;
	isDefault = false;
};

void DictionaryLong::setDefaultValue(int64_t value)
{
	isDefault = true;
	defaultValue = value;
};

int64_t DictionaryLong::getDefaultValue()
{
	return defaultValue;
}

bool DictionaryLong::hasDefaultValue()
{
	return isDefault;
}


