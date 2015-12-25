#include "body\dataTypes\usdsUVarint.h"

using namespace usds;

UsdsUVarint::UsdsUVarint(Body* parent_body) : UsdsBaseType(parent_body)
{
	objectType = USDS_UNSIGNED_VARINT;
}

UsdsUVarint::~UsdsUVarint()
{
}

void UsdsUVarint::initType()
{


};

void UsdsUVarint::setValue(int value) throw (...)
{
	if (value < 0)
		throw ErrorStack("UsdsUVarint::setValue") << value << (ErrorMessage(BODY_UVARINT__ERROR_VALUE) << "Value must be in range [0, 2147483647], current valu: " << value);

	objectValue = value;
};

void UsdsUVarint::setValue(long long value) throw (...)
{
	if (value < 0)
		throw ErrorStack("UsdsUVarint::setValue") << value << (ErrorMessage(BODY_UVARINT__ERROR_VALUE) << "Value must be in range [0, (2^63 – 1)], current valu: " << value);

	objectValue = value;
};

void UsdsUVarint::setValue(unsigned long long value) throw (...)
{

	objectValue = value;
};

int UsdsUVarint::getIntValue() throw (...)
{
	if (objectValue > 2147483647)
		throw ErrorStack("UsdsUVarint::getIntValue") << (ErrorMessage(BODY_UVARINT__ERROR_VALUE) << "Value is too big for 'int': " << objectValue);

	return int(objectValue);
};

long long UsdsUVarint::getLongValue() throw (...)
{
	if (objectValue > 9223372036854775807)
		throw ErrorStack("UsdsUVarint::getLongValue") << (ErrorMessage(BODY_UVARINT__ERROR_VALUE) << "Value is too big for 'long long': " << objectValue);

	return objectValue;

};

unsigned long long UsdsUVarint::getULongValue() throw (...)
{
	return objectValue;
};