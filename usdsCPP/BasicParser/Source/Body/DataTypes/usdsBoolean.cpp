#include "body\dataTypes\usdsBoolean.h"

using namespace usds;

UsdsBoolean::UsdsBoolean(BodyObjectPool* object_pool) : UsdsBaseType(object_pool)
{
}

UsdsBoolean::~UsdsBoolean()
{
}

void UsdsBoolean::setValue(bool value)
{

	objectValue = value;
};

bool UsdsBoolean::getValue()
{

	return objectValue;
};


void UsdsBoolean::clear()
{


};