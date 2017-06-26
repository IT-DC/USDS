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

void UsdsLong::setValue(int8_t value) throw (...)
{

	objectValue = value;
};

void UsdsLong::setValue(uint8_t value) throw (...)
{

	objectValue = value;
};

void UsdsLong::setValue(int16_t value) throw (...)
{

	objectValue = value;
};

void UsdsLong::setValue(uint16_t value) throw (...)
{

	objectValue = value;
};

void UsdsLong::setValue(int32_t value) throw (...)
{

	objectValue = value;
};

void UsdsLong::setValue(uint32_t value) throw (...)
{

	objectValue = value;
};

void UsdsLong::setValue(int64_t value) throw (...)
{
	objectValue = value;
};

void UsdsLong::setValue(uint64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_LONG, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsLong::setValue") << value;
	throw;
};

int64_t UsdsLong::get()
{
	return objectValue;
};

void UsdsLong::set(int64_t value)
{
	objectValue = value;
};


void UsdsLong::getValue(int8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsLong::getValue") << value;
	throw;
};

void UsdsLong::getValue(uint8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsLong::getValue") << value;
	throw;
};

void UsdsLong::getValue(int16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsLong::getValue") << value;
	throw;
};

void UsdsLong::getValue(uint16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsLong::getValue") << value;
	throw;
};

void UsdsLong::getValue(int32_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsLong::getValue") << value;
	throw;
};

void UsdsLong::getValue(uint32_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsLong::getValue") << value;
	throw;
};

void UsdsLong::getValue(int64_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsLong::getValue(uint64_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsLong::getValue") << value;
	throw;
};

