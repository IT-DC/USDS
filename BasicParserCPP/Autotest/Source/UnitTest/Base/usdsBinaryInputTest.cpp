#include "usdsAutotest.h"

#include "binary\usdsBinaryInput.h"
#include "binary\usdsBinaryOutput.h"

void BinaryInputTest::test_1()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.setBinary(0, 1);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_BUFF)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	try
	{
		uint8_t buff;
		binary.setBinary(&buff, 0);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_SIZE)
		{
			throw "Failed at the step 2\n";
		}
	}
};

void BinaryInputTest::test_2()
{
	usds::BinaryInput binary;
	uint64_t value = 0;
	int32_t size = 0;

	// step 1
	try
	{
		size = binary.readUVarint(&value);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// Step 2
	uint8_t buff_1[] = { 255, 0 };
	binary.setBinary(buff_1, 2);
	try
	{
		size = binary.readUVarint(&value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__UVARINT_ERROR_FORMAT)
		{
			throw "Failed at the step 2\n";
		}
	}

	// Step 3
	uint8_t buff_2[] = { 128, 128, 128, 128, 128, 128, 128, 128, 128, 2 };
	binary.setBinary(buff_2, 10);
	try
	{
		size = binary.readUVarint(&value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BEEG_UVARINT)
		{
			throw "Failed at the step 3\n";
		}
	}

	// Step 4
	uint8_t buff_3[] = { 128, 128 };
	binary.setBinary(buff_3, 2);
	try
	{
		size = binary.readUVarint(&value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 4\n";
		}
	}

	// Step 5
	uint8_t buff_4[] = { 1, 0 };
	binary.setBinary(buff_4, 2);
	size = binary.readUVarint(&value);

	if (size != 1 || value != 1)
	{
		throw "Failed at the step 5\n";
	}

	// Step 6
	uint8_t buff_5[] = { 128, 1 };
	binary.setBinary(buff_5, 2);
	size = binary.readUVarint(&value);

	if (size != 2 || value != 128)
	{
		throw "Failed at the step 6\n";
	}

	// Step 7
	uint8_t buff_6[] = { 129, 128, 128, 128, 128, 128, 128, 128, 128, 1 };
	binary.setBinary(buff_6, 10);
	size = binary.readUVarint(&value);
	if (size != 10 || value != 0x8000000000000001ull)
	{
		throw "Failed at the step 7\n";
	}

	// Step 8
	uint8_t buff_7[] = { 255, 255, 255, 255, 255, 255, 255, 255, 255, 1 };
	binary.setBinary(buff_7, 10);
	size = binary.readUVarint(&value);
	if (size != 10 || value != 0xFFFFFFFFFFFFFFFFull)
	{
		throw "Failed at the step 8\n";
	}

};

void BinaryInputTest::test_3()
{
	usds::BinaryInput binary;
	uint32_t value = 0;
	int32_t size = 0;

	// step 1
	try
	{
		size = binary.readUVarint(&value);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// Step 2
	uint8_t buff_1[] = { 255, 0 };
	binary.setBinary(buff_1, 2);
	try
	{
		size = binary.readUVarint(&value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__UVARINT_ERROR_FORMAT)
		{
			throw "Failed at the step 2\n";
		}
	}

	// Step 3
	uint8_t buff_2[] = { 128, 128, 128, 128, 16};
	binary.setBinary(buff_2, 5);
	try
	{
		size = binary.readUVarint(&value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BEEG_UVARINT)
		{
			throw "Failed at the step 3\n";
		}
	}

	// Step 4
	uint8_t buff_3[] = { 128, 128 };
	binary.setBinary(buff_3, 2);
	try
	{
		size = binary.readUVarint(&value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 4\n";
		}
	}

	// Step 5
	uint8_t buff_4[] = { 1, 0 };
	binary.setBinary(buff_4, 2);
	size = binary.readUVarint(&value);

	if (size != 1 || value != 1)
	{
		throw "Failed at the step 5\n";
	}

	// Step 6
	uint8_t buff_5[] = { 128, 1 };
	binary.setBinary(buff_5, 2);
	size = binary.readUVarint(&value);

	if (size != 2 || value != 128)
	{
		throw "Failed at the step 6\n";
	}

	// Step 7
	uint8_t buff_6[] = { 129, 128, 128, 128, 15 };
	binary.setBinary(buff_6, 5);
	size = binary.readUVarint(&value);
	if (size != 5 || value != 0xF0000001u)
	{
		throw "Failed at the step 7\n";
	}

	// Step 8
	uint8_t buff_7[] = { 255, 255, 255, 255, 15};
	binary.setBinary(buff_7, 5);
	size = binary.readUVarint(&value);
	if (size != 5 || value != 0xFFFFFFFFu)
	{
		throw "Failed at the step 8\n";
	}

};

void BinaryInputTest::test_4()
{
	usds::BinaryInput binary;
	int32_t value = 0;
	int32_t size = 0;

	// step 1
	try
	{
		size = binary.readUVarint(&value);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// Step 2
	uint8_t buff_1[] = { 255, 0 };
	binary.setBinary(buff_1, 2);
	try
	{
		size = binary.readUVarint(&value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__UVARINT_ERROR_FORMAT)
		{
			throw "Failed at the step 2\n";
		}
	}

	// Step 3
	uint8_t buff_2[] = { 128, 128, 128, 128, 8 };
	binary.setBinary(buff_2, 5);
	try
	{
		size = binary.readUVarint(&value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BEEG_UVARINT)
		{
			throw "Failed at the step 3\n";
		}
	}

	// Step 4
	uint8_t buff_3[] = { 128, 128 };
	binary.setBinary(buff_3, 2);
	try
	{
		size = binary.readUVarint(&value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 4\n";
		}
	}

	// Step 5
	uint8_t buff_4[] = { 1, 0 };
	binary.setBinary(buff_4, 2);
	size = binary.readUVarint(&value);

	if (size != 1 || value != 1)
	{
		throw "Failed at the step 5\n";
	}

	// Step 6
	uint8_t buff_5[] = { 128, 1 };
	binary.setBinary(buff_5, 2);
	size = binary.readUVarint(&value);

	if (size != 2 || value != 128)
	{
		throw "Failed at the step 6\n";
	}

	// Step 7
	uint8_t buff_6[] = { 129, 128, 128, 128, 7 };
	binary.setBinary(buff_6, 5);
	size = binary.readUVarint(&value);
	if (size != 5 || value != 0x70000001)
	{
		throw "Failed at the step 7\n";
	}

	// Step 8
	uint8_t buff_7[] = { 255, 255, 255, 255, 7 };
	binary.setBinary(buff_7, 5);
	size = binary.readUVarint(&value);
	if (size != 5 || value != 0x7FFFFFFF)
	{
		throw "Failed at the step 8\n";
	}

};


void BinaryInputTest::test_5()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readInt();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 255 };
	binary.setBinary(buff_1, 2);
	try
	{
		binary.readInt();
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t buff_2[] = { 255, 255 , 255, 0 , 255, 0, 255, 255};
	binary.setBinary(buff_2, 8);
	int32_t value_1 = binary.readInt();
	int32_t value_2 = binary.readInt();
	if (value_1 != 16777215 || value_2 != -65281)
	{
		throw "Failed at the step 3\n";
	}

};

void BinaryInputTest::test_6()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readLong();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 255, 255, 255, 255, 255, 255 };
	binary.setBinary(buff_1, 7);
	try
	{
		binary.readLong();
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t buff_2[] = { 255, 255, 255, 0, 255, 0, 255, 0, 1, 0, 0, 255, 255, 255, 255, 255 };
	binary.setBinary(buff_2, 16);
	int64_t value_1 = binary.readLong();
	int64_t value_2 = binary.readLong();
	if (value_1 != 0xFF00FF00FFFFFFll || value_2 != -16777215ll)
	{
		throw "Failed at the step 3\n";
	}

};

void BinaryInputTest::test_7()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readDouble();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 255, 255, 255, 255, 255, 255 };
	binary.setBinary(buff_1, 7);
	try
	{
		binary.readDouble();
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t buff_2[] = { 0, 0, 0, 0, 0, 0, 0xF0, 0x3F, 0x02, 0, 0, 0, 0, 0, 0, 0xC0 };
	binary.setBinary(buff_2, 16);
	double value_1 = binary.readDouble();
	double value_2 = binary.readDouble();
	if (value_1 != 1.0000000000000000 || value_2 != -2.0000000000000009)
	{
		throw "Failed at the step 3\n";
	}

};

void BinaryInputTest::test_8()
{
	usds::BinaryInput binary;
	uint8_t buff[] = { 0, 0, 0, 0 };
	size_t size = 4;

	// step 1
	try
	{
		binary.readByteArray(buff, size);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 255, 255};
	binary.setBinary(buff_1, 3);
	try
	{
		binary.readByteArray(buff, size);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t buff_2[] = { 1, 2, 3, 4 };
	binary.setBinary(buff_2, 4);
	binary.readByteArray(buff, size);
	
	if (buff[0] != 1 || buff[1] != 2 || buff[2] != 3 || buff[3] != 4)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	try
	{
		binary.readByteArray(0, size);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_BUFF)
		{
			throw "Failed at the step 4\n";
		}
	}

};

void BinaryInputTest::test_9()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readByteArray(4);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 255, 255 };
	binary.setBinary(buff_1, 3);
	try
	{
		binary.readByteArray(4);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t buff_2[] = { 1, 2, 3, 4 };
	binary.setBinary(buff_2, 4);
	const uint8_t* buff = (const uint8_t*)binary.readByteArray(4);

	if (buff[0] != 1 || buff[1] != 2 || buff[2] != 3 || buff[3] != 4)
	{
		throw "Failed at the step 3\n";
	}

};

void BinaryInputTest::test_10()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readBool();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	uint8_t buff_1[] = { 10, 10 };
	binary.setBinary(buff_1, 2);
	try
	{
		binary.readBool();
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BOOLEAN_ERROR_FORMAT)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t buff_2[] = { 255, 0};
	binary.setBinary(buff_2, 2);
	bool value_1 = binary.readBool();
	bool value_2 = binary.readBool();
	if (value_1 != true || value_2 != false)
	{
		throw "Failed at the step 3\n";
	}

};

void BinaryInputTest::test_11()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readUByte();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 0 };
	binary.setBinary(buff_1, 2);
	uint8_t value_1 = binary.readUByte();
	uint8_t value_2 = binary.readUByte();
	if (value_1 != 255 || value_2 != 0)
	{
		throw "Failed at the step 2\n";
	}

};

void BinaryInputTest::test_12()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readByte();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 10 };
	binary.setBinary(buff_1, 2);
	int8_t value_1 = binary.readByte();
	int8_t value_2 = binary.readByte();
	if (value_1 != -1 || value_2 != 10)
	{
		throw "Failed at the step 2\n";
	}

};

void BinaryInputTest::test_13()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.stepBack(1);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	try
	{
		binary.stepForward(1);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	try
	{
		binary.isEnd();
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_BUFF)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	try
	{
		binary.getCurrentPosition();
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_BUFF)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	try
	{
		binary.getFirstPosition();
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_BUFF)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	try
	{
		binary.getSize();
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_BUFF)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	uint8_t buff[] = { 1, 2, 3 };
	binary.setBinary(buff, 3);
	try
	{
		binary.stepBack(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 7\n";
		}
	}

	// step 8
	binary.stepForward(1);
	const uint8_t* value = binary.getCurrentPosition();
	if (*value != 2)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	binary.stepForward(2);
	if (!binary.isEnd())
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	try
	{
		binary.stepForward(1);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 10\n";
		}
	}

	// step 11
	binary.stepBack(1);
	value = binary.getCurrentPosition();
	if (*value != 3)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	if (binary.getSize() != 3)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	value = binary.getFirstPosition();
	if (*value != 1)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	value = binary.getCurrentPosition();
	if (*value != 3)
	{
		throw "Failed at the step 14\n";
	}

};

void BinaryInputTest::test_14()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readShort();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	uint8_t buff_1[] = { 255 };
	binary.setBinary(buff_1, 1);
	try
	{
		binary.readShort();
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t buff_2[] = { 255, 255, 255, 0 };
	binary.setBinary(buff_2, 4);
	int16_t value_1 = binary.readShort();
	int16_t value_2 = binary.readShort();
	if (value_1 != -1 || value_2 != 255)
	{
		throw "Failed at the step 3\n";
	}
}

void BinaryInputTest::test_15()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readUShort();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	uint8_t buff_1[] = { 255 };
	binary.setBinary(buff_1, 1);
	try
	{
		binary.readUShort();
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t buff_2[] = { 255, 255, 255, 0 };
	binary.setBinary(buff_2, 4);
	uint16_t value_1 = binary.readUShort();
	uint16_t value_2 = binary.readUShort();
	if (value_1 != 65535 || value_2 != 255)
	{
		throw "Failed at the step 3\n";
	}
}

void BinaryInputTest::test_16()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readUInt();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 255, 255 };
	binary.setBinary(buff_1, 3);
	try
	{
		binary.readUInt();
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t buff_2[] = { 255, 255, 255, 255, 255, 255, 255, 0 };
	binary.setBinary(buff_2, 8);
	uint32_t value_1 = binary.readUInt();
	uint32_t value_2 = binary.readUInt();
	if (value_1 != 4294967295 || value_2 != 16777215)
	{
		throw "Failed at the step 3\n";
	}
}

void BinaryInputTest::test_17()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readULong();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 255, 255, 255, 255, 255, 255 };
	binary.setBinary(buff_1, 7);
	try
	{
		binary.readULong();
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t buff_2[] = { 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255};
	binary.setBinary(buff_2, 16);
	uint64_t value_1 = binary.readULong();
	uint64_t value_2 = binary.readULong();
	if (value_1 != 281474976710655 || value_2 != 0xFF00000000000000ULL)
	{
		throw "Failed at the step 3\n";
	}
}

void BinaryInputTest::test_18()
{
	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readFloat();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 255, 255 };
	binary.setBinary(buff_1, 3);
	try
	{
		binary.readFloat();
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t buff_2[] = { 0, 0, 0xA0, 0xBF, 0, 0, 0x90, 0x3F };
	binary.setBinary(buff_2, 8);
	float value_1 = binary.readFloat();
	float value_2 = binary.readFloat();
	if (value_1 != -1.25F || value_2 != 1.125F)
	{
		throw "Failed at the step 3\n";
	}

};

void BinaryInputTest::test_19()
{
	usds::BinaryInput binary;

	int64_t value = 0;

	// step 1
	try
	{
		binary.readVarint(&value);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_BUFF)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	{
		uint8_t buff[] = { 0 };
		binary.setBinary(buff, 1);
		size_t size = binary.readVarint(&value);
		if (size != 1 || value != 0)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	{
		uint8_t buff[] = { 2 };
		binary.setBinary(buff, 1);
		size_t size = binary.readVarint(&value);
		if (size != 1 || value != 1)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	try
	{
		uint8_t buff[] = { 1 };
		binary.setBinary(buff, 1);
		size_t size = binary.readVarint(&value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__VARINT_ERROR_FORMAT)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	{
		uint8_t buff[] = { 3 };
		binary.setBinary(buff, 1);
		size_t size = binary.readVarint(&value);
		if (size != 1 || value != -1)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	{
		uint8_t buff[] = { 126 };
		binary.setBinary(buff, 1);
		size_t size = binary.readVarint(&value);
		if (size != 1 || value != 63)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	{
		uint8_t buff[] = { 127 };
		binary.setBinary(buff, 1);
		size_t size = binary.readVarint(&value);
		if (size != 1 || value != -63)
		{
			throw "Failed at the step 7\n";
		}
	}

	// step 8
	try
	{
		uint8_t buff[] = { 255 };
		binary.setBinary(buff, 1);
		size_t size = binary.readVarint(&value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			throw "Failed at the step 8\n";
		}
	}

	// step 9
	try
	{
		uint8_t buff[] = { 255, 255, 0 };
		binary.setBinary(buff, 3);
		size_t size = binary.readVarint(&value);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__VARINT_ERROR_FORMAT)
		{
			throw "Failed at the step 9\n";
		}
	}

	// step 10
	{
		uint8_t buff[] = { 128, 2 };
		binary.setBinary(buff, 2);
		size_t size = binary.readVarint(&value);
		if (size != 2 || value != 128)
		{
			throw "Failed at the step 10\n";
		}
	}

	// step 11
	{
		uint8_t buff[] = { 129, 2 };
		binary.setBinary(buff, 2);
		size_t size = binary.readVarint(&value);
		if (size != 2 || value != -128)
		{
			throw "Failed at the step 11\n";
		}
	}

	// step 12
	{
		uint8_t buff[] = { 254, 127 };
		binary.setBinary(buff, 2);
		size_t size = binary.readVarint(&value);
		if (size != 2 || value != 8191)
		{
			throw "Failed at the step 12\n";
		}
	}

	// step 13
	{
		uint8_t buff[] = { 255, 127 };
		binary.setBinary(buff, 2);
		size_t size = binary.readVarint(&value);
		if (size != 2 || value != -8191)
		{
			throw "Failed at the step 13\n";
		}
	}

	// step 14
	{
		uint8_t buff[] = { 128, 128, 1 };
		binary.setBinary(buff, 3);
		size_t size = binary.readVarint(&value);
		if (size != 3 || value != 8192)
		{
			throw "Failed at the step 12\n";
		}
	}

	// step 15
	{
		uint8_t buff[] = { 129, 128, 1 };
		binary.setBinary(buff, 3);
		size_t size = binary.readVarint(&value);
		if (size != 3 || value != -8192)
		{
			throw "Failed at the step 12\n";
		}
	}

	// step 16
	{
		uint8_t buff[] = { 254, 255, 255, 255, 255, 255, 255, 255, 255, 1 };
		binary.setBinary(buff, 10);
		size_t size = binary.readVarint(&value);
		if (size != 10 || value != INT64_MAX)
		{
			throw "Failed at the step 16\n";
		}
	}

	// step 17
	{
		uint8_t buff[] = { 255, 255, 255, 255, 255, 255, 255, 255, 255, 1 };
		binary.setBinary(buff, 10);
		size_t size = binary.readVarint(&value);
		if (size != 10 || value != (INT64_MIN + 1))
		{
			throw "Failed at the step 17\n";
		}
	}

	// step 18
	{
		uint8_t buff[] = { 129, 128, 128, 128, 128, 128, 128, 128, 128, 2 };
		binary.setBinary(buff, 10);
		size_t size = binary.readVarint(&value);
		if (size != 10 || value != INT64_MIN )
		{
			throw "Failed at the step 18\n";
		}
	}

	// step 19
	{
		usds::BinaryOutput binary_out(64);
		for (int64_t i = -10000; i <= 10000; i++)
		{
			binary.clear();
			binary_out.clear();
			value = -20000;
			binary_out.writeVarint(i);
			binary.setBinary(binary_out.getBinary(), binary_out.getSize());
			binary.readVarint(&value);
			if (value != i)
				throw "Failed at the step 19\n";
		}
	}

	// step 20
	{
		usds::BinaryOutput binary_out(64);
		for (int64_t i = -100000000; i <= 100000000; i += 1000)
		{
			binary.clear();
			binary_out.clear();
			value = -1;
			binary_out.writeVarint(i);
			binary.setBinary(binary_out.getBinary(), binary_out.getSize());
			binary.readVarint(&value);
			if (value != i)
				throw "Failed at the step 20\n";
		}
	}

	// step 21
	{
		usds::BinaryOutput binary_out(64);
		int64_t i = INT64_MIN;
		for (int32_t j= 0; j <= 65536; j++)
		{
			binary.clear();
			binary_out.clear();
			value = -1;
			binary_out.writeVarint(i);
			binary.setBinary(binary_out.getBinary(), binary_out.getSize());
			binary.readVarint(&value);
			if (value != i)
				throw "Failed at the step 21\n";
			i = i + 281474976710656LL;
		}
	}


}


