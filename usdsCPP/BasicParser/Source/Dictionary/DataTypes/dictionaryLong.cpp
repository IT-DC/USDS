#include "dictionary\dataTypes\dictionaryLong.h"

using namespace usds;

DictionaryLong::DictionaryLong()
{


};

void DictionaryLong::clear()
{
	isDefault = false;
};

void DictionaryLong::setDefault(long long value)
{
	isDefault = true;
	defaultValue = value;
};