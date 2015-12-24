#include "dictionary\dataTypes\dictionaryBoolean.h"

using namespace usds;

DictionaryBoolean::DictionaryBoolean(Dictionary* dict) : DictionaryBaseType(dict)
{
	objectType = USDS_BOOLEAN;

};

void DictionaryBoolean::clear()
{
	isDefault = false;
	
};

void DictionaryBoolean::setDefault(bool value)
{
	isDefault = true;
	defaultValue = value;
};
