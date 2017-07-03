#include "usdsAutotest.h"

#pragma execution_character_set("utf-8")

#include "body\usdsBody.h"
#include "dictionary\usdsDictionary.h"
#include "dictionary/dataTypes/dictionaryString.h"
#include "body/dataTypes/usdsString.h"

void UsdsStringTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;

	usds::DictionaryString* dict_string1 = (usds::DictionaryString*)dict.addTag(usds::USDS_STRING, 1, "string_no_def", 0);
	usds::DictionaryString* dict_string2 = (usds::DictionaryString*)dict.addTag(usds::USDS_STRING, 2, "string_utf8", 0);
	dict_string2->setDefaultEncode(usds::USDS_UTF8);
	dict.finalizeDictionary();

	// test 1
	usds::UsdsString* body_string = (usds::UsdsString*)body.addTag(dict_string1);
	try
	{
		body_string->setFromUTF8("Hello");
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRING__NO_ENCODE)
		{
			throw "Failed at the step 1\n";
		}
	}

	// test 2
	try
	{
		body_string->setEncode(usds::USDS_NO_DEFAULT_ENCODE);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRING__NO_ENCODE)
		{
			throw "Failed at the step 2\n";
		}
	}

	// test 3
	body_string->setEncode(usds::USDS_UTF8);
	body_string->setFromUTF8("Hello");
	try
	{
		body_string->setEncode(usds::USDS_UTF16LE);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRING__STRING_AREADY_INITIALIZED)
		{
			throw "Failed at the step 3\n";
		}
	}

	// test 4
	size_t size = 0;
	const char* value = body_string->getUTF8Value(&size);
	if (size != 5)
		throw "Failed at the step 4\n";
	if (strncmp(value, "Hello", size) != 0)
		throw "Failed at the step 4\n";

	// test 5
	body_string->setFromUTF8("Hello", 6);
	size = 0;
	value = body_string->getUTF8Value(&size);
	if (size != 5)
		throw "Failed at the step 5\n";
	if (strncmp(value, "Hello", size) != 0)
		throw "Failed at the step 5\n";

	// test 6
	body_string->setFromUTF8("Привет");
	size = 0;
	value = body_string->getUTF8Value(&size);
	if (size != 12)
		throw "Failed at the step 6\n";
	if (strncmp(value, "Привет", size) != 0)
		throw "Failed at the step 6\n";


}
