#include "body\dataTypes\usdsEnum.h"

#include "dictionary\dataTypes\dictionaryEnum.h"

#include "binary/usdsTypeConverter.h"

using namespace usds;

UsdsEnum::UsdsEnum(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsEnum::~UsdsEnum()
{

}

void UsdsEnum::setValue(int8_t value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		objectValue = value;
	else
		usdsTypeWrite(value, subType, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsEnum::setValue") << value;
	throw;
};

void UsdsEnum::setValue(uint8_t value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		objectValue = value;
	else
		usdsTypeWrite(value, subType, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsEnum::setValue") << value;
	throw;
};

void UsdsEnum::setValue(int16_t value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		objectValue = value;
	else
		usdsTypeWrite(value, subType, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsEnum::setValue") << value;
	throw;
};

void UsdsEnum::setValue(uint16_t value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		objectValue = value;
	else
		usdsTypeWrite(value, subType, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsEnum::setValue") << value;
	throw;
};

void UsdsEnum::setValue(int32_t value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		objectValue = value;
	else
		usdsTypeWrite(value, subType, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsEnum::setValue") << value;
	throw;
};

void UsdsEnum::setValue(uint32_t value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		objectValue = value;
	else
		usdsTypeWrite(value, subType, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsEnum::setValue") << value;
	throw;
};

void UsdsEnum::setValue(int64_t value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		objectValue = value;
	else
		usdsTypeWrite(value, subType, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsEnum::setValue") << value;
	throw;
};

void UsdsEnum::setValue(uint64_t value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		usdsTypeWrite(value, USDS_LONG, (uint8_t*)(&objectValue));
	else
		usdsTypeWrite(value, subType, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsEnum::setValue") << value;
	throw;
};


void UsdsEnum::getValue(int8_t* value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
	else
		usdsTypeRead((uint8_t*)&objectValue, subType, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsEnum::getValue(uint8_t* value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
	else
		usdsTypeRead((uint8_t*)&objectValue, subType, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsEnum::getValue(int16_t* value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
	else
		usdsTypeRead((uint8_t*)&objectValue, subType, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsEnum::getValue(uint16_t* value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
	else
		usdsTypeRead((uint8_t*)&objectValue, subType, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsEnum::getValue(int32_t* value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
	else
		usdsTypeRead((uint8_t*)&objectValue, subType, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsEnum::getValue(uint32_t* value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
	else
		usdsTypeRead((uint8_t*)&objectValue, subType, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsEnum::getValue(int64_t* value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		*value = objectValue;
	else
		usdsTypeRead((uint8_t*)&objectValue, subType, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsEnum::getValue(uint64_t* value) throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		usdsTypeRead((uint8_t*)&objectValue, USDS_LONG, value);
	else
		usdsTypeRead((uint8_t*)&objectValue, subType, value);
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsVarint::getValue") << value;
	throw;
};

void UsdsEnum::set(int64_t value) throw (...)
try
{
	if (subType == USDS_VARINT)
		objectValue = value;
	else
		usdsTypeWrite(value, subType, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsEnum::setValue") << value;
	throw;
};

int64_t UsdsEnum::get() throw (...)
try
{
	if (subType == USDS_VARINT || subType == USDS_LONG)
		return objectValue;
	else
	{
		int64_t value = 0;
		usdsTypeRead((uint8_t*)&objectValue, subType, &value);
		return value;
	}
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsEnum::get");
	throw;
};

void UsdsEnum::setFromUTF8(const char* name) throw (...)
try
{
	int64_t value = ((DictionaryEnum*)parentDictionaryObject)->getValue(name);
	if (subType == USDS_VARINT || subType == USDS_LONG)
		objectValue = value;
	else
		usdsTypeWrite(value, subType, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsEnum::setValue") << name;
	throw;
};

void UsdsEnum::setFromUTF8(const char* name, size_t byte_size) throw (...)
try
{
	int64_t value = ((DictionaryEnum*)parentDictionaryObject)->getValue(name, byte_size);
	if (subType == USDS_VARINT || subType == USDS_LONG)
		objectValue = value;
	else
		usdsTypeWrite(value, subType, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsEnum::setValue").addStringAndSize(name, byte_size);
	throw;
};

const char* UsdsEnum::getUTF8Value() throw (...)
try
{
	int64_t value = 0;
	if (subType == USDS_VARINT || subType == USDS_LONG)
		value = objectValue;
	else
		usdsTypeRead((uint8_t*)&objectValue, subType, &value);
		
	const char* name = ((DictionaryEnum*)parentDictionaryObject)->getEnumerator(value);
	if (name == 0)
		throw ErrorMessage(BODY_ENUM__ENUMERATOR_NOT_FOUND, "Enumerator for the value ") << objectValue << " not found";

	return name;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsEnum::getUTF8Value") << msg;
}
catch (ErrorStack err)
{
	err.addLevel("UsdsEnum::getUTF8Value");
	throw;
};

const char* UsdsEnum::getUTF8Value(size_t* byte_size)
try
{
	int64_t value = 0;
	if (subType == USDS_VARINT || subType == USDS_LONG)
		value = objectValue;
	else
		usdsTypeRead((uint8_t*)&objectValue, subType, &value);

	const char* name = ((DictionaryEnum*)parentDictionaryObject)->getEnumerator(value);
	if (name == 0)
		throw ErrorMessage(BODY_ENUM__ENUMERATOR_NOT_FOUND, "Enumerator for the value ") << objectValue << " not found";

	*byte_size = strlen(name);

	return name;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsEnum::getUTF8Value") << byte_size << msg;
}
catch (ErrorStack err)
{
	err.addLevel("UsdsEnum::getUTF8Value") << byte_size;
	throw;
};


void UsdsEnum::additionalInitObject()
{
	if (((DictionaryEnum*)parentDictionaryObject)->hasDefaultValue())
		objectValue = ((DictionaryEnum*)parentDictionaryObject)->getDefaultValue();

	subType = ((DictionaryEnum*)parentDictionaryObject)->getSubtype();
};

usdsType UsdsEnum::getSubtype()
{
	return subType;
}

bool UsdsEnum::isSubtypeBigendian()
{
	return ((DictionaryEnum*)parentDictionaryObject)->isSubtypeBigendian();
}

