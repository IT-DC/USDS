#include "usdsBinaryOutput.h"

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
	checkSize(17);	// 8 bytes - "int64_t", 9 bytes - shiftes

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
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from bool to " << usdsTypeName(usds_type);
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
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		writeByte(value);
		break;
	}
	case USDS_UBYTE:
	{
		if (value < 0)
		throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[0, 255] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		uint8_t proxy_value = (uint8_t)value;
		writeUByte(proxy_value);
		break;
	}
	case USDS_INT:
	{
		int32_t proxy_value = value;
		writeInt(proxy_value);
		break;
	}
	case USDS_LONG:
	{
		int64_t proxy_value = value;
		writeLong(proxy_value);
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from int8_t to " << usdsTypeName(usds_type);
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

void BinaryOutput::write(usdsTypes usds_type, uint8_t value) throw(...)
try
{
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		if (value > 127)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[-128, 127] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		int8_t proxy_value = (int8_t)value;
		writeByte(proxy_value);
		break;
	}
	case USDS_UBYTE:
	{
		writeUByte(value);
		break;
	}
	case USDS_INT:
	{
		int32_t proxy_value = value;
		writeInt(proxy_value);
		break;
	}
	case USDS_LONG:
	{
		int64_t proxy_value = value;
		writeLong(proxy_value);
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from uint8_t to " << usdsTypeName(usds_type);
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


void BinaryOutput::write(usdsTypes usds_type, int16_t value) throw(...)
try
{
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		if (value > 127 || value < -128)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[-128, 127] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		int8_t proxy_value = (int8_t)value;
		writeByte(proxy_value);
		break;
	}
	case USDS_UBYTE:
	{
		if (value < 0 || value > 255)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[0, 255] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		uint8_t proxy_value = (uint8_t)value;
		writeUByte(proxy_value);
		break;
	}
	case USDS_INT:
	{
		int32_t proxy_value = value;
		writeInt(proxy_value);
		break;
	}
	case USDS_LONG:
	{
		int64_t proxy_value = value;
		writeLong(proxy_value);
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from int16_t to " << usdsTypeName(usds_type);
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

void BinaryOutput::write(usdsTypes usds_type, uint16_t value) throw(...)
try
{
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		if (value > 127)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[-128, 127] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		int8_t proxy_value = (int8_t)value;
		writeByte(proxy_value);
		break;
	}
	case USDS_UBYTE:
	{
		if (value > 255)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[0, 255] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		uint8_t proxy_value = (uint8_t)value;
		writeUByte(proxy_value);
		break;
	}
	case USDS_INT:
	{
		int32_t proxy_value = value;
		writeInt(proxy_value);
		break;
	}
	case USDS_LONG:
	{
		int64_t proxy_value = value;
		writeLong(proxy_value);
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from uint16_t to " << usdsTypeName(usds_type);
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


void BinaryOutput::write(usdsTypes usds_type, int32_t value) throw(...)
try
{
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		if (value > 127 || value < -128)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[-128, 127] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		int8_t proxy_value = (int8_t)value;
		writeByte(proxy_value);
		break;
	}
	case USDS_UBYTE:
	{
		if (value < 0 || value > 255)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[0, 255] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		uint8_t proxy_value = (uint8_t)value;
		writeUByte(proxy_value);
		break;
	}
	case USDS_INT:
	{
		writeInt(value);
		break;
	}
	case USDS_LONG:
	{
		int64_t proxy_value = value;
		writeLong(proxy_value);
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from int32_t to " << usdsTypeName(usds_type);
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

void BinaryOutput::write(usdsTypes usds_type, uint32_t value) throw(...)
try
{
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		if (value > 127)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[-128, 127] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		int8_t proxy_value = (int8_t)value;
		writeByte(proxy_value);
		break;
	}
	case USDS_UBYTE:
	{
		if (value > 255)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[0, 255] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		uint8_t proxy_value = (uint8_t)value;
		writeUByte(proxy_value);
		break;
	}
	case USDS_INT:
	{
		if (value > INT32_MAX)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [-2147483648, 2147483647] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		int32_t proxy_value = (int32_t)value;
		writeInt(proxy_value);
		break;
	}
	case USDS_LONG:
	{
		int64_t proxy_value = value;
		writeLong(proxy_value);
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from uint32_t to " << usdsTypeName(usds_type);
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


void BinaryOutput::write(usdsTypes usds_type, int64_t value) throw(...)
try
{
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		if (value > 127 || value < -128)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [-128, 127] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		int8_t proxy_value = (int8_t)value;
		writeByte(proxy_value);
		break;
	}
	case USDS_UBYTE:
	{
		if (value < 0 || value > 255)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [0, 255] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		uint8_t proxy_value = (uint8_t)value;
		writeUByte(proxy_value);
		break;
	}
	case USDS_INT:
	{
		if (value < INT32_MIN|| value > INT32_MAX)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [-2147483648, 2147483647] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		int32_t proxy_value = (int32_t)value;
		writeInt(proxy_value);
		break;
	}
	case USDS_LONG:
	{
		writeLong(value);
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from int64_t to " << usdsTypeName(usds_type);
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

void BinaryOutput::write(usdsTypes usds_type, uint64_t value) throw(...)
try
{
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		if (value > 127)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [-128, 127] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		int8_t proxy_value = (int8_t)value;
		writeByte(proxy_value);
		break;
	}
	case USDS_UBYTE:
	{
		if (value > 255)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [0, 255] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		uint8_t proxy_value = (uint8_t)value;
		writeUByte(proxy_value);
		break;
	}
	case USDS_INT:
	{
		if (value > INT32_MAX)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [-2147483648, 2147483647] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		int32_t proxy_value = (int32_t)value;
		writeInt(proxy_value);
		break;
	}
	case USDS_LONG:
	{
		if (value > INT64_MAX)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [-(2^63), (2^63–1)] for type " << usdsTypeName(usds_type) << ". Current value: " << value;
		int64_t proxy_value = (int64_t)value;
		writeLong(proxy_value);
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from uint64_t to " << usdsTypeName(usds_type);
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

//===================================================================================================================

void BinaryOutput::readBoolean(size_t position, bool* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	if ((position + USDS_BOOLEAN_SIZE) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << USDS_BOOLEAN_SIZE << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";
	if ((buffFirstPos+position)[0] == 0)
		*value = false;
	else
		*value = true;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::readBoolean") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::readBoolean") << position << value;
	throw;
};

void BinaryOutput::readByte(size_t position, int8_t* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");
	
	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	if ((position + USDS_BYTE_SIZE) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << USDS_BYTE_SIZE << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	*value = (buffFirstPos + position)[0];
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::readByte") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::readByte") << position << value;
	throw;
};

void BinaryOutput::readUByte(size_t position, uint8_t* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	if ((position + USDS_UBYTE_SIZE) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << USDS_UBYTE_SIZE << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	*value = (buffFirstPos + position)[0];
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::readUByte") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::readUByte") << position << value;
	throw;
};


void BinaryOutput::readInt(size_t position, int32_t* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	if ((position + USDS_INT_SIZE) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << USDS_INT_SIZE << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	memcpy(value, buffFirstPos + position, USDS_INT_SIZE);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::readInt") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::readInt") << position << value;
	throw;
};

void BinaryOutput::readLong(size_t position, int64_t* value) throw(...)
try
{
	if (value == 0)
		throw ErrorMessage(BIN_OUT__NULL_POINTER, "Pointer of the output value can not be null");

	// check buff size
	size_t doc_size = buffCurrentPos - buffFirstPos;
	if ((position + USDS_LONG_SIZE) > (doc_size))
		throw ErrorMessage(BIN_OUT__BUFFER_OVERFLOW) << "Can not read " << USDS_LONG_SIZE << " bytes from position" << position << " , document's size is less: " << (buffCurrentPos - buffFirstPos) << " bytes";

	memcpy(value, buffFirstPos + position, USDS_LONG_SIZE);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryOutput::readLong") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryOutput::readLong") << position << value;
	throw;
};


//===================================================================================================================

void BinaryOutput::read(size_t position, usdsTypes usds_type, bool* value) throw(...)
try
{
	switch (usds_type)
	{
	case USDS_BOOLEAN:
		readBoolean(position, value);
		break;
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from " << usdsTypeName(usds_type) << " to bool";

	}
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
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		readByte(position, value);
		break;
	}
	case USDS_UBYTE:
	{
		uint8_t proxy_value;
		readUByte(position, &proxy_value);
		if (proxy_value > 127)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[-128, 127] for type int8_t. Value in USDS binary: " << *value;
		*value = (int8_t)proxy_value;
		break;
	}
	case USDS_INT:
	{
		int32_t proxy_value;
		readInt(position, &proxy_value);
		if (proxy_value > 127 || proxy_value < -128)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[-128, 127] for type int8_t. Value in USDS binary: " << *value;
		*value = (int8_t)proxy_value;
		break;
	}
	case USDS_LONG:
	{
		int64_t proxy_value;
		readLong(position, &proxy_value);
		if (proxy_value > 127 || proxy_value < -128)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[-128, 127] for type int8_t. Value in USDS binary: " << *value;
		*value = (int8_t)proxy_value;
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from " << usdsTypeName(usds_type) << " to int8_t";

	}
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
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		int8_t proxy_value;
		readByte(position, &proxy_value);
		if (proxy_value < 0)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[0, 255] for type uint8_t. Value in USDS binary: " << *value;
		*value = (uint8_t)proxy_value;
		break;
	}
	case USDS_UBYTE:
	{
		readUByte(position, value);
		break;
	}
	case USDS_INT:
	{
		int32_t proxy_value;
		readInt(position, &proxy_value);
		if (proxy_value > 255 || proxy_value < 0)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[0, 255] for type uint8_t. Value in USDS binary: " << *value;
		*value = (uint8_t)proxy_value;
		break;
	}
	case USDS_LONG:
	{
		int64_t proxy_value;
		readLong(position, &proxy_value);
		if (proxy_value > 255 || proxy_value < 0)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[0, 255] for type uint8_t. Value in USDS binary: " << *value;
		*value = (uint8_t)proxy_value;
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from " << usdsTypeName(usds_type) << " to uint8_t";

	}
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
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		int8_t proxy_value;
		readByte(position, &proxy_value);
		*value = proxy_value;
		break;
	}
	case USDS_UBYTE:
	{
		uint8_t proxy_value;
		readUByte(position, &proxy_value);
		*value = proxy_value;
		break;
	}
	case USDS_INT:
	{
		int32_t proxy_value;
		readInt(position, &proxy_value);
		if (proxy_value > 32767 || proxy_value < -32768)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[-32768, 32767] for type int16_t. Value in USDS binary: " << *value;
		*value = (int16_t)proxy_value;
		break;
	}
	case USDS_LONG:
	{
		int64_t proxy_value;
		readLong(position, &proxy_value);
		if (proxy_value > 32767 || proxy_value < -32768)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[-32768, 32767] for type int16_t. Value in USDS binary: " << *value;
		*value = (int16_t)proxy_value;
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from " << usdsTypeName(usds_type) << " to int16_t";

	}
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
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		int8_t proxy_value;
		readByte(position, &proxy_value);
		if (proxy_value < 0)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[0, 65535] for type uint16_t. Value in USDS binary: " << *value;
		*value = (uint16_t)proxy_value;
		break;
	}
	case USDS_UBYTE:
	{
		uint8_t proxy_value;
		readUByte(position, &proxy_value);
		*value = proxy_value;
		break;
	}
	case USDS_INT:
	{
		int32_t proxy_value;
		readInt(position, &proxy_value);
		if (proxy_value > 65535 || proxy_value < 0)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[0, 65535] for type uint16_t. Value in USDS binary: " << *value;
		*value = (uint16_t)proxy_value;
		break;
	}
	case USDS_LONG:
	{
		int64_t proxy_value;
		readLong(position, &proxy_value);
		if (proxy_value > 65535 || proxy_value < 0)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range[0, 65535] for type uint16_t. Value in USDS binary: " << *value;
		*value = (uint16_t)proxy_value;
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from " << usdsTypeName(usds_type) << " to uint16_t";

	}
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
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		int8_t proxy_value;
		readByte(position, &proxy_value);
		*value = proxy_value;
		break;
	}
	case USDS_UBYTE:
	{
		uint8_t proxy_value;
		readUByte(position, &proxy_value);
		*value = proxy_value;
		break;
	}
	case USDS_INT:
	{
		readInt(position, value);
		break;
	}
	case USDS_LONG:
	{
		int64_t proxy_value;
		readLong(position, &proxy_value);
		if (proxy_value > INT32_MAX || proxy_value < INT32_MIN)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [-2147483648, 2147483647] for type int32_t. Value in USDS binary: " << *value;
		*value = (int32_t)proxy_value;
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from " << usdsTypeName(usds_type) << " to int32_t";

	}
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
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		int8_t proxy_value;
		readByte(position, &proxy_value);
		if (proxy_value < 0)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [0, 4294967295] for type uint32_t. Value in USDS binary: " << *value;
		*value = (uint32_t)proxy_value;
		break;
	}
	case USDS_UBYTE:
	{
		uint8_t proxy_value;
		readUByte(position, &proxy_value);
		*value = proxy_value;
		break;
	}
	case USDS_INT:
	{
		int32_t proxy_value;
		readInt(position, &proxy_value);
		if (proxy_value < 0)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [0, 4294967295] for type uint32_t. Value in USDS binary: " << *value;
		*value = (uint32_t)proxy_value;
		break;
	}
	case USDS_LONG:
	{
		int64_t proxy_value;
		readLong(position, &proxy_value);
		if (proxy_value > UINT32_MAX || proxy_value < 0)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [0, 4294967295] for type uint32_t. Value in USDS binary: " << *value;
		*value = (uint32_t)proxy_value;
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from " << usdsTypeName(usds_type) << " to uint32_t";

	}
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
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		int8_t proxy_value;
		readByte(position, &proxy_value);
		*value = proxy_value;
		break;
	}
	case USDS_UBYTE:
	{
		uint8_t proxy_value;
		readUByte(position, &proxy_value);
		*value = proxy_value;
		break;
	}
	case USDS_INT:
	{
		int32_t proxy_value;
		readInt(position, &proxy_value);
		*value = proxy_value;
		break;
	}
	case USDS_LONG:
	{
		readLong(position, value);
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from " << usdsTypeName(usds_type) << " to int64_t";

	}
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
	switch (usds_type)
	{
	case USDS_BYTE:
	{
		int8_t proxy_value;
		readByte(position, &proxy_value);
		if (proxy_value < 0)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [0, (2^64-1)] for type uint64_t. Value in USDS binary: " << *value;
		*value = (uint64_t)proxy_value;
		break;
	}
	case USDS_UBYTE:
	{
		uint8_t proxy_value;
		readUByte(position, &proxy_value);
		*value = proxy_value;
		break;
	}
	case USDS_INT:
	{
		int32_t proxy_value;
		readInt(position, &proxy_value);
		if (proxy_value < 0)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [0, (2^64-1)] for type uint64_t. Value in USDS binary: " << *value;
		*value = (uint64_t)proxy_value;
		break;
	}
	case USDS_LONG:
	{
		int64_t proxy_value;
		readLong(position, &proxy_value);
		if (proxy_value < 0)
			throw ErrorMessage(BIN_OUT__VALUE_CONVERSION) << "Value must be in range [0, (2^64-1)] for type uint64_t. Value in USDS binary: " << *value;
		*value = (uint64_t)proxy_value;
		break;
	}
	default:
		throw ErrorMessage(BIN_OUT__UNSUPPORTED_CONVERSION) << "Unsupported conversion: from " << usdsTypeName(usds_type) << " to int64_t";

	}
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

