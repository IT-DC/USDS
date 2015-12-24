#include "usdsAutotest.h"
#include "unitTest\dictionary\dictionaryArrayTest.h"

#include "dictionary\dataTypes\dictionaryArray.h"

void DictionaryArrayTest::runTest(int number)
{
	if (!needStart(number, UNIT_TESTS__DICTIONARY_TYPES))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__DICTIONARY_TYPES << " -------------- Class DictionaryArray ---------------\n";

	test_1();
	/*test_2();
	test_3();
	test_4();
	test_5();*/


};

void DictionaryArrayTest::test_1()
{
	int test_number = UNIT_TESTS__DICTIONARY_TYPES_1;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	usds::DictionaryArray object(0);

	// step 1

/*	object.init()

	
	try
	{
		body_pool.addObject(0, 0);
		std::cout << "Failed at the step 1\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_OBJECT_POOL__NULL_DICTIONARY_TAG)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}
	*/
	std::cout << "Successful!\n";

}