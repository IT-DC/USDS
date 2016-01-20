#include "usdsAutotest.h"
#include "unitTest\dictionary\dictionaryArrayTest.h"

#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryArray.h"

void DictionaryArrayTest::runTest(int number)
{
	if (!needStart(number, UNIT_TESTS__DICTIONARY_TYPES))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__DICTIONARY_TYPES << " ------------- Dictionary Array Class ---------------\n";
	
	test_1();
	test_2();

};

// Test simple types for array's element
void DictionaryArrayTest::test_1()
{
	int test_number = UNIT_TESTS__DICTIONARY_ARRAY_1;
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

	// step 2

	try
	{
		object->setElementType(usds::USDS_ARRAY);
		std::cout << "Failed at the step 2\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ERROR_ELEMENT_TYPE)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}

	// step 3

	try
	{
		object->setElementType(usds::USDS_STRUCT);
		std::cout << "Failed at the step 3\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ERROR_ELEMENT_TYPE)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}

	// step 4
	try
	{
		object->setElementType(usds::USDS_INT);
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}

	// step 5

	try
	{
		object->setElementType(usds::USDS_UNSIGNED_VARINT);
		std::cout << "Failed at the step 5\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ALREADY_INITIALIZED)
		{
			std::cout << "Failed at the step 5\n";
			throw test_number;
		}
	}
	
	// step 6
	
	dict.clear();
	dict.setID(1, 0, 0);
	object = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);
	
	try
	{
		object->setElementType(usds::USDS_UNSIGNED_VARINT);
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 6\n";
		throw test_number;
	}

	// step 7
	
	dict.clear();
	dict.setID(1, 0, 0);
	object = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);
	
	try
	{
		object->setElementType(usds::USDS_STRING);
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 7\n";
		throw test_number;
	}

	// step 8

	try
	{
		object->getElementTagID();
		std::cout << "Failed at the step 8\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ELEMENT_NOT_TAG)
		{
			std::cout << "Failed at the step 8\n";
			throw test_number;
		}
	}

	// step 9

	try
	{
		object->getElementTagName();
		std::cout << "Failed at the step 9\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ELEMENT_NOT_TAG)
		{
			std::cout << "Failed at the step 9\n";
			throw test_number;
		}
	}

	// step 10
	try
	{
		dict.finalizeDictionary();
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 10\n";
		throw test_number;
	}

	std::cout << "Successful!\n";
}

// test TAG as element for array
void DictionaryArrayTest::test_2()
{
	int test_number = UNIT_TESTS__DICTIONARY_ARRAY_2;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";
	// step 1

	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryArray* object = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);

	try
	{
		object->getElementType();
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
	try
	{
		object->setElementAsTag(0, 0);
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ERROR_ELEMENT_NAME)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}
	
	// step 3
	try
	{
		object->setElementAsTag(0);
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ERROR_ELEMENT_ID)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}
	
	// step 4
	try
	{
		object->getElement();
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 4\n";
			throw test_number;
		}
	}
	
	// step 5
	try
	{
		object->getElementTagID();
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 5\n";
			throw test_number;
		}
	}

	// step 6
	try
	{
		object->getElementTagName();
		std::cout << "Failed at the step 6\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 6\n";
			throw test_number;
		}
	}

	// step 7
	try
	{
		object->finalize();
		std::cout << "Failed at the step 7\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 7\n";
			throw test_number;
		}
	}
	
	// step 8
	try
	{
		dict.addTag(usds::USDS_INT, 2, "int", 0);
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 8\n";
		throw test_number;
	}

	// step 9

	object->setElementAsTag(2);
	try
	{
		object->setElementAsTag(2);
		std::cout << "Failed at the step 9\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ALREADY_INITIALIZED)
		{
			std::cout << "Failed at the step 9\n";
			throw test_number;
		}
	}

	// step 10
	try
	{
		object->setElementAsTag("int", 0);
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ALREADY_INITIALIZED)
		{
			std::cout << "Failed at the step 10\n";
			throw test_number;
		}
	}

	// step 11
	try
	{
		dict.finalizeDictionary();
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 11\n";
		throw test_number;
	}

	// step 12
	try
	{
		if(object->getElement()->getType() != usds::USDS_INT)
		{
			std::cout << "Failed at the step 12\n";
			throw test_number;
		}
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 12\n";
		throw test_number;
	}

	// step 13
	try
	{
		int id = object->getElementTagID();
		if (id != 2)
		{
			std::cout << "Failed at the step 13\n";
			throw test_number;
		}
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 13\n";
		throw test_number;
	}

	// step 14
	try
	{
		if (strcmp(object->getElementTagName(), "int")!=0)
		{
			std::cout << "Failed at the step 14\n";
			throw test_number;
		}
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 14\n";
		throw test_number;
	}

	// step 15

	dict.clear();
	dict.setID(1, 0, 0);
	object = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);

	try
	{
		dict.addTag(usds::USDS_INT, 2, "int", 0);
		object->setElementAsTag("int", 0);
		dict.finalizeDictionary();
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 15\n";
		throw test_number;
	}

	// step 16
	try
	{
		int id = object->getElementTagID();
		if (id != 2)
		{
			std::cout << "Failed at the step 16\n";
			throw test_number;
		}
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 16\n";
		throw test_number;
	}

	// step 17
	try
	{
		if (strcmp(object->getElementTagName(), "int") != 0)
		{
			std::cout << "Failed at the step 17\n";
			throw test_number;
		}
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 17\n";
		throw test_number;
	}

	// step 18

	dict.clear();
	dict.setID(1, 0, 0);
	object = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);

	try
	{
		object->setElementAsTag(1);
		dict.finalizeDictionary();
		std::cout << "Failed at the step 18\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__RECURSION_ERROR)
		{
			std::cout << "Failed at the step 18\n";
			throw test_number;
		}
	}

	// step 19

	dict.clear();
	dict.setID(1, 0, 0);
	object = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);

	try
	{
		object->setElementAsTag("array", 0);
		dict.finalizeDictionary();
		std::cout << "Failed at the step 19\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__RECURSION_ERROR)
		{
			std::cout << "Failed at the step 19\n";
			throw test_number;
		}
	}

	std::cout << "Successful!\n";
}

