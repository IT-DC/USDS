#include "usdsAutotest.h"

#include "dictionary\dataTypes\dictionaryString.h"

void DictionaryStringTest::test_1()
{
	// step 1

	usds::DictionaryString object(0);
	if (object.getType() != usds::USDS_STRING)
	{
		throw "Failed at the step 1\n";
	}

	// step 2

	object.initType(0, 1, "string", 0);
	if (object.getEncode() != usds::USDS_NO_ENCODE)
	{
		throw "Failed at the step 2\n";
	}

	// step 3
	try
	{
		object.finalize();
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRING__ERROR_ENCODE)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4

	object.setEncode(usds::USDS_UTF8);
	if (object.getEncode() != usds::USDS_UTF8)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	try
	{
		object.finalize();
	}
	catch (usds::ErrorStack)
	{
		throw "Failed at the step 5\n";
	}
	
}