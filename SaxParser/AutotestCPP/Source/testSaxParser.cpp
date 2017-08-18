#include "testSaxParser.h"

using namespace testSaxParser;

int32_t main(int32_t argc, char* argv[])
{
	BaseTest* tests = 0;
	Package sax_result;
	Package basic_result;

	// Test 1: Test simple structs
	std::cout << "Test 1: \"Test simple structs\"\n";
	tests = new TestSimpleStruct();
	std::cout << "USDS Binary: ";
	sax_result = tests->SaxGetBinary();
	basic_result = tests->BasicGetBinary();
	if (sax_result.size != basic_result.size)
	{
		std::cout << "error! Sizes of Binary are not equal\n";
	}
	else if (memcmp(sax_result.body, basic_result.body, sax_result.size) != 0)
	{
		std::cout << "error! Results are not equal\n";
	}
	else if (tests->SaxSetBinary(sax_result) != true)
	{
		std::cout << "error! Deserialization failed\n";
	}
	std::cout << "passed\n";


	std::cout << "Press any key\n";
	std::cin.get();

	return 0;
}
