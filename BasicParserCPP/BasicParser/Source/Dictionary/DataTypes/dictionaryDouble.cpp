#include "dictionary\dataTypes\dictionaryDouble.h"

using namespace usds;

DictionaryDouble::DictionaryDouble(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryDouble::additionalInitType()
{
	isBigendian = false;
	isDefault = false;
};

void DictionaryDouble::setDefaultValue(double value)
{
	isDefault = true;
	defaultValue = value;
};

double DictionaryDouble::getDefaultValue()
{
	return defaultValue;
}

bool DictionaryDouble::hasDefaultValue()
{
	return isDefault;
}



