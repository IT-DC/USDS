#include "usdsAutotest.h"

#include "unitTest\usdsUnitTest.h"
#include "unitTest\base\usdsErrorTest.h"
#include "unitTest\base\usdsBinaryInputTest.h"
#include "unitTest\base\usdsBinaryOutputTest.h"
#include "unitTest\base\usdsObjectPoolTest.h"

void UnitTest::runTest(int number)
{
	if (!needStart(number, UNIT_TESTS))
		return;
	
	std::cout << "==========================================================\n";
	std::cout << UNIT_TESTS << ": Unit tests are started at ";
	printTime();
	std::cout << "==========================================================\n";

	ErrorTest err_test;
	err_test.runTest(number);

	BinaryInputTest bin_input_test;
	bin_input_test.runTest(number);

	BinaryOutputTest bin_output_test;
	bin_output_test.runTest(number);

	ObjectPoolTest object_pool_test;
	object_pool_test.runTest(number);


	
	
};

