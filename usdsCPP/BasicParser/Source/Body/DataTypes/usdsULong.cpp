#include "body\dataTypes\usdsULong.h"

#include "dictionary\dataTypes\dictionaryULong.h"

using namespace usds;

UsdsULong::UsdsULong(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsULong::~UsdsULong()
{
}

void UsdsULong::additionalInitObject()
{
	if (((DictionaryULong*)parentDictionaryObject)->hasDefaultValue())
		objectValue = ((DictionaryULong*)parentDictionaryObject)->getDefaultValue();
};

void UsdsULong::setValue(int8_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_ULONG, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsULong::setValue") << value;
	throw;
};

void UsdsULong::setValue(uint8_t value) throw (...)
{

	objectValue = value;
};

void UsdsULong::setValue(int16_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_ULONG, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsULong::setValue") << value;
	throw;
};

void UsdsULong::setValue(uint16_t value) throw (...)
{

	objectValue = value;
};

void UsdsULong::setValue(int32_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_ULONG, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsULong::setValue") << value;
	throw;
};

void UsdsULong::setValue(uint32_t value) throw (...)
{
	objectValue = value;
};

void UsdsULong::setValue(int64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_ULONG, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsULong::setValue") << value;
	throw;
};

void UsdsULong::setValue(uint64_t value) throw (...)
{
	objectValue = value;
};

uint64_t UsdsULong::get()
{
	return objectValue;
};

void UsdsULong::set(uint64_t value)
{
	objectValue = value;
};


void UsdsULong::getValue(int8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsULong::getValue") << value;
	throw;
};

void UsdsULong::getValue(uint8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsULong::getValue") << value;
	throw;
};

void UsdsULong::getValue(int16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsULong::getValue") << value;
	throw;
};

void UsdsULong::getValue(uint16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsULong::getValue") << value;
	throw;
};

void UsdsULong::getValue(int32_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsULong::getValue") << value;
	throw;
};

void UsdsULong::getValue(uint32_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsULong::getValue") << value;
	throw;
};

void UsdsULong::getValue(int64_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsULong::getValue") << value;
	throw;
};

void UsdsULong::getValue(uint64_t* value) throw (...)
{
	*value = objectValue;
};

bool UsdsULong::isBigendian()
{
	return ((DictionaryULong*)parentDictionaryObject)->getBigendian();
}

