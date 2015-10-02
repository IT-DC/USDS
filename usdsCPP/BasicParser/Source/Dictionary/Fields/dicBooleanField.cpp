#include "dictionary\fields\dicBooleanField.h"

using namespace usds;

DicBooleanField::DicBooleanField()
{


};

void DicBooleanField::clear()
{
	isDefault = false;
	
};

void DicBooleanField::setDefault(bool value)
{
	isDefault = true;
	defaultValue = value;
};
