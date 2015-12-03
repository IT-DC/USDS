#include "unitTest\Base\usdsErrorTest.h"

#include "unitTest\base\usdsErrors.h"

#include "usdsAutotest.h"

void ErrorTest::runTest(int number)
{
	if (!needStart(number, UNIT_TESTS__USDS_ERRORS))
		return;
	testNumbers = number;
	
	std::cout << UNIT_TESTS__USDS_ERRORS << " ---------------- Class ErrorStack -----------------\n";

	test_1();
	test_2();
	test_3();

	
};

void ErrorTest::test_1()
{
	if (!needStart(testNumbers, UNIT_TESTS__USDS_ERRORS_1))
		return;
	
	std::cout << UNIT_TESTS__USDS_ERRORS_1 << ": ";

	// Step 1
	usds::ErrorMessage error_class(usds::BIN_OUT__BUFFER_OVERFLOW);
	if (error_class.getCode() != usds::BIN_OUT__BUFFER_OVERFLOW)
	{
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__USDS_ERRORS_1;
	}

	// Step 2
	const char* message = error_class.getMessage();
	if (message[0] != 0)
	{
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__USDS_ERRORS_1;
	}

	// Step 3
	error_class << "Message";
	message = error_class.getMessage();
	if (strcmp(message, "Message") != 0)
	{
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__USDS_ERRORS_1;
	}

	// Step 4
	error_class << ": ";
	message = error_class.getMessage();
	if (strcmp(message, "Message: ") != 0)
	{
		std::cout << "Failed at the step 4\n";
		throw UNIT_TESTS__USDS_ERRORS_1;
	}

	// Step 5
	error_class << -88888888;
	message = error_class.getMessage();
	if (strcmp(message, "Message: -88888888") != 0)
	{
		std::cout << "Failed at the step 5\n";
		throw UNIT_TESTS__USDS_ERRORS_1;
	}

	// Step 6
	size_t value = 0;
	error_class << ", " << value;
	message = error_class.getMessage();
	if (strcmp(message, "Message: -88888888, 0") != 0)
	{
		std::cout << "Failed at the step 6\n";
		throw UNIT_TESTS__USDS_ERRORS_1;
	}

	std::cout << "Successful!\n";
};

void ErrorTest::test_2()
{
	if (!needStart(testNumbers, UNIT_TESTS__USDS_ERRORS_2))
		return;

	std::cout << UNIT_TESTS__USDS_ERRORS_2 << ": ";

	// Step 1
	usds::ErrorMessage error_class(usds::BIN_OUT__BUFFER_OVERFLOW, "Message");
	if (error_class.getCode() != usds::BIN_OUT__BUFFER_OVERFLOW)
	{
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__USDS_ERRORS_2;
	}

	// Step 2
	const char* message = error_class.getMessage();
	if (strcmp(message, "Message") != 0)
	{
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__USDS_ERRORS_2;
	}

	// Step 3
	error_class << ": " << -88888888;
	message = error_class.getMessage();
	if (strcmp(message, "Message: -88888888") != 0)
	{
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__USDS_ERRORS_2;
	}

	std::cout << "Successful!\n";
};

void ErrorTest::test_3()
{
	if (!needStart(testNumbers, UNIT_TESTS__USDS_ERRORS_3))
		return;

	std::cout << UNIT_TESTS__USDS_ERRORS_3 << ": ";

	// Step 1
	usds::ErrorStack error_stack("FuncName");
	if (error_stack.getCode() != usds::NO_ERROR_CODE)
	{
		std::cout << "Failed at the step 1\n";
		throw UNIT_TESTS__USDS_ERRORS_3;
	}

	// Step 2
	const char* message = error_stack.getMessage();
	if (strcmp(message, "no message") != 0)
	{
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__USDS_ERRORS_3;
	}

	// Step 2
	const char* path = error_stack.getFullMessage();
	std::cout << "\n" << path;
	if (strcmp(path, "Error code: 0\nError message: no message\nStack:\npath=FuncName()\n") != 0)
	{
		std::cout << "Failed at the step 2\n";
		throw UNIT_TESTS__USDS_ERRORS_3;
	}

	usds::ErrorMessage error_class(usds::BIN_OUT__BUFFER_OVERFLOW, "Message");
	error_class << ": " << 921 << ";";


	std::cout << "Successful!\n";
};