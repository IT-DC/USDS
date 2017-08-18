#ifndef TEST_SIMPLE_STRUCTS_H
#define TEST_SIMPLE_STRUCTS_H

#include "baseTestClass.h"
#include "TestSimpleStruct/Include/testStruct.h"

namespace testSaxParser
{
	// Test simple structs
	class TestSimpleStruct : public BaseTest
	{
	public:
		TestSimpleStruct();
		virtual ~TestSimpleStruct();

		Package SaxGetBinary();
		Package SaxGetXml();
		Package SaxGetJson();

		Package BasicGetBinary();
		Package BasicGetXml();
		Package BasicGetJson();

		bool SaxSetBinary(Package input);
		bool SaxSetXml(Package input);
		bool SaxSetJson(Package input);

	private:
		simpleStruct value;


	};
}
#endif

