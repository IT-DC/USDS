#include "unitTest\body\usdsIntTest.h"

#include "body\dataTypes\usdsInt.h"
#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\usdsDictionary.h"

void UsdsIntTest::runTest(int32_t number)
{
	if (!needStart(number, UNIT_TESTS__BODY_INT_1))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__BODY_INT_1 << " ---------------- Body Int Class ------------------\n";

	test_1();
	test_2();

};

// Test setValue for UsdsIntTest
void UsdsIntTest::test_1()
{
	int32_t test_number = UNIT_TESTS__BODY_INT_1;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryInt* dict_int = 0;
	usds::UsdsInt* body_int = 0;

	// step 1
	dict_int = (usds::DictionaryInt*)dict.addTag(usds::USDS_INT, 1, "int", 0);
	dict.finalizeDictionary();
	body_int = (usds::UsdsInt*)body.addTag(dict_int);
	if (body_int->getType() != usds::USDS_INT)
	{
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}

	// step 2
	bool bool_value = true;
	try
	{
		body_int->setValue(bool_value);
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_BASE_TYPE__UNSUPPORTED_CONVERTION)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}

	// step 3
	int8_t int8_value = -1;
	body_int->setValue(int8_value);
	if (body_int->getValue() != -1)
	{
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}

	// step 4
	uint8_t uint8_value = 255;
	body_int->setValue(uint8_value);
	if (body_int->getValue() != 255)
	{
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}

	// step 5
	int16_t int16_value = -10000;
	body_int->setValue(int16_value);
	if (body_int->getValue() != -10000)
	{
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}

	// step 6
	uint16_t uint16_value = 20000;
	body_int->setValue(uint16_value);
	if (body_int->getValue() != 20000)
	{
		std::cout << "Failed at the step 6\n";
		throw test_number;
	}

	// step 7
	int32_t int32_value = -100000;
	body_int->setValue(int32_value);
	if (body_int->getValue() != -100000)
	{
		std::cout << "Failed at the step 7\n";
		throw test_number;
	}

	// step 8
	uint32_t uint32_value = 200000;
	body_int->setValue(uint32_value);
	if (body_int->getValue() != 200000)
	{
		std::cout << "Failed at the step 8\n";
		throw test_number;
	}

	// step 9
	uint32_value = (uint32_t)4294967295;
	try
	{
		body_int->setValue(uint32_value);
		std::cout << "Failed at the step 9\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_INT__TOO_BIG_VALUE)
		{
			std::cout << "Failed at the step 9\n";
			throw test_number;
		}
	}

	// step 10
	int64_t int64_value = -200000;
	body_int->setValue(int64_value);
	if (body_int->getValue() != -200000)
	{
		std::cout << "Failed at the step 10\n";
		throw test_number;
	}

	// step 11
	int64_value = -2147483649ll;
	try
	{
		body_int->setValue(int64_value);
		std::cout << "Failed at the step 11\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_INT__TOO_BIG_VALUE)
		{
			std::cout << "Failed at the step 11\n";
			throw test_number;
		}
	}

	// step 12
	uint64_t uint64_value = 200000;
	body_int->setValue(uint64_value);
	if (body_int->getValue() != 200000)
	{
		std::cout << "Failed at the step 12\n";
		throw test_number;
	}

	// step 13
	uint64_value = 2147483649ull;
	try
	{
		body_int->setValue(uint64_value);
		std::cout << "Failed at the step 13\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_INT__TOO_BIG_VALUE)
		{
			std::cout << "Failed at the step 13\n";
			throw test_number;
		}
	}

	// step 14
	float float_value = 1.0;
	try
	{
		body_int->setValue(float_value);
		std::cout << "Failed at the step 14\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_BASE_TYPE__UNSUPPORTED_CONVERTION)
		{
			std::cout << "Failed at the step 14\n";
			throw test_number;
		}
	}

	// step 15
	double double_value = 1.0;
	try
	{
		body_int->setValue(double_value);
		std::cout << "Failed at the step 15\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_BASE_TYPE__UNSUPPORTED_CONVERTION)
		{
			std::cout << "Failed at the step 15\n";
			throw test_number;
		}
	}

	// step 16
	const char* char_value = "5";
	try
	{
		body_int->setValue(char_value);
		std::cout << "Failed at the step 16\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_BASE_TYPE__UNSUPPORTED_CONVERTION)
		{
			std::cout << "Failed at the step 16\n";
			throw test_number;
		}
	}

	// step 17
	try
	{
		body_int->setValue(char_value, 1);
		std::cout << "Failed at the step 17\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_BASE_TYPE__UNSUPPORTED_CONVERTION)
		{
			std::cout << "Failed at the step 17\n";
			throw test_number;
		}
	}

	std::cout << "Successful!\n";
}

// Test getValue for UsdsIntTest
void UsdsIntTest::test_2()
{
	int32_t test_number = UNIT_TESTS__BODY_INT_2;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	usds::Dictionary dict(0);
	dict.setID(1, 0, 0);
	usds::Body body;
	usds::DictionaryInt* dict_int = 0;
	usds::UsdsInt* body_int = 0;

	// step 1
	dict_int = (usds::DictionaryInt*)dict.addTag(usds::USDS_INT, 1, "int", 0);
	dict.finalizeDictionary();
	body_int = (usds::UsdsInt*)body.addTag(dict_int);
	if (body_int->getType() != usds::USDS_INT)
	{
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}

	// step 2
	body_int->setValue(-100000);
	try
	{
		body_int->getValue<bool>();
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_BASE_TYPE__UNSUPPORTED_CONVERTION)
		{
			std::cout << "Failed at the step 2\n";
			throw test_number;
		}
	}

	// step 3
	body_int->setValue(-100);
	if (body_int->getValue<int8_t>() != -100)
	{
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}

	// step 4
	body_int->setValue(-1000);
	try
	{
		body_int->getValue<int8_t>();
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_INT__TOO_BIG_VALUE)
		{
			std::cout << "Failed at the step 4\n";
			throw test_number;
		}
	}

	// step 5
	body_int->setValue(200);
	if (body_int->getValue<uint8_t>() != 200)
	{
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}

	// step 6
	body_int->setValue(-100);
	try
	{
		body_int->getValue<uint8_t>();
		std::cout << "Failed at the step 6\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_INT__TOO_BIG_VALUE)
		{
			std::cout << "Failed at the step 6\n";
			throw test_number;
		}
	}

	// step 7
	body_int->setValue(-10000);
	if (body_int->getValue<int16_t>() != -10000)
	{
		std::cout << "Failed at the step 7\n";
		throw test_number;
	}

	// step 8
	body_int->setValue(-100000);
	try
	{
		body_int->getValue<int16_t>();
		std::cout << "Failed at the step 8\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_INT__TOO_BIG_VALUE)
		{
			std::cout << "Failed at the step 8\n";
			throw test_number;
		}
	}

	// step 9
	body_int->setValue(30000);
	if (body_int->getValue<uint16_t>() != 30000)
	{
		std::cout << "Failed at the step 9\n";
		throw test_number;
	}

	// step 10
	body_int->setValue(100000);
	try
	{
		body_int->getValue<uint16_t>();
		std::cout << "Failed at the step 10\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_INT__TOO_BIG_VALUE)
		{
			std::cout << "Failed at the step 10\n";
			throw test_number;
		}
	}

	// step 11
	body_int->setValue(1000000);
	if (body_int->getValue<int32_t>() != 1000000)
	{
		std::cout << "Failed at the step 11\n";
		throw test_number;
	}

	// step 12
	body_int->setValue(1000000);
	if (body_int->getValue<int64_t>() != 1000000)
	{
		std::cout << "Failed at the step 12\n";
		throw test_number;
	}

	// step 13
	body_int->setValue(1000000);
	if (body_int->getValue<uint64_t>() != 1000000)
	{
		std::cout << "Failed at the step 13\n";
		throw test_number;
	}

	// step 14
	body_int->setValue(-100000);
	try
	{
		body_int->getValue<uint64_t>();
		std::cout << "Failed at the step 14\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_INT__TOO_BIG_VALUE)
		{
			std::cout << "Failed at the step 14\n";
			throw test_number;
		}
	}

	// step 15
	body_int->setValue(-100000);
	try
	{
		body_int->getValue<float>();
		std::cout << "Failed at the step 15\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_BASE_TYPE__UNSUPPORTED_CONVERTION)
		{
			std::cout << "Failed at the step 15\n";
			throw test_number;
		}
	}

	// step 16
	body_int->setValue(-100000);
	try
	{
		body_int->getValue<double>();
		std::cout << "Failed at the step 16\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_BASE_TYPE__UNSUPPORTED_CONVERTION)
		{
			std::cout << "Failed at the step 16\n";
			throw test_number;
		}
	}

	// step 17
	body_int->setValue(-100000);
	try
	{
		body_int->getValue<double>();
		std::cout << "Failed at the step 17\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_BASE_TYPE__UNSUPPORTED_CONVERTION)
		{
			std::cout << "Failed at the step 17\n";
			throw test_number;
		}
	}

	// step 18
	body_int->setValue(-100000);
	try
	{
		body_int->getValue<const char*>();
		std::cout << "Failed at the step 18\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_BASE_TYPE__UNSUPPORTED_CONVERTION)
		{
			std::cout << "Failed at the step 18\n";
			throw test_number;
		}
	}

	// step 19
	body_int->setValue(-100000);
	const char* const_char_value = 0;
	size_t size_t_value = 0;
	try
	{
		body_int->getValue(&const_char_value, &size_t_value);
		std::cout << "Failed at the step 19\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_BASE_TYPE__UNSUPPORTED_CONVERTION)
		{
			std::cout << "Failed at the step 19\n";
			throw test_number;
		}
	}


	std::cout << "Successful!\n";
}