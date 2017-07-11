#include "usdsAutotest.h"

#include "body\dataTypes\usdsVarint.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryVarint.h"
#include "dictionary\usdsDictionary.h"

// Test setValue for UsdsVarintTest
void UsdsVarintTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryVarint* dict_varint = 0;
	usds::UsdsVarint* body_varint = 0;

	// step 1
	dict_varint = (usds::DictionaryVarint*)dict.addTag(usds::USDS_VARINT, 1, "varint", 0);
	dict.finalizeDictionary();
	body_varint = (usds::UsdsVarint*)body.addTag(dict_varint);
	if (body_varint->getType() != usds::USDS_VARINT)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_varint->setValue(bool_value);
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
	int8_t int8_value = -1;
	body_varint->setValue(int8_value);
	if (body_varint->getValue<int8_t>() != -1)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	uint8_t uint8_value = 255;
	body_varint->setValue(uint8_value);
	if (body_varint->getValue<uint8_t>() != 255)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	int16_t int16_value = -10000;
	body_varint->setValue(int16_value);
	if (body_varint->getValue<int16_t>() != -10000)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	uint16_t uint16_value = 20000;
	body_varint->setValue(uint16_value);
	if (body_varint->getValue<int16_t>() != 20000)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	int32_t int32_value = -100000;
	body_varint->setValue(int32_value);
	if (body_varint->getValue<int32_t>() != -100000)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	uint32_t uint32_value = 200000;
	body_varint->setValue(uint32_value);
	if (body_varint->getValue<int32_t>() != 200000)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	int64_t int64_value = -200000;
	body_varint->setValue(int64_value);
	if (body_varint->getValue<int64_t>() != -200000)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	uint64_t uint64_value = 200000;
	body_varint->setValue(uint64_value);
	if (body_varint->getValue<uint64_t>() != 200000)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	uint64_value = UINT64_MAX;
	try
	{
		body_varint->setValue(uint64_value);
		throw "Failed at the step 11\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 11\n";
		}
	}

	// step 12
	float float_value = 1.0;
	try
	{
		body_varint->setValue(float_value);
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 12\n";
		}
	}

	// step 13
	double double_value = 1.0;
	try
	{
		body_varint->setValue(double_value);
		throw "Failed at the step 13\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 13\n";
		}
	}

}

// Test getValue for UsdsVarintTest
void UsdsVarintTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryVarint* dict_varint = 0;
	usds::UsdsVarint* body_varint = 0;

	// step 1
	dict_varint = (usds::DictionaryVarint*)dict.addTag(usds::USDS_VARINT, 1, "varint", 0);
	dict.finalizeDictionary();
	body_varint = (usds::UsdsVarint*)body.addTag(dict_varint);
	if (body_varint->getType() != usds::USDS_VARINT)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	body_varint->setValue(-100000);
	try
	{
		body_varint->getValue<bool>();
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
	body_varint->setValue(-100);
	if (body_varint->getValue<int8_t>() != -100)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_varint->setValue(-1000);
	try
	{
		body_varint->getValue<int8_t>();
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
	body_varint->setValue(200);
	if (body_varint->getValue<uint8_t>() != 200)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	body_varint->setValue(-100);
	try
	{
		body_varint->getValue<uint8_t>();
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
	body_varint->setValue(-10000);
	if (body_varint->getValue<int16_t>() != -10000)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	body_varint->setValue(-100000);
	try
	{
		body_varint->getValue<int16_t>();
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
	body_varint->setValue(100000);
	try
	{
		body_varint->getValue<int16_t>();
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 9\n";
		}
	}

	// step 10
	body_varint->setValue(30000);
	if (body_varint->getValue<uint16_t>() != 30000)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	body_varint->setValue(100000);
	try
	{
		body_varint->getValue<uint16_t>();
		throw "Failed at the step 11\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 11\n";
		}
	}

	// step 12
	body_varint->setValue(1000000);
	if (body_varint->getValue<int32_t>() != 1000000)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	body_varint->setValue(INT64_MAX);
	try
	{
		body_varint->getValue<int32_t>();
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
	body_varint->setValue(INT64_MIN);
	try
	{
		body_varint->getValue<int32_t>();
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
	body_varint->setValue(INT64_MAX);
	if (body_varint->getValue<int64_t>() != INT64_MAX)
	{
		throw "Failed at the step 15\n";
	}

	// step 16
	body_varint->setValue(INT64_MAX);
	if (body_varint->getValue<uint64_t>() != INT64_MAX)
	{
		throw "Failed at the step 16\n";
	}

	// step 17
	body_varint->setValue(-100000);
	try
	{
		body_varint->getValue<uint64_t>();
		throw "Failed at the step 17\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 17\n";
		}
	}

	// step 18
	body_varint->setValue(-100000);
	try
	{
		body_varint->getValue<float>();
		throw "Failed at the step 18\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 18\n";
		}
	}

	// step 19
	body_varint->setValue(-100000);
	try
	{
		body_varint->getValue<double>();
		throw "Failed at the step 19\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 19\n";
		}
	}

}