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
void DictionaryTextParserTestAutoId::test_1()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	
	// step 1
	const char* text_dict = 
		"USDS 888:MyLittleAPI 1.0 {\
			BOOLEAN bool;\
			BYTE byte;\
			UBYTE ubyte;\
			SHORT short;\
			USHORT ushort;\
			INT int;\
			UINT uint;\
			LONG long;\
			ULONG ulong;\
			FLOAT float;\
			DOUBLE double;\
			VARINT varint;\
			UVARINT uvarint;\
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

void DictionaryTextParserTestAutoId::test_2()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1 {\
			STRING str1;\
			STRING<UTF-8> str2;\
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

void DictionaryTextParserTestAutoId::test_3()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS 1:MyLittleAPI 1.1 {\
			struct\
			{\
				BOOLEAN bool;\
				BYTE byte;\
				UBYTE ubyte;\
				SHORT short;\
				USHORT ushort;\
				INT int;\
				UINT uint;\
				LONG long;\
				ULONG ulong;\
				FLOAT float;\
				DOUBLE double;\
				VARINT varint;\
				UVARINT uvarint;\
				STRING string;\
				STRING<UTF-8> string2;\
			};\
			struct2\
			{\
				struct internal_struct;\
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

void DictionaryTextParserTestAutoId::test_4()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS 0:MyLittleAPI 0.0 {\
			struct\
			{\
				BOOLEAN bool;\
				internal_struct\
				{\
					BOOLEAN bool;\
					BYTE byte;\
				};\
				BYTE byte;\
				internal_struct2\
				{\
					BYTE byte;\
					internal_internal_struct\
					{\
						BYTE byte;\
						BOOLEAN bool;\
					};\
					BOOLEAN bool;\
				};\
			};\
			BYTE byte;\
			struct2\
			{\
				BOOLEAN bool;\
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
	if (struct_tag->getFieldNumbers() != 4)
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
	if (((usds::DictionaryStruct*)field)->getFieldNumbers() != 2)
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
	if (((usds::DictionaryStruct*)field)->getFieldNumbers() != 3)
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
	if (((usds::DictionaryStruct*)field_int)->getFieldNumbers() != 2)
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

void DictionaryTextParserTestAutoId::test_5()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS 4294967295:MyLittleAPI 55.255 {\
			struct\
			{\
				BOOLEAN bool = NULL;\
				BYTE byte = NULL;\
				UBYTE ubyte = NULL;\
				SHORT short = NULL;\
				USHORT ushort = NULL;\
				INT int = NULL;\
				UINT uint = NULL;\
				LONG long = NULL;\
				ULONG ulong = NULL;\
				FLOAT float = NULL;\
				DOUBLE double = NULL;\
				VARINT varint = NULL;\
				UVARINT uvarint = NULL;\
				STRING string = NULL;\
				STRING<UTF-8> string2 = NULL;\
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


void DictionaryTextParserTestAutoId::test_6()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS 3000000000:MyLittleAPI 254.125\
		{\
			struct\
			{\
				int_struct\
				{\
					BYTE byte;\
				} = NULL;\
				byte tag_byte = NULL;\
			};\
			BYTE byte;\
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

void DictionaryTextParserTestAutoId::test_7()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS 4294967295:MyLittleAPI 55.255 {\n\
			struct\n\
			{\n\
				BOOLEAN bool = true;\n\
				BOOLEAN bool2 = false;\n\
				BYTE byte = 127;\n\
				BYTE byte2 = -128;\n\
				UBYTE ubyte = 255;\n\
				SHORT short = 32767;\n\
				SHORT short2 = -32768;\n\
				USHORT ushort = 65535;\n\
				INT int = 2147483647;\n\
				INT int2 = -2147483648;\n\
				UINT uint = 4294967295;\n\
				LONG long = 9223372036854775807;\n\
				LONG long2 = -9223372036854775808;\n\
				ULONG ulong = 18446744073709551615;\n\
				FLOAT float = 1.125e2;\n\
				DOUBLE double = -.125;\n\
				VARINT varint = 9223372036854775807;\n\
				VARINT varint2 = -9223372036854775808;\n\
				UVARINT uvarint = 18446744073709551615;\n\
				STRING string = \"Привет\\\"!\\\"\";\n\
				STRING<UTF-8> string2 = \"\";\n\
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

void DictionaryTextParserTestAutoId::test_8()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	
	// step 1
	const char* text_dict =
		"USDS MyLittleAPI {\n\
			BOOLEAN[] bool;\n\
			BYTE[] byte;\n\
			UBYTE[] ubyte;\n\
			SHORT[] short;\n\
			USHORT[] ushort;\n\
			INT[] int;\n\
			UINT[] uint;\n\
			LONG[] long;\n\
			ULONG[] ulong;\n\
			FLOAT[] float;\n\
			DOUBLE[] double;\n\
			VARINT[] varint;\n\
			UVARINT[] uvarint;\n\
			STRING[] string;\n\
			STRING<UTF-8>[] string2;\n\
			struct[]\n\
			{\n\
				BOOLEAN bool;\n\
				BYTE byte;\n\
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

void DictionaryTextParserTestAutoId::test_9()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI {\n\
			BOOLEAN[][] bool;\n\
			BYTE[][][] byte;\n\
			UBYTE[][][][] ubyte;\n\
			struct[][][]\n\
			{\n\
				BOOLEAN bool;\n\
				BYTE byte;\n\
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

void DictionaryTextParserTestAutoId::test_10()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI {\n\
			struct[]\n\
			{\n\
				BOOLEAN[] bool;\n\
				BYTE[] byte;\n\
				UBYTE[] ubyte;\n\
				SHORT[] short;\n\
				USHORT[] ushort;\n\
				INT[] int;\n\
				UINT[] uint;\n\
				LONG[] long;\n\
				ULONG[] ulong;\n\
				FLOAT[] float;\n\
				DOUBLE[] double;\n\
				VARINT[] varint;\n\
				UVARINT[] uvarint;\n\
				STRING[] string;\n\
				STRING<UTF-8>[] string2;\n\
				struct[]\n\
				{\n\
					bool[] bool_tag_link;\n\
					BYTE byte;\n\
				};\n\
				bool bool2;\n\
				struct2[] struct_field;\n\
			};\n\
			BOOLEAN[] bool;\n\
			struct2\n\
			{\n\
				BOOLEAN bool = NULL;\n\
				BYTE byte = 110;\n\
			};\n\
			struct3\n\
			{\n\
				INT int;\n\
				struct2[] struct_field;\n\
				struct2 struct_field2;\n\
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
		|| ((usds::DictionaryStruct*)field->getElement())->getFieldNumbers() != 2)
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

	// step 25
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(18);
	if (strcmp(field->getName(), "struct_field") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_TAG)
		throw "Failed at the step 25\n";

	// step 26
	usds::DictionaryStruct* tag_struct = (usds::DictionaryStruct*)((usds::DictionaryTagLink*)(usds::DictionaryTagLink*)field->getElement())->getTag();
	if (strcmp(tag_struct->getName(), "struct2") != 0 || tag_struct->getType() != usds::USDS_STRUCT || tag_struct->getFieldNumbers() != 2)
		throw "Failed at the step 26\n";

	// step 27
	usds::DictionaryBoolean* boolean_struct_filed = (usds::DictionaryBoolean*)tag_struct->getField(1);
	if (strcmp(boolean_struct_filed->getName(), "bool") != 0 || boolean_struct_filed->getType() != usds::USDS_BOOLEAN || boolean_struct_filed->isNullable() != true)
		throw "Failed at the step 27\n";

	// step 28
	usds::DictionaryByte* byte_struct_filed = (usds::DictionaryByte*)tag_struct->getField(2);
	if (strcmp(byte_struct_filed->getName(), "byte") != 0 || byte_struct_filed->getType() != usds::USDS_BYTE || byte_struct_filed->hasDefaultValue()!= true || byte_struct_filed->getDefaultValue() != 110)
		throw "Failed at the step 28\n";

	// step 29
	tag = (usds::DictionaryArray*)dict.getTag(2);
	if (strcmp(tag->getName(), "bool") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 29\n";

	// step 30
	tag_struct = (usds::DictionaryStruct*)dict.getTag(3);
	if (strcmp(tag_struct->getName(), "struct2") != 0 || tag_struct->getType() != usds::USDS_STRUCT || tag_struct->getFieldNumbers() != 2)
		throw "Failed at the step 30\n";

	// step 31
	boolean_struct_filed = (usds::DictionaryBoolean*)tag_struct->getField(1);
	if (strcmp(boolean_struct_filed->getName(), "bool") != 0 || boolean_struct_filed->getType() != usds::USDS_BOOLEAN || boolean_struct_filed->isNullable() != true)
		throw "Failed at the step 31\n";

	// step 32
	byte_struct_filed = (usds::DictionaryByte*)tag_struct->getField(2);
	if (strcmp(byte_struct_filed->getName(), "byte") != 0 || byte_struct_filed->getType() != usds::USDS_BYTE || byte_struct_filed->hasDefaultValue() != true || byte_struct_filed->getDefaultValue() != 110)
		throw "Failed at the step 32\n";

	// step 33
	tag_struct = (usds::DictionaryStruct*)dict.getTag(4);
	if (strcmp(tag_struct->getName(), "struct3") != 0 || tag_struct->getType() != usds::USDS_STRUCT || tag_struct->getFieldNumbers() != 3)
		throw "Failed at the step 33\n";

	// step 34
	usds::DictionaryInt* int_struct_filed = (usds::DictionaryInt*)tag_struct->getField(1);
	if (strcmp(int_struct_filed->getName(), "int") != 0 || int_struct_filed->getType() != usds::USDS_INT)
		throw "Failed at the step 34\n";

	// step 35
	field = (usds::DictionaryArray*)tag_struct->getField(2);
	if (strcmp(field->getName(), "struct_field") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_TAG)
		throw "Failed at the step 35\n";

	// step 36
	usds::DictionaryStruct* internal_tag_struct = (usds::DictionaryStruct*)((usds::DictionaryTagLink*)field->getElement())->getTag();
	if (strcmp(internal_tag_struct->getName(), "struct2") != 0 || internal_tag_struct->getType() != usds::USDS_STRUCT || internal_tag_struct->getFieldNumbers() != 2)
		throw "Failed at the step 36\n";

	// step 37
	boolean_struct_filed = (usds::DictionaryBoolean*)internal_tag_struct->getField(1);
	if (strcmp(boolean_struct_filed->getName(), "bool") != 0 || boolean_struct_filed->getType() != usds::USDS_BOOLEAN || boolean_struct_filed->isNullable() != true)
		throw "Failed at the step 37\n";

	// step 38
	byte_struct_filed = (usds::DictionaryByte*)internal_tag_struct->getField(2);
	if (strcmp(byte_struct_filed->getName(), "byte") != 0 || byte_struct_filed->getType() != usds::USDS_BYTE || byte_struct_filed->hasDefaultValue() != true || byte_struct_filed->getDefaultValue() != 110)
		throw "Failed at the step 38\n";

	// step 39
	tag_field = (usds::DictionaryTagLink*)tag_struct->getField(3);
	if (strcmp(tag_field->getName(), "struct_field2") != 0 || tag_field->getType() != usds::USDS_TAG || tag_field->getTag()->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 39\n";

	// step 40
	tag_struct = (usds::DictionaryStruct*)tag_field->getTag();
	if (strcmp(tag_struct->getName(), "struct2") != 0 || tag_struct->getType() != usds::USDS_STRUCT || tag_struct->getFieldNumbers() != 2)
		throw "Failed at the step 40\n";

	// step 41
	boolean_struct_filed = (usds::DictionaryBoolean*)tag_struct->getField(1);
	if (strcmp(boolean_struct_filed->getName(), "bool") != 0 || boolean_struct_filed->getType() != usds::USDS_BOOLEAN || boolean_struct_filed->isNullable() != true)
		throw "Failed at the step 41\n";

	// step 42
	byte_struct_filed = (usds::DictionaryByte*)tag_struct->getField(2);
	if (strcmp(byte_struct_filed->getName(), "byte") != 0 || byte_struct_filed->getType() != usds::USDS_BYTE || byte_struct_filed->hasDefaultValue() != true || byte_struct_filed->getDefaultValue() != 110)
		throw "Failed at the step 42\n";


}

void DictionaryTextParserTestAutoId::test_11()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI {\n\
			struct[][]\n\
			{\n\
				BOOLEAN[][] bool;\n\
				BYTE[][][] byte;\n\
				struct[][][]\n\
				{\n\
					bool[] bool_tag_link;\n\
					BYTE byte;\n\
				};\n\
				STRING<UTF-8>[][] string;\n\
				bool bool2;\n\
				struct2[] struct_field;\n\
			};\n\
			BOOLEAN[][][] bool;\n\
			struct2[][]\n\
			{\n\
				BOOLEAN bool = NULL;\n\
				BYTE byte = 110;\n\
			};\n\
		}";

	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 3 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 0)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryArray* tag = (usds::DictionaryArray*)dict.getTag(1);
	if (strcmp(tag->getName(), "struct") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_ARRAY)
		throw "Failed at the step 2\n";
	{
		// step 3
		usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)((usds::DictionaryArray*)tag->getElement())->getElement();
		if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getFieldNumbers() != 6)
			throw "Failed at the step 3\n";

		// step 4
		usds::DictionaryArray* array_field = (usds::DictionaryArray*)struct_tag->getField(1);
		if (strcmp(array_field->getName(), "bool") != 0 || array_field->getType() != usds::USDS_ARRAY || array_field->getElement()->getType() != usds::USDS_ARRAY
			|| ((usds::DictionaryArray*)array_field->getElement())->getElement()->getType() != usds::USDS_BOOLEAN)
			throw "Failed at the step 4\n";

		// step 5
		array_field = (usds::DictionaryArray*)struct_tag->getField(2);
		if (strcmp(array_field->getName(), "byte") != 0 || array_field->getType() != usds::USDS_ARRAY || array_field->getElement()->getType() != usds::USDS_ARRAY
			|| ((usds::DictionaryArray*)array_field->getElement())->getElement()->getType() != usds::USDS_ARRAY
			|| ((usds::DictionaryArray*)((usds::DictionaryArray*)array_field->getElement())->getElement())->getElement()->getType() != usds::USDS_BYTE)
			throw "Failed at the step 5\n";

		// step 6
		array_field = (usds::DictionaryArray*)struct_tag->getField(3);
		if (strcmp(array_field->getName(), "struct") != 0 || array_field->getType() != usds::USDS_ARRAY || array_field->getElement()->getType() != usds::USDS_ARRAY
			|| ((usds::DictionaryArray*)array_field->getElement())->getElement()->getType() != usds::USDS_ARRAY
			|| ((usds::DictionaryArray*)((usds::DictionaryArray*)array_field->getElement())->getElement())->getElement()->getType() != usds::USDS_STRUCT)
			throw "Failed at the step 6\n";

		// step 7
		usds::DictionaryStruct* internal_struct = (usds::DictionaryStruct*)((usds::DictionaryArray*)((usds::DictionaryArray*)array_field->getElement())->getElement())->getElement();
		if (internal_struct->getType() != usds::USDS_STRUCT || internal_struct->getFieldNumbers() != 2)
			throw "Failed at the step 7\n";
		{
			// step 8
			usds::DictionaryArray* internal_array_field = (usds::DictionaryArray*)internal_struct->getField(1);
			if (strcmp(internal_array_field->getName(), "bool_tag_link") != 0 || internal_array_field->getType() != usds::USDS_ARRAY || internal_array_field->getElement()->getType() != usds::USDS_TAG)
				throw "Failed at the step 8\n";

			// step 9
			usds::DictionaryArray* internal_tag_link = (usds::DictionaryArray*)((usds::DictionaryTagLink*)internal_array_field->getElement())->getTag();
			if (strcmp(internal_tag_link->getName(), "bool") != 0 || internal_tag_link->getType() != usds::USDS_ARRAY || internal_tag_link->getElement()->getType() != usds::USDS_ARRAY
				|| ((usds::DictionaryArray*)internal_tag_link->getElement())->getElement()->getType() != usds::USDS_ARRAY
				|| ((usds::DictionaryArray*)((usds::DictionaryArray*)internal_tag_link->getElement())->getElement())->getElement()->getType() != usds::USDS_BOOLEAN)
				throw "Failed at the step 9\n";

			// step 10
			usds::DictionaryByte* internal_byte_field = (usds::DictionaryByte*)internal_struct->getField(2);
			if (strcmp(internal_byte_field->getName(), "byte") != 0 || internal_byte_field->getType() != usds::USDS_BYTE)
				throw "Failed at the step 10\n";
		}

		// step 11
		array_field = (usds::DictionaryArray*)struct_tag->getField(4);
		if (strcmp(array_field->getName(), "string") != 0 || array_field->getType() != usds::USDS_ARRAY || array_field->getElement()->getType() != usds::USDS_ARRAY
			|| ((usds::DictionaryArray*)array_field->getElement())->getElement()->getType() != usds::USDS_STRING
			|| ((usds::DictionaryString*)((usds::DictionaryArray*)array_field->getElement())->getElement())->getDefaultEncode() != usds::USDS_UTF8)
			throw "Failed at the step 11\n";

		// step 12
		usds::DictionaryTagLink* tag_field = (usds::DictionaryTagLink*)struct_tag->getField(5);
		if (strcmp(tag_field->getName(), "bool2") != 0 || tag_field->getType() != usds::USDS_TAG)
			throw "Failed at the step 12\n";

		{
			// step 13
			usds::DictionaryArray* internal_tag_link = (usds::DictionaryArray*)tag_field->getTag();
			if (strcmp(internal_tag_link->getName(), "bool") != 0 || internal_tag_link->getType() != usds::USDS_ARRAY || internal_tag_link->getElement()->getType() != usds::USDS_ARRAY
				|| ((usds::DictionaryArray*)internal_tag_link->getElement())->getElement()->getType() != usds::USDS_ARRAY
				|| ((usds::DictionaryArray*)((usds::DictionaryArray*)internal_tag_link->getElement())->getElement())->getElement()->getType() != usds::USDS_BOOLEAN)
				throw "Failed at the step 13\n";
		}

		// step 14
		array_field = (usds::DictionaryArray*)struct_tag->getField(6);
		if (strcmp(array_field->getName(), "struct_field") != 0 || array_field->getType() != usds::USDS_ARRAY || array_field->getElement()->getType() != usds::USDS_TAG)
			throw "Failed at the step 14\n";
		{
			// step 15
			usds::DictionaryArray* internal_array_struct = (usds::DictionaryArray*)((usds::DictionaryTagLink*)array_field->getElement())->getTag();
			if (strcmp(internal_array_struct->getName(), "struct2") != 0 || internal_array_struct->getType() != usds::USDS_ARRAY || internal_array_struct->getElement()->getType() != usds::USDS_ARRAY
				|| ((usds::DictionaryArray*)internal_array_struct->getElement())->getElement()->getType() != usds::USDS_STRUCT)
				throw "Failed at the step 15\n";
			
			{
				// step 16
				usds::DictionaryStruct* internal_struct_tag = (usds::DictionaryStruct*)((usds::DictionaryArray*)internal_array_struct->getElement())->getElement();
				if (internal_struct_tag->getType() != usds::USDS_STRUCT || internal_struct_tag->getFieldNumbers() != 2)
					throw "Failed at the step 16\n";

				// step 17
				usds::DictionaryBoolean* internal_boolean_filed = (usds::DictionaryBoolean*)internal_struct_tag->getField(1);
				if (strcmp(internal_boolean_filed->getName(), "bool") != 0 || internal_boolean_filed->getType() != usds::USDS_BOOLEAN || internal_boolean_filed->isNullable() != true)
					throw "Failed at the step 17\n";

				// step 18
				usds::DictionaryByte* internal_byte_filed = (usds::DictionaryByte*)internal_struct_tag->getField(2);
				if (strcmp(internal_byte_filed->getName(), "byte") != 0 || internal_byte_filed->getType() != usds::USDS_BYTE || internal_byte_filed->hasDefaultValue() != true || internal_byte_filed->getDefaultValue() != 110)
					throw "Failed at the step 18\n";
			}
		}
	}

	// step 19
	tag = (usds::DictionaryArray*)dict.getTag(2);
	if (strcmp(tag->getName(), "bool") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_ARRAY
		|| ((usds::DictionaryArray*)tag->getElement())->getElement()->getType() != usds::USDS_ARRAY
		|| ((usds::DictionaryArray*)((usds::DictionaryArray*)tag->getElement())->getElement())->getElement()->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 19\n";

	// step 20
	tag = (usds::DictionaryArray*)dict.getTag(3);
	if (strcmp(tag->getName(), "struct2") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_ARRAY
		|| ((usds::DictionaryArray*)tag->getElement())->getElement()->getType() != usds::USDS_STRUCT)
		throw "Failed at the step 20\n";

	{
		// step 21
		usds::DictionaryStruct* internal_struct_tag = (usds::DictionaryStruct*)((usds::DictionaryArray*)tag->getElement())->getElement();
		if (internal_struct_tag->getType() != usds::USDS_STRUCT || internal_struct_tag->getFieldNumbers() != 2)
			throw "Failed at the step 21\n";

		// step 22
		usds::DictionaryBoolean* internal_boolean_filed = (usds::DictionaryBoolean*)internal_struct_tag->getField(1);
		if (strcmp(internal_boolean_filed->getName(), "bool") != 0 || internal_boolean_filed->getType() != usds::USDS_BOOLEAN || internal_boolean_filed->isNullable() != true)
			throw "Failed at the step 22\n";

		// step 23
		usds::DictionaryByte* internal_byte_filed = (usds::DictionaryByte*)internal_struct_tag->getField(2);
		if (strcmp(internal_byte_filed->getName(), "byte") != 0 || internal_byte_filed->getType() != usds::USDS_BYTE || internal_byte_filed->hasDefaultValue() != true || internal_byte_filed->getDefaultValue() != 110)
			throw "Failed at the step 23\n";
	}
}

void DictionaryTextParserTestAutoId::test_12()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI {\n\
			struct[]\n\
			{\n\
				BOOLEAN[] bool = NULL;\n\
				BYTE[] byte = NULL;\n\
				UBYTE[] ubyte = NULL;\n\
				SHORT[] short = NULL;\n\
				USHORT[] ushort = NULL;\n\
				INT[] int = NULL;\n\
				UINT[] uint = NULL;\n\
				LONG[] long = NULL;\n\
				ULONG[] ulong = NULL;\n\
				FLOAT[] float = NULL;\n\
				DOUBLE[] double = NULL;\n\
				VARINT[] varint = NULL;\n\
				UVARINT[] uvarint = NULL;\n\
				STRING[] string = NULL;\n\
				STRING<UTF-8>[] string2 = NULL;\n\
				struct[]\n\
				{\n\
					bool[] bool_tag_link = NULL;\n\
					BYTE byte;\n\
				} = NULL;\n\
				bool bool2 = NULL;\n\
				struct2[] struct_field = NULL;\n\
			};\n\
			BOOLEAN[] bool;\n\
			struct2\n\
			{\n\
				BOOLEAN bool = NULL;\n\
				BYTE byte = 110;\n\
			};\n\
			struct3\n\
			{\n\
				INT int;\n\
				struct2[] struct_field = NULL;\n\
				struct2 struct_field2 = NULL;\n\
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
	if (strcmp(field->getName(), "bool") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_BOOLEAN || field->isNullable() != true)
		throw "Failed at the step 3\n";

	// step 4
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(2);
	if (strcmp(field->getName(), "byte") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_BYTE || field->isNullable() != true)
		throw "Failed at the step 4\n";

	// step 5
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(3);
	if (strcmp(field->getName(), "ubyte") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_UBYTE || field->isNullable() != true)
		throw "Failed at the step 5\n";

	// step 6
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(4);
	if (strcmp(field->getName(), "short") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_SHORT || field->isNullable() != true)
		throw "Failed at the step 6\n";

	// step 7
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(5);
	if (strcmp(field->getName(), "ushort") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_USHORT || field->isNullable() != true)
		throw "Failed at the step 7\n";

	// step 8
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(6);
	if (strcmp(field->getName(), "int") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_INT || field->isNullable() != true)
		throw "Failed at the step 8\n";

	// step 9
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(7);
	if (strcmp(field->getName(), "uint") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_UINT || field->isNullable() != true)
		throw "Failed at the step 9\n";

	// step 10
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(8);
	if (strcmp(field->getName(), "long") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_LONG || field->isNullable() != true)
		throw "Failed at the step 10\n";

	// step 11
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(9);
	if (strcmp(field->getName(), "ulong") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_ULONG || field->isNullable() != true)
		throw "Failed at the step 11\n";

	// step 12
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(10);
	if (strcmp(field->getName(), "float") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_FLOAT || field->isNullable() != true)
		throw "Failed at the step 12\n";

	// step 13
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(11);
	if (strcmp(field->getName(), "double") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_DOUBLE || field->isNullable() != true)
		throw "Failed at the step 13\n";

	// step 14
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(12);
	if (strcmp(field->getName(), "varint") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_VARINT || field->isNullable() != true)
		throw "Failed at the step 14\n";

	// step 15
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(13);
	if (strcmp(field->getName(), "uvarint") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_UVARINT || field->isNullable() != true)
		throw "Failed at the step 15\n";

	// step 16
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(14);
	if (strcmp(field->getName(), "string") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_STRING || field->isNullable() != true
		|| ((usds::DictionaryString*)field->getElement())->getDefaultEncode() != usds::USDS_NO_DEFAULT_ENCODE)
		throw "Failed at the step 16\n";

	// step 17
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(15);
	if (strcmp(field->getName(), "string2") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_STRING || field->isNullable() != true
		|| ((usds::DictionaryString*)field->getElement())->getDefaultEncode() != usds::USDS_UTF8)
		throw "Failed at the step 17\n";

	// step 18
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(16);
	if (strcmp(field->getName(), "struct") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_STRUCT || field->isNullable() != true
		|| ((usds::DictionaryStruct*)field->getElement())->getFieldNumbers() != 2)
		throw "Failed at the step 18\n";

	// step 19
	usds::DictionaryBaseType* internal_field = ((usds::DictionaryStruct*)field->getElement())->getField(1);
	if (strcmp(internal_field->getName(), "bool_tag_link") != 0 || internal_field->getType() != usds::USDS_ARRAY || internal_field->isNullable() != true)
		throw "Failed at the step 19\n";

	// step 20
	usds::DictionaryBaseType* internal_element = ((usds::DictionaryArray*)internal_field)->getElement();
	if (internal_element->getType() != usds::USDS_TAG || internal_element->isNullable() != false)
		throw "Failed at the step 20\n";

	// step 21
	usds::DictionaryBaseType* internal_element_tag = ((usds::DictionaryTagLink*)internal_element)->getTag();
	if (strcmp(internal_element_tag->getName(), "bool") || internal_element_tag->getType() != usds::USDS_ARRAY || internal_element_tag->isNullable() != false
		|| ((usds::DictionaryArray*)internal_element_tag)->getElement()->getType() != usds::USDS_BOOLEAN)
		throw "Failed at the step 21\n";

	// step 22
	internal_field = ((usds::DictionaryStruct*)field->getElement())->getField(2);
	if (strcmp(internal_field->getName(), "byte") != 0 || internal_field->getType() != usds::USDS_BYTE || internal_field->isNullable() != false)
		throw "Failed at the step 22\n";

	// step 23
	usds::DictionaryTagLink* tag_field = (usds::DictionaryTagLink*)((usds::DictionaryStruct*)tag->getElement())->getField(17);
	if (strcmp(tag_field->getName(), "bool2") != 0 || tag_field->getType() != usds::USDS_TAG || tag_field->isNullable() != true)
		throw "Failed at the step 23\n";

	// step 24
	usds::DictionaryArray* array_tag_field = (usds::DictionaryArray*)tag_field->getTag();
	if (strcmp(array_tag_field->getName(), "bool") != 0 || array_tag_field->getType() != usds::USDS_ARRAY || array_tag_field->getElement()->getType() != usds::USDS_BOOLEAN || array_tag_field->isNullable() != false)
		throw "Failed at the step 24\n";

	// step 25
	field = (usds::DictionaryArray*)((usds::DictionaryStruct*)tag->getElement())->getField(18);
	if (strcmp(field->getName(), "struct_field") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_TAG || field->isNullable() != true)
		throw "Failed at the step 25\n";

	// step 26
	usds::DictionaryStruct* tag_struct = (usds::DictionaryStruct*)((usds::DictionaryTagLink*)(usds::DictionaryTagLink*)field->getElement())->getTag();
	if (strcmp(tag_struct->getName(), "struct2") != 0 || tag_struct->getType() != usds::USDS_STRUCT || tag_struct->getFieldNumbers() != 2 || tag_struct->isNullable() != false)
		throw "Failed at the step 26\n";

	// step 27
	usds::DictionaryBoolean* boolean_struct_filed = (usds::DictionaryBoolean*)tag_struct->getField(1);
	if (strcmp(boolean_struct_filed->getName(), "bool") != 0 || boolean_struct_filed->getType() != usds::USDS_BOOLEAN || boolean_struct_filed->isNullable() != true)
		throw "Failed at the step 27\n";

	// step 28
	usds::DictionaryByte* byte_struct_filed = (usds::DictionaryByte*)tag_struct->getField(2);
	if (strcmp(byte_struct_filed->getName(), "byte") != 0 || byte_struct_filed->getType() != usds::USDS_BYTE || byte_struct_filed->hasDefaultValue() != true || byte_struct_filed->getDefaultValue() != 110)
		throw "Failed at the step 28\n";

	// step 29
	tag = (usds::DictionaryArray*)dict.getTag(2);
	if (strcmp(tag->getName(), "bool") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_BOOLEAN || tag->isNullable() != false)
		throw "Failed at the step 29\n";

	// step 30
	tag_struct = (usds::DictionaryStruct*)dict.getTag(3);
	if (strcmp(tag_struct->getName(), "struct2") != 0 || tag_struct->getType() != usds::USDS_STRUCT || tag_struct->getFieldNumbers() != 2 || tag_struct->isNullable() != false)
		throw "Failed at the step 30\n";

	// step 31
	boolean_struct_filed = (usds::DictionaryBoolean*)tag_struct->getField(1);
	if (strcmp(boolean_struct_filed->getName(), "bool") != 0 || boolean_struct_filed->getType() != usds::USDS_BOOLEAN || boolean_struct_filed->isNullable() != true)
		throw "Failed at the step 31\n";

	// step 32
	byte_struct_filed = (usds::DictionaryByte*)tag_struct->getField(2);
	if (strcmp(byte_struct_filed->getName(), "byte") != 0 || byte_struct_filed->getType() != usds::USDS_BYTE || byte_struct_filed->hasDefaultValue() != true || byte_struct_filed->getDefaultValue() != 110)
		throw "Failed at the step 32\n";

	// step 33
	tag_struct = (usds::DictionaryStruct*)dict.getTag(4);
	if (strcmp(tag_struct->getName(), "struct3") != 0 || tag_struct->getType() != usds::USDS_STRUCT || tag_struct->getFieldNumbers() != 3 || tag_struct->isNullable() != false)
		throw "Failed at the step 33\n";

	// step 34
	usds::DictionaryInt* int_struct_filed = (usds::DictionaryInt*)tag_struct->getField(1);
	if (strcmp(int_struct_filed->getName(), "int") != 0 || int_struct_filed->getType() != usds::USDS_INT || int_struct_filed->isNullable() != false)
		throw "Failed at the step 34\n";

	// step 35
	field = (usds::DictionaryArray*)tag_struct->getField(2);
	if (strcmp(field->getName(), "struct_field") != 0 || field->getType() != usds::USDS_ARRAY || field->getElement()->getType() != usds::USDS_TAG || field->isNullable() != true)
		throw "Failed at the step 35\n";

	// step 36
	usds::DictionaryStruct* internal_tag_struct = (usds::DictionaryStruct*)((usds::DictionaryTagLink*)field->getElement())->getTag();
	if (strcmp(internal_tag_struct->getName(), "struct2") != 0 || internal_tag_struct->getType() != usds::USDS_STRUCT || internal_tag_struct->getFieldNumbers() != 2 || internal_tag_struct->isNullable() != false)
		throw "Failed at the step 36\n";

	// step 37
	boolean_struct_filed = (usds::DictionaryBoolean*)internal_tag_struct->getField(1);
	if (strcmp(boolean_struct_filed->getName(), "bool") != 0 || boolean_struct_filed->getType() != usds::USDS_BOOLEAN || boolean_struct_filed->isNullable() != true)
		throw "Failed at the step 37\n";

	// step 38
	byte_struct_filed = (usds::DictionaryByte*)internal_tag_struct->getField(2);
	if (strcmp(byte_struct_filed->getName(), "byte") != 0 || byte_struct_filed->getType() != usds::USDS_BYTE || byte_struct_filed->hasDefaultValue() != true || byte_struct_filed->getDefaultValue() != 110)
		throw "Failed at the step 38\n";

	// step 39
	tag_field = (usds::DictionaryTagLink*)tag_struct->getField(3);
	if (strcmp(tag_field->getName(), "struct_field2") != 0 || tag_field->getType() != usds::USDS_TAG || tag_field->getTag()->getType() != usds::USDS_STRUCT || tag_field->isNullable() != true)
		throw "Failed at the step 39\n";

	// step 40
	tag_struct = (usds::DictionaryStruct*)tag_field->getTag();
	if (strcmp(tag_struct->getName(), "struct2") != 0 || tag_struct->getType() != usds::USDS_STRUCT || tag_struct->getFieldNumbers() != 2 || tag_struct->isNullable() != false)
		throw "Failed at the step 40\n";

	// step 41
	boolean_struct_filed = (usds::DictionaryBoolean*)tag_struct->getField(1);
	if (strcmp(boolean_struct_filed->getName(), "bool") != 0 || boolean_struct_filed->getType() != usds::USDS_BOOLEAN || boolean_struct_filed->isNullable() != true)
		throw "Failed at the step 41\n";

	// step 42
	byte_struct_filed = (usds::DictionaryByte*)tag_struct->getField(2);
	if (strcmp(byte_struct_filed->getName(), "byte") != 0 || byte_struct_filed->getType() != usds::USDS_BYTE || byte_struct_filed->hasDefaultValue() != true || byte_struct_filed->getDefaultValue() != 110)
		throw "Failed at the step 42\n";

}
void DictionaryTextParserTestAutoId::test_13()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI {\n\
			struct[][]\n\
			{\n\
				BOOLEAN[][] bool = NULL;\n\
				BYTE[][][] byte = NULL;\n\
				struct[][][]\n\
				{\n\
					bool[] bool_tag_link = NULL;\n\
					BYTE byte;\n\
				} = NULL;\n\
				STRING<UTF-8>[][] string = NULL;\n\
				bool bool2 = NULL;\n\
				struct2[] struct_field = NULL;\n\
			};\n\
			BOOLEAN[][][] bool;\n\
			struct2[][]\n\
			{\n\
				BOOLEAN bool = NULL;\n\
				BYTE byte = 110;\n\
			};\n\
		}";

	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 3 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 0)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryArray* tag = (usds::DictionaryArray*)dict.getTag(1);
	if (strcmp(tag->getName(), "struct") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_ARRAY || tag->isNullable() != false || tag->getElement()->isNullable() != false)
		throw "Failed at the step 2\n";
	{
		// step 3
		usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)((usds::DictionaryArray*)tag->getElement())->getElement();
		if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getFieldNumbers() != 6 || struct_tag->isNullable() != false)
			throw "Failed at the step 3\n";

		// step 4
		usds::DictionaryArray* array_field = (usds::DictionaryArray*)struct_tag->getField(1);
		if (strcmp(array_field->getName(), "bool") != 0 || array_field->getType() != usds::USDS_ARRAY || array_field->getElement()->getType() != usds::USDS_ARRAY
			|| ((usds::DictionaryArray*)array_field->getElement())->getElement()->getType() != usds::USDS_BOOLEAN
			|| array_field->isNullable() != true
			|| array_field->getElement()->isNullable() != false
			|| ((usds::DictionaryArray*)array_field->getElement())->getElement()->isNullable() != false)
			throw "Failed at the step 4\n";

		// step 5
		array_field = (usds::DictionaryArray*)struct_tag->getField(2);
		if (strcmp(array_field->getName(), "byte") != 0 || array_field->getType() != usds::USDS_ARRAY || array_field->getElement()->getType() != usds::USDS_ARRAY
			|| ((usds::DictionaryArray*)array_field->getElement())->getElement()->getType() != usds::USDS_ARRAY
			|| ((usds::DictionaryArray*)((usds::DictionaryArray*)array_field->getElement())->getElement())->getElement()->getType() != usds::USDS_BYTE
			|| array_field->isNullable() != true
			|| array_field->getElement()->isNullable() != false
			|| ((usds::DictionaryArray*)array_field->getElement())->getElement()->isNullable() != false
			|| ((usds::DictionaryArray*)((usds::DictionaryArray*)array_field->getElement())->getElement())->getElement()->isNullable() != false
		)
			throw "Failed at the step 5\n";

		// step 6
		array_field = (usds::DictionaryArray*)struct_tag->getField(3);
		if (strcmp(array_field->getName(), "struct") != 0 || array_field->getType() != usds::USDS_ARRAY || array_field->getElement()->getType() != usds::USDS_ARRAY
			|| ((usds::DictionaryArray*)array_field->getElement())->getElement()->getType() != usds::USDS_ARRAY
			|| ((usds::DictionaryArray*)((usds::DictionaryArray*)array_field->getElement())->getElement())->getElement()->getType() != usds::USDS_STRUCT
			|| array_field->isNullable() != true
			|| array_field->getElement()->isNullable() != false
			|| ((usds::DictionaryArray*)array_field->getElement())->getElement()->isNullable() != false
			|| ((usds::DictionaryArray*)((usds::DictionaryArray*)array_field->getElement())->getElement())->getElement()->isNullable() != false
		)
			throw "Failed at the step 6\n";

		// step 7
		usds::DictionaryStruct* internal_struct = (usds::DictionaryStruct*)((usds::DictionaryArray*)((usds::DictionaryArray*)array_field->getElement())->getElement())->getElement();
		if (internal_struct->getType() != usds::USDS_STRUCT || internal_struct->getFieldNumbers() != 2 || internal_struct->isNullable() != false)
			throw "Failed at the step 7\n";
		{
			// step 8
			usds::DictionaryArray* internal_array_field = (usds::DictionaryArray*)internal_struct->getField(1);
			if (strcmp(internal_array_field->getName(), "bool_tag_link") != 0 || internal_array_field->getType() != usds::USDS_ARRAY || internal_array_field->getElement()->getType() != usds::USDS_TAG
				|| internal_array_field->isNullable() != true
				|| internal_array_field->getElement()->isNullable() != false
			)
				throw "Failed at the step 8\n";

			// step 9
			usds::DictionaryArray* internal_tag_link = (usds::DictionaryArray*)((usds::DictionaryTagLink*)internal_array_field->getElement())->getTag();
			if (strcmp(internal_tag_link->getName(), "bool") != 0 || internal_tag_link->getType() != usds::USDS_ARRAY || internal_tag_link->getElement()->getType() != usds::USDS_ARRAY
				|| ((usds::DictionaryArray*)internal_tag_link->getElement())->getElement()->getType() != usds::USDS_ARRAY
				|| ((usds::DictionaryArray*)((usds::DictionaryArray*)internal_tag_link->getElement())->getElement())->getElement()->getType() != usds::USDS_BOOLEAN
				|| internal_tag_link->isNullable() != false
				|| internal_tag_link->getElement()->isNullable() != false
				|| ((usds::DictionaryArray*)internal_tag_link->getElement())->getElement()->isNullable() != false
				|| ((usds::DictionaryArray*)((usds::DictionaryArray*)internal_tag_link->getElement())->getElement())->getElement()->isNullable() != false
			)
				throw "Failed at the step 9\n";

			// step 10
			usds::DictionaryByte* internal_byte_field = (usds::DictionaryByte*)internal_struct->getField(2);
			if (strcmp(internal_byte_field->getName(), "byte") != 0 || internal_byte_field->getType() != usds::USDS_BYTE || internal_byte_field->isNullable() != false)
				throw "Failed at the step 10\n";
		}

		// step 11
		array_field = (usds::DictionaryArray*)struct_tag->getField(4);
		if (strcmp(array_field->getName(), "string") != 0 || array_field->getType() != usds::USDS_ARRAY || array_field->getElement()->getType() != usds::USDS_ARRAY
			|| ((usds::DictionaryArray*)array_field->getElement())->getElement()->getType() != usds::USDS_STRING
			|| ((usds::DictionaryString*)((usds::DictionaryArray*)array_field->getElement())->getElement())->getDefaultEncode() != usds::USDS_UTF8
			|| array_field->isNullable() != true
			|| array_field->getElement()->isNullable() != false
			|| ((usds::DictionaryArray*)array_field->getElement())->getElement()->isNullable() != false
		)
			throw "Failed at the step 11\n";

		// step 12
		usds::DictionaryTagLink* tag_field = (usds::DictionaryTagLink*)struct_tag->getField(5);
		if (strcmp(tag_field->getName(), "bool2") != 0 || tag_field->getType() != usds::USDS_TAG || tag_field->isNullable() != true)
			throw "Failed at the step 12\n";

		{
			// step 13
			usds::DictionaryArray* internal_tag_link = (usds::DictionaryArray*)tag_field->getTag();
			if (strcmp(internal_tag_link->getName(), "bool") != 0 || internal_tag_link->getType() != usds::USDS_ARRAY || internal_tag_link->getElement()->getType() != usds::USDS_ARRAY
				|| ((usds::DictionaryArray*)internal_tag_link->getElement())->getElement()->getType() != usds::USDS_ARRAY
				|| ((usds::DictionaryArray*)((usds::DictionaryArray*)internal_tag_link->getElement())->getElement())->getElement()->getType() != usds::USDS_BOOLEAN
				|| internal_tag_link->isNullable() != false
				|| internal_tag_link->getElement()->isNullable() != false
				|| ((usds::DictionaryArray*)internal_tag_link->getElement())->getElement()->isNullable() != false
				|| ((usds::DictionaryArray*)((usds::DictionaryArray*)internal_tag_link->getElement())->getElement())->getElement()->isNullable() != false
				)
				throw "Failed at the step 13\n";
		}

		// step 14
		array_field = (usds::DictionaryArray*)struct_tag->getField(6);
		if (strcmp(array_field->getName(), "struct_field") != 0 || array_field->getType() != usds::USDS_ARRAY || array_field->getElement()->getType() != usds::USDS_TAG
			|| array_field->isNullable() != true
			|| array_field->getElement()->isNullable() != false
		)
			throw "Failed at the step 14\n";
		{
			// step 15
			usds::DictionaryArray* internal_array_struct = (usds::DictionaryArray*)((usds::DictionaryTagLink*)array_field->getElement())->getTag();
			if (strcmp(internal_array_struct->getName(), "struct2") != 0 || internal_array_struct->getType() != usds::USDS_ARRAY || internal_array_struct->getElement()->getType() != usds::USDS_ARRAY
				|| ((usds::DictionaryArray*)internal_array_struct->getElement())->getElement()->getType() != usds::USDS_STRUCT
				|| internal_array_struct->isNullable() != false
				|| internal_array_struct->getElement()->isNullable() != false
				|| ((usds::DictionaryArray*)internal_array_struct->getElement())->getElement()->isNullable() != false
			)
				throw "Failed at the step 15\n";

			{
				// step 16
				usds::DictionaryStruct* internal_struct_tag = (usds::DictionaryStruct*)((usds::DictionaryArray*)internal_array_struct->getElement())->getElement();
				if (internal_struct_tag->getType() != usds::USDS_STRUCT || internal_struct_tag->getFieldNumbers() != 2 || internal_struct_tag->isNullable() != false)
					throw "Failed at the step 16\n";

				// step 17
				usds::DictionaryBoolean* internal_boolean_filed = (usds::DictionaryBoolean*)internal_struct_tag->getField(1);
				if (strcmp(internal_boolean_filed->getName(), "bool") != 0 || internal_boolean_filed->getType() != usds::USDS_BOOLEAN || internal_boolean_filed->isNullable() != true)
					throw "Failed at the step 17\n";

				// step 18
				usds::DictionaryByte* internal_byte_filed = (usds::DictionaryByte*)internal_struct_tag->getField(2);
				if (strcmp(internal_byte_filed->getName(), "byte") != 0 || internal_byte_filed->getType() != usds::USDS_BYTE || internal_byte_filed->hasDefaultValue() != true || internal_byte_filed->getDefaultValue() != 110)
					throw "Failed at the step 18\n";
			}
		}
	}

	// step 19
	tag = (usds::DictionaryArray*)dict.getTag(2);
	if (strcmp(tag->getName(), "bool") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_ARRAY
		|| ((usds::DictionaryArray*)tag->getElement())->getElement()->getType() != usds::USDS_ARRAY
		|| ((usds::DictionaryArray*)((usds::DictionaryArray*)tag->getElement())->getElement())->getElement()->getType() != usds::USDS_BOOLEAN
		|| tag->isNullable() != false
		|| tag->getElement()->isNullable() != false
		|| ((usds::DictionaryArray*)tag->getElement())->getElement()->isNullable() != false
		|| ((usds::DictionaryArray*)((usds::DictionaryArray*)tag->getElement())->getElement())->getElement()->isNullable() != false
		)
		throw "Failed at the step 19\n";

	// step 20
	tag = (usds::DictionaryArray*)dict.getTag(3);
	if (strcmp(tag->getName(), "struct2") != 0 || tag->getType() != usds::USDS_ARRAY || tag->getElement()->getType() != usds::USDS_ARRAY
		|| ((usds::DictionaryArray*)tag->getElement())->getElement()->getType() != usds::USDS_STRUCT
		|| tag->isNullable() != false
		|| tag->getElement()->isNullable() != false
		|| ((usds::DictionaryArray*)tag->getElement())->getElement()->isNullable() != false
	)
		throw "Failed at the step 20\n";

	{
		// step 21
		usds::DictionaryStruct* internal_struct_tag = (usds::DictionaryStruct*)((usds::DictionaryArray*)tag->getElement())->getElement();
		if (internal_struct_tag->getType() != usds::USDS_STRUCT || internal_struct_tag->getFieldNumbers() != 2 || internal_struct_tag->isNullable() != false)
			throw "Failed at the step 21\n";

		// step 22
		usds::DictionaryBoolean* internal_boolean_filed = (usds::DictionaryBoolean*)internal_struct_tag->getField(1);
		if (strcmp(internal_boolean_filed->getName(), "bool") != 0 || internal_boolean_filed->getType() != usds::USDS_BOOLEAN || internal_boolean_filed->isNullable() != true)
			throw "Failed at the step 22\n";

		// step 23
		usds::DictionaryByte* internal_byte_filed = (usds::DictionaryByte*)internal_struct_tag->getField(2);
		if (strcmp(internal_byte_filed->getName(), "byte") != 0 || internal_byte_filed->getType() != usds::USDS_BYTE || internal_byte_filed->hasDefaultValue() != true || internal_byte_filed->getDefaultValue() != 110)
			throw "Failed at the step 23\n";
	}
}

void DictionaryTextParserTestAutoId::test_14()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS 1:MyLittleAPI 1.1 {\
			struct_recursion\
			{\
				BOOLEAN bool;\
				BYTE byte;\
				struct_recursion recursion;\
			};\
		}";
	try
	{
		parser->parse(text_dict, usds::USDS_UTF8, &dict);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRUCT__RECURSION_ERROR)
		{
			throw "Failed at the step 1\n";
		}
	}

}

void DictionaryTextParserTestAutoId::test_15()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS 1:MyLittleAPI 1.1 {\
			struct_recursion\
			{\
				BOOLEAN bool;\
				BYTE byte;\
				struct_recursion recursion = NULL;\
			};\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 1 || dict.getDictionaryID() != 1 || dict.getMajorVersion() != 1 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (strcmp(tag->getName(), "struct_recursion") != 0 || tag->getType() != usds::USDS_STRUCT || tag->getFieldNumbers() != 3)
		throw "Failed at the step 2\n";

	// step 3
	usds::DictionaryTagLink* field = (usds::DictionaryTagLink*)tag->getField(3);
	if (field->getTag() != tag)
		throw "Failed at the step 3\n";


}

void DictionaryTextParserTestAutoId::test_16()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"\xEF\xBB\xBFUSDS MyLittleAPI {\
			struct\
			{\
				BOOLEAN bool;\
				internal_struct\
				{\
					BOOLEAN bool;\
					BYTE byte;\
				};\
				BYTE byte;\
				internal_struct2\
				{\
					BYTE byte;\
					internal_internal_struct\
					{\
						BYTE byte;\
						BOOLEAN bool;\
					};\
					BOOLEAN bool;\
				};\
			};\
			BYTE byte;\
			struct2\
			{\
				BOOLEAN bool;\
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
	if (struct_tag->getFieldNumbers() != 4)
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
	if (((usds::DictionaryStruct*)field)->getFieldNumbers() != 2)
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
	if (((usds::DictionaryStruct*)field)->getFieldNumbers() != 3)
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
	if (((usds::DictionaryStruct*)field_int)->getFieldNumbers() != 2)
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



