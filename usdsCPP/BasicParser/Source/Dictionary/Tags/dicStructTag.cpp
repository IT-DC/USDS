#include "dictionary\tags\dicStructTag.h"
#include "dictionary\usdsDictionary.h"
#include "dictionary\fields\dicBaseField.h"
#include "dictionary\fields\dicArrayField.h"

#include <string>
#include <iostream>

using namespace usds;

DicStructTag::DicStructTag()
{


};

DicBaseField* DicStructTag::addField(usdsTypes field_type, int id, const char* name, size_t name_size) throw(...)
try
{
	// check type
	if (field_type < 1 || field_type > 32)
	{
		std::wstringstream msg;
		msg << L"Unsupported field type '" << field_type << "'";
		throw ErrorMessage(DIC_STRUCT_TAG_UNSUPPORTED_TYPE, &msg);
	}

	// check ID
	if (id <= 0)
	{
		std::wstringstream err;
		err << L"Field ID must be in range [1; 2,147,483,647]. Current value:" << id;
		throw ErrorMessage(DIC_STRUCT_TAG_FIELD_ID_ERROR_VALUE, &err);
	}

	// check name
	int field_id;
	if (name_size == 0)
		field_id = findFieldID(name);
	else
		field_id = findFieldID(name, name_size);
	if (field_id != 0)
	{
		std::stringstream err;
		err << "Field with name '" << name << "' not unique in the tag " << tagName;
		throw ErrorMessage(DIC_STRUCT_TAG_FIELD_ALREADY_EXISTS, &err);
	}

	DicBaseField* field = (dictionary->getObjectPool())->addField(field_type, dictionary, this, id, name, name_size);
	connectFieldToTag(field);
	
	// count data for index
	fieldNumber++;
	if (id > fieldMaxID)
		fieldMaxID = id;

	return field;
}
catch (ErrorMessage& err)
{
	err.addPath(L"DicStructTag::addField");
	throw err;
};

DicBaseField* DicStructTag::getFirstField()
{

	return firstField;
};

DicBaseField* DicStructTag::getLastField()
{

	return lastField;
};

DicBaseField* DicStructTag::getField(int id) throw (...)
{
	if (id > fieldNumber)
		return 0;

	return fieldIndex[id-1];
};

int DicStructTag::getFieldNumber() throw (...)
{

	return fieldNumber;
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

int DicStructTag::findFieldID(const char* name, size_t name_size) throw (...)
{
	DicBaseField* field = firstField;
	while (field != 0)
	{
		if (strncmp(field->getName(), name, name_size) == 0)
			return field->getID();
		field = field->getNextField();
	}

	// if not found
	return 0;

};

void DicStructTag::finalizeTag() throw(...)
{
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
	DicBaseField* field = firstField;
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
	firstField = 0;
	lastField = 0;
	for (int i = 0; i < fieldNumber; i++)
	{
		field = fieldIndex[i];
		switch (field->getType())
		{
		case USDS_ARRAY:
			((DicArrayField*)field)->finalizeField();
			break;
		default:
			break;
		}
		connectFieldToTag(field);
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

//=========================================================================================

void DicStructTag::connectFieldToTag(DicBaseField* field)
{
	if (firstField == 0)
		firstField = field;
	field->setPreviousField(lastField);
	field->setNextField(0);
	if (lastField != 0)
		lastField->setNextField(field);
	lastField = field;


};