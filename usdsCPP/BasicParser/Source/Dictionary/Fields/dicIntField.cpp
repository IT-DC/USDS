#include "dictionary\fields\dicIntField.h"

using namespace usds;

DicIntField::DicIntField()
{


};

void DicIntField::clear()
{
	isDefault = false;
};

void DicIntField::setDefault(int value)
{
	isDefault = true;
	defaultValue = value;
};