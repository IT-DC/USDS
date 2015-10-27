#include "dictionary\dataTypes\dictionaryBoolean.h"

using namespace usds;

DictionaryBoolean::DictionaryBoolean(DictionaryObjectPool* parent) : DictionaryBaseType(parent)
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
