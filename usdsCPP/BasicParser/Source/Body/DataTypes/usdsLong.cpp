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

void UsdsLong::setValue(long long value) throw (...)
{

	objectValue = value;
};

long long UsdsLong::getLongValue() throw (...)
{

	return objectValue;
};