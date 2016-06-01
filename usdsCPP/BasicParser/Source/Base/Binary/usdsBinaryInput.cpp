#include "base\binary\usdsBinaryInput.h"

using namespace usds;

BinaryInput::BinaryInput()
{
	usdsBuff = 0;
	buffLastPos = 0;
	buffCurrentPos = 0;
};

BinaryInput::~BinaryInput() {};

void BinaryInput::setBinary(const uint8_t* buff, size_t size) throw(...)
try
{
	if (buff == 0)
		throw ErrorMessage(BIN_IN__NULL_BUFF, "Buffer pointer must be not null");

	if (size == 0)
		throw ErrorMessage(BIN_IN__NULL_SIZE, "Buffer size must be not null");

	usdsBuff = buff;
	buffLastPos = usdsBuff + size;
	buffCurrentPos = usdsBuff;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::setBinary") << buff << size << err;
};

void BinaryInput::clear()
{
	usdsBuff = 0;
	buffLastPos = 0;
	buffCurrentPos = 0;
};

int32_t BinaryInput::readUVarint(uint64_t* value) throw(...)
try
{
	uint64_t buf = 0;
	*value = 0;

	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'unsigned varint'");

	// byte 0
	if (*buffCurrentPos < 128u)
	{
		*value = *buffCurrentPos;
		buffCurrentPos++;
		return 1;
	}
	else
	{
		*value = (*buffCurrentPos) & 127ull;
		buffCurrentPos++;
	}

	// bytes 1-8
	for (int32_t i = 1; i <= 8; i++)
	{
		if (buffCurrentPos >= buffLastPos)
			throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'unsigned varint'");
		if (*buffCurrentPos == 0)
			throw ErrorMessage(BIN_IN__UVARINT_ERROR_FORMAT) << "Binary format error: byte " << i << " of the UNSIGNED VARINT can not be 0";
		if (*buffCurrentPos < 128u)
		{
			buf = *buffCurrentPos;
			*value += (buf << 7*i);
			buffCurrentPos++;
			return i+1;
		}
		else
		{
			buf = (*buffCurrentPos) & 127;
			*value += (buf << 7*i);
			buffCurrentPos++;
		}
	}

	// byte 9
	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'unsigned varint'");
	if (*buffCurrentPos == 0)
		throw ErrorMessage(BIN_IN__UVARINT_ERROR_FORMAT, "Binary format error: byte 9 of the UNSIGNED VARINT can not be 0");
	if (*buffCurrentPos > 1)
		throw ErrorMessage(BIN_IN__BEEG_UVARINT, "Can't read unsigned varint: the size is more than 8 bytes");
	*value = *value | 0x8000000000000000ull;
	buffCurrentPos++;
	return 10;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readUVarint") << value << err;
};

int32_t BinaryInput::readUVarint(uint32_t* value) throw(...)
try
{
	uint32_t buf = 0;
	*value = 0;

	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'unsigned varint'");

	// byte 0
	if (*buffCurrentPos < 128u)
	{
		*value = *buffCurrentPos;
		buffCurrentPos++;
		return 1;
	}
	else
	{
		*value = (*buffCurrentPos) & 127ull;
		buffCurrentPos++;
	}

	// bytes 1-3
	for (int32_t i = 1; i <= 3; i++)
	{
		if (buffCurrentPos >= buffLastPos)
			throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'unsigned varint'");
		if (*buffCurrentPos == 0)
			throw ErrorMessage(BIN_IN__UVARINT_ERROR_FORMAT) << "Binary format error: byte " << i << " of the UNSIGNED VARINT can not be 0";
		if (*buffCurrentPos < 128u)
		{
			buf = *buffCurrentPos;
			*value += (buf << 7 * i);
			buffCurrentPos++;
			return i + 1;
		}
		else
		{
			buf = (*buffCurrentPos) & 127;
			*value += (buf << 7 * i);
			buffCurrentPos++;
		}
	}

	// byte 4
	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'unsigned varint'");
	if (*buffCurrentPos == 0)
		throw ErrorMessage(BIN_IN__UVARINT_ERROR_FORMAT, "Binary format error: byte 4 of the UNSIGNED VARINT can not be 0");
	if (*buffCurrentPos > 15)
		throw ErrorMessage(BIN_IN__BEEG_UVARINT, "Can't read unsigned varint: the size is more than 4 bytes");
	buf = *buffCurrentPos;
	*value += (buf << 28);
	buffCurrentPos++;
	return 5;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readUVarint") << value << err;
};

int32_t BinaryInput::readUVarint(int32_t* value) throw(...)
try
{
	int32_t buf = 0;
	*value = 0;

	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'unsigned varint'");

	// byte 0
	if (*buffCurrentPos < 128u)
	{
		*value = *buffCurrentPos;
		buffCurrentPos++;
		return 1;
	}
	else
	{
		*value = (*buffCurrentPos) & 127ull;
		buffCurrentPos++;
	}

	// bytes 1-3
	for (int32_t i = 1; i <= 3; i++)
	{
		if (buffCurrentPos >= buffLastPos)
			throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'unsigned varint'");
		if (*buffCurrentPos == 0)
			throw ErrorMessage(BIN_IN__UVARINT_ERROR_FORMAT) << "Binary format error: byte " << i << " of the UNSIGNED VARINT can not be 0";
		if (*buffCurrentPos < 128u)
		{
			buf = *buffCurrentPos;
			*value += (buf << 7 * i);
			buffCurrentPos++;
			return i + 1;
		}
		else
		{
			buf = (*buffCurrentPos) & 127;
			*value += (buf << 7 * i);
			buffCurrentPos++;
		}
	}

	// byte 4
	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'unsigned varint'");
	if (*buffCurrentPos == 0)
		throw ErrorMessage(BIN_IN__UVARINT_ERROR_FORMAT, "Binary format error: byte 4 of the UNSIGNED VARINT can not be 0");
	if (*buffCurrentPos > 7)
		throw ErrorMessage(BIN_IN__BEEG_UVARINT, "Can't read unsigned varint: the size is more than signed int32_t (4 byte)");
	buf = *buffCurrentPos;
	*value += (buf << 28);
	buffCurrentPos++;
	return 5;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readUVarint") << value << err;
};

int32_t BinaryInput::readInt() throw(...)
try
{
	// buffer overflow
	if (buffCurrentPos + 4 > buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'int'");

	int32_t value;
	memcpy(&value, buffCurrentPos, 4);
	buffCurrentPos += 4;

	return value;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readInt") << err;
};

int64_t BinaryInput::readLong() throw(...)
try
{
	// buffer overflow
	if (buffCurrentPos + 8 > buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'long'");

	int64_t value;
	memcpy(&value, buffCurrentPos, 8);
	buffCurrentPos += 8;

	return value;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readLong") << err;
};

double BinaryInput::readDouble() throw(...)
try
{
	// buffer overflow
	if (buffCurrentPos + 8 > buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'double'");

	double value;
	memcpy(&value, buffCurrentPos, 8);
	buffCurrentPos += 8;

	return value;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readDouble") << err;
};

void BinaryInput::readByteArray(void* buff, size_t size) throw(...)
try
{
	if (buff == 0)
		throw ErrorMessage(BIN_IN__NULL_BUFF, "Output buffer can not be null");
	// buffer overflow
	if (buffCurrentPos + size > buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read array, size: ") << size << " bytes";
	memcpy(buff, buffCurrentPos, size);
	buffCurrentPos += size;
	
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readByteArray") << buff << size << err;
};

const void* BinaryInput::readByteArray(size_t size) throw(...)
try
{
	// buffer overflow
	if (buffCurrentPos + size > buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'string', size: ") << size << " bytes";;
	const void* value = (void*)buffCurrentPos;
	buffCurrentPos += size;
	return value;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readByteArray") << size << err;
};

bool BinaryInput::readBool() throw(...)
try
{
	// buffer overflow
	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'bool'");

	bool value;
	if (*buffCurrentPos == 255)
		value = true;
	else if (*buffCurrentPos == 0)
		value = false;
	else
		throw ErrorMessage(BIN_IN__BOOLEAN_ERROR_FORMAT, "Error value for BOOLEAN: ") << (int32_t)*buffCurrentPos << ", must be 0 or 0xFF";
	
	buffCurrentPos++;

	return value;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readBool") << err;
};

uint8_t BinaryInput::readUByte() throw(...)
try
{
	// buffer overflow
	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read the Byte");

	uint8_t value = buffCurrentPos[0];
	buffCurrentPos++;
	return value;

}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readUByte") << err;
};

int8_t BinaryInput::readByte() throw(...)
try
{
	// buffer overflow
	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read a Byte");

	int8_t value = buffCurrentPos[0];
	buffCurrentPos++;
	return value;

}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readByte") << err;
};

void BinaryInput::stepBack(size_t size) throw(...)
try
{
	if (buffCurrentPos - size < usdsBuff || size_t(buffCurrentPos) < size)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Too big step back");

	buffCurrentPos -= size;

}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::stepBack") << size << err;
};

void BinaryInput::stepForward(size_t size) throw(...)
try
{
	if (buffCurrentPos + size > buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Too big step forward, size: ") << size << " bytes";
	
	buffCurrentPos += size;

}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::stepForward") << size << err;
};


bool BinaryInput::isEnd() throw(...)
try
{
	if (usdsBuff == 0)
		throw ErrorMessage(BIN_IN__NULL_BUFF, "Binary is not initialised");
	return (buffLastPos == buffCurrentPos);
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::isEnd") << err;
};

const uint8_t* BinaryInput::getCurrentPosition() throw(...)
try
{
	if (usdsBuff == 0)
		throw ErrorMessage(BIN_IN__NULL_BUFF, "Binary is not initialised");
	return buffCurrentPos;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::getCurrentPosition") << err;
};

const uint8_t* BinaryInput::getFirstPosition() throw(...)
try
{
	if (usdsBuff == 0)
		throw ErrorMessage(BIN_IN__NULL_BUFF, "Binary is not initialised");
	return usdsBuff;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::getFirstPosition") << err;
};

size_t BinaryInput::getDataSize() throw(...)
try
{
	if (usdsBuff == 0)
		throw ErrorMessage(BIN_IN__NULL_BUFF, "Binary is not initialised");
	return buffLastPos - usdsBuff;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::getDataSize") << err;
};