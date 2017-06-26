#include "body\dataTypes\usdsByte.h"

using namespace usds;

UsdsByte::UsdsByte(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsByte::~UsdsByte()
{
}

void UsdsByte::additionalInitObject()
{


};

void UsdsByte::setValue(int8_t value) throw (...)
{

	objectValue = value;
};

void UsdsByte::setValue(uint8_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_BYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsByte::setValue") << value;
	throw;
};

void UsdsByte::setValue(int16_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_BYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsByte::setValue") << value;
	throw;
};

void UsdsByte::setValue(uint16_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_BYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsByte::setValue") << value;
	throw;
};

void UsdsByte::setValue(int32_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_BYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsByte::setValue") << value;
	throw;
};

void UsdsByte::setValue(uint32_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_BYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsByte::setValue") << value;
	throw;
};

void UsdsByte::setValue(int64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_BYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsByte::setValue") << value;
	throw;
};

void UsdsByte::setValue(uint64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_BYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsByte::setValue") << value;
	throw;
};

int8_t UsdsByte::get()
{
	return objectValue;
};

void UsdsByte::set(int8_t value)
{
	objectValue = value;
};


void UsdsByte::getValue(int8_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsByte::getValue(uint8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_BYTE, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsByte::getValue") << value;
	throw;
};

void UsdsByte::getValue(int16_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsByte::getValue(uint16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_BYTE, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsByte::getValue") << value;
	throw;
};

void UsdsByte::getValue(int32_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsByte::getValue(uint32_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_BYTE, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsByte::getValue") << value;
	throw;
};

void UsdsByte::getValue(int64_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsByte::getValue(uint64_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_BYTE, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsByte::getValue") << value;
	throw;
};



