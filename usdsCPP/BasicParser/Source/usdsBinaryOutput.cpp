#include "base\usdsBinaryOutput.h"

using namespace usds;

BinaryOutput::BinaryOutput() throw(...)
{
	out_usds_buff = 0;
	out_default_doc_size = 4096;
	try
	{
		out_usds_buff = new unsigned char[out_default_doc_size];
	}
	catch (...)
	{
		std::wstringstream mess;
		mess << L"Can't allocate memory for output buffer. The size: " << out_default_doc_size;
		throw ErrorMessage(BIN_OUT_ALLOCATE_ERROR, &mess, L"BinaryOutput::BinaryOutput()");
	};
	out_buff_last_pos = out_usds_buff + out_default_doc_size;
	out_buff_current_pos = out_usds_buff;

};

BinaryOutput::~BinaryOutput()
{
	if (out_usds_buff != 0)
		delete[] out_usds_buff;
};

void BinaryOutput::clean()
{
	// output buffer
	out_buff_current_pos = out_usds_buff;

};


inline void BinaryOutput::writeUVarint(unsigned long long value) throw(...)
try {
	checkSize(17);	// 8 bytes - "long long", 9 bytes - shiftes

	// step 1 of 10
	memcpy(out_buff_current_pos, &value, 8);
	out_buff_current_pos++;
	if (value < 128ull)
		return;
	out_buff_current_pos[7] = 0;
	out_buff_current_pos[8] = 0;

	// step 2 of 10
	*((unsigned long long*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	if (value < 128ull * 128ull)
		return;

	// step 3 of 10
	*((unsigned long long*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	if (value < 128ull * 128ull * 128ull)
		return;

	// step 4 of 10
	*((unsigned long long*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	if (value < 128ull * 128ull * 128ull * 128ull)
		return;

	// step 5 of 10
	*((unsigned long long*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull)
		return;

	// step 6 of 10
	*((unsigned long long*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return;

	// step 7 of 10
	*((unsigned long long*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return;

	// step 8 of 10
	*((unsigned long long*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return;

	// step 9 of 10
	*((unsigned long long*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return;

	// step 10 of 10
	out_buff_current_pos[0] = 1;
	out_buff_current_pos++;
}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeUVarint(unsigned long long)");
	throw err;
};


inline void BinaryOutput::writeUVarint(unsigned int value) throw(...)
try {
	checkSize(8);	// 4 bytes - "unsigned int", 8 bytes - shiftes

	// step 1 of 5
	memcpy(out_buff_current_pos, &value, 4);
	out_buff_current_pos++;
	if (value < 128u)
		return;
	out_buff_current_pos[3] = 0;

	// step 2 of 5
	*((unsigned int*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	if (value < 128u * 128u)
		return;

	// step 3 of 5
	*((unsigned int*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	if (value < 128 * 128u * 128u)
		return;

	// step 4 of 5
	*((unsigned int*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	if (value < 128 * 128u * 128u * 128u)
		return;

	// step 5 of 5
	*((unsigned int*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	
}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeUVarint(unsigned int)");
	throw err;
};

inline void BinaryOutput::writeInt(int value) throw(...)
try {
	checkSize(4);
	memcpy(out_buff_current_pos, &value, 4);
	out_buff_current_pos += 4;
}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeInt");
	throw err;
};

inline void BinaryOutput::writeLong(long long value) throw(...)
try {
	checkSize(8);
	memcpy(out_buff_current_pos, &value, 8);
	out_buff_current_pos += 8;

}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeInt");
	throw err;
};

inline void BinaryOutput::writeDouble(double value) throw(...)
try {
	checkSize(8);
	memcpy(out_buff_current_pos, &value, 8);
	out_buff_current_pos += 8;
	
}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeInt");
	throw err;
};

inline void BinaryOutput::writeUTF8String(const char* value, int size) throw(...)
try {
	checkSize(size);
	// add string without NULL-simbol
	memcpy(out_buff_current_pos, value, size);
	out_buff_current_pos += size;

}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeInt");
	throw err;
};

inline void BinaryOutput::writeBool(bool value) throw(...)
try {
	checkSize(1);
	if (value)
		*out_buff_current_pos = 255;
	else
		*out_buff_current_pos = 0;
	out_buff_current_pos++;

}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeInt");
	throw err;
};


inline void BinaryOutput::checkSize(size_t min_increase)  throw(...)
{
	if ((size_t)(out_buff_last_pos - out_buff_current_pos) >= min_increase)
		return;

	// New size is +25%, but it have to be more, then size+minIncrease
	size_t buff_current_size = out_buff_last_pos - out_usds_buff;
	size_t doc_current_size = out_buff_current_pos - out_usds_buff;
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
		throw ErrorMessage(BIN_OUT_BUFFER_OVERFLOW, &mess, L"BinaryOutput::resizeArray");
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
		throw ErrorMessage(BIN_OUT_ALLOCATE_ERROR, &mess, L"BinaryOutput::resizeArray");
	}

	memcpy(new_usds_buff, out_usds_buff, doc_current_size);

	delete[] out_usds_buff;
	out_usds_buff = new_usds_buff;
	out_buff_current_pos = out_usds_buff + doc_current_size;
	out_buff_last_pos = out_usds_buff + new_size;

};