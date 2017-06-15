#include "usdsAutotest.h"

#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"
#include "dictionary\dataTypes\dictionaryString.h"

// Test simple types for array's element
void DictionaryArrayTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryArray* object = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);

	// step 1

	try
	{
		object->setElementType(usds::USDS_NO_TYPE);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ERROR_ELEMENT_TYPE)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2

	/*
	try
	{
		object->setElementType(usds::USDS_ARRAY);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ERROR_ELEMENT_TYPE)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3

	try
	{
		object->setElementType(usds::USDS_STRUCT);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ERROR_ELEMENT_TYPE)
		{
			throw "Failed at the step 3\n";
		}
	}
	*/

	// step 4
	try
	{
		object->setElementType(usds::USDS_INT);
	}
	catch (usds::ErrorStack)
	{
		throw "Failed at the step 4\n";
	}

	// step 5

	try
	{
		object->setElementType(usds::USDS_UVARINT);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ALREADY_INITIALIZED)
		{
			throw "Failed at the step 5\n";
		}
	}
	
	// step 6
	
	dict.clear();
	dict.setID(1, 0, 0);
	object = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);
	
	try
	{
		object->setElementType(usds::USDS_UVARINT);
	}
	catch (usds::ErrorStack)
	{
		throw "Failed at the step 6\n";
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
		throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRING__ERROR_ENCODE)
		{
			throw "Failed at the step 8\n";
		}
	}

	// step 9
	((usds::DictionaryString*)(object->getElement()))->setEncode(usds::USDS_UTF8);
	try
	{
		dict.finalizeDictionary();
	}
	catch (usds::ErrorStack)
	{
		throw "Failed at the step 9\n";
	}

}

// test TAG as element for array
void DictionaryArrayTest::test_2()
{
	// step 1

	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryArray* object = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);

	try
	{
		object->getElementType();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__NOT_INITIALIZED)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	try
	{
		object->finalize();
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__NOT_INITIALIZED)
		{
			throw "Failed at the step 2\n";
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
		throw "Failed at the step 3\n";
	}

	// step 4
	try
	{
		if (((usds::DictionaryTagLink*)(object->getElement()))->getTag()->getType() != usds::USDS_INT)
		{
			throw "Failed at the step 4\n";
		}
	}
	catch (usds::ErrorStack)
	{
		throw "Failed at the step 4\n";
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
		throw "Failed at the step 5\n";
	}

	// step 6
	try
	{
		if (((usds::DictionaryTagLink*)(object->getElement()))->getTag()->getType() != usds::USDS_INT)
		{
			throw "Failed at the step 6\n";
		}
	}
	catch (usds::ErrorStack)
	{
		throw "Failed at the step 6\n";
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
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__RECURSION_ERROR)
		{
			throw "Failed at the step 7\n";
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
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__RECURSION_ERROR)
		{
			throw "Failed at the step 8\n";
		}
	}

}

