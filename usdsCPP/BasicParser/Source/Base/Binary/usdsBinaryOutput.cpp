#include "base\binary\usdsBinaryOutput.h"

using namespace usds;

BinaryOutput::BinaryOutput() throw(...)
try
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
		throw ErrorMessage(BIN_OUT__ALLOCATE_ERROR, "Can't allocate memory for output buffer. The size: ") << defaultDocSize;
	};
	buffLastPos = usdsBuff + defaultDocSize;
	buffFirstPos = usdsBuff + defaultFrontBuffSize;
	buffCurrentPos = buffFirstPos;

}
catch (ErrorMessage& err)
{
	throw ErrorStack("BinaryOutput::BinaryOutput") << err;
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
try
{
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
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeUVarint") << value;
	throw;
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
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeUVarint") << value;
	throw;
};

int BinaryOutput::writeUVarint(int value) throw(...)
try
{
	if (value < 0)
		throw ErrorMessage(BIN_OUT__NEGATIVE_VALUE, "Value must be > 0. Current value = ") << value;

	return writeUVarint(unsigned int(value));
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::writeUVarint") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeUVarint") << value;
	throw;
};


void BinaryOutput::writeInt(int value) throw(...)
try 
{
	checkSize(4);
	memcpy(buffCurrentPos, &value, 4);
	buffCurrentPos += 4;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeInt") << value;
	throw;
};

void BinaryOutput::writeLong(long long value) throw(...)
try 
{
	checkSize(8);
	memcpy(buffCurrentPos, &value, 8);
	buffCurrentPos += 8;

}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeLong") << value;
	throw;
};

void BinaryOutput::writeDouble(double value) throw(...)
try 
{
	checkSize(8);
	memcpy(buffCurrentPos, &value, 8);
	buffCurrentPos += 8;
	
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeDouble") << value;
	throw;
};

void BinaryOutput::writeByteArray(const void* value, size_t size) throw(...)
try
{
	checkSize(size);
	
	memcpy(buffCurrentPos, value, size);
	buffCurrentPos += size;

}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeByteArray") << value << size;
	throw;
};

void BinaryOutput::writeUByte(unsigned char value) throw(...)
try 
{
	checkSize(1);
	*buffCurrentPos = value;
	buffCurrentPos++;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeUByte") << value;
	throw;
};

void BinaryOutput::writeByte(int value) throw(...)
try
{
	if (value > 127 || value < -128)
		throw ErrorMessage(BIN_OUT__BEEG_VALUE, "Value must be [-128, 127]. Current value = ") << value;

	checkSize(1);
	*buffCurrentPos = ((unsigned char*)(&value))[0];
	buffCurrentPos++;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::writeByte") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeByte") << value;
	throw;
};

void BinaryOutput::writeBool(bool value) throw(...)
try
{
	checkSize(1);
	if (value)
		*buffCurrentPos = 255;
	else
		*buffCurrentPos = 0;
	buffCurrentPos++;

}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeBool") << value;
	throw;
};

void BinaryOutput::writeType(usdsTypes value) throw(...)
try
{
	checkSize(1);
	*buffCurrentPos = ((unsigned char*)(&value))[0];
	buffCurrentPos++;

}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeType") << value;
	throw;
};

//==========================================================================================================

void BinaryOutput::checkSize(size_t min_increase)  throw(...)
try
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
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW, "USDS out buffer owerflow. Old size: ") << buff_current_size << ", buffer minimal increas: " << min_increase;

	// Create new array and copy data
	unsigned char* new_usds_buff = 0;
	try
	{
		new_usds_buff = new unsigned char[new_size];
	}
	catch (...)
	{
		throw ErrorMessage(BIN_OUT__ALLOCATE_ERROR, "Can't reallocate memory for output buffer. New size: ") << new_size;
	}
	memcpy(new_usds_buff, usdsBuff, doc_current_size + front_buff_current_size);

	delete[] usdsBuff;
	usdsBuff = new_usds_buff;
	buffFirstPos = usdsBuff + front_buff_current_size;
	buffCurrentPos = buffFirstPos + doc_current_size;
	buffLastPos = usdsBuff + new_size;

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::checkSize") << min_increase << msg;
}

//==========================================================================================================

void BinaryOutput::pushFrontSize() throw(...)
try
{
	size_t doc_current_size = buffCurrentPos - buffFirstPos;
	size_t size = writeUVarint(doc_current_size);
	size_t front_size = buffFirstPos - usdsBuff;
	// check front buff
	if (front_size < size)
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW, "USDS front buffer owerflow. Current size: ") << buffFirstPos - usdsBuff << ", required: +" << size;

	// move data to the front
	buffCurrentPos -= size;
	buffFirstPos -= size;
	memcpy(buffFirstPos, buffCurrentPos, size);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::pushFrontSize") << msg;
}

void BinaryOutput::pushFrontUByte(unsigned char value) throw(...)
try
{
	// check front buff
	if ((buffFirstPos - usdsBuff) < 1)
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW, "USDS front buffer owerflow. Current size: ") << buffFirstPos - usdsBuff << ", required: +1 byte";

	buffFirstPos--;
	buffFirstPos[0] = value;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::pushFrontUByte") << value << msg;
}

void BinaryOutput::pushFrontInt(int value) throw(...)
try
{
	// check front buff
	if ((buffFirstPos - usdsBuff) < 4)
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "USDS front buffer owerflow. Current size: " << buffFirstPos - usdsBuff << ", required: +4 byte";

	buffFirstPos -= 4;
	memcpy(buffFirstPos, &value, 4);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::pushFrontInt") << value << msg;
};

//===================================================================================================================
void BinaryOutput::readByteArray(size_t position, void* value, size_t size) throw(...)
try
{
	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	if ((position + size) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << size << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	memcpy(value, buffFirstPos + position, size);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::readByteArray") << position << value << size << msg;
};


