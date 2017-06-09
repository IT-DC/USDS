#include "dictionary\dataTypes\dictionaryLong.h"

using namespace usds;

DictionaryLong::DictionaryLong(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryLong::additionalInitType()
{
	isDefault = false;
};

void DictionaryLong::setDefault(int64_t value)
{
	isDefault = true;
	defaultValue = value;
};