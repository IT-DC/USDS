#include "dictionary\fields\dicStringField.h"

using namespace usds;

DicStringField::DicStringField()
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

usdsEncodes DicStringField::getEncode() throw(...)
{

	return defaultEncode;
};