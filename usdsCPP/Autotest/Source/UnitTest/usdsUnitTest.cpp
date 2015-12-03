#include "unitTest\usdsUnitTest.h"
#include "unitTest\base\usdsErrorTest.h"

#include "usdsAutotest.h"

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







	
	
};

