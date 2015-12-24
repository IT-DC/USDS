#include "dictionary\dataTypes\dictionaryStruct.h"
#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryArray.h"

#include <string>
#include <iostream>

using namespace usds;

DictionaryStruct::DictionaryStruct(Dictionary* dict) : DictionaryBaseType(dict)
{
	buffIndexSize = 8;
	fieldIndex = new DictionaryBaseType*[buffIndexSize];

	objectType = USDS_STRUCT;
};

DictionaryBaseType* DictionaryStruct::addField(usdsTypes field_type, int id, const char* name, size_t name_size) throw(...)
try
{
	// check name
	int field_id;
	if (name_size == 0)
		field_id = findFieldID(name);
	else
		field_id = findFieldID(name, name_size);
	if (field_id != 0)
		throw ErrorMessage(DIC_STRUCT__FIELD_ALREADY_EXISTS) << "Field with name '" << name << "' not unique in the tag " << objectName;
	
	DictionaryBaseType* field = dictionary->addField(field_type, this, id, name, name_size);
	connectFieldToTag(field);
	
	// count data for index
	fieldNumber++;
	if (id > fieldMaxID)
		fieldMaxID = id;

	return field;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryStruct::addField") << field_type << id << name << name_size << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryStruct::addField") << field_type << id << name << name_size;
	throw;
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
		throw ErrorStack("DictionaryStruct::getField") << id << (ErrorMessage(DIC_STRUCT__FIELD_ID_ERROR_VALUE) << "Field ID must be in range [1; " << fieldNumber << "]. Current value:" << id);

	return fieldIndex[id];
};

DictionaryBaseType* DictionaryStruct::getField(const char* name) throw (...)
{
	if (name == 0)
		throw ErrorStack("DictionaryStruct::getField") << name << ErrorMessage(DIC_STRUCT__NULL_NAME, "Name can not be NULL");

	DictionaryBaseType* field = firstField;
	while (field != 0)
	{
		if (strcmp(field->getName(), name) == 0)
			return field;
		field = field->getNext();
	}

	throw ErrorStack("DictionaryStruct::getField") << name << (ErrorMessage(DIC_STRUCT__FIELD_NOT_FOUND) << "Field '" << name << "' not found");

	return 0;
};

DictionaryBaseType* DictionaryStruct::getField(const char* name, size_t name_size) throw (...)
{
	if (name == 0)
		throw ErrorStack("DictionaryStruct::getField") << name << name_size << ErrorMessage(DIC_STRUCT__NULL_NAME, "Name can not be NULL");
	
	DictionaryBaseType* field = firstField;
	while (field != 0)
	{
		if (strcmp(field->getName(), name) == 0)
			return field;
		field = field->getNext();
	}

	throw ErrorStack("DictionaryStruct::getField").addStringAttribute(name, name_size) << name_size << ((ErrorMessage(DIC_STRUCT__FIELD_NOT_FOUND) << "Field '").addString(name, name_size) << "' not found");
	return 0;
};


int DictionaryStruct::findFieldID(const char* name) throw (...)
{
	if (name == 0)
		throw ErrorStack("DictionaryStruct::findFieldID") << name << ErrorMessage(DIC_STRUCT__NULL_NAME, "Name can not be NULL");
	
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
	if (name == 0)
		throw ErrorStack("DictionaryStruct::findFieldID") << name << name_size << ErrorMessage(DIC_STRUCT__NULL_NAME, "Name can not be NULL");

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
try
{
	// Check field ID
	if (fieldMaxID != fieldNumber)
		throw ErrorMessage(DIC_STRUCT__FIELD_ID_ERROR_VALUE) << "Field numeration must be sequentially in a tag. Tag ID: " << objectID << ", field number: " << fieldNumber << ", wrong tag ID: " << fieldMaxID;;

	// Create index
	if (fieldNumber >= buffIndexSize)
	{
		delete[] fieldIndex;
		buffIndexSize = fieldNumber + 1;
		fieldIndex = new DictionaryBaseType*[buffIndexSize];
	}
	for (int id = 1; id <= fieldNumber; id++)
		fieldIndex[id] = 0;

	DictionaryBaseType* field = firstField;
	while (field != 0)
	{
		int id = field->getID();
		// check id - unique in a tag
		if (fieldIndex[id] != 0)
			throw ErrorMessage(DIC_STRUCT__FIELD_ALREADY_EXISTS) << "Not unique field ID = " << id << " in Tag ID = " << objectID;
		fieldIndex[id] = field;
		field = field->getNext();
	}

	// Finalize fields: replace TagName to TagID in Links
	firstField = 0;
	lastField = 0;
	for (int id = 1; id <= fieldNumber; id++)
	{
		field = fieldIndex[id];
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
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryStruct::finalize") << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryStruct::finalize");
	throw;
}

void DictionaryStruct::clear()
{
	firstField = 0;
	lastField = 0;

	fieldMaxID = 0;
	fieldNumber = 0;

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