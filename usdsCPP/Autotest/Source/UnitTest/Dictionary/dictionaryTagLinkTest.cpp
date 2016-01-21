#include "usdsAutotest.h"
#include "unitTest\dictionary\dictionaryTagLinkTest.h"

#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"

void DictionaryTagLinkTest::runTest(int number)
{
	if (!needStart(number, UNIT_TESTS__DICTIONARY_TAG_LINK))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__DICTIONARY_TAG_LINK << " ----------- Dictionary Tag Link Class --------------\n";

	test_1();
	test_2();
	test_3();

};

void DictionaryTagLinkTest::test_1()
{
	int test_number = UNIT_TESTS__DICTIONARY_TAG_LINK_1;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";


	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryTagLink* object = (usds::DictionaryTagLink*)dict.addField(usds::USDS_TAG, 0, 1, "tag_link", 0);

	// step 1

	try
	{
		object->finalize();
		std::cout << "Failed at the step 1\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_TAG_LINK__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}

	// step 2

	dict.addTag(usds::USDS_INT, 1, "int", 0);
	dict.finalizeDictionary();
	try
	{
		object->setTag(2);
		object->finalize();
		std::cout << "Failed at the step 2\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__TAG_ID_ERROR_VALUE)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}

	// step 3

	try
	{
		object->setTag("array", 0);
		object->finalize();
		std::cout << "Failed at the step 3\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_TAG_LINK__TAG_NOT_FOUND)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}


	std::cout << "Successful!\n";
}

void DictionaryTagLinkTest::test_2()
{
	int test_number = UNIT_TESTS__DICTIONARY_TAG_LINK_2;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryTagLink* object = (usds::DictionaryTagLink*)dict.addField(usds::USDS_TAG, 0, 1, "tag_link", 0);
	dict.addTag(usds::USDS_INT, 1, "int", 0);
	dict.finalizeDictionary();

	// step 1

	try
	{
		object->setTag(0);
		std::cout << "Failed at the step 1\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_TAG_LINK__ERROR_ELEMENT_ID)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}

	// step 2

	try
	{
		object->setTag(1);
		object->finalize();
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}

	// step 3

	try
	{
		if(strcmp(object->getTag()->getName(), "int") != 0)
			std::cout << "Failed at the step 3\n";
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}

	std::cout << "Successful!\n";
}

void DictionaryTagLinkTest::test_3()
{
	int test_number = UNIT_TESTS__DICTIONARY_TAG_LINK_3;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryTagLink* object = (usds::DictionaryTagLink*)dict.addField(usds::USDS_TAG, 0, 1, "tag_link", 0);
	dict.addTag(usds::USDS_INT, 1, "int", 0);
	dict.finalizeDictionary();

	// step 1

	try
	{
		object->setTag(0, 0);
		std::cout << "Failed at the step 1\n";
		throw test_number;

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_TAG_LINK__ERROR_ELEMENT_NAME)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}

	// step 2

	try
	{
		object->setTag("int", 0);
		object->finalize();
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}

	// step 3

	try
	{
		if (object->getTag()->getID() != 1)
			std::cout << "Failed at the step 3\n";
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}

	std::cout << "Successful!\n";
}