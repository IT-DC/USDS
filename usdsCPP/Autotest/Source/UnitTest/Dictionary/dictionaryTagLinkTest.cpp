#include "usdsAutotest.h"

#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"

void DictionaryTagLinkTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryTagLink* object = (usds::DictionaryTagLink*)dict.addField(usds::USDS_TAG, 0, 1, "tag_link", 0);

	// step 1

	try
	{
		object->finalize();
		throw "Failed at the step 1\n";
		

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_TAG_LINK__NOT_INITIALIZED)
		{
			throw "Failed at the step 1\n";
			
		}
	}

	// step 2

	dict.addTag(usds::USDS_INT, 1, "int", 0);
	dict.finalizeDictionary();
	try
	{
		object->setTag(2);
		object->finalize();
		throw "Failed at the step 2\n";
		

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__TAG_ID_ERROR_VALUE)
		{
			throw "Failed at the step 2\n";
			
		}
	}

	// step 3

	try
	{
		object->setTag("array", 0);
		object->finalize();
		throw "Failed at the step 3\n";
		

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_TAG_LINK__TAG_NOT_FOUND)
		{
			throw "Failed at the step 3\n";
			
		}
	}

}

void DictionaryTagLinkTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryTagLink* object = (usds::DictionaryTagLink*)dict.addField(usds::USDS_TAG, 0, 1, "tag_link", 0);
	dict.addTag(usds::USDS_INT, 1, "int", 0);
	dict.finalizeDictionary();

	// step 1

	try
	{
		object->setTag(0);
		throw "Failed at the step 1\n";
		

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_TAG_LINK__ERROR_ELEMENT_ID)
		{
			throw "Failed at the step 1\n";
			
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
		throw "Failed at the step 2\n";
		
	}

	// step 3

	try
	{
		if(strcmp(object->getTag()->getName(), "int") != 0)
			throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack)
	{
		throw "Failed at the step 3\n";
		
	}

}

void DictionaryTagLinkTest::test_3()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryTagLink* object = (usds::DictionaryTagLink*)dict.addField(usds::USDS_TAG, 0, 1, "tag_link", 0);
	dict.addTag(usds::USDS_INT, 1, "int", 0);
	dict.finalizeDictionary();

	// step 1

	try
	{
		object->setTag(0, 0);
		throw "Failed at the step 1\n";
		

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_TAG_LINK__ERROR_ELEMENT_NAME)
		{
			throw "Failed at the step 1\n";
			
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
		throw "Failed at the step 2\n";
		
	}

	// step 3

	try
	{
		if (object->getTag()->getID() != 1)
			throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack)
	{
		throw "Failed at the step 3\n";
		
	}

}