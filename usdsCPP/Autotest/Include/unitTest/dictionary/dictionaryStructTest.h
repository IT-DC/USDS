#ifndef USDS_DICTIONARY_STRUCT_TEST_H
#define USDS_DICTIONARY_STRUCT_TEST_H

#include "usdsAutotest.h"

class DictionaryStructTest
{
public:
	DictionaryStructTest() {};
	~DictionaryStructTest() {};

	void runTest(int32_t number);

private:

	void test_1();
	void test_2();
	void test_3();
	void test_4();

	int32_t testNumbers;

};

#endif