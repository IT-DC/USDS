#include "body\dataTypes\usdsBoolean.h"

using namespace usds;

UsdsBoolean::UsdsBoolean(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsBoolean::~UsdsBoolean()
{
}

void UsdsBoolean::setValue(bool value) throw (...)
{
	objectValue = value;
};

void UsdsBoolean::getValue(bool* value) throw (...)
{
	*value = objectValue;
};

void UsdsBoolean::set(bool value) throw (...)
{
	objectValue = value;
};

bool UsdsBoolean::get() throw (...)
{
	return objectValue;
};

void UsdsBoolean::additionalInitObject()
{


};