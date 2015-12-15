#include "base\binary\usdsBinaryInput.h"

using namespace usds;

BinaryInput::BinaryInput()
{
	usdsBuff = 0;
	buffLastPos = 0;
	buffCurrentPos = 0;
};

BinaryInput::~BinaryInput() {};

void BinaryInput::setBinary(const unsigned char* buff, size_t size) throw(...)
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

int BinaryInput::readUVarint(unsigned long long* value) throw(...)
try
{
	unsigned long long buf = 0;
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
	for (int i = 1; i <= 8; i++)
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

int BinaryInput::readUVarint(unsigned int* value) throw(...)
try
{
	unsigned int buf = 0;
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
	for (int i = 1; i <= 3; i++)
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

int BinaryInput::readUVarint(int* value) throw(...)
try
{
	int buf = 0;
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
	for (int i = 1; i <= 3; i++)
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
		throw ErrorMessage(BIN_IN__BEEG_UVARINT, "Can't read unsigned varint: the size is more than signed int (4 byte)");
	buf = *buffCurrentPos;
	*value += (buf << 28);
	buffCurrentPos++;
	return 5;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readUVarint") << value << err;
};

int BinaryInput::readInt() throw(...)
try
{
	// buffer overflow
	if (buffCurrentPos + 4 > buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'int'");

	int value;
	memcpy(&value, buffCurrentPos, 4);
	buffCurrentPos += 4;

	return value;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readInt") << err;
};

long long BinaryInput::readLong() throw(...)
try
{
	// buffer overflow
	if (buffCurrentPos + 8 > buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'long'");

	long long value;
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
	value = (*buffCurrentPos == 255);
	buffCurrentPos++;

	return value;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readBool") << err;
};

unsigned char BinaryInput::readUByte() throw(...)
try
{
	// buffer overflow
	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read the Byte");

	unsigned char value = buffCurrentPos[0];
	buffCurrentPos++;
	return value;

}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readUByte") << err;
};

char BinaryInput::readByte() throw(...)
try
{
	// buffer overflow
	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read a Byte");

	char value = buffCurrentPos[0];
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

const unsigned char* BinaryInput::getCurrentPosition() throw(...)
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

const unsigned char* BinaryInput::getFirstPosition() throw(...)
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