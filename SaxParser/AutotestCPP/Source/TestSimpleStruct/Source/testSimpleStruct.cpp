#include "TestSimpleStruct/Include/testSimpleStruct.h"

#include <string.h>

using namespace testSaxParser;


TestSimpleStruct::TestSimpleStruct()
{
	value.boolParameter = true;
	value.byteParameter = -127;
	value.ubyteParameter = 255;
	value.shortParameter = -10000;
	value.ushortParameter = 20000;
	value.intParameter = INT32_MAX;
	value.uintParameter = UINT32_MAX;
	value.longParameter = INT64_MAX;
	value.ulongParameter = UINT64_MAX;
	value.floatParameter = 1.25f;
	value.doubleParameter = 1.125;
	value.stringParameter = new char[10];

#pragma warning(disable: 4996)
	strcpy(value.stringParameter, "123456789");
	strcpy(value.string2Parameter, "012345678");

};

TestSimpleStruct::~TestSimpleStruct()
{
	delete[] value.stringParameter;
};

Package TestSimpleStruct::SaxGetBinary()
{
	Package out;
	out.body = 0;
	out.size = 0;


	return out;
};

Package TestSimpleStruct::SaxGetXml()
{
	Package out;
	out.body = 0;
	out.size = 0;


	return out;
};

Package TestSimpleStruct::SaxGetJson()
{
	Package out;
	out.body = 0;
	out.size = 0;


	return out;
};

bool TestSimpleStruct::SaxSetBinary(Package input)
{
	
	return true;
};

bool TestSimpleStruct::SaxSetXml(Package input)
{
	

	return true;
};

bool TestSimpleStruct::SaxSetJson(Package input)
{
	

	return true;
};
