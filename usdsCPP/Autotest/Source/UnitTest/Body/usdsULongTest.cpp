#include "usdsAutotest.h"

#include "body\dataTypes\usdsULong.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryULong.h"
#include "dictionary\usdsDictionary.h"

// Test setValue for UsdsULongTest
void UsdsULongTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryULong* dict_ulong = 0;
	usds::UsdsULong* body_ulong = 0;

	// step 1
	dict_ulong = (usds::DictionaryULong*)dict.addTag(usds::USDS_ULONG, 1, "ulong", 0);
	dict.finalizeDictionary();
	body_ulong = (usds::UsdsULong*)body.addTag(dict_ulong);
	if (body_ulong->getType() != usds::USDS_ULONG)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_ulong->setValue(bool_value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	int8_t int8_value = 126;
	body_ulong->setValue(int8_value);
	if (body_ulong->getValue<int8_t>() != 126)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	int8_value = -3;
	try
	{
		body_ulong->setValue(int8_value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	uint8_t uint8_value = 255;
	body_ulong->setValue(uint8_value);
	if (body_ulong->getValue<uint8_t>() != 255)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	int16_t int16_value = 20000;
	body_ulong->setValue(int16_value);
	if (body_ulong->getValue<int16_t>() != 20000)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	int16_value = -20000;
	try
	{
		body_ulong->setValue(int16_value);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 7\n";
		}
	}

	// step 8
	uint16_t uint16_value = 60000;
	body_ulong->setValue(uint16_value);
	if (body_ulong->getValue<uint16_t>() != 60000)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	int32_t int32_value = INT32_MAX;
	body_ulong->setValue(int32_value);
	if (body_ulong->getValue<int32_t>() != INT32_MAX)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	int32_value = INT32_MIN;
	try
	{
		body_ulong->setValue(int32_value);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 10\n";
		}
	}

	// step 11
	uint32_t uint32_value = UINT32_MAX;
	body_ulong->setValue(uint32_value);
	if (body_ulong->getValue<uint32_t>() != UINT32_MAX)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	int64_t int64_value = INT64_MAX;
	body_ulong->setValue(int64_value);
	if (body_ulong->getValue<int64_t>() != INT64_MAX)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	int64_value = INT64_MIN;
	try
	{
		body_ulong->setValue(int64_value);
		throw "Failed at the step 13\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 13\n";
		}
	}

	// step 14
	uint64_t uint64_value = UINT64_MAX;
	body_ulong->setValue(uint64_value);
	if (body_ulong->getValue<uint64_t>() != UINT64_MAX)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	float float_value = 1.0;
	try
	{
		body_ulong->setValue(float_value);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 15\n";
		}
	}

	// step 16
	double double_value = 1.0;
	try
	{
		body_ulong->setValue(double_value);
		throw "Failed at the step 16\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 16\n";
		}
	}

}

// Test getValue for UsdsULongTest
void UsdsULongTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryULong* dict_ulong = 0;
	usds::UsdsULong* body_ulong = 0;

	// step 1
	dict_ulong = (usds::DictionaryULong*)dict.addTag(usds::USDS_ULONG, 1, "ulong", 0);
	dict.finalizeDictionary();
	body_ulong = (usds::UsdsULong*)body.addTag(dict_ulong);
	if (body_ulong->getType() != usds::USDS_ULONG)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	body_ulong->setValue(10);
	try
	{
		body_ulong->getValue<bool>();
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	body_ulong->setValue(127);
	if (body_ulong->getValue<int8_t>() != 127)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_ulong->setValue(128);
	try
	{
		body_ulong->getValue<int8_t>();
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	body_ulong->setValue(255);
	if (body_ulong->getValue<uint8_t>() != 255)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	body_ulong->setValue(256);
	try
	{
		body_ulong->getValue<uint8_t>();
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	body_ulong->setValue(32000);
	if (body_ulong->getValue<int16_t>() != 32000)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	body_ulong->setValue(33000);
	try
	{
		body_ulong->getValue<int16_t>();
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 8\n";
		}
	}

	// step 9
	body_ulong->setValue(65000);
	if (body_ulong->getValue<uint16_t>() != 65000)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	body_ulong->setValue(100000);
	try
	{
		body_ulong->getValue<uint16_t>();
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 10\n";
		}
	}

	// step 11
	body_ulong->setValue(INT32_MAX);
	if (body_ulong->getValue<int32_t>() != INT32_MAX)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	body_ulong->setValue(INT64_MAX);
	try
	{
		body_ulong->getValue<int32_t>();
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 12\n";
		}
	}

	// step 13
	body_ulong->setValue(INT64_MAX);
	if (body_ulong->getValue<int64_t>() != INT64_MAX)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	body_ulong->setValue(UINT64_MAX);
	try
	{
		body_ulong->getValue<int64_t>();
		throw "Failed at the step 14\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 14\n";
		}
	}

	// step 15
	body_ulong->setValue(UINT64_MAX);
	if (body_ulong->getValue<uint64_t>() != UINT64_MAX)
	{
		throw "Failed at the step 15\n";
	}

	// step 16
	body_ulong->setValue(100000);
	try
	{
		body_ulong->getValue<float>();
		throw "Failed at the step 16\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 16\n";
		}
	}

	// step 17
	body_ulong->setValue(100000);
	try
	{
		body_ulong->getValue<double>();
		throw "Failed at the step 17\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 17\n";
		}
	}

}

void UsdsULongTest::test_3()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryULong* dict_little = 0;
	usds::DictionaryULong* dict_big = 0;
	usds::UsdsULong* body_little = 0;
	usds::UsdsULong* body_big = 0;

	// step 1
	dict_little = (usds::DictionaryULong*)dict.addTag(usds::USDS_ULONG, 1, "little", 0);
	dict_big = (usds::DictionaryULong*)dict.addTag(usds::USDS_ULONG, 2, "big", 0);
	dict_big->setBigendian(true);
	dict.finalizeDictionary();
	body_little = (usds::UsdsULong*)body.addTag(dict_little);
	if (body_little->isBigendian() == true)
		throw "Failed at the step 1\n";

	// step 2
	body_big = (usds::UsdsULong*)body.addTag(dict_big);
	if (body_big->isBigendian() == false)
		throw "Failed at the step 2\n";

}
