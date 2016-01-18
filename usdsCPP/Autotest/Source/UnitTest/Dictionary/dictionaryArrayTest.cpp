#include "usdsAutotest.h"
#include "unitTest\dictionary\dictionaryArrayTest.h"

#include "dictionary\usdsDictionary.h"
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


	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryArray* object = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);

	// step 1

	try
	{
		object->setElementType(usds::USDS_TAG);
		std::cout << "Failed at the step 1\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ERROR_ELEMENT_TYPE)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}
	std::cout << "Successful!\n";

}