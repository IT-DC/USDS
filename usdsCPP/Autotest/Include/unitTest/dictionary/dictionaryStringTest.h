#ifndef USDS_DICTIONARY_STRING_TEST_H
#define USDS_DICTIONARY_STRING_TEST_H

#include "usdsAutotest.h"

class DictionaryStringTest
{
public:
	DictionaryStringTest() {};
	~DictionaryStringTest() {};

	void runTest(int32_t number);

private:

	void test_1();
	void test_2();
	void test_3();

	int32_t testNumbers;

};

#endif