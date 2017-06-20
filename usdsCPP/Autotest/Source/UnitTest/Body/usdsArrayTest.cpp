#include "usdsAutotest.h"

#include "body\dataTypes\usdsArray.h"
#include "body\dataTypes\usdsStruct.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryStruct.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"
#include "dictionary\usdsDictionary.h"

void UsdsArrayTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryArray* dict_array = 0;
	usds::UsdsArray* body_array = 0;
	dict_array = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);

	// step 1
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
	if (body_array->getElementType() != usds::USDS_INT)
	{
		throw "Failed at the step 2\n";
	}

	// step 3
	try
	{
		if (body_array->getSize() != 0)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	try
	{
		size_t buf_size = body_array->getBufferSize();
		body_array->setBufferSize(buf_size + 276);
		size_t new_buf_size = body_array->getBufferSize();
		if (buf_size >= new_buf_size)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	}

};

void UsdsArrayTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryArray* dict_array = 0;
	usds::UsdsArray* body_array = 0;
	dict_array = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);
	dict_array->setElementType(usds::USDS_UVARINT);
	dict.finalizeDictionary();
	body_array = (usds::UsdsArray*)body.addTag(dict_array);

	// step 1
	try
	{
		size_t buf_size = body_array->getBufferSize();
		body_array->setBufferSize(buf_size + 276);
		size_t new_buf_size = body_array->getBufferSize();
		if (buf_size >= new_buf_size)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

};

void UsdsArrayTest::test_3()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryArray* dict_array = 0;
	usds::UsdsArray* body_array = 0;
	dict_array = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);
	dict_array->setElementType(usds::USDS_UVARINT);
	dict.finalizeDictionary();
	body_array = (usds::UsdsArray*)body.addTag(dict_array);

	// step 1
	try
	{
		size_t buf_size = body_array->getBufferSize();
		body_array->setBufferSize(buf_size + 276);
		size_t new_buf_size = body_array->getBufferSize();
		if (buf_size >= new_buf_size)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

};

void UsdsArrayTest::test_4()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryArray* dict_array = 0;
	usds::UsdsArray* body_array = 0;
	dict_array = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);
	usds::DictionaryStruct* dict_element = (usds::DictionaryStruct*)dict_array->setElementType(usds::USDS_STRUCT);
	dict_element->addField(usds::USDS_INT, 1, "int", 0);
	dict.finalizeDictionary();
	body_array = (usds::UsdsArray*)body.addTag(dict_array);

	// step 1
	try
	{
		usds::UsdsStruct* element = (usds::UsdsStruct*)body_array->pushElementBack();
		if (element->getType() != usds::USDS_STRUCT || body_array->getSize() != 1 || body_array->getElementType() != usds::USDS_STRUCT)
			throw "Failed at the step 1\n";
		element->setFieldValue(1, 888);
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	try
	{
		usds::UsdsStruct* element = (usds::UsdsStruct*)body_array->pushElementBack();
		if (strcmp(element->getName(), "_array_element") != 0 || body_array->getSize() != 2)
			throw "Failed at the step 2\n";
		element->setFieldValue(1, 999);
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	}

	// step 3
	try
	{
		usds::UsdsStruct* element = (usds::UsdsStruct*)body_array->getElement(0);
		int32_t field_value = 0;
		element->getFieldValue(1, &field_value);
		if (element->getType() != usds::USDS_STRUCT || field_value != 888)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	try
	{
		usds::UsdsStruct* element = (usds::UsdsStruct*)body_array->getElement(1);
		int32_t field_value = 0;
		element->getFieldValue(1, &field_value);
		if (strcmp(element->getName(), "_array_element") != 0 || field_value != 999)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	try
	{
		body_array->getElement(2);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_FOUND)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	try
	{
		body_array->pushBack(true);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_SIMPLE)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	try
	{
		body_array->getValue<bool>(0);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_SIMPLE)
		{
			throw "Failed at the step 7\n";
		}
	}
}

void UsdsArrayTest::test_5()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryArray* dict_array = 0;
	usds::UsdsArray* body_array = 0;
	
	usds::DictionaryStruct* dict_struct = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct", 0);
	dict_struct->addField(usds::USDS_INT, 1, "int", 0);

	dict_array = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 2, "array", 0);
	usds::DictionaryTagLink* dict_tag = (usds::DictionaryTagLink*)dict_array->setElementType(usds::USDS_TAG);
	dict_tag->setTag(1);
	
	dict.finalizeDictionary();
	body_array = (usds::UsdsArray*)body.addTag(dict_array);

	// step 1
	try
	{
		usds::UsdsStruct* element = (usds::UsdsStruct*)body_array->pushElementBack();
		if (element->getType() != usds::USDS_STRUCT || element->getID() != 1 || body_array->getSize() != 1 || body_array->getElementType() != usds::USDS_STRUCT)
			throw "Failed at the step 1\n";
		element->setFieldValue(1, 888);
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	try
	{
		usds::UsdsStruct* element = (usds::UsdsStruct*)body_array->pushElementBack();
		if (strcmp(element->getName(), "struct") != 0 || body_array->getSize() != 2)
			throw "Failed at the step 2\n";
		element->setFieldValue(1, 999);
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	}

	// step 3
	try
	{
		usds::UsdsStruct* element = (usds::UsdsStruct*)body_array->getElement(0);
		int32_t field_value = 0;
		element->getFieldValue(1, &field_value);
		if (element->getType() != usds::USDS_STRUCT || field_value != 888)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	try
	{
		usds::UsdsStruct* element = (usds::UsdsStruct*)body_array->getElement(1);
		int32_t field_value = 0;
		element->getFieldValue(1, &field_value);
		if (strcmp(element->getName(), "struct") != 0 || field_value != 999)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	try
	{
		body_array->getElement(2);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_FOUND)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	try
	{
		body_array->pushBack(true);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_SIMPLE)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	try
	{
		body_array->getValue<bool>(0);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_SIMPLE)
		{
			throw "Failed at the step 7\n";
		}
	}
}

void UsdsArrayTest::test_6()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryArray* dict_array = 0;
	usds::UsdsArray* body_array = 0;

	dict.addTag(usds::USDS_INT, 1, "int", 0);
	dict_array = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 2, "array", 0);
	usds::DictionaryTagLink* dict_tag = (usds::DictionaryTagLink*)dict_array->setElementType(usds::USDS_TAG);
	dict_tag->setTag(1);

	dict.finalizeDictionary();
	body_array = (usds::UsdsArray*)body.addTag(dict_array);

	// step 0.5
	try
	{
		if (body_array->getElementType() != usds::USDS_INT || strcmp(body_array->getElementName(), "int") != 0 || body_array->getElementId() != 1)
			throw "Failed at the step 0.5\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 1
	int32_t value = 888;
	try
	{
		body_array->pushBack(value);
		value = 999;
		body_array->pushBack(value);
		if (body_array->getSize() != 2)
			throw "Failed at the step 0.5\n";
	}
	catch (...)
	{
		throw "Failed at the step 0.5\n";
	}

	// step 2
	try
	{
		body_array->pushBack(true);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (body_array->getSize() != 2 || err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
			throw "Failed at the step 2\n";
	}

	// step 3
	try
	{
		if (body_array->getValue<int32_t>(0) != 888 || body_array->getValue<int32_t>(1) != 999)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	try
	{
		body_array->pushElementBack();
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_DIFFICULT)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	try
	{
		body_array->getElement(0);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_DIFFICULT)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	try
	{
		body_array->getValue<int32_t>(2);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_FOUND)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	try
	{
		body_array->getValue<bool>(0);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 7\n";
		}
	}

}

void UsdsArrayTest::test_7()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryArray* dict_array = 0;
	usds::UsdsArray* body_array = 0;
	dict_array = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);
	dict_array->setElementType(usds::USDS_BOOLEAN);
	dict.finalizeDictionary();
	body_array = (usds::UsdsArray*)body.addTag(dict_array);

	// step 1
	try
	{
		body_array->pushBack(true);
		body_array->pushBack(false);
		if (body_array->getSize() != 2)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	try
	{
		body_array->pushBack(2);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (body_array->getSize() != 2 || err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
			throw "Failed at the step 2\n";
	}

	// step 3
	try
	{
		if (body_array->getValue<bool>(0) != true || body_array->getValue<bool>(1) != false)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	try
	{
		body_array->pushElementBack();
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_DIFFICULT)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	try
	{
		body_array->getElement(0);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_DIFFICULT)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	try
	{
		body_array->getValue<bool>(2);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_FOUND)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	try
	{
		body_array->getValue<int32_t>(0);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 7\n";
		}
	}


};

void UsdsArrayTest::test_8()
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
		int8_t value = 1;
		body_array->pushBack(value);
		if (body_array->getSize() != 1)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	try
	{
		uint8_t value = 2;
		body_array->pushBack(value);
		if (body_array->getSize() != 2)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	}

	// step 3
	try
	{
		int16_t value = 3;
		body_array->pushBack(value);
		if (body_array->getSize() != 3)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	try
	{
		uint16_t value = 4;
		body_array->pushBack(value);
		if (body_array->getSize() != 4)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	try
	{
		int32_t value = 5;
		body_array->pushBack(value);
		if (body_array->getSize() != 5)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	try
	{
		uint32_t value = 6;
		body_array->pushBack(value);
		if (body_array->getSize() != 6)
			throw "Failed at the step 6\n";
	}
	catch (...)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	try
	{
		int64_t value = 7;
		body_array->pushBack(value);
		if (body_array->getSize() != 7)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		uint64_t value = 8;
		body_array->pushBack(value);
		if (body_array->getSize() != 8)
			throw "Failed at the step 8\n";
	}
	catch (...)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		body_array->pushElementBack();
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_DIFFICULT)
		{
			throw "Failed at the step 9\n";
		}
	}

	// step 10
	try
	{
		double value = 1.25;
		body_array->pushBack(value);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 10\n";
		}
	}

	// step 11
	try
	{
		int8_t value = 0;
		body_array->getValue(7, &value);
		if (value != 8)
			throw "Failed at the step 11\n";
	}
	catch (...)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	try
	{
		uint8_t value = 0;
		body_array->getValue(6, &value);
		if (value != 7)
			throw "Failed at the step 12\n";
	}
	catch (...)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	try
	{
		int16_t value = 0;
		body_array->getValue(5, &value);
		if (value != 6)
			throw "Failed at the step 13\n";
	}
	catch (...)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	try
	{
		uint16_t value = 0;
		body_array->getValue(4, &value);
		if (value != 5)
			throw "Failed at the step 14\n";
	}
	catch (...)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	try
	{
		int32_t value = 0;
		body_array->getValue(3, &value);
		if (value != 4)
			throw "Failed at the step 15\n";
	}
	catch (...)
	{
		throw "Failed at the step 15\n";
	}

	// step 16
	try
	{
		uint32_t value = 0;
		body_array->getValue(2, &value);
		if (value != 3)
			throw "Failed at the step 16\n";
	}
	catch (...)
	{
		throw "Failed at the step 16\n";
	}

	// step 17
	try
	{
		int64_t value = 0;
		body_array->getValue(1, &value);
		if (value != 2)
			throw "Failed at the step 17\n";
	}
	catch (...)
	{
		throw "Failed at the step 17\n";
	}

	// step 18
	try
	{
		uint64_t value = 0;
		body_array->getValue(0, &value);
		if (value != 1)
			throw "Failed at the step 18\n";
	}
	catch (...)
	{
		throw "Failed at the step 18\n";
	}

	// step 19
	try
	{
		body_array->getElement(0);
		throw "Failed at the step 19\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_DIFFICULT)
		{
			throw "Failed at the step 19\n";
		}
	}

	// step 20
	try
	{
		double value = 0;
		body_array->getValue(0, &value);
		throw "Failed at the step 20\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 20\n";
		}
	}

	// step 21
	try
	{
		int32_t value = 0;
		body_array->getValue(8, &value);
		throw "Failed at the step 21\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_FOUND)
		{
			throw "Failed at the step 21\n";
		}
	}
}


void UsdsArrayTest::test_9()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryArray* dict_array = 0;
	usds::UsdsArray* body_array = 0;
	dict_array = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array", 0);
	dict_array->setElementType(usds::USDS_LONG);
	dict.finalizeDictionary();
	body_array = (usds::UsdsArray*)body.addTag(dict_array);

	// step 1
	try
	{
		int8_t value = 1;
		body_array->pushBack(value);
		if (body_array->getSize() != 1)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	try
	{
		uint8_t value = 2;
		body_array->pushBack(value);
		if (body_array->getSize() != 2)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	}

	// step 3
	try
	{
		int16_t value = 3;
		body_array->pushBack(value);
		if (body_array->getSize() != 3)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	try
	{
		uint16_t value = 4;
		body_array->pushBack(value);
		if (body_array->getSize() != 4)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	try
	{
		int32_t value = 5;
		body_array->pushBack(value);
		if (body_array->getSize() != 5)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	try
	{
		uint32_t value = 6;
		body_array->pushBack(value);
		if (body_array->getSize() != 6)
			throw "Failed at the step 6\n";
	}
	catch (...)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	try
	{
		int64_t value = 7;
		body_array->pushBack(value);
		if (body_array->getSize() != 7)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		uint64_t value = 8;
		body_array->pushBack(value);
		if (body_array->getSize() != 8)
			throw "Failed at the step 8\n";
	}
	catch (...)
	{
		throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		body_array->pushElementBack();
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_DIFFICULT)
		{
			throw "Failed at the step 9\n";
		}
	}

	// step 10
	try
	{
		double value = 1.25;
		body_array->pushBack(value);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 10\n";
		}
	}

	// step 11
	try
	{
		int8_t value = 0;
		body_array->getValue(7, &value);
		if (value != 8)
			throw "Failed at the step 11\n";
	}
	catch (...)
	{
		throw "Failed at the step 11\n";
	}

	// step 12
	try
	{
		uint8_t value = 0;
		body_array->getValue(6, &value);
		if (value != 7)
			throw "Failed at the step 12\n";
	}
	catch (...)
	{
		throw "Failed at the step 12\n";
	}

	// step 13
	try
	{
		int16_t value = 0;
		body_array->getValue(5, &value);
		if (value != 6)
			throw "Failed at the step 13\n";
	}
	catch (...)
	{
		throw "Failed at the step 13\n";
	}

	// step 14
	try
	{
		uint16_t value = 0;
		body_array->getValue(4, &value);
		if (value != 5)
			throw "Failed at the step 14\n";
	}
	catch (...)
	{
		throw "Failed at the step 14\n";
	}

	// step 15
	try
	{
		int32_t value = 0;
		body_array->getValue(3, &value);
		if (value != 4)
			throw "Failed at the step 15\n";
	}
	catch (...)
	{
		throw "Failed at the step 15\n";
	}

	// step 16
	try
	{
		uint32_t value = 0;
		body_array->getValue(2, &value);
		if (value != 3)
			throw "Failed at the step 16\n";
	}
	catch (...)
	{
		throw "Failed at the step 16\n";
	}

	// step 17
	try
	{
		int64_t value = 0;
		body_array->getValue(1, &value);
		if (value != 2)
			throw "Failed at the step 17\n";
	}
	catch (...)
	{
		throw "Failed at the step 17\n";
	}

	// step 18
	try
	{
		uint64_t value = 0;
		body_array->getValue(0, &value);
		if (value != 1)
			throw "Failed at the step 18\n";
	}
	catch (...)
	{
		throw "Failed at the step 18\n";
	}

	// step 19
	try
	{
		body_array->getElement(0);
		throw "Failed at the step 19\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_DIFFICULT)
		{
			throw "Failed at the step 19\n";
		}
	}

	// step 20
	try
	{
		double value = 0;
		body_array->getValue(0, &value);
		throw "Failed at the step 20\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 20\n";
		}
	}

	// step 21
	try
	{
		int64_t value = 0;
		body_array->getValue(8, &value);
		throw "Failed at the step 21\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_ARRAY__ELEMENT_NOT_FOUND)
		{
			throw "Failed at the step 21\n";
		}
	}
}

