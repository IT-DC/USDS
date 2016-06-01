#include "body\dataTypes\usdsLong.h"

using namespace usds;

UsdsLong::UsdsLong(Body* parent_body) : UsdsBaseType(parent_body)
{
	objectType = USDS_LONG;
}

UsdsLong::~UsdsLong()
{
}

void UsdsLong::initType()
{


};

void UsdsLong::setValue(int64_t value) throw (...)
{

	objectValue = value;
};

int64_t UsdsLong::getLongValue() throw (...)
{

	return objectValue;
};