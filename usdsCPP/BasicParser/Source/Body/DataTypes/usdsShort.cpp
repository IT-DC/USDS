#include "body\dataTypes\usdsShort.h"

using namespace usds;

UsdsShort::UsdsShort(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsShort::~UsdsShort()
{
}

void UsdsShort::additionalInitObject()
{


};

void UsdsShort::setValue(int8_t value) throw (...)
{

	objectValue = value;
};

void UsdsShort::setValue(uint8_t value) throw (...)
{

	objectValue = value;
};

void UsdsShort::setValue(int16_t value) throw (...)
{

	objectValue = value;
};

void UsdsShort::setValue(uint16_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_SHORT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsShort::setValue") << value;
	throw;
};

void UsdsShort::setValue(int32_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_SHORT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsShort::setValue") << value;
	throw;
};

void UsdsShort::setValue(uint32_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_SHORT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsShort::setValue") << value;
	throw;
};

void UsdsShort::setValue(int64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_SHORT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsShort::setValue") << value;
	throw;
};

void UsdsShort::setValue(uint64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_SHORT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsShort::setValue") << value;
	throw;
};

int16_t UsdsShort::get()
{
	return objectValue;
};

void UsdsShort::set(int16_t value)
{
	objectValue = value;
};


void UsdsShort::getValue(int8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_SHORT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsShort::getValue") << value;
	throw;
};

void UsdsShort::getValue(uint8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_SHORT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsShort::getValue") << value;
	throw;
};

void UsdsShort::getValue(int16_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsShort::getValue(uint16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_SHORT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsShort::getValue") << value;
	throw;
};

void UsdsShort::getValue(int32_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsShort::getValue(uint32_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_SHORT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsShort::getValue") << value;
	throw;
};

void UsdsShort::getValue(int64_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsShort::getValue(uint64_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_SHORT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsShort::getValue") << value;
	throw;
};

