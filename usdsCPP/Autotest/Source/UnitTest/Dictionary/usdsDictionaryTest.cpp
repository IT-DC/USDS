#include "usdsAutotest.h"
#include "unitTest\dictionary\usdsDictionaryTest.h"

#include "dictionary\usdsDictionary.h"

void DictionaryTest::runTest(int number)
{
	if (!needStart(number, UNIT_TESTS__DICTIONARY))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__DICTIONARY << " ---------------- Dictionary Class ------------------\n";

	test_1();
	test_2();
	test_3();
	test_4();
	//test_5();
};

// Test clear dictionary
void DictionaryTest::test_1()
{
	int test_number = UNIT_TESTS__DICTIONARY_1;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1
	usds::Dictionary dict(0);
	
	try
	{
		dict.finalizeDictionary();
		std::cout << "Failed at the step 1\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}

	// step 2
	try
	{
		dict.getDictionaryID();
		std::cout << "Failed at the step 2\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}

	// step 3
	try
	{
		dict.getMajorVersion();
		std::cout << "Failed at the step 3\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}

	// step 4
	try
	{
		dict.getMinorVersion();
		std::cout << "Failed at the step 4\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 4\n";
			throw test_number;
		}
	}

	// step 5
	try
	{
		dict.getFirstTag();
		std::cout << "Failed at the step 5\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NO_TAGS)
		{
			std::cout << "Failed at the step 5\n";
			throw test_number;
		}
	}

	// step 6
	try
	{
		dict.getLastTag();
		std::cout << "Failed at the step 6\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NO_TAGS)
		{
			std::cout << "Failed at the step 6\n";
			throw test_number;
		}
	}

	// step 7
	try
	{
		dict.getTag(1);
		std::cout << "Failed at the step 7\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 7\n";
			throw test_number;
		}
	}

	// step 8
	if (dict.getTagNumber() != 0)
	{
		std::cout << "Failed at the step 8\n";
		throw test_number;
	}

	// step 9
	try
	{
		size_t size = 0;
		dict.getBinary(&size);
		std::cout << "Failed at the step 9\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NOT_FINALIZED)
		{
			std::cout << "Failed at the step 9\n";
			throw test_number;
		}
	}

	std::cout << "Successful!\n";
}

// Test dictionary identifier 
void DictionaryTest::test_2()
{
	int test_number = UNIT_TESTS__DICTIONARY_2;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1
	usds::Dictionary dict(0);
	try
	{
		dict.setID(-2, 2, 4);
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__ID_ERROR_VALUE)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}
	
	// step 2
	dict.setID(25, 2, 4);
	if (dict.getDictionaryID() != 25 || dict.getMajorVersion() != 2 || dict.getMinorVersion() != 4)
	{
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}

	// step 3
	try
	{
		dict.finalizeDictionary();
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NO_TAGS)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}

	std::cout << "Successful!\n";
}

// Test errors in "Find" 
void DictionaryTest::test_3()
{
	int test_number = UNIT_TESTS__DICTIONARY_3;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1
	usds::Dictionary dict(0);
	try
	{
		dict.findTagID(0);
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NULL_NAME)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}

	// step 2
	if (dict.findTagID("int") != 0)
	{
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}

	// step 3
	try
	{
		dict.findTagID(0, 0);
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NULL_NAME)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}

	// step 4
	if (dict.findTagID("int", 0) != 0 || dict.findTagID("int", 3) != 0)
	{
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}

	// step 5
	try
	{
		dict.findTag(0);
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NULL_NAME)
		{
			std::cout << "Failed at the step 5\n";
			throw test_number;
		}
	}

	// step 6
	if (dict.findTag("int") != 0)
	{
		std::cout << "Failed at the step 6\n";
		throw test_number;
	}

	// step 7
	try
	{
		dict.findTag(0, 0);
		std::cout << "Failed at the step 7\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NULL_NAME)
		{
			std::cout << "Failed at the step 7\n";
			throw test_number;
		}
	}

	// step 8
	if (dict.findTag("int", 0) != 0 || dict.findTag("int", 3) != 0)
	{
		std::cout << "Failed at the step 8\n";
		throw test_number;
	}

	std::cout << "Successful!\n";
}

// Test AddTag
void DictionaryTest::test_4()
{
	int test_number = UNIT_TESTS__DICTIONARY_4;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);

	// step 1
	try
	{
		dict.addTag(usds::USDS_TAG, 1, "tag", 0);
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__UNSUPPORTED_TYPE)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}
	
	// step 2
	try
	{
		dict.addTag(usds::USDS_INT, 1, 0, 0);
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NULL_NAME)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}

	// step 3
	try
	{
		dict.addTag(usds::USDS_INT, 0, "int", 0);
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_BASE_TYPE__TAG_ID_ERROR_VALUE)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}


	std::cout << "Successful!\n";
}
