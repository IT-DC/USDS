#include "usdsAutotest.h"

#include "body\dataTypes\usdsUShort.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryUShort.h"
#include "dictionary\usdsDictionary.h"

// Test setValue for UsdsUShortTest
void UsdsUShortTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryUShort* dict_ushort = 0;
	usds::UsdsUShort* body_ushort = 0;

	// step 1
	dict_ushort = (usds::DictionaryUShort*)dict.addTag(usds::USDS_USHORT, 1, "ushort", 0);
	dict.finalizeDictionary();
	body_ushort = (usds::UsdsUShort*)body.addTag(dict_ushort);
	if (body_ushort->getType() != usds::USDS_USHORT)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_ushort->setValue(bool_value);
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
	int8_t int8_value = 127;
	body_ushort->setValue(int8_value);
	if (body_ushort->getValue<int8_t>() != 127)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	int8_value = -1;
	try
	{
		body_ushort->setValue(int8_value);
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
	body_ushort->setValue(uint8_value);
	if (body_ushort->getValue<uint8_t>() != 255)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	int16_t int16_value = 32000;
	body_ushort->setValue(int16_value);
	if (body_ushort->getValue<int16_t>() != 32000)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	int16_value = -1;
	try
	{
		body_ushort->setValue(int16_value);
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
	uint16_t uint16_value = UINT16_MAX;
	body_ushort->setValue(uint16_value);
	if (body_ushort->getValue<uint16_t>() != UINT16_MAX)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	int32_t int32_value = UINT16_MAX;
	body_ushort->setValue(int32_value);
	if (body_ushort->getValue<int32_t>() != UINT16_MAX)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	int32_value = 66000;
	try
	{
		body_ushort->setValue(int32_value);
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
	int32_value = -1;
	try
	{
		body_ushort->setValue(int32_value);
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
	uint32_t uint32_value = UINT16_MAX;
	body_ushort->setValue(uint32_value);
	if (body_ushort->getValue<uint32_t>() != UINT16_MAX)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	uint32_value = 66000;
	try
	{
		body_ushort->setValue(uint32_value);
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
	int64_t int64_value = UINT16_MAX;
	body_ushort->setValue(int64_value);
	if (body_ushort->getValue<int64_t>() != UINT16_MAX)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	int64_value = -1;
	try
	{
		body_ushort->setValue(int64_value);
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
	int64_value = 66000;
	try
	{
		body_ushort->setValue(int64_value);
		throw "Failed at the step 16\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 16\n";
		}
	}

	// step 17
	uint64_t uint64_value = UINT16_MAX;
	body_ushort->setValue(uint64_value);
	if (body_ushort->getValue<uint64_t>() != UINT16_MAX)
	{
		throw "Failed at the step 17\n";
	}

	// step 18
	uint64_value = 66000;
	try
	{
		body_ushort->setValue(uint64_value);
		throw "Failed at the step 18\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 18\n";
		}
	}

	// step 19
	float float_value = 1.0;
	try
	{
		body_ushort->setValue(float_value);
		throw "Failed at the step 19\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 19\n";
		}
	}

	// step 20
	double double_value = 1.0;
	try
	{
		body_ushort->setValue(double_value);
		throw "Failed at the step 20\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 20\n";
		}
	}

}

// Test getValue for UsdsUShortTest
void UsdsUShortTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryUShort* dict_ushort = 0;
	usds::UsdsUShort* body_ushort = 0;

	// step 1
	dict_ushort = (usds::DictionaryUShort*)dict.addTag(usds::USDS_USHORT, 1, "ushort", 0);
	dict.finalizeDictionary();
	body_ushort = (usds::UsdsUShort*)body.addTag(dict_ushort);
	if (body_ushort->getType() != usds::USDS_USHORT)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	body_ushort->setValue(1);
	try
	{
		body_ushort->getValue<bool>();
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
	body_ushort->setValue(127);
	if (body_ushort->getValue<int8_t>() != 127)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_ushort->setValue(128);
	try
	{
		body_ushort->getValue<int8_t>();
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
	body_ushort->setValue(255);
	if (body_ushort->getValue<uint8_t>() != 255)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	body_ushort->setValue(256);
	try
	{
		body_ushort->getValue<uint8_t>();
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
	body_ushort->setValue(32000);
	if (body_ushort->getValue<int16_t>() != 32000)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	body_ushort->setValue(33000);
	try
	{
		body_ushort->getValue<int16_t>();
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
	body_ushort->setValue(UINT16_MAX);
	if (body_ushort->getValue<uint16_t>() != UINT16_MAX)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	body_ushort->setValue(UINT16_MAX);
	if (body_ushort->getValue<int32_t>() != UINT16_MAX)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	body_ushort->setValue(UINT16_MAX);
	if (body_ushort->getValue<uint32_t>() != UINT16_MAX)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	body_ushort->setValue(UINT16_MAX);
	if (body_ushort->getValue<int64_t>() != UINT16_MAX)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	body_ushort->setValue(UINT16_MAX);
	if (body_ushort->getValue<uint64_t>() != UINT16_MAX)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	body_ushort->setValue(1);
	try
	{
		body_ushort->getValue<float>();
		throw "Failed at the step 14\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 14\n";
		}
	}

	// step 15
	body_ushort->setValue(1);
	try
	{
		body_ushort->getValue<double>();
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 15\n";
		}
	}

}