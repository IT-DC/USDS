#ifndef USDS_DICTIONARY_SIMPLE_TEST_H
#define USDS_DICTIONARY_SIMPLE_TEST_H

#include "usdsAutotest.h"

class DictionarySimpleTest
{
public:
	DictionarySimpleTest() {};
	~DictionarySimpleTest() {};

	void runTest(int32_t number);

private:

	void test_1();
	void test_2();
	void test_3();

	int32_t testNumbers;

};

#endif