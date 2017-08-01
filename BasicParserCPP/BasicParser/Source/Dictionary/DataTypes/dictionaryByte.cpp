#include "dictionary\dataTypes\dictionaryByte.h"

using namespace usds;

DictionaryByte::DictionaryByte(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryByte::additionalInitType()
{
	isDefault = false;
};

void DictionaryByte::setDefaultValue(int8_t value)
{
	isDefault = true;
	defaultValue = value;
};

int8_t DictionaryByte::getDefaultValue()
{
	return defaultValue;
}

bool DictionaryByte::hasDefaultValue()
{
	return isDefault;
}

