#include "dictionary\dataTypes\dictionaryUVarint.h"

using namespace usds;

DictionaryUVarint::DictionaryUVarint(DictionaryObjectPool* parent) : DictionaryBaseType(parent)
{

	objectType = USDS_UNSIGNED_VARINT;
};

void DictionaryUVarint::clear()
{
	isDefault = false;
};

void DictionaryUVarint::setDefault(long long value)
{
	isDefault = true;
	defaultValue = value;
};