#include "usdsAutotest.h"

#include "dictionary/usdsDictionary.h"
#include "dictionary/dataTypes/dictionaryPolymorph.h"
#include "dictionary/dataTypes/dictionaryStruct.h"
#include "dictionary/dataTypes/dictionaryTagLink.h"
#include "dictionary/dataTypes/dictionaryInt.h"

void DictionaryPolymorphTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	
	usds::DictionaryStruct* struct_tag_1 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct_1", 0);
	struct_tag_1->addField(usds::USDS_INT, 1, "int_field", 0);
	usds::DictionaryPolymorph* poly_field = (usds::DictionaryPolymorph*)struct_tag_1->addField(usds::USDS_POLYMORPH, 2, "poly_field", 0);
	poly_field->addTag(2);
	poly_field->addTag(3);
	poly_field->addTag(4);

	usds::DictionaryPolymorph* poly_tag_2 = (usds::DictionaryPolymorph*)dict.addTag(usds::USDS_POLYMORPH, 2, "poly_tag_2", 0);
	poly_tag_2->addTag(4);
	poly_tag_2->addTag(9);

	usds::DictionaryStruct* struct_tag_3 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 3, "struct_3", 0);
	struct_tag_3->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_4 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 4, "struct_4", 0);
	struct_tag_4->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_5 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 5, "struct_5", 0);
	struct_tag_5->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_6 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 6, "struct_6", 0);
	struct_tag_6->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_7 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 7, "struct_7", 0);
	struct_tag_7->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_8 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 8, "struct_8", 0);
	struct_tag_8->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryPolymorph* poly_tag_9 = (usds::DictionaryPolymorph*)dict.addTag(usds::USDS_POLYMORPH, 9, "poly_tag_9", 0);
	poly_tag_9->addTag(4);
	poly_tag_9->addTag(6);
	poly_tag_9->addTag(8);

	dict.finalizeDictionary();

	// test 1
	poly_field = (usds::DictionaryPolymorph*)struct_tag_1->getField(2);
	if (poly_field->getType() != usds::USDS_POLYMORPH || poly_field->getID() != 2 || strcmp(poly_field->getName(), "poly_field")!= 0)
		throw "Failed at the step 1\n";
	
	// test 2
	try
	{
		poly_field->getSubStruct(1);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 2\n";
	}

	// test 2.1
	try
	{
		poly_field->getSubStruct("struct_1");
		throw "Failed at the step 2.1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 2.1\n";
	}

	// test 2.2
	try
	{
		poly_field->getSubtagId("struct_1");
		throw "Failed at the step 2.2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 2.2\n";
	}

	// test 3
	try
	{
		poly_field->getSubStruct(2);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 3\n";
	}

	// test 3.1
	try
	{
		poly_field->getSubStruct("struct_2");
		throw "Failed at the step 3.1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 3.1\n";
	}

	// test 3.2
	try
	{
		poly_field->getSubtagId("struct_2");
		throw "Failed at the step 3.2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 3.2\n";
	}

	// test 4
	try
	{
		poly_field->getSubStruct(5);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 4\n";
	}

	// test 4.1
	try
	{
		poly_field->getSubStruct("struct_5");
		throw "Failed at the step 4.1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 4.1\n";
	}

	// test 4.2
	try
	{
		poly_field->getSubtagId("struct_5");
		throw "Failed at the step 4.2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 4.2\n";
	}

	// test 5
	try
	{
		poly_field->getSubStruct(7);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 5\n";
	}

	// test 5.1
	try
	{
		poly_field->getSubStruct("struct_7");
		throw "Failed at the step 5.1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 5.1\n";
	}

	// test 5.2
	try
	{
		poly_field->getSubtagId("struct_7");
		throw "Failed at the step 5.2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 5.2\n";
	}

	// test 6
	if (
		poly_field->getSubStruct(3) != dict.getTag(3) ||
		poly_field->getSubStruct(4) != dict.getTag(4) ||
		poly_field->getSubStruct(6) != dict.getTag(6) ||
		poly_field->getSubStruct(8) != dict.getTag(8) ||
		poly_field->getSubStruct("struct_3") != dict.getTag(3) ||
		poly_field->getSubStruct("struct_4") != dict.getTag(4) ||
		poly_field->getSubStruct("struct_6") != dict.getTag(6) ||
		poly_field->getSubStruct("struct_8") != dict.getTag(8) ||
		poly_field->getSubtagId("struct_3") != 3 ||
		poly_field->getSubtagId("struct_4") != 4 ||
		poly_field->getSubtagId("struct_6") != 6 ||
		poly_field->getSubtagId("struct_8") != 8
		)
		throw "Failed at the step 6\n";

	// test 7
	poly_tag_2 = (usds::DictionaryPolymorph*)dict.getTag(2);
	if (poly_tag_2->getType() != usds::USDS_POLYMORPH || poly_tag_2->getID() != 2 || strcmp(poly_tag_2->getName(), "poly_tag_2") != 0)
		throw "Failed at the step 7\n";

	// test 8
	try
	{
		poly_tag_2->getSubStruct(1);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// test 9
	try
	{
		poly_tag_2->getSubStruct(2);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}

	// test 10
	try
	{
		poly_tag_2->getSubStruct(3);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 10\n";
	}


	// test 11
	try
	{
		poly_tag_2->getSubStruct(5);
		throw "Failed at the step 11\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 11\n";
	}

	// test 12
	try
	{
		poly_tag_2->getSubStruct(7);
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 12\n";
	}

	// test 13
	if (
		poly_tag_2->getSubStruct(4) != dict.getTag(4) ||
		poly_tag_2->getSubStruct(6) != dict.getTag(6) ||
		poly_tag_2->getSubStruct(8) != dict.getTag(8)
		)
		throw "Failed at the step 13\n";

	// test 14
	poly_tag_9 = (usds::DictionaryPolymorph*)dict.getTag(9);
	if (poly_tag_9->getType() != usds::USDS_POLYMORPH || poly_tag_9->getID() != 9 || strcmp(poly_tag_9->getName(), "poly_tag_9") != 0)
		throw "Failed at the step 14\n";

	// test 15
	try
	{
		poly_tag_9->getSubStruct(1);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 15\n";
	}

	// test 16
	try
	{
		poly_tag_9->getSubStruct(2);
		throw "Failed at the step 16\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 16\n";
	}

	// test 17
	try
	{
		poly_tag_9->getSubStruct(3);
		throw "Failed at the step 17\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 17\n";
	}

	// test 18
	try
	{
		poly_tag_9->getSubStruct(5);
		throw "Failed at the step 18\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 18\n";
	}

	// test 19
	try
	{
		poly_tag_9->getSubStruct(7);
		throw "Failed at the step 19\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 19\n";
	}

	// test 20
	if (
		poly_tag_9->getSubStruct(4) != dict.getTag(4) ||
		poly_tag_9->getSubStruct(6) != dict.getTag(6) ||
		poly_tag_9->getSubStruct(8) != dict.getTag(8)
		)
		throw "Failed at the step 20\n";
	
	// test 21
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(3) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 21\n";

	// test 22
	if (
		poly_tag_2->getFirstTag()->getTag() != dict.getTag(4) ||
		((usds::DictionaryTagLink*)poly_tag_2->getFirstTag()->getNext())->getTag() != dict.getTag(9)
		)
		throw "Failed at the step 22\n";

	// test 23
	if (
		poly_tag_9->getFirstTag()->getTag() != dict.getTag(4) ||
		((usds::DictionaryTagLink*)poly_tag_9->getFirstTag()->getNext())->getTag() != dict.getTag(6) ||
		((usds::DictionaryTagLink*)poly_tag_9->getFirstTag()->getNext()->getNext())->getTag() != dict.getTag(8)
		)
		throw "Failed at the step 23\n";
}

void DictionaryPolymorphTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);

	usds::DictionaryStruct* struct_tag_1 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct_1", 0);
	struct_tag_1->addField(usds::USDS_INT, 1, "int_field", 0);
	usds::DictionaryPolymorph* poly_field = (usds::DictionaryPolymorph*)struct_tag_1->addField(usds::USDS_POLYMORPH, 2, "poly_field", 0);
	poly_field->addTag("poly_tag_2", 0);
	poly_field->addTag("struct_3", 0);
	poly_field->addTag("struct_4", 0);

	usds::DictionaryPolymorph* poly_tag_2 = (usds::DictionaryPolymorph*)dict.addTag(usds::USDS_POLYMORPH, 2, "poly_tag_2", 0);
	poly_tag_2->addTag("struct_4", 0);
	poly_tag_2->addTag("poly_tag_9", 0);

	usds::DictionaryStruct* struct_tag_3 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 3, "struct_3", 0);
	struct_tag_3->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_4 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 4, "struct_4", 0);
	struct_tag_4->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_5 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 5, "struct_5", 0);
	struct_tag_5->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_6 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 6, "struct_6", 0);
	struct_tag_6->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_7 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 7, "struct_7", 0);
	struct_tag_7->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_8 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 8, "struct_8", 0);
	struct_tag_8->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryPolymorph* poly_tag_9 = (usds::DictionaryPolymorph*)dict.addTag(usds::USDS_POLYMORPH, 9, "poly_tag_9", 0);
	poly_tag_9->addTag("struct_4", 0);
	poly_tag_9->addTag("struct_6", 0);
	poly_tag_9->addTag("struct_8", 0);

	dict.finalizeDictionary();

	// test 1
	poly_field = (usds::DictionaryPolymorph*)struct_tag_1->getField(2);
	if (poly_field->getType() != usds::USDS_POLYMORPH || poly_field->getID() != 2 || strcmp(poly_field->getName(), "poly_field") != 0)
		throw "Failed at the step 1\n";

	// test 2
	try
	{
		poly_field->getSubStruct(1);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 2\n";
	}

	// test 3
	try
	{
		poly_field->getSubStruct(2);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 3\n";
	}

	// test 4
	try
	{
		poly_field->getSubStruct(5);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 4\n";
	}

	// test 5
	try
	{
		poly_field->getSubStruct(7);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 5\n";
	}

	// test 6
	if (
		poly_field->getSubStruct(3) != dict.getTag(3) ||
		poly_field->getSubStruct(4) != dict.getTag(4) ||
		poly_field->getSubStruct(6) != dict.getTag(6) ||
		poly_field->getSubStruct(8) != dict.getTag(8)
		)
		throw "Failed at the step 6\n";

	// test 7
	poly_tag_2 = (usds::DictionaryPolymorph*)dict.getTag(2);
	if (poly_tag_2->getType() != usds::USDS_POLYMORPH || poly_tag_2->getID() != 2 || strcmp(poly_tag_2->getName(), "poly_tag_2") != 0)
		throw "Failed at the step 7\n";

	// test 8
	try
	{
		poly_tag_2->getSubStruct(1);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 8\n";
	}

	// test 9
	try
	{
		poly_tag_2->getSubStruct(2);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 9\n";
	}

	// test 10
	try
	{
		poly_tag_2->getSubStruct(3);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 10\n";
	}


	// test 11
	try
	{
		poly_tag_2->getSubStruct(5);
		throw "Failed at the step 11\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 11\n";
	}

	// test 12
	try
	{
		poly_tag_2->getSubStruct(7);
		throw "Failed at the step 12\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 12\n";
	}

	// test 13
	if (
		poly_tag_2->getSubStruct(4) != dict.getTag(4) ||
		poly_tag_2->getSubStruct(6) != dict.getTag(6) ||
		poly_tag_2->getSubStruct(8) != dict.getTag(8)
		)
		throw "Failed at the step 13\n";

	// test 14
	poly_tag_9 = (usds::DictionaryPolymorph*)dict.getTag(9);
	if (poly_tag_9->getType() != usds::USDS_POLYMORPH || poly_tag_9->getID() != 9 || strcmp(poly_tag_9->getName(), "poly_tag_9") != 0)
		throw "Failed at the step 14\n";

	// test 15
	try
	{
		poly_tag_9->getSubStruct(1);
		throw "Failed at the step 15\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 15\n";
	}

	// test 16
	try
	{
		poly_tag_9->getSubStruct(2);
		throw "Failed at the step 16\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 16\n";
	}

	// test 17
	try
	{
		poly_tag_9->getSubStruct(3);
		throw "Failed at the step 17\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 17\n";
	}

	// test 18
	try
	{
		poly_tag_9->getSubStruct(5);
		throw "Failed at the step 18\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 18\n";
	}

	// test 19
	try
	{
		poly_tag_9->getSubStruct(7);
		throw "Failed at the step 19\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 19\n";
	}

	// test 20
	if (
		poly_tag_9->getSubStruct(4) != dict.getTag(4) ||
		poly_tag_9->getSubStruct(6) != dict.getTag(6) ||
		poly_tag_9->getSubStruct(8) != dict.getTag(8)
		)
		throw "Failed at the step 20\n";

	// test 21
	if (
		poly_field->getFirstTag()->getTag() != dict.getTag(2) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext())->getTag() != dict.getTag(3) ||
		((usds::DictionaryTagLink*)poly_field->getFirstTag()->getNext()->getNext())->getTag() != dict.getTag(4)
		)
		throw "Failed at the step 21\n";

	// test 22
	if (
		poly_tag_2->getFirstTag()->getTag() != dict.getTag(4) ||
		((usds::DictionaryTagLink*)poly_tag_2->getFirstTag()->getNext())->getTag() != dict.getTag(9)
		)
		throw "Failed at the step 22\n";

	// test 23
	if (
		poly_tag_9->getFirstTag()->getTag() != dict.getTag(4) ||
		((usds::DictionaryTagLink*)poly_tag_9->getFirstTag()->getNext())->getTag() != dict.getTag(6) ||
		((usds::DictionaryTagLink*)poly_tag_9->getFirstTag()->getNext()->getNext())->getTag() != dict.getTag(8)
		)
		throw "Failed at the step 23\n";
}

void DictionaryPolymorphTest::test_3()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);

	// step 1
	dict.addTag(usds::USDS_INT, 1, "int", 0);
	((usds::DictionaryPolymorph*)dict.addTag(usds::USDS_POLYMORPH, 2, "poly", 0))->addTag(1);
	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__UNSUPPORTED_SUBTAG)
			throw "Failed at the step 1\n";
	}

	// step 2
	dict.clear();
	dict.addTag(usds::USDS_INT, 1, "int", 0);
	dict.addTag(usds::USDS_POLYMORPH, 2, "poly", 0);
	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__ZERO_NUMBERS_OF_SUBTAGS)
			throw "Failed at the step 2\n";
	}

	// step 3
	dict.clear();
	((usds::DictionaryPolymorph*)dict.addTag(usds::USDS_POLYMORPH, 1, "poly1", 0))->addTag(2);
	((usds::DictionaryPolymorph*)dict.addTag(usds::USDS_POLYMORPH, 2, "poly2", 0))->addTag(1);
	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__RECURSION_IS_FORBIDDEN)
			throw "Failed at the step 3\n";
	}

	// step 4
	dict.clear();
	((usds::DictionaryPolymorph*)dict.addTag(usds::USDS_POLYMORPH, 1, "poly1", 0))->addTag(2);
	((usds::DictionaryPolymorph*)dict.addTag(usds::USDS_POLYMORPH, 2, "poly2", 0))->addTag(3);
	((usds::DictionaryPolymorph*)dict.addTag(usds::USDS_POLYMORPH, 3, "poly3", 0))->addTag(1);
	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__RECURSION_IS_FORBIDDEN)
			throw "Failed at the step 4\n";
	}


	// step 5
	dict.clear();
	usds::DictionaryStruct* struct_tag_1 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct_1", 0);
	struct_tag_1->addField(usds::USDS_INT, 1, "int_field", 0);
	usds::DictionaryPolymorph* poly_field = (usds::DictionaryPolymorph*)struct_tag_1->addField(usds::USDS_POLYMORPH, 2, "poly_field", 0);
	poly_field->addTag(2);

	usds::DictionaryStruct* struct_tag_2 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 2, "struct_2", 0);
	struct_tag_2->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_3 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 3, "struct_3", 0);
	struct_tag_3->addField(usds::USDS_INT, 1, "int_field", 0);
	
	dict.finalizeDictionary();
	try
	{
		poly_field->addTag(3);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__ALREADY_FINALIZED)
			throw "Failed at the step 5\n";
	}

	// step 6
	try
	{
		poly_field->addTag("struct_3", 0);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__ALREADY_FINALIZED)
			throw "Failed at the step 6\n";
	}

	// step 7
	try
	{
		poly_field->getSubStruct(4);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
			throw "Failed at the step 7\n";
	}

	// step 8
	dict.clear();
	struct_tag_1 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct_1", 0);
	struct_tag_1->addField(usds::USDS_INT, 1, "int_field", 0);
	poly_field = (usds::DictionaryPolymorph*)struct_tag_1->addField(usds::USDS_POLYMORPH, 2, "poly_field", 0);
	poly_field->addTag(2);

	struct_tag_2 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 2, "struct_2", 0);
	struct_tag_2->addField(usds::USDS_INT, 1, "int_field", 0);

	try
	{
		poly_field->getSubStruct(2);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__NOT_FINALIZED)
			throw "Failed at the step 8\n";
	}

	// step 9
	try
	{
		poly_field->getFirstTag();
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__NOT_FINALIZED)
			throw "Failed at the step 9\n";
	}

	// step 10
	dict.clear();
	struct_tag_1 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct_1", 0);
	struct_tag_1->addField(usds::USDS_INT, 1, "int_field", 0);
	poly_field = (usds::DictionaryPolymorph*)struct_tag_1->addField(usds::USDS_POLYMORPH, 2, "poly_field", 0);
	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__ZERO_NUMBERS_OF_SUBTAGS)
			throw "Failed at the step 10\n";
	}

	// step 11
	dict.clear();
	struct_tag_1 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct_1", 0);
	struct_tag_1->addField(usds::USDS_INT, 1, "int_field", 0);
	poly_field = (usds::DictionaryPolymorph*)struct_tag_1->addField(usds::USDS_POLYMORPH, 2, "poly_field", 0);
	poly_field->addTag(2);
	
	usds::DictionaryPolymorph* poly_tag_2 = (usds::DictionaryPolymorph*)dict.addTag(usds::USDS_POLYMORPH, 2, "poly_tag_2", 0);
	poly_tag_2->addTag(3);

	dict.addTag(usds::USDS_INT, 3, "int", 0);

	try
	{
		dict.finalizeDictionary();
		throw "Failed at the step 11\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__UNSUPPORTED_SUBTAG)
			throw "Failed at the step 11\n";
	}

}


