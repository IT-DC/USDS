#ifndef USDS_INT_TEST_H
#define USDS_INT_TEST_H

#include "usdsAutotest.h"

class UsdsIntTest
{
public:
	UsdsIntTest() {};
	~UsdsIntTest() {};

	void runTest(int32_t number);

private:

	void test_1();
	void test_2();

	int32_t testNumbers;

};

#endif