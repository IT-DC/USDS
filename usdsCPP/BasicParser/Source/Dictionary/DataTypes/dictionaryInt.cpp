#include "dictionary\dataTypes\dictionaryInt.h"

using namespace usds;

DictionaryInt::DictionaryInt(DictionaryObjectPool* parent) : DictionaryBaseType(parent)
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