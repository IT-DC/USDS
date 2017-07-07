#include "body\dataTypes\usdsUByte.h"

#include "dictionary/dataTypes/dictionaryUByte.h"

using namespace usds;

UsdsUByte::UsdsUByte(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsUByte::~UsdsUByte()
{
}

void UsdsUByte::additionalInitObject()
{
	if (((DictionaryUByte*)parentDictionaryObject)->hasDefaultValue())
		objectValue = ((DictionaryUByte*)parentDictionaryObject)->getDefaultValue();
};

void UsdsUByte::setValue(int8_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_UBYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUByte::setValue") << value;
	throw;
};

void UsdsUByte::setValue(uint8_t value) throw (...)
{
	objectValue = value;
}

void UsdsUByte::setValue(int16_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_UBYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUByte::setValue") << value;
	throw;
};

void UsdsUByte::setValue(uint16_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_UBYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUByte::setValue") << value;
	throw;
};

void UsdsUByte::setValue(int32_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_UBYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUByte::setValue") << value;
	throw;
};

void UsdsUByte::setValue(uint32_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_UBYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUByte::setValue") << value;
	throw;
};

void UsdsUByte::setValue(int64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_UBYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUByte::setValue") << value;
	throw;
};

void UsdsUByte::setValue(uint64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_UBYTE, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUByte::setValue") << value;
	throw;
};

uint8_t UsdsUByte::get()
{
	return objectValue;
};

void UsdsUByte::set(uint8_t value)
{
	objectValue = value;
};


void UsdsUByte::getValue(int8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_UBYTE, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUByte::getValue") << value;
	throw;
};

void UsdsUByte::getValue(uint8_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsUByte::getValue(int16_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsUByte::getValue(uint16_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsUByte::getValue(int32_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsUByte::getValue(uint32_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsUByte::getValue(int64_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsUByte::getValue(uint64_t* value) throw (...)
{
	*value = objectValue;
};



