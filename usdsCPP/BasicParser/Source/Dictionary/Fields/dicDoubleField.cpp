#include "dictionary\fields\dicDoubleField.h"

using namespace usds;

DicDoubleField::DicDoubleField()
{


};

void DicDoubleField::clear()
{
	isDefault = false;
};

void DicDoubleField::setDefault(double value)
{
	isDefault = true;
	defaultValue = value;
};
