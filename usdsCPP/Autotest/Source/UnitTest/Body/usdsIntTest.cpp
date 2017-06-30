#include "usdsAutotest.h"

#include "body\dataTypes\usdsInt.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\usdsDictionary.h"

// Test setValue for UsdsIntTest
void UsdsIntTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryInt* dict_int = 0;
	usds::UsdsInt* body_int = 0;

	// step 1
	dict_int = (usds::DictionaryInt*)dict.addTag(usds::USDS_INT, 1, "int", 0);
	dict.finalizeDictionary();
	body_int = (usds::UsdsInt*)body.addTag(dict_int);
	if (body_int->getType() != usds::USDS_INT)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_int->setValue(bool_value);
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
	body_int->setValue(int8_value);
	if (body_int->getValue<int8_t>() != -1)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	uint8_t uint8_value = 255;
	body_int->setValue(uint8_value);
	if (body_int->getValue<uint8_t>() != 255)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	int16_t int16_value = -10000;
	body_int->setValue(int16_value);
	if (body_int->getValue<int16_t>() != -10000)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	uint16_t uint16_value = 20000;
	body_int->setValue(uint16_value);
	if (body_int->getValue<int16_t>() != 20000)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	int32_t int32_value = -100000;
	body_int->setValue(int32_value);
	if (body_int->getValue<int32_t>() != -100000)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	uint32_t uint32_value = 200000;
	body_int->setValue(uint32_value);
	if (body_int->getValue<int32_t>() != 200000)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	uint32_value = (uint32_t)4294967295;
	try
	{
		body_int->setValue(uint32_value);
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
	int64_t int64_value = -200000;
	body_int->setValue(int64_value);
	if (body_int->getValue<int64_t>() != -200000)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	int64_value = -2147483649ll;
	try
	{
		body_int->setValue(int64_value);
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
	uint64_t uint64_value = 200000;
	body_int->setValue(uint64_value);
	if (body_int->getValue<uint64_t>() != 200000)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	uint64_value = 2147483649ull;
	try
	{
		body_int->setValue(uint64_value);
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
	float float_value = 1.0;
	try
	{
		body_int->setValue(float_value);
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
	double double_value = 1.0;
	try
	{
		body_int->setValue(double_value);
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
	uint32_value = 300000;
	body_int->set(uint32_value);
	if (body_int->get() != 300000)
	{
		throw "Failed at the step 16\n";
	}

}

// Test getValue for UsdsIntTest
void UsdsIntTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryInt* dict_int = 0;
	usds::UsdsInt* body_int = 0;

	// step 1
	dict_int = (usds::DictionaryInt*)dict.addTag(usds::USDS_INT, 1, "int", 0);
	dict.finalizeDictionary();
	body_int = (usds::UsdsInt*)body.addTag(dict_int);
	if (body_int->getType() != usds::USDS_INT)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	body_int->setValue(-100000);
	try
	{
		body_int->getValue<bool>();
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
	body_int->setValue(-100);
	if (body_int->getValue<int8_t>() != -100)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_int->setValue(-1000);
	try
	{
		body_int->getValue<int8_t>();
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
	body_int->setValue(200);
	if (body_int->getValue<uint8_t>() != 200)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	body_int->setValue(-100);
	try
	{
		body_int->getValue<uint8_t>();
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
	body_int->setValue(-10000);
	if (body_int->getValue<int16_t>() != -10000)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	body_int->setValue(-100000);
	try
	{
		body_int->getValue<int16_t>();
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
	body_int->setValue(30000);
	if (body_int->getValue<uint16_t>() != 30000)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	body_int->setValue(100000);
	try
	{
		body_int->getValue<uint16_t>();
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
	body_int->setValue(1000000);
	if (body_int->getValue<int32_t>() != 1000000)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	body_int->setValue(1000000);
	if (body_int->getValue<int64_t>() != 1000000)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	body_int->setValue(1000000);
	if (body_int->getValue<uint64_t>() != 1000000)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	body_int->setValue(-100000);
	try
	{
		body_int->getValue<uint64_t>();
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
	body_int->setValue(-100000);
	try
	{
		body_int->getValue<float>();
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
	body_int->setValue(-100000);
	try
	{
		body_int->getValue<double>();
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

void UsdsIntTest::test_3()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryInt* dict_little = 0;
	usds::DictionaryInt* dict_big = 0;
	usds::UsdsInt* body_little = 0;
	usds::UsdsInt* body_big = 0;

	// step 1
	dict_little = (usds::DictionaryInt*)dict.addTag(usds::USDS_INT, 1, "little", 0);
	dict_big = (usds::DictionaryInt*)dict.addTag(usds::USDS_INT, 2, "big", 0);
	dict_big->setBigendian(true);
	dict.finalizeDictionary();
	body_little = (usds::UsdsInt*)body.addTag(dict_little);
	if (body_little->isBigendian() == true)
		throw "Failed at the step 1\n";

	// step 2
	body_big = (usds::UsdsInt*)body.addTag(dict_big);
	if (body_big->isBigendian() == false)
		throw "Failed at the step 2\n";

}