#include "body\dataTypes\usdsString.h"

#include "dictionary\dataTypes\dictionaryString.h"

#include "unicode\unistr.h"
#include <string>

#pragma warning (disable : 4996)

using namespace usds;

UsdsString::UsdsString(Body* parent_body) : UsdsBaseType(parent_body)
{
	valueBufferSize = 16;
	objectValue = new uint8_t[valueBufferSize];
}

UsdsString::~UsdsString()
{
	if (objectValue != 0)
		delete [] objectValue;
}

void UsdsString::additionalInitObject()
try
{
	textEncode = ((DictionaryString*)parentDictionaryObject)->getDefaultEncode();

	if (textEncode == USDS_NO_DEFAULT_ENCODE)
	{
		valueSize = 0;
	}
	else
	{
		if (((DictionaryString*)parentDictionaryObject)->hasDefaultValue())
		{
			setFromUTF8(((DictionaryString*)parentDictionaryObject)->getUTF8DefaultValue());
		}
		else
		{
			valueSize = 0;
		}
	}
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsString::additionalInitObject");
	throw;
};

void UsdsString::setEncode(usdsEncodes encode) throw(...)
try
{
	if (encode == USDS_NO_DEFAULT_ENCODE)
		throw ErrorMessage(BODY_STRING__NO_ENCODE) << "Encode cannot be USDS_NO_DEFAULT_ENCODE";
	if (((DictionaryString*)parentDictionaryObject)->getDefaultEncode() != USDS_NO_DEFAULT_ENCODE)
		throw ErrorMessage(BODY_STRING__DEFAULT_ENCODE_IS_SET) << "Default encode is not USDS_NO_DEFAULT_ENCODE";
	if (valueSize != 0)
		throw ErrorMessage(BODY_STRING__STRING_AREADY_INITIALIZED) << "Cannot change encode: string is not empty";

	textEncode = encode;

	if (((DictionaryString*)parentDictionaryObject)->hasDefaultValue())
	{
		setFromUTF8(((DictionaryString*)parentDictionaryObject)->getUTF8DefaultValue());
	}
	else
	{
		valueSize = 0;
	}
}
catch (ErrorMessage&msg)
{
	throw ErrorStack("UsdsString::setEncode") << encode << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsString::setEncode") << encode;
	throw;
};

usdsEncodes UsdsString::getEncode() throw(...)
{
	return textEncode;
};

void UsdsString::setFromUTF8(const char* value) throw (...)
try
{
	if (textEncode == USDS_NO_DEFAULT_ENCODE)
		throw ErrorMessage(BODY_STRING__NO_ENCODE) << "Encode cannot be USDS_NO_DEFAULT_ENCODE";

	switch (textEncode)
	{
	case USDS_UTF8:
	{
		size_t byte_size = strlen(value);
		if (valueBufferSize < (byte_size + 1))
		{
			delete[] objectValue;
			valueBufferSize = byte_size + 1;
			objectValue = new uint8_t[valueBufferSize];
		}
		memcpy(objectValue, value, valueBufferSize);
		valueSize = byte_size;
		return;
	}
	default:
		throw ErrorMessage(BODY_STRING__UNSUPPORTED_CONVERSION) << "Unsupported conversion from UTF-8 to " << usdsEncodeName(textEncode);
	}
}
catch (ErrorMessage&msg)
{
	throw ErrorStack("UsdsString::setFromUTF8") << value << msg;
}

void UsdsString::setFromUTF8(const char* value, size_t byte_size) throw (...)
try
{
	if (textEncode == USDS_NO_DEFAULT_ENCODE)
		throw ErrorMessage(BODY_STRING__NO_ENCODE) << "Encode cannot be USDS_NO_DEFAULT_ENCODE";

	switch (textEncode)
	{
	case USDS_UTF8:
	{
		if (byte_size != 0 && value[byte_size - 1] == 0)
			byte_size--;
		if (valueBufferSize < byte_size + 1)
		{
			delete[] objectValue;
			valueBufferSize = byte_size + 1;
			objectValue = new uint8_t[valueBufferSize];
		}
		memcpy(objectValue, value, byte_size);
		objectValue[byte_size] = 0;
		valueSize = byte_size;
		return;
	}
	default:
		throw ErrorMessage(BODY_STRING__UNSUPPORTED_CONVERSION) << "Unsupported conversion from UTF-8 to " << usdsEncodeName(textEncode);
	}
}
catch (ErrorMessage&msg)
{
	throw ErrorStack("UsdsString::setFromUTF8").addStringAndSize(value, byte_size) << msg;
}

const char* UsdsString::getUTF8Value(size_t* byte_size) throw (...)
try
{
	if (textEncode == USDS_NO_DEFAULT_ENCODE)
		throw ErrorMessage(BODY_STRING__NO_ENCODE) << "Encode cannot be USDS_NO_DEFAULT_ENCODE";

	switch (textEncode)
	{
	case USDS_UTF8:
	{
		*byte_size = valueSize;
		return (const char*)objectValue;
	}
	default:
		throw ErrorMessage(BODY_STRING__UNSUPPORTED_CONVERSION) << "Unsupported conversion from UTF8 to " << usdsEncodeName(textEncode);
	}
}
catch (ErrorMessage&msg)
{
	throw ErrorStack("UsdsString::setEncode") << byte_size << msg;
}

const char* UsdsString::getUTF8Value() throw (...)
try
{
	if (textEncode == USDS_NO_DEFAULT_ENCODE)
		throw ErrorMessage(BODY_STRING__NO_ENCODE) << "Encode cannot be USDS_NO_DEFAULT_ENCODE";

	switch (textEncode)
	{
	case USDS_UTF8:
	{
		return (const char*)objectValue;
	}
	default:
		throw ErrorMessage(BODY_STRING__UNSUPPORTED_CONVERSION) << "Unsupported conversion from UTF8 to " << usdsEncodeName(textEncode);
	}
}
catch (ErrorMessage&msg)
{
	throw ErrorStack("UsdsString::setEncode") << msg;
}

const uint8_t* UsdsString::getByteValue() throw (...)
{
	return objectValue;
};

size_t UsdsString::getByteSize() throw (...)
{
	return valueSize;
};

uint8_t* UsdsString::reserveBinaryForValue(size_t byte_size)
{
	if (valueBufferSize < byte_size + sizeof(uint32_t))
	{
		delete[] objectValue;
		valueBufferSize = byte_size + sizeof(uint32_t);
		objectValue = new uint8_t[valueBufferSize];
	}
	*((uint32_t*)(objectValue + byte_size)) = 0;
	return objectValue;
}


