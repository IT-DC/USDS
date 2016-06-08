#ifndef USDS_ERROR_TEST_H
#define USDS_ERROR_TEST_H

#include "usdsAutotest.h"

class ErrorTest
{
public:
	ErrorTest() {};
	~ErrorTest() {};

	void runTest(int32_t number);

private:
	
	void test_1();
	void test_2();
	void test_3();
	void test_4();
	void test_5();

	int32_t testNumbers;

};

#endif