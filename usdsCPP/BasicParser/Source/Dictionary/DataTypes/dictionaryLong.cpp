#include "dictionary\dataTypes\dictionaryLong.h"

using namespace usds;

DictionaryLong::DictionaryLong(Dictionary* dict) : DictionaryBaseType(dict)
{

	objectType = USDS_LONG;
};

void DictionaryLong::initType()
{
	isDefault = false;
};

void DictionaryLong::setDefault(int64_t value)
{
	isDefault = true;
	defaultValue = value;
};