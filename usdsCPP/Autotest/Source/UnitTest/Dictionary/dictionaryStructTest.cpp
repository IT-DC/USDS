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
	test_2();
	//test_3();

};

// Test empty Structure
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

	// step 4
	try
	{
		object->getField(1);
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__STRUCT_IS_NOT_FINALIZED)
		{
			std::cout << "Failed at the step 4\n";
			throw test_number;
		}
	}

	// step 5
	try
	{
		object->getField((const char*)0);
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__NULL_NAME)
		{
			std::cout << "Failed at the step 5\n";
			throw test_number;
		}
	}

	// step 6
	try
	{
		object->getField("int");
		std::cout << "Failed at the step 6\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__FIELD_NOT_FOUND)
		{
			std::cout << "Failed at the step 6\n";
			throw test_number;
		}
	}

	// step 7
	try
	{
		object->getField(0, 0);
		std::cout << "Failed at the step 7\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__NULL_NAME)
		{
			std::cout << "Failed at the step 7\n";
			throw test_number;
		}
	}

	// step 8
	try
	{
		object->getField("int", 0);
		std::cout << "Failed at the step 8\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__FIELD_NOT_FOUND)
		{
			std::cout << "Failed at the step 8\n";
			throw test_number;
		}
	}

	// step 9
	try
	{
		object->findFieldID(0);
		std::cout << "Failed at the step 9\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__NULL_NAME)
		{
			std::cout << "Failed at the step 9\n";
			throw test_number;
		}
	}

	// step 10
	if (object->findFieldID("int") != 0)
	{
		std::cout << "Failed at the step 10\n";
		throw test_number;
	}

	// step 11
	try
	{
		object->findFieldID(0, 0);
		std::cout << "Failed at the step 11\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__NULL_NAME)
		{
			std::cout << "Failed at the step 11\n";
			throw test_number;
		}
	}

	// step 12
	if (object->findFieldID("int", 0) != 0)
	{
		std::cout << "Failed at the step 12\n";
		throw test_number;
	}

	std::cout << "Successful!\n";
}

// Test simple fields
void DictionaryStructTest::test_2()
{
	int test_number = UNIT_TESTS__DICTIONARY_STRUCT_2;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1

	
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryStruct* object = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct", 0);

	try
	{
		object->addField(usds::USDS_INT, 0, "int", 0);
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
		object->addField(usds::USDS_INT, 1, 0, 0);
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__NULL_NAME)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}
	
	// step 3

	try
	{
		object->addField(usds::USDS_BOOLEAN, 1, "boolean", 0);
		object->addField(usds::USDS_INT, 2, "int", 0);
		object->addField(usds::USDS_DOUBLE, 3, "double", 0);
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}

	std::cout << "Successful!\n";
}