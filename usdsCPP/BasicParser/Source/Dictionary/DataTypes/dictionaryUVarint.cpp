#include "dictionary\dataTypes\dictionaryUVarint.h"

using namespace usds;

DictionaryUVarint::DictionaryUVarint(Dictionary* dict) : DictionaryBaseType(dict)
{

	objectType = USDS_UVARINT;
};

void DictionaryUVarint::initType()
{
	isDefault = false;
};

void DictionaryUVarint::setDefault(int64_t value)
{
	isDefault = true;
	defaultValue = value;
};