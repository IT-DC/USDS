#include "unitTest\Base\usdsErrorTest.h"

#include "BasicParser\Include\base\usdsErrors.h"

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
	test_4();
	
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

	// Step 3
	const char* path = error_stack.getFullMessage();
	if (strcmp(path, "Error code: 0\nError message: \"no message\"\nStack:\npath=FuncName()\n") != 0)
	{
		std::cout << "Failed at the step 3\n";
		throw UNIT_TESTS__USDS_ERRORS_3;
	}

	std::cout << "Successful!\n";
};

void ErrorTest::test_4()
{
	if (!needStart(testNumbers, UNIT_TESTS__USDS_ERRORS_4))
		return;

	std::cout << UNIT_TESTS__USDS_ERRORS_4 << ": ";
	try
	{
		try
		{
			try
			{
				try
				{
					throw usds::ErrorMessage(usds::BIN_OUT__BUFFER_OVERFLOW, "Message") << ": " << 999 << ";";
				}
				catch (usds::ErrorMessage& err)
				{
					throw usds::ErrorStack("FuncName") << 666 << "www" << (size_t)888 << err;
				}
			}
			catch (usds::ErrorStack& stack)
			{
				// Step 1
				if (stack.getCode() != usds::BIN_OUT__BUFFER_OVERFLOW)
				{
					std::cout << "Failed at the step 1\n";
					throw UNIT_TESTS__USDS_ERRORS_4;
				}
				// Step 2
				if (strcmp(stack.getMessage(), "Message: 999;") != 0)
				{
					std::cout << "Failed at the step 2\n";
					throw UNIT_TESTS__USDS_ERRORS_4;
				}
				// Step 3
				if (strcmp(stack.getFullMessage(), "Error code: 1001\nError message: \"Message: 999;\"\nStack:\ncode=1001 message=\"Message: 999;\" path=FuncName(int 666, const char* \"www\", size_t 888)\n") != 0)
				{
					std::cout << "Failed at the step 3\n";
					throw UNIT_TESTS__USDS_ERRORS_4;
				}

				stack.addLevel("FuncName2");
				throw;
			}
		}
		catch (usds::ErrorStack& stack)
		{
			// Step 4
			if (stack.getCode() != usds::BIN_OUT__BUFFER_OVERFLOW)
			{
				std::cout << "Failed at the step 4\n";
				throw UNIT_TESTS__USDS_ERRORS_4;
			}
			// Step 5
			if (strcmp(stack.getMessage(), "Message: 999;") != 0)
			{
				std::cout << "Failed at the step 5\n";
				throw UNIT_TESTS__USDS_ERRORS_4;
			}
			// Step 6
			if (strcmp(stack.getFullMessage(), "Error code: 1001\nError message: \"Message: 999;\"\nStack:\npath=FuncName2()\n\t--> code=1001 message=\"Message: 999;\" path=FuncName(int 666, const char* \"www\", size_t 888)\n") != 0)
			{
				std::cout << "Failed at the step 6\n";
				throw UNIT_TESTS__USDS_ERRORS_4;
			}

			stack.addLevel("FuncName3") << (void*)0xA0B1C3D4 << (usds::ErrorMessage(usds::BIN_OUT__ALLOCATE_ERROR, "Message 2") << ": " << 555);
			throw;
		}
	}
	catch (usds::ErrorStack& stack)
	{
		// Step 7
		if (stack.getCode() != usds::BIN_OUT__ALLOCATE_ERROR)
		{
			std::cout << "Failed at the step 7\n";
			throw UNIT_TESTS__USDS_ERRORS_4;
		}
		// Step 8
		if (strcmp(stack.getMessage(), "Message 2: 555") != 0)
		{
			std::cout << "Failed at the step 8\n";
			throw UNIT_TESTS__USDS_ERRORS_4;
		}
		// Step 9
		if (strcmp(stack.getFullMessage(), "Error code: 1002\nError message: \"Message 2: 555\"\nStack:\ncode=1002 message=\"Message 2: 555\" path=FuncName3(pointer A0B1C3D4)\n\t--> path=FuncName2()\n\t\t--> code=1001 message=\"Message: 999;\" path=FuncName(int 666, const char* \"www\", size_t 888)\n") != 0)
		{
			std::cout << "Failed at the step 9\n";
			throw UNIT_TESTS__USDS_ERRORS_4;
		}

	}


	std::cout << "Successful!\n";
};