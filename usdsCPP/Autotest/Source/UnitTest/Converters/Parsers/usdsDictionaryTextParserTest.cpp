#include "usdsAutotest.h"

#include "converters/usdsDictionaryTextParser.h"

#include "dictionary\usdsDictionary.h"

// Test simple types for array's element
void DictionaryTextParserTest::test_1()
{
	usds::DictionaryTextParser* pareser = new usds::DictionaryTextParser();
	
	
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	
	// step 1
	try
	{
		//object->setElementType(usds::USDS_LAST_TYPE);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ARRAY__ERROR_ELEMENT_TYPE)
		{
			throw "Failed at the step 1\n";
		}
	}



}