#include "usdsAutotest.h"

#include "dictionary\usdsDictionary.h"
#include "body\usdsBody.h"
#include "body\usdsBaseType.h"

#include "dictionary\dataTypes\dictionaryStruct.h"

#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryByte.h"
#include "dictionary\dataTypes\dictionaryUByte.h"
#include "dictionary\dataTypes\dictionaryShort.h"
#include "dictionary\dataTypes\dictionaryUShort.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryUInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryULong.h"
#include "dictionary\dataTypes\dictionaryFloat.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryVarint.h"
#include "dictionary\dataTypes\dictionaryUVarint.h"
#include "dictionary\dataTypes\dictionaryString.h"

#include "body\dataTypes\usdsStruct.h"

void UsdsStructTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryStruct* dict_struct = 0;
	usds::UsdsStruct* body_struct = 0;

	// step 1
	dict_struct = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct", 0);
	dict_struct->addField(usds::USDS_BOOLEAN, 1, "bool", 0);
	dict_struct->addField(usds::USDS_INT, 2, "int", 0);
	((usds::DictionaryString*)dict_struct->addField(usds::USDS_STRING, 3, "string", 0))->setDefaultEncode(usds::USDS_UTF8);
	dict.finalizeDictionary();
	body_struct = (usds::UsdsStruct*)body.addTag(dict_struct);
	if (body_struct->getType() != usds::USDS_STRUCT || body_struct->getFieldsNumber() != 3)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	if (body_struct->getField(1)->getType() != usds::USDS_BOOLEAN || body_struct->getField(2)->getType() != usds::USDS_INT || body_struct->getField(3)->getType() != usds::USDS_STRING)
		throw "Failed at the step 2\n";
	
	// step 3
	if (body_struct->getField("bool")->getType() != usds::USDS_BOOLEAN || body_struct->getField("int")->getType() != usds::USDS_INT || body_struct->getField("string")->getType() != usds::USDS_STRING)
		throw "Failed at the step 3\n";

	// step 4
	body_struct->setFieldValue(1, false);
	if (body_struct->getField("bool")->getValue<bool>() != false || body_struct->getFieldValue<bool>("bool") != false || body_struct->getFieldValue<bool>(1) != false)
		throw "Failed at the step 4\n";

	// step 5
	body_struct->setFieldValue("bool", true);
	if (body_struct->getField("bool")->getValue<bool>() != true || body_struct->getFieldValue<bool>("bool") != true || body_struct->getFieldValue<bool>(1) != true)
		throw "Failed at the step 4\n";

	// step 6
	body_struct->setFieldValue(2, 98765);
	if (body_struct->getField("int")->getValue<int32_t>() != 98765 || body_struct->getFieldValue<int32_t>("int") != 98765 || body_struct->getFieldValue<int32_t>(2) != 98765)
		throw "Failed at the step 6\n";

	// step 7
	body_struct->setFieldValue("int", 56789);
	if (body_struct->getField("int")->getValue<int32_t>() != 56789 || body_struct->getFieldValue<int32_t>("int") != 56789 || body_struct->getFieldValue<int32_t>(2) != 56789)
		throw "Failed at the step 7\n";

	// step 8
	body_struct->setFieldValue(3, usds::USDS_UTF8, "Hell world!");
	const char* str_value1 = 0;
	const char* str_value2 = 0;
	body_struct->getFieldValue("string", usds::USDS_UTF8, &str_value1);
	body_struct->getFieldValue(3, usds::USDS_UTF8, &str_value2);
	if (strcmp(str_value1, "Hell world!") != 0 || strcmp(str_value2, "Hell world!") != 0)
		throw "Failed at the step 8\n";

	// step 9
	body_struct->setFieldValue("string", usds::USDS_UTF8, "Not hell world!");
	str_value1 = 0;
	str_value2 = 0;
	body_struct->getFieldValue("string", usds::USDS_UTF8, &str_value1);
	body_struct->getFieldValue(3, usds::USDS_UTF8, &str_value2);
	if (strcmp(str_value1, "Not hell world!") != 0 || strcmp(str_value2, "Not hell world!") != 0)
		throw "Failed at the step 9\n";

	// step 10
	try
	{
		body_struct->setFieldValue(2, usds::USDS_UTF8, "Hell world!");
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__ERROR_FIELD_TYPE)
		{
			throw "Failed at the step 10\n";
		}
	}

	// step 11
	try
	{
		body_struct->setFieldValue("bool", usds::USDS_UTF8, "Hell world!");
		throw "Failed at the step 11\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__ERROR_FIELD_TYPE)
		{
			throw "Failed at the step 11\n";
		}
	}

	// step 12
	try
	{
		const char* value;
		body_struct->getFieldValue(2, usds::USDS_UTF8, &value);
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__ERROR_FIELD_TYPE)
		{
			throw "Failed at the step 12\n";
		}
	}

	// step 13
	try
	{
		const char* value;
		body_struct->getFieldValue("bool", usds::USDS_UTF8, &value);
		throw "Failed at the step 13\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__ERROR_FIELD_TYPE)
		{
			throw "Failed at the step 13\n";
		}
	}

	// step 14
	try
	{
		body_struct->setFieldValue(4, usds::USDS_UTF8, "Hell world!");
		throw "Failed at the step 14\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_NOT_FOUND)
		{
			throw "Failed at the step 14\n";
		}
	}

	// step 15
	try
	{
		body_struct->setFieldValue("long", usds::USDS_UTF8, "Hell world!");
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_NOT_FOUND)
		{
			throw "Failed at the step 15\n";
		}
	}

	// step 16
	try
	{
		body_struct->setFieldValue(4, false);
		throw "Failed at the step 16\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_NOT_FOUND)
		{
			throw "Failed at the step 16\n";
		}
	}

	// step 17
	try
	{
		body_struct->setFieldValue("long", false);
		throw "Failed at the step 17\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_NOT_FOUND)
		{
			throw "Failed at the step 17\n";
		}
	}

	// step 18
	try
	{
		body_struct->getFieldValue<int32_t>(4);
		throw "Failed at the step 18\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_NOT_FOUND)
		{
			throw "Failed at the step 18\n";
		}
	}

	// step 19
	try
	{
		body_struct->getFieldValue<int32_t>("long");
		throw "Failed at the step 19\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_NOT_FOUND)
		{
			throw "Failed at the step 19\n";
		}
	}
}

void UsdsStructTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryStruct* dict_struct = 0;
	usds::UsdsStruct* body_struct = 0;

	dict_struct = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct", 0);
	dict_struct->addField(usds::USDS_INT, 1, "int", 0)->setNullable(true);
	dict_struct->addField(usds::USDS_INT, 2, "int2", 0);
	dict_struct->addField(usds::USDS_BOOLEAN, 3, "boolean", 0)->setNullable(true);
	dict_struct->addField(usds::USDS_DOUBLE, 4, "double", 0)->setNullable(true);
	((usds::DictionaryString*)(dict_struct->addField(usds::USDS_STRING, 5, "string", 0)->setNullable(true)))->setDefaultEncode(usds::USDS_UTF8);
	dict.finalizeDictionary();
	body_struct = (usds::UsdsStruct*)body.addTag(dict_struct);

	// step 1
	if (body_struct->isNullValue(1) != true || body_struct->isNullValue(2) != false)
		throw "Failed at the step 1\n";

	// step 2
	if (body_struct->isNullValue("int") != true || body_struct->isNullValue("int2") != false)
		throw "Failed at the step 2\n";

	// step 3
	try
	{
		body_struct->isNullValue(6);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_NOT_FOUND)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	try
	{
		body_struct->isNullValue("int3");
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_NOT_FOUND)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	try
	{
		body_struct->setFieldAsNull(2);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__NOT_NULLABLE_FIELD)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	try
	{
		body_struct->setFieldAsNull("int2");
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__NOT_NULLABLE_FIELD)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	try
	{
		body_struct->getField("int");
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_IS_NULL)
		{
			throw "Failed at the step 7\n";
		}
	}

	// step 8
	try
	{
		body_struct->getField(1);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_IS_NULL)
		{
			throw "Failed at the step 8\n";
		}
	}

	// step 9
	try
	{
		body_struct->getFieldValue<int32_t>("int");
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_IS_NULL)
		{
			throw "Failed at the step 9\n";
		}
	}

	// step 10
	try
	{
		body_struct->getFieldValue<int64_t>("int");
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_IS_NULL)
		{
			throw "Failed at the step 10\n";
		}
	}

	// step 11
	try
	{
		body_struct->getFieldValue<double>("int");
		throw "Failed at the step 11\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_IS_NULL)
		{
			throw "Failed at the step 11\n";
		}
	}

	// step 12
	try
	{
		body_struct->getFieldValue<bool>("int");
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_IS_NULL)
		{
			throw "Failed at the step 12\n";
		}
	}

	// step 13
	try
	{
		const char* value = 0;
		body_struct->getFieldValue("int", usds::USDS_UTF8, &value);
		throw "Failed at the step 13\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__ERROR_FIELD_TYPE)
		{
			throw "Failed at the step 13\n";
		}
	}

	// step 14
	try
	{
		const char* value = 0;
		body_struct->getFieldValue("string", usds::USDS_UTF8, &value);
		throw "Failed at the step 14\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRUCT__FIELD_IS_NULL)
		{
			throw "Failed at the step 14\n";
		}
	}

	// step 15
	int32_t int_value = 123;
	body_struct->setFieldValue("int", int_value);
	if (body_struct->getFieldValue<int32_t>("int") != 123 || body_struct->isNullValue("int") == true)
		throw "Failed at the step 15\n";

	// step 16
	body_struct->setFieldAsNull("int");
	if (body_struct->isNullValue("int") == false)
		throw "Failed at the step 16\n";

	// step 16
	int_value = 1234;
	body_struct->setFieldValue(1, int_value);
	if (body_struct->getFieldValue<int32_t>(1) != 1234 || body_struct->isNullValue(1) == true)
		throw "Failed at the step 16\n";

	// step 17
	body_struct->setFieldAsNull(1);
	if (body_struct->isNullValue(1) == false)
		throw "Failed at the step 17\n";

	// step 18
	int64_t long_value = 12345;
	body_struct->setFieldValue("int", long_value);
	if (body_struct->getFieldValue<int64_t>("int") != 12345 || body_struct->isNullValue("int") == true)
		throw "Failed at the step 18\n";

	// step 19
	bool bool_value = true;
	body_struct->setFieldValue("boolean", bool_value);
	if (body_struct->getFieldValue<bool>("boolean") != true || body_struct->isNullValue("boolean") == true)
		throw "Failed at the step 19\n";

	// step 20
	body_struct->setFieldAsNull("boolean");
	if (body_struct->isNullValue("boolean") == false)
		throw "Failed at the step 20\n";

	// step 21
	bool_value = false;
	body_struct->setFieldValue(3, bool_value);
	if (body_struct->getFieldValue<bool>(3) != false || body_struct->isNullValue(3) == true)
		throw "Failed at the step 21\n";

	// step 22
	body_struct->setFieldAsNull(3);
	if (body_struct->isNullValue(3) == false)
		throw "Failed at the step 22\n";

	// step 23
	double double_value = 1.25;
	body_struct->setFieldValue("double", double_value);
	if (body_struct->getFieldValue<double>("double") != 1.25 || body_struct->isNullValue("double") == true)
		throw "Failed at the step 23\n";

	// step 24
	body_struct->setFieldAsNull("double");
	if (body_struct->isNullValue("double") == false)
		throw "Failed at the step 24\n";

	// step 25
	double_value = 1.125;
	body_struct->setFieldValue(4, double_value);
	if (body_struct->getFieldValue<double>(4) != 1.125 || body_struct->isNullValue(4) == true)
		throw "Failed at the step 25\n";

	// step 26
	body_struct->setFieldAsNull(4);
	if (body_struct->isNullValue(4) == false)
		throw "Failed at the step 26\n";

	// step 27
	const char* string_value = 0;
	body_struct->setFieldValue("string", usds::USDS_UTF8, "Hell world!");
	body_struct->getFieldValue("string", usds::USDS_UTF8, &string_value);
	if (strcmp(string_value, "Hell world!") != 0 || body_struct->isNullValue("string") == true)
		throw "Failed at the step 27\n";

	// step 28
	body_struct->setFieldAsNull("string");
	if (body_struct->isNullValue("string") == false)
		throw "Failed at the step 28\n";

	// step 29
	string_value = 0;
	body_struct->setFieldValue(5, usds::USDS_UTF8, "not hell world!");
	body_struct->getFieldValue(5, usds::USDS_UTF8, &string_value);
	if (strcmp(string_value, "not hell world!") != 0 || body_struct->isNullValue(5) == true)
		throw "Failed at the step 29\n";

	// step 30
	body_struct->setFieldAsNull(5);
	if (body_struct->isNullValue(5) == false)
		throw "Failed at the step 30\n";

}

void UsdsStructTest::test_3()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryStruct* dict_struct = 0;
	usds::UsdsStruct* body_struct = 0;

	dict_struct = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct", 0);
	usds::DictionaryBoolean* dict_bool = (usds::DictionaryBoolean*)dict_struct->addField(usds::USDS_BOOLEAN, 1, "boolean", 0);
	dict_bool->setDefaultValue(false);
	dict_bool = (usds::DictionaryBoolean*)dict_struct->addField(usds::USDS_BOOLEAN, 2, "boolean2", 0);
	dict_bool->setDefaultValue(true);
	dict_bool = (usds::DictionaryBoolean*)dict_struct->addField(usds::USDS_BOOLEAN, 3, "boolean3", 0);
	dict_bool->setDefaultValue(false);
	usds::DictionaryByte* dict_byte = (usds::DictionaryByte*)dict_struct->addField(usds::USDS_BYTE, 4, "byte", 0);
	dict_byte->setDefaultValue(-123);
	usds::DictionaryUByte* dict_ubyte = (usds::DictionaryUByte*)dict_struct->addField(usds::USDS_UBYTE, 5, "ubyte", 0);
	dict_ubyte->setDefaultValue(222);
	usds::DictionaryShort* dict_short = (usds::DictionaryShort*)dict_struct->addField(usds::USDS_SHORT, 6, "short", 0);
	dict_short->setDefaultValue(-22222);
	usds::DictionaryUShort* dict_ushort = (usds::DictionaryUShort*)dict_struct->addField(usds::USDS_USHORT, 7, "ushort", 0);
	dict_ushort->setDefaultValue(44444);
	usds::DictionaryInt* dict_int = (usds::DictionaryInt*)dict_struct->addField(usds::USDS_INT, 8, "int", 0);
	dict_int->setDefaultValue(12345678);
	usds::DictionaryUInt* dict_uint = (usds::DictionaryUInt*)dict_struct->addField(usds::USDS_UINT, 9, "uint", 0);
	dict_uint->setDefaultValue(87654321);
	usds::DictionaryLong* dict_long = (usds::DictionaryLong*)dict_struct->addField(usds::USDS_LONG, 10, "long", 0);
	dict_long->setDefaultValue(1234567890);
	usds::DictionaryULong* dict_ulong = (usds::DictionaryULong*)dict_struct->addField(usds::USDS_ULONG, 11, "ulong", 0);
	dict_ulong->setDefaultValue(12345678901);
	usds::DictionaryFloat* dict_float = (usds::DictionaryFloat*)dict_struct->addField(usds::USDS_FLOAT, 12, "float", 0);
	dict_float->setDefaultValue(1.125);
	usds::DictionaryDouble* dict_double = (usds::DictionaryDouble*)dict_struct->addField(usds::USDS_DOUBLE, 13, "double", 0);
	dict_double->setDefaultValue(-1.125);
	usds::DictionaryVarint* dict_varint = (usds::DictionaryVarint*)dict_struct->addField(usds::USDS_VARINT, 14, "varint", 0);
	dict_varint->setDefaultValue(123454321);
	usds::DictionaryUVarint* dict_uvarint = (usds::DictionaryUVarint*)dict_struct->addField(usds::USDS_UVARINT, 15, "uvarint", 0);
	dict_uvarint->setDefaultValue(1234543210);
	usds::DictionaryString* dict_string = (usds::DictionaryString*)dict_struct->addField(usds::USDS_STRING, 16, "string1", 0);
	dict_string->setDefaultEncode(usds::USDS_UTF8);
	dict_string->setDefaultValueFromUTF8("Hell world");
	dict_string = (usds::DictionaryString*)dict_struct->addField(usds::USDS_STRING, 17, "string2", 0);
	dict_string->setDefaultEncode(usds::USDS_UTF8);
	dict_string->setDefaultValueFromUTF8("Hell world", 8);
	dict_string = (usds::DictionaryString*)dict_struct->addField(usds::USDS_STRING, 18, "string3", 0);
	dict_string->setDefaultEncode(usds::USDS_UTF8);
	dict_string->setDefaultValueFromUTF8(0, 0);
	dict_string = (usds::DictionaryString*)dict_struct->addField(usds::USDS_STRING, 19, "string4", 0);
	dict_string->setDefaultValueFromUTF8("Hell world");
	
	dict.finalizeDictionary();
	body_struct = (usds::UsdsStruct*)body.addTag(dict_struct);


	// test 1
	if (body_struct->getFieldValue<bool>("boolean") != false)
		throw "Failed at the step 1\n";
	if (body_struct->getFieldValue<bool>("boolean2") != true)
		throw "Failed at the step 1\n";
	if (body_struct->getFieldValue<bool>("boolean3") != false)
		throw "Failed at the step 1\n";

	// test 2
	if (body_struct->getFieldValue<int32_t>("byte") != -123)
		throw "Failed at the step 2\n";

	// test 3
	if (body_struct->getFieldValue<int32_t>("ubyte") != 222)
		throw "Failed at the step 3\n";

	// test 4
	if (body_struct->getFieldValue<int32_t>("short") != -22222)
		throw "Failed at the step 4\n";

	// test 5
	if (body_struct->getFieldValue<int32_t>("ushort") != 44444)
		throw "Failed at the step 5\n";

	// test 6
	if (body_struct->getFieldValue<int32_t>("int") != 12345678)
		throw "Failed at the step 6\n";

	// test 7
	if (body_struct->getFieldValue<int32_t>("uint") != 87654321)
		throw "Failed at the step 7\n";
	
	// test 8
	if (body_struct->getFieldValue<int64_t>("long") != 1234567890)
		throw "Failed at the step 8\n";

	// test 9
	if (body_struct->getFieldValue<int64_t>("ulong") != 12345678901)
		throw "Failed at the step 9\n";

	// test 10
	if (body_struct->getFieldValue<double>("float") != 1.125)
		throw "Failed at the step 10\n";

	// test 11
	if (body_struct->getFieldValue<double>("double") != -1.125)
		throw "Failed at the step 11\n";

	// test 12
	if (body_struct->getFieldValue<int64_t>("varint") != 123454321)
		throw "Failed at the step 12\n";

	// test 13
	if (body_struct->getFieldValue<int64_t>("uvarint") != 1234543210)
		throw "Failed at the step 13\n";

	// test 14
	const char* string_value = 0;
	body_struct->getFieldValue("string1", usds::USDS_UTF8, &string_value);
	if (strcmp(string_value, "Hell world") != 0)
		throw "Failed at the step 14\n";

	// test 15
	string_value = 0;
	body_struct->getFieldValue("string2", usds::USDS_UTF8, &string_value);
	if (strcmp(string_value, "Hell wor") != 0)
		throw "Failed at the step 15\n";

	// test 16
	string_value = 0;
	body_struct->getFieldValue("string3", usds::USDS_UTF8, &string_value);
	if (strcmp(string_value, "") != 0)
		throw "Failed at the step 16\n";

	// test 17
	string_value = 0;
	try
	{
		body_struct->getFieldValue("string4", usds::USDS_UTF8, &string_value);
		throw "Failed at the step 17\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_STRING__NO_ENCODE)
		{
			throw "Failed at the step 17\n";
		}
	}

	// test 18
	string_value = 0;
	((usds::UsdsString*)body_struct->getField("string4"))->setEncode(usds::USDS_UTF8);
	body_struct->getFieldValue("string4", usds::USDS_UTF8, &string_value);
	if (strcmp(string_value, "Hell world") != 0)
		throw "Failed at the step 18\n";


}



