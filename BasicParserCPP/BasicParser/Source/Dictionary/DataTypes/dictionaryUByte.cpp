#include "dictionary\dataTypes\dictionaryUByte.h"

using namespace usds;

DictionaryUByte::DictionaryUByte(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryUByte::additionalInitType()
{
	isDefault = false;
};

void DictionaryUByte::setDefaultValue(uint8_t value)
{
	isDefault = true;
	defaultValue = value;
};

uint8_t DictionaryUByte::getDefaultValue()
{
	return defaultValue;
}

bool DictionaryUByte::hasDefaultValue()
{
	return isDefault;
}

