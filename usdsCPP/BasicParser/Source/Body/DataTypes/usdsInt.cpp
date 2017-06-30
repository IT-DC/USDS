#include "body\dataTypes\usdsInt.h"

#include "dictionary\dataTypes\dictionaryInt.h"

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
try
{
	usdsTypeWrite(value, USDS_INT,(uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsInt::setValue") << value;
	throw;
};

void UsdsInt::setValue(int64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_INT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsInt::setValue") << value;
	throw;
};

void UsdsInt::setValue(uint64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_INT, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsInt::setValue") << value;
	throw;
};

int32_t UsdsInt::get()
{
	return objectValue;
};

void UsdsInt::set(int32_t value)
{
	objectValue = value;
};


void UsdsInt::getValue(int8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_INT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsInt::getValue") << value;
	throw;
};

void UsdsInt::getValue(uint8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_INT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsInt::getValue") << value;
	throw;
};

void UsdsInt::getValue(int16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_INT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsInt::getValue") << value;
	throw;
};

void UsdsInt::getValue(uint16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_INT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsInt::getValue") << value;
	throw;
};

void UsdsInt::getValue(int32_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsInt::getValue(uint32_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_INT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsInt::getValue") << value;
	throw;
};

void UsdsInt::getValue(int64_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsInt::getValue(uint64_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_INT, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsInt::getValue") << value;
	throw;
};

bool UsdsInt::isBigendian()
{
	return ((DictionaryInt*)parentDictionaryObject)->getBigendian();
}

