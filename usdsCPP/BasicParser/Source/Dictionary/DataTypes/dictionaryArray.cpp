#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"
#include "dictionary\usdsDictionary.h"

using namespace usds;

DictionaryArray::DictionaryArray(Dictionary* dict) : DictionaryBaseType(dict)
{
	objectType = USDS_ARRAY;

};

void DictionaryArray::initType()
{
	element = 0;

};

DictionaryBaseType* DictionaryArray::setElementType(usdsTypes type_id) throw (...)
try
{
	if (element != 0)
		throw ErrorMessage(DIC_ARRAY__ALREADY_INITIALIZED, "Element's type is already initialized");
	if (typeSize(type_id) == 0 && type_id != USDS_VARINT && type_id != USDS_UNSIGNED_VARINT && type_id != USDS_STRING && type_id != USDS_TAG)
		throw ErrorMessage(DIC_ARRAY__ERROR_ELEMENT_TYPE, "Unsupported type for array's element. Use type TAG.");
	
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

usdsTypes DictionaryArray::getElementType() throw (...)
{
	if (element == 0)
		throw ErrorStack("DictionaryArray::getElementType") << ErrorMessage(DIC_ARRAY__NOT_INITIALIZED, "Array field not initialized");

	return element->getType();
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

void DictionaryArray::finalize() throw (...)
try
{
	if (element == 0)
		throw ErrorMessage(DIC_ARRAY__NOT_INITIALIZED, "Array element is NULL");
	element->finalize();
	
	if (getParent() == 0 && element->getType() == USDS_TAG)
	{
		if (((DictionaryTagLink*)element)->getTag()->getID() == objectID)
			throw ErrorMessage(DIC_ARRAY__RECURSION_ERROR, "Array's element 'TAG' can not be itself.");
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