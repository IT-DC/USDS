#include "usdsAutotest.h"
#include "unitTest\base\usdsObjectPoolTest.h"

#include "base\objectPool\dicObjectPool.h"
#include "base\objectPool\bodyObjectPool.h"

void ObjectPoolTest::runTest(int number)
{
	if (!needStart(number, UNIT_TESTS__OBJECT_POOL))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__OBJECT_POOL << " ---Classes DictionaryObjectPool and BodyObjectPool---\n";
											 
	test_1();
	/*test_2();
	test_3();
	test_4();*/

};

void ObjectPoolTest::test_1()
{
	int test_number = UNIT_TESTS__OBJECT_POOL_1;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	usds::DictionaryObjectPool dic_pool;
	usds::BodyObjectPool body_pool;
	
	// step 1
	try
	{
		dic_pool.addObject(usds::USDS_NO_TYPE, 0, 0, 0, 0, 0);
		std::cout << "Failed at the step 1\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_OBJECT_POOL__UNSUPPORTED_TYPE)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}
	
	// step 2
	try
	{
		dic_pool.addObject(usds::USDS_ARRAY, 0, 0, 0, 0, 0);
		std::cout << "Failed at the step 2\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_BASE_TYPE__NULL_DICTIONARY)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}

	// step 3
	usds::Dictionary* dict = (usds::Dictionary*)1;
	try
	{
		dic_pool.addObject(usds::USDS_ARRAY, dict, 0, 0, 0, 0);
		std::cout << "Failed at the step 3\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_BASE_TYPE__NULL_NAME)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}

	// step 4
	try
	{
		dic_pool.addObject(usds::USDS_ARRAY, dict, 0, 0, "name", 0);
		std::cout << "Failed at the step 4\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_BASE_TYPE__TAG_ID_ERROR_VALUE)
		{
			std::cout << "Failed at the step 4\n";
			throw test_number;
		}
	}

	// step 5
	try
	{
		dic_pool.addObject(usds::USDS_TAG, dict, 0, 0, "name", 0);
		std::cout << "Failed at the step 5\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_OBJECT_POOL__UNSUPPORTED_TYPE)
		{
			std::cout << "Failed at the step 5\n";
			throw test_number;
		}
	}

	std::cout << "Successful!\n";

}