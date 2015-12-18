#ifndef USDS_OBJECT_POOL_TEST_H
#define USDS_OBJECT_POOL_TEST_H

class ObjectPoolTest
{
public:
	ObjectPoolTest() {};
	~ObjectPoolTest() {};

	void runTest(int number);

private:

	void test_1();
	void test_2();
	void test_3();
	void test_4();

	int testNumbers;

};

#endif