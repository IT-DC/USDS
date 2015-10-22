#include "body\dataTypes\usdsLong.h"

using namespace usds;

UsdsLong::UsdsLong(BodyObjectPool* object_pool) : UsdsBaseType(object_pool)
{
}

UsdsLong::~UsdsLong()
{
}

void UsdsLong::clear()
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