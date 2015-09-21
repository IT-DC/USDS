#include "tags\dicStructFields.h"

using namespace usds;

//====================================================================================================================
// Simple types
//====================================================================================================================
// Boolean

void DicBooleanField::writeToBinary(BinaryOutput* buff) throw (...)
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

//====================================================================================================================
// Integer

void DicIntField::writeToBinary(BinaryOutput* buff) throw (...)
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

//====================================================================================================================
// Long

void DicLongField::writeToBinary(BinaryOutput* buff) throw (...)
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

//====================================================================================================================
// Double

void DicDoubleField::writeToBinary(BinaryOutput* buff) throw (...)
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

//====================================================================================================================
// Unsigned Varint

void DicUVarintField::writeToBinary(BinaryOutput* buff) throw (...)
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

//====================================================================================================================
// Array
//====================================================================================================================

void DicArrayField::writeToBinary(BinaryOutput* buff) throw (...)
{

};

void DicArrayField::clear()
{

};

//====================================================================================================================
// String
//====================================================================================================================

void DicStringField::writeToBinary(BinaryOutput* buff) throw (...)
{


};
void DicStringField::clear()
{
	isDefault = false;
	defaultEncode = USDS_NO_ENCODE;
};

void DicStringField::setDefault(const char* value)
{
	isDefault = true;
	defaultValue = value;
};

void DicStringField::setEncode(usdsEncodes encode) throw(...)
{
	defaultEncode = encode;
};