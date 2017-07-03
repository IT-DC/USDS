#include "usdsAutotest.h"


#include "dictionary\dicObjectPool.h"
#include "body\bodyObjectPool.h"
#include "dictionary\usdsDictionary.h"
#include "body\usdsBody.h"

#include "dictionary\dataTypes\dictionaryTagLink.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryString.h"
#include "dictionary\dataTypes\dictionaryUVarint.h"
#include "dictionary\dataTypes\dictionaryStruct.h"

#include "dictionary\dictionaryBaseType.h"
#include "body\dataTypes\usdsArray.h"
#include "body\dataTypes\usdsBoolean.h"
#include "body\dataTypes\usdsDouble.h"
#include "body\dataTypes\usdsInt.h"
#include "body\dataTypes\usdsLong.h"
#include "body\dataTypes\usdsString.h"
#include "body\dataTypes\usdsStruct.h"
#include "body\dataTypes\usdsUVarint.h"

void ObjectPoolTest::test_1()
{
	class testPool : public usds::BasePoolObject
	{
	public:
		testPool(testPool* parent) { value = 0; };
		~testPool() {};

		int32_t value;

	};
	usds::TemplateObjectPool<testPool, testPool> testObjects(0);
	testPool* object;
	testPool* object_4;
	testPool* object_5;

	// Step 1
	((testPool*)testObjects.addObject())->value = 1;
	((testPool*)testObjects.addObject())->value = 2;
	((testPool*)testObjects.addObject())->value = 3;
	((testPool*)testObjects.addObject())->value = 4;
	((testPool*)testObjects.addObject())->value = 5;

	object = (testPool*)testObjects.getFirstElement();
	for (int32_t i = 1; i <= 5; i++)
	{
		if (object->value != i)
		{
			throw "Failed at the step 1\n";
		}
		object = (testPool*)testObjects.getNextElement(object);
	}
	object = (testPool*)testObjects.getLastElement();
	for (int32_t i = 5; i <= 1; i--)
	{
		if (object->value != i)
		{
			throw "Failed at the step 1\n";
		}
		object = (testPool*)testObjects.getPreviousElement(object);
	}


	// Step 2
	if (testObjects.getFullSize() != 5 || testObjects.getAllocatedSize() != 5 || ((testPool*)testObjects.getLastAllocatedElement())->value != 5)
	{
		throw "Failed at the step 2\n";
	}
	testObjects.clearPool();
	if (testObjects.getFullSize() != 5 || testObjects.getAllocatedSize() != 0 || testObjects.getLastAllocatedElement()!=0)
	{
		throw "Failed at the step 2\n";
	}

	// Step 3
	for (int32_t i = 1; i <= 3; i++)
	{
		object = (testPool*)testObjects.addObject();
		if (object->value != i || ((testPool*)testObjects.getLastAllocatedElement())->value != i)
		{
			throw "Failed at the step 3\n";
		}
	}
	object_4 = (testPool*)testObjects.getNextElement(object);
	if (object_4->value != 4)
	{
		throw "Failed at the step 3\n";
	}
	if (testObjects.getFullSize() != 5 || testObjects.getAllocatedSize() != 3)
	{
		throw "Failed at the step 3\n";
	}

	// Step 4
	object_4->remove();
	object = (testPool*)testObjects.getFirstElement();
	for (int32_t i = 1; i <= 5; i++)
	{
		if (object->value != i)
		{
			throw "Failed at the step 4\n";
		}
		object = (testPool*)testObjects.getNextElement(object);
	}

	// Step 5
	object_5 = (testPool*)testObjects.getNextElement(object_4);
	object = (testPool*)testObjects.getFirstElement();
	for (int32_t i = 1; i <= 5; i++)
	{
		if (object->value != i)
		{
			throw "Failed at the step 5\n";
		}
		object = (testPool*)testObjects.getNextElement(object);
	}

	// Step 6
	object = (testPool*)testObjects.getFirstElement();
	object->remove();
	object = (testPool*)testObjects.getFirstElement();
	if (object->value!=2)
	{
		throw "Failed at the step 6\n";
	}
	for (int32_t i = 1; i <= 4; i++)
	{
		if (object->value != i+1)
		{
			throw "Failed at the step 6\n";
		}
		object = (testPool*)testObjects.getNextElement(object);
	}
	if (object->value != 1)
	{
		throw "Failed at the step 6\n";
	}

	if (testObjects.getFullSize() != 5 || testObjects.getAllocatedSize() != 2 || ((testPool*)testObjects.getLastAllocatedElement())->value != 3)
	{
		throw "Failed at the step 6\n";
	}


	// step 7
	object = (testPool*)testObjects.getFirstElement();
	object = (testPool*)testObjects.getNextElement(object);
	object->remove();
	object = (testPool*)testObjects.getFirstElement();
	if (testObjects.getPreviousElement(object) != 0)
	{
		throw "Failed at the step 7\n";
	}
	if (object->value != 2)
	{
		throw "Failed at the step 7\n";
	}
	object = (testPool*)testObjects.getNextElement(object);
	if (object->value != 4)
	{
		throw "Failed at the step 7\n";
	}
	object = (testPool*)testObjects.getNextElement(object);
	if (object->value != 5)
	{
		throw "Failed at the step 7\n";
	}
	object = (testPool*)testObjects.getNextElement(object);
	if (object->value != 1)
	{
		throw "Failed at the step 7\n";
	}
	object = (testPool*)testObjects.getNextElement(object);
	if (object->value != 3)
	{
		throw "Failed at the step 7\n";
	}
	if (testObjects.getFullSize() != 5 || testObjects.getAllocatedSize() != 1 || ((testPool*)testObjects.getLastAllocatedElement())->value != 2)
	{
		throw "Failed at the step 7\n";
	}
	if (testObjects.getNextElement(object) != 0)
	{
		throw "Failed at the step 7\n";
	}
	

	// Step 8
	object = (testPool*)testObjects.getLastElement();
	if (testObjects.getNextElement(object) != 0)
	{
		throw "Failed at the step 7\n";
	}
	if (object->value != 3)
	{
		throw "Failed at the step 8\n";
	}
	object = (testPool*)testObjects.getPreviousElement(object);
	if (object->value != 1)
	{
		throw "Failed at the step 8\n";
	}
	object = (testPool*)testObjects.getPreviousElement(object);
	if (object->value != 5)
	{
		throw "Failed at the step 8\n";
	}
	object = (testPool*)testObjects.getPreviousElement(object);
	if (object->value != 4)
	{
		throw "Failed at the step 8\n";
	}
	object = (testPool*)testObjects.getPreviousElement(object);
	if (object->value != 2)
	{
		throw "Failed at the step 8\n";
	}
	if (testObjects.getPreviousElement(object) != 0)
	{
		throw "Failed at the step 7\n";
	}

}


void ObjectPoolTest::test_2()
{
	usds::DictionaryObjectPool dic_pool(0);
	
	// step 1
	try
	{
		dic_pool.addObject(usds::USDS_NO_TYPE, 0, 0, 0, 0);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_OBJECT_POOL__UNSUPPORTED_TYPE)
		{
			throw "Failed at the step 1\n";
		}
	}
	
	// step 2
	try
	{
		dic_pool.addObject(usds::USDS_ARRAY, 0, 0, 0, 0);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_BASE_TYPE__NULL_NAME)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	try
	{
		dic_pool.addObject(usds::USDS_ARRAY, 0, 0, "name", 0);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_BASE_TYPE__TAG_ID_ERROR_VALUE)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	try
	{
		dic_pool.addObject(usds::USDS_LAST_TYPE, 0, 0, "name", 0);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_OBJECT_POOL__UNSUPPORTED_TYPE)
		{
			throw "Failed at the step 4\n";
		}
	}

}

void ObjectPoolTest::test_3()
{
	usds::BodyObjectPool body_pool(0);

	// step 1
	try
	{
		body_pool.addObject(0, 0);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_OBJECT_POOL__NULL_DICTIONARY_TAG)
		{
			throw "Failed at the step 1\n";
		}
	}

}

void ObjectPoolTest::test_4()
{
	usds::DictionaryObjectPool dic_pool(0);
	usds::BodyObjectPool body_pool(0);

	// step 1
	usds::DictionaryBoolean* dic_object = (usds::DictionaryBoolean*)dic_pool.addObject(usds::USDS_BOOLEAN, 0, 1, "boolean", 0);
	if (dic_object->getID() != 1 || dic_object->getType() != usds::USDS_BOOLEAN || strcmp(dic_object->getName(), "boolean") != 0)
	{
		throw "Failed at the step 1\n";
	}
	// step 2
	usds::UsdsBoolean* body_object = (usds::UsdsBoolean*)body_pool.addObject(dic_object, 0);
	if (body_object->getID() != 1 || body_object->getType() != usds::USDS_BOOLEAN || strcmp(body_object->getName(), "boolean") != 0)
	{
		throw "Failed at the step 2\n";
	}
	// step 3
	dic_pool.clear();
	if (dic_object != (usds::DictionaryBoolean*)dic_pool.addObject(usds::USDS_BOOLEAN, 0, 1, "boolean", 0))
	{
		throw "Failed at the step 3\n";
	}
	if (dic_object == (usds::DictionaryBoolean*)dic_pool.addObject(usds::USDS_BOOLEAN, 0, 1, "boolean", 0))
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_pool.clear();
	if (body_object != (usds::UsdsBoolean*)body_pool.addObject(dic_object, 0))
	{
		throw "Failed at the step 4\n";
	}
	if (body_object == (usds::UsdsBoolean*)body_pool.addObject(dic_object, 0))
	{
		throw "Failed at the step 4\n";
	}

}

void ObjectPoolTest::test_5()
{
	usds::DictionaryObjectPool dic_pool(0);
	usds::BodyObjectPool body_pool(0);

	// step 1
	usds::DictionaryInt* dic_object = (usds::DictionaryInt*)dic_pool.addObject(usds::USDS_INT, 0, 2, "int", 0);
	if (dic_object->getID() != 2 || dic_object->getType() != usds::USDS_INT || strcmp(dic_object->getName(), "int") != 0)
	{
		throw "Failed at the step 1\n";
	}
	// step 2
	usds::UsdsInt* body_object = (usds::UsdsInt*)body_pool.addObject(dic_object, 0);
	if (body_object->getID() != 2 || body_object->getType() != usds::USDS_INT || strcmp(body_object->getName(), "int") != 0)
	{
		throw "Failed at the step 2\n";
	}
	// step 3
	dic_pool.clear();
	if (dic_object != (usds::DictionaryInt*)dic_pool.addObject(usds::USDS_INT, 0, 1, "int", 0))
	{
		throw "Failed at the step 3\n";
	}
	if (dic_object == (usds::DictionaryInt*)dic_pool.addObject(usds::USDS_INT, 0, 1, "int", 0))
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_pool.clear();
	if (body_object != (usds::UsdsInt*)body_pool.addObject(dic_object, 0))
	{
		throw "Failed at the step 4\n";
	}
	if (body_object == (usds::UsdsInt*)body_pool.addObject(dic_object, 0))
	{
		throw "Failed at the step 4\n";
	}

}

void ObjectPoolTest::test_6()
{
	usds::DictionaryObjectPool dic_pool(0);
	usds::BodyObjectPool body_pool(0);

	// step 1
	usds::DictionaryLong* dic_object = (usds::DictionaryLong*)dic_pool.addObject(usds::USDS_LONG, 0, 3, "long", 0);
	if (dic_object->getID() != 3 || dic_object->getType() != usds::USDS_LONG || strcmp(dic_object->getName(), "long") != 0)
	{
		throw "Failed at the step 1\n";
	}
	// step 2
	usds::UsdsLong* body_object = (usds::UsdsLong*)body_pool.addObject(dic_object, 0);
	if (body_object->getID() != 3 || body_object->getType() != usds::USDS_LONG || strcmp(body_object->getName(), "long") != 0)
	{
		throw "Failed at the step 2\n";
	}
	// step 3
	dic_pool.clear();
	if (dic_object != (usds::DictionaryLong*)dic_pool.addObject(usds::USDS_LONG, 0, 1, "long", 0))
	{
		throw "Failed at the step 3\n";
	}
	if (dic_object == (usds::DictionaryLong*)dic_pool.addObject(usds::USDS_LONG, 0, 1, "long", 0))
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_pool.clear();
	if (body_object != (usds::UsdsLong*)body_pool.addObject(dic_object, 0))
	{
		throw "Failed at the step 4\n";
	}
	if (body_object == (usds::UsdsLong*)body_pool.addObject(dic_object, 0))
	{
		throw "Failed at the step 4\n";
	}

}

void ObjectPoolTest::test_7()
{
	usds::DictionaryObjectPool dic_pool(0);
	usds::BodyObjectPool body_pool(0);

	// step 1
	usds::DictionaryDouble* dic_object = (usds::DictionaryDouble*)dic_pool.addObject(usds::USDS_DOUBLE, 0, 4, "Double", 0);
	if (dic_object->getID() != 4 || dic_object->getType() != usds::USDS_DOUBLE || strcmp(dic_object->getName(), "Double") != 0)
	{
		throw "Failed at the step 1\n";
	}
	// step 2
	usds::UsdsDouble* body_object = (usds::UsdsDouble*)body_pool.addObject(dic_object, 0);
	if (body_object->getID() != 4 || body_object->getType() != usds::USDS_DOUBLE || strcmp(body_object->getName(), "Double") != 0)
	{
		throw "Failed at the step 2\n";
	}
	// step 3
	dic_pool.clear();
	if (dic_object != (usds::DictionaryDouble*)dic_pool.addObject(usds::USDS_DOUBLE, 0, 1, "Double", 0))
	{
		throw "Failed at the step 3\n";
	}
	if (dic_object == (usds::DictionaryDouble*)dic_pool.addObject(usds::USDS_DOUBLE, 0, 1, "Double", 0))
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_pool.clear();
	if (body_object != (usds::UsdsDouble*)body_pool.addObject(dic_object, 0))
	{
		throw "Failed at the step 4\n";
	}
	if (body_object == (usds::UsdsDouble*)body_pool.addObject(dic_object, 0))
	{
		throw "Failed at the step 4\n";
	}

}

void ObjectPoolTest::test_8()
{
	usds::DictionaryObjectPool dic_pool(0);
	usds::BodyObjectPool body_pool(0);

	// step 1
	usds::DictionaryUVarint* dic_object = (usds::DictionaryUVarint*)dic_pool.addObject(usds::USDS_UVARINT, 0, 5, "UVarint", 0);
	if (dic_object->getID() != 5 || dic_object->getType() != usds::USDS_UVARINT || strcmp(dic_object->getName(), "UVarint") != 0)
	{
		throw "Failed at the step 1\n";
	}
	// step 2
	usds::UsdsUVarint* body_object = (usds::UsdsUVarint*)body_pool.addObject(dic_object, 0);
	if (body_object->getID() != 5 || body_object->getType() != usds::USDS_UVARINT || strcmp(body_object->getName(), "UVarint") != 0)
	{
		throw "Failed at the step 2\n";
	}
	// step 3
	dic_pool.clear();
	if (dic_object != (usds::DictionaryUVarint*)dic_pool.addObject(usds::USDS_UVARINT, 0, 1, "UVarint", 0))
	{
		throw "Failed at the step 3\n";
	}
	if (dic_object == (usds::DictionaryUVarint*)dic_pool.addObject(usds::USDS_UVARINT, 0, 1, "UVarint", 0))
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_pool.clear();
	if (body_object != (usds::UsdsUVarint*)body_pool.addObject(dic_object, 0))
	{
		throw "Failed at the step 4\n";
	}
	if (body_object == (usds::UsdsUVarint*)body_pool.addObject(dic_object, 0))
	{
		throw "Failed at the step 4\n";
	}

}

void ObjectPoolTest::test_9()
{
	usds::DictionaryObjectPool dic_pool(0);
	usds::BodyObjectPool body_pool(0);

	// step 1
	usds::DictionaryString* dic_object = (usds::DictionaryString*)dic_pool.addObject(usds::USDS_STRING, 0, 5, "String", 0);
	dic_object->setDefaultEncode(usds::USDS_UTF8);
	if (dic_object->getID() != 5 || dic_object->getType() != usds::USDS_STRING || strcmp(dic_object->getName(), "String") != 0 || dic_object->getDefaultEncode() != usds::USDS_UTF8)
	{
		throw "Failed at the step 1\n";
	}
	// step 2
	usds::UsdsString* body_object = (usds::UsdsString*)body_pool.addObject(dic_object, 0);
	if (body_object->getID() != 5 || body_object->getType() != usds::USDS_STRING || strcmp(body_object->getName(), "String") != 0)
	{
		throw "Failed at the step 2\n";
	}
	// step 3
	dic_pool.clear();
	if (dic_object != (usds::DictionaryString*)dic_pool.addObject(usds::USDS_STRING, 0, 1, "String", 0))
	{
		throw "Failed at the step 3\n";
	}
	if (dic_object == (usds::DictionaryString*)dic_pool.addObject(usds::USDS_STRING, 0, 1, "String", 0))
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body_pool.clear();
	if (body_object != (usds::UsdsString*)body_pool.addObject(dic_object, 0))
	{
		throw "Failed at the step 4\n";
	}
	if (body_object == (usds::UsdsString*)body_pool.addObject(dic_object, 0))
	{
		throw "Failed at the step 4\n";
	}

}

void ObjectPoolTest::test_10()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;

	// step 1
	usds::DictionaryArray* dic_object = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 6, "Array", 0);
	dic_object->setElementType(usds::USDS_INT);
	if (dic_object->getID() != 6 || dic_object->getType() != usds::USDS_ARRAY || strcmp(dic_object->getName(), "Array") != 0)
	{
		throw "Failed at the step 1\n";
	}
	// step 2
	usds::UsdsArray* body_object = (usds::UsdsArray*)body.addTag(dic_object);
	if (body_object->getID() != 6 || body_object->getType() != usds::USDS_ARRAY || strcmp(body_object->getName(), "Array") != 0 || body_object->getElementType() != usds::USDS_INT)
	{
		throw "Failed at the step 2\n";
	}
	// step 3
	dict.clear();
	dict.setID(1, 0, 0);
	if (dic_object != (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "Array", 0))
	{
		throw "Failed at the step 3\n";
	}
	if (dic_object == (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "Array_2", 0))
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body.clear();
	dic_object->setElementType(usds::USDS_INT);
	if (body_object != (usds::UsdsArray*)body.addTag(dic_object))
	{
		throw "Failed at the step 4\n";
	}
	if (body_object == (usds::UsdsArray*)body.addTag(dic_object))
	{
		throw "Failed at the step 4\n";
	}

}

void ObjectPoolTest::test_11()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;

	// step 1
	usds::DictionaryStruct* dic_object = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 6, "Struct", 0);
	dic_object->addField(usds::USDS_INT, 1, "field", 0);
	dic_object->finalize();
	if (dic_object->getID() != 6 || dic_object->getType() != usds::USDS_STRUCT || strcmp(dic_object->getName(), "Struct") != 0)
	{
		throw "Failed at the step 1\n";
	}
	// step 2
	usds::UsdsStruct* body_object = (usds::UsdsStruct*)body.addTag(dic_object);
	if (body_object->getID() != 6 || body_object->getType() != usds::USDS_STRUCT || strcmp(body_object->getName(), "Struct") != 0)
	{
		throw "Failed at the step 2\n";
	}
	// step 3
	dict.clear();
	dict.setID(1, 0, 0);
	if (dic_object != (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 6, "Struct", 0))
	{
		throw "Failed at the step 3\n";
	}
	if (dic_object == (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 7, "Struct_2", 0))
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	body.clear();
	dic_object->addField(usds::USDS_INT, 1, "field", 0);
	dic_object->finalize();
	if (body_object != (usds::UsdsStruct*)body.addTag(dic_object))
	{
		throw "Failed at the step 4\n";
	}
	if (body_object == (usds::UsdsStruct*)body.addTag(dic_object))
	{
		throw "Failed at the step 4\n";
	}

}

void ObjectPoolTest::test_12()
{
	usds::DictionaryObjectPool dic_pool(0);

	// step 1
	usds::DictionaryTagLink* dic_object = (usds::DictionaryTagLink*)dic_pool.addObject(usds::USDS_TAG, 0, 1, "tag", 0);
	if (dic_object->getID() != 1 || dic_object->getType() != usds::USDS_TAG || strcmp(dic_object->getName(), "tag") != 0)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	dic_pool.clear();
	if (dic_object != (usds::DictionaryTagLink*)dic_pool.addObject(usds::USDS_TAG, 0, 1, "tag", 0))
	{
		throw "Failed at the step 2\n";
	}
	if (dic_object == (usds::DictionaryTagLink*)dic_pool.addObject(usds::USDS_TAG, 0, 1, "tag2", 0))
	{
		throw "Failed at the step 2\n";
	}

}

