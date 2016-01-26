#include "usdsAutotest.h"
#include "unitTest\dictionary\usdsDictionaryTest.h"

#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"

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
	test_5();
	test_6();
	test_7();
};

// Test empty dictionary
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

	// step 4
	dict.addTag(usds::USDS_INT, 1, "int", 0);
	try
	{
		dict.addTag(usds::USDS_INT, 2, "int", 0);
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__TAG_ALREADY_EXISTS)
		{
			std::cout << "Failed at the step 4\n";
			throw test_number;
		}
	}

	// step 5
	dict.addTag(usds::USDS_INT, 3, "int_2", 0);
	try
	{
		dict.finalizeDictionary();
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__TAG_ID_ERROR_VALUE)
		{
			std::cout << "Failed at the step 5\n";
			throw test_number;
		}
	}

	// step 6
	dict.addTag(usds::USDS_INT, 3, "int_3", 0);
	try
	{
		dict.finalizeDictionary();
		std::cout << "Failed at the step 6\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__TAG_ID_ERROR_VALUE)
		{
			std::cout << "Failed at the step 6\n";
			throw test_number;
		}
	}

	std::cout << "Successful!\n";
}


// Test Tag finalization
void DictionaryTest::test_5()
{
	int test_number = UNIT_TESTS__DICTIONARY_5;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);

	// step 1
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);
	try
	{
		dict.finalizeDictionary();
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
	usds::DictionaryTagLink* tag_link = (usds::DictionaryTagLink*)array_tag->setElementType(usds::USDS_TAG);
	try
	{
		dict.finalizeDictionary();
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_TAG_LINK__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}

	// step 3
	dict.addTag(usds::USDS_INT, 2, "int", 0);
	tag_link->setTag(2);
	try
	{
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
		dict.finalizeDictionary();
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__FINALIZED_ALREADY)
		{
			std::cout << "Failed at the step 4\n";
			throw test_number;
		}
	}

	// step 5
	try
	{
		dict.addTag(usds::USDS_INT, 3, "int_2", 0);
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__FINALIZED_ALREADY)
		{
			std::cout << "Failed at the step 5\n";
			throw test_number;
		}
	}

	// step 6
	try
	{
		dict.addField(usds::USDS_INT, 0, 3, "int_2", 0);
		std::cout << "Failed at the step 6\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__FINALIZED_ALREADY)
		{
			std::cout << "Failed at the step 6\n";
			throw test_number;
		}
	}


	std::cout << "Successful!\n";
}

// Test Tag navigation
void DictionaryTest::test_6()
{
	int test_number = UNIT_TESTS__DICTIONARY_6;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);

	usds::DictionaryInt* tag_1 = (usds::DictionaryInt*)dict.addTag(usds::USDS_INT, 1, "int_1", 0);
	usds::DictionaryLong* tag_4 = (usds::DictionaryLong*)dict.addTag(usds::USDS_LONG, 4, "int_4", 0);
	usds::DictionaryBoolean* tag_2 = (usds::DictionaryBoolean*)dict.addTag(usds::USDS_BOOLEAN, 2, "int_2", 0);
	usds::DictionaryDouble* tag_3 = (usds::DictionaryDouble*)dict.addTag(usds::USDS_DOUBLE, 3, "int_3", 0);

	// step 1
	if (tag_1->getParent() != 0 || tag_1->getPrevious() != 0 || tag_1->getNext() != tag_4)
	{
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}

	// step 2
	if (tag_2->getParent() != 0 || tag_2->getPrevious() != tag_4 || tag_2->getNext() != tag_3)
	{
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}

	// step 3
	if (tag_3->getParent() != 0 || tag_3->getPrevious() != tag_2 || tag_3->getNext() != 0)
	{
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}

	// step 4
	if (tag_4->getParent() != 0 || tag_4->getPrevious() != tag_1 || tag_4->getNext() != tag_2)
	{
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}

	// step 5
	dict.finalizeDictionary();
	if (dict.getTag(1) != tag_1 || dict.getTag(2) != tag_2 || dict.getTag(3) != tag_3 || dict.getTag(4) != tag_4)
	{
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}

	// step 6
	if (tag_1->getParent() != 0 || tag_1->getPrevious() != 0 || tag_1->getNext() != tag_2)
	{
		std::cout << "Failed at the step 6\n";
		throw test_number;
	}

	// step 7
	if (tag_2->getParent() != 0 || tag_2->getPrevious() != tag_1 || tag_2->getNext() != tag_3)
	{
		std::cout << "Failed at the step 7\n";
		throw test_number;
	}

	// step 8
	if (tag_3->getParent() != 0 || tag_3->getPrevious() != tag_2 || tag_3->getNext() != tag_4)
	{
		std::cout << "Failed at the step 8\n";
		throw test_number;
	}

	// step 9
	if (tag_4->getParent() != 0 || tag_4->getPrevious() != tag_3 || tag_4->getNext() != 0)
	{
		std::cout << "Failed at the step 9\n";
		throw test_number;
	}


	std::cout << "Successful!\n";
}


// Test dictionary binary
void DictionaryTest::test_7()
{
	int test_number = UNIT_TESTS__DICTIONARY_7;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryInt* tag_1 = (usds::DictionaryInt*)dict.addTag(usds::USDS_INT, 1, "int_1", 0);

	size_t size = 0;
	const unsigned char* binary = 0;

	// step 1
	try
	{
		binary = dict.getBinary(&size);
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NOT_FINALIZED)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}

	// step 2
	dict.finalizeDictionary();
	binary = dict.getBinary(&size);
	if (binary == 0 || size != 9)
	{
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}

	// step 3
	unsigned char sample_binary[] = { usds::USDS_TAG_SIGNATURE , 1, 5, 'i', 'n', 't', '_', '1', usds::USDS_INT };
	for (int i = 0; i < 9; i++)
	{
		if (sample_binary[i] != binary[i])
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}



	std::cout << "Successful!\n";
}