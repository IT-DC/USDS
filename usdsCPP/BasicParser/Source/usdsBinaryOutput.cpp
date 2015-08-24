#include "base\usdsBinaryOutput.h"

using namespace usds;

BinaryOutput::BinaryOutput()
{
	out_usds_buff = 0;
	out_default_doc_size = 4096;
	out_usds_buff = new unsigned char[out_default_doc_size];
	if (out_usds_buff == 0)
	{
		out_buff_last_pos = 0;
		out_buff_current_pos = 0;
	}
	else
	{
		out_buff_last_pos = out_usds_buff + out_default_doc_size;
		out_buff_current_pos = out_usds_buff;
	}

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


inline void BinaryOutput::writeUVarint(unsigned long long value) throw()
{
	try
	{
		resizeArray(10);
	}
	catch (errorMessage& err)
	{
		err.addMessage("BinaryOutput::writeUVarint");
		throw err;
	};

	// step 1 of 5
	memcpy(out_buff_current_pos, &value, 8);
	out_buff_current_pos++;
	if (value < 128)
		return;
	out_buff_current_pos[7] = 0;
	out_buff_current_pos[8] = 0;

	// step 2 of 5
	*((int*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;

	out_buff_current_pos++;
	if (value < 16384)
		return;

	// step 3 of 5
	*((int*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	if (value < 2097152)
		return;

	// step 4 of 5
	*((int*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;
	if (value < 268435456)
		return;

	// step 5 of 5
	*((int*)out_buff_current_pos) <<= 1;
	if (*(out_buff_current_pos - 1) & 128)
		*out_buff_current_pos |= 1;
	else
		*(out_buff_current_pos - 1) |= 128;
	out_buff_current_pos++;

};

inline void BinaryOutput::writeInt(int value)
{
	memcpy(out_buff_current_pos, &value, 4);
	out_buff_current_pos += 4;
};

inline void BinaryOutput::writeLong(long long value)
{
	memcpy(out_buff_current_pos, &value, 8);
	out_buff_current_pos += 8;

};

inline void BinaryOutput::writeDouble(double value)
{
	memcpy(out_buff_current_pos, &value, 8);
	out_buff_current_pos += 8;
	
};

inline void BinaryOutput::writeUTF8String(const char* value, int size) throw()
{
	// add string without NULL-simbol
	memcpy(out_buff_current_pos, value, size);
	out_buff_current_pos += size;

};

inline void BinaryOutput::writeBool(bool value)
{
	if (value)
		*out_buff_current_pos = 255;
	else
		*out_buff_current_pos = 0;
	out_buff_current_pos++;

};


inline void BinaryOutput::resizeArray(size_t min_increase)  throw()
{
	if ((out_buff_last_pos - out_buff_current_pos) >= min_increase)
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
		std::string mess("USDS out buffer owerflow. Old size: ");
		mess += buff_current_size;
		mess += ", buffer minimal increas: ";
		mess += min_increase;
		throw errorMessage(BIN_OUT_BUFFER_OVERFLOW, &mess, "BinaryOutput::resizeArray");
	};

	// Create new array and copy data
	unsigned char* new_usds_buff = 0;
	try
	{
		new_usds_buff = new unsigned char[new_size];
	}
	catch (...)
	{
		new_usds_buff = 0;
	}
	if (new_usds_buff == 0)
	{
		std::string mess("Can't reallocate memory for output buffer. New size: ");
		mess += new_size;
		throw errorMessage(BIN_OUT_ALLOCATE_ERROR, &mess, "BinaryOutput::resizeArray");
	}
	memcpy(new_usds_buff, out_usds_buff, doc_current_size);

	delete[] out_usds_buff;
	out_usds_buff = new_usds_buff;
	out_buff_current_pos = out_usds_buff + doc_current_size;
	out_buff_last_pos = out_usds_buff + new_size;

};