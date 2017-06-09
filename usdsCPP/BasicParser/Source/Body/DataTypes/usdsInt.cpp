#include "body\dataTypes\usdsInt.h"

using namespace usds;

UsdsInt::UsdsInt(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsInt::~UsdsInt()
{
}

void UsdsInt::additionalInitObject()
{


};

void UsdsInt::setValue(int8_t value) throw (...)
{

	objectValue = value;
};

void UsdsInt::setValue(uint8_t value) throw (...)
{
	
	objectValue = value;
};

void UsdsInt::setValue(int16_t value) throw (...)
{

	objectValue = value;
};

void UsdsInt::setValue(uint16_t value) throw (...)
{

	objectValue = value;
};

void UsdsInt::setValue(int32_t value) throw (...)
{

	objectValue = value;
};

void UsdsInt::setValue(uint32_t value) throw (...)
{
	if (value > 2147483647)
		throw ErrorStack("UsdsInt::setValue") << value << (ErrorMessage(BODY_INT__TOO_BIG_VALUE) << "Value must be in range[-2147483648, 2147483647], current value : " << value);
	objectValue = value;
};

void UsdsInt::setValue(int64_t value) throw (...)
{
	if (value > 2147483647 || value < -2147483648ll)
		throw ErrorStack("UsdsInt::setValue") << value << (ErrorMessage(BODY_INT__TOO_BIG_VALUE) << "Value must be in range[-2147483648, 2147483647], current value : " << value);
	objectValue = (int32_t)value;
};

void UsdsInt::setValue(uint64_t value) throw (...)
{
	if (value > 2147483647)
		throw ErrorStack("UsdsInt::setValue") << value << (ErrorMessage(BODY_INT__TOO_BIG_VALUE) << "Value must be in range[-2147483648, 2147483647], current value : " << value);
	objectValue = (int32_t)value;
};


void UsdsInt::getValue(int8_t* value) throw (...)
{
	if (objectValue > 127 || objectValue < -128)
		throw ErrorStack("UsdsInt::getValue") << value << (ErrorMessage(BODY_INT__TOO_BIG_VALUE) << "Too big value for int8_t, current value : " << value);
	*value = objectValue;
};

void UsdsInt::getValue(uint8_t* value) throw (...)
{
	if (objectValue > 255 || objectValue < 0)
		throw ErrorStack("UsdsInt::getValue") << value << (ErrorMessage(BODY_INT__TOO_BIG_VALUE) << "Too big value for uint8_t, current value : " << value);
	*value = objectValue;
};

void UsdsInt::getValue(int16_t* value) throw (...)
{
	if (objectValue > 32767 || objectValue < -32768)
		throw ErrorStack("UsdsInt::getValue") << value << (ErrorMessage(BODY_INT__TOO_BIG_VALUE) << "Too big value for int16_t, current value : " << value);
	*value = objectValue;
};

void UsdsInt::getValue(uint16_t* value) throw (...)
{
	if (objectValue > 65535 || objectValue < 0)
		throw ErrorStack("UsdsInt::getValue") << value << (ErrorMessage(BODY_INT__TOO_BIG_VALUE) << "Too big value for uint16_t, current value : " << value);
	*value = objectValue;
};

void UsdsInt::getValue(int32_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsInt::getValue(uint32_t* value) throw (...)
{
	if (objectValue < 0)
		throw ErrorStack("UsdsInt::getValue") << value << (ErrorMessage(BODY_INT__TOO_BIG_VALUE) << "Too big value for uint32_t, current value : " << value);
	*value = objectValue;
};

void UsdsInt::getValue(int64_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsInt::getValue(uint64_t* value) throw (...)
{
	if (objectValue < 0)
		throw ErrorStack("UsdsInt::getValue") << value << (ErrorMessage(BODY_INT__TOO_BIG_VALUE) << "Too big value for uint64_t, current value : " << value);
	*value = objectValue;
};

int32_t UsdsInt::getValue()
{
	return objectValue;
};