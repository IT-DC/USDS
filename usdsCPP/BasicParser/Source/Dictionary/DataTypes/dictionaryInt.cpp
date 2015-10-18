#include "dictionary\dataTypes\dictionaryInt.h"

using namespace usds;

DictionaryInt::DictionaryInt()
{


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