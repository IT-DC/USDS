#include "usdsAutotest.h"

#include "body\dataTypes\usdsBoolean.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\usdsDictionary.h"

void UsdsBooleanTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryBoolean* dict_boolean = 0;
	usds::UsdsBoolean* body_boolean = 0;

	// step 1
	dict_boolean = (usds::DictionaryBoolean*)dict.addTag(usds::USDS_BOOLEAN, 1, "boolean", 0);
	dict.finalizeDictionary();
	body_boolean = (usds::UsdsBoolean*)body.addTag(dict_boolean);
	if (body_boolean->getType() != usds::USDS_BOOLEAN)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_boolean->setValue(bool_value);
		if (body_boolean->getValue<bool>() != true)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	}

	// step 3
	int32_t int_value = 1000;
	try
	{
		body_boolean->setValue(int_value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	double double_value = 1.25;
	try
	{
		body_boolean->setValue(double_value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 3\n";
		}
	}

}

void UsdsBooleanTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryBoolean* dict_boolean = 0;
	usds::UsdsBoolean* body_boolean = 0;

	// step 1
	dict_boolean = (usds::DictionaryBoolean*)dict.addTag(usds::USDS_BOOLEAN, 1, "double", 0);
	dict.finalizeDictionary();
	body_boolean = (usds::UsdsBoolean*)body.addTag(dict_boolean);
	if (body_boolean->getType() != usds::USDS_BOOLEAN)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	body_boolean->setValue(false);
	try
	{
		body_boolean->getValue<bool>();
		if (body_boolean->getValue<bool>() != false)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	}

	// step 3
	body_boolean->setValue(false);
	try
	{
		body_boolean->getValue<int32_t>();
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	body_boolean->setValue(false);
	try
	{
		body_boolean->getValue<float>();
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	body_boolean->setValue(false);
	try
	{
		body_boolean->getValue<double>();
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 5\n";
		}
	}


}


