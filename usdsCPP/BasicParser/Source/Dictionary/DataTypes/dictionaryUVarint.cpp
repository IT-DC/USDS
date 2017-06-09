#include "dictionary\dataTypes\dictionaryUVarint.h"

using namespace usds;

DictionaryUVarint::DictionaryUVarint(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryUVarint::additionalInitType()
{
	isDefault = false;
};

void DictionaryUVarint::setDefault(int64_t value)
{
	isDefault = true;
	defaultValue = value;
};