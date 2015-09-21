#include "tags\dicBaseField.h"

using namespace usds;

void DicBaseField::init(const char* name, int id, bool optional) throw(...)
{
	parentTag = 0;
	nextField = 0;
	previousField = 0;
	clear();

	fieldName = name;
	fieldID = id;
	isOptional = optional;

};

const char* DicBaseField::getName() throw(...)
{

	return fieldName.c_str();
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

