#include "body\dataTypes\usdsUVarint.h"

using namespace usds;

UsdsUVarint::UsdsUVarint(BodyObjectPool* object_pool) : UsdsBaseType(object_pool)
{

}

UsdsUVarint::~UsdsUVarint()
{
}

void UsdsUVarint::clear()
{


};

void UsdsUVarint::setValue(int value) throw (...)
{
	if (value < 0)
	{
		std::stringstream msg;
		msg << "Value must be in range [0, 2147483647], current valu: " << value;
		throw ErrorMessage(USDS_UVARINT_ERROR_VALUE, &msg, L"UsdsUVarint::setValue(int)");
	}

	objectValue = value;
};

void UsdsUVarint::setValue(long long value) throw (...)
{
	if (value < 0)
	{
		std::stringstream msg;
		msg << "Value must be in range [0, (2^63 – 1)], current valu: " << value;
		throw ErrorMessage(USDS_UVARINT_ERROR_VALUE, &msg, L"UsdsUVarint::setValue(long long)");
	}

	objectValue = value;
};

void setValue(unsigned long long value) throw (...)
{

	objectValue = value;
};

int UsdsUVarint::getIntValue() throw (...)
{
	if (objectValue > 2147483647)
	{
		std::stringstream msg;
		msg << "Value is too big for 'int': " << objectValue;
		throw ErrorMessage(USDS_UVARINT_ERROR_VALUE, &msg, L"UsdsUVarint::setValue(long long)");
	}

	return int(objectValue);
};

long long UsdsUVarint::getLongValue() throw (...)
{
	if (objectValue > 9223372036854775807)
	{
		std::stringstream msg;
		msg << "Value is too big for 'long long': " << objectValue;
		throw ErrorMessage(USDS_UVARINT_ERROR_VALUE, &msg, L"UsdsUVarint::setValue(long long)");
	}

	return objectValue;

};

unsigned long long UsdsUVarint::getULongValue() throw (...)
{
	return objectValue;
};