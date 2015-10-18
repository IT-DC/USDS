#include "dictionary\dataTypes\dictionaryDouble.h"

using namespace usds;

DictionaryDouble::DictionaryDouble()
{


};

void DictionaryDouble::clear()
{
	isDefault = false;
};

void DictionaryDouble::setDefault(double value)
{
	isDefault = true;
	defaultValue = value;
};
