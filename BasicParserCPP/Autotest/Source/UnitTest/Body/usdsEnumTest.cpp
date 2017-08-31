#include "usdsAutotest.h"

#include "dictionary\usdsDictionary.h"
#include "body/usdsBody.h"

#include "body/dataTypes/usdsEnum.h"
#include "dictionary/dataTypes/dictionaryEnum.h"

// Test setValue for UsdsEnum with Varint subtype
void UsdsEnumTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryEnum* dict_enum = 0;
	usds::UsdsEnum* body_enum = 0;

	dict_enum = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, 1, "enum", 0);
	dict_enum->addEnumerator(1, "V1", 0);
	dict_enum->addEnumerator(100, "V100", 0);
	dict.finalizeDictionary();
	body_enum = (usds::UsdsEnum*)body.addTag(dict_enum);

	// step 1
	if (body_enum->getType() != usds::USDS_ENUM || body_enum->getSubtype() != usds::USDS_VARINT || body_enum->isSubtypeBigendian() != false)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_enum->setValue(bool_value);
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
	int8_t int8_value = -128;
	body_enum->setValue(int8_value);
	if (body_enum->getValue<int8_t>() != -128)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	uint8_t uint8_value = 255;
	body_enum->setValue(uint8_value);
	if (body_enum->getValue<uint8_t>() != 255)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	int16_t int16_value = -10000;
	body_enum->setValue(int16_value);
	if (body_enum->getValue<int16_t>() != -10000)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	uint16_t uint16_value = 20000;
	body_enum->setValue(uint16_value);
	if (body_enum->getValue<int16_t>() != 20000)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	int32_t int32_value = -100000;
	body_enum->setValue(int32_value);
	if (body_enum->getValue<int32_t>() != -100000)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	uint32_t uint32_value = 200000;
	body_enum->setValue(uint32_value);
	if (body_enum->getValue<int32_t>() != 200000)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	int64_t int64_value = -200000;
	body_enum->setValue(int64_value);
	if (body_enum->getValue<int64_t>() != -200000)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	uint64_t uint64_value = 200000;
	body_enum->setValue(uint64_value);
	if (body_enum->getValue<uint64_t>() != 200000)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	uint64_value = UINT64_MAX;
	try
	{
		body_enum->setValue(uint64_value);
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
		body_enum->setValue(float_value);
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
		body_enum->setValue(double_value);
		throw "Failed at the step 13\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 13\n";
		}
	}

	// step 14
	body_enum->setFromUTF8("V1");
	if (strcmp(body_enum->getUTF8Value(), "V1") != 0 || body_enum->get() != 1)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	body_enum->setFromUTF8("V1000", 4);
	size_t size = 0;
	if (strcmp(body_enum->getUTF8Value(&size), "V100") != 0 || size != 4 || body_enum->get() != 100)
	{
		throw "Failed at the step 15\n";
	}

	// step 16
	try
	{
		body_enum->setFromUTF8("V1000");
		throw "Failed at the step 16\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__ENUMERATOR_NOT_FOUND)
		{
			throw "Failed at the step 16\n";
		}
	}

	// step 17
	try
	{
		body_enum->set(2);
		body_enum->getUTF8Value();
		throw "Failed at the step 17\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ENUM__ENUMERATOR_NOT_FOUND)
		{
			throw "Failed at the step 17\n";
		}
	}

	// step 18
	try
	{
		body_enum->set(2);
		body_enum->getUTF8Value(&size);
		throw "Failed at the step 18\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ENUM__ENUMERATOR_NOT_FOUND)
		{
			throw "Failed at the step 18\n";
		}
	}

}

// Test setValue for UsdsEnum with BYTE subtype
void UsdsEnumTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryEnum* dict_enum = 0;
	usds::UsdsEnum* body_enum = 0;

	dict_enum = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, 1, "enum", 0);
	dict_enum->setSubtype(usds::USDS_BYTE, false);
	dict_enum->addEnumerator(1, "V1", 0);
	dict_enum->addEnumerator(100, "V100", 0);
	dict.finalizeDictionary();
	body_enum = (usds::UsdsEnum*)body.addTag(dict_enum);

	// step 1
	if (body_enum->getType() != usds::USDS_ENUM || body_enum->getSubtype() != usds::USDS_BYTE || body_enum->isSubtypeBigendian() != false)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_enum->setValue(bool_value);
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
	body_enum->setValue(int8_value);
	if (body_enum->getValue<int8_t>() != -1)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	uint8_t uint8_value = 120;
	body_enum->setValue(uint8_value);
	if (body_enum->getValue<uint8_t>() != 120)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	uint8_value = 255;
	try
	{
		body_enum->setValue(uint8_value);
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
	int16_t int16_value = -10;
	body_enum->setValue(int16_value);
	if (body_enum->getValue<int16_t>() != -10)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	int16_value = 1000;
	try
	{
		body_enum->setValue(int16_value);
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
	int16_value = -240;
	try
	{
		body_enum->setValue(int16_value);
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
	uint16_t uint16_value = 121;
	body_enum->setValue(uint16_value);
	if (body_enum->getValue<int16_t>() != 121)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	uint16_value = 1000;
	try
	{
		body_enum->setValue(uint16_value);
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
	int32_t int32_value = -100;
	body_enum->setValue(int32_value);
	if (body_enum->getValue<int32_t>() != -100)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	int32_value = 1000;
	try
	{
		body_enum->setValue(int32_value);
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
		body_enum->setValue(int32_value);
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
	uint32_t uint32_value = 122;
	body_enum->setValue(uint32_value);
	if (body_enum->getValue<int32_t>() != 122)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	uint32_value = 1000;
	try
	{
		body_enum->setValue(uint32_value);
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
	int64_t int64_value = -101;
	body_enum->setValue(int64_value);
	if (body_enum->getValue<int64_t>() != -101)
	{
		throw "Failed at the step 16\n";
	}

	// step 17
	int64_value = -200;
	try
	{
		body_enum->setValue(int64_value);
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
	int64_value = 200;
	try
	{
		body_enum->setValue(int64_value);
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
	uint64_t uint64_value = 13;
	body_enum->setValue(uint64_value);
	if (body_enum->getValue<uint64_t>() != 13)
	{
		throw "Failed at the step 19\n";
	}

	// step 20
	uint64_value = 200;
	try
	{
		body_enum->setValue(uint64_value);
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
		body_enum->setValue(float_value);
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
		body_enum->setValue(double_value);
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

// Test setValue for UsdsEnum with UINT subtype
void UsdsEnumTest::test_3()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryEnum* dict_enum = 0;
	usds::UsdsEnum* body_enum = 0;

	dict_enum = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, 1, "enum", 0);
	dict_enum->setSubtype(usds::USDS_UINT, false);
	dict_enum->addEnumerator(1, "V1", 0);
	dict_enum->addEnumerator(100, "V100", 0);
	dict.finalizeDictionary();
	body_enum = (usds::UsdsEnum*)body.addTag(dict_enum);

	// step 1
	if (body_enum->getType() != usds::USDS_ENUM || body_enum->getSubtype() != usds::USDS_UINT || body_enum->isSubtypeBigendian() != false)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_enum->setValue(bool_value);
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
	body_enum->setValue(int8_value);
	if (body_enum->getValue<int8_t>() != 127)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	int8_value = -128;
	try
	{
		body_enum->setValue(int8_value);
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
	body_enum->setValue(uint8_value);
	if (body_enum->getValue<uint8_t>() != 255)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	int16_t int16_value = 20000;
	body_enum->setValue(int16_value);
	if (body_enum->getValue<int16_t>() != 20000)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	int16_value = -20000;
	try
	{
		body_enum->setValue(int16_value);
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
	body_enum->setValue(uint16_value);
	if (body_enum->getValue<uint16_t>() != 60000)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	int32_t int32_value = INT32_MAX;
	body_enum->setValue(int32_value);
	if (body_enum->getValue<int32_t>() != INT32_MAX)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	int32_value = INT32_MIN;
	try
	{
		body_enum->setValue(int32_value);
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
	body_enum->setValue(uint32_value);
	if (body_enum->getValue<uint32_t>() != UINT32_MAX)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	int64_t int64_value = UINT32_MAX;
	body_enum->setValue(int64_value);
	if (body_enum->getValue<int64_t>() != UINT32_MAX)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	int64_value = INT64_MIN;
	try
	{
		body_enum->setValue(int64_value);
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
	uint64_t uint64_value = UINT32_MAX;
	body_enum->setValue(uint64_value);
	if (body_enum->getValue<uint64_t>() != UINT32_MAX)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	uint64_value = UINT64_MAX;
	try
	{
		body_enum->setValue(uint64_value);
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
	float float_value = 1.0;
	try
	{
		body_enum->setValue(float_value);
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
	double double_value = 1.0;
	try
	{
		body_enum->setValue(double_value);
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

// Test getValue for UsdsEnum with Varint subtype
void UsdsEnumTest::test_4()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryEnum* dict_enum = 0;
	usds::UsdsEnum* body_enum = 0;

	dict_enum = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, 1, "enum", 0);
	dict_enum->addEnumerator(1, "V1", 0);
	dict_enum->addEnumerator(100, "V100", 0);
	dict.finalizeDictionary();
	body_enum = (usds::UsdsEnum*)body.addTag(dict_enum);
	
	// step 1
	if (body_enum->getType() != usds::USDS_ENUM || body_enum->getSubtype() != usds::USDS_VARINT || body_enum->isSubtypeBigendian() != false)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	body_enum->setValue(-100000);
	try
	{
		body_enum->getValue<bool>();
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
	body_enum->setValue(-100);
	if (body_enum->getValue<int8_t>() != -100)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_enum->setValue(-1000);
	try
	{
		body_enum->getValue<int8_t>();
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
	body_enum->setValue(200);
	if (body_enum->getValue<uint8_t>() != 200)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	body_enum->setValue(-100);
	try
	{
		body_enum->getValue<uint8_t>();
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
	body_enum->setValue(-10000);
	if (body_enum->getValue<int16_t>() != -10000)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	body_enum->setValue(-100000);
	try
	{
		body_enum->getValue<int16_t>();
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
	body_enum->setValue(100000);
	try
	{
		body_enum->getValue<int16_t>();
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
	body_enum->setValue(30000);
	if (body_enum->getValue<uint16_t>() != 30000)
	{
		throw "Failed at the step 10\n";
	}

	// step 11
	body_enum->setValue(100000);
	try
	{
		body_enum->getValue<uint16_t>();
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
	body_enum->setValue(1000000);
	if (body_enum->getValue<int32_t>() != 1000000)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	body_enum->setValue(INT64_MAX);
	try
	{
		body_enum->getValue<int32_t>();
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
	body_enum->setValue(INT64_MIN);
	try
	{
		body_enum->getValue<int32_t>();
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
	body_enum->setValue(INT64_MAX);
	if (body_enum->getValue<int64_t>() != INT64_MAX)
	{
		throw "Failed at the step 15\n";
	}

	// step 16
	body_enum->setValue(INT64_MAX);
	if (body_enum->getValue<uint64_t>() != INT64_MAX)
	{
		throw "Failed at the step 16\n";
	}

	// step 17
	body_enum->setValue(-100000);
	try
	{
		body_enum->getValue<uint64_t>();
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
	body_enum->setValue(-100000);
	try
	{
		body_enum->getValue<float>();
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
	body_enum->setValue(-100000);
	try
	{
		body_enum->getValue<double>();
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

// Test getValue for UsdsEnum with BYTE subtype
void UsdsEnumTest::test_5()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryEnum* dict_enum = 0;
	usds::UsdsEnum* body_enum = 0;

	dict_enum = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, 1, "enum", 0);
	dict_enum->setSubtype(usds::USDS_BYTE, false);
	dict_enum->addEnumerator(1, "V1", 0);
	dict_enum->addEnumerator(100, "V100", 0);
	dict.finalizeDictionary();
	body_enum = (usds::UsdsEnum*)body.addTag(dict_enum);

	// step 1
	if (body_enum->getType() != usds::USDS_ENUM || body_enum->getSubtype() != usds::USDS_BYTE || body_enum->isSubtypeBigendian() != false)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	body_enum->setValue(-100);
	try
	{
		body_enum->getValue<bool>();
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
	if (body_enum->getValue<int8_t>() != -100)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_enum->setValue(20);
	if (body_enum->getValue<uint8_t>() != 20)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	body_enum->setValue(-100);
	try
	{
		body_enum->getValue<uint8_t>();
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
	body_enum->setValue(-100);
	if (body_enum->getValue<int16_t>() != -100)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	body_enum->setValue(20);
	if (body_enum->getValue<uint16_t>() != 20)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	body_enum->setValue(-10);
	try
	{
		body_enum->getValue<uint16_t>();
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
	body_enum->setValue(100);
	if (body_enum->getValue<int32_t>() != 100)
	{
		throw "Failed at the step 11\n";
	}

	// step 10
	body_enum->setValue(-10);
	try
	{
		body_enum->getValue<uint32_t>();
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
	body_enum->setValue(123);
	if (body_enum->getValue<int64_t>() != 123)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	body_enum->setValue(111);
	if (body_enum->getValue<uint64_t>() != 111)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	body_enum->setValue(-10);
	try
	{
		body_enum->getValue<uint64_t>();
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
	body_enum->setValue(-100);
	try
	{
		body_enum->getValue<float>();
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
	body_enum->setValue(-100);
	try
	{
		body_enum->getValue<double>();
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

// Test getValue for UsdsEnum with UINT subtype
void UsdsEnumTest::test_6()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryEnum* dict_enum = 0;
	usds::UsdsEnum* body_enum = 0;

	dict_enum = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, 1, "enum", 0);
	dict_enum->setSubtype(usds::USDS_UINT, false);
	dict_enum->addEnumerator(1, "V1", 0);
	dict_enum->addEnumerator(100, "V100", 0);
	dict.finalizeDictionary();
	body_enum = (usds::UsdsEnum*)body.addTag(dict_enum);

	// step 1
	if (body_enum->getType() != usds::USDS_ENUM || body_enum->getSubtype() != usds::USDS_UINT || body_enum->isSubtypeBigendian() != false)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	body_enum->setValue(10);
	try
	{
		body_enum->getValue<bool>();
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
	body_enum->setValue(127);
	if (body_enum->getValue<int8_t>() != 127)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_enum->setValue(128);
	try
	{
		body_enum->getValue<int8_t>();
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
	body_enum->setValue(255);
	if (body_enum->getValue<uint8_t>() != 255)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	body_enum->setValue(256);
	try
	{
		body_enum->getValue<uint8_t>();
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
	body_enum->setValue(32000);
	if (body_enum->getValue<int16_t>() != 32000)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	body_enum->setValue(33000);
	try
	{
		body_enum->getValue<int16_t>();
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
	body_enum->setValue(65000);
	if (body_enum->getValue<uint16_t>() != 65000)
	{
		throw "Failed at the step 9\n";
	}

	// step 10
	body_enum->setValue(100000);
	try
	{
		body_enum->getValue<uint16_t>();
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
	body_enum->setValue(INT32_MAX);
	if (body_enum->getValue<int32_t>() != INT32_MAX)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	body_enum->setValue(UINT32_MAX);
	try
	{
		body_enum->getValue<int32_t>();
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
	body_enum->setValue(UINT32_MAX);
	if (body_enum->getValue<int64_t>() != UINT32_MAX)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	body_enum->setValue(UINT32_MAX);
	if (body_enum->getValue<uint64_t>() != UINT32_MAX)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	body_enum->setValue(100000);
	try
	{
		body_enum->getValue<float>();
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
	body_enum->setValue(100000);
	try
	{
		body_enum->getValue<double>();
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

// Test negative text values, indexed
void UsdsEnumTest::test_7()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryEnum* dict_enum = 0;
	usds::UsdsEnum* body_enum = 0;

	dict_enum = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, 1, "enum", 0);
	dict_enum->setSubtype(usds::USDS_SHORT, false);
	dict_enum->addEnumerator(-1, "V1", 0);
	dict_enum->addEnumerator(-1000, "V1000", 0);
	dict.finalizeDictionary();
	body_enum = (usds::UsdsEnum*)body.addTag(dict_enum);

	// test 1
	body_enum->setFromUTF8("V1");
	size_t size = 0;
	if (body_enum->getValue<int16_t>() != -1 || strcmp(body_enum->getUTF8Value(), "V1") !=0 || strcmp(body_enum->getUTF8Value(&size), "V1") != 0 || size != 2)
	{
		throw "Failed at the step 1\n";
	}

	// test 2
	body_enum->setFromUTF8("V1000");
	size = 0;
	if (body_enum->getValue<int16_t>() != -1000 || strcmp(body_enum->getUTF8Value(), "V1000") != 0 || strcmp(body_enum->getUTF8Value(&size), "V1000") != 0 || size != 5)
	{
		throw "Failed at the step 2\n";
	}
	
}

// Test negative text values, not indexed
void UsdsEnumTest::test_8()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryEnum* dict_enum = 0;
	usds::UsdsEnum* body_enum = 0;

	dict_enum = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, 1, "enum", 0);
	dict_enum->setSubtype(usds::USDS_SHORT, false);
	dict_enum->addEnumerator(-1, "V1", 0);
	dict_enum->addEnumerator(-10000, "V10000", 0);
	dict_enum->addEnumerator(10000, "Vp10000", 0);
	dict_enum->addEnumerator(1, "Vp1", 0);
	dict.finalizeDictionary();
	body_enum = (usds::UsdsEnum*)body.addTag(dict_enum);

	// test 1
	body_enum->setFromUTF8("V1");
	size_t size = 0;
	if (body_enum->getValue<int16_t>() != -1 || strcmp(body_enum->getUTF8Value(), "V1") != 0 || strcmp(body_enum->getUTF8Value(&size), "V1") != 0 || size != 2)
	{
		throw "Failed at the step 1\n";
	}

	// test 2
	body_enum->setFromUTF8("V10000");
	size = 0;
	if (body_enum->getValue<int16_t>() != -10000 || strcmp(body_enum->getUTF8Value(), "V10000") != 0 || strcmp(body_enum->getUTF8Value(&size), "V10000") != 0 || size != 6)
	{
		throw "Failed at the step 2\n";
	}

	// test 3
	body_enum->setFromUTF8("Vp1");
	size = 0;
	if (body_enum->getValue<int16_t>() != 1 || strcmp(body_enum->getUTF8Value(), "Vp1") != 0 || strcmp(body_enum->getUTF8Value(&size), "Vp1") != 0 || size != 3)
	{
		throw "Failed at the step 3\n";
	}

	// test 4
	body_enum->setFromUTF8("Vp10000");
	size = 0;
	if (body_enum->getValue<int16_t>() != 10000 || strcmp(body_enum->getUTF8Value(), "Vp10000") != 0 || strcmp(body_enum->getUTF8Value(&size), "Vp10000") != 0 || size != 7)
	{
		throw "Failed at the step 4\n";
	}

}

