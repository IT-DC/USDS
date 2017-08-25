#include "usdsAutotest.h"

#include "dictionary/dataTypes/dictionaryEnum.h"
#include "dictionary/usdsDictionary.h"

#include <sstream>

void DictionaryEnumTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	

	// step 1
	usds::DictionaryEnum* object = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, 1, "enum", 0);

	if (object->getType() != usds::USDS_ENUM)
	{
		throw "Failed at the step 1\n";
	}
	
	// step 2
	if (object->isIndexed() || object->getSubtype() != usds::USDS_VARINT || object->isSubtypeBigendian() || object->hasDefaultValue())
		throw "Failed at the step 2\n";

	// step 3
	try
	{
		object->getEnumerator(1);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__ENUMERATORS_NOT_INITIALIZED)
		{
			throw "Failed at the step 3\n";

		}
	}

	// step 4
	try
	{
		object->setSubtype(usds::USDS_BOOLEAN, true);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__UNSUPPORTED_SUBTYPE)
		{
			throw "Failed at the step 4\n";

		}
	}

	// step 5
	try
	{
		object->setSubtype(usds::USDS_VARINT, true);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__UNSUPPORTED_SUBTYPE)
		{
			throw "Failed at the step 5\n";

		}
	}

	// step 6
	object->setSubtype(usds::USDS_INT, true);
	if (object->getSubtype() != usds::USDS_INT || object->isSubtypeBigendian() != true)
		throw "Failed at the step 6\n";

	// step 7
	object->setSubtype(usds::USDS_INT, false);
	if (object->getSubtype() != usds::USDS_INT || object->isSubtypeBigendian() != false)
		throw "Failed at the step 7\n";

	// step 8
	object->setDefaultValue(2);
	if (object->hasDefaultValue() != true || object->getDefaultValue() != 2)
		throw "Failed at the step 8\n";

	// step 9
	try
	{
		object->setSubtype(usds::USDS_VARINT, false);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__ENUMERATORS_ALREADY_INITIALIZED)
		{
			throw "Failed at the step 9\n";

		}
	}

	// step 10
	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__ENUMERATORS_NOT_INITIALIZED)
		{
			throw "Failed at the step 10\n";

		}
	}

	// step 11
	int64_t n = object->addEnumerator("Cpp", 0);
	if (n != 1 || strcmp(object->getEnumerator(1), "Cpp")!=0)
		throw "Failed at the step 11\n";

	// step 12
	dict.finalizeDictionary();
	if (object->isIndexed() != true)
		throw "Failed at the step 12\n";

	// step 13
	if (object->isIndexed() != true || strcmp(object->getEnumerator(1), "Cpp") != 0)
		throw "Failed at the step 13\n";

	// step 14
	try
	{
		object->setSubtype(usds::USDS_INT, false);
		throw "Failed at the step 14\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__ALREADY_FINALIZED)
		{
			throw "Failed at the step 14\n";

		}
	}

	// step 15
	try
	{
		object->setDefaultValue(3);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__ALREADY_FINALIZED)
		{
			throw "Failed at the step 15\n";

		}
	}

	// step 16
	try
	{
		object->addEnumerator("Cs", 0);
		throw "Failed at the step 16\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__ALREADY_FINALIZED)
		{
			throw "Failed at the step 16\n";

		}
	}

}

void DictionaryEnumTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::DictionaryEnum* object = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, "enum", 0);

	// step 1
	object->addEnumerator(2, "Cpp", 0);
	if (object->getEnumerator(1) != 0 || strcmp(object->getEnumerator(2), "Cpp") != 0)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	try
	{
		object->addEnumerator(2, "Cs", 0);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__NOT_UNIQUE_VALUE)
		{
			throw "Failed at the step 2\n";

		}
	}

	// step 3
	try
	{
		object->addEnumerator(1, "Cpp", 0);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__NOT_UNIQUE_NAME)
		{
			throw "Failed at the step 3\n";

		}
	}

	// step 4
	try
	{
		object->addEnumerator(1, "Cppp", 3);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__NOT_UNIQUE_NAME)
		{
			throw "Failed at the step 4\n";

		}
	}

	// step 5
	try
	{
		object->addEnumerator(1,
			"qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop"\
			"qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop"\
			"qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop"\
			"qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop"\
			"qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop"\
			"qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop"\
			, 0);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__TOO_LONG_ENUMERATOR_NAME)
		{
			throw "Failed at the step 5\n";

		}
	}

	// step 6
	try
	{
		object->addEnumerator(1,
			"qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop"\
			"qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop"\
			"qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop"\
			"qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop"\
			"qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop"\
			"qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop"\
			, 512);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__TOO_LONG_ENUMERATOR_NAME)
		{
			throw "Failed at the step 6\n";

		}
	}

	// step 7
	try
	{
		object->addEnumerator(1, 0, 3);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__NULL_NAME)
		{
			throw "Failed at the step 7\n";

		}
	}

	// step 8
	const char null_name[3] = {0, 0, 0};
	try
	{
		object->addEnumerator(1, null_name, 2);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__NULL_NAME)
		{
			throw "Failed at the step 8\n";

		}
	}

}


void DictionaryEnumTest::test_3()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::DictionaryEnum* object = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, "enum", 0);
	object->setSubtype(usds::USDS_BYTE, false);

	// step 1
	try
	{
		object->addEnumerator(128, "Cs", 0);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 1\n";

		}
	}

	// step 2
	try
	{
		object->addEnumerator(-129, "Cs", 0);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 2\n";

		}
	}

	// step 3
	object->addEnumerator(2, "V2", 0);
	object->addEnumerator(1, "V1", 0);
	try
	{
		object->addEnumerator("V3", 0);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__NOT_UNIQUE_VALUE)
		{
			throw "Failed at the step 3\n";

		}
	}

	// step 4
	object->addEnumerator(3, "V3", 0);
	object->addEnumerator(10, "V10", 0);
	int64_t n = object->addEnumerator("V11", 0);
	if (n != 11)
		throw "Failed at the step 4\n";

	// step 5
	object->addEnumerator(4, "V4", 0);
	n = object->addEnumerator("V5", 0);
	if (n != 5)
		throw "Failed at the step 4\n";

	// step 6
	if 
	(
		object->getEnumerator(-1) != 0 ||
		object->getEnumerator(0) != 0 ||
		strcmp (object->getEnumerator(1), "V1") != 0 ||
		strcmp(object->getEnumerator(2), "V2") != 0 ||
		strcmp(object->getEnumerator(3), "V3") != 0 ||
		strcmp(object->getEnumerator(4), "V4") != 0 ||
		strcmp(object->getEnumerator(5), "V5") != 0 ||
		object->getEnumerator(6) != 0 ||
		object->getEnumerator(9) != 0 ||
		strcmp(object->getEnumerator(10), "V10") != 0 ||
		strcmp(object->getEnumerator(11), "V11") != 0 ||
		object->getEnumerator(12) != 0
	)
		throw "Failed at the step 6\n";

	// step 7
	dict.finalizeDictionary();
	if (object->isIndexed() != true)
		throw "Failed at the step 7\n";

	// step 8
	if
	(
		object->getEnumerator(-1) != 0 ||
		object->getEnumerator(0) != 0 ||
		strcmp(object->getEnumerator(1), "V1") != 0 ||
		strcmp(object->getEnumerator(2), "V2") != 0 ||
		strcmp(object->getEnumerator(3), "V3") != 0 ||
		strcmp(object->getEnumerator(4), "V4") != 0 ||
		strcmp(object->getEnumerator(5), "V5") != 0 ||
		object->getEnumerator(6) != 0 ||
		object->getEnumerator(9) != 0 ||
		strcmp(object->getEnumerator(10), "V10") != 0 ||
		strcmp(object->getEnumerator(11), "V11") != 0 ||
		object->getEnumerator(12) != 0
	)
		throw "Failed at the step 8\n";

	// step 9
	if 
	(
		object->getValue("V1") != 1 ||
		object->getValue("V2") != 2 ||
		object->getValue("V3") != 3 ||
		object->getValue("V4") != 4 ||
		object->getValue("V5") != 5 ||
		object->getValue("V10") != 10 ||
		object->getValue("V11") != 11
	)
		throw "Failed at the step 9\n";

	// step 10
	if
		(
			object->getValue("V1_", 2) != 1 ||
			object->getValue("V2_", 2) != 2 ||
			object->getValue("V3_", 2) != 3 ||
			object->getValue("V4_", 2) != 4 ||
			object->getValue("V5_", 2) != 5 ||
			object->getValue("V10_", 3) != 10 ||
			object->getValue("V11_", 3) != 11
			)
		throw "Failed at the step 10\n";

	// step 11
	try
	{
		object->getValue("V6");
		throw "Failed at the step 11\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__ENUMERATOR_NOT_FOUND)
		{
			throw "Failed at the step 11\n";

		}
	}

	// step 12
	try
	{
		object->getValue("V6", 2);
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_ENUM__ENUMERATOR_NOT_FOUND)
		{
			throw "Failed at the step 12\n";

		}
	}

}

void DictionaryEnumTest::test_4()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::DictionaryEnum* object = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, "enum", 0);

	// step 1
	object->addEnumerator(-512, "Cs", 0);
	object->addEnumerator(511, "Cpp", 0);

	dict.finalizeDictionary();
	if (object->isIndexed() != true)
		throw "Failed at the step 1\n";

	// step 2
	dict.clear();
	dict.setID("name", 1, 0, 0);
	object = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, "enum", 0);

	object->addEnumerator(-512, "Cs", 0);
	object->addEnumerator(512, "Cpp", 0);

	dict.finalizeDictionary();
	if (object->isIndexed() != false)
		throw "Failed at the step 2\n";

	// step 3
	dict.clear();
	dict.setID("name", 1, 0, 0);
	object = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, "enum", 0);

	object->addEnumerator(-512, "Cs", 0);
	object->addEnumerator(512, "Cpp", 0);
	for (size_t i = 1; i < 256; i++)
	{
		std::stringstream name("V");
		name << i;
		object->addEnumerator(i, name.str().c_str(), 0);
	}

	dict.finalizeDictionary();
	if (object->isIndexed() != true)
		throw "Failed at the step 3\n";

	// step 4
	dict.clear();
	dict.setID("name", 1, 0, 0);
	object = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, "enum", 0);

	object->addEnumerator(-512, "Cs", 0);
	object->addEnumerator(516, "Cpp", 0);
	for (size_t i = 1; i < 256; i++)
	{
		std::stringstream name("V");
		name << i;
		object->addEnumerator(i, name.str().c_str(), 0);
	}

	dict.finalizeDictionary();
	if (object->isIndexed() != false)
		throw "Failed at the step 4\n";

}

void DictionaryEnumTest::test_5()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::DictionaryEnum* object = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, "enum", 0);
	object->setSubtype(usds::USDS_SHORT, false);

	object->addEnumerator(-1, "Cs", 0);
	object->addEnumerator(-1000, "Cpp", 0);
	
	// step 1
	try
	{
		object->setDefaultValue(-100000);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 1\n";

		}
	}
	
	// step 2
	object->setDefaultValue(-1000);
	dict.finalizeDictionary();
	if (object->isIndexed() != true)
		throw "Failed at the step 2\n";

	// step 3
	size_t size = 0;
	if (object->getDefaultValue() != -1000 || strcmp(object->getDefaultAsUTF8(), "Cpp") != 0 || strcmp(object->getDefaultAsUTF8(&size), "Cpp") != 0 || size != 3)
		throw "Failed at the step 3\n";

	// step 4
	if (strcmp(object->getEnumerator(-1), "Cs") != 0 || object->getValue("Cs") != -1)
		throw "Failed at the step 4\n";

	// step 5
	if (strcmp(object->getEnumerator(-1000), "Cpp") != 0 || object->getValue("Cpp") != -1000)
		throw "Failed at the step 5\n";

	// step 6
	dict.clear();
	dict.setID("name", 1, 0, 0);
	object = (usds::DictionaryEnum*)dict.addTag(usds::USDS_ENUM, "enum", 0);
	object->setSubtype(usds::USDS_SHORT, false);
	object->addEnumerator(-1, "Cs", 0);
	object->addEnumerator(-10000, "Cpp", 0);
	object->setDefaultValue(-10000);
	dict.finalizeDictionary();
	if (object->isIndexed() != false)
		throw "Failed at the step 6\n";

	// step 7
	size = 0;
	if (object->getDefaultValue() != -10000 || strcmp(object->getDefaultAsUTF8(), "Cpp") != 0 || strcmp(object->getDefaultAsUTF8(&size), "Cpp") != 0 || size != 3)
		throw "Failed at the step 7\n";

	// step 8
	if (strcmp(object->getEnumerator(-1), "Cs") != 0 || object->getValue("Cs") != -1)
		throw "Failed at the step 8\n";

	// step 9
	if (strcmp(object->getEnumerator(-10000), "Cpp") != 0 || object->getValue("Cpp") != -10000)
		throw "Failed at the step 9\n";

}

