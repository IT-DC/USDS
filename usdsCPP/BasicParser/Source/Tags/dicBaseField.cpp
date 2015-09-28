#include "tags\dicBaseField.h"
#include "base\usdsObjectPool.h"
#include "base\usdsBinaryOutput.h"
#include "tags\dicStructTag.h"

using namespace usds;

void DicBaseField::init(Dictionary* dict, int id, const char* name, size_t name_size, bool optional) throw(...)
{
	parentTag = 0;
	nextField = 0;
	previousField = 0;
	clear();

	dictionary = dict;

	if (name_size == 0)
		fieldName = name;
	else
		fieldName.assign(name, name_size);
	fieldID = id;
	isOptional = optional;

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

