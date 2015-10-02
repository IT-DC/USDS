#include "dictionary\fields\dicBaseField.h"

using namespace usds;

void DicBaseField::init(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size) throw(...)
{
	nextField = 0;
	previousField = 0;

	clear();

	dictionary = dict;
	parentTag = tag;

	if (name_size == 0)
		fieldName = name;
	else
		fieldName.assign(name, name_size);
	fieldID = id;
	isNullable = false;

};

const char* DicBaseField::getName() throw(...)
{

	return fieldName.c_str();
};

size_t DicBaseField::getNameSize() throw(...)
{

	return fieldName.size();
};

int DicBaseField::getID() throw(...)
{

	return fieldID;
};

DicBaseField* DicBaseField::getNextField() throw (...)
{

	return nextField;
};

DicBaseField* DicBaseField::getPreviousField() throw (...)
{

	return previousField;
};

DicStructTag* DicBaseField::getParentTag() throw (...)
{

	return parentTag;
};

void DicBaseField::setNextField(DicBaseField* next)
{

	nextField = next;
};

void DicBaseField::setPreviousField(DicBaseField* previous)
{

	previousField = previous;
};

void DicBaseField::setParentTag(DicStructTag* parent)
{

	parentTag = parent;
};

