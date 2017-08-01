#include "body\dataTypes\usdsUInt.h"

#include "dictionary\dataTypes\dictionaryUInt.h"

using namespace usds;

UsdsUInt::UsdsUInt(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsUInt::~UsdsUInt()
{
}

void UsdsUInt::additionalInitObject()
{
	if (((DictionaryUInt*)parentDictionaryObject)->hasDefaultValue())
		objectValue = ((DictionaryUInt*)parentDictionaryObject)->getDefaultValue();
};

void UsdsUInt::setValue(int8_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_UINT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUInt::setValue") << value;
	throw;
};

void UsdsUInt::setValue(uint8_t value) throw (...)
{

	objectValue = value;
};

void UsdsUInt::setValue(int16_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_UINT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUInt::setValue") << value;
	throw;
};

void UsdsUInt::setValue(uint16_t value) throw (...)
{
	objectValue = value;
};

void UsdsUInt::setValue(int32_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_UINT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUInt::setValue") << value;
	throw;
};

void UsdsUInt::setValue(uint32_t value) throw (...)
{
	objectValue = value;
};


void UsdsUInt::setValue(int64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_UINT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUInt::setValue") << value;
	throw;
};

void UsdsUInt::setValue(uint64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_UINT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUInt::setValue") << value;
	throw;
};

uint32_t UsdsUInt::get()
{
	return objectValue;
};

void UsdsUInt::set(uint32_t value)
{
	objectValue = value;
};

void UsdsUInt::getValue(int8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_UINT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUInt::getValue") << value;
	throw;
};

void UsdsUInt::getValue(uint8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_UINT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUInt::getValue") << value;
	throw;
};

void UsdsUInt::getValue(int16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_UINT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUInt::getValue") << value;
	throw;
};

void UsdsUInt::getValue(uint16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_UINT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUInt::getValue") << value;
	throw;
};

void UsdsUInt::getValue(int32_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_UINT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUInt::getValue") << value;
	throw;
};

void UsdsUInt::getValue(uint32_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsUInt::getValue(int64_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsUInt::getValue(uint64_t* value) throw (...)
{
	*value = objectValue;
};

bool UsdsUInt::isBigendian()
{
	return ((DictionaryUInt*)parentDictionaryObject)->getBigendian();
}

