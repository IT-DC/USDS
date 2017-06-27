#include "body\dataTypes\usdsUVarint.h"

using namespace usds;

UsdsUVarint::UsdsUVarint(Body* parent_body) : UsdsBaseType(parent_body)
{
	
}

UsdsUVarint::~UsdsUVarint()
{
}

void UsdsUVarint::additionalInitObject()
{


};

void UsdsUVarint::setValue(int8_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_ULONG, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUVarint::setValue") << value;
	throw;
};

void UsdsUVarint::setValue(uint8_t value) throw (...)
{

	objectValue = value;
};

void UsdsUVarint::setValue(int16_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_ULONG, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUVarint::setValue") << value;
	throw;
};

void UsdsUVarint::setValue(uint16_t value) throw (...)
{

	objectValue = value;
};

void UsdsUVarint::setValue(int32_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_ULONG, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUVarint::setValue") << value;
	throw;
};

void UsdsUVarint::setValue(uint32_t value) throw (...)
{
	objectValue = value;
};

void UsdsUVarint::setValue(int64_t value) throw (...)
try
{
	usdsTypeWrite(value, USDS_ULONG, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUVarint::setValue") << value;
	throw;
};

void UsdsUVarint::setValue(uint64_t value) throw (...)
{
	objectValue = value;
};

uint64_t UsdsUVarint::get()
{
	return objectValue;
};

void UsdsUVarint::set(uint64_t value)
{
	objectValue = value;
};


void UsdsUVarint::getValue(int8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUVarint::getValue") << value;
	throw;
};

void UsdsUVarint::getValue(uint8_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUVarint::getValue") << value;
	throw;
};

void UsdsUVarint::getValue(int16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUVarint::getValue") << value;
	throw;
};

void UsdsUVarint::getValue(uint16_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUVarint::getValue") << value;
	throw;
};

void UsdsUVarint::getValue(int32_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUVarint::getValue") << value;
	throw;
};

void UsdsUVarint::getValue(uint32_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUVarint::getValue") << value;
	throw;
};

void UsdsUVarint::getValue(int64_t* value) throw (...)
try
{
	usdsTypeRead((uint8_t*)&objectValue, USDS_ULONG, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsUVarint::getValue") << value;
	throw;
};

void UsdsUVarint::getValue(uint64_t* value) throw (...)
{
	*value = objectValue;
};




