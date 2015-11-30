#include "unitTest\usdsUnitTest.h"
#include "unitTest\base\usdsErrorTest.h"

#include <ctime>
#include <iostream>

#pragma warning(disable : 4996)

void UnitTest::runTest()
{
	ErrorTest err_test;

	std::cout << "Unit tests are started at ";
	printTime();

	err_test.runTest();







	std::cout << "Unit tests are finished successful at ";
	printTime();
};

void UnitTest::printTime()
{
	time_t t = time(0);
	std::cout << std::asctime(std::localtime(&t));
};