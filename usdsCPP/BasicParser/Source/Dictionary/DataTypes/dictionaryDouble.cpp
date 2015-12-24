#include "dictionary\dataTypes\dictionaryDouble.h"

using namespace usds;

DictionaryDouble::DictionaryDouble(Dictionary* dict) : DictionaryBaseType(dict)
{

	objectType = USDS_DOUBLE;
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
