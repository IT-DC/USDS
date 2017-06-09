#include "body\dataTypes\usdsDouble.h"

using namespace usds;

UsdsDouble::UsdsDouble(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsDouble::~UsdsDouble()
{
}


void UsdsDouble::additionalInitObject()
{


};

void UsdsDouble::setValue(double value) throw (...)
{

	objectValue = value;
};

double UsdsDouble::getValue() throw (...)
{

	return objectValue;
};