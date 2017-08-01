#include "usdsAutotest.h"

#include "binary\usdsBinaryOutput.h"

void BinaryOutputTest::test_1()
{
	usds::BinaryOutput binary(64);

	// step 1
	size_t size = 0;
	if (binary.getBinary() != binary.getBinary(&size))
	{
		throw "Failed at the step 1\n";
	}
	// step 2
	if (size != 0 || binary.getSize()!=0)
	{
		throw "Failed at the step 2\n";
	}
	// step 3
	try
	{
		binary.getBinary(0);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_OUT__NULL_POINTER)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	try
	{
		size = binary.getBufferSize();
		binary.setBufferSize(size + 2000);
		size_t new_size = binary.getBufferSize();
		if ((size + 2000) > new_size)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	}

}

void BinaryOutputTest::test_2()
{
	usds::BinaryOutput binary(64);
	size_t size;
	int32_t varint_size;
	const uint8_t* buff;

	// step 1
	varint_size = binary.writeUVarint(0x8000000000000001ull);
	buff = binary.getBinary(&size);
	if (varint_size!= 10 || size != 10 || buff[0] != 129 || buff[1] != 128 || buff[2] != 128 || buff[3] != 128 || buff[4] != 128 || buff[5] != 128 || buff[6] != 128 || buff[7] != 128 || buff[8] != 128 || buff[9] != 1)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	varint_size = binary.writeUVarint(0xFFFFFFFFu);
	buff = binary.getBinary(&size);
	if (varint_size != 5 || size != 15 || buff[10] != 255 || buff[11] != 255 || buff[12] != 255 || buff[13] != 255 || buff[14] != 15)
	{
		throw "Failed at the step 2\n";
	}

	// step 3
	int32_t value = 0x7FFFFFFF;
	varint_size = binary.writeUVarint(value);
	buff = binary.getBinary(&size);
	if (varint_size != 5 || size != 20 || buff[15] != 255 || buff[16] != 255 || buff[17] != 255 || buff[18] != 255 || buff[19] != 7)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	value = -1;
	try
	{
		varint_size = binary.writeUVarint(value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_OUT__NEGATIVE_VALUE)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	value = -1;
	binary.writeInt(value);
	buff = binary.getBinary(&size);
	if (size != 24 || buff[20] != 255 || buff[21] != 255 || buff[22] != 255 || buff[23] != 255)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	binary.writeLong(-1ll);
	buff = binary.getBinary(&size);
	if (size != 32 || buff[24] != 255 || buff[25] != 255 || buff[26] != 255 || buff[27] != 255 || buff[28] != 255 || buff[29] != 255 || buff[30] != 255 || buff[31] != 255)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	double value_double = -2.0000000000000009;
	binary.writeDouble(value_double);
	buff = binary.getBinary(&size);
	if (size != 40 || buff[32] != 0x02 || buff[33] != 0 || buff[34] != 0 || buff[35] != 0 || buff[36] != 0 || buff[37] != 0 || buff[38] != 0 || buff[39] != 0xC0)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	uint8_t value_uchar = 254;
	binary.writeUByte(value_uchar);
	buff = binary.getBinary(&size);
	if (size != 41 || buff[40] != 0xFE)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	int8_t value_char = -1;
	binary.writeByte(value_char);
	buff = binary.getBinary(&size);
	if (size != 42 || buff[41] != 0xFF)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	binary.writeBoolean(true);
	binary.writeBoolean(false);
	buff = binary.getBinary(&size);
	if (size != 44 || buff[42] != 0xFF || buff[43] != 0)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	binary.writeType(usds::USDS_ARRAY);
	binary.writeSignature(usds::USDS_TAG_SIGNATURE);
	binary.writeEncode(usds::USDS_UTF16LE);
	buff = binary.getBinary(&size);
	if (size != 47 || buff[44] != usds::USDS_ARRAY || buff[45] != usds::USDS_TAG_SIGNATURE || buff[46] != usds::USDS_UTF16LE)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	binary.writeUShort(62000);
	buff = binary.getBinary(&size);
	if (size != 49 || buff[47] != 0x30 || buff[48] != 0xF2)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	binary.writeShort(32000);
	buff = binary.getBinary(&size);
	if (size != 51 || buff[49] != 0 || buff[50] != 0x7D)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	binary.writeUInt(4000000000);
	buff = binary.getBinary(&size);
	if (size != 55 || buff[51] != 0 || buff[52] != 0x28 || buff[53] != 0x6B || buff[54] != 0xEE)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	binary.writeULong(0x8877665544332211);
	buff = binary.getBinary(&size);
	if (size != 63 || buff[55] != 0x11 || buff[56] != 0x22 || buff[57] != 0x33 || buff[58] != 0x44 || buff[59] != 0x55 || buff[60] != 0x66 || buff[61] != 0x77 || buff[62] != 0x88)
	{
		throw "Failed at the step 14\n";
	}

}

void BinaryOutputTest::test_3()
{
	usds::BinaryOutput binary(64);
	const uint8_t* buff;
	size_t size = 0;

	// step 1
	uint8_t buff_1[] = { 0, 1, 2, 3 };
	binary.writeByteArray(buff_1, 4);
	buff = binary.getBinary(&size);
	if (size != 4 || buff[0] != 0 || buff[1] != 1 || buff[2] != 2 || buff[3] != 3)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	binary.pushFrontSize();
	buff = binary.getBinary(&size);
	if (size != 5 || buff[0] != 4)
	{
		throw "Failed at the step 1\n";
	}

	// step 3
	uint8_t buff_2[1000];
	binary.writeByteArray(buff_2, 1000);
	buff = binary.getBinary(&size);
	if (size != 1005 || buff[0] != 4)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	binary.pushFrontSize();
	buff = binary.getBinary(&size);
	if (size != 1007 || buff[0] != 237 || buff[1] != 7)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	binary.pushFrontUByte(240);
	buff = binary.getBinary(&size);
	if (size != 1008 || buff[0] != 240 || buff[1] != 237)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	binary.pushFrontUInt(4278255360);
	buff = binary.getBinary(&size);
	if (size != 1012 || buff[0] != 0 || buff[1] != 255 || buff[2] != 0 || buff[3] != 255)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	binary.pushFrontSignature(usds::USDS_MAJOR_SIGNATURE);
	buff = binary.getBinary(&size);
	if (size != 1013 || buff[0] != 36)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	uint8_t buff_read[4];
	binary.readByteArray(9, buff_read, 4);
	if (buff_read[0] != 0 || buff_read[1] != 1 || buff_read[2] != 2 || buff_read[3] != 3)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	binary.clear();
	buff = binary.getBinary(&size);
	if (size != 0 || binary.getSize() != 0)
	{
		throw "Failed at the step 9\n";
	}

}

void BinaryOutputTest::test_4()
{
	usds::BinaryOutput* binary = new usds::BinaryOutput(64);

	// step 1
	try
	{
		binary->writeByteArray(0, 4);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_OUT__NULL_POINTER)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	try
	{
		binary->readByteArray(0, 0, 4);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_OUT__NULL_POINTER)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	try
	{
		uint8_t buff[1000];
		uint8_t buff_out[1001];
		binary->writeByteArray(buff, 1000);
		binary->readByteArray(0, buff_out, 1001);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_OUT__BUFFER_OVERFLOW)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	try
	{
		uint8_t buff[1000];
#ifdef _WIN64
		binary->writeByteArray(buff, 0xFFFFFFFFFFFFFFFF);
#else
		binary->writeByteArray(buff, 0xFFFFFFFF);
#endif
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_OUT__BUFFER_OVERFLOW)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	try
	{
		uint8_t buff[1000];
#ifdef _WIN64
		binary->writeByteArray(buff, 0xFFFFFFFFFFFF0000);
#else
		binary->writeByteArray(buff, 0xFFFF0000);
#endif
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_OUT__ALLOCATE_ERROR)
		{
			throw "Failed at the step 5\n";
		}
	}

	delete binary;
}

void BinaryOutputTest::test_5()
{
	usds::BinaryOutput binary(64);

	// step 1
	try
	{
		binary.write(usds::USDS_BOOLEAN, true);
		if (binary.getBinary()[0] != 255)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 3
	bool value = false;
	try
	{
		binary.read(0, usds::USDS_BOOLEAN, &value);
		if (value != true)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	try
	{
		binary.write(usds::USDS_INT, true);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
			throw "Failed at the step 4\n";
	}

	// step 5
	try
	{
		binary.read(0, usds::USDS_INT, &value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
			throw "Failed at the step 5\n";
	}

}

void BinaryOutputTest::test_6()
{
	usds::BinaryOutput binary(64);

	// step 1
	int8_t value = 120;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		if (binary.getBinary()[0] != 120)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		if (binary.getBinary()[1] != 120)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	}

	// step 3
	value = -1;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 3\n";
	}

	// step 4
	try
	{
		binary.write(usds::USDS_INT, value);
		if (binary.getBinary()[2] != 255 || binary.getBinary()[3] != 255 || binary.getBinary()[4] != 255 || binary.getBinary()[5] != 255)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	value = 120;
	try
	{
		binary.write(usds::USDS_LONG, value);
		if (binary.getBinary()[6] != 120 || binary.getBinary()[7] != 0 || binary.getBinary()[8] != 0 || binary.getBinary()[9] != 0
			|| binary.getBinary()[10] != 0 || binary.getBinary()[11] != 0 || binary.getBinary()[12] != 0 || binary.getBinary()[13] != 0)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	}

	// step 9
	value = 0;
	try
	{
		binary.read(1, usds::USDS_BYTE, &value);
		if (value != 120)
			throw "Failed at the step 9\n";
	}
	catch (...)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	value = 0;
	try
	{
		binary.read(2, usds::USDS_UBYTE, &value);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 10\n";
	}

	// step 11
	value = 0;
	try
	{
		binary.read(2, usds::USDS_INT, &value);
		if (value != -1)
			throw "Failed at the step 11\n";
	}
	catch (...)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	value = 0;
	try
	{
		binary.read(0, usds::USDS_INT, &value);
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 12\n";
	}

	// step 13
	value = 0;
	try
	{
		binary.read(4, usds::USDS_INT, &value);
		throw "Failed at the step 13\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 13\n";
	}

	// step 14
	value = 0;
	try
	{
		binary.read(6, usds::USDS_LONG, &value);
		if (value != 120)
			throw "Failed at the step 14\n";
	}
	catch (...)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	value = 0;
	try
	{
		binary.read(0, usds::USDS_LONG, &value);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 15\n";
	}

	// step 16
	value = 0;
	try
	{
		binary.read(4, usds::USDS_LONG, &value);
		throw "Failed at the step 16\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 16\n";
	}

}


void BinaryOutputTest::test_7()
{
	usds::BinaryOutput binary(64);

	// step 1
	int16_t value = 120;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		if (binary.getBinary()[0] != 120)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	value = 200;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 2\n";
	}

	// step 3
	value = -200;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 3\n";
	}

	// step 4
	value = 200;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		if (binary.getBinary()[1] != 200)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	value = 400;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 5\n";
	}

	// step 6
	value = -1;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 6\n";
	}

	// step 7
	value = 10000;
	try
	{
		binary.write(usds::USDS_INT, value);
		if (binary.getBinary()[2] != 0x10 || binary.getBinary()[3] != 0x27 || binary.getBinary()[4] != 0 || binary.getBinary()[5] != 0)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	value = -3;
	try
	{
		binary.write(usds::USDS_LONG, value);
		if (binary.getBinary()[6] != 253 || binary.getBinary()[7] != 255 || binary.getBinary()[8] != 255 || binary.getBinary()[9] != 255 ||
			binary.getBinary()[10] != 255 || binary.getBinary()[11] != 255 || binary.getBinary()[12] != 255 || binary.getBinary()[13] != 255)
			throw "Failed at the step 8\n";
	}
	catch (...)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	value = 0;
	try
	{
		binary.read(0, usds::USDS_BYTE, &value);
		if (value != 120)
			throw "Failed at the step 9\n";
	}
	catch (...)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	value = 0;
	try
	{
		binary.read(1, usds::USDS_UBYTE, &value);
		if (value != 200)
			throw "Failed at the step 10\n";
	}
	catch (...)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	value = 0;
	try
	{
		binary.read(2, usds::USDS_INT, &value);
		if (value != 10000)
			throw "Failed at the step 11\n";
	}
	catch (...)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	value = 0;
	try
	{
		binary.read(0, usds::USDS_INT, &value);
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 12\n";
	}

	// step 13
	value = 0;
	try
	{
		binary.read(1, usds::USDS_INT, &value);
		throw "Failed at the step 13\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 13\n";
	}

	// step 14
	value = 0;
	try
	{
		binary.read(6, usds::USDS_LONG, &value);
		if (value != -3)
			throw "Failed at the step 14\n";
	}
	catch (...)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	value = 0;
	try
	{
		binary.read(0, usds::USDS_LONG, &value);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 15\n";
	}

	// step 16
	value = 0;
	try
	{
		binary.read(1, usds::USDS_LONG, &value);
		throw "Failed at the step 16\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 16\n";
	}
}

void BinaryOutputTest::test_8()
{
	usds::BinaryOutput binary(64);

	// step 1
	int32_t value = 120;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		if (binary.getBinary()[0] != 120)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	value = 200;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 2\n";
	}

	// step 3
	value = -200;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 3\n";
	}

	// step 4
	value = 200;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		if (binary.getBinary()[1] != 200)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	value = 400;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 5\n";
	}

	// step 6
	value = -1;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 6\n";
	}

	// step 7
	value = 1000000000;
	try
	{
		binary.write(usds::USDS_INT, value);
		if (binary.getBinary()[2] != 0 || binary.getBinary()[3] != 0xCA || binary.getBinary()[4] != 0x9A || binary.getBinary()[5] != 0x3B)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	value = -3;
	try
	{
		binary.write(usds::USDS_LONG, value);
		if (binary.getBinary()[6] != 253 || binary.getBinary()[7] != 255 || binary.getBinary()[8] != 255 || binary.getBinary()[9] != 255 ||
			binary.getBinary()[10] != 255 || binary.getBinary()[11] != 255 || binary.getBinary()[12] != 255 || binary.getBinary()[13] != 255)
			throw "Failed at the step 8\n";
	}
	catch (...)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	value = 0;
	try
	{
		binary.read(0, usds::USDS_BYTE, &value);
		if (value != 120)
			throw "Failed at the step 9\n";
	}
	catch (...)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	value = 0;
	try
	{
		binary.read(1, usds::USDS_UBYTE, &value);
		if (value != 200)
			throw "Failed at the step 10\n";
	}
	catch (...)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	value = 0;
	try
	{
		binary.read(2, usds::USDS_INT, &value);
		if (value != 1000000000)
			throw "Failed at the step 11\n";
	}
	catch (...)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	value = 0;
	try
	{
		binary.read(6, usds::USDS_LONG, &value);
		if (value != -3)
			throw "Failed at the step 12\n";
	}
	catch (...)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	value = 0;
	try
	{
		binary.read(0, usds::USDS_LONG, &value);
		throw "Failed at the step 13\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 13\n";
	}

	// step 14
	value = 0;
	try
	{
		binary.read(1, usds::USDS_LONG, &value);
		throw "Failed at the step 14\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 14\n";
	}

}


void BinaryOutputTest::test_9()
{
	usds::BinaryOutput binary(64);

	// step 1
	int64_t value = 120;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		if (binary.getBinary()[0] != 120)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	value = 200;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 2\n";
	}

	// step 3
	value = -200;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 3\n";
	}

	// step 4
	value = 200;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		if (binary.getBinary()[1] != 200)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	value = 400;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 5\n";
	}

	// step 6
	value = -1;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 6\n";
	}

	// step 7
	value = 1000000000;
	try
	{
		binary.write(usds::USDS_INT, value);
		if (binary.getBinary()[2] != 0 || binary.getBinary()[3] != 0xCA || binary.getBinary()[4] != 0x9A || binary.getBinary()[5] != 0x3B)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	}

	// step 7.1
	value = 10000000000;
	try
	{
		binary.write(usds::USDS_INT, value);
		throw "Failed at the step 7.1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 7.1\n";
	}

	// step 7.2
	value = -10000000000;
	try
	{
		binary.write(usds::USDS_INT, value);
		throw "Failed at the step 7.2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 7.2\n";
	}

	// step 8
	value = -3;
	try
	{
		binary.write(usds::USDS_LONG, value);
		if (binary.getBinary()[6] != 253 || binary.getBinary()[7] != 255 || binary.getBinary()[8] != 255 || binary.getBinary()[9] != 255 ||
			binary.getBinary()[10] != 255 || binary.getBinary()[11] != 255 || binary.getBinary()[12] != 255 || binary.getBinary()[13] != 255)
			throw "Failed at the step 8\n";
	}
	catch (...)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	value = 0;
	try
	{
		binary.read(0, usds::USDS_BYTE, &value);
		if (value != 120)
			throw "Failed at the step 9\n";
	}
	catch (...)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	value = 0;
	try
	{
		binary.read(1, usds::USDS_UBYTE, &value);
		if (value != 200)
			throw "Failed at the step 10\n";
	}
	catch (...)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	value = 0;
	try
	{
		binary.read(2, usds::USDS_INT, &value);
		if (value != 1000000000)
			throw "Failed at the step 11\n";
	}
	catch (...)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	value = 0;
	try
	{
		binary.read(6, usds::USDS_LONG, &value);
		if (value != -3)
			throw "Failed at the step 12\n";
	}
	catch (...)
	{
		throw "Failed at the step 12\n";
	}

}

void BinaryOutputTest::test_10()
{
	usds::BinaryOutput binary(0);

	// step 1
	uint8_t value = 120;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		if (binary.getBinary()[0] != 120)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}
	
	// step 2
	value = 200;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 2\n";
	}
	
	// step 3
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		if (binary.getBinary()[1] != 200)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}


	// step 4
	try
	{
		binary.write(usds::USDS_INT, value);
		if (binary.getBinary()[2] != 200 || binary.getBinary()[3] != 0 || binary.getBinary()[4] != 0 || binary.getBinary()[5] != 0)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	try
	{
		binary.write(usds::USDS_LONG, value);
		if (binary.getBinary()[6] != 200 || binary.getBinary()[7] != 0 || binary.getBinary()[8] != 0 || binary.getBinary()[9] != 0
			|| binary.getBinary()[10] != 0 || binary.getBinary()[11] != 0 || binary.getBinary()[12] != 0 || binary.getBinary()[13] != 0)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	value = 0;
	try
	{
		binary.read(0, usds::USDS_BYTE, &value);
		if (value != 120)
			throw "Failed at the step 6\n";
	}
	catch (...)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	value = 0;
	try
	{
		binary.read(1, usds::USDS_BYTE, &value);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 7\n";
	}

	// step 8
	value = 0;
	try
	{
		binary.read(1, usds::USDS_UBYTE, &value);
		if (value != 200)
			throw "Failed at the step 8\n";
	}
	catch (...)
	{
		throw "Failed at the step 8\n";
	}

	// step 11
	value = 0;
	try
	{
		binary.read(2, usds::USDS_INT, &value);
		if (value != 200)
			throw "Failed at the step 11\n";
	}
	catch (...)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	value = 0;
	try
	{
		binary.read(0, usds::USDS_INT, &value);
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 12\n";
	}

	// step 13
	value = 0;
	try
	{
		binary.write(usds::USDS_UBYTE, 255);
		binary.write(usds::USDS_UBYTE, 255);
		binary.read(1, usds::USDS_INT, &value);
		throw "Failed at the step 13\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 13\n";
	}

	// step 14
	value = 0;
	try
	{
		binary.read(6, usds::USDS_LONG, &value);
		if (value != 200)
			throw "Failed at the step 14\n";
	}
	catch (...)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	value = 0;
	try
	{
		binary.read(0, usds::USDS_LONG, &value);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 15\n";
	}

	// step 16
	value = 0;
	try
	{
		binary.read(8, usds::USDS_LONG, &value);
		throw "Failed at the step 16\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 16\n";
	}


};


void BinaryOutputTest::test_11()
{
	usds::BinaryOutput binary(64);

	// step 1
	uint16_t value = 120;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		if (binary.getBinary()[0] != 120)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	value = 200;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 2\n";
	}

	// step 3
	value = 200;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		if (binary.getBinary()[1] != 200)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	value = 400;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 4\n";
	}

	// step 5
	value = 10000;
	try
	{
		binary.write(usds::USDS_INT, value);
		if (binary.getBinary()[2] != 0x10 || binary.getBinary()[3] != 0x27 || binary.getBinary()[4] != 0 || binary.getBinary()[5] != 0)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	value = 20000;
	try
	{
		binary.write(usds::USDS_LONG, value);
		if (binary.getBinary()[6] != 0x20 || binary.getBinary()[7] != 0x4E || binary.getBinary()[8] != 0 || binary.getBinary()[9] != 0 ||
			binary.getBinary()[10] != 0 || binary.getBinary()[11] != 0 || binary.getBinary()[12] != 0 || binary.getBinary()[13] != 0)
			throw "Failed at the step 6\n";
	}
	catch (...)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	value = 0;
	try
	{
		binary.read(0, usds::USDS_BYTE, &value);
		if (value != 120)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	value = 0;
	try
	{
		binary.read(1, usds::USDS_BYTE, &value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 8\n";
	}

	// step 9
	value = 0;
	try
	{
		binary.read(1, usds::USDS_UBYTE, &value);
		if (value != 200)
			throw "Failed at the step 9\n";
	}
	catch (...)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	value = 0;
	try
	{
		binary.read(2, usds::USDS_INT, &value);
		if (value != 10000)
			throw "Failed at the step 10\n";
	}
	catch (...)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	value = 0;
	try
	{
		binary.read(0, usds::USDS_INT, &value);
		throw "Failed at the step 11\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 11\n";
	}

	// step 12
	value = 0;
	try
	{
		binary.read(1, usds::USDS_INT, &value);
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 12\n";
	}

	// step 13
	value = 0;
	try
	{
		binary.read(6, usds::USDS_LONG, &value);
		if (value != 20000)
			throw "Failed at the step 13\n";
	}
	catch (...)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	value = 0;
	try
	{
		binary.read(0, usds::USDS_LONG, &value);
		throw "Failed at the step 14\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 14\n";
	}

	// step 15
	value = 0;
	try
	{
		binary.read(1, usds::USDS_LONG, &value);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 15\n";
	}

}

void BinaryOutputTest::test_12()
{
	usds::BinaryOutput binary(64);

	// step 1
	uint32_t value = 120;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		if (binary.getBinary()[0] != 120)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	value = 200;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 2\n";
	}

	// step 3
	value = 200;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		if (binary.getBinary()[1] != 200)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	value = 400;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 4\n";
	}

	// step 5
	value = 1000000000;
	try
	{
		binary.write(usds::USDS_INT, value);
		if (binary.getBinary()[2] != 0 || binary.getBinary()[3] != 0xCA || binary.getBinary()[4] != 0x9A || binary.getBinary()[5] != 0x3B)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	value = 4000000000;
	try
	{
		binary.write(usds::USDS_INT, value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 6\n";
	}

	// step 8
	value = 4000000000;
	try
	{
		binary.write(usds::USDS_LONG, value);
		if (binary.getBinary()[6] != 0 || binary.getBinary()[7] != 0x28 || binary.getBinary()[8] != 0x6B || binary.getBinary()[9] != 0xEE ||
			binary.getBinary()[10] != 0 || binary.getBinary()[11] != 0 || binary.getBinary()[12] != 0 || binary.getBinary()[13] != 0)
			throw "Failed at the step 8\n";
	}
	catch (...)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	value = 0;
	try
	{
		binary.read(0, usds::USDS_BYTE, &value);
		if (value != 120)
			throw "Failed at the step 9\n";
	}
	catch (...)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	value = 0;
	try
	{
		binary.read(1, usds::USDS_BYTE, &value);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 10\n";
	}

	// step 11
	value = 0;
	try
	{
		binary.read(1, usds::USDS_UBYTE, &value);
		if (value != 200)
			throw "Failed at the step 11\n";
	}
	catch (...)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	value = 0;
	try
	{
		binary.read(2, usds::USDS_INT, &value);
		if (value != 1000000000)
			throw "Failed at the step 12\n";
	}
	catch (...)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	value = 0;
	try
	{
		binary.write(usds::USDS_UBYTE, 255);
		binary.read(11, usds::USDS_INT, &value);
		throw "Failed at the step 13\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 13\n";
	}

	// step 14
	value = 0;
	try
	{
		binary.read(6, usds::USDS_LONG, &value);
		if (value != 4000000000)
			throw "Failed at the step 14\n";
	}
	catch (...)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	value = 0;
	try
	{
		binary.read(0, usds::USDS_LONG, &value);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 15\n";
	}

	// step 16
	value = 0;
	try
	{
		binary.read(7, usds::USDS_LONG, &value);
		throw "Failed at the step 16\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 16\n";
	}

};

void BinaryOutputTest::test_13()
{
	usds::BinaryOutput binary(64);

	// step 1
	uint64_t value = 120;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		if (binary.getBinary()[0] != 120)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	value = 200;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 2\n";
	}

	// step 3
	value = 200;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		if (binary.getBinary()[1] != 200)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	value = 400;
	try
	{
		binary.write(usds::USDS_UBYTE, value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 4\n";
	}

	// step 5
	value = 1000000000;
	try
	{
		binary.write(usds::USDS_INT, value);
		if (binary.getBinary()[2] != 0 || binary.getBinary()[3] != 0xCA || binary.getBinary()[4] != 0x9A || binary.getBinary()[5] != 0x3B)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	value = 10000000000;
	try
	{
		binary.write(usds::USDS_INT, value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 6\n";
	}

	// step 7
	value = 10000000000;
	try
	{
		binary.write(usds::USDS_LONG, value);
		if (binary.getBinary()[6] != 0 || binary.getBinary()[7] != 0xE4 || binary.getBinary()[8] != 0x0B || binary.getBinary()[9] != 0x54 ||
			binary.getBinary()[10] != 0x2 || binary.getBinary()[11] != 0 || binary.getBinary()[12] != 0 || binary.getBinary()[13] != 0)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	value = UINT64_MAX;
	try
	{
		binary.write(usds::USDS_LONG, value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 8\n";
	}

	// step 9
	value = 0;
	try
	{
		binary.read(0, usds::USDS_BYTE, &value);
		if (value != 120)
			throw "Failed at the step 9\n";
	}
	catch (...)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	value = 0;
	try
	{
		binary.read(1, usds::USDS_BYTE, &value);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 10\n";
	}

	// step 11
	value = 0;
	try
	{
		binary.read(1, usds::USDS_UBYTE, &value);
		if (value != 200)
			throw "Failed at the step 11\n";
	}
	catch (...)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	value = 0;
	try
	{
		binary.read(2, usds::USDS_INT, &value);
		if (value != 1000000000)
			throw "Failed at the step 12\n";
	}
	catch (...)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	value = 0;
	try
	{
		binary.write(usds::USDS_UBYTE, 255);
		binary.read(11, usds::USDS_INT, &value);
		throw "Failed at the step 13\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 13\n";
	}

	// step 14
	value = 0;
	try
	{
		binary.read(6, usds::USDS_LONG, &value);
		if (value != 10000000000)
			throw "Failed at the step 14\n";
	}
	catch (...)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	value = 0;
	try
	{
		binary.read(7, usds::USDS_LONG, &value);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			throw "Failed at the step 15\n";
	}

};

void BinaryOutputTest::test_14()
{
	usds::BinaryOutput binary(64);

	// step 1
	float value = 0.25F;
	try
	{
		binary.writeFloat(value);
		if (binary.getBinary()[0] != 0 || binary.getBinary()[1] != 0 || binary.getBinary()[2] != 0x80 || binary.getBinary()[3] != 0x3E)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	value = 0.125F;
	try
	{
		binary.write(usds::USDS_FLOAT, value);
		if (binary.getBinary()[4] != 0 || binary.getBinary()[5] != 0 || binary.getBinary()[6] != 0 || binary.getBinary()[7] != 0x3E)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	}

	// step 3
	value = 0.125F;
	try
	{
		binary.write(usds::USDS_DOUBLE, value);
		if (binary.getBinary()[8] != 0 || binary.getBinary()[9] != 0 || binary.getBinary()[10] != 0 || binary.getBinary()[11] != 0 ||
			binary.getBinary()[12] != 0 || binary.getBinary()[13] != 0 || binary.getBinary()[14] != 0xC0 || binary.getBinary()[15] != 0x3F)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	value = 200;
	try
	{
		binary.write(usds::USDS_BYTE, value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
			throw "Failed at the step 4\n";
	}

	// step 7
	value = 0;
	try
	{
		binary.read(0, usds::USDS_FLOAT, &value);
		if (value != 0.25F)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		binary.read(0, usds::USDS_DOUBLE, &value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
			throw "Failed at the step 8\n";
	}

}

void BinaryOutputTest::test_15()
{
	usds::BinaryOutput binary(64);

	// step 1
	double value = 0.25;
	try
	{
		binary.write(usds::USDS_DOUBLE, value);
		if (binary.getBinary()[0] != 0 || binary.getBinary()[1] != 0 || binary.getBinary()[2] != 0 || binary.getBinary()[3] != 0 ||
			binary.getBinary()[4] != 0 || binary.getBinary()[5] != 0 || binary.getBinary()[6] != 0xD0 || binary.getBinary()[7] != 0x3F)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	try
	{
		binary.write(usds::USDS_FLOAT, value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
			throw "Failed at the step 2\n";
	}

	// step 5
	value = 0;
	try
	{
		binary.read(4, usds::USDS_FLOAT, &value);
		if (value != 1.625)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	value = 0;
	try
	{
		binary.read(0, usds::USDS_DOUBLE, &value);
		if (value != 0.25)
			throw "Failed at the step 6\n";
	}
	catch (...)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	try
	{
		binary.read(0, usds::USDS_LONG, &value);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
			throw "Failed at the step 7\n";
	}
}

void BinaryOutputTest::test_16()
{
	usds::BinaryOutput binary(64);

	// step 1
	int32_t value = 888;
	try
	{
		binary.writePointer(&value);
		if (binary.getSize() != sizeof(int32_t*))
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	int32_t* out_value;
	try
	{
		binary.readPointer(0, (void**)(&out_value));
		if (out_value != &value || *out_value != 888)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	}
}

void BinaryOutputTest::test_17()
{
	usds::BinaryOutput binary(64);

	// step 1
	int64_t value = 1;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 1 || binary.getSize() != 1 || binary.getBinary()[0] != 2)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	binary.clear();
	value = -1;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 1 || binary.getSize() != 1 || binary.getBinary()[0] != 3)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	}

	// step 3
	binary.clear();
	value = 63;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 1 || binary.getSize() != 1 || binary.getBinary()[0] != 126)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	binary.clear();
	value = -63;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 1 || binary.getSize() != 1 || binary.getBinary()[0] != 127)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	binary.clear();
	value = 0;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 1 || binary.getSize() != 1 || binary.getBinary()[0] != 0)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	binary.clear();
	value = 64;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 2 || binary.getSize() != 2 || binary.getBinary()[0] != 128 || binary.getBinary()[1] != 1)
			throw "Failed at the step 6\n";
	}
	catch (...)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	binary.clear();
	value = -64;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 2 || binary.getSize() != 2 || binary.getBinary()[0] != 129 || binary.getBinary()[1] != 1)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	binary.clear();
	value = 8191;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 2 || binary.getSize() != 2 || binary.getBinary()[0] != 254 || binary.getBinary()[1] != 127)
			throw "Failed at the step 8\n";
	}
	catch (...)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	binary.clear();
	value = -8191;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 2 || binary.getSize() != 2 || binary.getBinary()[0] != 255 || binary.getBinary()[1] != 127)
			throw "Failed at the step 9\n";
	}
	catch (...)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	binary.clear();
	value = 8192;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 3 || binary.getSize() != 3 || binary.getBinary()[0] != 128 || binary.getBinary()[1] != 128 || binary.getBinary()[2] != 1)
			throw "Failed at the step 10\n";
	}
	catch (...)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	binary.clear();
	value = -8192;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 3 || binary.getSize() != 3 || binary.getBinary()[0] != 129 || binary.getBinary()[1] != 128 || binary.getBinary()[2] != 1)
			throw "Failed at the step 10\n";
	}
	catch (...)
	{
		throw "Failed at the step 10\n";
	}

	// step 12
	binary.clear();
	value = 1048575;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 3 || binary.getSize() != 3 || binary.getBinary()[0] != 254 || binary.getBinary()[1] != 255 || binary.getBinary()[2] != 127)
			throw "Failed at the step 12\n";
	}
	catch (...)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	binary.clear();
	value = -1048575;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 3 || binary.getSize() != 3 || binary.getBinary()[0] != 255 || binary.getBinary()[1] != 255 || binary.getBinary()[2] != 127)
			throw "Failed at the step 13\n";
	}
	catch (...)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	binary.clear();
	value = INT64_MAX;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 10 || binary.getSize() != 10 || 
			binary.getBinary()[0] != 254 || binary.getBinary()[1] != 255 || binary.getBinary()[2] != 255 || binary.getBinary()[3] != 255 ||
			binary.getBinary()[4] != 255 || binary.getBinary()[5] != 255 || binary.getBinary()[6] != 255 || binary.getBinary()[7] != 255 ||
			binary.getBinary()[8] != 255 || binary.getBinary()[9] != 1)
			throw "Failed at the step 14\n";
	}
	catch (...)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	binary.clear();
	value = INT64_MIN + 1;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 10 || binary.getSize() != 10 ||
			binary.getBinary()[0] != 255 || binary.getBinary()[1] != 255 || binary.getBinary()[2] != 255 || binary.getBinary()[3] != 255 ||
			binary.getBinary()[4] != 255 || binary.getBinary()[5] != 255 || binary.getBinary()[6] != 255 || binary.getBinary()[7] != 255 ||
			binary.getBinary()[8] != 255 || binary.getBinary()[9] != 1)
			throw "Failed at the step 15\n";
	}
	catch (...)
	{
		throw "Failed at the step 15\n";
	}

	// step 16
	binary.clear();
	value = INT64_MIN;
	try
	{
		size_t size = binary.writeVarint(value);
		if (size != 10 || binary.getSize() != 10 ||
			binary.getBinary()[0] != 129 || binary.getBinary()[1] != 128 || binary.getBinary()[2] != 128 || binary.getBinary()[3] != 128 ||
			binary.getBinary()[4] != 128 || binary.getBinary()[5] != 128 || binary.getBinary()[6] != 128 || binary.getBinary()[7] != 128 ||
			binary.getBinary()[8] != 128 || binary.getBinary()[9] != 2)
			throw "Failed at the step 16\n";
	}
	catch (...)
	{
		throw "Failed at the step 16\n";
	}


}

