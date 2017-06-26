#include "usdsAutotest.h"

#include "body\dataTypes\usdsUByte.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryUByte.h"
#include "dictionary\usdsDictionary.h"

// Test setValue for UsdsUByteTest
void UsdsUByteTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryUByte* dict_byte = 0;
	usds::UsdsUByte* body_byte = 0;

	// step 1
	dict_byte = (usds::DictionaryUByte*)dict.addTag(usds::USDS_UBYTE, 1, "ubyte", 0);
	dict.finalizeDictionary();
	body_byte = (usds::UsdsUByte*)body.addTag(dict_byte);
	if (body_byte->getType() != usds::USDS_UBYTE)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_byte->setValue(bool_value);
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
	int8_t int8_value = 44;
	body_byte->setValue(int8_value);
	if (body_byte->getValue<int8_t>() != 44)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	int8_value = -1;
	try
	{
		body_byte->setValue(int8_value);
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
	uint8_t uint8_value = 200;
	body_byte->setValue(uint8_value);
	if (body_byte->getValue<uint8_t>() != 200)
	{
		throw "Failed at the step 5\n";
	}
	

	// step 6
	int16_t int16_value = 201;
	body_byte->setValue(int16_value);
	if (body_byte->getValue<int16_t>() != 201)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	int16_value = 1000;
	try
	{
		body_byte->setValue(int16_value);
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
	int16_value = -2;
	try
	{
		body_byte->setValue(int16_value);
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
	uint16_t uint16_value = 202;
	body_byte->setValue(uint16_value);
	if (body_byte->getValue<int16_t>() != 202)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	uint16_value = 1000;
	try
	{
		body_byte->setValue(uint16_value);
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
	int32_t int32_value = 203;
	body_byte->setValue(int32_value);
	if (body_byte->getValue<int32_t>() != 203)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	int32_value = 1000;
	try
	{
		body_byte->setValue(int32_value);
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
	int32_value = -240;
	try
	{
		body_byte->setValue(int32_value);
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
	uint32_t uint32_value = 204;
	body_byte->setValue(uint32_value);
	if (body_byte->getValue<int32_t>() != 204)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	uint32_value = 1000;
	try
	{
		body_byte->setValue(uint32_value);
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
	int64_t int64_value = 205;
	body_byte->setValue(int64_value);
	if (body_byte->getValue<int64_t>() != 205)
	{
		throw "Failed at the step 16\n";
	}

	// step 17
	int64_value = -200;
	try
	{
		body_byte->setValue(int64_value);
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
	int64_value = 300;
	try
	{
		body_byte->setValue(int64_value);
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
	uint64_t uint64_value = 206;
	body_byte->setValue(uint64_value);
	if (body_byte->getValue<uint64_t>() != 206)
	{
		throw "Failed at the step 19\n";
	}

	// step 20
	uint64_value = 300;
	try
	{
		body_byte->setValue(uint64_value);
		throw "Failed at the step 20\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 20\n";
		}
	}

	// step 21
	float float_value = 1.0;
	try
	{
		body_byte->setValue(float_value);
		throw "Failed at the step 21\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 21\n";
		}
	}

	// step 22
	double double_value = 1.0;
	try
	{
		body_byte->setValue(double_value);
		throw "Failed at the step 22\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 22\n";
		}
	}

}

// Test getValue for UsdsUByteTest
void UsdsUByteTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryUByte* dict_byte = 0;
	usds::UsdsUByte* body_byte = 0;

	// step 1
	dict_byte = (usds::DictionaryUByte*)dict.addTag(usds::USDS_UBYTE, 1, "byte", 0);
	dict.finalizeDictionary();
	body_byte = (usds::UsdsUByte*)body.addTag(dict_byte);
	if (body_byte->getType() != usds::USDS_UBYTE)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	body_byte->setValue(100);
	try
	{
		body_byte->getValue<bool>();
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
	body_byte->setValue(100);
	if (body_byte->getValue<int8_t>() != 100)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_byte->setValue(200);
	try
	{
		body_byte->getValue<int8_t>();
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
	body_byte->setValue(200);
	if (body_byte->getValue<uint8_t>() != 200)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	body_byte->setValue(200);
	if (body_byte->getValue<int16_t>() != 200)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	body_byte->setValue(201);
	if (body_byte->getValue<uint16_t>() != 201)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	body_byte->setValue(202);
	if (body_byte->getValue<int32_t>() != 202)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	body_byte->setValue(123);
	if (body_byte->getValue<int64_t>() != 123)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	body_byte->setValue(111);
	if (body_byte->getValue<uint64_t>() != 111)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	body_byte->setValue(100);
	try
	{
		body_byte->getValue<float>();
		throw "Failed at the step 11\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 11\n";
		}
	}

	// step 12
	body_byte->setValue(100);
	try
	{
		body_byte->getValue<double>();
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 12\n";
		}
	}


}