#include "usdsAutotest.h"
#include "unitTest\base\usdsBinaryInputTest.h"

#include "base\binary\usdsBinaryInput.h"

void BinaryInputTest::runTest(int number)
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
		unsigned char buff;
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
	// int readUVarint(unsigned long long* value) throw(...);
	
	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_2))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_2 << ": ";

	usds::BinaryInput binary;
	unsigned long long value = 0;
	int size = 0;

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
	unsigned char buff_1[] = { 255, 0 };
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
	unsigned char buff_2[] = { 128, 128, 128, 128, 128, 128, 128, 128, 128, 2 };
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
	unsigned char buff_3[] = { 128, 128 };
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
	unsigned char buff_4[] = { 1, 0 };
	binary.setBinary(buff_4, 2);
	size = binary.readUVarint(&value);

	if (size != 1 || value != 1)
	{
		std::cout << "Failed at the step 5\n";
		throw UNIT_TESTS__BINARY_INPUT_2;
	}

	// Step 6
	unsigned char buff_5[] = { 128, 1 };
	binary.setBinary(buff_5, 2);
	size = binary.readUVarint(&value);

	if (size != 2 || value != 128)
	{
		std::cout << "Failed at the step 6\n";
		throw UNIT_TESTS__BINARY_INPUT_2;
	}

	// Step 7
	unsigned char buff_6[] = { 129, 128, 128, 128, 128, 128, 128, 128, 128, 1 };
	binary.setBinary(buff_6, 10);
	size = binary.readUVarint(&value);
	if (size != 10 || value != 0x8000000000000001ull)
	{
		std::cout << "Failed at the step 7\n";
		throw UNIT_TESTS__BINARY_INPUT_2;
	}

	// Step 8
	unsigned char buff_7[] = { 255, 255, 255, 255, 255, 255, 255, 255, 255, 1 };
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
	// int readUVarint(unsigned int* value) throw(...);
	
	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_3))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_3 << ": ";

	usds::BinaryInput binary;
	unsigned int value = 0;
	int size = 0;

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
	unsigned char buff_1[] = { 255, 0 };
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
	unsigned char buff_2[] = { 128, 128, 128, 128, 16};
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
	unsigned char buff_3[] = { 128, 128 };
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
	unsigned char buff_4[] = { 1, 0 };
	binary.setBinary(buff_4, 2);
	size = binary.readUVarint(&value);

	if (size != 1 || value != 1)
	{
		std::cout << "Failed at the step 5\n";
		throw UNIT_TESTS__BINARY_INPUT_3;
	}

	// Step 6
	unsigned char buff_5[] = { 128, 1 };
	binary.setBinary(buff_5, 2);
	size = binary.readUVarint(&value);

	if (size != 2 || value != 128)
	{
		std::cout << "Failed at the step 6\n";
		throw UNIT_TESTS__BINARY_INPUT_3;
	}

	// Step 7
	unsigned char buff_6[] = { 129, 128, 128, 128, 15 };
	binary.setBinary(buff_6, 5);
	size = binary.readUVarint(&value);
	if (size != 5 || value != 0xF0000001u)
	{
		std::cout << "Failed at the step 7\n";
		throw UNIT_TESTS__BINARY_INPUT_3;
	}

	// Step 8
	unsigned char buff_7[] = { 255, 255, 255, 255, 15};
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
	// int readUVarint(int* value) throw(...);

	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_4))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_4 << ": ";

	usds::BinaryInput binary;
	int value = 0;
	int size = 0;

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
	unsigned char buff_1[] = { 255, 0 };
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
	unsigned char buff_2[] = { 128, 128, 128, 128, 8 };
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
	unsigned char buff_3[] = { 128, 128 };
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
	unsigned char buff_4[] = { 1, 0 };
	binary.setBinary(buff_4, 2);
	size = binary.readUVarint(&value);

	if (size != 1 || value != 1)
	{
		std::cout << "Failed at the step 5\n";
		throw UNIT_TESTS__BINARY_INPUT_4;
	}

	// Step 6
	unsigned char buff_5[] = { 128, 1 };
	binary.setBinary(buff_5, 2);
	size = binary.readUVarint(&value);

	if (size != 2 || value != 128)
	{
		std::cout << "Failed at the step 6\n";
		throw UNIT_TESTS__BINARY_INPUT_4;
	}

	// Step 7
	unsigned char buff_6[] = { 129, 128, 128, 128, 7 };
	binary.setBinary(buff_6, 5);
	size = binary.readUVarint(&value);
	if (size != 5 || value != 0x70000001)
	{
		std::cout << "Failed at the step 7\n";
		throw UNIT_TESTS__BINARY_INPUT_4;
	}

	// Step 8
	unsigned char buff_7[] = { 255, 255, 255, 255, 7 };
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
	// int readInt() throw(...);

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
	unsigned char buff_1[] = { 255, 255 };
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
	unsigned char buff_2[] = { 255, 255 , 255, 0 , 255, 0, 255, 255};
	binary.setBinary(buff_2, 8);
	int value_1 = binary.readInt();
	int value_2 = binary.readInt();
	if (value_1 != 16777215 || value_2 != -65281)
	{
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__BINARY_INPUT_5;
	}

	std::cout << "Successful!\n";
};

void BinaryInputTest::test_6()
{
	// int readUVarint(int* value) throw(...);

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
	unsigned char buff_1[] = { 255, 255, 255, 255, 255, 255, 255 };
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
	unsigned char buff_2[] = { 255, 255, 255, 0, 255, 0, 255, 0, 1, 0, 0, 255, 255, 255, 255, 255 };
	binary.setBinary(buff_2, 16);
	long long value_1 = binary.readLong();
	long long value_2 = binary.readLong();
	if (value_1 != 0xFF00FF00FFFFFFll || value_2 != -16777215ll)
	{
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__BINARY_INPUT_6;
	}


	std::cout << "Successful!\n";
};

void BinaryInputTest::test_7()
{
	// int readUVarint(int* value) throw(...);

	if (!needStart(testNumbers, UNIT_TESTS__BINARY_INPUT_7))
		return;

	std::cout << UNIT_TESTS__BINARY_INPUT_7 << ": ";




	std::cout << "Successful!\n";
};