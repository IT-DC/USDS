#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\usdsDictionary.h"

using namespace usds;

DictionaryArray::DictionaryArray(DictionaryObjectPool* parent) : DictionaryBaseType(parent)
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
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_INITIALIZED, L"Array field not initialized", L"DicArrayField::getElementType");

	return elementType;
};

int DictionaryArray::getElementTagID() throw (...)
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_INITIALIZED, L"Array field isn't initialized", L"DicArrayField::getElementTagID");
	if (elementType != USDS_TAG)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_ELEMENT_NOT_TAG, L"Array element isn't tag", L"DicArrayField::getElementTagID");
	if (elementTagID == 0 || elementTagNeedID)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_FINISHED, L"Array isn't finished", L"DicArrayField::getElementTagID");

	return elementTagID;
};

DictionaryBaseType* DictionaryArray::getElementTag() throw (...)
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_INITIALIZED, L"Array field isn't initialized", L"DictionaryArray::getElementTag");
	if (elementType != USDS_TAG)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_ELEMENT_NOT_TAG, L"Array element isn't tag", L"DictionaryArray::getElementTag");
	if (elementTagID == 0 || elementTagNeedID)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_FINISHED, L"Array isn't finished", L"DictionaryArray::getElementTag");

	return dictionary->getTag(elementTagID);
};

const char* DictionaryArray::getElementTagName() throw (...)
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_INITIALIZED, L"Array field isn't initialized", L"DicArrayField::getElementTagName");
	if (elementType != USDS_TAG)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_ELEMENT_NOT_TAG, L"Array element isn't tag", L"DicArrayField::getElementTagName");
	if (elementTagNeedName)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_FINISHED, L"Array isn't finished", L"DicArrayField::getElementTagName");

	return elementTagName.c_str();
};

void DictionaryArray::finalize() throw (...)
{
	switch (elementType)
	{
	case USDS_TAG:
		if (elementTagNeedID)
		{
			elementTagID = dictionary->findTagID(elementTagName.c_str());
			if (elementTagID == 0)
			{
				std::stringstream msg;
				msg << "Tag with name '" << elementTagName << "' not found in dictionary ID=" << dictionary->getDictionaryID() << " v." << int(dictionary->getMajorVersion()) << "." << int(dictionary->getMinorVersion());
				throw ErrorMessage(DIC_STRUCT_FIELD_TAG_NOT_FOUND, &msg, L"DicArrayField::finalizeField");
			}
			elementTagNeedID = false;
		}
		else if (elementTagNeedName)
		{
			DictionaryBaseType* tag = dictionary->getTag(elementTagID);
			if (tag == 0)
			{
				std::stringstream msg;
				msg << "Tag with ID '" << elementTagID << "' not found in dictionary ID=" << dictionary->getDictionaryID() << " v." << int(dictionary->getMajorVersion()) << "." << int(dictionary->getMinorVersion());
				throw ErrorMessage(DIC_STRUCT_FIELD_TAG_NOT_FOUND, &msg, L"DicArrayField::finalizeField");
			}
			elementTagName = tag->getName();
			elementTagNeedName = false;
		}

		break;
	default:
		break;
	}



};