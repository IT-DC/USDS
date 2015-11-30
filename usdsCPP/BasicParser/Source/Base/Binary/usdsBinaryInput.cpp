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
	throw ErrorStack("BinaryInput::setBinary") << (void*)buff << size << err;
};

void BinaryInput::clear()
{
	usdsBuff = 0;
	buffLastPos = 0;
	buffCurrentPos = 0;
};

int BinaryInput::readUVarint(unsigned long long* value) throw(...)
{
	int step = 0;
	unsigned long long buf = 0;
	*value = 0;
	while (true)
	{
		// buffer overflow
		if (buffCurrentPos >= buffLastPos)
			throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read 'unsigned varint'", L"BinaryInput::readUVarint(unsigned long long*)");

		buf = (*buffCurrentPos) & 127;
		*value += (buf << (step * 7));
		// last byte
		if (*buffCurrentPos < 128u)
			break;
		step++;
		// The value is too big
		if (step == 10)
			throw ErrorMessage(BIN_IN_BEEG_UVARINT, L"Can't read unsigned varint: the size is more than 8 bytes", L"BinaryInput::readUVarint(unsigned long long*)");
		buffCurrentPos++;
	};
	// The value is too big
	if (step == 9 && (*buffCurrentPos) > 1)
		throw ErrorMessage(BIN_IN_BEEG_UVARINT, L"Can't read unsigned varint: the size is more than 8 bytes", L"BinaryInput::readUVarint(unsigned long long*)");

	buffCurrentPos++;

	return step+1;
};

int BinaryInput::readUVarint(unsigned int* value) throw(...)
{
	int step = 0;
	int buf = 0;
	*value = 0;
	while (true)
	{
		// buffer overflow
		if (buffCurrentPos >= buffLastPos)
			throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read 'unsigned varint'", L"BinaryInput::readUVarint(unsigned int*)");

		buf = (*buffCurrentPos) & 127;
		*value += (buf << (step * 7));
		// last byte
		if (*buffCurrentPos < 128u)
			break;
		step++;
		// The value is too big
		if (step == 5)
			throw ErrorMessage(BIN_IN_BEEG_UVARINT, L"Can't read unsigned varint: the size is more than 4 bytes", L"BinaryInput::readUVarint(unsigned int*)");
		buffCurrentPos++;
	};
	// The value is too big
	if (step == 4 && (*buffCurrentPos) > 7)
		throw ErrorMessage(BIN_IN_BEEG_UVARINT, L"Can't read unsigned varint: the size is more than 4 bytes", L"BinaryInput::readUVarint(unsigned int*)");

	buffCurrentPos++;

	return step + 1;
};

int BinaryInput::readUVarint(int* value) throw(...)
{
	int step = 0;
	int buf = 0;
	*value = 0;
	while (true)
	{
		// buffer overflow
		if (buffCurrentPos >= buffLastPos)
			throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read 'unsigned varint'", L"BinaryInput::readUVarint(int*)");

		buf = (*buffCurrentPos) & 127;
		*value += (buf << (step * 7));
		// last byte
		if (*buffCurrentPos < 128u)
			break;
		step++;
		// The value is too big
		if (step == 5)
			throw ErrorMessage(BIN_IN_BEEG_UVARINT, L"Can't read unsigned varint: the size is more than 4 bytes", L"BinaryInput::readUVarint(int*)");
		buffCurrentPos++;
	};
	// The value is too big
	if (step == 4 && (*buffCurrentPos) > 3)
		throw ErrorMessage(BIN_IN_BEEG_UVARINT, L"Can't read unsigned varint to int: the size is more than 4 bytes", L"BinaryInput::readUVarint(int*)");

	buffCurrentPos++;

	return step + 1;
};

int BinaryInput::readInt() throw(...)
{
	// buffer overflow
	if (buffCurrentPos > buffLastPos + 4)
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read 'int'", L"BinaryInput::readInt()");

	int value;
	memcpy(&value, buffCurrentPos, 4);
	buffCurrentPos += 4;

	return value;
};

long long BinaryInput::readLong() throw(...)
{
	// buffer overflow
	if (buffCurrentPos > buffLastPos + 8)
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read 'long'", L"BinaryInput::readLong()");

	long long value;
	memcpy(&value, buffCurrentPos, 8);
	buffCurrentPos += 8;

	return value;
};

double BinaryInput::readDouble() throw(...)
{
	// buffer overflow
	if (buffCurrentPos > buffLastPos + 8)
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read 'double'", L"BinaryInput::readDouble()");

	double value;
	memcpy(&value, buffCurrentPos, 8);
	buffCurrentPos += 8;

	return value;
};

void BinaryInput::readByteArray(void* buff, size_t size) throw(...)
{
	// buffer overflow
	if (buffCurrentPos > buffLastPos + size)
	{
		std::wstringstream mess;
		mess << L"Unexpected end of the buffer, can't read 'string', size: " << size << L" bytes";
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, &mess, L"BinaryInput::readByteArray");
	};
	memcpy(buff, buffCurrentPos, size);
	buffCurrentPos += size;
	
};

const void* BinaryInput::readByteArray(size_t size) throw(...)
{
	// buffer overflow
	if (buffCurrentPos > buffLastPos + size)
	{
		std::wstringstream mess;
		mess << L"Unexpected end of the buffer, can't read 'string', size: " << size << L" bytes";
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, &mess, L"BinaryInput::readByteArray");
	};
	const void* value = (void*)buffCurrentPos;
	buffCurrentPos += size;
	return value;
};

bool BinaryInput::readBool() throw(...)
{
	// buffer overflow
	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read 'bool'", L"BinaryInput::readBool()");

	bool value;
	if (*buffCurrentPos == 255)
		value = true;
	else
		value = false;
	buffCurrentPos++;

	return value;
}

unsigned char BinaryInput::readUByte() throw(...)
{
	// buffer overflow
	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read a Byte", L"BinaryInput::readUByte()");

	unsigned char value = buffCurrentPos[0];
	buffCurrentPos++;
	return value;

};

char BinaryInput::readByte() throw(...)
{
	// buffer overflow
	if (buffCurrentPos >= buffLastPos)
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read a Byte", L"BinaryInput::readByte()");

	char value = buffCurrentPos[0];
	buffCurrentPos++;
	return value;

};

void BinaryInput::stepBack(size_t size) throw(...)
{
	if (buffCurrentPos - size < usdsBuff || size_t(buffCurrentPos) < size)
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Too big step back", L"BinaryInput::stepBack");

	buffCurrentPos -= size;

};

void BinaryInput::stepForward(size_t size) throw(...)
{
	if (buffCurrentPos > buffLastPos + size)
	{
		std::wstringstream mess;
		mess << L"Too big step forward, size: " << size << L" bytes";
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, &mess, L"BinaryInput::stepForward");
	};
	
	buffCurrentPos += size;

};


bool BinaryInput::isEnd() throw(...)
{
	if (usdsBuff == 0)
		throw ErrorMessage(BIN_IN_NULL_BUFF, L"Binary is not initialised", L"BinaryInput::isEnd");
	return (buffLastPos == buffCurrentPos);
};

const unsigned char* BinaryInput::getCurrentPosition()
{
	return buffCurrentPos;
};

const unsigned char* BinaryInput::getFirstPosition()
{
	return usdsBuff;
};

size_t BinaryInput::getDataSize()
{
	return buffLastPos - usdsBuff;
};