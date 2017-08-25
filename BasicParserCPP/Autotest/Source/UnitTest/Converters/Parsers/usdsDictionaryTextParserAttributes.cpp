#include "usdsAutotest.h"

#include "converters/usdsDictionaryTextParser.h"
#include "dictionary/usdsDictionary.h"
#include "dictionary/dataTypes/dictionaryString.h"
#include "dictionary/dataTypes/dictionaryEnum.h"

void DictionaryTextParserTestAttributes::test_1()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		ENCODE:UTF-8\n\
		ENUMERATOR : UBYTE\n\
		{\n\
			1: STRING str1;\n\
			2: STRING<UTF-8> str2;\n\
			3: ENUM enum1 { v1, v2 };\n\
			4: ENUM<SHORT> enum2 { v1, v2 };\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 4 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	const char* name = dict.getTag(1)->getName();
	if (strcmp(name, "str1") != 0)
		throw "Failed at the step 2\n";
	if (dict.getTag(1)->getType() != usds::USDS_STRING)
		throw "Failed at the step 2\n";
	if (((usds::DictionaryString*)dict.getTag(1))->getDefaultEncode() != usds::USDS_UTF8)
		throw "Failed at the step 2\n";

	// step 3
	name = dict.getTag(2)->getName();
	if (strcmp(name, "str2") != 0)
		throw "Failed at the step 3\n";
	if (dict.getTag(2)->getType() != usds::USDS_STRING)
		throw "Failed at the step 3\n";
	if (((usds::DictionaryString*)dict.getTag(2))->getDefaultEncode() != usds::USDS_UTF8)
		throw "Failed at the step 3\n";

	// step 4
	name = dict.getTag(3)->getName();
	if (strcmp(name, "enum1") != 0)
		throw "Failed at the step 4\n";
	if (dict.getTag(3)->getType() != usds::USDS_ENUM)
		throw "Failed at the step 4\n";
	if (((usds::DictionaryEnum*)dict.getTag(3))->getSubtype() != usds::USDS_UBYTE)
		throw "Failed at the step 4\n";

	// step 5
	name = dict.getTag(4)->getName();
	if (strcmp(name, "enum2") != 0)
		throw "Failed at the step 5\n";
	if (dict.getTag(4)->getType() != usds::USDS_ENUM)
		throw "Failed at the step 5\n";
	if (((usds::DictionaryEnum*)dict.getTag(4))->getSubtype() != usds::USDS_SHORT)
		throw "Failed at the step 5\n";

}