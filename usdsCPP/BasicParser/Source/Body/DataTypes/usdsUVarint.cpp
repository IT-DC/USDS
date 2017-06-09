#include "body\dataTypes\usdsUVarint.h"

using namespace usds;

UsdsUVarint::UsdsUVarint(Body* parent_body) : UsdsBaseType(parent_body)
{
	
}

UsdsUVarint::~UsdsUVarint()
{
}

void UsdsUVarint::additionalInitObject()
{


};

void UsdsUVarint::setValue(int32_t value) throw (...)
{
	if (value < 0)
		throw ErrorStack("UsdsUVarint::setValue") << value << (ErrorMessage(BODY_UVARINT__ERROR_VALUE) << "Value must be in range [0, 2147483647], current value: " << value);

	objectValue = value;
};

void UsdsUVarint::setValue(int64_t value) throw (...)
{
	if (value < 0)
		throw ErrorStack("UsdsUVarint::setValue") << value << (ErrorMessage(BODY_UVARINT__ERROR_VALUE) << "Value must be in range [0, (2^63 – 1)], current value: " << value);

	objectValue = value;
};

void UsdsUVarint::setValue(uint64_t value) throw (...)
{

	objectValue = value;
};

int32_t UsdsUVarint::getIntValue() throw (...)
{
	if (objectValue > 2147483647)
		throw ErrorStack("UsdsUVarint::getIntValue") << (ErrorMessage(BODY_UVARINT__ERROR_VALUE) << "Value is too big for 'int': " << objectValue);

	return int(objectValue);
};

int64_t UsdsUVarint::getLongValue() throw (...)
{
	if (objectValue > 9223372036854775807)
		throw ErrorStack("UsdsUVarint::getLongValue") << (ErrorMessage(BODY_UVARINT__ERROR_VALUE) << "Value is too big for 'int64_t': " << objectValue);

	return objectValue;

};

uint64_t UsdsUVarint::getULongValue() throw (...)
{
	return objectValue;
};