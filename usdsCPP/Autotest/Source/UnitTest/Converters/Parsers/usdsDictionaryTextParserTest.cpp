#include "usdsAutotest.h"

#include "converters/usdsDictionaryTextParser.h"

#include "dictionary\usdsDictionary.h"
#include "dictionary/dictionaryBaseType.h"
#include "dictionary/dataTypes/dictionaryString.h"
#include "dictionary/dataTypes/dictionaryStruct.h"
#include "dictionary/dataTypes/dictionaryTagLink.h"

// Test simple types for array's element
void DictionaryTextParserTest::test_1()
{
	usds::DictionaryTextParser* pareser = new usds::DictionaryTextParser();
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
	pareser->parse(text_dict, usds::USDS_UTF8, &dict);
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
	usds::DictionaryTextParser* pareser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.0.1 {\
			1: STRING str1;\
			2: STRING<UTF-8> str2;\
		}";
	pareser->parse(text_dict, usds::USDS_UTF8, &dict);
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
	usds::DictionaryTextParser* pareser = new usds::DictionaryTextParser();
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
	pareser->parse(text_dict, usds::USDS_UTF8, &dict);
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
	usds::DictionaryTextParser* pareser = new usds::DictionaryTextParser();
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
	pareser->parse(text_dict, usds::USDS_UTF8, &dict);
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
	usds::DictionaryTextParser* pareser = new usds::DictionaryTextParser();
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
	pareser->parse(text_dict, usds::USDS_UTF8, &dict);
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
	usds::DictionaryTextParser* pareser = new usds::DictionaryTextParser();
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
	pareser->parse(text_dict, usds::USDS_UTF8, &dict);
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

// TODO autotests for all integers in text dictionary

void DictionaryTextParserTest::test_7()
{
	usds::DictionaryTextParser* pareser = new usds::DictionaryTextParser();
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
				15: FLOAT float = 0;\n\
				16: DOUBLE double = 0;\n\
				17: VARINT varint = 9223372036854775807;\n\
				18: VARINT varint2 = -9223372036854775808;\n\
				19: UVARINT uvarint = 18446744073709551615;\n\
				20: STRING string = \"Hello\";\n\
				21: STRING<UTF-8> string2 = \"\";\n\
			};\n\
		}";
	pareser->parse(text_dict, usds::USDS_UTF8, &dict);
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



}



