#ifndef USDS_DICTIONARY_TEST_H
#define USDS_DICTIONARY_TEST_H

#include "usdsAutotest.h"

class DictionaryTest
{
public:
	DictionaryTest() {};
	~DictionaryTest() {};

	void runTest(int32_t number);

private:

	void test_1();
	void test_2();
	void test_3();
	void test_4();
	void test_5();
	void test_6();
	void test_7();

	int32_t testNumbers;

};

#endif