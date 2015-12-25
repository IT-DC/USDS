#include "body\dataTypes\usdsBoolean.h"

using namespace usds;

UsdsBoolean::UsdsBoolean(Body* parent_body) : UsdsBaseType(parent_body)
{
	objectType = USDS_BOOLEAN;
}

UsdsBoolean::~UsdsBoolean()
{
}

void UsdsBoolean::setValue(bool value) throw (...)
{

	objectValue = value;
};

bool UsdsBoolean::getBooleanValue() throw (...)
{

	return objectValue;
};


void UsdsBoolean::initType()
{


};