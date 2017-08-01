#include "usdsAutotest.h"

#include "body\dataTypes\usdsUVarint.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryUVarint.h"
#include "dictionary\usdsDictionary.h"

// Test setValue for UsdsUVarintTest
void UsdsUVarintTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryUVarint* dict_uvarint = 0;
	usds::UsdsUVarint* body_uvarint = 0;

	// step 1
	dict_uvarint = (usds::DictionaryUVarint*)dict.addTag(usds::USDS_UVARINT, 1, "uvarint", 0);
	dict.finalizeDictionary();
	body_uvarint = (usds::UsdsUVarint*)body.addTag(dict_uvarint);
	if (body_uvarint->getType() != usds::USDS_UVARINT)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_uvarint->setValue(bool_value);
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
	body_uvarint->setValue(int8_value);
	if (body_uvarint->getValue<int8_t>() != 126)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	int8_value = -3;
	try
	{
		body_uvarint->setValue(int8_value);
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
	body_uvarint->setValue(uint8_value);
	if (body_uvarint->getValue<uint8_t>() != 255)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	int16_t int16_value = 20000;
	body_uvarint->setValue(int16_value);
	if (body_uvarint->getValue<int16_t>() != 20000)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	int16_value = -20000;
	try
	{
		body_uvarint->setValue(int16_value);
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
	body_uvarint->setValue(uint16_value);
	if (body_uvarint->getValue<uint16_t>() != 60000)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	int32_t int32_value = INT32_MAX;
	body_uvarint->setValue(int32_value);
	if (body_uvarint->getValue<int32_t>() != INT32_MAX)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	int32_value = INT32_MIN;
	try
	{
		body_uvarint->setValue(int32_value);
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
	body_uvarint->setValue(uint32_value);
	if (body_uvarint->getValue<uint32_t>() != UINT32_MAX)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	int64_t int64_value = INT64_MAX;
	body_uvarint->setValue(int64_value);
	if (body_uvarint->getValue<int64_t>() != INT64_MAX)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	int64_value = INT64_MIN;
	try
	{
		body_uvarint->setValue(int64_value);
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
	body_uvarint->setValue(uint64_value);
	if (body_uvarint->getValue<uint64_t>() != UINT64_MAX)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	float float_value = 1.0;
	try
	{
		body_uvarint->setValue(float_value);
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
		body_uvarint->setValue(double_value);
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

// Test getValue for UsdsUVarintTest
void UsdsUVarintTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryUVarint* dict_uvarint = 0;
	usds::UsdsUVarint* body_uvarint = 0;

	// step 1
	dict_uvarint = (usds::DictionaryUVarint*)dict.addTag(usds::USDS_UVARINT, 1, "uvarint", 0);
	dict.finalizeDictionary();
	body_uvarint = (usds::UsdsUVarint*)body.addTag(dict_uvarint);
	if (body_uvarint->getType() != usds::USDS_UVARINT)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	body_uvarint->setValue(10);
	try
	{
		body_uvarint->getValue<bool>();
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
	body_uvarint->setValue(127);
	if (body_uvarint->getValue<int8_t>() != 127)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_uvarint->setValue(128);
	try
	{
		body_uvarint->getValue<int8_t>();
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
	body_uvarint->setValue(255);
	if (body_uvarint->getValue<uint8_t>() != 255)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	body_uvarint->setValue(256);
	try
	{
		body_uvarint->getValue<uint8_t>();
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
	body_uvarint->setValue(32000);
	if (body_uvarint->getValue<int16_t>() != 32000)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	body_uvarint->setValue(33000);
	try
	{
		body_uvarint->getValue<int16_t>();
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
	body_uvarint->setValue(65000);
	if (body_uvarint->getValue<uint16_t>() != 65000)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	body_uvarint->setValue(100000);
	try
	{
		body_uvarint->getValue<uint16_t>();
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
	body_uvarint->setValue(INT32_MAX);
	if (body_uvarint->getValue<int32_t>() != INT32_MAX)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	body_uvarint->setValue(INT64_MAX);
	try
	{
		body_uvarint->getValue<int32_t>();
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
	body_uvarint->setValue(INT64_MAX);
	if (body_uvarint->getValue<int64_t>() != INT64_MAX)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	body_uvarint->setValue(UINT64_MAX);
	try
	{
		body_uvarint->getValue<int64_t>();
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
	body_uvarint->setValue(UINT64_MAX);
	if (body_uvarint->getValue<uint64_t>() != UINT64_MAX)
	{
		throw "Failed at the step 15\n";
	}

	// step 16
	body_uvarint->setValue(100000);
	try
	{
		body_uvarint->getValue<float>();
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
	body_uvarint->setValue(100000);
	try
	{
		body_uvarint->getValue<double>();
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