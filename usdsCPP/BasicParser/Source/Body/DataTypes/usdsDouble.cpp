#include "body\dataTypes\usdsDouble.h"

using namespace usds;

UsdsDouble::UsdsDouble(Body* parent_body) : UsdsBaseType(parent_body)
{
	objectType = USDS_DOUBLE;
}

UsdsDouble::~UsdsDouble()
{
}


void UsdsDouble::initType()
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