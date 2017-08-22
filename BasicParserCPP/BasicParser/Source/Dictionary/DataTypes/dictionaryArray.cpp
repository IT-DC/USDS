#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"
#include "dictionary\usdsDictionary.h"

using namespace usds;

DictionaryArray::DictionaryArray(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryArray::additionalInitType()
{
	element = 0;

};

DictionaryBaseType* DictionaryArray::setElementType(usdsType type_id) throw (...)
try
{
	if (element != 0)
		throw ErrorMessage(DIC_ARRAY__ALREADY_INITIALIZED, "Element's type is already initialized");
	if (type_id < usds::USDS_TAG || type_id >= usds::USDS_LAST_TYPE)
		throw ErrorMessage(DIC_ARRAY__ERROR_ELEMENT_TYPE, "Unsupported type for array's element: '") << type_id << "'. Use [USDS_TAG, USDS_FUNCTION].";
	
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

usdsType DictionaryArray::getElementType() throw (...)
{
	if (element == 0)
		throw ErrorStack("DictionaryArray::getElementType") << ErrorMessage(DIC_ARRAY__NOT_INITIALIZED, "Dictionary Array field not initialized");

	return element->getType();
};

DictionaryBaseType* DictionaryArray::getElement() throw (...)
try
{
	if (element == 0)
		throw ErrorMessage(DIC_ARRAY__NOT_INITIALIZED, "Dictionary Array field isn't initialized");

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