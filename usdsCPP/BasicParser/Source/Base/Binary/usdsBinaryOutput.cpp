#include "base\binary\usdsBinaryOutput.h"

using namespace usds;

BinaryOutput::BinaryOutput() throw(...)
{
	usdsBuff = 0;
	defaultDocSize = 4096;
	defaultFrontBuffSize = 64;
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
	buffFirstPos = usdsBuff + defaultFrontBuffSize;
	buffCurrentPos = buffFirstPos;

};

BinaryOutput::~BinaryOutput()
{
	if (usdsBuff != 0)
		delete[] usdsBuff;
};

bool BinaryOutput::isEmpty()
{
	
	return (buffCurrentPos == buffFirstPos);
};

void BinaryOutput::clear()
{
	buffFirstPos = usdsBuff + defaultFrontBuffSize;
	buffCurrentPos = buffFirstPos;
};

const unsigned char* BinaryOutput::getBinary(size_t* size) throw(...)
{
	*size = buffCurrentPos - buffFirstPos;
	return buffFirstPos;
};

size_t BinaryOutput::getSize()
{
	return buffCurrentPos - buffFirstPos;
};

const unsigned char* BinaryOutput::getBinary() throw(...)
{
	return buffFirstPos;
};

//==============================================================================================================

int BinaryOutput::writeUVarint(unsigned long long value) throw(...)
try {
	checkSize(17);	// 8 bytes - "long long", 9 bytes - shiftes

	// step 1 of 10
	memcpy(buffCurrentPos, &value, 8);
	buffCurrentPos++;
	if (value < 128ull)
		return 1;
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
		return 2;

	// step 3 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull)
		return 3;

	// step 4 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull)
		return 4;

	// step 5 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull)
		return 5;

	// step 6 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return 6;

	// step 7 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return 7;

	// step 8 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return 8;

	// step 9 of 10
	*((unsigned long long*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return 9;

	// step 10 of 10
	buffCurrentPos[0] = 1;
	buffCurrentPos++;
	return 10;
}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeUVarint(unsigned long long)");
	throw err;
};


int BinaryOutput::writeUVarint(unsigned int value) throw(...)
try {
	checkSize(12);	// 4 bytes - "unsigned int", 8 bytes - shiftes

	// step 1 of 5
	memcpy(buffCurrentPos, &value, 4);
	buffCurrentPos++;
	if (value < 128u)
		return 1;
	buffCurrentPos[3] = 0;

	// step 2 of 5
	*((unsigned int*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128u * 128u)
		return 2;

	// step 3 of 5
	*((unsigned int*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128 * 128u * 128u)
		return 3;

	// step 4 of 5
	*((unsigned int*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128 * 128u * 128u * 128u)
		return 4;

	// step 5 of 5
	*((unsigned int*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	return 5;
}
catch (ErrorMessage& err)
{
	err.addPath(L"BinaryOutput::writeUVarint(unsigned int)");
	throw err;
};

int BinaryOutput::writeUVarint(int value) throw(...)
try
{
	if (value < 0)
	{
		std::wstringstream msg;
		msg << L"Value must be > 0. Current value = " << value;
		throw ErrorMessage(BIN_OUT_NEGATIVE_VALUE, &msg);
	}

	return writeUVarint(unsigned int(value));

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
	size_t doc_current_size = buffCurrentPos - buffFirstPos;
	size_t front_buff_current_size = buffFirstPos - usdsBuff;
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
	memcpy(new_usds_buff, usdsBuff, doc_current_size + front_buff_current_size);

	delete[] usdsBuff;
	usdsBuff = new_usds_buff;
	buffFirstPos = usdsBuff + front_buff_current_size;
	buffCurrentPos = buffFirstPos + doc_current_size;
	buffLastPos = usdsBuff + new_size;

};

//==========================================================================================================

void BinaryOutput::pushFrontSize() throw(...)
{
	size_t doc_current_size = buffCurrentPos - buffFirstPos;
	size_t size = writeUVarint(doc_current_size);
	size_t front_size = buffFirstPos - usdsBuff;
	// check front buff
	if (front_size < size)
	{
		std::wstringstream mess;
		mess << L"USDS front buffer owerflow. Current size: " << buffFirstPos - usdsBuff << L", required: +" << size;
		throw ErrorMessage(BIN_OUT_BUFFER_OVERFLOW, &mess, L"BinaryOutput::pushFrontSize");
	};

	// move data to the front
	buffCurrentPos -= size;
	buffFirstPos -= size;
	memcpy(buffFirstPos, buffCurrentPos, size);

};

void BinaryOutput::pushFrontUByte(unsigned char value) throw(...)
{
	// check front buff
	if ((buffFirstPos - usdsBuff) < 1)
	{
		std::wstringstream mess;
		mess << L"USDS front buffer owerflow. Current size: " << buffFirstPos - usdsBuff << L", required: +1 byte";
		throw ErrorMessage(BIN_OUT_BUFFER_OVERFLOW, &mess, L"BinaryOutput::pushFrontUByte");
	};
	buffFirstPos--;
	buffFirstPos[0] = value;
};

void BinaryOutput::pushFrontInt(int value) throw(...)
{
	// check front buff
	if ((buffFirstPos - usdsBuff) < 4)
	{
		std::wstringstream mess;
		mess << L"USDS front buffer owerflow. Current size: " << buffFirstPos - usdsBuff << L", required: +4 byte";
		throw ErrorMessage(BIN_OUT_BUFFER_OVERFLOW, &mess, L"BinaryOutput::pushFrontInt");
	};
	buffFirstPos -= 4;
	memcpy(buffFirstPos, &value, 4);

};