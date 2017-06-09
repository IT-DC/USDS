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

bool UsdsBoolean::getValue() throw (...)
{

	return objectValue;
};


void UsdsBoolean::additionalInitObject()
{


};