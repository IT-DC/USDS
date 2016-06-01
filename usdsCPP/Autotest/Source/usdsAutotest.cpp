#include "usdsAutotest.h"

#include "unitTest\usdsUnitTest.h"
#include "base\usdsErrors.h"

#pragma warning(disable : 4996)

int32_t main(int32_t argc, char* argv[])
{
	testNumbers tests = ANY_TEST;
	
	UnitTest unit;
	
	std::cout << "Start!\n";
	try
	{
		unit.runTest(tests);


		std::cout << "==========================================================\n";
		std::cout << "All tests completed successfully at ";
		printTime();
	}
	catch (usds::ErrorStack & err)
	{
		std::cout << "Test failed, unexpected error:\n" << err.getFullMessage() << "\n";
	}
	catch (usds::ErrorMessage & msg)
	{
		std::cout << "Test failed, unexpected message:\n" << msg.getMessage() << "\n";
	}

	catch (...)
	{
		std::cout << "Test failed\n";
	}

	std::cout << "Press Enter";
	std::cin.ignore();

	return 0;
}

bool needStart(int32_t current_number, int32_t my_number)
{
	if (current_number == ANY_TEST)
		return true;

	if (current_number / 1000 * 1000 != current_number)
	{
		if (my_number / 1000 * 1000 != my_number)
			return current_number == my_number;
		if (my_number / 100000 * 100000 == my_number)
			return my_number <= current_number && (my_number + 99999) >= current_number;
		if (my_number / 1000 * 1000 == my_number)
			return my_number <= current_number && (my_number + 999) >= current_number;
	}
	
	if (current_number / 100000 * 100000 == current_number)
		return current_number <= my_number && (current_number + 99999) >= my_number;
	
	if (current_number / 1000 * 1000 == current_number)
	{
		if (my_number / 1000 * 1000 != my_number)
			return current_number <= my_number && (current_number + 999) >= my_number;
		if (my_number / 100000 * 100000 == my_number)
			return my_number <= current_number && (my_number + 99999) >= current_number;
		if (my_number / 1000 * 1000 == my_number)
			return current_number == my_number;
	}

	
	return false;
};


void printTime()
{
	time_t t = time(0);
	std::cout << std::asctime(std::localtime(&t));
};