#include "dictionary\dataTypes\dictionaryInt.h"

using namespace usds;

DictionaryInt::DictionaryInt(Dictionary* dict) : DictionaryBaseType(dict)
{

	objectType = USDS_INT;
};

void DictionaryInt::clear()
{
	isDefault = false;
};

void DictionaryInt::setDefault(int value)
{
	isDefault = true;
	defaultValue = value;
};