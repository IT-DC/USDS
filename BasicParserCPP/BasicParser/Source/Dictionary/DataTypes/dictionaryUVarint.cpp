#include "dictionary\dataTypes\dictionaryUVarint.h"

using namespace usds;

DictionaryUVarint::DictionaryUVarint(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryUVarint::additionalInitType()
{
	isDefault = false;
};

void DictionaryUVarint::setDefaultValue(uint64_t value)
{
	isDefault = true;
	defaultValue = value;
};

uint64_t DictionaryUVarint::getDefaultValue()
{
	return defaultValue;
}

bool DictionaryUVarint::hasDefaultValue()
{
	return isDefault;
}
