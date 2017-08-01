#include "body\dataTypes\usdsDouble.h"

#include "dictionary\dataTypes\dictionaryDouble.h"

using namespace usds;

UsdsDouble::UsdsDouble(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsDouble::~UsdsDouble()
{
}


void UsdsDouble::additionalInitObject()
{
	if (((DictionaryDouble*)parentDictionaryObject)->hasDefaultValue())
		objectValue = ((DictionaryDouble*)parentDictionaryObject)->getDefaultValue();
};

void UsdsDouble::setValue(float value) throw (...)
{
	objectValue = value;
};

void UsdsDouble::setValue(double value) throw (...)
{
	objectValue = value;
};

void UsdsDouble::getValue(double* value) throw (...)
{

	*value = objectValue;
};

void UsdsDouble::set(double value) throw (...)
{
	objectValue = value;
};

double UsdsDouble::get()
{
	return objectValue;
}

bool UsdsDouble::isBigendian()
{
	return ((DictionaryDouble*)parentDictionaryObject)->getBigendian();
}

