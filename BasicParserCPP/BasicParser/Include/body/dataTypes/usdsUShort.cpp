#include "body\dataTypes\usdsUShort.h"

#include "dictionary\dataTypes\dictionaryUShort.h"

using namespace usds;

UsdsUShort::UsdsUShort(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsUShort::~UsdsUShort()
{
}

void UsdsUShort::additionalInitObject()
{
	if (((DictionaryUShort*)parentDictionaryObject)->hasDefaultValue())
		objectValue = ((DictionaryUShort*)parentDictionaryObject)->getDefaultValue();
};

void UsdsUShort::setValue(int8_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_USHORT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUShort::setValue") << value;
	throw;
};

void UsdsUShort::setValue(uint8_t value) throw (...)
{

	objectValue = value;
};

void UsdsUShort::setValue(int16_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_USHORT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUShort::setValue") << value;
	throw;
};

void UsdsUShort::setValue(uint16_t value) throw (...)
{
	objectValue = value;
};

void UsdsUShort::setValue(int32_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_USHORT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUShort::setValue") << value;
	throw;
};

void UsdsUShort::setValue(uint32_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_USHORT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUShort::setValue") << value;
	throw;
};

void UsdsUShort::setValue(int64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_USHORT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUShort::setValue") << value;
	throw;
};

void UsdsUShort::setValue(uint64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_USHORT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUShort::setValue") << value;
	throw;
};

uint16_t UsdsUShort::get()
{
	return objectValue;
};

void UsdsUShort::set(uint16_t value)
{
	objectValue = value;
};


void UsdsUShort::getValue(int8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_USHORT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUShort::getValue") << value;
	throw;
};

void UsdsUShort::getValue(uint8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_USHORT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUShort::getValue") << value;
	throw;
};

void UsdsUShort::getValue(int16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_USHORT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUShort::getValue") << value;
	throw;
};

void UsdsUShort::getValue(uint16_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsUShort::getValue(int32_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsUShort::getValue(uint32_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsUShort::getValue(int64_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsUShort::getValue(uint64_t* value) throw (...)
{
	*value = objectValue;
};

bool UsdsUShort::isBigendian()
{
	return ((DictionaryUShort*)parentDictionaryObject)->getBigendian();
}

