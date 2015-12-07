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
	int step = 0;
	unsigned long long buf = 0;
	*value = 0;
	while (true)
	{
		// buffer overflow
		if (buffCurrentPos >= buffLastPos)
			throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'unsigned varint'");

		buf = (*buffCurrentPos) & 127;
		*value += (buf << (step * 7));
		// last byte
		if (*buffCurrentPos < 128u)
			break;
		step++;
		// The value is too big
		if (step == 10)
			throw ErrorMessage(BIN_IN__BEEG_UVARINT, "Can't read unsigned varint: the size is more than 8 bytes");
		buffCurrentPos++;
	};
	// The value is too big
	if (step == 9 && (*buffCurrentPos) > 1)
		throw ErrorMessage(BIN_IN__BEEG_UVARINT, "Can't read unsigned varint: the size is more than 8 bytes");

	buffCurrentPos++;

	return step+1;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readUVarint") << value << err;
};

int BinaryInput::readUVarint(unsigned int* value) throw(...)
try
{
	int step = 0;
	int buf = 0;
	*value = 0;
	while (true)
	{
		// buffer overflow
		if (buffCurrentPos >= buffLastPos)
			throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'unsigned varint'");

		buf = (*buffCurrentPos) & 127;
		*value += (buf << (step * 7));
		// last byte
		if (*buffCurrentPos < 128u)
			break;
		step++;
		// The value is too big
		if (step == 5)
			throw ErrorMessage(BIN_IN__BEEG_UVARINT, "Can't read unsigned varint: the size is more than 4 bytes");
		buffCurrentPos++;
	};
	// The value is too big
	if (step == 4 && (*buffCurrentPos) > 7)
		throw ErrorMessage(BIN_IN__BEEG_UVARINT, "Can't read unsigned varint: the size is more than 4 bytes");

	buffCurrentPos++;

	return step + 1;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readUVarint") << value << err;
};

int BinaryInput::readUVarint(int* value) throw(...)
try
{
	int step = 0;
	int buf = 0;
	*value = 0;
	while (true)
	{
		// buffer overflow
		if (buffCurrentPos >= buffLastPos)
			throw ErrorMessage(BIN_IN__BUFF_OVERFLOW, "Unexpected end of the buffer, can't read 'unsigned varint'");

		buf = (*buffCurrentPos) & 127;
		*value += (buf << (step * 7));
		// last byte
		if (*buffCurrentPos < 128u)
			break;
		step++;
		// The value is too big
		if (step == 5)
			throw ErrorMessage(BIN_IN__BEEG_UVARINT, "Can't read unsigned varint: the size is more than 4 bytes");
		buffCurrentPos++;
	};
	// The value is too big
	if (step == 4 && (*buffCurrentPos) > 3)
		throw ErrorMessage(BIN_IN__BEEG_UVARINT, "Can't read unsigned varint to int: the size is more than 4 bytes");

	buffCurrentPos++;

	return step + 1;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryInput::readUVarint") << value << err;
};

int BinaryInput::readInt() throw(...)
try
{
	// buffer overflow
	if (buffCurrentPos > buffLastPos + 4)
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
	if (buffCurrentPos > buffLastPos + 8)
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
	if (buffCurrentPos > buffLastPos + 8)
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
	if (buffCurrentPos > buffLastPos + size)
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
	if (buffCurrentPos > buffLastPos + size)
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
	if (buffCurrentPos > buffLastPos + size)
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