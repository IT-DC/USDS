#include "usdsAutotest.h"

#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"

// Test empty dictionary
void DictionaryTest::test_1()
{
	// step 1
	usds::Dictionary dict(0);
	
	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 1\n";
		

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NO_TAGS)
		{
			throw "Failed at the step 1\n";
			
		}
	}

	// step 2
	if (dict.getDictionaryID() != 0)
		throw "Failed at the step 2\n";

	// step 3
	if (dict.getMajorVersion() != 0)
		throw "Failed at the step 3\n";

	// step 4
	if (dict.getMinorVersion() != 0)
		throw "Failed at the step 4\n";

	// step 5
	try
	{
		dict.getFirstTag();
		throw "Failed at the step 5\n";
		

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NO_TAGS)
		{
			throw "Failed at the step 5\n";
			
		}
	}

	// step 6
	try
	{
		dict.getLastTag();
		throw "Failed at the step 6\n";
		

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NO_TAGS)
		{
			throw "Failed at the step 6\n";
			
		}
	}

	// step 7
	try
	{
		dict.getTag(1);
		throw "Failed at the step 7\n";
		

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NOT_INITIALIZED)
		{
			throw "Failed at the step 7\n";
			
		}
	}

	// step 8
	if (dict.getTagNumber() != 0)
	{
		throw "Failed at the step 8\n";
		
	}

	// step 9
	try
	{
		size_t size = 0;
		dict.getBinary(&size);
		throw "Failed at the step 9\n";
		

	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NOT_FINALIZED)
		{
			throw "Failed at the step 9\n";
			
		}
	}

}

// Test dictionary identifier 
void DictionaryTest::test_2()
{
	usds::Dictionary dict(0);
	
	// step 1
	dict.setID("name", 25, 2, 4);
	const char* name = dict.getDictionaryName();
	if (dict.getDictionaryID() != 25 || dict.getMajorVersion() != 2 || dict.getMinorVersion() != 4 || strcmp(name, "name") != 0)
	{
		throw "Failed at the step 1\n";
		
	}

	// step 2
	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 2\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NO_TAGS)
		{
			throw "Failed at the step 3\n";
			
		}
	}

}

// Test errors in "Find" 
void DictionaryTest::test_3()
{
	// step 1
	usds::Dictionary dict(0);
	try
	{
		dict.findTagID(0);
		throw "Failed at the step 1\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NULL_NAME)
		{
			throw "Failed at the step 1\n";
			
		}
	}

	// step 2
	if (dict.findTagID("int") != 0)
	{
		throw "Failed at the step 1\n";
		
	}

	// step 3
	try
	{
		dict.findTagID(0, 0);
		throw "Failed at the step 3\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NULL_NAME)
		{
			throw "Failed at the step 3\n";
			
		}
	}

	// step 4
	if (dict.findTagID("int", 0) != 0 || dict.findTagID("int", 3) != 0)
	{
		throw "Failed at the step 4\n";
		
	}

	// step 5
	try
	{
		dict.findTag(0);
		throw "Failed at the step 5\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NULL_NAME)
		{
			throw "Failed at the step 5\n";
			
		}
	}

	// step 6
	if (dict.findTag("int") != 0)
	{
		throw "Failed at the step 6\n";
		
	}

	// step 7
	try
	{
		dict.findTag(0, 0);
		throw "Failed at the step 7\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NULL_NAME)
		{
			throw "Failed at the step 7\n";
			
		}
	}

	// step 8
	if (dict.findTag("int", 0) != 0 || dict.findTag("int", 3) != 0)
	{
		throw "Failed at the step 8\n";
		
	}

}

// Test AddTag
void DictionaryTest::test_4()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);

	// step 1
	try
	{
		dict.addTag(usds::USDS_TAG, 1, "tag", 0);
		throw "Failed at the step 1\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__UNSUPPORTED_TYPE)
		{
			throw "Failed at the step 1\n";
			
		}
	}
	
	// step 2
	try
	{
		dict.addTag(usds::USDS_INT, 1, 0, 0);
		throw "Failed at the step 2\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NULL_NAME)
		{
			throw "Failed at the step 2\n";
			
		}
	}

	// step 3
	try
	{
		dict.addTag(usds::USDS_INT, 0, "int", 0);
		throw "Failed at the step 3\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_BASE_TYPE__TAG_ID_ERROR_VALUE)
		{
			throw "Failed at the step 3\n";
			
		}
	}

	// step 4
	dict.addTag(usds::USDS_INT, 1, "int", 0);
	try
	{
		dict.addTag(usds::USDS_INT, 2, "int", 0);
		throw "Failed at the step 4\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__TAG_ALREADY_EXISTS)
		{
			throw "Failed at the step 4\n";
			
		}
	}

	// step 5
	dict.addTag(usds::USDS_INT, 3, "int_2", 0);
	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 5\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__TAG_ID_ERROR_VALUE)
		{
			throw "Failed at the step 5\n";
			
		}
	}

	// step 6
	dict.addTag(usds::USDS_INT, 3, "int_3", 0);
	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 6\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__TAG_ID_ERROR_VALUE)
		{
			throw "Failed at the step 6\n";
			
		}
	}

}


// Test Tag finalization
void DictionaryTest::test_5()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);

	// step 1
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);
	try
	{
		dict.finalizeDictionary();
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
	usds::DictionaryTagLink* tag_link = (usds::DictionaryTagLink*)array_tag->setElementType(usds::USDS_TAG);
	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 2\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_TAG_LINK__NOT_INITIALIZED)
		{
			throw "Failed at the step 2\n";
			
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
		throw "Failed at the step 3\n";
		
	}

	// step 4
	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 4\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__FINALIZED_ALREADY)
		{
			throw "Failed at the step 4\n";
			
		}
	}

	// step 5
	try
	{
		dict.addTag(usds::USDS_INT, 3, "int_2", 0);
		throw "Failed at the step 5\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__FINALIZED_ALREADY)
		{
			throw "Failed at the step 5\n";
			
		}
	}

	// step 6
	try
	{
		dict.addField(usds::USDS_INT, 0, 3, "int_2", 0);
		throw "Failed at the step 6\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__FINALIZED_ALREADY)
		{
			throw "Failed at the step 6\n";
			
		}
	}


}

// Test Tag navigation
void DictionaryTest::test_6()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);

	usds::DictionaryInt* tag_1 = (usds::DictionaryInt*)dict.addTag(usds::USDS_INT, 1, "int_1", 0);
	usds::DictionaryLong* tag_4 = (usds::DictionaryLong*)dict.addTag(usds::USDS_LONG, 4, "int_4", 0);
	usds::DictionaryBoolean* tag_2 = (usds::DictionaryBoolean*)dict.addTag(usds::USDS_BOOLEAN, 2, "int_2", 0);
	usds::DictionaryDouble* tag_3 = (usds::DictionaryDouble*)dict.addTag(usds::USDS_DOUBLE, 3, "int_3", 0);

	// step 1
	if (tag_1->getParent() != 0 || tag_1->getPrevious() != 0 || tag_1->getNext() != tag_4)
	{
		throw "Failed at the step 1\n";
		
	}

	// step 2
	if (tag_2->getParent() != 0 || tag_2->getPrevious() != tag_4 || tag_2->getNext() != tag_3)
	{
		throw "Failed at the step 2\n";
		
	}

	// step 3
	if (tag_3->getParent() != 0 || tag_3->getPrevious() != tag_2 || tag_3->getNext() != 0)
	{
		throw "Failed at the step 3\n";
		
	}

	// step 4
	if (tag_4->getParent() != 0 || tag_4->getPrevious() != tag_1 || tag_4->getNext() != tag_2)
	{
		throw "Failed at the step 4\n";
		
	}

	// step 5
	dict.finalizeDictionary();
	if (dict.getTag(1) != tag_1 || dict.getTag(2) != tag_2 || dict.getTag(3) != tag_3 || dict.getTag(4) != tag_4)
	{
		throw "Failed at the step 5\n";
		
	}

	// step 6
	if (tag_1->getParent() != 0 || tag_1->getPrevious() != 0 || tag_1->getNext() != tag_2)
	{
		throw "Failed at the step 6\n";
		
	}

	// step 7
	if (tag_2->getParent() != 0 || tag_2->getPrevious() != tag_1 || tag_2->getNext() != tag_3)
	{
		throw "Failed at the step 7\n";
		
	}

	// step 8
	if (tag_3->getParent() != 0 || tag_3->getPrevious() != tag_2 || tag_3->getNext() != tag_4)
	{
		throw "Failed at the step 8\n";
		
	}

	// step 9
	if (tag_4->getParent() != 0 || tag_4->getPrevious() != tag_3 || tag_4->getNext() != 0)
	{
		throw "Failed at the step 9\n";
		
	}


}


// Test dictionary binary
void DictionaryTest::test_7()
{
	// step 1
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::DictionaryInt* tag_1 = (usds::DictionaryInt*)dict.addTag(usds::USDS_INT, 1, "int_1", 0);

	size_t size = 0;
	const uint8_t* binary = 0;

	// step 1
	try
	{
		binary = dict.getBinary(&size);
		throw "Failed at the step 1\n";
		
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DICTIONARY__NOT_FINALIZED)
		{
			throw "Failed at the step 1\n";
			
		}
	}

	// step 2
	dict.finalizeDictionary();
	binary = dict.getBinary(&size);
	if (binary == 0 || size != 9)
	{
		throw "Failed at the step 2\n";
		
	}

	// step 3
	uint8_t sample_binary[] = { usds::USDS_TAG_SIGNATURE , 1, 5, 'i', 'n', 't', '_', '1', usds::USDS_INT };
	for (int32_t i = 0; i < 9; i++)
	{
		if (sample_binary[i] != binary[i])
		{
			throw "Failed at the step 3\n";
			
		}
	}

}