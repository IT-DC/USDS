#include "usdsAutotest.h"

#include "body\dataTypes\usdsDouble.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\usdsDictionary.h"

void UsdsDoubleTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryDouble* dict_double = 0;
	usds::UsdsDouble* body_double = 0;

	// step 1
	dict_double = (usds::DictionaryDouble*)dict.addTag(usds::USDS_DOUBLE, 1, "double", 0);
	dict.finalizeDictionary();
	body_double = (usds::UsdsDouble*)body.addTag(dict_double);
	if (body_double->getType() != usds::USDS_DOUBLE)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_double->setValue(bool_value);
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
	int32_t int_value = 1000;
	try
	{
		body_double->setValue(int_value);
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
	body_double->setValue(double_value);
	if (body_double->getValue<double>() != 1.25)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	float float_value = 1.125;
	body_double->setValue(float_value);
	if (body_double->getValue<double>() != 1.125)
	{
		throw "Failed at the step 5\n";
	}
	
}

void UsdsDoubleTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryDouble* dict_double = 0;
	usds::UsdsDouble* body_double = 0;

	// step 1
	dict_double = (usds::DictionaryDouble*)dict.addTag(usds::USDS_DOUBLE, 1, "double", 0);
	dict.finalizeDictionary();
	body_double = (usds::UsdsDouble*)body.addTag(dict_double);
	if (body_double->getType() != usds::USDS_DOUBLE)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	body_double->setValue(1.25);
	try
	{
		body_double->getValue<bool>();
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
	body_double->setValue(1.25);
	try
	{
		body_double->getValue<int32_t>();
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
	body_double->setValue(1.25);
	try
	{
		body_double->getValue<float>();
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
	body_double->setValue(1.25);
	if (body_double->getValue<double>() != 1.25)
	{
		throw "Failed at the step 5\n";
	}

}


