#include "usdsAutotest.h"

#include "usdsBinaryOutput.h"

void BinaryOutputTest::test_1()
{
	usds::BinaryOutput binary;

	// step 1
	size_t size = 0;
	if (binary.getBinary() != binary.getBinary(&size))
	{
		throw "Failed at the step 1\n";
	}
	// step 2
	if (size != 0 || binary.getSize()!=0 || !binary.isEmpty())
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

}

void BinaryOutputTest::test_2()
{
	usds::BinaryOutput binary;
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
	binary.writeBool(true);
	binary.writeBool(false);
	buff = binary.getBinary(&size);
	if (size != 44 || buff[42] != 0xFF || buff[43] != 0)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	binary.writeType(usds::USDS_ARRAY);
	binary.writeSignature(usds::USDS_TAG_SIGNATURE);
	buff = binary.getBinary(&size);
	if (size != 46 || buff[44] != usds::USDS_ARRAY || buff[45] != usds::USDS_TAG_SIGNATURE)
	{
		throw "Failed at the step 11\n";
	}

}

void BinaryOutputTest::test_3()
{
	usds::BinaryOutput binary;
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
	binary.pushFrontInt(-1);
	buff = binary.getBinary(&size);
	if (size != 1012 || buff[0] != 255 || buff[1] != 255 || buff[2] != 255 || buff[3] != 255)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	uint8_t buff_read[4];
	binary.readByteArray(8, buff_read, 4);
	if (buff_read[0] != 0 || buff_read[1] != 1 || buff_read[2] != 2 || buff_read[3] != 3)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	binary.clear();
	buff = binary.getBinary(&size);
	if (size != 0 || !binary.isEmpty())
	{
		throw "Failed at the step 8\n";
	}

}

void BinaryOutputTest::test_4()
{
	usds::BinaryOutput* binary = new usds::BinaryOutput();

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