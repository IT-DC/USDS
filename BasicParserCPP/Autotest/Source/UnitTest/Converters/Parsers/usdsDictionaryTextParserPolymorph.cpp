#include "usdsAutotest.h"

#include "converters/usdsDictionaryTextParser.h"
#include "dictionary/usdsDictionary.h"
#include "dictionary/dataTypes/dictionaryPolymorph.h"
#include "dictionary/dataTypes/dictionaryArray.h"
#include "dictionary/dataTypes/dictionaryStruct.h"
#include "dictionary/dataTypes/dictionaryTagLink.h"

// Simpl polymorph - positive test
void DictionaryTextParserPolymorphTest::test_1()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_tag = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			1: <struct_1||struct_3||struct_4> poly_tag;\n\
			2: struct_1 { 1: INT int; } ;\n\
			3: struct_2 { 1: INT int; } ;\n\
			4: struct_3 { 1: INT int; } ;\n\
			5: struct_4 { 1: INT int; } ;\n\
			6: struct_5 { 1: INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 6 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	poly_tag = (usds::DictionaryPolymorph*)dict.getTag(1);
	if (poly_tag->getType() != usds::USDS_POLYMORPH || poly_tag->getID() != 1 || strcmp(poly_tag->getName(), "poly_tag") != 0)
		throw "Failed at the step 2\n";

	// step 3
	usds::DictionaryStruct* struct_tag = poly_tag->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_tag->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_3") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_tag->getSubStruct(5);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 5 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 5\n";

	// step 6
	try
	{
		struct_tag = poly_tag->getSubStruct(1);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 6\n";
	}

	// step 7
	try
	{
		struct_tag = poly_tag->getSubStruct(3);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_tag->getSubStruct(6);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	if (
		poly_tag->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_tag->getFirstTag()->getNext())->getTag() != dict.getTag(4) ||
		((usds::DictionaryTagLink*)poly_tag->getFirstTag()->getNext()->getNext())->getTag() != dict.getTag(5)
		)
		throw "Failed at the step 9\n";

}

// Simpl polymorph - positive test
void DictionaryTextParserPolymorphTest::test_2()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_tag = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			<struct_1||struct_3||struct_4> poly_tag;\n\
			struct_1 { INT int; } ;\n\
			struct_2 { INT int; } ;\n\
			struct_3 { INT int; } ;\n\
			struct_4 { INT int; } ;\n\
			struct_5 { INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 6 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	poly_tag = (usds::DictionaryPolymorph*)dict.getTag(1);
	if (poly_tag->getType() != usds::USDS_POLYMORPH || poly_tag->getID() != 1 || strcmp(poly_tag->getName(), "poly_tag") != 0)
		throw "Failed at the step 2\n";

	// step 3
	usds::DictionaryStruct* struct_tag = poly_tag->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_tag->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_3") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_tag->getSubStruct(5);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 5 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 5\n";

	// step 6
	try
	{
		struct_tag = poly_tag->getSubStruct(1);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 6\n";
	}

	// step 7
	try
	{
		struct_tag = poly_tag->getSubStruct(3);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_tag->getSubStruct(6);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	if (
		poly_tag->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_tag->getFirstTag()->getNext())->getTag() != dict.getTag(4) ||
		((usds::DictionaryTagLink*)poly_tag->getFirstTag()->getNext()->getNext())->getTag() != dict.getTag(5)
		)
		throw "Failed at the step 9\n";

}

// Nested polymorph - positive test
void DictionaryTextParserPolymorphTest::test_3()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_tag = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			1: <struct_1||struct_4||poly_tag_2> poly_tag;\n\
			2: struct_1 { 1: INT int; } ;\n\
			3: struct_2 { 1: INT int; } ;\n\
			4: <struct_1||struct_5> poly_tag_2;\n\
			5: struct_4 { 1: INT int; } ;\n\
			6: struct_5 { 1: INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 6 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	poly_tag = (usds::DictionaryPolymorph*)dict.getTag(1);
	if (poly_tag->getType() != usds::USDS_POLYMORPH || poly_tag->getID() != 1 || strcmp(poly_tag->getName(), "poly_tag") != 0)
		throw "Failed at the step 2\n";

	// step 3
	usds::DictionaryStruct* struct_tag = poly_tag->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_tag->getSubStruct(5);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 5 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_tag->getSubStruct(6);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 6 || strcmp(struct_tag->getName(), "struct_5") != 0)
		throw "Failed at the step 5\n";

	// step 6
	try
	{
		struct_tag = poly_tag->getSubStruct(1);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 6\n";
	}

	// step 7
	try
	{
		struct_tag = poly_tag->getSubStruct(3);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_tag->getSubStruct(4);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 8.1
	if (
		poly_tag->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_tag->getFirstTag()->getNext())->getTag() != dict.getTag(5) ||
		((usds::DictionaryTagLink*)poly_tag->getFirstTag()->getNext()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 8.1\n";

	// step 9
	poly_tag = (usds::DictionaryPolymorph*)dict.getTag(4);
	if (poly_tag->getType() != usds::USDS_POLYMORPH || poly_tag->getID() != 4 || strcmp(poly_tag->getName(), "poly_tag_2") != 0)
		throw "Failed at the step 9\n";

	// step 10
	struct_tag = poly_tag->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 10\n";

	// step 11
	struct_tag = poly_tag->getSubStruct(6);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 6 || strcmp(struct_tag->getName(), "struct_5") != 0)
		throw "Failed at the step 11\n";

	// step 12
	try
	{
		struct_tag = poly_tag->getSubStruct(1);
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 12\n";
	}

	// step 13
	try
	{
		struct_tag = poly_tag->getSubStruct(3);
		throw "Failed at the step 13\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 13\n";
	}

	// step 14
	try
	{
		struct_tag = poly_tag->getSubStruct(4);
		throw "Failed at the step 14\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 14\n";
	}

	// step 15
	try
	{
		struct_tag = poly_tag->getSubStruct(5);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 15\n";
	}

	// step 16
	if (
		poly_tag->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_tag->getFirstTag()->getNext())->getTag() != dict.getTag(6)
		)
		throw "Failed at the step 16\n";

}

// Nested polymorph - positive test
void DictionaryTextParserPolymorphTest::test_4()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_tag = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			<struct_1||struct_4||poly_tag_2> poly_tag;\n\
			struct_1 { INT int; } ;\n\
			struct_2 { INT int; } ;\n\
			<struct_1||struct_5> poly_tag_2;\n\
			struct_4 { INT int; } ;\n\
			struct_5 { INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 6 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	poly_tag = (usds::DictionaryPolymorph*)dict.getTag(1);
	if (poly_tag->getType() != usds::USDS_POLYMORPH || poly_tag->getID() != 1 || strcmp(poly_tag->getName(), "poly_tag") != 0)
		throw "Failed at the step 2\n";

	// step 3
	usds::DictionaryStruct* struct_tag = poly_tag->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_tag->getSubStruct(5);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 5 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_tag->getSubStruct(6);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 6 || strcmp(struct_tag->getName(), "struct_5") != 0)
		throw "Failed at the step 5\n";

	// step 6
	try
	{
		struct_tag = poly_tag->getSubStruct(1);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 6\n";
	}

	// step 7
	try
	{
		struct_tag = poly_tag->getSubStruct(3);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_tag->getSubStruct(4);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 8.1
	if (
		poly_tag->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_tag->getFirstTag()->getNext())->getTag() != dict.getTag(5) ||
		((usds::DictionaryTagLink*)poly_tag->getFirstTag()->getNext()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 8.1\n";

	// step 9
	poly_tag = (usds::DictionaryPolymorph*)dict.getTag(4);
	if (poly_tag->getType() != usds::USDS_POLYMORPH || poly_tag->getID() != 4 || strcmp(poly_tag->getName(), "poly_tag_2") != 0)
		throw "Failed at the step 9\n";

	// step 10
	struct_tag = poly_tag->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 10\n";

	// step 11
	struct_tag = poly_tag->getSubStruct(6);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 6 || strcmp(struct_tag->getName(), "struct_5") != 0)
		throw "Failed at the step 11\n";

	// step 12
	try
	{
		struct_tag = poly_tag->getSubStruct(1);
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 12\n";
	}

	// step 13
	try
	{
		struct_tag = poly_tag->getSubStruct(3);
		throw "Failed at the step 13\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 13\n";
	}

	// step 14
	try
	{
		struct_tag = poly_tag->getSubStruct(4);
		throw "Failed at the step 14\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 14\n";
	}

	// step 15
	try
	{
		struct_tag = poly_tag->getSubStruct(5);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 15\n";
	}

	// step 16
	if (
		poly_tag->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_tag->getFirstTag()->getNext())->getTag() != dict.getTag(6)
		)
		throw "Failed at the step 16\n";

}

// Polymorph in struct - positive test
void DictionaryTextParserPolymorphTest::test_5()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			1: struct_1\n\
			{\n\
				1: <struct_2||struct_4> poly;\n\
			};\n\
			2: struct_2 { 1: INT int; } ;\n\
			3: struct_3 { 1: INT int; } ;\n\
			4: struct_4 { 1: INT int; } ;\n\
			5: struct_5 { 1: INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 1 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 2\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)struct_tag->getField(1);
	if (poly_field->getType() != usds::USDS_POLYMORPH || poly_field->getID() != 1 || strcmp(poly_field->getName(), "poly") != 0)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}

}

// Polymorph in struct - positive test
void DictionaryTextParserPolymorphTest::test_6()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			struct_1\n\
			{\n\
				<struct_2||struct_4> poly;\n\
			};\n\
			struct_2 { INT int; } ;\n\
			struct_3 { INT int; } ;\n\
			struct_4 { INT int; } ;\n\
			struct_5 { INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 1 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 2\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)struct_tag->getField(1);
	if (poly_field->getType() != usds::USDS_POLYMORPH || poly_field->getID() != 1 || strcmp(poly_field->getName(), "poly") != 0)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}

}

// Polymorph in array - positive test
void DictionaryTextParserPolymorphTest::test_7()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			1: <struct_2||struct_4>[] poly;\n\
			2: struct_2 { 1: INT int; } ;\n\
			3: struct_3 { 1: INT int; } ;\n\
			4: struct_4 { 1: INT int; } ;\n\
			5: struct_5 { 1: INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)dict.getTag(1);
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getID() != 1 || strcmp(array_tag->getName(), "poly") != 0 || array_tag->getElementType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 2\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)array_tag->getElement();
	if (poly_field->getType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 3\n";

	// step 4
	usds::DictionaryStruct* struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}
}


// Polymorph in array - positive test
void DictionaryTextParserPolymorphTest::test_8()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			<struct_2||struct_4>[] poly;\n\
			struct_2 { INT int; } ;\n\
			struct_3 { INT int; } ;\n\
			struct_4 { INT int; } ;\n\
			struct_5 { INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)dict.getTag(1);
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getID() != 1 || strcmp(array_tag->getName(), "poly") != 0 || array_tag->getElementType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 2\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)array_tag->getElement();
	if (poly_field->getType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 3\n";

	// step 4
	usds::DictionaryStruct* struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}
}

// Polymorph in multy array - positive test
void DictionaryTextParserPolymorphTest::test_9()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			1: <struct_2||struct_4>[][][] poly;\n\
			2: struct_2 { 1: INT int; } ;\n\
			3: struct_3 { 1: INT int; } ;\n\
			4: struct_4 { 1: INT int; } ;\n\
			5: struct_5 { 1: INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)dict.getTag(1);
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getID() != 1 || strcmp(array_tag->getName(), "poly") != 0 || array_tag->getElementType() != usds::USDS_ARRAY)
		throw "Failed at the step 2\n";

	// step 2.1
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ARRAY)
		throw "Failed at the step 2.1\n";
	
	// step 2.2
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 2.2\n";
	
	// step 3
	poly_field = (usds::DictionaryPolymorph*)array_tag->getElement();
	if (poly_field->getType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 3\n";

	// step 4
	usds::DictionaryStruct* struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}
}

// Polymorph in multy array - positive test
void DictionaryTextParserPolymorphTest::test_10()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			<struct_2||struct_4>[][][] poly;\n\
			struct_2 { INT int; } ;\n\
			struct_3 { INT int; } ;\n\
			struct_4 { INT int; } ;\n\
			struct_5 { INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)dict.getTag(1);
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getID() != 1 || strcmp(array_tag->getName(), "poly") != 0 || array_tag->getElementType() != usds::USDS_ARRAY)
		throw "Failed at the step 2\n";

	// step 2.1
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ARRAY)
		throw "Failed at the step 2.1\n";

	// step 2.2
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 2.2\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)array_tag->getElement();
	if (poly_field->getType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 3\n";

	// step 4
	usds::DictionaryStruct* struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}
}

// Array of Polymorph in Struct - positive test
void DictionaryTextParserPolymorphTest::test_11()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			1: struct_1\n\
			{\n\
				1: <struct_2||struct_4>[] poly;\n\
			};\n\
			2: struct_2 { 1: INT int; } ;\n\
			3: struct_3 { 1: INT int; } ;\n\
			4: struct_4 { 1: INT int; } ;\n\
			5: struct_5 { 1: INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 1 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 2\n";

	// step 2.1
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)struct_tag->getField(1);
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getID() != 1 || strcmp(array_tag->getName(), "poly") != 0 || array_tag->getElementType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 2.1\n";
	
	// step 3
	poly_field = (usds::DictionaryPolymorph*)array_tag->getElement();
	if (poly_field->getType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}
}

// Array of Polymorph in Struct - positive test
void DictionaryTextParserPolymorphTest::test_12()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			struct_1\n\
			{\n\
				<struct_2||struct_4>[] poly;\n\
			};\n\
			struct_2 { INT int; } ;\n\
			struct_3 { INT int; } ;\n\
			struct_4 { INT int; } ;\n\
			struct_5 { INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 1 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 2\n";

	// step 2.1
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)struct_tag->getField(1);
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getID() != 1 || strcmp(array_tag->getName(), "poly") != 0 || array_tag->getElementType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 2.1\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)array_tag->getElement();
	if (poly_field->getType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}
}

// Multi Array of Polymorph in Struct - positive test
void DictionaryTextParserPolymorphTest::test_13()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			1: struct_1\n\
			{\n\
				1: <struct_2||struct_4>[][][] poly;\n\
			};\n\
			2: struct_2 { 1: INT int; } ;\n\
			3: struct_3 { 1: INT int; } ;\n\
			4: struct_4 { 1: INT int; } ;\n\
			5: struct_5 { 1: INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 1 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 2\n";

	// step 2.1
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)struct_tag->getField(1);
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getID() != 1 || strcmp(array_tag->getName(), "poly") != 0 || array_tag->getElementType() != usds::USDS_ARRAY)
		throw "Failed at the step 2.1\n";

	// step 2.2
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ARRAY)
		throw "Failed at the step 2.2\n";

	// step 2.3
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 2.3\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)array_tag->getElement();
	if (poly_field->getType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}
}

// Multi Array of Polymorph in Struct - positive test
void DictionaryTextParserPolymorphTest::test_14()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			struct_1\n\
			{\n\
				<struct_2||struct_4>[][][] poly;\n\
			};\n\
			struct_2 { INT int; } ;\n\
			struct_3 { INT int; } ;\n\
			struct_4 { INT int; } ;\n\
			struct_5 { INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 1 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 2\n";

	// step 2.1
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)struct_tag->getField(1);
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getID() != 1 || strcmp(array_tag->getName(), "poly") != 0 || array_tag->getElementType() != usds::USDS_ARRAY)
		throw "Failed at the step 2.1\n";

	// step 2.2
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ARRAY)
		throw "Failed at the step 2.2\n";

	// step 2.3
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 2.3\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)array_tag->getElement();
	if (poly_field->getType() != usds::USDS_POLYMORPH)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}
}

// Nullable Polymorph in struct - positive test
void DictionaryTextParserPolymorphTest::test_15()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			1: struct_1\n\
			{\n\
				1: <struct_2||struct_4> poly = NULL;\n\
			};\n\
			2: struct_2 { 1: INT int; } ;\n\
			3: struct_3 { 1: INT int; } ;\n\
			4: struct_4 { 1: INT int; } ;\n\
			5: struct_5 { 1: INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 1 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 2\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)struct_tag->getField(1);
	if (poly_field->getType() != usds::USDS_POLYMORPH || poly_field->getID() != 1 || strcmp(poly_field->getName(), "poly") != 0 || poly_field->isNullable() != true)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0 || struct_tag->isNullable() != false)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0 || struct_tag->isNullable() != false)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}

}

// Nullable Polymorph in struct - positive test
void DictionaryTextParserPolymorphTest::test_16()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			struct_1\n\
			{\n\
				<struct_2||struct_4> poly = NULL;\n\
			};\n\
			struct_2 { INT int; } ;\n\
			struct_3 { INT int; } ;\n\
			struct_4 { INT int; } ;\n\
			struct_5 { INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 1 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 2\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)struct_tag->getField(1);
	if (poly_field->getType() != usds::USDS_POLYMORPH || poly_field->getID() != 1 || strcmp(poly_field->getName(), "poly") != 0 || poly_field->isNullable() != true)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0 || struct_tag->isNullable() != false)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0 || struct_tag->isNullable() != false)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}

}

// Nullable Array of Polymorph in Struct - positive test
void DictionaryTextParserPolymorphTest::test_17()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			1: struct_1\n\
			{\n\
				1: <struct_2||struct_4>[] poly = NULL;\n\
			};\n\
			2: struct_2 { 1: INT int; } ;\n\
			3: struct_3 { 1: INT int; } ;\n\
			4: struct_4 { 1: INT int; } ;\n\
			5: struct_5 { 1: INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 1 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 2\n";

	// step 2.1
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)struct_tag->getField(1);
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getID() != 1 || strcmp(array_tag->getName(), "poly") != 0 || array_tag->getElementType() != usds::USDS_POLYMORPH || array_tag->isNullable() != true)
		throw "Failed at the step 2.1\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)array_tag->getElement();
	if (poly_field->getType() != usds::USDS_POLYMORPH || poly_field->isNullable() != false)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0 || struct_tag->isNullable() != false)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0 || struct_tag->isNullable() != false)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}
}

// Nullable Array of Polymorph in Struct - positive test
void DictionaryTextParserPolymorphTest::test_18()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			struct_1\n\
			{\n\
				<struct_2||struct_4>[] poly = NULL;\n\
			};\n\
			struct_2 { INT int; } ;\n\
			struct_3 { INT int; } ;\n\
			struct_4 { INT int; } ;\n\
			struct_5 { INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 1 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 2\n";

	// step 2.1
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)struct_tag->getField(1);
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getID() != 1 || strcmp(array_tag->getName(), "poly") != 0 || array_tag->getElementType() != usds::USDS_POLYMORPH || array_tag->isNullable() != true)
		throw "Failed at the step 2.1\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)array_tag->getElement();
	if (poly_field->getType() != usds::USDS_POLYMORPH || poly_field->isNullable() != false)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0 || struct_tag->isNullable() != false)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0 || struct_tag->isNullable() != false)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}
}

// Nullable Multi Array of Polymorph in Struct - positive test
void DictionaryTextParserPolymorphTest::test_19()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			1: struct_1\n\
			{\n\
				1: <struct_2||struct_4>[][][] poly = NULL;\n\
			};\n\
			2: struct_2 { 1: INT int; } ;\n\
			3: struct_3 { 1: INT int; } ;\n\
			4: struct_4 { 1: INT int; } ;\n\
			5: struct_5 { 1: INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 1 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 2\n";

	// step 2.1
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)struct_tag->getField(1);
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getID() != 1 || strcmp(array_tag->getName(), "poly") != 0 || array_tag->getElementType() != usds::USDS_ARRAY || array_tag->isNullable() != true)
		throw "Failed at the step 2.1\n";

	// step 2.2
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ARRAY || array_tag->isNullable() != false)
		throw "Failed at the step 2.2\n";

	// step 2.3
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_POLYMORPH || array_tag->isNullable() != false)
		throw "Failed at the step 2.3\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)array_tag->getElement();
	if (poly_field->getType() != usds::USDS_POLYMORPH || poly_field->isNullable() != false)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0 || struct_tag->isNullable() != false)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0 || struct_tag->isNullable() != false)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}
}

// Nullable Multi Array of Polymorph in Struct - positive test
void DictionaryTextParserPolymorphTest::test_20()
{
	usds::DictionaryTextParser* parser = new usds::DictionaryTextParser();
	usds::Dictionary dict(0);
	usds::DictionaryPolymorph* poly_field = 0;

	// step 1
	const char* text_dict =
		"USDS MyLittleAPI 0.1\n\
		{\n\
			struct_1\n\
			{\n\
				<struct_2||struct_4>[][][] poly = NULL;\n\
			};\n\
			struct_2 { INT int; } ;\n\
			struct_3 { INT int; } ;\n\
			struct_4 { INT int; } ;\n\
			struct_5 { INT int; } ;\n\
		}";
	parser->parse(text_dict, usds::USDS_UTF8, &dict);
	if (dict.getTagNumber() != 5 || dict.getDictionaryID() != 0 || dict.getMajorVersion() != 0 || dict.getMinorVersion() != 1)
		throw "Failed at the step 1\n";

	// step 2
	usds::DictionaryStruct* struct_tag = (usds::DictionaryStruct*)dict.getTag(1);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 1 || strcmp(struct_tag->getName(), "struct_1") != 0)
		throw "Failed at the step 2\n";

	// step 2.1
	usds::DictionaryArray* array_tag = (usds::DictionaryArray*)struct_tag->getField(1);
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getID() != 1 || strcmp(array_tag->getName(), "poly") != 0 || array_tag->getElementType() != usds::USDS_ARRAY || array_tag->isNullable() != true)
		throw "Failed at the step 2.1\n";

	// step 2.2
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_ARRAY || array_tag->isNullable() != false)
		throw "Failed at the step 2.2\n";

	// step 2.3
	array_tag = (usds::DictionaryArray*)array_tag->getElement();
	if (array_tag->getType() != usds::USDS_ARRAY || array_tag->getElementType() != usds::USDS_POLYMORPH || array_tag->isNullable() != false)
		throw "Failed at the step 2.3\n";

	// step 3
	poly_field = (usds::DictionaryPolymorph*)array_tag->getElement();
	if (poly_field->getType() != usds::USDS_POLYMORPH || poly_field->isNullable() != false)
		throw "Failed at the step 3\n";

	// step 4
	struct_tag = poly_field->getSubStruct(2);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 2 || strcmp(struct_tag->getName(), "struct_2") != 0 || struct_tag->isNullable() != false)
		throw "Failed at the step 4\n";

	// step 5
	struct_tag = poly_field->getSubStruct(4);
	if (struct_tag->getType() != usds::USDS_STRUCT || struct_tag->getID() != 4 || strcmp(struct_tag->getName(), "struct_4") != 0 || struct_tag->isNullable() != false)
		throw "Failed at the step 5\n";

	// step 6
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 6\n";

	// step 7
	try
	{
		struct_tag = poly_field->getSubStruct(1);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	try
	{
		struct_tag = poly_field->getSubStruct(3);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		struct_tag = poly_field->getSubStruct(5);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}
}


