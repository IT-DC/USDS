#include "unitTest\Base\usdsErrorTest.h"

#include <ctime>
#include <iostream>

#pragma warning(disable : 4996)

void ErrorTest::runTest()
{
	std::cout << "Class ErrorStack:\n";






	std::cout << "Class ErrorStack successful!\n";
};

void ErrorTest::printTime()
{
	time_t t = time(0);
	std::cout << std::asctime(std::localtime(&t));
};