#include "base\binary\usdsBinaryOutput.h"

using namespace usds;

BinaryOutput::BinaryOutput() throw(...)
{
	usdsBuff = 0;
	defaultDocSize = 4096;
	try
	{
		usdsBuff = new unsigned char[defaultDocSize];
	}
	catch (...)
	{
		std::wstringstream mess;
		mess << L"Can't allocate memory for output buffer. The size: " << defaultDocSize;
		throw ErrorMessage(BIN_OUT_ALLOCATE_ERROR, &mess, L"BinaryOutput::BinaryOutput()");
	};
	buffLastPos = usdsBuff + defaultDocSize;
	buffCurrentPos = usdsBuff;

};

BinaryOutput::~BinaryOutput()
{
	if (usdsBuff != 0)
		delete[] usdsBuff;
};

void BinaryOutput::clear()
{
	// output buffer
	buffCurrentPos = usdsBuff;

};

const unsigned char* BinaryOutput::getBinary(size_t* size) throw(...)
{
	*size = buffCurrentPos - usdsBuff;
	return usdsBuff;
};

//==============================================================================================================

void BinaryOutput::writeUVarint(unsigned long long value) throw(...)
try {
	checkSize(17);	// 8 bytes - "long long", 9 bytes - shiftes

	// step 1 of 10
	memcpy(buffCurrentPos, &value, 8);
	buffCurrentPos++;
	if (value < 128ull)
		return;
	buffCurrentPos[7] = 0;
	buffCurrentPos[8] = 0;

	// step 2 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull)
		return;

	// step 3 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull)
		return;

	// step 4 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull)
		return;

	// step 5 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull)
		return;

	// step 6 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return;

	// step 7 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return;

	// step 8 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return;

	// step 9 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return;

	// step 10 of 10
	buffCurrentPos[0] = 1;
	buffCurrentPos++;
}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeUVarint(unsigned long long)");
	throw err;
};


void BinaryOutput::writeUVarint(unsigned int value) throw(...)
try {
	checkSize(12);	// 4 bytes - "unsigned int", 8 bytes - shiftes

	// step 1 of 5
	memcpy(buffCurrentPos, &value, 4);
	buffCurrentPos++;
	if (value < 128u)
		return;
	buffCurrentPos[3] = 0;

	// step 2 of 5
	*((unsigned int*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128u * 128u)
		return;

	// step 3 of 5
	*((unsigned int*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128 * 128u * 128u)
		return;

	// step 4 of 5
	*((unsigned int*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128 * 128u * 128u * 128u)
		return;

	// step 5 of 5
	*((unsigned int*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	
}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeUVarint(unsigned int)");
	throw err;
};

void BinaryOutput::writeUVarint(int value) throw(...)
try
{
	if (value < 0)
	{
		std::wstringstream msg;
		msg << L"Value must be > 0. Current value = " << value;
		throw ErrorMessage(BIN_OUT_NEGATIVE_VALUE, &msg);
	}

	writeUVarint(unsigned int(value));

}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BinaryOutput::writeUVarint");
	throw msg;
};


void BinaryOutput::writeInt(int value) throw(...)
try {
	checkSize(4);
	memcpy(buffCurrentPos, &value, 4);
	buffCurrentPos += 4;
}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeInt");
	throw err;
};

void BinaryOutput::writeLong(long long value) throw(...)
try {
	checkSize(8);
	memcpy(buffCurrentPos, &value, 8);
	buffCurrentPos += 8;

}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeLong");
	throw err;
};

void BinaryOutput::writeDouble(double value) throw(...)
try {
	checkSize(8);
	memcpy(buffCurrentPos, &value, 8);
	buffCurrentPos += 8;
	
}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeDouble");
	throw err;
};

void BinaryOutput::writeByteArray(const void* value, size_t size) throw(...)
try {
	checkSize(size);
	// add string without NULL-simbol
	memcpy(buffCurrentPos, value, size);
	buffCurrentPos += size;

}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeByteArray");
	throw err;
};

void BinaryOutput::writeUByte(unsigned char value) throw(...)
try 
{
	checkSize(1);
	*buffCurrentPos = value;
	buffCurrentPos++;
}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeUByte");
	throw err;
};

void BinaryOutput::writeBool(bool value) throw(...)
try {
	checkSize(1);
	if (value)
		*buffCurrentPos = 255;
	else
		*buffCurrentPos = 0;
	buffCurrentPos++;

}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeBool");
	throw err;
};


void BinaryOutput::checkSize(size_t min_increase)  throw(...)
{
	if ((size_t)(buffLastPos - buffCurrentPos) >= min_increase)
		return;

	// New size is +25%, but it have to be more, then size+minIncrease
	size_t buff_current_size = buffLastPos - usdsBuff;
	size_t doc_current_size = buffCurrentPos - usdsBuff;
	size_t new_size = buff_current_size + buff_current_size / 4;
	if ((new_size - buff_current_size) < min_increase)
		new_size = buff_current_size + min_increase;
	// Size have to be a multiple of 64 byte
	new_size = (new_size / 64 + 1) * 64;

	// Buffer overflow
	if (new_size < buff_current_size)
	{
		std::wstringstream mess;
		mess << L"USDS out buffer owerflow. Old size: " << buff_current_size << L", buffer minimal increas: " << min_increase;
		throw ErrorMessage(BIN_OUT_BUFFER_OVERFLOW, &mess, L"BinaryOutput::checkSize");
	};

	// Create new array and copy data
	unsigned char* new_usds_buff = 0;
	try
	{
		new_usds_buff = new unsigned char[new_size];
	}
	catch (...)
	{
		std::wstringstream mess;
		mess << L"Can't reallocate memory for output buffer. New size: " << new_size;
		throw ErrorMessage(BIN_OUT_ALLOCATE_ERROR, &mess, L"BinaryOutput::checkSize");
	}

	memcpy(new_usds_buff, usdsBuff, doc_current_size);

	delete[] usdsBuff;
	usdsBuff = new_usds_buff;
	buffCurrentPos = usdsBuff + doc_current_size;
	buffLastPos = usdsBuff + new_size;

};