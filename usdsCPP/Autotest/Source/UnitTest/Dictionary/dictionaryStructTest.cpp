#include "usdsAutotest.h"
#include "unitTest\dictionary\dictionaryStructTest.h"

#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryStruct.h"

void DictionaryStructTest::runTest(int number)
{
	if (!needStart(number, UNIT_TESTS__DICTIONARY_STRUCT))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__DICTIONARY_STRING << " ------------- Dictionary Struct Class --------------\n";

	test_1();
	//test_2();
	//test_3();

};

void DictionaryStructTest::test_1()
{
	int test_number = UNIT_TESTS__DICTIONARY_STRUCT_1;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1

	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryStruct* object = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct", 0);
	
	if (object->getType() != usds::USDS_STRUCT)
	{
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}

	// step 2

	if (object->getFirstField() != 0 || object->getLastField() != 0 || object->getFieldNumber() != 0)
	{
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}

	// step 3
	try
	{
		object->finalize();
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__NO_FIELD)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}


	std::cout << "Successful!\n";
}