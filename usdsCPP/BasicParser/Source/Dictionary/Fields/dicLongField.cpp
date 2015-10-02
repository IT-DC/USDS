#include "dictionary\fields\dicLongField.h"

using namespace usds;

DicLongField::DicLongField()
{


};

void DicLongField::clear()
{
	isDefault = false;
};

void DicLongField::setDefault(long long value)
{
	isDefault = true;
	defaultValue = value;
};