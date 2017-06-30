#include "usdsAutotest.h"

#include "body\dataTypes\usdsShort.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryShort.h"
#include "dictionary\usdsDictionary.h"

// Test setValue for UsdsShortTest
void UsdsShortTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryShort* dict_short = 0;
	usds::UsdsShort* body_short = 0;

	// step 1
	dict_short = (usds::DictionaryShort*)dict.addTag(usds::USDS_SHORT, 1, "short", 0);
	dict.finalizeDictionary();
	body_short = (usds::UsdsShort*)body.addTag(dict_short);
	if (body_short->getType() != usds::USDS_SHORT)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_short->setValue(bool_value);
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
	int8_t int8_value = -127;
	body_short->setValue(int8_value);
	if (body_short->getValue<int8_t>() != -127)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	uint8_t uint8_value = 255;
	body_short->setValue(uint8_value);
	if (body_short->getValue<uint8_t>() != 255)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	int16_t int16_value = -10000;
	body_short->setValue(int16_value);
	if (body_short->getValue<int16_t>() != -10000)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	uint16_t uint16_value = 20000;
	body_short->setValue(uint16_value);
	if (body_short->getValue<int16_t>() != 20000)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	uint16_value = 33000;
	try
	{
		body_short->setValue(uint16_value);
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
	int32_t int32_value = INT16_MAX;
	body_short->setValue(int32_value);
	if (body_short->getValue<int32_t>() != INT16_MAX)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	int32_value = 33000;
	try
	{
		body_short->setValue(int32_value);
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
	int32_value = -33000;
	try
	{
		body_short->setValue(int32_value);
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
	uint32_t uint32_value = 32000;
	body_short->setValue(uint32_value);
	if (body_short->getValue<uint32_t>() != 32000)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	uint32_value = 33000;
	try
	{
		body_short->setValue(uint32_value);
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
	int64_t int64_value = -32000;
	body_short->setValue(int64_value);
	if (body_short->getValue<int64_t>() != -32000)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	int64_value = -33000;
	try
	{
		body_short->setValue(int64_value);
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
	int64_value = 33000;
	try
	{
		body_short->setValue(int64_value);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 15\n";
		}
	}

	// step 16
	uint64_t uint64_value = 32000;
	body_short->setValue(uint64_value);
	if (body_short->getValue<uint64_t>() != 32000)
	{
		throw "Failed at the step 16\n";
	}

	// step 17
	uint64_value = 33000;
	try
	{
		body_short->setValue(uint64_value);
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
	float float_value = 1.0;
	try
	{
		body_short->setValue(float_value);
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
	double double_value = 1.0;
	try
	{
		body_short->setValue(double_value);
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

// Test getValue for UsdsShortTest
void UsdsShortTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryShort* dict_short = 0;
	usds::UsdsShort* body_short = 0;

	// step 1
	dict_short = (usds::DictionaryShort*)dict.addTag(usds::USDS_SHORT, 1, "short", 0);
	dict.finalizeDictionary();
	body_short = (usds::UsdsShort*)body.addTag(dict_short);
	if (body_short->getType() != usds::USDS_SHORT)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	body_short->setValue(-1000);
	try
	{
		body_short->getValue<bool>();
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
	body_short->setValue(-127);
	if (body_short->getValue<int8_t>() != -127)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_short->setValue(-129);
	try
	{
		body_short->getValue<int8_t>();
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
	body_short->setValue(128);
	try
	{
		body_short->getValue<int8_t>();
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	body_short->setValue(255);
	if (body_short->getValue<uint8_t>() != 255)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	body_short->setValue(-1);
	try
	{
		body_short->getValue<uint8_t>();
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
	body_short->setValue(256);
	try
	{
		body_short->getValue<uint8_t>();
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
	body_short->setValue(-32000);
	if (body_short->getValue<int16_t>() != -32000)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	body_short->setValue(32000);
	if (body_short->getValue<uint16_t>() != 32000)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	body_short->setValue(-1);
	try
	{
		body_short->getValue<uint16_t>();
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
	body_short->setValue(32000);
	if (body_short->getValue<int32_t>() != 32000)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	body_short->setValue(32000);
	if (body_short->getValue<uint32_t>() != 32000)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	body_short->setValue(-1);
	try
	{
		body_short->getValue<uint32_t>();
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
	body_short->setValue(32000);
	if (body_short->getValue<int64_t>() != 32000)
	{
		throw "Failed at the step 15\n";
	}

	// step 16
	body_short->setValue(32000);
	if (body_short->getValue<uint64_t>() != 32000)
	{
		throw "Failed at the step 16\n";
	}

	// step 17
	body_short->setValue(-1);
	try
	{
		body_short->getValue<uint64_t>();
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
	body_short->setValue(1);
	try
	{
		body_short->getValue<float>();
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
	body_short->setValue(-1);
	try
	{
		body_short->getValue<double>();
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

void UsdsShortTest::test_3()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryShort* dict_little = 0;
	usds::DictionaryShort* dict_big = 0;
	usds::UsdsShort* body_little = 0;
	usds::UsdsShort* body_big = 0;

	// step 1
	dict_little = (usds::DictionaryShort*)dict.addTag(usds::USDS_SHORT, 1, "little", 0);
	dict_big = (usds::DictionaryShort*)dict.addTag(usds::USDS_SHORT, 2, "big", 0);
	dict_big->setBigendian(true);
	dict.finalizeDictionary();
	body_little = (usds::UsdsShort*)body.addTag(dict_little);
	if (body_little->isBigendian() == true)
		throw "Failed at the step 1\n";

	// step 2
	body_big = (usds::UsdsShort*)body.addTag(dict_big);
	if (body_big->isBigendian() == false)
		throw "Failed at the step 2\n";

}
