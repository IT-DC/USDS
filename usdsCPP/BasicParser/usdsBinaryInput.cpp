#include "base\usdsBinaryInput.h"

using namespace usds;

BinaryInput::BinaryInput()
{
	in_usds_buff = 0;
	in_buff_last_pos = 0;
	in_buff_current_pos = 0;
	in_buff_body_pos = 0;
	in_buff_body_last_pos = 0;
};

BinaryInput::~BinaryInput() {};

void BinaryInput::setBinary(unsigned char* buff, size_t size) throw(...)
{
	if (buff == 0)
		throw ErrorMessage(BIN_IN_NULL_BUFF, L"Buff link must be not null", L"BinaryInput::setBinary");

	if (size == 0)
		throw ErrorMessage(BIN_IN_NULL_SIZE, L"Buff size must be not null", L"BinaryInput::setBinary");

	in_usds_buff = buff;
	in_buff_last_pos = in_usds_buff + size;
	in_buff_current_pos = in_usds_buff;
};

void BinaryInput::clean()
{
	in_usds_buff = 0;
	in_buff_last_pos = 0;
	in_buff_current_pos = 0;
	in_buff_body_pos = 0;
	in_buff_body_last_pos = 0;
	in_buff_body_last_pos = 0;
};

inline unsigned long long BinaryInput::readUVarint() throw(...)
{
	int step = 0;
	unsigned long long buf = 0;
	unsigned long long value = 0;
	while (true)
	{
		// buffer overflow
		if (in_buff_current_pos >= in_buff_body_last_pos)
			throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read 'unsigned varint'", L"BinaryInput::readUVarint()");

		buf = (*in_buff_current_pos) & 127;
		value += (buf << (step * 7));
		// last byte
		if (*in_buff_current_pos < 128)
			break;
		step++;
		// The value is too big
		if (step == 10)
			throw ErrorMessage(BIN_IN_BEEG_UVARINT, L"Can't read unsigned varint: the size is more than 8 bytes", L"BinaryInput::readUVarint()");
		in_buff_current_pos++;
	};
	// The value is too big
	if (step == 9 && (*in_buff_current_pos) > 1)
		throw ErrorMessage(BIN_IN_BEEG_UVARINT, L"Can't read unsigned varint: the size is more than 8 bytes", L"BinaryInput::readUVarint()");

	in_buff_current_pos++;

	return value;
};

inline int BinaryInput::readInt() throw(...)
{
	// buffer overflow
	if (in_buff_current_pos > in_buff_body_last_pos + 4)
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read 'int'", L"BinaryInput::readInt()");

	int value;
	memcpy(&value, in_buff_current_pos, 4);
	in_buff_current_pos += 4;

	return value;
};

inline long long BinaryInput::readLong() throw(...)
{
	// buffer overflow
	if (in_buff_current_pos > in_buff_body_last_pos + 8)
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read 'long'", L"BinaryInput::readLong()");

	long long value;
	memcpy(&value, in_buff_current_pos, 8);
	in_buff_current_pos += 8;

	return value;
};

inline double BinaryInput::readDouble() throw(...)
{
	// buffer overflow
	if (in_buff_current_pos > in_buff_body_last_pos + 8)
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read 'double'", L"BinaryInput::readDouble()");

	double value;
	memcpy(&value, in_buff_current_pos, 8);
	in_buff_current_pos += 8;

	return value;
};

inline void BinaryInput::readString(unsigned char* buff, int size) throw(...)
{
	// buffer overflow
	if (in_buff_current_pos > in_buff_body_last_pos + size)
	{
		std::wstringstream mess;
		mess << L"Unexpected end of the buffer, can't read 'string', size: " << size << L" bytes";
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, &mess, L"BinaryInput::readString");
	};
	memcpy(buff, in_buff_current_pos, size);
	in_buff_current_pos += size;
	
};

inline bool BinaryInput::readBool() throw(...)
{
	// buffer overflow
	if (in_buff_current_pos >= in_buff_body_last_pos)
		throw ErrorMessage(BIN_IN_BUFF_OVERFLOW, L"Unexpected end of the buffer, can't read 'bool'", L"BinaryInput::readBool()");

	bool value;
	if (*in_buff_current_pos == 255)
		value = true;
	else
		value = false;
	in_buff_current_pos++;

	return value;
}
