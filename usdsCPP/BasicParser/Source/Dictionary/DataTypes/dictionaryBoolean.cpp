#include "dictionary\dataTypes\dictionaryBoolean.h"

using namespace usds;

DictionaryBoolean::DictionaryBoolean(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryBoolean::additionalInitType()
{
	isDefault = false;
	
};

void DictionaryBoolean::setDefault(bool value)
{
	isDefault = true;
	defaultValue = value;
};
