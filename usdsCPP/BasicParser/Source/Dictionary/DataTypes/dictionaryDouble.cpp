#include "dictionary\dataTypes\dictionaryDouble.h"

using namespace usds;

DictionaryDouble::DictionaryDouble(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryDouble::additionalInitType()
{
	isDefault = false;
};

void DictionaryDouble::setDefault(double value)
{
	isDefault = true;
	defaultValue = value;
};
