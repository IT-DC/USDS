#include "usdsAutotest.h"

#include "body\dataTypes\usdsFloat.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryFloat.h"
#include "dictionary\usdsDictionary.h"

void UsdsFloatTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryFloat* dict_float = 0;
	usds::UsdsFloat* body_float = 0;

	// step 1
	dict_float = (usds::DictionaryFloat*)dict.addTag(usds::USDS_FLOAT, 1, "float", 0);
	dict.finalizeDictionary();
	body_float = (usds::UsdsFloat*)body.addTag(dict_float);
	if (body_float->getType() != usds::USDS_FLOAT)
	{
		throw "Failed at the step 1\n";
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_float->setValue(bool_value);
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
		body_float->setValue(int_value);
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
		body_float->setValue(double_value);
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
	float float_value = 1.125;
	body_float->setValue(float_value);
	if (body_float->getValue<float>() != 1.125)
	{
		throw "Failed at the step 5\n";
	}

}

void UsdsFloatTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryFloat* dict_float = 0;
	usds::UsdsFloat* body_float = 0;

	// step 1
	dict_float = (usds::DictionaryFloat*)dict.addTag(usds::USDS_FLOAT, 1, "float", 0);
	dict.finalizeDictionary();
	body_float = (usds::UsdsFloat*)body.addTag(dict_float);
	if (body_float->getType() != usds::USDS_FLOAT)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	body_float->setValue(1.25F);
	try
	{
		body_float->getValue<bool>();
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
	body_float->setValue(1.25F);
	try
	{
		body_float->getValue<int32_t>();
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
	body_float->setValue(1.25F);
	if (body_float->getValue<float>() != 1.25)
	{
		throw "Failed at the step 4\n";
	}

	// step 5
	body_float->setValue(1.125F);
	if (body_float->getValue<double>() != 1.125)
	{
		throw "Failed at the step 5\n";
	}

}

void UsdsFloatTest::test_3()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;
	usds::DictionaryFloat* dict_little = 0;
	usds::DictionaryFloat* dict_big = 0;
	usds::UsdsFloat* body_little = 0;
	usds::UsdsFloat* body_big = 0;

	// step 1
	dict_little = (usds::DictionaryFloat*)dict.addTag(usds::USDS_FLOAT, 1, "little", 0);
	dict_big = (usds::DictionaryFloat*)dict.addTag(usds::USDS_FLOAT, 2, "big", 0);
	dict_big->setBigendian(true);
	dict.finalizeDictionary();
	body_little = (usds::UsdsFloat*)body.addTag(dict_little);
	if (body_little->isBigendian() == true)
		throw "Failed at the step 1\n";

	// step 2
	body_big = (usds::UsdsFloat*)body.addTag(dict_big);
	if (body_big->isBigendian() == false)
		throw "Failed at the step 2\n";

}

