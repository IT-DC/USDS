#include "usdsAutotest.h"

#include "usdsErrors.h"

// test for ErrorMessage
void ErrorTest::test_1()
{
	// Step 1
	usds::ErrorMessage error_class(1);
	if (error_class.getCode() != 1)
	{
		throw "Failed at the step 1\n";
	}

	// Step 2
	const char* message = error_class.getMessage();
	if (message[0] != 0)
	{
		throw "Failed at the step 2\n";
	}

	// Step 3
	error_class << "Message";
	message = error_class.getMessage();
	if (strcmp(message, "Message") != 0)
	{
		throw "Failed at the step 3\n";
	}

	// Step 4
	std::string string_value1("10");
	std::string* string_value2 = new std::string("Hell world!");
	error_class.addString(": 12345", 6) << ", " << true << ", " << false << ", " << (int8_t)-33 << ", " << (uint8_t)25 << ", " << (int16_t)-258 << ", " << (uint16_t)258 << ", " << string_value1 << ", " << string_value2;
	message = error_class.getMessage();
	if (strcmp(message, "Message: 1234, true, false, -33, 25, -258, 258, 10, Hell world!") != 0)
	{
		throw "Failed at the step 4\n";
	}
	delete string_value2;

};

// test for ErrorMessage
void ErrorTest::test_2()
{
	// Step 1
	usds::ErrorMessage error_class(1, "Message");
	if (error_class.getCode() != 1)
	{
		throw "Failed at the step 1\n";
	}

	// Step 2
	const char* message = error_class.getMessage();
	if (strcmp(message, "Message") != 0)
	{
		throw "Failed at the step 2\n";
	}

	// Step 3
	error_class.addString(": 12345", 0) << ", " << (int32_t)-33 << ", " << (uint32_t)25 << ", " << (int64_t)-258 << ", " << (uint64_t)258 << ", " << (float)0.1 << ", " << (double)0.01 << ", " << (void*)256;
	message = error_class.getMessage();

#ifdef _MSC_VER
	#ifdef _WIN32
		const char* correct_message = "Message: 12345, -33, 25, -258, 258, 0.1, 0.01, 0x00000100";
	#elif defined _WIN64
		const char* correct_message = "Message: 12345, -33, 25, -258, 258, 0.1, 0.01, 0x0000000000000100";
	#endif
#endif

	if (strcmp(message, correct_message) != 0)
	{
		throw "Failed at the step 4\n";
	}

};

// test for ErrorStack
void ErrorTest::test_3()
{
	// Step 1
	usds::ErrorStack error_stack("FuncName");
	if (error_stack.getCode() != usds::NO_ERROR_CODE)
	{
		throw "Failed at the step 1\n";
	}

	// Step 2
	const char* message = error_stack.getMessage();
	if (strcmp(message, "no message") != 0)
	{
		throw "Failed at the step 2\n";
	}

	// Step 3
	const char* path = error_stack.getFullMessage();
	if (strcmp(path, "Error code: 0\nError message: \"no message\"\nStack:\npath=FuncName()\n") != 0)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	std::string string_value1("Hell world!");
	std::string* string_value2 = new std::string("No");
	error_stack.addStringAndSize("12345", 4) << true << false << (uint8_t)5 << (int8_t)-6 << (uint16_t)257 << (int16_t)-256
		<< (uint32_t)100000 << (int32_t)-100000 << (uint64_t)100001 << (int64_t)-100001 << (float)10.001 << (double)10.002 << "11" << string_value1 << (const char*)0 << string_value2 << (std::string*)0;
	path = error_stack.getFullMessage();
	if (strcmp(path, "Error code: 0\nError message: \"no message\"\nStack:\npath=FuncName(const char* \"1234\", size_t 4, bool true, bool false, uint8_t 5, int8_t -6, uint16_t 257, int16_t -256, "
		"uint32_t 100000, int32_t -100000, uint64_t 100001, int64_t -100001, float 10.001, double 10.002, const char* \"11\", string \"Hell world!\", const char* 0, string* \"No\", string* 0)\n") != 0)
	{
		throw "Failed at the step 4\n";
	}
	delete string_value2;

};

// test for ErrorStack
void ErrorTest::test_4()
{
	// Step 1
	usds::ErrorStack error_stack("FuncName");
	if (error_stack.getCode() != usds::NO_ERROR_CODE)
	{
		throw "Failed at the step 1\n";
	}

	// Step 2
	const char* message = error_stack.getMessage();
	if (strcmp(message, "no message") != 0)
	{
		throw "Failed at the step 2\n";
	}

	// Step 3
	const char* path = error_stack.getFullMessage();
	if (strcmp(path, "Error code: 0\nError message: \"no message\"\nStack:\npath=FuncName()\n") != 0)
	{
		throw "Failed at the step 3\n";
	}

	// step 4
	error_stack.addStringAndSize("12345", 0).addStringAndSize(0, 4) << (void*)256 << (bool*)257 << (uint8_t*)258 << (int8_t*)259 << (uint16_t*)260 << (int16_t*)261
		<< (uint32_t*)262 << (int32_t*)263 << (uint64_t*)264 << (int64_t*)265 << (float*)266 << (double*)267 << (const char**)268;
	path = error_stack.getFullMessage();

#ifdef _MSC_VER
#ifdef _WIN32
	const char* correct_message = "Error code: 0\nError message: \"no message\"\nStack:\npath=FuncName(const char* \"12345\", size_t 0, const char* 0, size_t 4, void* 0x00000100, bool* 0x00000101, uint8_t* 0x00000102, int8_t* 0x00000103, uint16_t* 0x00000104, int16_t* 0x00000105, "
		"uint32_t* 0x00000106, int32_t* 0x00000107, uint64_t* 0x00000108, int64_t* 0x00000109, float* 0x0000010A, double* 0x0000010B, char** 0x0000010C)\n";
#elif defined _WIN64
	const char* correct_message = "Error code: 0\nError message: \"no message\"\nStack:\npath=FuncName(const char* \"12345\", size_t 0, const char* 0, size_t 4, void* 0x0000000000000100, bool* 0x0000000000000101, uint8_t* 0x0000000000000102, int8_t* 0x0000000000000103, uint16_t* 0x0000000000000104, int16_t* 0x0000000000000105, "
		"uint32_t* 0x0000000000000106, int32_t* 0x0000000000000107, uint64_t* 0x0000000000000108, int64_t* 0x0000000000000109, float* 0x000000000000010A, double* 0x000000000000010B, char** 0x000000000000010C)\n";
#endif
#endif

	if (strcmp(path, correct_message) != 0)
	{
		throw "Failed at the step 4\n";
	}

};

// test for ErrorStack
void ErrorTest::test_5()
{
	try
	{
		try
		{
			try
			{
				try
				{
					throw usds::ErrorMessage(1, "Message") << ": " << 999 << ";";
				}
				catch (usds::ErrorMessage& err)
				{
					throw usds::ErrorStack("FuncName") << 666 << "www" << (uint32_t)888 << err;
				}
			}
			catch (usds::ErrorStack& stack)
			{
				// Step 1
				if (stack.getCode() != 1)
				{
					throw "Failed at the step 1\n";
				}
				// Step 2
				if (strcmp(stack.getMessage(), "Message: 999;") != 0)
				{
					throw "Failed at the step 2\n";
				}
				// Step 3
				if(strcmp(stack.getFullMessage(), "Error code: 1\nError message: \"Message: 999;\"\nStack:\ncode=1 message=\"Message: 999;\" path=FuncName(int32_t 666, const char* \"www\", uint32_t 888)\n") != 0)
				{
					throw "Failed at the step 3\n";
				}

				stack.addLevel("FuncName2");
				throw;
			}
		}
		catch (usds::ErrorStack& stack)
		{
			// Step 4
			if (stack.getCode() != 1)
			{
				throw "Failed at the step 4\n";
			}
			// Step 5
			if (strcmp(stack.getMessage(), "Message: 999;") != 0)
			{
				throw "Failed at the step 5\n";
			}
			// Step 6
			if (strcmp(stack.getFullMessage(), "Error code: 1\nError message: \"Message: 999;\"\nStack:\npath=FuncName2()\n\t--> code=1 message=\"Message: 999;\" path=FuncName(int32_t 666, const char* \"www\", uint32_t 888)\n") != 0)
			{
				throw "Failed at the step 6\n";
			}

			stack.addLevel("FuncName3") << (void*)0xA0B1C3D4 << (usds::ErrorMessage(2, "Message 2") << ": " << 555);
			throw;
		}
	}
	catch (usds::ErrorStack& stack)
	{
		// Step 7
		if (stack.getCode() != 2)
		{
			throw "Failed at the step 7\n";
		}
		// Step 8
		if (strcmp(stack.getMessage(), "Message 2: 555") != 0)
		{
			throw "Failed at the step 8\n";
		}
		// Step 9
		if (strcmp(stack.getFullMessage(), "Error code: 2\nError message: \"Message 2: 555\"\nStack:\ncode=2 message=\"Message 2: 555\" path=FuncName3(void* 0xA0B1C3D4)\n\t--> path=FuncName2()\n\t\t--> code=1 message=\"Message: 999;\" path=FuncName(int32_t 666, const char* \"www\", uint32_t 888)\n") != 0)
		{
			throw "Failed at the step 9\n";
		}

	}

};