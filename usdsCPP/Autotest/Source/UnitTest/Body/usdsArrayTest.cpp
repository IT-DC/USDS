#include "unitTest\body\usdsArrayTest.h"

#include "body\dataTypes\usdsArray.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\usdsDictionary.h"


void UsdsArrayTest::runTest(int32_t number)
{
	if (!needStart(number, UNIT_TESTS__BODY_ARRAY))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__BODY_ARRAY << " ---------------- Body Array Class ------------------\n";
	
	test_1();
	//test_2();

};

// Test INT type for array's element
void UsdsArrayTest::test_1()
{
	int32_t test_number = UNIT_TESTS__BODY_ARRAY_1;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryArray* dict_array = 0;
	usds::UsdsArray* body_array = 0;

	// step 1
	dict_array = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);
	try
	{
		body_array = (usds::UsdsArray*)body.addTag(dict_array);
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}

	// step 2
	dict_array->setElementType(usds::USDS_INT);
	dict.finalizeDictionary();
	body_array = (usds::UsdsArray*)body.addTag(dict_array);
	
	if (body_array->getElementType() != usds::USDS_INT || body_array->size()!=0)
	{	
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}

	// step 3
	int32_t int_value = 5;
	body_array->pushBack(int_value);
	if (body_array->size() != 1 || body_array->getValue<int>(0) != int_value)
	{
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}


	std::cout << "Successful!\n";
}


