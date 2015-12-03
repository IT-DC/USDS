#ifndef USDS_ERROR_TEST_H
#define USDS_ERROR_TEST_H

class ErrorTest
{
public:
	ErrorTest() {};
	~ErrorTest() {};

	void runTest(int number);

private:
	
	void test_1();
	void test_2();
	void test_3();
	
	int testNumbers;

};

#endif