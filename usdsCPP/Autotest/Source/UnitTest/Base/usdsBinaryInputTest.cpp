#include "unitTest\base\usdsBinaryInputTest.h"

#include "base\binary\usdsBinaryInput.h"

void BinaryInputTest::runTest(int32_t number)
{
	if (!needStart(number, UNIT_TESTS__BINARY_INPUT))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__BINARY_INPUT << " ---------------- Class BinaryInput -----------------\n";

	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	test_6();
	test_7();
	test_8();
	test_9();
	test_10();
	test_11();
	test_12();
	test_13();

};

void BinaryInputTest::test_1()
{
	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_1))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_1 << ": ";

	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.setBinary(0, 1);
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__BINARY_INPUT_1;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_BUFF)
		{
			std::cout << "Failed at the step 1\n";
			throw UNIT_TESTS__BINARY_INPUT_1;
		}
	}

	// step 2
	try
	{
		uint8_t buff;
		binary.setBinary(&buff, 0);
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__BINARY_INPUT_1;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_SIZE)
		{
			std::cout << "Failed at the step 2\n";
			throw UNIT_TESTS__BINARY_INPUT_1;
		}
	}
	
	std::cout << "Successful!\n";
};

void BinaryInputTest::test_2()
{
	// int32_t readUVarint(uint64_t* value) throw(...);
	
	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_2))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_2 << ": ";

	usds::BinaryInput binary;
	uint64_t value = 0;
	int32_t size = 0;

	// step 1
	try
	{
		size = binary.readUVarint(&value);
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__BINARY_INPUT_2;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 1\n";
			throw UNIT_TESTS__BINARY_INPUT_2;
		}
	}

	// Step 2
	uint8_t buff_1[] = { 255, 0 };
	binary.setBinary(buff_1, 2);
	try
	{
		size = binary.readUVarint(&value);
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__BINARY_INPUT_2;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__UVARINT_ERROR_FORMAT)
		{
			std::cout << "Failed at the step 2\n";
			throw UNIT_TESTS__BINARY_INPUT_2;
		}
	}

	// Step 3
	uint8_t buff_2[] = { 128, 128, 128, 128, 128, 128, 128, 128, 128, 2 };
	binary.setBinary(buff_2, 10);
	try
	{
		size = binary.readUVarint(&value);
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__BINARY_INPUT_2;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BEEG_UVARINT)
		{
			std::cout << "Failed at the step 3\n";
			throw UNIT_TESTS__BINARY_INPUT_2;
		}
	}

	// Step 4
	uint8_t buff_3[] = { 128, 128 };
	binary.setBinary(buff_3, 2);
	try
	{
		size = binary.readUVarint(&value);
		std::cout << "Failed at the step 4\n";
		throw UNIT_TESTS__BINARY_INPUT_2;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 4\n";
			throw UNIT_TESTS__BINARY_INPUT_2;
		}
	}

	// Step 5
	uint8_t buff_4[] = { 1, 0 };
	binary.setBinary(buff_4, 2);
	size = binary.readUVarint(&value);

	if (size != 1 || value != 1)
	{
		std::cout << "Failed at the step 5\n";
		throw UNIT_TESTS__BINARY_INPUT_2;
	}

	// Step 6
	uint8_t buff_5[] = { 128, 1 };
	binary.setBinary(buff_5, 2);
	size = binary.readUVarint(&value);

	if (size != 2 || value != 128)
	{
		std::cout << "Failed at the step 6\n";
		throw UNIT_TESTS__BINARY_INPUT_2;
	}

	// Step 7
	uint8_t buff_6[] = { 129, 128, 128, 128, 128, 128, 128, 128, 128, 1 };
	binary.setBinary(buff_6, 10);
	size = binary.readUVarint(&value);
	if (size != 10 || value != 0x8000000000000001ull)
	{
		std::cout << "Failed at the step 7\n";
		throw UNIT_TESTS__BINARY_INPUT_2;
	}

	// Step 8
	uint8_t buff_7[] = { 255, 255, 255, 255, 255, 255, 255, 255, 255, 1 };
	binary.setBinary(buff_7, 10);
	size = binary.readUVarint(&value);
	if (size != 10 || value != 0xFFFFFFFFFFFFFFFFull)
	{
		std::cout << "Failed at the step 8\n";
		throw UNIT_TESTS__BINARY_INPUT_2;
	}

	std::cout << "Successful!\n";
};

void BinaryInputTest::test_3()
{
	// int32_t readUVarint(uint32_t* value) throw(...);
	
	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_3))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_3 << ": ";

	usds::BinaryInput binary;
	uint32_t value = 0;
	int32_t size = 0;

	// step 1
	try
	{
		size = binary.readUVarint(&value);
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__BINARY_INPUT_3;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 1\n";
			throw UNIT_TESTS__BINARY_INPUT_3;
		}
	}

	// Step 2
	uint8_t buff_1[] = { 255, 0 };
	binary.setBinary(buff_1, 2);
	try
	{
		size = binary.readUVarint(&value);
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__BINARY_INPUT_3;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__UVARINT_ERROR_FORMAT)
		{
			std::cout << "Failed at the step 2\n";
			throw UNIT_TESTS__BINARY_INPUT_3;
		}
	}

	// Step 3
	uint8_t buff_2[] = { 128, 128, 128, 128, 16};
	binary.setBinary(buff_2, 5);
	try
	{
		size = binary.readUVarint(&value);
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__BINARY_INPUT_3;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BEEG_UVARINT)
		{
			std::cout << "Failed at the step 3\n";
			throw UNIT_TESTS__BINARY_INPUT_3;
		}
	}

	// Step 4
	uint8_t buff_3[] = { 128, 128 };
	binary.setBinary(buff_3, 2);
	try
	{
		size = binary.readUVarint(&value);
		std::cout << "Failed at the step 4\n";
		throw UNIT_TESTS__BINARY_INPUT_3;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 4\n";
			throw UNIT_TESTS__BINARY_INPUT_3;
		}
	}

	// Step 5
	uint8_t buff_4[] = { 1, 0 };
	binary.setBinary(buff_4, 2);
	size = binary.readUVarint(&value);

	if (size != 1 || value != 1)
	{
		std::cout << "Failed at the step 5\n";
		throw UNIT_TESTS__BINARY_INPUT_3;
	}

	// Step 6
	uint8_t buff_5[] = { 128, 1 };
	binary.setBinary(buff_5, 2);
	size = binary.readUVarint(&value);

	if (size != 2 || value != 128)
	{
		std::cout << "Failed at the step 6\n";
		throw UNIT_TESTS__BINARY_INPUT_3;
	}

	// Step 7
	uint8_t buff_6[] = { 129, 128, 128, 128, 15 };
	binary.setBinary(buff_6, 5);
	size = binary.readUVarint(&value);
	if (size != 5 || value != 0xF0000001u)
	{
		std::cout << "Failed at the step 7\n";
		throw UNIT_TESTS__BINARY_INPUT_3;
	}

	// Step 8
	uint8_t buff_7[] = { 255, 255, 255, 255, 15};
	binary.setBinary(buff_7, 5);
	size = binary.readUVarint(&value);
	if (size != 5 || value != 0xFFFFFFFFu)
	{
		std::cout << "Failed at the step 8\n";
		throw UNIT_TESTS__BINARY_INPUT_3;
	}

	std::cout << "Successful!\n";
};

void BinaryInputTest::test_4()
{
	// int32_t readUVarint(int32_t* value) throw(...);

	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_4))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_4 << ": ";

	usds::BinaryInput binary;
	int32_t value = 0;
	int32_t size = 0;

	// step 1
	try
	{
		size = binary.readUVarint(&value);
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__BINARY_INPUT_4;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 1\n";
			throw UNIT_TESTS__BINARY_INPUT_4;
		}
	}

	// Step 2
	uint8_t buff_1[] = { 255, 0 };
	binary.setBinary(buff_1, 2);
	try
	{
		size = binary.readUVarint(&value);
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__BINARY_INPUT_4;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__UVARINT_ERROR_FORMAT)
		{
			std::cout << "Failed at the step 2\n";
			throw UNIT_TESTS__BINARY_INPUT_4;
		}
	}

	// Step 3
	uint8_t buff_2[] = { 128, 128, 128, 128, 8 };
	binary.setBinary(buff_2, 5);
	try
	{
		size = binary.readUVarint(&value);
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__BINARY_INPUT_4;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BEEG_UVARINT)
		{
			std::cout << "Failed at the step 3\n";
			throw UNIT_TESTS__BINARY_INPUT_4;
		}
	}

	// Step 4
	uint8_t buff_3[] = { 128, 128 };
	binary.setBinary(buff_3, 2);
	try
	{
		size = binary.readUVarint(&value);
		std::cout << "Failed at the step 4\n";
		throw UNIT_TESTS__BINARY_INPUT_4;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 4\n";
			throw UNIT_TESTS__BINARY_INPUT_4;
		}
	}

	// Step 5
	uint8_t buff_4[] = { 1, 0 };
	binary.setBinary(buff_4, 2);
	size = binary.readUVarint(&value);

	if (size != 1 || value != 1)
	{
		std::cout << "Failed at the step 5\n";
		throw UNIT_TESTS__BINARY_INPUT_4;
	}

	// Step 6
	uint8_t buff_5[] = { 128, 1 };
	binary.setBinary(buff_5, 2);
	size = binary.readUVarint(&value);

	if (size != 2 || value != 128)
	{
		std::cout << "Failed at the step 6\n";
		throw UNIT_TESTS__BINARY_INPUT_4;
	}

	// Step 7
	uint8_t buff_6[] = { 129, 128, 128, 128, 7 };
	binary.setBinary(buff_6, 5);
	size = binary.readUVarint(&value);
	if (size != 5 || value != 0x70000001)
	{
		std::cout << "Failed at the step 7\n";
		throw UNIT_TESTS__BINARY_INPUT_4;
	}

	// Step 8
	uint8_t buff_7[] = { 255, 255, 255, 255, 7 };
	binary.setBinary(buff_7, 5);
	size = binary.readUVarint(&value);
	if (size != 5 || value != 0x7FFFFFFF)
	{
		std::cout << "Failed at the step 8\n";
		throw UNIT_TESTS__BINARY_INPUT_4;
	}

	std::cout << "Successful!\n";
};


void BinaryInputTest::test_5()
{
	// int32_t readInt() throw(...);

	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_5))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_5 << ": ";

	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readInt();
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__BINARY_INPUT_5;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 1\n";
			throw UNIT_TESTS__BINARY_INPUT_5;
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 255 };
	binary.setBinary(buff_1, 2);
	try
	{
		binary.readInt();
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__BINARY_INPUT_5;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 2\n";
			throw UNIT_TESTS__BINARY_INPUT_5;
		}
	}

	// step 3
	uint8_t buff_2[] = { 255, 255 , 255, 0 , 255, 0, 255, 255};
	binary.setBinary(buff_2, 8);
	int32_t value_1 = binary.readInt();
	int32_t value_2 = binary.readInt();
	if (value_1 != 16777215 || value_2 != -65281)
	{
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__BINARY_INPUT_5;
	}

	std::cout << "Successful!\n";
};

void BinaryInputTest::test_6()
{
	// int64_t readLong() throw(...);

	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_6))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_6 << ": ";

	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readLong();
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__BINARY_INPUT_6;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 1\n";
			throw UNIT_TESTS__BINARY_INPUT_6;
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 255, 255, 255, 255, 255, 255 };
	binary.setBinary(buff_1, 7);
	try
	{
		binary.readLong();
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__BINARY_INPUT_6;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 2\n";
			throw UNIT_TESTS__BINARY_INPUT_6;
		}
	}

	// step 3
	uint8_t buff_2[] = { 255, 255, 255, 0, 255, 0, 255, 0, 1, 0, 0, 255, 255, 255, 255, 255 };
	binary.setBinary(buff_2, 16);
	int64_t value_1 = binary.readLong();
	int64_t value_2 = binary.readLong();
	if (value_1 != 0xFF00FF00FFFFFFll || value_2 != -16777215ll)
	{
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__BINARY_INPUT_6;
	}


	std::cout << "Successful!\n";
};

void BinaryInputTest::test_7()
{
	// double readDouble() throw(...);

	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_7))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_7 << ": ";

	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readDouble();
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__BINARY_INPUT_7;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 1\n";
			throw UNIT_TESTS__BINARY_INPUT_7;
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 255, 255, 255, 255, 255, 255 };
	binary.setBinary(buff_1, 7);
	try
	{
		binary.readDouble();
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__BINARY_INPUT_7;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 2\n";
			throw UNIT_TESTS__BINARY_INPUT_7;
		}
	}

	// step 3
	uint8_t buff_2[] = { 0, 0, 0, 0, 0, 0, 0xF0, 0x3F, 0x02, 0, 0, 0, 0, 0, 0, 0xC0 };
	binary.setBinary(buff_2, 16);
	double value_1 = binary.readDouble();
	double value_2 = binary.readDouble();
	if (value_1 != 1.0000000000000000 || value_2 != -2.0000000000000009)
	{
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__BINARY_INPUT_7;
	}

	std::cout << "Successful!\n";
};

void BinaryInputTest::test_8()
{
	// void readByteArray(void* buff, size_t size) throw(...);

	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_8))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_8 << ": ";

	usds::BinaryInput binary;
	uint8_t buff[] = { 0, 0, 0, 0 };
	size_t size = 4;

	// step 1
	try
	{
		binary.readByteArray(buff, size);
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__BINARY_INPUT_8;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 1\n";
			throw UNIT_TESTS__BINARY_INPUT_8;
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 255, 255};
	binary.setBinary(buff_1, 3);
	try
	{
		binary.readByteArray(buff, size);
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__BINARY_INPUT_8;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 2\n";
			throw UNIT_TESTS__BINARY_INPUT_8;
		}
	}

	// step 3
	uint8_t buff_2[] = { 1, 2, 3, 4 };
	binary.setBinary(buff_2, 4);
	binary.readByteArray(buff, size);
	
	if (buff[0] != 1 || buff[1] != 2 || buff[2] != 3 || buff[3] != 4)
	{
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__BINARY_INPUT_8;
	}

	// step 4
	try
	{
		binary.readByteArray(0, size);
		std::cout << "Failed at the step 4\n";
		throw UNIT_TESTS__BINARY_INPUT_8;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_BUFF)
		{
			std::cout << "Failed at the step 4\n";
			throw UNIT_TESTS__BINARY_INPUT_8;
		}
	}

	std::cout << "Successful!\n";
};

void BinaryInputTest::test_9()
{
	// const void* readByteArray(size_t size) throw(...);

	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_8))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_9 << ": ";

	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readByteArray(4);
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__BINARY_INPUT_9;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 1\n";
			throw UNIT_TESTS__BINARY_INPUT_9;
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 255, 255 };
	binary.setBinary(buff_1, 3);
	try
	{
		binary.readByteArray(4);
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__BINARY_INPUT_9;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 2\n";
			throw UNIT_TESTS__BINARY_INPUT_9;
		}
	}

	// step 3
	uint8_t buff_2[] = { 1, 2, 3, 4 };
	binary.setBinary(buff_2, 4);
	const uint8_t* buff = (const uint8_t*)binary.readByteArray(4);

	if (buff[0] != 1 || buff[1] != 2 || buff[2] != 3 || buff[3] != 4)
	{
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__BINARY_INPUT_9;
	}

	std::cout << "Successful!\n";
};

void BinaryInputTest::test_10()
{
	// bool readBool() throw(...);

	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_10))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_10 << ": ";

	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readBool();
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__BINARY_INPUT_10;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 1\n";
			throw UNIT_TESTS__BINARY_INPUT_10;
		}
	}

	// step 2
	uint8_t buff_1[] = { 10, 10 };
	binary.setBinary(buff_1, 2);
	try
	{
		binary.readBool();
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__BINARY_INPUT_10;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BOOLEAN_ERROR_FORMAT)
		{
			std::cout << "Failed at the step 2\n";
			throw UNIT_TESTS__BINARY_INPUT_10;
		}
	}

	// step 3
	uint8_t buff_2[] = { 255, 0};
	binary.setBinary(buff_2, 2);
	bool value_1 = binary.readBool();
	bool value_2 = binary.readBool();
	if (value_1 != true || value_2 != false)
	{
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__BINARY_INPUT_10;
	}

	std::cout << "Successful!\n";
};

void BinaryInputTest::test_11()
{
	// uint8_t readUByte() throw(...);

	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_11))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_11 << ": ";

	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readUByte();
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__BINARY_INPUT_11;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 1\n";
			throw UNIT_TESTS__BINARY_INPUT_11;
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 0 };
	binary.setBinary(buff_1, 2);
	uint8_t value_1 = binary.readUByte();
	uint8_t value_2 = binary.readUByte();
	if (value_1 != 255 || value_2 != 0)
	{
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__BINARY_INPUT_11;
	}

	std::cout << "Successful!\n";
};

void BinaryInputTest::test_12()
{
	// uint8_t readByte() throw(...);

	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_12))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_12 << ": ";

	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.readByte();
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__BINARY_INPUT_12;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 1\n";
			throw UNIT_TESTS__BINARY_INPUT_12;
		}
	}

	// step 2
	uint8_t buff_1[] = { 255, 10 };
	binary.setBinary(buff_1, 2);
	int8_t value_1 = binary.readByte();
	int8_t value_2 = binary.readByte();
	if (value_1 != -1 || value_2 != 10)
	{
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__BINARY_INPUT_11;
	}

	std::cout << "Successful!\n";
};

void BinaryInputTest::test_13()
{
	// navigation
	int32_t test_number = UNIT_TESTS__BINARY_INPUT_13;

	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	usds::BinaryInput binary;

	// step 1
	try
	{
		binary.stepBack(1);
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}

	// step 2
	try
	{
		binary.stepForward(1);
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}

	// step 3
	try
	{
		binary.isEnd();
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_BUFF)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}

	// step 4
	try
	{
		binary.getCurrentPosition();
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_BUFF)
		{
			std::cout << "Failed at the step 4\n";
			throw test_number;
		}
	}

	// step 5
	try
	{
		binary.getFirstPosition();
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_BUFF)
		{
			std::cout << "Failed at the step 5\n";
			throw test_number;
		}
	}

	// step 6
	try
	{
		binary.getDataSize();
		std::cout << "Failed at the step 6\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__NULL_BUFF)
		{
			std::cout << "Failed at the step 6\n";
			throw test_number;
		}
	}

	// step 7
	uint8_t buff[] = { 1, 2, 3 };
	binary.setBinary(buff, 3);
	try
	{
		binary.stepBack(1);
		std::cout << "Failed at the step 7\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 7\n";
			throw test_number;
		}
	}

	// step 8
	binary.stepForward(1);
	const uint8_t* value = binary.getCurrentPosition();
	if (*value != 2)
	{
		std::cout << "Failed at the step 8\n";
		throw test_number;
	}

	// step 9
	binary.stepForward(2);
	if (!binary.isEnd())
	{
		std::cout << "Failed at the step 9\n";
		throw test_number;
	}

	// step 10
	try
	{
		binary.stepForward(1);
		std::cout << "Failed at the step 10\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BIN_IN__BUFF_OVERFLOW)
		{
			std::cout << "Failed at the step 10\n";
			throw test_number;
		}
	}

	// step 11
	binary.stepBack(1);
	value = binary.getCurrentPosition();
	if (*value != 3)
	{
		std::cout << "Failed at the step 11\n";
		throw test_number;
	}

	// step 12
	if (binary.getDataSize() != 3)
	{
		std::cout << "Failed at the step 12\n";
		throw test_number;
	}

	// step 13
	value = binary.getFirstPosition();
	if (*value != 1)
	{
		std::cout << "Failed at the step 13\n";
		throw test_number;
	}

	// step 14
	value = binary.getCurrentPosition();
	if (*value != 3)
	{
		std::cout << "Failed at the step 14\n";
		throw test_number;
	}


	std::cout << "Successful!\n";
};