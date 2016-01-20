#include "usdsAutotest.h"
#include "unitTest\dictionary\dictionarySimpleTest.h"

#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryUVarint.h"

void DictionarySimpleTest::runTest(int number)
{
	if (!needStart(number, UNIT_TESTS__DICTIONARY_SIMPLE))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__DICTIONARY_SIMPLE << " ------------ Dictionary Simple Classes -------------\n";

	test_1();
	test_2();
	test_3();

};

void DictionarySimpleTest::test_1()
{
	int test_number = UNIT_TESTS__DICTIONARY_SIMPLE_1;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1

	usds::DictionaryBoolean bool_object(0);
	if (bool_object.getType() != usds::USDS_BOOLEAN)
	{
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}

	// step 2

	usds::DictionaryDouble double_object(0);
	if (double_object.getType() != usds::USDS_DOUBLE)
	{
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}

	// step 3

	usds::DictionaryInt int_object(0);
	if (int_object.getType() != usds::USDS_INT)
	{
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}

	// step 4

	usds::DictionaryLong long_object(0);
	if (long_object.getType() != usds::USDS_LONG)
	{
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}

	// step 5

	usds::DictionaryUVarint uvarint_object(0);
	if (uvarint_object.getType() != usds::USDS_UNSIGNED_VARINT)
	{
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}


	std::cout << "Successful!\n";
}

// Test for Base class - main attributes
void DictionarySimpleTest::test_2()
{
	int test_number = UNIT_TESTS__DICTIONARY_SIMPLE_2;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1

	usds::DictionaryBoolean bool_object(0);
	try
	{
		bool_object.init(0, 0, "bool", 0);
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_BASE_TYPE__TAG_ID_ERROR_VALUE)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}

	// step 2

	try
	{
		bool_object.init(0, 1, 0, 0);
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_BASE_TYPE__NULL_NAME)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}

	// step 3

	try
	{
		bool_object.init(0, 1, "boolaa", 4);
		if (strcmp(bool_object.getName(), "bool") != 0 || bool_object.getNameSize() != 4)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}

	// step 4

	try
	{
		bool_object.init(0, 1, "bool", 0);
		if (strcmp(bool_object.getName(), "bool") != 0)
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
	
	try
	{
		if (bool_object.getID() != 1)
		{
			std::cout << "Failed at the step 5\n";
			throw test_number;
		}
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}

	// step 6

	try
	{
		if (strcmp(bool_object.getTypeName(), "BOOLEAN") != 0)
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

	std::cout << "Successful!\n";
}

// Test for Base class - navigation
void DictionarySimpleTest::test_3()
{
	int test_number = UNIT_TESTS__DICTIONARY_SIMPLE_3;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1

	usds::DictionaryBoolean bool_object(0);
	bool_object.init(0, 1, "bool", 0);

	try
	{
		if (bool_object.getParent() != 0)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}

	// step 2

	usds::DictionaryInt int_object(0);
	int_object.init(&bool_object, 2, "int", 0);

	if (int_object.getParent() != &bool_object || int_object.getPrevious() != 0 || int_object.getNext() != 0)
	{
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}

	// step 3

	int_object.setParent(0);
	int_object.setPrevious(&bool_object);
	int_object.setNext(&bool_object);

	if (int_object.getParent() != 0 || int_object.getPrevious() != &bool_object || int_object.getNext() != &bool_object)
	{
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}



	std::cout << "Successful!\n";
}