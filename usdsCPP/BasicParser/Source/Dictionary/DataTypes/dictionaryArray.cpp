#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\usdsDictionary.h"

using namespace usds;

DictionaryArray::DictionaryArray(Dictionary* dict) : DictionaryBaseType(dict)
{
	objectType = USDS_ARRAY;

};

void DictionaryArray::clear()
{
	elementType = USDS_NO_TYPE;
	elementTagIDs.clear();
	elementTagNames.clear();
	elementEncode = USDS_NO_ENCODE;

	elementTagID = 0;
	elementTagName.clear();
	elementTagNeedID = false;
	elementTagNeedName = false;

};

void DictionaryArray::setElementType(usdsTypes type_id) throw (...)
{
	elementType = type_id;
};

void DictionaryArray::setElementAsTag(const char* tag_name, size_t name_size) throw (...)
{
	elementType = USDS_TAG;
	if (name_size == 0)
		elementTagName = tag_name;
	else
		elementTagName.assign(tag_name, name_size);
	elementTagID = -1;
	elementTagNeedID = true;
	elementTagNeedName = false;
};

void DictionaryArray::setElementAsTag(int tag_id) throw (...)
{
	elementType = USDS_TAG;
	elementTagName.clear();
	elementTagID = tag_id;
	elementTagNeedID = false;
	elementTagNeedName = true;
};

usdsTypes DictionaryArray::getElementType() throw (...)
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorStack("DictionaryArray::getElementType") << ErrorMessage(DIC_ARRAY__NOT_INITIALIZED, "Array field not initialized");

	return elementType;
};

int DictionaryArray::getElementTagID() throw (...)
try
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorMessage(DIC_ARRAY__NOT_INITIALIZED, "Array field isn't initialized");
	if (elementType != USDS_TAG)
		throw ErrorMessage(DIC_ARRAY__ELEMENT_NOT_TAG, "Array element isn't tag");
	if (elementTagID == 0 || elementTagNeedID)
		throw ErrorMessage(DIC_ARRAY__NOT_FINISHED, "Array isn't finished");

	return elementTagID;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryArray::getElementTagID") << msg;
};

DictionaryBaseType* DictionaryArray::getElementTag() throw (...)
try
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorMessage(DIC_ARRAY__NOT_INITIALIZED, "Array field isn't initialized");
	if (elementType != USDS_TAG)
		throw ErrorMessage(DIC_ARRAY__ELEMENT_NOT_TAG, "Array element isn't tag");
	if (elementTagID == 0 || elementTagNeedID)
		throw ErrorMessage(DIC_ARRAY__NOT_FINISHED, "Array isn't finished");

	return dictionary->getTag(elementTagID);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryArray::getElementTagID") << msg;
};

const char* DictionaryArray::getElementTagName() throw (...)
try
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorMessage(DIC_ARRAY__NOT_INITIALIZED, "Array field isn't initialized");
	if (elementType != USDS_TAG)
		throw ErrorMessage(DIC_ARRAY__ELEMENT_NOT_TAG, "Array element isn't tag");
	if (elementTagNeedName)
		throw ErrorMessage(DIC_ARRAY__NOT_FINISHED, "Array isn't finished");

	return elementTagName.c_str();
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryArray::getElementTagName") << msg;
};

void DictionaryArray::finalize() throw (...)
try
{
	switch (elementType)
	{
	case USDS_TAG:
		if (elementTagNeedID)
		{
			elementTagID = dictionary->findTagID(elementTagName.c_str());
			if (elementTagID == 0)
				throw ErrorMessage(DIC_ARRAY__TAG_NOT_FOUND) << "Tag with name '" << elementTagName << "' not found in dictionary ID=" << dictionary->getDictionaryID() << " v." << int(dictionary->getMajorVersion()) << "." << int(dictionary->getMinorVersion());
			elementTagNeedID = false;
		}
		else if (elementTagNeedName)
		{
			DictionaryBaseType* tag = dictionary->getTag(elementTagID);
			if (tag == 0)
				throw ErrorMessage(DIC_ARRAY__TAG_NOT_FOUND) << "Tag with ID '" << elementTagID << "' not found in dictionary ID=" << dictionary->getDictionaryID() << " v." << int(dictionary->getMajorVersion()) << "." << int(dictionary->getMinorVersion());
			elementTagName = tag->getName();
			elementTagNeedName = false;
		}
		break;
	default:
		break;
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