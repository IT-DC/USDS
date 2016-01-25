#include "usdsAutotest.h"
#include "unitTest\dictionary\dictionaryStructTest.h"

#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryStruct.h"

#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryString.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"

void DictionaryStructTest::runTest(int number)
{
	if (!needStart(number, UNIT_TESTS__DICTIONARY_STRUCT))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__DICTIONARY_STRING << " ------------- Dictionary Struct Class --------------\n";

	test_1();
	test_2();
	test_3();
	test_4();
};

// Test empty Structure
void DictionaryStructTest::test_1()
{
	int test_number = UNIT_TESTS__DICTIONARY_STRUCT_1;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1

	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryStruct* object = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct", 0);
	
	if (object->getType() != usds::USDS_STRUCT)
	{
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}

	// step 2

	if (object->getFirstField() != 0 || object->getLastField() != 0 || object->getFieldNumber() != 0)
	{
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}

	// step 3
	try
	{
		object->finalize();
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__NO_FIELD)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}

	// step 4
	try
	{
		object->getField(1);
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__STRUCT_IS_NOT_FINALIZED)
		{
			std::cout << "Failed at the step 4\n";
			throw test_number;
		}
	}

	// step 5
	try
	{
		object->getField((const char*)0);
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__NULL_NAME)
		{
			std::cout << "Failed at the step 5\n";
			throw test_number;
		}
	}

	// step 6
	try
	{
		object->getField("int");
		std::cout << "Failed at the step 6\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__FIELD_NOT_FOUND)
		{
			std::cout << "Failed at the step 6\n";
			throw test_number;
		}
	}

	// step 7
	try
	{
		object->getField(0, 0);
		std::cout << "Failed at the step 7\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__NULL_NAME)
		{
			std::cout << "Failed at the step 7\n";
			throw test_number;
		}
	}

	// step 8
	try
	{
		object->getField("int", 0);
		std::cout << "Failed at the step 8\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__FIELD_NOT_FOUND)
		{
			std::cout << "Failed at the step 8\n";
			throw test_number;
		}
	}

	// step 9
	try
	{
		object->findFieldID(0);
		std::cout << "Failed at the step 9\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__NULL_NAME)
		{
			std::cout << "Failed at the step 9\n";
			throw test_number;
		}
	}

	// step 10
	if (object->findFieldID("int") != 0)
	{
		std::cout << "Failed at the step 10\n";
		throw test_number;
	}

	// step 11
	try
	{
		object->findFieldID(0, 0);
		std::cout << "Failed at the step 11\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__NULL_NAME)
		{
			std::cout << "Failed at the step 11\n";
			throw test_number;
		}
	}

	// step 12
	if (object->findFieldID("int", 0) != 0)
	{
		std::cout << "Failed at the step 12\n";
		throw test_number;
	}

	std::cout << "Successful!\n";
}

// Test simple fields
void DictionaryStructTest::test_2()
{
	int test_number = UNIT_TESTS__DICTIONARY_STRUCT_2;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1

	
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryStruct* object = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct", 0);

	try
	{
		object->addField(usds::USDS_INT, 0, "int", 0);
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_BASE_TYPE__TAG_ID_ERROR_VALUE)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}

	
	// step 2
	try
	{
		object->addField(usds::USDS_INT, 1, 0, 0);
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__NULL_NAME)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}
	
	// step 3

	usds::DictionaryBoolean* field_boolean = 0;
	usds::DictionaryInt* field_int = 0;
	usds::DictionaryDouble* field_double = 0;
	usds::DictionaryString* field_string = 0;

	try
	{
		field_boolean = (usds::DictionaryBoolean*)object->addField(usds::USDS_BOOLEAN, 1, "boolean", 0);
		field_int = (usds::DictionaryInt*)object->addField(usds::USDS_INT, 2, "int", 0);
		field_double = (usds::DictionaryDouble*)object->addField(usds::USDS_DOUBLE, 3, "double", 0);
		field_string = (usds::DictionaryString*)object->addField(usds::USDS_STRING, 4, "string", 0);
		if (field_boolean == 0 || field_int == 0 || field_double == 0 || field_string == 0)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}

	// step 4
	try
	{
		object->addField(usds::USDS_INT, 5, "int", 0);
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__FIELD_ALREADY_EXISTS)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}

	// step 5
	if (object->getFirstField() != (usds::DictionaryBaseType*)field_boolean || object->getLastField() != (usds::DictionaryBaseType*)field_string || object->getFieldNumber() != 4)
	{
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}
	
	// step 6
	if (object->findFieldID("boolean") != 1 || object->findFieldID("int") != 2 || object->findFieldID("double") != 3 || object->findFieldID("string") != 4)
	{
		std::cout << "Failed at the step 6\n";
		throw test_number;
	}

	// step 7
	if (field_boolean->getNext() != field_int || field_boolean->getPrevious() != 0 || field_boolean->getParent() != object)
	{
		std::cout << "Failed at the step 7\n";
		throw test_number;
	}

	// step 8
	if (field_int->getNext() != field_double || field_int->getPrevious() != field_boolean || field_int->getParent() != object)
	{
		std::cout << "Failed at the step 8\n";
		throw test_number;
	}

	// step 9
	if (field_double->getNext() != field_string || field_double->getPrevious() != field_int || field_double->getParent() != object)
	{
		std::cout << "Failed at the step 9\n";
		throw test_number;
	}

	// step 10
	if (field_string->getNext() != 0 || field_string->getPrevious() != field_double || field_string->getParent() != object)
	{
		std::cout << "Failed at the step 10\n";
		throw test_number;
	}

	// step 11
	if (field_boolean->getType() != usds::USDS_BOOLEAN || field_int->getType() != usds::USDS_INT || field_double->getType() != usds::USDS_DOUBLE || field_string->getType() != usds::USDS_STRING)
	{
		std::cout << "Failed at the step 11\n";
		throw test_number;
	}

	// step 12
	if (object->findFieldID("intt") != 0 || object->findFieldID("intt", 0) != 0 || object->findFieldID("intt", 3) != 2)
	{
		std::cout << "Failed at the step 12\n";
		throw test_number;
	}

	// step 13
	try
	{
		if (object->getField("int") != field_int || object->getField("int", 0) != field_int || object->getField("intt", 3) != field_int)
		{
			std::cout << "Failed at the step 13\n";
			throw test_number;
		}
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 13\n";
		throw test_number;
	}


	// step 14
	try
	{
		dict.finalizeDictionary();
		std::cout << "Failed at the step 14\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRING__ERROR_ENCODE)
		{
			std::cout << "Failed at the step 14\n";
			throw test_number;
		}
	}
	
	// step 15
	try
	{
		field_string->setEncode(usds::USDS_UTF8);
		dict.finalizeDictionary();
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 15\n";
		throw test_number;
	}

	// step 16
	try
	{
		if (object->getField(1) != field_boolean || object->getField(2) != field_int || object->getField(3) != field_double || object->getField(4) != field_string)
		{
			std::cout << "Failed at the step 16\n";
			throw test_number;
		}
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 16\n";
		throw test_number;
	}


	std::cout << "Successful!\n";
}


// Test TAG fields
void DictionaryStructTest::test_3()
{
	int test_number = UNIT_TESTS__DICTIONARY_STRUCT_3;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct", 0);
	dict.addTag(usds::USDS_INT, 2, "int", 0);
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 3, "array", 0);
	array_tag->setElementType(usds::USDS_INT);
	usds::DictionaryTagLink* field_1 = (usds::DictionaryTagLink*)struct_tag->addField(usds::USDS_TAG, 1, "int_tag", 0);
	field_1->setTag(2);
	usds::DictionaryTagLink* field_2 = (usds::DictionaryTagLink*)struct_tag->addField(usds::USDS_TAG, 2, "array_tag", 0);
		
	try
	{
		dict.finalizeDictionary();
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_TAG_LINK__NOT_INITIALIZED)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}

	// step 2
	field_2->setTag(3);
	try
	{
		dict.finalizeDictionary();
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}

	// step 3

	dict.clear();
	dict.setID(1, 0, 0);
	struct_tag = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct", 0);
	field_1 = (usds::DictionaryTagLink*)struct_tag->addField(usds::USDS_TAG, 1, "tag", 0);
	field_1->setTag(1);
	try
	{
		dict.finalizeDictionary();
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__RECURSION_ERROR)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}


	std::cout << "Successful!\n";
}

// test fields errors
void DictionaryStructTest::test_4()
{
	int test_number = UNIT_TESTS__DICTIONARY_STRUCT_3;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct", 0);

	struct_tag->addField(usds::USDS_INT, 2, "int", 0);
	try
	{
		dict.finalizeDictionary();
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__FIELD_ID_ERROR_VALUE)
		{
			std::cout << "Failed at the step 1\n";
			throw test_number;
		}
	}

	// step 2
	struct_tag->addField(usds::USDS_INT, 2, "int_2", 0);
	try
	{
		dict.finalizeDictionary();
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__FIELD_ALREADY_EXISTS)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}
	
	std::cout << "Successful!\n";
}