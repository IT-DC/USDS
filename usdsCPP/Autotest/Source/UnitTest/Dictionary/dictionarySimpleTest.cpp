#include "usdsAutotest.h"

#include "dictionary/usdsDictionary.h"

#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryByte.h"
#include "dictionary\dataTypes\dictionaryUByte.h"
#include "dictionary\dataTypes\dictionaryShort.h"
#include "dictionary\dataTypes\dictionaryUShort.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryUInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryFloat.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryULong.h"
#include "dictionary\dataTypes\dictionaryVarint.h"
#include "dictionary\dataTypes\dictionaryUVarint.h"


void DictionarySimpleTest::test_1()
{
	// step 1

	usds::DictionaryBoolean bool_object(0);
	if (bool_object.getType() != usds::USDS_BOOLEAN)
	{
		throw "Failed at the step 1\n";
	}

	// step 2

	usds::DictionaryDouble double_object(0);
	if (double_object.getType() != usds::USDS_DOUBLE)
	{
		throw "Failed at the step 2\n";
	}
	if (double_object.getBigendian() == true)
		throw "Failed at the step 2.1\n";
	double_object.setBigendian(true);
	if (double_object.getBigendian() == false)
		throw "Failed at the step 2.2\n";

	// step 3

	usds::DictionaryInt int_object(0);
	if (int_object.getType() != usds::USDS_INT)
	{
		throw "Failed at the step 3\n";
	}
	if (int_object.getBigendian() == true)
		throw "Failed at the step 3.1\n";
	int_object.setBigendian(true);
	if (int_object.getBigendian() == false)
		throw "Failed at the step 3.2\n";

	// step 4

	usds::DictionaryLong long_object(0);
	if (long_object.getType() != usds::USDS_LONG)
	{
		throw "Failed at the step 4\n";
	}
	if (long_object.getBigendian() == true)
		throw "Failed at the step 4.1\n";
	long_object.setBigendian(true);
	if (long_object.getBigendian() == false)
		throw "Failed at the step 4.2\n";

	// step 5

	usds::DictionaryUVarint uvarint_object(0);
	if (uvarint_object.getType() != usds::USDS_UVARINT)
	{
		throw "Failed at the step 5\n";
	}

	// step 6

	usds::DictionaryByte byte_object(0);
	if (byte_object.getType() != usds::USDS_BYTE)
	{
		throw "Failed at the step 6\n";
	}

	// step 7

	usds::DictionaryUByte ubyte_object(0);
	if (ubyte_object.getType() != usds::USDS_UBYTE)
	{
		throw "Failed at the step 7\n";
	}

	// step 8

	usds::DictionaryULong ulong_object(0);
	if (ulong_object.getType() != usds::USDS_ULONG)
	{
		throw "Failed at the step 8\n";
	}
	if (ulong_object.getBigendian() == true)
		throw "Failed at the step 8.1\n";
	ulong_object.setBigendian(true);
	if (ulong_object.getBigendian() == false)
		throw "Failed at the step 8.2\n";

	// step 9

	usds::DictionaryFloat float_object(0);
	if (float_object.getType() != usds::USDS_FLOAT)
	{
		throw "Failed at the step 9\n";
	}
	if (float_object.getBigendian() == true)
		throw "Failed at the step 9.1\n";
	float_object.setBigendian(true);
	if (float_object.getBigendian() == false)
		throw "Failed at the step 9.2\n";

	// step 10

	usds::DictionaryUInt uint_object(0);
	if (uint_object.getType() != usds::USDS_UINT)
	{
		throw "Failed at the step 10\n";
	}
	if (uint_object.getBigendian() == true)
		throw "Failed at the step 10.1\n";
	uint_object.setBigendian(true);
	if (uint_object.getBigendian() == false)
		throw "Failed at the step 10.2\n";

	// step 11

	usds::DictionaryShort short_object(0);
	if (short_object.getType() != usds::USDS_SHORT)
	{
		throw "Failed at the step 11\n";
	}
	if (short_object.getBigendian() == true)
		throw "Failed at the step 11.1\n";
	short_object.setBigendian(true);
	if (short_object.getBigendian() == false)
		throw "Failed at the step 11.2\n";


	// step 12

	usds::DictionaryUShort ushort_object(0);
	if (ushort_object.getType() != usds::USDS_USHORT)
	{
		throw "Failed at the step 12\n";
	}
	if (ushort_object.getBigendian() == true)
		throw "Failed at the step 12.1\n";
	ushort_object.setBigendian(true);
	if (ushort_object.getBigendian() == false)
		throw "Failed at the step 12.2\n";

	// step 13

	usds::DictionaryVarint varint_object(0);
	if (varint_object.getType() != usds::USDS_VARINT)
	{
		throw "Failed at the step 13\n";
	}


}


// Test for Base class - main attributes
void DictionarySimpleTest::test_2()
{
	// step 1

	usds::DictionaryBoolean bool_object(0);
	try
	{
		bool_object.initType(0, 0, "bool", 0);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_BASE_TYPE__TAG_ID_ERROR_VALUE)
		{
			throw "Failed at the step 1\n";
		}
	}

	// step 2

	try
	{
		bool_object.initType(0, 1, 0, 0);
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
		bool_object.initType(0, 1, "boolaa", 4);
		if (strcmp(bool_object.getName(), "bool") != 0 || bool_object.getNameSize() != 4)
		{
			throw "Failed at the step 3\n";
		}
	}
	catch (usds::ErrorStack)
	{
		throw "Failed at the step 3\n";
	}

	// step 4

	try
	{
		bool_object.initType(0, 1, "bool", 0);
		if (strcmp(bool_object.getName(), "bool") != 0)
		{
			throw "Failed at the step 4\n";
		}
	}
	catch (usds::ErrorStack)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	
	try
	{
		if (bool_object.getID() != 1)
		{
			throw "Failed at the step 5\n";
		}
	}
	catch (usds::ErrorStack)
	{
		throw "Failed at the step 5\n";
	}

	// step 6

	try
	{
		if (strcmp(bool_object.getTypeName(), "BOOLEAN") != 0)
		{
			throw "Failed at the step 6\n";
		}
	}
	catch (usds::ErrorStack)
	{
		throw "Failed at the step 6\n";
	}

}

// Test for Base class - navigation
void DictionarySimpleTest::test_3()
{
	// step 1

	usds::DictionaryBoolean bool_object(0);
	bool_object.initType(0, 1, "bool", 0);

	try
	{
		if (bool_object.getParent() != 0)
		{
			throw "Failed at the step 1\n";
		}
	}
	catch (usds::ErrorStack)
	{
		throw "Failed at the step 1\n";
	}

	// step 2

	usds::DictionaryInt int_object(0);
	int_object.initType(&bool_object, 2, "int", 0);

	if (int_object.getParent() != &bool_object || int_object.getPrevious() != 0 || int_object.getNext() != 0)
	{
		throw "Failed at the step 2\n";
	}

	// step 3

	int_object.setParent(0);
	int_object.setPrevious(&bool_object);
	int_object.setNext(&bool_object);

	if (int_object.getParent() != 0 || int_object.getPrevious() != &bool_object || int_object.getNext() != &bool_object)
	{
		throw "Failed at the step 3\n";
	}

}

void DictionarySimpleTest::test_4()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);

	// step 1
	try
	{
		usds::DictionaryByte* byte_object = (usds::DictionaryByte*)dict.addTag(usds::USDS_BYTE, 1, "byte", 0);
		if (byte_object->getType() != usds::USDS_BYTE)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	try
	{
		usds::DictionaryUByte* ubyte_object = (usds::DictionaryUByte*)dict.addTag(usds::USDS_UBYTE, 2, "ubyte", 0);
		if (ubyte_object->getType() != usds::USDS_UBYTE)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	}

	// step 3
	try
	{
		usds::DictionaryULong* ulong_object = (usds::DictionaryULong*)dict.addTag(usds::USDS_ULONG, 3, "ulong", 0);
		if (ulong_object->getType() != usds::USDS_ULONG)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	try
	{
		usds::DictionaryFloat* float_object = (usds::DictionaryFloat*)dict.addTag(usds::USDS_FLOAT, 4, "float", 0);
		if (float_object->getType() != usds::USDS_FLOAT)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	try
	{
		usds::DictionaryUInt* uint_object = (usds::DictionaryUInt*)dict.addTag(usds::USDS_UINT, 5, "uint", 0);
		if (uint_object->getType() != usds::USDS_UINT)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	}

	// step 6
	try
	{
		usds::DictionaryShort* short_object = (usds::DictionaryShort*)dict.addTag(usds::USDS_SHORT, 6, "short", 0);
		if (short_object->getType() != usds::USDS_SHORT)
			throw "Failed at the step 6\n";
	}
	catch (...)
	{
		throw "Failed at the step 6\n";
	}

	// step 7
	try
	{
		usds::DictionaryUShort* ushort_object = (usds::DictionaryUShort*)dict.addTag(usds::USDS_USHORT, 7, "ushort", 0);
		if (ushort_object->getType() != usds::USDS_USHORT)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		usds::DictionaryVarint* varint_object = (usds::DictionaryVarint*)dict.addTag(usds::USDS_VARINT, 8, "varint", 0);
		if (varint_object->getType() != usds::USDS_VARINT)
			throw "Failed at the step 8\n";
	}
	catch (...)
	{
		throw "Failed at the step 8\n";
	}


}