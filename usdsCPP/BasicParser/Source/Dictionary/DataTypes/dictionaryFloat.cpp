#include "dictionary\dataTypes\dictionaryFloat.h"

using namespace usds;

DictionaryFloat::DictionaryFloat(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryFloat::additionalInitType()
{
	isBigendian = false;
	isDefault = false;
};

void DictionaryFloat::setDefaultValue(float value)
{
	isDefault = true;
	defaultValue = value;
};

float DictionaryFloat::getDefaultValue()
{
	return defaultValue;
}

bool DictionaryFloat::hasDefaultValue()
{
	return isDefault;
}
