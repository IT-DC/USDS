#include "tags\dicBaseTag.h"
#include "tags\dicStructTag.h"
#include "tags\dicStructFields.h"

#include <string>
#include <iostream>

using namespace usds;

DicStructTag::DicStructTag(DictionaryObjectPool* pull) : DicBaseTag(pull)
{


};

void DicStructTag::writeToBinary(BinaryOutput* buff) throw(...)
{


};

void DicStructTag::setFields(DicBaseField* fields) throw(...)
{
	if (fields == 0)
		throw ErrorMessage(DIC_STRUCT_TAG_NOT_INITIALIZED_FIELD, L"Fields must be not null", L"DicStructTag::setFields");
	DicBaseField* field = fields;
	firstField = field;
	while (field->getNextField() != 0)
	{
		field->setParentTag(this);
		field = field->getNextField();
	};
	// last field
	field->setParentTag(this);
	lastField = field;
};

DicBaseField* DicStructTag::getFirstField()
{

	return firstField;
};

DicBaseField* DicStructTag::getLastField()
{

	return lastField;
};

DicIntField* DicStructTag::addIntField(const char* name, int id, bool optional) throw(...)
{

	return 0;
};
DicIntField* DicStructTag::addIntField(const char* name, int id, int default_value) throw(...)
{

	return 0;
};

void DicStructTag::clear()
{
	firstField = 0;
	lastField = 0;
};
