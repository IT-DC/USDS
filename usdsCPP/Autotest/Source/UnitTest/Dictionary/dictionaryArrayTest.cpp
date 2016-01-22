#include "usdsAutotest.h"
#include "unitTest\dictionary\dictionaryArrayTest.h"

#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"

void DictionaryArrayTest::runTest(int number)
{
	if (!needStart(number, UNIT_TESTS__DICTIONARY_ARRAY))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__DICTIONARY_ARRAY << " ------------- Dictionary Array Class ---------------\n";
	
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
		object->setElementType(usds::USDS_NO_TYPE);
		std::cout << "Failed at the step 1\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::USDS_TYPES__ERROR_TYPE_CODE)
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
		dict.finalizeDictionary();
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 8\n";
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
		object->finalize();
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}
	
	// step 3
	try
	{
		dict.addTag(usds::USDS_INT, 2, "int", 0);
		usds::DictionaryTagLink* tag_link = (usds::DictionaryTagLink*)object->setElementType(usds::USDS_TAG);
		tag_link->setTag(2);
		dict.finalizeDictionary();
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}

	// step 4
	try
	{
		if (((usds::DictionaryTagLink*)(object->getElement()))->getTag()->getType() != usds::USDS_INT)
		{
			std::cout << "Failed at the step 4\n";
			throw test_number;
		}
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}


	// step 5

	dict.clear();
	dict.setID(1, 0, 0);
	object = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);

	try
	{
		dict.addTag(usds::USDS_INT, 2, "int", 0);
		usds::DictionaryTagLink* tag_link = (usds::DictionaryTagLink*)object->setElementType(usds::USDS_TAG);
		tag_link->setTag("int", 0);
		dict.finalizeDictionary();
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}

	// step 6
	try
	{
		if (((usds::DictionaryTagLink*)(object->getElement()))->getTag()->getType() != usds::USDS_INT)
		{
			std::cout << "Failed at the step 6\n";
			throw test_number;
		}
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
		usds::DictionaryTagLink* tag_link = (usds::DictionaryTagLink*)object->setElementType(usds::USDS_TAG);
		tag_link->setTag(1);
		dict.finalizeDictionary();
		std::cout << "Failed at the step 7\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__RECURSION_ERROR)
		{
			std::cout << "Failed at the step 7\n";
			throw test_number;
		}
	}

	// step 8

	dict.clear();
	dict.setID(1, 0, 0);
	object = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);

	try
	{
		usds::DictionaryTagLink* tag_link = (usds::DictionaryTagLink*)object->setElementType(usds::USDS_TAG);
		tag_link->setTag("array", 0);
		dict.finalizeDictionary();
		std::cout << "Failed at the step 8\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__RECURSION_ERROR)
		{
			std::cout << "Failed at the step 8\n";
			throw test_number;
		}
	}

	std::cout << "Successful!\n";
}

