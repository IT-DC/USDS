#ifndef TEST_STRUCT_H
#define TEST_STRUCT_H

#include <cstdint>

//
//$

namespace saxParserSimpleStruct
{
	//$S MyLittleAPI
	struct simpleStruct
	{
		bool boolParameter;
		int8_t byteParameter;
		uint8_t ubyteParameter;
		int16_t shortParameter;
		uint16_t ushortParameter;
		int32_t intParameter;
		uint32_t uintParameter;
		int64_t longParameter;
		uint64_t ulongParameter;
		float floatParameter;
		double doubleParameter;
		int64_t varintParameter;
		uint64_t uvarintParameter;
		//$S ENCODE:UTF-8
		char* stringParameter;
		char string2Parameter[10];
	};

	// testing of commented code
	/*
	//$S MyLittleAPI
	struct simpleStruct2
	{
		bool boolParameter;
		int8_t byteParameter;
	*/
	
}
#endif

