#include "body\dataTypes\usdsBoolean.h"

using namespace usds;

UsdsBoolean::UsdsBoolean(BodyObjectPool* object_pool) : UsdsBaseType(object_pool)
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


void UsdsBoolean::clear()
{


};