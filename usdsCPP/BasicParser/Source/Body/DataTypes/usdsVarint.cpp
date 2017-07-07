#include "body\dataTypes\usdsVarint.h"

#include "dictionary/dataTypes/dictionaryVarint.h"

using namespace usds;

UsdsVarint::UsdsVarint(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsVarint::~UsdsVarint()
{
}

void UsdsVarint::additionalInitObject()
{
	if (((DictionaryVarint*)parentDictionaryObject)->hasDefaultValue())
		objectValue = ((DictionaryVarint*)parentDictionaryObject)->getDefaultValue();
};

void UsdsVarint::setValue(int8_t value) throw (...)
{

	objectValue = value;
};

void UsdsVarint::setValue(uint8_t value) throw (...)
{

	objectValue = value;
};

void UsdsVarint::setValue(int16_t value) throw (...)
{

	objectValue = value;
};

void UsdsVarint::setValue(uint16_t value) throw (...)
{

	objectValue = value;
};

void UsdsVarint::setValue(int32_t value) throw (...)
{

	objectValue = value;
};

void UsdsVarint::setValue(uint32_t value) throw (...)
{

	objectValue = value;
};

void UsdsVarint::setValue(int64_t value) throw (...)
{
	objectValue = value;
};

void UsdsVarint::setValue(uint64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_LONG, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::setValue") << value;
	throw;
};

int64_t UsdsVarint::get()
{
	return objectValue;
};

void UsdsVarint::set(int64_t value)
{
	objectValue = value;
};


void UsdsVarint::getValue(int8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsVarint::getValue(uint8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsVarint::getValue(int16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsVarint::getValue(uint16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsVarint::getValue(int32_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsVarint::getValue(uint32_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsVarint::getValue(int64_t* value) throw (...)
{
	*value = objectValue;
};

void UsdsVarint::getValue(uint64_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

