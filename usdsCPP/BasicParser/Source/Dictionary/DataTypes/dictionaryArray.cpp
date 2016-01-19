#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\usdsDictionary.h"

using namespace usds;

DictionaryArray::DictionaryArray(Dictionary* dict) : DictionaryBaseType(dict)
{
	objectType = USDS_ARRAY;

};

void DictionaryArray::initType()
{
	elementType = USDS_NO_TYPE;
	element = 0;

};

DictionaryBaseType* DictionaryArray::setElementType(usdsTypes type_id) throw (...)
try
{
	if (elementType != USDS_NO_TYPE)
		throw ErrorMessage(DIC_ARRAY__ALREADY_INITIALIZED, "Element's type is already initialized");
	if (type_id == USDS_TAG)
		throw ErrorMessage(DIC_ARRAY__ERROR_ELEMENT_TYPE, "Use functions setElementAsTag for type TAG");
	if (typeSize(type_id) == 0 && type_id != USDS_VARINT && type_id != USDS_UNSIGNED_VARINT && type_id != USDS_STRING)
		throw ErrorMessage(DIC_ARRAY__ERROR_ELEMENT_TYPE, "Unsupported type for array's element. Use type TAG.");
	
	elementType = type_id;
	element = dictionary->addField(type_id, this, 1, "_array_element", 0);
	return element;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryArray::setElementType") << type_id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryArray::setElementType") << type_id;
	throw;
};

void DictionaryArray::setElementAsTag(const char* tag_name, size_t name_size) throw (...)
try
{
	if (elementType != USDS_NO_TYPE)
		throw ErrorMessage(DIC_ARRAY__ALREADY_INITIALIZED, "Element's type is already initialized");
	if (tag_name == 0)
		throw ErrorMessage(DIC_ARRAY__ERROR_ELEMENT_NAME, "Tag name for the element can not be NULL");
	
	elementType = USDS_TAG;
	element = 0;
	if (name_size == 0)
		elementTagName = tag_name;
	else
		elementTagName.assign(tag_name, name_size);
	elementTagID = -1;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryArray::setElementAsTag") << tag_name << name_size << msg;
};

void DictionaryArray::setElementAsTag(int tag_id) throw (...)
try
{
	if (elementType != USDS_NO_TYPE)
		throw ErrorMessage(DIC_ARRAY__ALREADY_INITIALIZED, "Element's type is already initialized");
	if (tag_id <= 0)
		throw ErrorMessage(DIC_ARRAY__ERROR_ELEMENT_ID, "Tag ID for the element must be > 1. Current value = ") << tag_id;

	elementType = USDS_TAG;
	element = 0;

	elementTagName.clear();
	elementTagID = tag_id;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryArray::setElementAsTag") << tag_id << msg;
};

usdsTypes DictionaryArray::getElementType() throw (...)
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorStack("DictionaryArray::getElementType") << ErrorMessage(DIC_ARRAY__NOT_INITIALIZED, "Array field not initialized");

	return elementType;
};

DictionaryBaseType* DictionaryArray::getElement() throw (...)
try
{
	if (element == 0)
		throw ErrorMessage(DIC_ARRAY__NOT_INITIALIZED, "Array field isn't initialized");

	return element;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryArray::getElementTagID") << msg;
};

int DictionaryArray::getElementTagID() throw (...)
try
{
	if (element == 0)
		throw ErrorMessage(DIC_ARRAY__NOT_INITIALIZED, "Array field isn't initialized");
	if (elementType != USDS_TAG)
		throw ErrorMessage(DIC_ARRAY__ELEMENT_NOT_TAG, "Array element isn't tag");

	return element->getID();
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryArray::getElementTagID") << msg;
};


const char* DictionaryArray::getElementTagName() throw (...)
try
{
	if (element == 0)
		throw ErrorMessage(DIC_ARRAY__NOT_INITIALIZED, "Array field isn't initialized");
	if (elementType != USDS_TAG)
		throw ErrorMessage(DIC_ARRAY__ELEMENT_NOT_TAG, "Array element isn't tag");

	return element->getName();
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryArray::getElementTagName") << msg;
};

void DictionaryArray::finalize() throw (...)
try
{
	if (elementType == USDS_TAG)
	{
		if (elementTagID == -1)
		{
			element = dictionary->findTag(elementTagName.c_str());
			if (element == 0)
				throw ErrorMessage(DIC_ARRAY__TAG_NOT_FOUND) << "Tag with name '" << elementTagName << "' not found in dictionary ID=" << dictionary->getDictionaryID() << " v." << int(dictionary->getMajorVersion()) << "." << int(dictionary->getMinorVersion());
		}
		else
		{
			element = dictionary->getTag(elementTagID);
		}
		if (element->getID() == objectID)
		{
			element = 0;
			throw ErrorMessage(DIC_ARRAY__RECURSION_ERROR, "Array's element 'TAG' can not be itself.");
		}
	}
	else
	{
		if (element == 0)
			throw ErrorMessage(DIC_ARRAY__NOT_INITIALIZED, "Array element is NULL");
	}

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryArray::finalize") << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryArray::finalize");
	throw;
};