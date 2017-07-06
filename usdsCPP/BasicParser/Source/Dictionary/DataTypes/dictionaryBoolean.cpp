#include "dictionary\dataTypes\dictionaryBoolean.h"

using namespace usds;

DictionaryBoolean::DictionaryBoolean(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryBoolean::additionalInitType()
{
	isDefault = false;
	
};

void DictionaryBoolean::setDefaultValue(bool value)
{
	isDefault = true;
	defaultValue = value;
};


bool DictionaryBoolean::getDefaultValue()
{
	return defaultValue;
}

bool DictionaryBoolean::hasDefaultValue()
{
	return isDefault;
}

