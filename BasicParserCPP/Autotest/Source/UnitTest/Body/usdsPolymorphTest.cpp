#include "usdsAutotest.h"

#include "dictionary/usdsDictionary.h"
#include "body/usdsBody.h"

#include "dictionary/dataTypes/dictionaryPolymorph.h"
#include "dictionary/dataTypes/dictionaryStruct.h"
#include "dictionary/dataTypes/dictionaryArray.h"

#include "body/dataTypes/usdsPolymorph.h"
#include "body/dataTypes/usdsStruct.h"
#include "body/dataTypes/usdsArray.h"

// Positive tests
void UsdsPolymorphTest::test_1()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;

	usds::DictionaryStruct* struct_tag_1 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct_1", 0);
	struct_tag_1->addField(usds::USDS_INT, 1, "int_field", 0);
	usds::DictionaryPolymorph* dict_poly_field = (usds::DictionaryPolymorph*)struct_tag_1->addField(usds::USDS_POLYMORPH, 2, "poly_field", 0);
	dict_poly_field->addTag(2);
	dict_poly_field->addTag(3);

	usds::DictionaryStruct* struct_tag_2 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 2, "struct_2", 0);
	struct_tag_2->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_3 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 3, "struct_3", 0);
	struct_tag_3->addField(usds::USDS_INT, 1, "int_field", 0);

	dict.finalizeDictionary();

	// test 1
	usds::UsdsStruct* body_struct = (usds::UsdsStruct*)body.addTag(struct_tag_1);
	usds::UsdsPolymorph* poly_field = (usds::UsdsPolymorph*)body_struct->getField(2);
	if (poly_field->getType() != usds::USDS_POLYMORPH || strcmp(poly_field->getName(), "poly_field") != 0)
		throw "Failed at the step 1\n";

	// test 2
	poly_field->setSubtagType(2);
	if (poly_field->getSubtagId() != 2 || poly_field->getSubtag()->getType() != usds::USDS_STRUCT || poly_field->getSubtag()->getID() != 2 || strcmp(poly_field->getSubtag()->getName(), "struct_2")!= 0)
		throw "Failed at the step 2\n";

	// test 3
	poly_field->setSubtagType(3);
	if (poly_field->getSubtagId() != 3 || poly_field->getSubtag()->getType() != usds::USDS_STRUCT || poly_field->getSubtag()->getID() != 3 || strcmp(poly_field->getSubtag()->getName(), "struct_3") != 0)
		throw "Failed at the step 3\n";
	
}

// Negative tests
void UsdsPolymorphTest::test_2()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;

	usds::DictionaryStruct* struct_tag_1 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 1, "struct_1", 0);
	struct_tag_1->addField(usds::USDS_INT, 1, "int_field", 0);
	usds::DictionaryPolymorph* dict_poly_field = (usds::DictionaryPolymorph*)struct_tag_1->addField(usds::USDS_POLYMORPH, 2, "poly_field", 0);
	dict_poly_field->addTag(2);
	dict_poly_field->addTag(3);

	usds::DictionaryStruct* struct_tag_2 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 2, "struct_2", 0);
	struct_tag_2->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_3 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 3, "struct_3", 0);
	struct_tag_3->addField(usds::USDS_INT, 1, "int_field", 0);

	dict.finalizeDictionary();

	// test 1
	usds::UsdsStruct* body_struct = (usds::UsdsStruct*)body.addTag(struct_tag_1);
	usds::UsdsPolymorph* poly_field = (usds::UsdsPolymorph*)body_struct->getField(2);
	try
	{
		poly_field->getSubtagId();
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_POLYMORPH__SUBTAG_IS_NOT_INITIALIZED)
		{
			throw "Failed at the step 1\n";
		}
	}

	// test 2
	try
	{
		poly_field->getSubtag();
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY_POLYMORPH__SUBTAG_IS_NOT_INITIALIZED)
		{
			throw "Failed at the step 2\n";
		}
	}


	// test 3
	try
	{
		poly_field->setSubtagType(1);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
		{
			throw "Failed at the step 3\n";
		}
	}

	// test 4
	try
	{
		poly_field->setSubtagType(4);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_POLYMORPH__TAG_NOT_FOUND)
		{
			throw "Failed at the step 4\n";
		}
	}

}

// Polymorph can not be Root
void UsdsPolymorphTest::test_3()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;

	usds::DictionaryPolymorph* dict_poly_tag = (usds::DictionaryPolymorph*)dict.addTag(usds::USDS_POLYMORPH, 1, "poly_tag", 0);
	dict_poly_tag->addTag(2);
	dict_poly_tag->addTag(3);

	usds::DictionaryStruct* struct_tag_2 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 2, "struct_2", 0);
	struct_tag_2->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_3 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 3, "struct_3", 0);
	struct_tag_3->addField(usds::USDS_INT, 1, "int_field", 0);

	dict.finalizeDictionary();

	// test 1
	try
	{
		body.addTag(dict_poly_tag);
		throw "Failed at the step 1\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::BODY__NOT_ROOT_TAG)
		{
			throw "Failed at the step 1\n";
		}
	}

}

// Array of polymorph
void UsdsPolymorphTest::test_4()
{
	usds::Dictionary dict(0);
	dict.setID("name", 1, 0, 0);
	usds::Body body;

	usds::DictionaryArray* dict_array_tag_1 = (usds::DictionaryArray*)dict.addTag(usds::USDS_ARRAY, 1, "array_1", 0);
	usds::DictionaryPolymorph* dict_poly_field = (usds::DictionaryPolymorph*)dict_array_tag_1->setElementType(usds::USDS_POLYMORPH);
	dict_poly_field->addTag(2);
	dict_poly_field->addTag(3);

	usds::DictionaryStruct* struct_tag_2 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 2, "struct_2", 0);
	struct_tag_2->addField(usds::USDS_INT, 1, "int_field", 0);

	usds::DictionaryStruct* struct_tag_3 = (usds::DictionaryStruct*)dict.addTag(usds::USDS_STRUCT, 3, "struct_3", 0);
	struct_tag_3->addField(usds::USDS_INT, 1, "int_field", 0);

	dict.finalizeDictionary();

	// test 1
	usds::UsdsArray* arr_tag = (usds::UsdsArray*)body.addTag(dict_array_tag_1);
	if (arr_tag->getElementType() != usds::USDS_POLYMORPH || arr_tag->getSize() != 0)
		throw "Failed at the step 1\n";

	// test 2
	usds::UsdsPolymorph* poly_element = (usds::UsdsPolymorph*)arr_tag->pushElementBack();
	poly_element->setSubtagType(2);
	poly_element = (usds::UsdsPolymorph*)arr_tag->pushElementBack();
	poly_element->setSubtagType(3);
	poly_element = (usds::UsdsPolymorph*)arr_tag->pushElementBack();
	poly_element->setSubtagType(2);

	poly_element = (usds::UsdsPolymorph*)arr_tag->getElement(0);
	if (poly_element->getType() != usds::USDS_POLYMORPH || poly_element->getSubtag()->getID() != 2 || strcmp(poly_element->getSubtag()->getName(), "struct_2")!=0)
		throw "Failed at the step 2\n";

	// test 3
	poly_element = (usds::UsdsPolymorph*)arr_tag->getElement(1);
	if (poly_element->getType() != usds::USDS_POLYMORPH || poly_element->getSubtag()->getID() != 3 || strcmp(poly_element->getSubtag()->getName(), "struct_3") != 0)
		throw "Failed at the step 3\n";

	// test 4
	poly_element = (usds::UsdsPolymorph*)arr_tag->getElement(2);
	if (poly_element->getType() != usds::USDS_POLYMORPH || poly_element->getSubtag()->getID() != 2 || strcmp(poly_element->getSubtag()->getName(), "struct_2") != 0)
		throw "Failed at the step 4\n";

}

