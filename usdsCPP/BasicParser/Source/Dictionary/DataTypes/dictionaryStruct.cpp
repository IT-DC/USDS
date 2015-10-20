#include "dictionary\dataTypes\dictionaryStruct.h"
#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryArray.h"

#include <string>
#include <iostream>

using namespace usds;

DictionaryStruct::DictionaryStruct(DictionaryObjectPool* parent) : DictionaryBaseType(parent)
{


};

DictionaryBaseType* DictionaryStruct::addField(usdsTypes field_type, int id, const char* name, size_t name_size) throw(...)
try
{
	// check type
	if (field_type < 1 || field_type >= USDS_LAST_TYPE)
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
		err << "Field with name '" << name << "' not unique in the tag " << objectName;
		throw ErrorMessage(DIC_STRUCT_TAG_FIELD_ALREADY_EXISTS, &err);
	}

	DictionaryBaseType* field = objectPool->addObject(field_type, dictionary, this, id, name, name_size);
	connectFieldToTag(field);
	
	// count data for index
	fieldNumber++;
	if (id > fieldMaxID)
		fieldMaxID = id;

	return field;
}
catch (ErrorMessage& err)
{
	err.addPath(L"DictionaryStruct::addField");
	throw err;
};

DictionaryBaseType* DictionaryStruct::getFirstField()
{

	return firstField;
};

DictionaryBaseType* DictionaryStruct::getLastField()
{

	return lastField;
};

int DictionaryStruct::getFieldNumber() throw (...)
{

	return fieldNumber;
};

//==============================================================================================
DictionaryBaseType* DictionaryStruct::getField(int id) throw (...)
{
	if (id > fieldNumber)
		return 0;

	return fieldIndex[id-1];
};

DictionaryBaseType* DictionaryStruct::getField(const char* name) throw (...)
{
	DictionaryBaseType* field = firstField;
	while (field != 0)
	{
		if (strcmp(field->getName(), name) == 0)
			return field;
		field = field->getNext();
	}

	// if not found
	return 0;
};

DictionaryBaseType* DictionaryStruct::getField(const char* name, size_t name_size) throw (...)
{
	DictionaryBaseType* field = firstField;
	while (field != 0)
	{
		if (strcmp(field->getName(), name) == 0)
			return field;
		field = field->getNext();
	}

	// if not found
	return 0;
};


int DictionaryStruct::findFieldID(const char* name) throw (...)
{
	DictionaryBaseType* field = firstField;
	while (field != 0)
	{
		if (strcmp(field->getName(), name) == 0)
			return field->getID();
		field = field->getNext();
	}

	// if not found
	return 0;

};

int DictionaryStruct::findFieldID(const char* name, size_t name_size) throw (...)
{
	DictionaryBaseType* field = firstField;
	while (field != 0)
	{
		if (strncmp(field->getName(), name, name_size) == 0)
			return field->getID();
		field = field->getNext();
	}

	// if not found
	return 0;

};

void DictionaryStruct::finalize() throw(...)
{
	// Check field ID
	if (fieldMaxID != fieldNumber)
	{
		std::wstringstream err;
		err << L"Field numeration must be sequentially in a tag. Tag ID: " << objectID << ", field number: " << fieldNumber << ", wrong tag ID: " << fieldMaxID;
		throw ErrorMessage(DIC_STRUCT_TAG_FIELD_ID_ERROR_VALUE, &err, L"DictionaryStruct::finalizeTag");
	}

	// Create index
	fieldIndex.reserve(fieldNumber);
	fieldIndex.assign(fieldNumber, 0);
	DictionaryBaseType* field = firstField;
	while (field != 0)
	{
		int id = field->getID();
		// check id - unique in a tag
		if (fieldIndex[id - 1] != 0)
		{
			std::wstringstream err;
			err << L"Not unique field ID = " << id << " in Tag ID = " << objectID;
			throw ErrorMessage(DICTIONARY_TAG_ID_ERROR_VALUE, &err, L"DictionaryStruct::finalizeTag");
		}
		fieldIndex[id - 1] = field;
		field = field->getNext();
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
			((DictionaryArray*)field)->finalize();
			break;
		default:
			break;
		}
		connectFieldToTag(field);
	}
	
};

void DictionaryStruct::clear()
{
	firstField = 0;
	lastField = 0;

	fieldMaxID = 0;
	fieldNumber = 0;
	fieldIndex.clear();

};

//=========================================================================================

void DictionaryStruct::connectFieldToTag(DictionaryBaseType* field)
{
	if (firstField == 0)
		firstField = field;
	field->setPrevious(lastField);
	field->setNext(0);
	if (lastField != 0)
		lastField->setNext(field);
	lastField = field;


};