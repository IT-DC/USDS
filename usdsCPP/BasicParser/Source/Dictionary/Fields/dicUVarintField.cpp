#include "dictionary\fields\dicUVarintField.h"

using namespace usds;

DicUVarintField::DicUVarintField()
{


};

void DicUVarintField::clear()
{
	isDefault = false;
};

void DicUVarintField::setDefault(long long value)
{
	isDefault = true;
	defaultValue = value;
};