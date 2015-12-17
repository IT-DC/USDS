#include "usdsAutotest.h"
#include "unitTest\base\usdsBinaryOutputTest.h"

#include "base\binary\usdsBinaryOutput.h"

void BinaryOutputTest::runTest(int number)
{
	if (!needStart(number, UNIT_TESTS__BINARY_OUTPUT))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__BINARY_INPUT << " ---------------- Class BinaryOutput -----------------\n";

	test_1();
	test_2();
	/*test_3();
	test_4();
	test_5();
	test_6();
	test_7();
	test_8();
	test_9();
	test_10();
	test_11();
	test_12();
	test_13(); */

};

void BinaryOutputTest::test_1()
{
	int test_number = UNIT_TESTS__BINARY_OUTPUT_1;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	usds::BinaryOutput binary;

	// step 1
	size_t size = 0;
	if (binary.getBinary() != binary.getBinary(&size))
	{
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}

	if (size != 0 || binary.getSize()!=0 || !binary.isEmpty())
	{
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}

	std::cout << "Successful!\n";

}

void BinaryOutputTest::test_2()
{
	int test_number = UNIT_TESTS__BINARY_OUTPUT_2;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	usds::BinaryOutput binary;

	// step 1
	unsigned long long value = 0x8000000000000001ull;
	binary.writeUVarint(value);
	size_t size;
	const unsigned char* buff = binary.getBinary(&size);
	if (size != 10 || buff[0] != 129 || buff[1] != 128 || buff[2] != 128 || buff[3] != 128 || buff[4] != 128 || buff[5] != 128 || buff[6] != 128 || buff[7] != 128 || buff[8] != 128 || buff[9] != 1)
	{
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}




	std::cout << "Successful!\n";

}