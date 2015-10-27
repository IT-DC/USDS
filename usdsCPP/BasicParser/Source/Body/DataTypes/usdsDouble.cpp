#include "body\dataTypes\usdsDouble.h"

using namespace usds;

UsdsDouble::UsdsDouble(BodyObjectPool* object_pool) : UsdsBaseType(object_pool)
{
	objectType = USDS_DOUBLE;
}

UsdsDouble::~UsdsDouble()
{
}


void UsdsDouble::clear()
{


};

void UsdsDouble::setValue(double value) throw (...)
{

	objectValue = value;
};

double UsdsDouble::getDoubleValue() throw (...)
{

	return objectValue;
};