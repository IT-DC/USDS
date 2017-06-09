#include "body\dataTypes\usdsLong.h"

using namespace usds;

UsdsLong::UsdsLong(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsLong::~UsdsLong()
{
}

void UsdsLong::additionalInitObject()
{


};

void UsdsLong::setValue(int64_t value) throw (...)
{

	objectValue = value;
};

int64_t UsdsLong::getValue() throw (...)
{

	return objectValue;
};