#include "usdsAutotest.h"

int main(int argc, char* argv[])
{
	UnitTest unit;

	std::cout << "Start!\n";
	try
	{
		unit.runTest();


		std::cout << "All tests completed successfully!\n";
	}
	catch (...)
	{
		std::cout << "Test failed\n";
	}

	std::cout << "Press Enter";
	std::cin.ignore();

	return 0;
}

