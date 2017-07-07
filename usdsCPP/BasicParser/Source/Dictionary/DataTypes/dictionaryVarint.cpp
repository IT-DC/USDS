#include "dictionary\dataTypes\dictionaryVarint.h"

using namespace usds;

DictionaryVarint::DictionaryVarint(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryVarint::additionalInitType()
{
	isDefault = false;
};

void DictionaryVarint::setDefaultValue(int64_t value)
{
	isDefault = true;
	defaultValue = value;
};

int64_t DictionaryVarint::getDefaultValue()
{
	return defaultValue;
}

bool DictionaryVarint::hasDefaultValue()
{
	return isDefault;
}

