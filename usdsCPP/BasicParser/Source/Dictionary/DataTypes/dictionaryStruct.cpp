#include "dictionary\dataTypes\dictionaryStruct.h"
#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"

#include <string>
#include <iostream>

using namespace usds;

DictionaryStruct::DictionaryStruct(Dictionary* dict) : DictionaryBaseType(dict)
{
	buffIndexSize = 0;
	fieldIndex = 0;

	objectType = USDS_STRUCT;
};


DictionaryStruct::~DictionaryStruct()
{
	if (fieldIndex != 0)
		delete[] fieldIndex;
}

DictionaryBaseType* DictionaryStruct::addField(usdsTypes field_type, int32_t id, const char* name, size_t name_size) throw(...)
try
{
	if (indexed)
		throw ErrorMessage(DIC_STRUCT__STRUCT_IS_FINALIZED, "Can not add a field: the structure is finalized already");
	
	// check name
	int32_t field_id;
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

int32_t DictionaryStruct::getFieldNumber() throw (...)
{

	return fieldNumber;
};

//==============================================================================================
DictionaryBaseType* DictionaryStruct::getField(int32_t id) throw (...)
{
	if (!indexed)
		throw ErrorStack("DictionaryStruct::getField") << id << ErrorMessage(DIC_STRUCT__STRUCT_IS_NOT_FINALIZED, "Function is not available: struct is not finalized.");
	
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
		if (name_size == 0)
		{
			if (strcmp(field->getName(), name) == 0)
				return field;
		}
		else
		{
			if (strncmp(field->getName(), name, name_size) == 0)
				return field;
		}
		field = field->getNext();
	}

	throw ErrorStack("DictionaryStruct::getField").addStringAndSize(name, name_size) << ((ErrorMessage(DIC_STRUCT__FIELD_NOT_FOUND) << "Field '").addString(name, name_size) << "' not found");
	return 0;
};


int32_t DictionaryStruct::findFieldID(const char* name) throw (...)
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

int32_t DictionaryStruct::findFieldID(const char* name, size_t name_size) throw (...)
{
	if (name == 0)
		throw ErrorStack("DictionaryStruct::findFieldID") << name << name_size << ErrorMessage(DIC_STRUCT__NULL_NAME, "Name can not be NULL");

	DictionaryBaseType* field = firstField;
	while (field != 0)
	{
		if (name_size == 0)
		{
			if (strcmp(field->getName(), name) == 0)
				return field->getID();
		}
		else
		{
			if (strncmp(field->getName(), name, name_size) == 0)
				return field->getID();
		}
		field = field->getNext();
	}

	// if not found
	return 0;

};

void DictionaryStruct::finalize() throw(...)
try
{
	if (indexed)
		throw ErrorMessage(DIC_STRUCT__STRUCT_IS_FINALIZED, "The structure is finalized already");
	if (fieldNumber == 0)
		throw ErrorMessage(DIC_STRUCT__NO_FIELD, "Structure can not be without fields");

	// Check field ID
	if (fieldMaxID != fieldNumber)
		throw ErrorMessage(DIC_STRUCT__FIELD_ID_ERROR_VALUE) << "Field numeration must be sequentially in a tag. Tag ID: " << objectID << ", field number: " << fieldNumber << ", wrong tag ID: " << fieldMaxID;;

	// Create index
	if (fieldNumber >= buffIndexSize)
	{
		if (fieldIndex != 0)
			delete[] fieldIndex;
		buffIndexSize = fieldNumber + 1;
		try
		{
			fieldIndex = new DictionaryBaseType*[buffIndexSize];
		}
		catch (...)
		{
			fieldIndex = 0;
			buffIndexSize = 0;
			throw ErrorMessage(DIC_STRUCT__ALLOCATE_ERROR, "Memory allocation error");
		}
	}
	for (int32_t id = 1; id <= fieldNumber; id++)
		fieldIndex[id] = 0;

	DictionaryBaseType* field = firstField;
	while (field != 0)
	{
		int32_t id = field->getID();
		// check id - unique in a tag
		if (fieldIndex[id] != 0)
			throw ErrorMessage(DIC_STRUCT__FIELD_ALREADY_EXISTS) << "Not unique field ID = " << id << " in Tag ID = " << objectID;
		fieldIndex[id] = field;
		field = field->getNext();
	}
	indexed = true;

	// sort fields
	firstField = 0;
	lastField = 0;
	for (int32_t id = 1; id <= fieldNumber; id++)
	{
		connectFieldToTag(fieldIndex[id]);
	}

	// Finalize fields: replace TagName to TagID in Links
	for (int32_t id = 1; id <= fieldNumber; id++)
	{
		field = fieldIndex[id];
		field->finalize();
		if (field->getType() == USDS_TAG)
		{
			if (((DictionaryTagLink*)field)->getTag()->getID() == objectID)
				throw ErrorMessage(DIC_STRUCT__RECURSION_ERROR, "Recursion links must be OPTIONAL.");
		}
	}
}
catch (ErrorMessage& msg)
{
	indexed = false;
	throw ErrorStack("DictionaryStruct::finalize") << msg;
}
catch (ErrorStack& err)
{
	indexed = false;
	err.addLevel("DictionaryStruct::finalize");
	throw;
}

void DictionaryStruct::initType()
{
	firstField = 0;
	lastField = 0;

	fieldMaxID = 0;
	fieldNumber = 0;
	indexed = false;

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