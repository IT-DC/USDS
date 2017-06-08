#include "usdsAutotest.h"

#include "body\dataTypes\usdsArray.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\usdsDictionary.h"

//========================================================================================================
// Test INT type for array's element - pushBack
void UsdsArrayTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryArray* dict_array = 0;
	usds::UsdsArray* body_array = 0;

	// step 1
	dict_array = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);
	try
	{
		body_array = (usds::UsdsArray*)body.addTag(dict_array);
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
	dict_array->setElementType(usds::USDS_INT);
	dict.finalizeDictionary();
	body_array = (usds::UsdsArray*)body.addTag(dict_array);
	
	if (body_array->getElementType() != usds::USDS_INT || body_array->size()!=0)
	{	
		throw "Failed at the step 2\n";
	}

	// step 3
	bool bool_value = true;
	try
	{
		body_array->pushBack(bool_value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__UNSUPPORTED_CONVERSION)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	int8_t int8_value = -100;
	body_array->pushBack(int8_value);
	if (body_array->size() != 1 || (int32_t)(*body_array)[0] != -100)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	uint8_t uint8_value = 250;
	body_array->pushBack(uint8_value);
	if (body_array->size() != 2 || body_array->getValue<int32_t>(1) != 250)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	int16_t int16_value = -10000;
	body_array->pushBack(int16_value);
	if (body_array->size() != 3 || body_array->getValue<int32_t>(2) != -10000)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	uint16_t uint16_value = 20000;
	body_array->pushBack(uint16_value);
	if (body_array->size() != 4 || body_array->getValue<int32_t>(3) != 20000)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	int32_t int32_value = -100000;
	body_array->pushBack(int32_value);
	if (body_array->size() != 5 || body_array->getValue<int32_t>(4) != -100000)
	{
		throw "Failed at the step 8\n";
	}
	
	// step 9
	uint32_t uint32_value = 100000;
	body_array->pushBack(uint32_value);
	if (body_array->size() != 6 || body_array->getValue<int32_t>(5) != 100000)
	{
		throw "Failed at the step 8\n";
	}

	// step 10
	uint32_value = 4000000000u;
	try
	{
		body_array->pushBack(uint32_value);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__TOO_BIG_VALUE)
		{
			throw "Failed at the step 10\n";
		}
	}

	// step 11
	int64_t int64_value = -100000;
	body_array->pushBack(int64_value);
	if (body_array->size() != 7 || body_array->getValue<int32_t>(6) != -100000)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	int64_value = -4000000000ll;
	try
	{
		body_array->pushBack(int64_value);
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__TOO_BIG_VALUE)
		{
			throw "Failed at the step 12\n";
		}
	}

	// step 13
	uint64_t uint64_value = 100000;
	body_array->pushBack(uint64_value);
	if (body_array->size() != 8 || body_array->getValue<int32_t>(7) != 100000)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	uint64_value =6000000000ll;
	try
	{
		body_array->pushBack(uint64_value);
		throw "Failed at the step 14\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__TOO_BIG_VALUE)
		{
			throw "Failed at the step 14\n";
		}
	}

	// step 15
	float float_value = 1.0;
	try
	{
		body_array->pushBack(float_value);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__UNSUPPORTED_CONVERSION)
		{
			throw "Failed at the step 15\n";
		}
	}

	// step 16
	double double_value = 1.0;
	try
	{
		body_array->pushBack(double_value);
		throw "Failed at the step 16\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__UNSUPPORTED_CONVERSION)
		{
			throw "Failed at the step 16\n";
		}
	}

	// step 17
	const char * char_value = "1";
	try
	{
		body_array->pushBack(char_value);
		throw "Failed at the step 17\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__UNSUPPORTED_CONVERSION)
		{
			throw "Failed at the step 17\n";
		}
	}

	// step 18
	try
	{
		body_array->pushBack(char_value, 1);
		throw "Failed at the step 18\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__UNSUPPORTED_CONVERSION)
		{
			throw "Failed at the step 18\n";
		}
	}

	// step 19
	try
	{
		body_array->pushTagBack();
		throw "Failed at the step 19\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_TAG)
		{
			throw "Failed at the step 19\n";
		}
	}

}

//========================================================================================================
// Test INT type for array's element - getValue
void UsdsArrayTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryArray* dict_array = 0;
	usds::UsdsArray* body_array = 0;

	dict_array = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);
	dict_array->setElementType(usds::USDS_INT);
	dict.finalizeDictionary();
	body_array = (usds::UsdsArray*)body.addTag(dict_array);

	// step 1
	try
	{
		(*body_array)[0];
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_FOUND)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2
	body_array->pushBack((int32_t)100);
	try
	{
		(bool)(*body_array)[0];
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__UNSUPPORTED_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

}