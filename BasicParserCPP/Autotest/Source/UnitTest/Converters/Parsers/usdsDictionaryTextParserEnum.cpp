#include "usdsAutotest.h"

#include "converters/usdsDictionaryTextParser.h"
#include "dictionary/usdsDictionary.h"
#include "dictionary/dataTypes/dictionaryEnum.h"
#include "dictionary/dataTypes/dictionaryArray.h"

void DictionaryTextParserEnumTest::test_1()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryEnum* enum_tag = 0;
	
	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			1: ENUM enum1 { v1, v2 };\n\
			2: ENUM<SHORT> enum2 { v1, v2 };\n\
			3: ENUM enum3 { v1=1, v2 = 2 };\n\
			4: ENUM enum4 { v1, v2 = 2, v10 = 10, v11, vm5 = -5, vm4, vm3, v5 = 5, v6 , vm100 = -100, vm99 };\n\
			5: ENUM<BYTE> enum5 { v1, v2 = 2, v10 = 10, v11, vm5 = -5, vm4, vm3, v5 = 5, v6 , vm100 = -100, vm99 };\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	enum_tag = (usds::DictionaryEnum*)dict.getTag(1);
	if (strcmp(enum_tag->getName(), "enum1")!=0 || enum_tag->getType() != usds::USDS_ENUM || 
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0
	)
		throw "Failed at the step 2\n";

	// step 3
	enum_tag = (usds::DictionaryEnum*)dict.getTag(2);
	if (strcmp(enum_tag->getName(), "enum2") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 3\n";

	// step 4
	enum_tag = (usds::DictionaryEnum*)dict.getTag(3);
	if (strcmp(enum_tag->getName(), "enum3") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 4\n";

	// step 5
	enum_tag = (usds::DictionaryEnum*)dict.getTag(4);
	if (strcmp(enum_tag->getName(), "enum4") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(-100), "vm100") != 0 ||
		strcmp(enum_tag->getEnumerator(-99), "vm99") != 0 ||
		strcmp(enum_tag->getEnumerator(-5), "vm5") != 0 ||
		strcmp(enum_tag->getEnumerator(-4), "vm4") != 0 ||
		strcmp(enum_tag->getEnumerator(-3), "vm3") != 0 ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0 ||
		strcmp(enum_tag->getEnumerator(5), "v5") != 0 ||
		strcmp(enum_tag->getEnumerator(6), "v6") != 0 ||
		strcmp(enum_tag->getEnumerator(10), "v10") != 0 ||
		strcmp(enum_tag->getEnumerator(11), "v11") != 0
		)
		throw "Failed at the step 5\n";

	// step 6
	enum_tag = (usds::DictionaryEnum*)dict.getTag(5);
	if (strcmp(enum_tag->getName(), "enum5") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(-100), "vm100") != 0 ||
		strcmp(enum_tag->getEnumerator(-99), "vm99") != 0 ||
		strcmp(enum_tag->getEnumerator(-5), "vm5") != 0 ||
		strcmp(enum_tag->getEnumerator(-4), "vm4") != 0 ||
		strcmp(enum_tag->getEnumerator(-3), "vm3") != 0 ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0 ||
		strcmp(enum_tag->getEnumerator(5), "v5") != 0 ||
		strcmp(enum_tag->getEnumerator(6), "v6") != 0 ||
		strcmp(enum_tag->getEnumerator(10), "v10") != 0 ||
		strcmp(enum_tag->getEnumerator(11), "v11") != 0
		)
		throw "Failed at the step 6\n";

}

void DictionaryTextParserEnumTest::test_2()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryEnum* enum_tag = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			ENUM enum1 { v1, v2 };\n\
			ENUM<SHORT> enum2 { v1, v2 };\n\
			ENUM enum3 { v1=1, v2 = 2 };\n\
			ENUM enum4 { v1, v2 = 2, v10 = 10, v11, vm5 = -5, vm4, vm3, v5 = 5, v6 , vm100 = -100, vm99 };\n\
			ENUM<BYTE> enum5 { v1, v2 = 2, v10 = 10, v11, vm5 = -5, vm4, vm3, v5 = 5, v6 , vm100 = -100, vm99 };\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	enum_tag = (usds::DictionaryEnum*)dict.getTag(1);
	if (strcmp(enum_tag->getName(), "enum1") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 2\n";

	// step 3
	enum_tag = (usds::DictionaryEnum*)dict.getTag(2);
	if (strcmp(enum_tag->getName(), "enum2") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 3\n";

	// step 4
	enum_tag = (usds::DictionaryEnum*)dict.getTag(3);
	if (strcmp(enum_tag->getName(), "enum3") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 4\n";

	// step 5
	enum_tag = (usds::DictionaryEnum*)dict.getTag(4);
	if (strcmp(enum_tag->getName(), "enum4") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(-100), "vm100") != 0 ||
		strcmp(enum_tag->getEnumerator(-99), "vm99") != 0 ||
		strcmp(enum_tag->getEnumerator(-5), "vm5") != 0 ||
		strcmp(enum_tag->getEnumerator(-4), "vm4") != 0 ||
		strcmp(enum_tag->getEnumerator(-3), "vm3") != 0 ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0 ||
		strcmp(enum_tag->getEnumerator(5), "v5") != 0 ||
		strcmp(enum_tag->getEnumerator(6), "v6") != 0 ||
		strcmp(enum_tag->getEnumerator(10), "v10") != 0 ||
		strcmp(enum_tag->getEnumerator(11), "v11") != 0
		)
		throw "Failed at the step 5\n";

	// step 6
	enum_tag = (usds::DictionaryEnum*)dict.getTag(5);
	if (strcmp(enum_tag->getName(), "enum5") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(-100), "vm100") != 0 ||
		strcmp(enum_tag->getEnumerator(-99), "vm99") != 0 ||
		strcmp(enum_tag->getEnumerator(-5), "vm5") != 0 ||
		strcmp(enum_tag->getEnumerator(-4), "vm4") != 0 ||
		strcmp(enum_tag->getEnumerator(-3), "vm3") != 0 ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0 ||
		strcmp(enum_tag->getEnumerator(5), "v5") != 0 ||
		strcmp(enum_tag->getEnumerator(6), "v6") != 0 ||
		strcmp(enum_tag->getEnumerator(10), "v10") != 0 ||
		strcmp(enum_tag->getEnumerator(11), "v11") != 0
		)
		throw "Failed at the step 6\n";

}


void DictionaryTextParserEnumTest::test_3()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryArray* array_tag = 0;
	usds::DictionaryEnum* enum_element = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			1: ENUM[] enum1 { v1, v2 };\n\
			2: ENUM<SHORT>[] enum2 { v1, v2 };\n\
			3: ENUM[] enum3 { v1=1, v2 = 2 };\n\
			4: ENUM[] enum4 { v1, v2 = 2, v10 = 10, v11, vm5 = -5, vm4, vm3, v5 = 5, v6 , vm100 = -100, vm99 };\n\
			5: ENUM<BYTE>[] enum5 { v1, v2 = 2, v10 = 10, v11, vm5 = -5, vm4, vm3, v5 = 5, v6 , vm100 = -100, vm99 };\n\
			6: ENUM[][][] enum6 { v1, v2 };\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 6 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	array_tag = (usds::DictionaryArray*)dict.getTag(1);
	if (strcmp(array_tag->getName(), "enum1") != 0 || array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ENUM)
		throw "Failed at the step 2\n";
	enum_element = (usds::DictionaryEnum*)array_tag->getElement();
	if (enum_element->getType() != usds::USDS_ENUM ||
		strcmp(enum_element->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_element->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 2\n";

	// step 3
	array_tag = (usds::DictionaryArray*)dict.getTag(2);
	if (strcmp(array_tag->getName(), "enum2") != 0 || array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ENUM)
		throw "Failed at the step 3\n";
	enum_element = (usds::DictionaryEnum*)array_tag->getElement();
	if (enum_element->getType() != usds::USDS_ENUM ||
		strcmp(enum_element->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_element->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 3\n";

	// step 4
	array_tag = (usds::DictionaryArray*)dict.getTag(3);
	if (strcmp(array_tag->getName(), "enum3") != 0 || array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ENUM)
		throw "Failed at the step 4\n";
	enum_element = (usds::DictionaryEnum*)array_tag->getElement();
	if (enum_element->getType() != usds::USDS_ENUM ||
		strcmp(enum_element->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_element->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 4\n";

	// step 5
	array_tag = (usds::DictionaryArray*)dict.getTag(4);
	if (strcmp(array_tag->getName(), "enum4") != 0 || array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ENUM)
		throw "Failed at the step 5\n";
	enum_element = (usds::DictionaryEnum*)array_tag->getElement();
	if (enum_element->getType() != usds::USDS_ENUM ||
		strcmp(enum_element->getEnumerator(-100), "vm100") != 0 ||
		strcmp(enum_element->getEnumerator(-99), "vm99") != 0 ||
		strcmp(enum_element->getEnumerator(-5), "vm5") != 0 ||
		strcmp(enum_element->getEnumerator(-4), "vm4") != 0 ||
		strcmp(enum_element->getEnumerator(-3), "vm3") != 0 ||
		strcmp(enum_element->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_element->getEnumerator(2), "v2") != 0 ||
		strcmp(enum_element->getEnumerator(5), "v5") != 0 ||
		strcmp(enum_element->getEnumerator(6), "v6") != 0 ||
		strcmp(enum_element->getEnumerator(10), "v10") != 0 ||
		strcmp(enum_element->getEnumerator(11), "v11") != 0
		)
		throw "Failed at the step 5\n";

	// step 6
	array_tag = (usds::DictionaryArray*)dict.getTag(5);
	if (strcmp(array_tag->getName(), "enum5") != 0 || array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ENUM)
		throw "Failed at the step 6\n";
	enum_element = (usds::DictionaryEnum*)array_tag->getElement();
	if (enum_element->getType() != usds::USDS_ENUM ||
		strcmp(enum_element->getEnumerator(-100), "vm100") != 0 ||
		strcmp(enum_element->getEnumerator(-99), "vm99") != 0 ||
		strcmp(enum_element->getEnumerator(-5), "vm5") != 0 ||
		strcmp(enum_element->getEnumerator(-4), "vm4") != 0 ||
		strcmp(enum_element->getEnumerator(-3), "vm3") != 0 ||
		strcmp(enum_element->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_element->getEnumerator(2), "v2") != 0 ||
		strcmp(enum_element->getEnumerator(5), "v5") != 0 ||
		strcmp(enum_element->getEnumerator(6), "v6") != 0 ||
		strcmp(enum_element->getEnumerator(10), "v10") != 0 ||
		strcmp(enum_element->getEnumerator(11), "v11") != 0
		)
		throw "Failed at the step 6\n";

	// step 7
	array_tag = (usds::DictionaryArray*)dict.getTag(6);
	if (strcmp(array_tag->getName(), "enum6") != 0 || array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ARRAY)
		throw "Failed at the step 7\n";
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ARRAY)
		throw "Failed at the step 7\n";
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ENUM)
		throw "Failed at the step 7\n";
	enum_element = (usds::DictionaryEnum*)array_tag->getElement();
	if (enum_element->getType() != usds::USDS_ENUM ||
		strcmp(enum_element->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_element->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 7\n";

}

void DictionaryTextParserEnumTest::test_4()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryArray* array_tag = 0;
	usds::DictionaryEnum* enum_element = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			ENUM[] enum1 { v1, v2 };\n\
			ENUM<SHORT>[] enum2 { v1, v2 };\n\
			ENUM[] enum3 { v1=1, v2 = 2 };\n\
			ENUM[] enum4 { v1, v2 = 2, v10 = 10, v11, vm5 = -5, vm4, vm3, v5 = 5, v6 , vm100 = -100, vm99 };\n\
			ENUM<BYTE>[] enum5 { v1, v2 = 2, v10 = 10, v11, vm5 = -5, vm4, vm3, v5 = 5, v6 , vm100 = -100, vm99 };\n\
			ENUM[][][] enum6 { v1, v2 };\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 6 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	array_tag = (usds::DictionaryArray*)dict.getTag(1);
	if (strcmp(array_tag->getName(), "enum1") != 0 || array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ENUM)
		throw "Failed at the step 2\n";
	enum_element = (usds::DictionaryEnum*)array_tag->getElement();
	if (enum_element->getType() != usds::USDS_ENUM ||
		strcmp(enum_element->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_element->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 2\n";

	// step 3
	array_tag = (usds::DictionaryArray*)dict.getTag(2);
	if (strcmp(array_tag->getName(), "enum2") != 0 || array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ENUM)
		throw "Failed at the step 3\n";
	enum_element = (usds::DictionaryEnum*)array_tag->getElement();
	if (enum_element->getType() != usds::USDS_ENUM ||
		strcmp(enum_element->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_element->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 3\n";

	// step 4
	array_tag = (usds::DictionaryArray*)dict.getTag(3);
	if (strcmp(array_tag->getName(), "enum3") != 0 || array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ENUM)
		throw "Failed at the step 4\n";
	enum_element = (usds::DictionaryEnum*)array_tag->getElement();
	if (enum_element->getType() != usds::USDS_ENUM ||
		strcmp(enum_element->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_element->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 4\n";

	// step 5
	array_tag = (usds::DictionaryArray*)dict.getTag(4);
	if (strcmp(array_tag->getName(), "enum4") != 0 || array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ENUM)
		throw "Failed at the step 5\n";
	enum_element = (usds::DictionaryEnum*)array_tag->getElement();
	if (enum_element->getType() != usds::USDS_ENUM ||
		strcmp(enum_element->getEnumerator(-100), "vm100") != 0 ||
		strcmp(enum_element->getEnumerator(-99), "vm99") != 0 ||
		strcmp(enum_element->getEnumerator(-5), "vm5") != 0 ||
		strcmp(enum_element->getEnumerator(-4), "vm4") != 0 ||
		strcmp(enum_element->getEnumerator(-3), "vm3") != 0 ||
		strcmp(enum_element->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_element->getEnumerator(2), "v2") != 0 ||
		strcmp(enum_element->getEnumerator(5), "v5") != 0 ||
		strcmp(enum_element->getEnumerator(6), "v6") != 0 ||
		strcmp(enum_element->getEnumerator(10), "v10") != 0 ||
		strcmp(enum_element->getEnumerator(11), "v11") != 0
		)
		throw "Failed at the step 5\n";

	// step 6
	array_tag = (usds::DictionaryArray*)dict.getTag(5);
	if (strcmp(array_tag->getName(), "enum5") != 0 || array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ENUM)
		throw "Failed at the step 6\n";
	enum_element = (usds::DictionaryEnum*)array_tag->getElement();
	if (enum_element->getType() != usds::USDS_ENUM ||
		strcmp(enum_element->getEnumerator(-100), "vm100") != 0 ||
		strcmp(enum_element->getEnumerator(-99), "vm99") != 0 ||
		strcmp(enum_element->getEnumerator(-5), "vm5") != 0 ||
		strcmp(enum_element->getEnumerator(-4), "vm4") != 0 ||
		strcmp(enum_element->getEnumerator(-3), "vm3") != 0 ||
		strcmp(enum_element->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_element->getEnumerator(2), "v2") != 0 ||
		strcmp(enum_element->getEnumerator(5), "v5") != 0 ||
		strcmp(enum_element->getEnumerator(6), "v6") != 0 ||
		strcmp(enum_element->getEnumerator(10), "v10") != 0 ||
		strcmp(enum_element->getEnumerator(11), "v11") != 0
		)
		throw "Failed at the step 6\n";

	// step 7
	array_tag = (usds::DictionaryArray*)dict.getTag(6);
	if (strcmp(array_tag->getName(), "enum6") != 0 || array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ARRAY)
		throw "Failed at the step 7\n";
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ARRAY)
		throw "Failed at the step 7\n";
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ENUM)
		throw "Failed at the step 7\n";
	enum_element = (usds::DictionaryEnum*)array_tag->getElement();
	if (enum_element->getType() != usds::USDS_ENUM ||
		strcmp(enum_element->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_element->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 7\n";

}

void DictionaryTextParserEnumTest::test_5()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryEnum* enum_tag = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			1: struct\n\
			{\n\
				1: ENUM enum1 { v1, v2 };\n\
				2: ENUM<SHORT> enum2 { v1, v2 };\n\
				3: ENUM enum3 { v1=1, v2 = 2 };\n\
				4: ENUM enum4 { v1, v2 = 2, v10 = 10, v11, vm5 = -5, vm4, vm3, v5 = 5, v6 , vm100 = -100, vm99 };\n\
				5: ENUM<BYTE> enum5 { v1, v2 = 2, v10 = 10, v11, vm5 = -5, vm4, vm3, v5 = 5, v6 , vm100 = -100, vm99 };\n\
				6: enum_global enum 6;\n\
			};\n\
			2: ENUM enum_global { v1, v2 };\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	enum_tag = (usds::DictionaryEnum*)dict.getTag(1);
	if (strcmp(enum_tag->getName(), "enum1") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 2\n";

	// step 3
	enum_tag = (usds::DictionaryEnum*)dict.getTag(2);
	if (strcmp(enum_tag->getName(), "enum2") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 3\n";

	// step 4
	enum_tag = (usds::DictionaryEnum*)dict.getTag(3);
	if (strcmp(enum_tag->getName(), "enum3") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0
		)
		throw "Failed at the step 4\n";

	// step 5
	enum_tag = (usds::DictionaryEnum*)dict.getTag(4);
	if (strcmp(enum_tag->getName(), "enum4") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(-100), "vm100") != 0 ||
		strcmp(enum_tag->getEnumerator(-99), "vm99") != 0 ||
		strcmp(enum_tag->getEnumerator(-5), "vm5") != 0 ||
		strcmp(enum_tag->getEnumerator(-4), "vm4") != 0 ||
		strcmp(enum_tag->getEnumerator(-3), "vm3") != 0 ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0 ||
		strcmp(enum_tag->getEnumerator(5), "v5") != 0 ||
		strcmp(enum_tag->getEnumerator(6), "v6") != 0 ||
		strcmp(enum_tag->getEnumerator(10), "v10") != 0 ||
		strcmp(enum_tag->getEnumerator(11), "v11") != 0
		)
		throw "Failed at the step 5\n";

	// step 6
	enum_tag = (usds::DictionaryEnum*)dict.getTag(5);
	if (strcmp(enum_tag->getName(), "enum5") != 0 || enum_tag->getType() != usds::USDS_ENUM ||
		strcmp(enum_tag->getEnumerator(-100), "vm100") != 0 ||
		strcmp(enum_tag->getEnumerator(-99), "vm99") != 0 ||
		strcmp(enum_tag->getEnumerator(-5), "vm5") != 0 ||
		strcmp(enum_tag->getEnumerator(-4), "vm4") != 0 ||
		strcmp(enum_tag->getEnumerator(-3), "vm3") != 0 ||
		strcmp(enum_tag->getEnumerator(1), "v1") != 0 ||
		strcmp(enum_tag->getEnumerator(2), "v2") != 0 ||
		strcmp(enum_tag->getEnumerator(5), "v5") != 0 ||
		strcmp(enum_tag->getEnumerator(6), "v6") != 0 ||
		strcmp(enum_tag->getEnumerator(10), "v10") != 0 ||
		strcmp(enum_tag->getEnumerator(11), "v11") != 0
		)
		throw "Failed at the step 6\n";

}





