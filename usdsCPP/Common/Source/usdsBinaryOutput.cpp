#include "usdsBinaryOutput.h"
#include <math.h>

using namespace usds;

BinaryOutput::BinaryOutput(size_t front_buffer_size) throw(...)
try
{
	usdsBuff = 0;
	defaultDocSize = 4096;
	defaultFrontBuffSize = front_buffer_size;
	try
	{
		usdsBuff = new uint8_t[defaultDocSize];
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

void BinaryOutput::clear()
{
	buffFirstPos = usdsBuff + defaultFrontBuffSize;
	buffCurrentPos = buffFirstPos;
};

const uint8_t* BinaryOutput::getBinary(size_t* size) throw(...)
{
	if (size == 0)
		throw ErrorStack("BinaryOutput::getBinary") << size << ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer for Size can not be NULL");
	*size = buffCurrentPos - buffFirstPos;
	return buffFirstPos;
};

const uint8_t* BinaryOutput::getBinary() throw(...)
{
	return buffFirstPos;
};

size_t BinaryOutput::getSize()
{
	return buffCurrentPos - buffFirstPos;
};

size_t BinaryOutput::getBufferSize()
{
	return buffLastPos - buffFirstPos;
}

void BinaryOutput::setBufferSize(size_t new_size) throw(...)
try
{
	size_t buff_current_size = buffLastPos - buffFirstPos;
	if (buff_current_size >= new_size)
		return;

	checkSize(new_size - (buffCurrentPos - buffFirstPos));
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::setBufferSize") << new_size;
	throw;
};

//==============================================================================================================

size_t BinaryOutput::writeUVarint(uint64_t value) throw(...)
try
{
	checkSize(17);	// 8 bytes - "uint64_t", 9 bytes - shiftes

	// step 1 of 10
	memcpy(buffCurrentPos, &value, 8);
	buffCurrentPos++;
	if (value < 128ull)
		return 1;
	buffCurrentPos[7] = 0;
	buffCurrentPos[8] = 0;

	// step 2 of 10
	*((uint64_t*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull)
		return 2;

	// step 3 of 10
	*((uint64_t*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull)
		return 3;

	// step 4 of 10
	*((uint64_t*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull)
		return 4;

	// step 5 of 10
	*((uint64_t*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull)
		return 5;

	// step 6 of 10
	*((uint64_t*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return 6;

	// step 7 of 10
	*((uint64_t*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return 7;

	// step 8 of 10
	*((uint64_t*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull * 128ull)
		return 8;

	// step 9 of 10
	*((uint64_t*)buffCurrentPos) <<= 1;
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


size_t BinaryOutput::writeUVarint(uint32_t value) throw(...)
try {
	checkSize(12);	// 4 bytes - "uint32_t", 8 bytes - shiftes

	// step 1 of 5
	memcpy(buffCurrentPos, &value, 4);
	buffCurrentPos++;
	if (value < 128u)
		return 1;
	buffCurrentPos[3] = 0;

	// step 2 of 5
	*((uint32_t*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128u * 128u)
		return 2;

	// step 3 of 5
	*((uint32_t*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128 * 128u * 128u)
		return 3;

	// step 4 of 5
	*((uint32_t*)buffCurrentPos) <<= 1;
	if (*(buffCurrentPos - 1) & 128)
		*buffCurrentPos |= 1;
	else
		*(buffCurrentPos - 1) |= 128;
	buffCurrentPos++;
	if (value < 128 * 128u * 128u * 128u)
		return 4;

	// step 5 of 5
	*((uint32_t*)buffCurrentPos) <<= 1;
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

size_t BinaryOutput::writeUVarint(int32_t value) throw(...)
try
{
	if (value < 0)
		throw ErrorMessage(BIN_OUT__NEGATIVE_VALUE, "Value must be > 0. Current value = ") << value;

	return writeUVarint(uint32_t(value));
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

void BinaryOutput::writeShort(int16_t value) throw(...)
try
{
	checkSize(USDS_SHORT_SIZE);
	memcpy(buffCurrentPos, &value, USDS_SHORT_SIZE);
	buffCurrentPos += USDS_SHORT_SIZE;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeShort") << value;
	throw;
};

void BinaryOutput::writeUShort(uint16_t value) throw(...)
try
{
	checkSize(USDS_USHORT_SIZE);
	memcpy(buffCurrentPos, &value, USDS_USHORT_SIZE);
	buffCurrentPos += USDS_USHORT_SIZE;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeShort") << value;
	throw;
};

void BinaryOutput::writeInt(int32_t value) throw(...)
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

void BinaryOutput::writeUInt(uint32_t value) throw(...)
try
{
	checkSize(USDS_UINT_SIZE);
	memcpy(buffCurrentPos, &value, USDS_UINT_SIZE);
	buffCurrentPos += USDS_UINT_SIZE;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeUInt") << value;
	throw;
};

void BinaryOutput::writeLong(int64_t value) throw(...)
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

void BinaryOutput::writeULong(uint64_t value) throw(...)
try
{
	checkSize(USDS_ULONG_SIZE);
	memcpy(buffCurrentPos, &value, USDS_ULONG_SIZE);
	buffCurrentPos += USDS_ULONG_SIZE;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeUInt") << value;
	throw;
};

void BinaryOutput::writeFloat(float value) throw(...)
try 
{
	checkSize(4);
	memcpy(buffCurrentPos, &value, 4);
	buffCurrentPos += 4;
	
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeDouble") << value;
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
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the Byte array can not be null");
	
	checkSize(size);
	
	memcpy(buffCurrentPos, value, size);
	buffCurrentPos += size;

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::writeByteArray") << value << size << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeByteArray") << value << size;
	throw;
};

void BinaryOutput::writeUByte(uint8_t value) throw(...)
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

void BinaryOutput::writeByte(int8_t value) throw(...)
try
{
	checkSize(1);
	*buffCurrentPos = value;
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

void BinaryOutput::writeBoolean(bool value) throw(...)
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
	err.addLevel("BinaryOutput::writeBoolean") << value;
	throw;
};

void BinaryOutput::writeType(usdsTypes value) throw(...)
try
{
	checkSize(1);
	*buffCurrentPos = ((uint8_t*)(&value))[0];
	buffCurrentPos++;

}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeType") << value;
	throw;
};

void BinaryOutput::writeEncode(usdsEncodes value) throw(...)
try
{
	checkSize(1);
	*buffCurrentPos = ((uint8_t*)(&value))[0];
	buffCurrentPos++;

}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::usdsEncodes") << value;
	throw;
};

void BinaryOutput::writeSignature(usdsSignature value) throw(...)
try
{
	checkSize(1);
	*buffCurrentPos = ((uint8_t*)(&value))[0];
	buffCurrentPos++;

}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeSignature") << value;
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
	if (((new_size - doc_current_size) - front_buff_current_size) < min_increase)
		new_size = doc_current_size + front_buff_current_size + min_increase;
	// Size has to be a multiple of 64 byte
	new_size = (new_size / 64 + 1) * 64;

	// Buffer overflow
	if (new_size < buff_current_size || new_size < min_increase)
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW, "USDS out buffer owerflow. Old size: ") << buff_current_size << ", buffer minimal increas: " << min_increase;

	// Create new array and copy data
	uint8_t* new_usds_buff = 0;
	try
	{
		new_usds_buff = new uint8_t[new_size];
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
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::pushFrontSize");
	throw;
};

void BinaryOutput::pushFrontUByte(uint8_t value) throw(...)
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
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::pushFrontUByte") << value;
	throw;
};

void BinaryOutput::pushFrontUInt(uint32_t value) throw(...)
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
	throw ErrorStack("BinaryOutput::pushFrontUInt") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::pushFrontUInt") << value;
	throw;
};

void BinaryOutput::pushFrontSignature(usdsSignature value) throw(...)
try
{
	// check front buff
	if ((buffFirstPos - usdsBuff) < 1)
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW, "USDS front buffer owerflow. Current size: ") << buffFirstPos - usdsBuff << ", required: +1 byte";

	buffFirstPos--;
	buffFirstPos[0] = ((uint8_t*)(&value))[0];
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::pushFrontSignature") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::pushFrontSignature") << value;
	throw;
};

//===================================================================================================================
void BinaryOutput::readByteArray(size_t position, void* value, size_t size) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the Output byte array can not be null");
	
	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	if ((position + size) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << size << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	memcpy(value, buffFirstPos + position, size);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::readByteArray") << position << value << size << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::readByteArray") << position << value << size;
	throw;
};

//===================================================================================================================
void BinaryOutput::write(usdsTypes usds_type, bool value) throw(...)
try
{
	switch (usds_type)
	{
	case USDS_BOOLEAN:
		writeBoolean(value);
		break;
	default:
		throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from bool to " << usdsTypeName(usds_type);
	}
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::write") << usds_type << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::write") << usds_type << value;
	throw;
};

void BinaryOutput::write(usdsTypes usds_type, int8_t value) throw(...)
try
{
	size_t type_size = usdsTypeSize(usds_type);
	checkSize(type_size);
	usdsTypeWrite(value, usds_type, buffCurrentPos);
	buffCurrentPos += type_size;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::write") << usds_type << value;
	throw;
};

void BinaryOutput::write(usdsTypes usds_type, uint8_t value) throw(...)
try
{
	size_t type_size = usdsTypeSize(usds_type);
	checkSize(type_size);
	usdsTypeWrite(value, usds_type, buffCurrentPos);
	buffCurrentPos += type_size;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::write") << usds_type << value;
	throw;
};

void BinaryOutput::write(usdsTypes usds_type, int16_t value) throw(...)
try
{
	size_t type_size = usdsTypeSize(usds_type);
	checkSize(type_size);
	usdsTypeWrite(value, usds_type, buffCurrentPos);
	buffCurrentPos += type_size;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::write") << usds_type << value;
	throw;
};

void BinaryOutput::write(usdsTypes usds_type, uint16_t value) throw(...)
try
{
	size_t type_size = usdsTypeSize(usds_type);
	checkSize(type_size);
	usdsTypeWrite(value, usds_type, buffCurrentPos);
	buffCurrentPos += type_size;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::write") << usds_type << value;
	throw;
};


void BinaryOutput::write(usdsTypes usds_type, int32_t value) throw(...)
try
{
	size_t type_size = usdsTypeSize(usds_type);
	checkSize(type_size);
	usdsTypeWrite(value, usds_type, buffCurrentPos);
	buffCurrentPos += type_size;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::write") << usds_type << value;
	throw;
};

void BinaryOutput::write(usdsTypes usds_type, uint32_t value) throw(...)
try
{
	size_t type_size = usdsTypeSize(usds_type);
	checkSize(type_size);
	usdsTypeWrite(value, usds_type, buffCurrentPos);
	buffCurrentPos += type_size;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::write") << usds_type << value;
	throw;
};


void BinaryOutput::write(usdsTypes usds_type, int64_t value) throw(...)
try
{
	size_t type_size = usdsTypeSize(usds_type);
	checkSize(type_size);
	usdsTypeWrite(value, usds_type, buffCurrentPos);
	buffCurrentPos += type_size;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::write") << usds_type << value;
	throw;
};

void BinaryOutput::write(usdsTypes usds_type, uint64_t value) throw(...)
try
{
	size_t type_size = usdsTypeSize(usds_type);
	checkSize(type_size);
	usdsTypeWrite(value, usds_type, buffCurrentPos);
	buffCurrentPos += type_size;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::write") << usds_type << value;
	throw;
};

void BinaryOutput::write(usdsTypes usds_type, float value) throw(...)
try
{
	size_t type_size = usdsTypeSize(usds_type);
	checkSize(type_size);
	usdsTypeWrite(value, usds_type, buffCurrentPos);
	buffCurrentPos += type_size;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::write") << usds_type << value;
	throw;
};

void BinaryOutput::write(usdsTypes usds_type, double value) throw(...)
try
{
	size_t type_size = usdsTypeSize(usds_type);
	checkSize(type_size);
	usdsTypeWrite(value, usds_type, buffCurrentPos);
	buffCurrentPos += type_size;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::write") << usds_type << value;
	throw;
};

//===================================================================================================================

void BinaryOutput::read(size_t position, usdsTypes usds_type, bool* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	if (usds_type != USDS_BOOLEAN)
		throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from " << usdsTypeName(usds_type) << " to bool";

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	if ((position + USDS_BOOLEAN_SIZE) > doc_size)
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << USDS_BOOLEAN_SIZE << " byte from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	if ((buffFirstPos + position)[0] == 0)
		*value = false;
	else
		*value = true;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::read") << position << usds_type << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::read") << position << usds_type << value;
	throw;
};

void BinaryOutput::read(size_t position, usdsTypes usds_type, int8_t* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	size_t type_size = usdsTypeSize(usds_type);
	if ((position + type_size) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << type_size << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	usdsTypeRead(buffFirstPos + position, usds_type, value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::read") << position << usds_type << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::read") << position << usds_type << value;
	throw;
};

void BinaryOutput::read(size_t position, usdsTypes usds_type, uint8_t* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	size_t type_size = usdsTypeSize(usds_type);
	if ((position + type_size) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << type_size << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	usdsTypeRead(buffFirstPos + position, usds_type, value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::read") << position << usds_type << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::read") << position << usds_type << value;
	throw;
};

void BinaryOutput::read(size_t position, usdsTypes usds_type, int16_t* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	size_t type_size = usdsTypeSize(usds_type);
	if ((position + type_size) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << type_size << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	usdsTypeRead(buffFirstPos + position, usds_type, value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::read") << position << usds_type << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::read") << position << usds_type << value;
	throw;
};

void BinaryOutput::read(size_t position, usdsTypes usds_type, uint16_t* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	size_t type_size = usdsTypeSize(usds_type);
	if ((position + type_size) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << type_size << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	usdsTypeRead(buffFirstPos + position, usds_type, value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::read") << position << usds_type << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::read") << position << usds_type << value;
	throw;
};

void BinaryOutput::read(size_t position, usdsTypes usds_type, int32_t* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	size_t type_size = usdsTypeSize(usds_type);
	if ((position + type_size) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << type_size << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	usdsTypeRead(buffFirstPos + position, usds_type, value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::read") << position << usds_type << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::read") << position << usds_type << value;
	throw;
};

void BinaryOutput::read(size_t position, usdsTypes usds_type, uint32_t* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	size_t type_size = usdsTypeSize(usds_type);
	if ((position + type_size) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << type_size << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	usdsTypeRead(buffFirstPos + position, usds_type, value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::read") << position << usds_type << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::read") << position << usds_type << value;
	throw;
};

void BinaryOutput::read(size_t position, usdsTypes usds_type, int64_t* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	size_t type_size = usdsTypeSize(usds_type);
	if ((position + type_size) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << type_size << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	usdsTypeRead(buffFirstPos + position, usds_type, value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::read") << position << usds_type << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::read") << position << usds_type << value;
	throw;
};

void BinaryOutput::read(size_t position, usdsTypes usds_type, uint64_t* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	size_t type_size = usdsTypeSize(usds_type);
	if ((position + type_size) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << type_size << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	usdsTypeRead(buffFirstPos + position, usds_type, value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::read") << position << usds_type << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::read") << position << usds_type << value;
	throw;
};

void BinaryOutput::read(size_t position, usdsTypes usds_type, float* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	size_t type_size = usdsTypeSize(usds_type);
	if ((position + type_size) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << type_size << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	usdsTypeRead(buffFirstPos + position, usds_type, value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::read") << position << usds_type << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::read") << position << usds_type << value;
	throw;
};

void BinaryOutput::read(size_t position, usdsTypes usds_type, double* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	size_t type_size = usdsTypeSize(usds_type);
	if ((position + type_size) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << type_size << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	usdsTypeRead(buffFirstPos + position, usds_type, value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::read") << position << usds_type << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::read") << position << usds_type << value;
	throw;
};

void BinaryOutput::writePointer(void* value) throw(...)
try
{
	checkSize(sizeof(void*));
	memcpy(buffCurrentPos, &value, sizeof(void*));
	buffCurrentPos += sizeof(void*);
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writePointer") << value;
	throw;
};

void BinaryOutput::readPointer(size_t position, void** value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	if ((position + sizeof(void*)) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << sizeof(void*) << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	memcpy(value, buffFirstPos + position, sizeof(void*));
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::readPointer") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::readPointer") << position << value;
	throw;
};

size_t BinaryOutput::writeVarint(int64_t value) throw(...)
try
{
	checkSize(17);	// 8 bytes - "int64_t", 9 bytes - shiftes

	// step 1 of 10
	memcpy(buffCurrentPos, &value, 8);
	buffCurrentPos[8] = 0;

	// create absolute value
	if (value < 0)
	{
		*((uint64_t*)buffCurrentPos) = 0xFFFFFFFFFFFFFFFFULL - *((uint64_t*)buffCurrentPos);
		*((uint64_t*)buffCurrentPos) += 1ULL;
		if (buffCurrentPos[7] >= 128)
			buffCurrentPos[8] = 1;
		*((uint64_t*)buffCurrentPos) <<= 1;
		*((uint64_t*)buffCurrentPos) += 1;
	}
	else
		*((uint64_t*)buffCurrentPos) <<= 1;

	if (value < 64 && value > -64)
	{
		buffCurrentPos++;
		return 1;
	}
	buffCurrentPos++;

	size_t byte_size = 1;

	while(1)
	{
		byte_size++;

		*((uint64_t*)buffCurrentPos) <<= 1;
		if (*(buffCurrentPos - 1) & 128)
			*buffCurrentPos |= 1;
		else
			*(buffCurrentPos - 1) |= 128;
		
		if (*((uint64_t*)buffCurrentPos) < 128ULL)
		{
			buffCurrentPos++;
			return byte_size;
		}

		buffCurrentPos++;
		buffCurrentPos[7] = 0;
	}
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::writeVarint") << value;
	throw;
};



