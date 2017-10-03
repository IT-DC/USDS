#ifndef TEST_SIMPLE_STRUCTS_H
#define TEST_SIMPLE_STRUCTS_H

#include "baseTestClass.h"
#include "TestSimpleStruct/Include/testStruct.h"

// Test simple structs
namespace saxParserSimpleStruct
{
	
	class TestSimpleStruct : public BaseTest
	{
	public:
		TestSimpleStruct();
		virtual ~TestSimpleStruct();

		Package SaxGetBinary();
		Package SaxGetXml();
		Package SaxGetJson();

		bool SaxSetBinary(Package input);
		bool SaxSetXml(Package input);
		bool SaxSetJson(Package input);

	private:
		simpleStruct value;


	};
}
#endif

