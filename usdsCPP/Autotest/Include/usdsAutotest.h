#ifndef USDS_AUTOTEST_H
#define USDS_AUTOTEST_H

#include <iostream>
#include <ctime>

enum testNumbers
{
	ANY_TEST = 0,
	UNIT_TESTS = 100000,
		UNIT_TESTS__USDS_ERRORS = 101000,
			UNIT_TESTS__USDS_ERRORS_1 = 101001,
			UNIT_TESTS__USDS_ERRORS_2 = 101002,
			UNIT_TESTS__USDS_ERRORS_3 = 101003,
			UNIT_TESTS__USDS_ERRORS_4 = 101004,
		UNIT_TESTS__BINARY_INPUT = 102000,
			UNIT_TESTS__BINARY_INPUT_1 = 102001,
			UNIT_TESTS__BINARY_INPUT_2 = 102002,
	INTAGRATION_TESTS = 200000,
	STRESS_TESTS = 300000
};

extern bool needStart(int current_number, int my_number);

extern void printTime();


#endif