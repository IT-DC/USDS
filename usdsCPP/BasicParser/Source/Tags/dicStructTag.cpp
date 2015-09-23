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

int DicStructTag::findFieldID(const char* name) throw (...)
{
	DicBaseField* field = firstField;
	while (field != 0)
	{
		if (strcmp(field->getName(), name) == 0)
			return field->getID();
		field = field->getNextField();
	}

	// if not found
	return 0;

};

void DicStructTag::finalizeTag(DicBaseTag* first_tag) throw(...)
{
	// Count fields, check names
	DicBaseField* field = firstField;
	while (field != 0)
	{
		// check name - unique in a tag
		DicBaseField* f = firstField;
		while (f != field)
		{
			if (strcmp(f->getName(), field->getName()) == 0)
			{
				std::stringstream err;
				err << "Field with name '" << field->getName() << "' already exists in tag ID = " << tagID;
				throw ErrorMessage(DIC_STRUCT_TAG_FIELD_ALREADY_EXISTS, &err, L"DicStructTag::finalizeTag");
			}
			f = f->getNextField();
		}
		// count data for index
		fieldNumber++;
		int id = field->getID();
		if (id > fieldMaxID)
			fieldMaxID = id;
		field = field->getNextField();
	}
	// Check field ID
	if (fieldMaxID != fieldNumber)
	{
		std::wstringstream err;
		err << L"Field numeration must be sequentially in a tag. Tag ID: " << tagID << ", field number: " << fieldNumber << ", wrong tag ID: " << fieldMaxID;
		throw ErrorMessage(DIC_STRUCT_TAG_FIELD_ID_ERROR_VALUE, &err, L"DicStructTag::finalizeTag");
	}

	// Create index
	fieldIndex.reserve(fieldNumber);
	fieldIndex.assign(fieldNumber, 0);
	field = firstField;
	while (field != 0)
	{
		int id = field->getID();
		// check id - unique in a tag
		if (fieldIndex[id - 1] != 0)
		{
			std::wstringstream err;
			err << L"Not unique field ID = " << id << " in Tag ID = " << tagID;
			throw ErrorMessage(DICTIONARY_TAG_ID_ERROR_VALUE, &err, L"DicStructTag::finalizeTag");
		}
		fieldIndex[id - 1] = field;
		field = field->getNextField();
	}

	// Finalize fields: replace TagName to TagID in Links
	field = firstField;
	while (field != 0)
	{
		switch (field->getType())
		{
		case USDS_ARRAY:
			break;
			((DicArrayField*)field)->finalizeField(first_tag);
		default:
			break;
		}
		field = field->getNextField();
	}


};



void DicStructTag::clear()
{
	firstField = 0;
	lastField = 0;

	fieldMaxID = 0;
	fieldNumber = 0;
	fieldIndex.clear();

};

void DicStructTag::checkFieldAttribute(int id, const char* name) throw (...)
{
	if (findFieldID(name) != 0)
	{
		std::stringstream err;
		err << "Field with name '" << name << "' already exists in tag ID = " << tagID;
		throw ErrorMessage(DIC_STRUCT_TAG_FIELD_ALREADY_EXISTS, &err, L"DicStructTag::checkFieldAttribute");
	}

	if (id <= 0 || id > 2147483647)
	{
		std::wstringstream err;
		err << L"Field ID must be in range [1; 2,147,483,647]. Current value:" << id;
		throw ErrorMessage(DIC_STRUCT_TAG_FIELD_ID_ERROR_VALUE, &err, L"DicStructTag::checkFieldAttribute");
	}
};