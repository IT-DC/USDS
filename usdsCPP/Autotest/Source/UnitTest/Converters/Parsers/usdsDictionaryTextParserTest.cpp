#include "usdsAutotest.h"

#pragma execution_character_set("utf-8")

#include "converters/usdsDictionaryTextParser.h"

#include "dictionary\usdsDictionary.h"
#include "dictionary/dictionaryBaseType.h"
#include "dictionary/dataTypes/dictionaryBoolean.h"
#include "dictionary/dataTypes/dictionaryByte.h"
#include "dictionary/dataTypes/dictionaryUByte.h"
#include "dictionary/dataTypes/dictionaryShort.h"
#include "dictionary/dataTypes/dictionaryUShort.h"
#include "dictionary/dataTypes/dictionaryInt.h"
#include "dictionary/dataTypes/dictionaryUInt.h"
#include "dictionary/dataTypes/dictionaryLong.h"
#include "dictionary/dataTypes/dictionaryULong.h"
#include "dictionary/dataTypes/dictionaryFloat.h"
#include "dictionary/dataTypes/dictionaryDouble.h"
#include "dictionary/dataTypes/dictionaryVarint.h"
#include "dictionary/dataTypes/dictionaryUvarint.h"
#include "dictionary/dataTypes/dictionaryString.h"
#include "dictionary/dataTypes/dictionaryStruct.h"
#include "dictionary/dataTypes/dictionaryArray.h"
#include "dictionary/dataTypes/dictionaryTagLink.h"

#include <sstream>
#include <iostream>


// Test simple types for array's element
void DictionaryTextParserTest::test_1()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	
	// step 1
	const char* text_dict = 
		"USDS MyLittleAPI 888.1.0 {\
			1: BOOLEAN bool;\
			2: BYTE byte;\
			3: UBYTE ubyte;\
			4: SHORT short;\
			5: USHORT ushort;\
			6: INT int;\
			7: UINT uint;\
			8: LONG long;\
			9: ULONG ulong;\
			10: FLOAT float;\
			11: DOUBLE double;\
			12: VARINT varint;\
			13: UVARINT uvarint;\
			}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	const char* dict_name = dict.getDictionaryName();
	if (dict.getTagNumber() != 13 || dict.getDictionaryID() != 888 || dict.getMajorVersion() != 1 || dict.getMinorVersion() != 0 || strcmp(dict_name, "MyLittleAPI") != 0)
		throw "Failed at the step 1\n";
	
	// step 2
	const char* name = dict.getTag(1)->getName();
	if (strcmp(name, "bool") != 0)
		throw "Failed at the step 2\n";
	if (dict.getTag(1)->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 2\n";

	// step 3
	name = dict.getTag(2)->getName();
	if (strcmp(name, "byte") != 0)
		throw "Failed at the step 3\n";
	if (dict.getTag(2)->getType() != usds::USDS_BYTE)
		throw "Failed at the step 3\n";

	// step 4
	name = dict.getTag(3)->getName();
	if (strcmp(name, "ubyte") != 0)
		throw "Failed at the step 3\n";
	if (dict.getTag(3)->getType() != usds::USDS_UBYTE)
		throw "Failed at the step 3\n";

	// step 5
	name = dict.getTag(4)->getName();
	if (strcmp(name, "short") != 0)
		throw "Failed at the step 5\n";
	if (dict.getTag(4)->getType() != usds::USDS_SHORT)
		throw "Failed at the step 5\n";

	// step 6
	name = dict.getTag(5)->getName();
	if (strcmp(name, "ushort") != 0)
		throw "Failed at the step 6\n";
	if (dict.getTag(5)->getType() != usds::USDS_USHORT)
		throw "Failed at the step 6\n";

	// step 7
	name = dict.getTag(6)->getName();
	if (strcmp(name, "int") != 0)
		throw "Failed at the step 7\n";
	if (dict.getTag(6)->getType() != usds::USDS_INT)
		throw "Failed at the step 7\n";

	// step 8
	name = dict.getTag(7)->getName();
	if (strcmp(name, "uint") != 0)
		throw "Failed at the step 8\n";
	if (dict.getTag(7)->getType() != usds::USDS_UINT)
		throw "Failed at the step 8\n";

	// step 9
	name = dict.getTag(8)->getName();
	if (strcmp(name, "long") != 0)
		throw "Failed at the step 9\n";
	if (dict.getTag(8)->getType() != usds::USDS_LONG)
		throw "Failed at the step 9\n";

	// step 10
	name = dict.getTag(9)->getName();
	if (strcmp(name, "ulong") != 0)
		throw "Failed at the step 10\n";
	if (dict.getTag(9)->getType() != usds::USDS_ULONG)
		throw "Failed at the step 10\n";

	// step 11
	name = dict.getTag(10)->getName();
	if (strcmp(name, "float") != 0)
		throw "Failed at the step 11\n";
	if (dict.getTag(10)->getType() != usds::USDS_FLOAT)
		throw "Failed at the step 11\n";

	// step 12
	name = dict.getTag(11)->getName();
	if (strcmp(name, "double") != 0)
		throw "Failed at the step 12\n";
	if (dict.getTag(11)->getType() != usds::USDS_DOUBLE)
		throw "Failed at the step 12\n";

	// step 13
	name = dict.getTag(12)->getName();
	if (strcmp(name, "varint") != 0)
		throw "Failed at the step 13\n";
	if (dict.getTag(12)->getType() != usds::USDS_VARINT)
		throw "Failed at the step 13\n";

	// step 14
	name = dict.getTag(13)->getName();
	if (strcmp(name, "uvarint") != 0)
		throw "Failed at the step 14\n";
	if (dict.getTag(13)->getType() != usds::USDS_UVARINT)
		throw "Failed at the step 14\n";

}

void DictionaryTextParserTest::test_2()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.0.1 {\
			1: STRING str1;\
			2: STRING<UTF-8> str2;\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 2 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	const char* name = dict.getTag(1)->getName();
	if (strcmp(name, "str1") != 0)
		throw "Failed at the step 2\n";
	if (dict.getTag(1)->getType() != usds::USDS_STRING)
		throw "Failed at the step 2\n";
	if (((usds::DictionaryString*)dict.getTag(1))->getDefaultEncode() != usds::USDS_NO_DEFAULT_ENCODE)
		throw "Failed at the step 2\n";

	// step 3
	name = dict.getTag(2)->getName();
	if (strcmp(name, "str2") != 0)
		throw "Failed at the step 3\n";
	if (dict.getTag(2)->getType() != usds::USDS_STRING)
		throw "Failed at the step 3\n";
	if (((usds::DictionaryString*)dict.getTag(2))->getDefaultEncode() != usds::USDS_UTF8)
		throw "Failed at the step 3\n";

}

void DictionaryTextParserTest::test_3()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 1.1.1 {\
			1: struct\
			{\
				1: BOOLEAN bool;\
				2: BYTE byte;\
				3: UBYTE ubyte;\
				4: SHORT short;\
				5: USHORT ushort;\
				6: INT int;\
				7: UINT uint;\
				8: LONG long;\
				9: ULONG ulong;\
				10: FLOAT float;\
				11: DOUBLE double;\
				12: VARINT varint;\
				13: UVARINT uvarint;\
				14: STRING string;\
				15: STRING<UTF-8> string2;\
			};\
			2: struct2\
			{\
				1: struct internal_struct;\
			};\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 2 || dict.getDictionaryID() != 1 || dict.getMajorVersion() != 1 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	const char* name = dict.getTag(1)->getName();
	if (strcmp(name, "struct") != 0)
		throw "Failed at the step 2\n";
	if (dict.getTag(1)->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 2\n";

	// step 3
	name = dict.getTag(2)->getName();
	if (strcmp(name, "struct2") != 0)
		throw "Failed at the step 3\n";
	if (dict.getTag(2)->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 3\n";

	// step 4
	usds::DictionaryStruct* tag = (usds::DictionaryStruct*)dict.getTag(1);
	usds::DictionaryBaseType* field = tag->getField(1);
	name = field->getName();
	if (strcmp(name, "bool") != 0 || field->getType() != usds::USDS_BOOLEAN || field->isNullable() != false)
		throw "Failed at the step 4\n";

	// step 5
	field = tag->getField(2);
	name = field->getName();
	if (strcmp(name, "byte") != 0 || field->getType() != usds::USDS_BYTE || field->isNullable() != false)
		throw "Failed at the step 5\n";

	// step 6
	field = tag->getField(3);
	name = field->getName();
	if (strcmp(name, "ubyte") != 0 || field->getType() != usds::USDS_UBYTE || field->isNullable() != false)
		throw "Failed at the step 6\n";

	// step 7
	field = tag->getField(4);
	name = field->getName();
	if (strcmp(name, "short") != 0 || field->getType() != usds::USDS_SHORT || field->isNullable() != false)
		throw "Failed at the step 7\n";

	// step 8
	field = tag->getField(5);
	name = field->getName();
	if (strcmp(name, "ushort") != 0 || field->getType() != usds::USDS_USHORT || field->isNullable() != false)
		throw "Failed at the step 8\n";

	// step 9
	field = tag->getField(6);
	name = field->getName();
	if (strcmp(name, "int") != 0 || field->getType() != usds::USDS_INT || field->isNullable() != false)
		throw "Failed at the step 9\n";

	// step 10
	field = tag->getField(7);
	name = field->getName();
	if (strcmp(name, "uint") != 0 || field->getType() != usds::USDS_UINT || field->isNullable() != false)
		throw "Failed at the step 10\n";

	// step 11
	field = tag->getField(8);
	name = field->getName();
	if (strcmp(name, "long") != 0 || field->getType() != usds::USDS_LONG || field->isNullable() != false)
		throw "Failed at the step 11\n";

	// step 12
	field = tag->getField(9);
	name = field->getName();
	if (strcmp(name, "ulong") != 0 || field->getType() != usds::USDS_ULONG || field->isNullable() != false)
		throw "Failed at the step 12\n";

	// step 13
	field = tag->getField(10);
	name = field->getName();
	if (strcmp(name, "float") != 0 || field->getType() != usds::USDS_FLOAT || field->isNullable() != false)
		throw "Failed at the step 13\n";

	// step 14
	field = tag->getField(11);
	name = field->getName();
	if (strcmp(name, "double") != 0 || field->getType() != usds::USDS_DOUBLE || field->isNullable() != false)
		throw "Failed at the step 14\n";

	// step 15
	field = tag->getField(12);
	name = field->getName();
	if (strcmp(name, "varint") != 0 || field->getType() != usds::USDS_VARINT || field->isNullable() != false)
		throw "Failed at the step 15\n";

	// step 16
	field = tag->getField(13);
	name = field->getName();
	if (strcmp(name, "uvarint") != 0 || field->getType() != usds::USDS_UVARINT || field->isNullable() != false)
		throw "Failed at the step 16\n";

	// step 17
	field = tag->getField(14);
	name = field->getName();
	if (strcmp(name, "string") != 0 || field->getType() != usds::USDS_STRING || ((usds::DictionaryString*)field)->getDefaultEncode() != usds::USDS_NO_DEFAULT_ENCODE || field->isNullable() != false)
		throw "Failed at the step 17\n";

	// step 18
	field = tag->getField(15);
	name = field->getName();
	if (strcmp(name, "string2") != 0 || field->getType() != usds::USDS_STRING || ((usds::DictionaryString*)field)->getDefaultEncode() != usds::USDS_UTF8 || field->isNullable() != false)
		throw "Failed at the step 18\n";

	// step 19
	tag = (usds::DictionaryStruct*)dict.getTag(2);
	field = tag->getField(1);
	name = field->getName();
	if (strcmp(name, "internal_struct") != 0 || field->getType() != usds::USDS_TAG || field->isNullable() != false)
		throw "Failed at the step 19\n";

	// step 20
	usds::DictionaryBaseType* parent = ((usds::DictionaryTagLink*)field)->getTag();
	name = parent->getName();
	if (strcmp(name, "struct") != 0 || parent->getType() != usds::USDS_STRUCT || field->isNullable() != false)
		throw "Failed at the step 20\n";

}

void DictionaryTextParserTest::test_4()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.0.0 {\
			1: struct\
			{\
				1: BOOLEAN bool;\
				2: internal_struct\
				{\
					1: BOOLEAN bool;\
					2: BYTE byte;\
				};\
				3: BYTE byte;\
				4: internal_struct2\
				{\
					1: BYTE byte;\
					2: internal_internal_struct\
					{\
						1: BYTE byte;\
						2: BOOLEAN bool;\
					};\
					3: BOOLEAN bool;\
				};\
			};\
			2: BYTE byte;\
			3: struct2\
			{\
				1: BOOLEAN bool;\
			};\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 3 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 0)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryBaseType* tag = dict.getTag(1);
	const char* name = tag->getName();
	if (strcmp(name, "struct") != 0 || tag->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 2\n";

	// step 3
	tag = dict.getTag(2);
	name = tag->getName();
	if (strcmp(name, "byte") != 0 || tag->getType() != usds::USDS_BYTE)
		throw "Failed at the step 3\n";

	// step 4
	tag = dict.getTag(3);
	name = tag->getName();
	if (strcmp(name, "struct2") != 0 || tag->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 4\n";

	// step 5
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (struct_tag->getFieldNumber() != 4)
		throw "Failed at the step 5\n";

	// step 6
	usds::DictionaryBaseType* field = struct_tag->getField(1);
	name = field->getName();
	if (strcmp(name, "bool") != 0 || field->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 6\n";

	// step 7
	field = struct_tag->getField(2);
	name = field->getName();
	if (strcmp(name, "internal_struct") != 0 || field->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 7\n";

	// step 8
	if (((usds::DictionaryStruct*)field)->getFieldNumber() != 2)
		throw "Failed at the step 8\n";

	// step 9
	usds::DictionaryBaseType* field_int = ((usds::DictionaryStruct*)field)->getField(1);
	name = field_int->getName();
	if (strcmp(name, "bool") != 0 || field_int->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 9\n";

	// step 10
	field_int = ((usds::DictionaryStruct*)field)->getField(2);
	name = field_int->getName();
	if (strcmp(name, "byte") != 0 || field_int->getType() != usds::USDS_BYTE)
		throw "Failed at the step 10\n";

	// step 11
	field = struct_tag->getField(3);
	name = field->getName();
	if (strcmp(name, "byte") != 0 || field->getType() != usds::USDS_BYTE)
		throw "Failed at the step 11\n";

	// step 12
	field = struct_tag->getField(4);
	name = field->getName();
	if (strcmp(name, "internal_struct2") != 0 || field->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 12\n";

	// step 13
	if (((usds::DictionaryStruct*)field)->getFieldNumber() != 3)
		throw "Failed at the step 13\n";

	// step 14
	field_int = ((usds::DictionaryStruct*)field)->getField(1);
	name = field_int->getName();
	if (strcmp(name, "byte") != 0 || field_int->getType() != usds::USDS_BYTE)
		throw "Failed at the step 14\n";

	// step 15
	field_int = ((usds::DictionaryStruct*)field)->getField(2);
	name = field_int->getName();
	if (strcmp(name, "internal_internal_struct") != 0 || field_int->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 15\n";

	// step 16
	field_int = ((usds::DictionaryStruct*)field)->getField(3);
	name = field_int->getName();
	if (strcmp(name, "bool") != 0 || field_int->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 16\n";

	// step 17
	field_int = ((usds::DictionaryStruct*)field)->getField(2);
	if (((usds::DictionaryStruct*)field_int)->getFieldNumber() != 2)
		throw "Failed at the step 17\n";

	// step 18
	usds::DictionaryBaseType* field_int_int = ((usds::DictionaryStruct*)field_int)->getField(1);
	name = field_int_int->getName();
	if (strcmp(name, "byte") != 0 || field_int_int->getType() != usds::USDS_BYTE)
		throw "Failed at the step 18\n";

	// step 19
	field_int_int = ((usds::DictionaryStruct*)field_int)->getField(2);
	name = field_int_int->getName();
	if (strcmp(name, "bool") != 0 || field_int_int->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 19\n";

}

void DictionaryTextParserTest::test_5()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 4294967295.55.255 {\
			1: struct\
			{\
				1: BOOLEAN bool = NULL;\
				2: BYTE byte = NULL;\
				3: UBYTE ubyte = NULL;\
				4: SHORT short = NULL;\
				5: USHORT ushort = NULL;\
				6: INT int = NULL;\
				7: UINT uint = NULL;\
				8: LONG long = NULL;\
				9: ULONG ulong = NULL;\
				10: FLOAT float = NULL;\
				11: DOUBLE double = NULL;\
				12: VARINT varint = NULL;\
				13: UVARINT uvarint = NULL;\
				14: STRING string = NULL;\
				15: STRING<UTF-8> string2 = NULL;\
			};\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 1 || dict.getDictionaryID() != 4294967295 || dict.getMajorVersion() != 55 || dict.getMinorVersion() != 255)
		throw "Failed at the step 1\n";
	
	// step 2
	usds::DictionaryStruct* tag = (usds::DictionaryStruct*)dict.getTag(1);
	const char* name = tag->getName();
	if (strcmp(name, "struct") != 0 || tag->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 2\n";

	// step 3
	usds::DictionaryBaseType* field = tag->getField(1);
	name = field->getName();
	if (strcmp(name, "bool") != 0 || field->getType() != usds::USDS_BOOLEAN || field->isNullable() != true)
		throw "Failed at the step 3\n";

	// step 4
	field = tag->getField(2);
	name = field->getName();
	if (strcmp(name, "byte") != 0 || field->getType() != usds::USDS_BYTE || field->isNullable() != true)
		throw "Failed at the step 4\n";

	// step 5
	field = tag->getField(3);
	name = field->getName();
	if (strcmp(name, "ubyte") != 0 || field->getType() != usds::USDS_UBYTE || field->isNullable() != true)
		throw "Failed at the step 5\n";

	// step 6
	field = tag->getField(4);
	name = field->getName();
	if (strcmp(name, "short") != 0 || field->getType() != usds::USDS_SHORT || field->isNullable() != true)
		throw "Failed at the step 6\n";

	// step 7
	field = tag->getField(5);
	name = field->getName();
	if (strcmp(name, "ushort") != 0 || field->getType() != usds::USDS_USHORT || field->isNullable() != true)
		throw "Failed at the step 7\n";

	// step 8
	field = tag->getField(6);
	name = field->getName();
	if (strcmp(name, "int") != 0 || field->getType() != usds::USDS_INT || field->isNullable() != true)
		throw "Failed at the step 8\n";

	// step 9
	field = tag->getField(7);
	name = field->getName();
	if (strcmp(name, "uint") != 0 || field->getType() != usds::USDS_UINT || field->isNullable() != true)
		throw "Failed at the step 9\n";

	// step 10
	field = tag->getField(8);
	name = field->getName();
	if (strcmp(name, "long") != 0 || field->getType() != usds::USDS_LONG || field->isNullable() != true)
		throw "Failed at the step 10\n";

	// step 11
	field = tag->getField(9);
	name = field->getName();
	if (strcmp(name, "ulong") != 0 || field->getType() != usds::USDS_ULONG || field->isNullable() != true)
		throw "Failed at the step 11\n";

	// step 12
	field = tag->getField(10);
	name = field->getName();
	if (strcmp(name, "float") != 0 || field->getType() != usds::USDS_FLOAT || field->isNullable() != true)
		throw "Failed at the step 12\n";

	// step 13
	field = tag->getField(11);
	name = field->getName();
	if (strcmp(name, "double") != 0 || field->getType() != usds::USDS_DOUBLE || field->isNullable() != true)
		throw "Failed at the step 13\n";

	// step 14
	field = tag->getField(12);
	name = field->getName();
	if (strcmp(name, "varint") != 0 || field->getType() != usds::USDS_VARINT || field->isNullable() != true)
		throw "Failed at the step 14\n";

	// step 15
	field = tag->getField(13);
	name = field->getName();
	if (strcmp(name, "uvarint") != 0 || field->getType() != usds::USDS_UVARINT || field->isNullable() != true)
		throw "Failed at the step 15\n";

	// step 16
	field = tag->getField(14);
	name = field->getName();
	if (strcmp(name, "string") != 0 || field->getType() != usds::USDS_STRING || ((usds::DictionaryString*)field)->getDefaultEncode() != usds::USDS_NO_DEFAULT_ENCODE || field->isNullable() != true)
		throw "Failed at the step 16\n";

	// step 17
	field = tag->getField(15);
	name = field->getName();
	if (strcmp(name, "string2") != 0 || field->getType() != usds::USDS_STRING || ((usds::DictionaryString*)field)->getDefaultEncode() != usds::USDS_UTF8 || field->isNullable() != true)
		throw "Failed at the step 17\n";

}


void DictionaryTextParserTest::test_6()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 3000000000.254.125\
		{\
			1: struct\
			{\
				1: int_struct\
				{\
					1: BYTE byte;\
				} = NULL;\
				2: byte tag_byte = NULL;\
			};\
			2: BYTE byte;\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 2 || dict.getDictionaryID() != 3000000000 || dict.getMajorVersion() != 254 || dict.getMinorVersion() != 125)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* tag = (usds::DictionaryStruct*)dict.getTag(1);
	const char* name = tag->getName();
	if (strcmp(name, "struct") != 0 || tag->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 2\n";

	// step 3
	usds::DictionaryBaseType* field = tag->getField(1);
	name = field->getName();
	if (strcmp(name, "int_struct") != 0 || field->getType() != usds::USDS_STRUCT || field->isNullable() != true)
		throw "Failed at the step 3\n";

	// step 4
	usds::DictionaryBaseType* int_field = ((usds::DictionaryStruct*)field)->getField(1);
	name = int_field->getName();
	if (strcmp(name, "byte") != 0 || int_field->getType() != usds::USDS_BYTE || int_field->isNullable() != false)
		throw "Failed at the step 4\n";

	// step 5
	field = tag->getField(2);
	name = field->getName();
	if (strcmp(name, "tag_byte") != 0 || field->getType() != usds::USDS_TAG || field->isNullable() != true)
		throw "Failed at the step 5\n";

	// step 6
	int_field = ((usds::DictionaryTagLink*)field)->getTag();
	name = int_field->getName();
	if (strcmp(name, "byte") != 0 || int_field->getType() != usds::USDS_BYTE || int_field->isNullable() != false)
		throw "Failed at the step 6\n";

}

void DictionaryTextParserTest::test_7()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	std::string text_dictionary;
	std::stringstream buffer;

	// step 1
	int64_t digit64 = 1;
	int64_t first_value64 = 0;
	for (size_t i = 1; i < 20; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			buffer.str("");
			buffer << "USDS U 0.0.0 { 1: struct { 1: VARINT varint = " << first_value64 << "; }; }\n";
			text_dictionary = buffer.str();
			parser->parse(text_dictionary.c_str(), usds::USDS_UTF8, &dict);
			int64_t value = ((usds::DictionaryVarint*)((usds::DictionaryStruct*)dict.getTag(1))->getField(1))->getDefaultValue();
			if (first_value64 != value)
				throw "Failed at the step 1\n";
			dict.clear();
			first_value64 = first_value64 + digit64;
		}
		first_value64 = first_value64 - digit64;
		digit64 = digit64 * 10;
	}

	// step 2
	digit64 = 1;
	first_value64 = 0;
	for (size_t i = 1; i < 20; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			buffer.str("");
			buffer << "USDS U 0.0.0 { 1: struct { 1: VARINT varint = " << first_value64 << "; }; }\n";
			text_dictionary = buffer.str();
			parser->parse(text_dictionary.c_str(), usds::USDS_UTF8, &dict);
			int64_t value = ((usds::DictionaryVarint*)((usds::DictionaryStruct*)dict.getTag(1))->getField(1))->getDefaultValue();
			if (first_value64 != value)
				throw "Failed at the step 1\n";
			dict.clear();
			first_value64 = first_value64 - digit64;
		}
		first_value64 = first_value64 + digit64;
		digit64 = digit64 * 10;
	}

	// step 3
	int32_t digit32 = 1;
	int32_t first_value32 = 0;
	for (size_t i = 1; i < 11; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			buffer.str("");
			buffer << "USDS U 0.0.0 { 1: struct { 1: INT int = " << first_value32 << "; }; }\n";
			text_dictionary = buffer.str();
			parser->parse(text_dictionary.c_str(), usds::USDS_UTF8, &dict);
			int64_t value = ((usds::DictionaryInt*)((usds::DictionaryStruct*)dict.getTag(1))->getField(1))->getDefaultValue();
			if (first_value32 != value)
				throw "Failed at the step 3\n";
			dict.clear();
			first_value32 = first_value32 + digit32;
		}
		first_value32 = first_value32 - digit32;
		digit32 = digit32 * 10;
	}

	// step 4
	digit32 = 1;
	first_value32 = 0;
	for (size_t i = 1; i < 11; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			buffer.str("");
			buffer << "USDS U 0.0.0 { 1: struct { 1: INT int = " << first_value32 << "; }; }\n";
			text_dictionary = buffer.str();
			parser->parse(text_dictionary.c_str(), usds::USDS_UTF8, &dict);
			int64_t value = ((usds::DictionaryInt*)((usds::DictionaryStruct*)dict.getTag(1))->getField(1))->getDefaultValue();
			if (first_value32 != value)
				throw "Failed at the step 4\n";
			dict.clear();
			first_value32 = first_value32 - digit32;
		}
		first_value32 = first_value32 + digit32;
		digit32 = digit32 * 10;
	}

	// step 5
	int16_t digit16 = 1;
	int16_t first_value16 = 0;
	for (size_t i = 1; i < 6; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			buffer.str("");
			buffer << "USDS U 0.0.0 { 1: struct { 1: SHORT short = " << first_value16 << "; }; }\n";
			text_dictionary = buffer.str();
			parser->parse(text_dictionary.c_str(), usds::USDS_UTF8, &dict);
			int64_t value = ((usds::DictionaryShort*)((usds::DictionaryStruct*)dict.getTag(1))->getField(1))->getDefaultValue();
			if (first_value16 != value)
				throw "Failed at the step 5\n";
			dict.clear();
			first_value16 = first_value16 + digit16;
		}
		first_value16 = first_value16 - digit16;
		digit16 = digit16 * 10;
	}

	// step 6
	digit16 = 1;
	first_value16 = 0;
	for (size_t i = 1; i < 6; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			buffer.str("");
			buffer << "USDS U 0.0.0 { 1: struct { 1: SHORT short = " << first_value16 << "; }; }\n";
			text_dictionary = buffer.str();
			parser->parse(text_dictionary.c_str(), usds::USDS_UTF8, &dict);
			int64_t value = ((usds::DictionaryShort*)((usds::DictionaryStruct*)dict.getTag(1))->getField(1))->getDefaultValue();
			if (first_value16 != value)
				throw "Failed at the step 6\n";
			dict.clear();
			first_value16 = first_value16 - digit16;
		}
		first_value16 = first_value16 + digit16;
		digit16 = digit16 * 10;
	}

	// step 7
	for (int32_t i = -127; i <= 127; i++)
	{
		buffer.str("");
		buffer << "USDS U 0.0.0 { 1: struct { 1: BYTE byte = " << i << "; }; }\n";
		text_dictionary = buffer.str();
		parser->parse(text_dictionary.c_str(), usds::USDS_UTF8, &dict);
		int32_t value = ((usds::DictionaryByte*)((usds::DictionaryStruct*)dict.getTag(1))->getField(1))->getDefaultValue();
		if (i != value)
			throw "Failed at the step 7\n";
		dict.clear();
	}

	// step 8
	for (int32_t i = 0; i <= 255; i++)
	{
		buffer.str("");
		buffer << "USDS U 0.0.0 { 1: struct { 1: UBYTE ubyte = " << i << "; }; }\n";
		text_dictionary = buffer.str();
		parser->parse(text_dictionary.c_str(), usds::USDS_UTF8, &dict);
		int32_t value = ((usds::DictionaryUByte*)((usds::DictionaryStruct*)dict.getTag(1))->getField(1))->getDefaultValue();
		if (i != value)
			throw "Failed at the step 8\n";
		dict.clear();
	}

	// step 9
	uint64_t digitu64 = 1;
	uint64_t first_valueu64 = 0;
	for (size_t i = 1; i < 21; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			buffer.str("");
			buffer << "USDS U 0.0.0 { 1: struct { 1: UVARINT uvarint = " << first_valueu64 << "; }; }\n";
			text_dictionary = buffer.str();
			parser->parse(text_dictionary.c_str(), usds::USDS_UTF8, &dict);
			uint64_t value = ((usds::DictionaryUVarint*)((usds::DictionaryStruct*)dict.getTag(1))->getField(1))->getDefaultValue();
			if (first_valueu64 != value)
				throw "Failed at the step 9\n";
			dict.clear();
			first_valueu64 = first_valueu64 + digitu64;
		}
		first_valueu64 = first_valueu64 - digitu64;
		digitu64 = digitu64 * 10;
	}

	// step 10
	uint32_t digitu32 = 1;
	uint32_t first_valueu32 = 0;
	for (size_t i = 1; i < 11; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			buffer.str("");
			buffer << "USDS U 0.0.0 { 1: struct { 1: UINT uint = " << first_valueu32 << "; }; }\n";
			text_dictionary = buffer.str();
			parser->parse(text_dictionary.c_str(), usds::USDS_UTF8, &dict);
			uint32_t value = ((usds::DictionaryUInt*)((usds::DictionaryStruct*)dict.getTag(1))->getField(1))->getDefaultValue();
			if (first_valueu32 != value)
				throw "Failed at the step 10\n";
			dict.clear();
			first_valueu32 = first_valueu32 + digitu32;
		}
		first_valueu32 = first_valueu32 - digitu32;
		digitu32 = digitu32 * 10;
	}

	// step 11
	uint16_t digitu16 = 1;
	uint16_t first_valueu16 = 0;
	for (size_t i = 1; i < 6; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			buffer.str("");
			buffer << "USDS U 0.0.0 { 1: struct { 1: USHORT ushort = " << first_valueu16 << "; }; }\n";
			text_dictionary = buffer.str();
			parser->parse(text_dictionary.c_str(), usds::USDS_UTF8, &dict);
			uint16_t value = ((usds::DictionaryShort*)((usds::DictionaryStruct*)dict.getTag(1))->getField(1))->getDefaultValue();
			if (first_valueu16 != value)
				throw "Failed at the step 5\n";
			dict.clear();
			first_valueu16 = first_valueu16 + digitu16;
		}
		first_valueu16 = first_valueu16 - digitu16;
		digitu16 = digitu16 * 10;
	}

}


void DictionaryTextParserTest::test_8()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	const size_t size = 77;
	const char* dicts[size] = {
		"USDS U 0.0.0 { 1: struct { 1: BYTE value = 128;};}",
		"USDS U 0.0.0 { 1: struct { 1: BYTE value = -129;};}",
		"USDS U 0.0.0 { 1: struct { 1: BYTE value = 200;};}",
		"USDS U 0.0.0 { 1: struct { 1: BYTE value = -200;};}",
		"USDS U 0.0.0 { 1: struct { 1: BYTE value = 1000;};}",
		"USDS U 0.0.0 { 1: struct { 1: BYTE value = -1000;};}",
		"USDS U 0.0.0 { 1: struct { 1: UBYTE value = 256;};}",
		"USDS U 0.0.0 { 1: struct { 1: UBYTE value = 300;};}",
		"USDS U 0.0.0 { 1: struct { 1: UBYTE value = 1000;};}",
		"USDS U 0.0.0 { 1: struct { 1: UBYTE value = -1;};}",
		"USDS U 0.0.0 { 1: struct { 1: UBYTE value = -10;};}",
		"USDS U 0.0.0 { 1: struct { 1: UBYTE value = -255;};}",
		"USDS U 0.0.0 { 1: struct { 1: UBYTE value = -1000;};}",
		"USDS U 0.0.0 { 1: struct { 1: SHORT value = 32768;};}",
		"USDS U 0.0.0 { 1: struct { 1: SHORT value = -32769;};}",
		"USDS U 0.0.0 { 1: struct { 1: SHORT value = 40000;};}",
		"USDS U 0.0.0 { 1: struct { 1: SHORT value = -40000;};}",
		"USDS U 0.0.0 { 1: struct { 1: SHORT value = 100000;};}",
		"USDS U 0.0.0 { 1: struct { 1: SHORT value = -100000;};}",
		"USDS U 0.0.0 { 1: struct { 1: USHORT value = 65536;};}",

		"USDS U 0.0.0 { 1: struct { 1: USHORT value = 70000;};}",
		"USDS U 0.0.0 { 1: struct { 1: USHORT value = 100000;};}",
		"USDS U 0.0.0 { 1: struct { 1: USHORT value = -1;};}",
		"USDS U 0.0.0 { 1: struct { 1: USHORT value = -10;};}",
		"USDS U 0.0.0 { 1: struct { 1: USHORT value = -100;};}",
		"USDS U 0.0.0 { 1: struct { 1: USHORT value = -1000;};}",
		"USDS U 0.0.0 { 1: struct { 1: USHORT value = -10000;};}",
		"USDS U 0.0.0 { 1: struct { 1: USHORT value = -100000;};}",
		"USDS U 0.0.0 { 1: struct { 1: INT value = 2147483648;};}",
		"USDS U 0.0.0 { 1: struct { 1: INT value = 3000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: INT value = 10000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: INT value = -2147483649;};}",
		"USDS U 0.0.0 { 1: struct { 1: INT value = -3000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: INT value = -10000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: UINT value = 4294967296;};}",
		"USDS U 0.0.0 { 1: struct { 1: UINT value = 5000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: UINT value = 10000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: UINT value = -1;};}",
		"USDS U 0.0.0 { 1: struct { 1: UINT value = -10;};}",
		"USDS U 0.0.0 { 1: struct { 1: UINT value = -100;};}",

		"USDS U 0.0.0 { 1: struct { 1: UINT value = -1000;};}",
		"USDS U 0.0.0 { 1: struct { 1: UINT value = -10000;};}",
		"USDS U 0.0.0 { 1: struct { 1: UINT value = -100000;};}",
		"USDS U 0.0.0 { 1: struct { 1: UINT value = -1000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: UINT value = -10000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: UINT value = -100000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: UINT value = -1000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: UINT value = -10000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: LONG value = 9223372036854775808;};}",
		"USDS U 0.0.0 { 1: struct { 1: LONG value = 10000000000000000000};}",
		"USDS U 0.0.0 { 1: struct { 1: LONG value = -9223372036854775809;};}",
		"USDS U 0.0.0 { 1: struct { 1: LONG value = -10000000000000000000};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = 18446744073709551616;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = 28446744073709551616;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = 108446744073709551616;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -1;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -10;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -100;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -1000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -10000;};}",

		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -100000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -1000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -10000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -100000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -1000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -10000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -100000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -1000000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -10000000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -100000000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -1000000000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -10000000000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -100000000000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -1000000000000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -10000000000000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -100000000000000000000;};}",
		"USDS U 0.0.0 { 1: struct { 1: ULONG value = -1000000000000000000000;};}",
	};

	// step 1
	for (size_t i = 0; i < size; i++)
	{
		try
		{
			parser->parse(dicts[i], usds::USDS_UTF8, &dict);
			throw "Failed at the step 1\n";
		}
		catch (usds::ErrorStack& err)
		{
			if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
			{
				throw "Failed at the step 2\n";
			}
		}
		dict.clear();
	}

}

void DictionaryTextParserTest::test_9()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	const size_t size = 20;
	struct dicts { const char* text; float value;} dicts[size];

	dicts[0].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = 125;};}";
	dicts[0].value = 125.0F;
	dicts[1].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = -125;};}";
	dicts[1].value = -125.0F;
	dicts[2].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = 1000000000000000000000000000000;};}";
	dicts[2].value = 1000000000000000000000000000000.0F;
	dicts[3].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = -1000000000000000000000000000000;};}";
	dicts[3].value = -1000000000000000000000000000000.0F;
	dicts[4].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = 125.0;};}";
	dicts[4].value = 125.0F;
	dicts[5].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = -125.0;};}";
	dicts[5].value = -125.0F;
	dicts[6].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = 1000000000000000000000000000000.0;};}";
	dicts[6].value = 1000000000000000000000000000000.0F;
	dicts[7].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = -1000000000000000000000000000000.0;};}";
	dicts[7].value = -1000000000000000000000000000000.0F;
	dicts[8].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = 125.125;};}";
	dicts[8].value = 125.125F;
	dicts[9].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = -125.125;};}";
	dicts[9].value = -125.125F;
	dicts[10].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = .125;};}";
	dicts[10].value = 0.125F;
	dicts[11].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = -.125;};}";
	dicts[11].value = -0.125F;
	dicts[12].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = 1.125e3;};}";
	dicts[12].value = 1125.0F;
	dicts[13].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = -1.125e3;};}";
	dicts[13].value = -1125.0F;
	dicts[14].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = 112.5e-2;};}";
	dicts[14].value = 1.125F;
	dicts[15].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = -112.5e-2;};}";
	dicts[15].value = -1.125F;
	dicts[16].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = .125e3;};}";
	dicts[16].value = 125.0F;
	dicts[17].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = -.125e3;};}";
	dicts[17].value = -125.0F;
	dicts[18].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = .125e-3;};}";
	dicts[18].value = 0.000125F;
	dicts[19].text = "USDS U 0.0.0 { 1: struct { 1: FLOAT value = -.125e-3;};}";
	dicts[19].value = -0.000125F;
	// step 1
	for (size_t i = 0; i < size; i++)
	{
		parser->parse(dicts[i].text, usds::USDS_UTF8, &dict);
		float value = ((usds::DictionaryFloat*)((usds::DictionaryStruct*)dict.getTag(1))->getField(1))->getDefaultValue();
		if (value != dicts[i].value)
			throw "Failed at the step 1\n";
		dict.clear();
	}

}


void DictionaryTextParserTest::test_10()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 4294967295.55.255 {\n\
			1: struct\n\
			{\n\
				1: BOOLEAN bool = true;\n\
				2: BOOLEAN bool2 = false;\n\
				3: BYTE byte = 127;\n\
				4: BYTE byte2 = -128;\n\
				5: UBYTE ubyte = 255;\n\
				6: SHORT short = 32767;\n\
				7: SHORT short2 = -32768;\n\
				8: USHORT ushort = 65535;\n\
				9: INT int = 2147483647;\n\
				10: INT int2 = -2147483648;\n\
				11: UINT uint = 4294967295;\n\
				12: LONG long = 9223372036854775807;\n\
				13: LONG long2 = -9223372036854775808;\n\
				14: ULONG ulong = 18446744073709551615;\n\
				15: FLOAT float = 1.125e2;\n\
				16: DOUBLE double = -.125;\n\
				17: VARINT varint = 9223372036854775807;\n\
				18: VARINT varint2 = -9223372036854775808;\n\
				19: UVARINT uvarint = 18446744073709551615;\n\
				20: STRING string = \"Привет\\\"!\\\"\";\n\
				21: STRING<UTF-8> string2 = \"\";\n\
			};\n\
		}";

	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 1 || dict.getDictionaryID() != 4294967295 || dict.getMajorVersion() != 55 || dict.getMinorVersion() != 255)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* tag = (usds::DictionaryStruct*)dict.getTag(1);
	const char* name = tag->getName();
	if (strcmp(name, "struct") != 0 || tag->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 2\n";

	// step 3
	usds::DictionaryBaseType* field = tag->getField(1);
	name = field->getName();
	if (strcmp(name, "bool") != 0 || field->getType() != usds::USDS_BOOLEAN || field->isNullable() != false || ((usds::DictionaryBoolean*)field)->getDefaultValue() != true)
		throw "Failed at the step 3\n";

	// step 4
	field = tag->getField(2);
	name = field->getName();
	if (strcmp(name, "bool2") != 0 || field->getType() != usds::USDS_BOOLEAN || field->isNullable() != false || ((usds::DictionaryBoolean*)field)->getDefaultValue() != false)
		throw "Failed at the step 4\n";
	
	// step 5
	field = tag->getField(3);
	name = field->getName();
	if (strcmp(name, "byte") != 0 || field->getType() != usds::USDS_BYTE || field->isNullable() != false || ((usds::DictionaryByte*)field)->getDefaultValue() != 127)
		throw "Failed at the step 5\n";

	// step 6
	field = tag->getField(4);
	name = field->getName();
	if (strcmp(name, "byte2") != 0 || field->getType() != usds::USDS_BYTE || field->isNullable() != false || ((usds::DictionaryByte*)field)->getDefaultValue() != -128)
		throw "Failed at the step 6\n";

	// step 7
	field = tag->getField(5);
	name = field->getName();
	if (strcmp(name, "ubyte") != 0 || field->getType() != usds::USDS_UBYTE || field->isNullable() != false || ((usds::DictionaryUByte*)field)->getDefaultValue() != 255)
		throw "Failed at the step 7\n";

	// step 8
	field = tag->getField(6);
	name = field->getName();
	if (strcmp(name, "short") != 0 || field->getType() != usds::USDS_SHORT || field->isNullable() != false || ((usds::DictionaryShort*)field)->getDefaultValue() != 32767)
		throw "Failed at the step 8\n";

	// step 9
	field = tag->getField(7);
	name = field->getName();
	if (strcmp(name, "short2") != 0 || field->getType() != usds::USDS_SHORT || field->isNullable() != false || ((usds::DictionaryShort*)field)->getDefaultValue() != -32768)
		throw "Failed at the step 9\n";

	// step 10
	field = tag->getField(8);
	name = field->getName();
	if (strcmp(name, "ushort") != 0 || field->getType() != usds::USDS_USHORT || field->isNullable() != false || ((usds::DictionaryUShort*)field)->getDefaultValue() != 65535)
		throw "Failed at the step 10\n";

	// step 11
	field = tag->getField(9);
	name = field->getName();
	if (strcmp(name, "int") != 0 || field->getType() != usds::USDS_INT || field->isNullable() != false || ((usds::DictionaryInt*)field)->getDefaultValue() != 2147483647)
		throw "Failed at the step 11\n";

	// step 12
	field = tag->getField(10);
	name = field->getName();
	if (strcmp(name, "int2") != 0 || field->getType() != usds::USDS_INT || field->isNullable() != false || ((usds::DictionaryInt*)field)->getDefaultValue() != INT32_MIN)
		throw "Failed at the step 12\n";

	// step 13
	field = tag->getField(11);
	name = field->getName();
	if (strcmp(name, "uint") != 0 || field->getType() != usds::USDS_UINT || field->isNullable() != false || ((usds::DictionaryUInt*)field)->getDefaultValue() != 4294967295)
		throw "Failed at the step 13\n";

	// step 14
	field = tag->getField(12);
	name = field->getName();
	if (strcmp(name, "long") != 0 || field->getType() != usds::USDS_LONG || field->isNullable() != false || ((usds::DictionaryLong*)field)->getDefaultValue() != 9223372036854775807)
		throw "Failed at the step 14\n";

	// step 15
	field = tag->getField(13);
	name = field->getName();
	if (strcmp(name, "long2") != 0 || field->getType() != usds::USDS_LONG || field->isNullable() != false || ((usds::DictionaryLong*)field)->getDefaultValue() != INT64_MIN)
		throw "Failed at the step 15\n";

	// step 16
	field = tag->getField(14);
	name = field->getName();
	if (strcmp(name, "ulong") != 0 || field->getType() != usds::USDS_ULONG || field->isNullable() != false || ((usds::DictionaryULong*)field)->getDefaultValue() != UINT64_MAX)
		throw "Failed at the step 16\n";

	// step 17
	field = tag->getField(15);
	name = field->getName();
	if (strcmp(name, "float") != 0 || field->getType() != usds::USDS_FLOAT || field->isNullable() != false || ((usds::DictionaryFloat*)field)->getDefaultValue() != 112.5F)
		throw "Failed at the step 17\n";

	// step 18
	field = tag->getField(16);
	name = field->getName();
	if (strcmp(name, "double") != 0 || field->getType() != usds::USDS_DOUBLE || field->isNullable() != false || ((usds::DictionaryDouble*)field)->getDefaultValue() != -0.125)
		throw "Failed at the step 18\n";

	// step 19
	field = tag->getField(17);
	name = field->getName();
	if (strcmp(name, "varint") != 0 || field->getType() != usds::USDS_VARINT || field->isNullable() != false || ((usds::DictionaryVarint*)field)->getDefaultValue() != INT64_MAX)
		throw "Failed at the step 19\n";

	// step 20
	field = tag->getField(18);
	name = field->getName();
	if (strcmp(name, "varint2") != 0 || field->getType() != usds::USDS_VARINT || field->isNullable() != false || ((usds::DictionaryVarint*)field)->getDefaultValue() != INT64_MIN)
		throw "Failed at the step 20\n";

	// step 21
	field = tag->getField(19);
	name = field->getName();
	if (strcmp(name, "uvarint") != 0 || field->getType() != usds::USDS_UVARINT || field->isNullable() != false || ((usds::DictionaryUVarint*)field)->getDefaultValue() != UINT64_MAX)
		throw "Failed at the step 21\n";

	// step 22
	field = tag->getField(20);
	name = field->getName();
	const char* string_value = ((usds::DictionaryString*)field)->getUTF8DefaultValue();
	if (strcmp(name, "string") != 0 || field->getType() != usds::USDS_STRING || field->isNullable() != false || strcmp(string_value, "Привет\\\"!\\\""))
		throw "Failed at the step 22\n";

	// step 23
	field = tag->getField(21);
	name = field->getName();
	string_value = ((usds::DictionaryString*)field)->getUTF8DefaultValue();
	if (strcmp(name, "string2") != 0 || field->getType() != usds::USDS_STRING || field->isNullable() != false || strcmp(string_value, ""))
		throw "Failed at the step 23\n";
	
}

void DictionaryTextParserTest::test_11()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	
	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.0.0 {\n\
			1: BOOLEAN[] bool;\n\
			2: BYTE[] byte;\n\
			3: UBYTE[] ubyte;\n\
			4: SHORT[] short;\n\
			5: USHORT[] ushort;\n\
			6: INT[] int;\n\
			7: UINT[] uint;\n\
			8: LONG[] long;\n\
			9: ULONG[] ulong;\n\
			10: FLOAT[] float;\n\
			11: DOUBLE[] double;\n\
			12: VARINT[] varint;\n\
			13: UVARINT[] uvarint;\n\
			14: STRING[] string;\n\
			15: STRING<UTF-8>[] string2;\n\
			16: struct[]\n\
			{\n\
				1: BOOLEAN bool;\n\
				2: BYTE byte;\n\
			};\n\
		}";

	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 16 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 0)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryArray* tag = (usds::DictionaryArray*)dict.getTag(1);
	if (strcmp(tag->getName(), "bool") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 2\n";

	// step 3
	tag = (usds::DictionaryArray*)dict.getTag(2);
	if (strcmp(tag->getName(), "byte") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_BYTE)
		throw "Failed at the step 3\n";

	// step 4
	tag = (usds::DictionaryArray*)dict.getTag(3);
	if (strcmp(tag->getName(), "ubyte") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_UBYTE)
		throw "Failed at the step 4\n";

	// step 5
	tag = (usds::DictionaryArray*)dict.getTag(4);
	if (strcmp(tag->getName(), "short") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_SHORT)
		throw "Failed at the step 5\n";

	// step 6
	tag = (usds::DictionaryArray*)dict.getTag(5);
	if (strcmp(tag->getName(), "ushort") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_USHORT)
		throw "Failed at the step 6\n";

	// step 7
	tag = (usds::DictionaryArray*)dict.getTag(6);
	if (strcmp(tag->getName(), "int") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_INT)
		throw "Failed at the step 7\n";

	// step 8
	tag = (usds::DictionaryArray*)dict.getTag(7);
	if (strcmp(tag->getName(), "uint") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_UINT)
		throw "Failed at the step 8\n";

	// step 9
	tag = (usds::DictionaryArray*)dict.getTag(8);
	if (strcmp(tag->getName(), "long") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_LONG)
		throw "Failed at the step 9\n";

	// step 10
	tag = (usds::DictionaryArray*)dict.getTag(9);
	if (strcmp(tag->getName(), "ulong") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_ULONG)
		throw "Failed at the step 10\n";

	// step 11
	tag = (usds::DictionaryArray*)dict.getTag(10);
	if (strcmp(tag->getName(), "float") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_FLOAT)
		throw "Failed at the step 11\n";

	// step 12
	tag = (usds::DictionaryArray*)dict.getTag(11);
	if (strcmp(tag->getName(), "double") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_DOUBLE)
		throw "Failed at the step 12\n";

	// step 13
	tag = (usds::DictionaryArray*)dict.getTag(12);
	if (strcmp(tag->getName(), "varint") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_VARINT)
		throw "Failed at the step 13\n";

	// step 14
	tag = (usds::DictionaryArray*)dict.getTag(13);
	if (strcmp(tag->getName(), "uvarint") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_UVARINT)
		throw "Failed at the step 14\n";

	// step 15
	tag = (usds::DictionaryArray*)dict.getTag(14);
	if (strcmp(tag->getName(), "string") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_STRING
		|| ((usds::DictionaryString*)tag->getElement())->getDefaultEncode() != usds::USDS_NO_DEFAULT_ENCODE)
		throw "Failed at the step 15\n";

	// step 16
	tag = (usds::DictionaryArray*)dict.getTag(15);
	if (strcmp(tag->getName(), "string2") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_STRING
		|| ((usds::DictionaryString*)tag->getElement())->getDefaultEncode() != usds::USDS_UTF8)
		throw "Failed at the step 16\n";

	// step 17
	tag = (usds::DictionaryArray*)dict.getTag(16);
	if (strcmp(tag->getName(), "struct") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 17\n";

	// step 18
	usds::DictionaryStruct* element = (usds::DictionaryStruct*)tag->getElement();
	usds::DictionaryBaseType* field = element->getField(1);
	if (strcmp(field->getName(), "bool") != 0 || field->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 18\n";

	// step 19
	field = element->getField(2);
	if (strcmp(field->getName(), "byte") != 0 || field->getType() != usds::USDS_BYTE)
		throw "Failed at the step 19\n";

}

void DictionaryTextParserTest::test_12()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.0.0 {\n\
			1: BOOLEAN[][] bool;\n\
			2: BYTE[][][] byte;\n\
			3: UBYTE[][][][] ubyte;\n\
			4: struct[][][]\n\
			{\n\
				1: BOOLEAN bool;\n\
				2: BYTE byte;\n\
			};\n\
		}";

	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 4 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 0)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryArray* tag = (usds::DictionaryArray*)dict.getTag(1);
	if (strcmp(tag->getName(), "bool") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_ARRAY ||
		((usds::DictionaryArray*)tag->getElement())->getElement()->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 2\n";

	// step 3
	tag = (usds::DictionaryArray*)dict.getTag(2);
	if (strcmp(tag->getName(), "byte") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_ARRAY
		|| ((usds::DictionaryArray*)tag->getElement())->getElement()->getType() != usds::USDS_ARRAY
		|| ((usds::DictionaryArray*)((usds::DictionaryArray*)tag->getElement())->getElement())->getElement()->getType() != usds::USDS_BYTE)
		throw "Failed at the step 3\n";

	// step 4
	tag = (usds::DictionaryArray*)dict.getTag(3);
	if (strcmp(tag->getName(), "ubyte") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_ARRAY
		|| ((usds::DictionaryArray*)tag->getElement())->getElement()->getType() != usds::USDS_ARRAY
		|| ((usds::DictionaryArray*)((usds::DictionaryArray*)tag->getElement())->getElement())->getElement()->getType() != usds::USDS_ARRAY
		|| ((usds::DictionaryArray*)((usds::DictionaryArray*)((usds::DictionaryArray*)tag->getElement())->getElement())->getElement())->getElement()->getType() != usds::USDS_UBYTE)
		throw "Failed at the step 4\n";

	// step 5
	tag = (usds::DictionaryArray*)dict.getTag(4);
	if (strcmp(tag->getName(), "struct") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_ARRAY
		|| ((usds::DictionaryArray*)tag->getElement())->getElement()->getType() != usds::USDS_ARRAY
		|| ((usds::DictionaryArray*)((usds::DictionaryArray*)tag->getElement())->getElement())->getElement()->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 5\n";

	// step 6
	usds::DictionaryStruct* element = (usds::DictionaryStruct*)((usds::DictionaryArray*)((usds::DictionaryArray*)tag->getElement())->getElement())->getElement();
	usds::DictionaryBaseType* field = element->getField(1);
	if (strcmp(field->getName(), "bool") != 0 || field->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 6\n";

	// step 7
	field = element->getField(2);
	if (strcmp(field->getName(), "byte") != 0 || field->getType() != usds::USDS_BYTE)
		throw "Failed at the step 7\n";

}

void DictionaryTextParserTest::test_13()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.0.0 {\n\
			1: struct[]\n\
			{\n\
				1: BOOLEAN[] bool;\n\
				2: BYTE[] byte;\n\
				3: UBYTE[] ubyte;\n\
				4: SHORT[] short;\n\
				5: USHORT[] ushort;\n\
				6: INT[] int;\n\
				7: UINT[] uint;\n\
				8: LONG[] long;\n\
				9: ULONG[] ulong;\n\
				10: FLOAT[] float;\n\
				11: DOUBLE[] double;\n\
				12: VARINT[] varint;\n\
				13: UVARINT[] uvarint;\n\
				16: struct[]\n\
				{\n\
					1: bool[] bool_tag_link;\n\
					2: BYTE byte;\n\
				};\n\
				14: STRING[] string;\n\
				15: STRING<UTF-8>[] string2;\n\
				17: bool bool2;\n\
				18: struct2[] struct_field;\n\
			};\n\
			2: BOOLEAN[] bool;\n\
			3: struct2\n\
			{\n\
				1: BOOLEAN bool = NULL;\n\
				2: BYTE byte = 0;\n\
			};\n\
			4: struct3\n\
			{\n\
				1: BOOLEAN bool;\n\
				2: struct2[] struct_field;\n\
				3: struct2 struct_field2;\n\
			};\n\
		}";

	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 4 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 0)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryArray* tag = (usds::DictionaryArray*)dict.getTag(1);
	if (strcmp(tag->getName(), "struct") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 2\n";

	// step 3
	usds::DictionaryArray* field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(1);
	if (strcmp(field->getName(), "bool") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 3\n";

	// step 4
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(2);
	if (strcmp(field->getName(), "byte") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_BYTE)
		throw "Failed at the step 4\n";

	// step 5
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(3);
	if (strcmp(field->getName(), "ubyte") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_UBYTE)
		throw "Failed at the step 5\n";

	// step 6
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(4);
	if (strcmp(field->getName(), "short") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_SHORT)
		throw "Failed at the step 6\n";

	// step 7
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(5);
	if (strcmp(field->getName(), "ushort") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_USHORT)
		throw "Failed at the step 7\n";

	// step 8
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(6);
	if (strcmp(field->getName(), "int") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_INT)
		throw "Failed at the step 8\n";

	// step 9
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(7);
	if (strcmp(field->getName(), "uint") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_UINT)
		throw "Failed at the step 9\n";

	// step 10
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(8);
	if (strcmp(field->getName(), "long") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_LONG)
		throw "Failed at the step 10\n";

	// step 11
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(9);
	if (strcmp(field->getName(), "ulong") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_ULONG)
		throw "Failed at the step 11\n";

	// step 12
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(10);
	if (strcmp(field->getName(), "float") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_FLOAT)
		throw "Failed at the step 12\n";

	// step 13
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(11);
	if (strcmp(field->getName(), "double") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_DOUBLE)
		throw "Failed at the step 13\n";

	// step 14
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(12);
	if (strcmp(field->getName(), "varint") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_VARINT)
		throw "Failed at the step 14\n";

	// step 15
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(13);
	if (strcmp(field->getName(), "uvarint") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_UVARINT)
		throw "Failed at the step 15\n";

	// step 16
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(14);
	if (strcmp(field->getName(), "string") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_STRING
		|| ((usds::DictionaryString*)field->getElement())->getDefaultEncode() != usds::USDS_NO_DEFAULT_ENCODE)
		throw "Failed at the step 16\n";

	// step 17
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(15);
	if (strcmp(field->getName(), "string2") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_STRING
		|| ((usds::DictionaryString*)field->getElement())->getDefaultEncode() != usds::USDS_UTF8)
		throw "Failed at the step 17\n";

	// step 18
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(16);
	if (strcmp(field->getName(), "struct") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_STRUCT
		|| ((usds::DictionaryStruct*)field->getElement())->getFieldNumber() != 2)
		throw "Failed at the step 18\n";

	// step 19
	usds::DictionaryBaseType* internal_field = ((usds::DictionaryStruct*)field->getElement())->getField(1);
	if (strcmp(internal_field->getName(), "bool_tag_link") != 0 || internal_field->getType() != usds::USDS_ARRAY)
		throw "Failed at the step 19\n";

	// step 20
	usds::DictionaryBaseType* internal_element = ((usds::DictionaryArray*)internal_field)->getElement();
	if (internal_element->getType() != usds::USDS_TAG)
		throw "Failed at the step 20\n";

	// step 21
	usds::DictionaryBaseType* internal_element_tag = ((usds::DictionaryTagLink*)internal_element)->getTag();
	if (strcmp(internal_element_tag->getName(), "bool") || internal_element_tag->getType() != usds::USDS_ARRAY || ((usds::DictionaryArray*)internal_element_tag)->getElement()->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 21\n";

	// step 22
	internal_field = ((usds::DictionaryStruct*)field->getElement())->getField(2);
	if (strcmp(internal_field->getName(), "byte") != 0 || internal_field->getType() != usds::USDS_BYTE)
		throw "Failed at the step 22\n";

	// step 23
	usds::DictionaryTagLink* tag_field = (usds::DictionaryTagLink*)((usds::DictionaryStruct*)tag->getElement())->getField(17);
	if (strcmp(tag_field->getName(), "bool2") != 0 || tag_field->getType() != usds::USDS_TAG)
		throw "Failed at the step 23\n";

	// step 24
	usds::DictionaryArray* array_tag_field = (usds::DictionaryArray*)tag_field->getTag();
	if (strcmp(array_tag_field->getName(), "bool") != 0 || array_tag_field->getType() != usds::USDS_ARRAY || array_tag_field->getElement()->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 24\n";




}

