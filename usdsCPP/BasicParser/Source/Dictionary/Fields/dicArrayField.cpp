#include "dictionary\fields\dicArrayField.h"
#include "dictionary\usdsDictionary.h"

using namespace usds;

DicArrayField::DicArrayField()
{


};

void DicArrayField::clear()
{
	elementType = USDS_NO_TYPE;
	elementTagIDs.clear();
	elementTagNames.clear();
	elementDefaultEncode = USDS_NO_ENCODE;

	elementTagID = 0;
	elementTagName.clear();
	elementTagNeedID = false;
	elementTagNeedName = false;

};

void DicArrayField::setElementAsTag(const char* tag_name, size_t name_size) throw (...)
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

void DicArrayField::setElementAsTag(int tag_id) throw (...)
{
	elementType = USDS_TAG;
	elementTagName.clear();
	elementTagID = tag_id;
	elementTagNeedID = false;
	elementTagNeedName = true;
};

usdsTypes DicArrayField::getElementType() throw (...)
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_INITIALIZED, L"Array field not initialized", L"DicArrayField::getElementType");

	return elementType;
};

int DicArrayField::getElementTagID() throw (...)
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_INITIALIZED, L"Array field isn't initialized", L"DicArrayField::getElementTagID");
	if (elementType != USDS_TAG)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_ELEMENT_NOT_TAG, L"Array element isn't tag", L"DicArrayField::getElementTagID");
	if (elementTagID == 0 || elementTagNeedID)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_FINISHED, L"Array isn't finished", L"DicArrayField::getElementTagID");

	return elementTagID;
};

const char* DicArrayField::getElementTagName() throw (...)
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_INITIALIZED, L"Array field isn't initialized", L"DicArrayField::getElementTagName");
	if (elementType != USDS_TAG)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_ELEMENT_NOT_TAG, L"Array element isn't tag", L"DicArrayField::getElementTagName");
	if (elementTagNeedName)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_FINISHED, L"Array isn't finished", L"DicArrayField::getElementTagName");

	return elementTagName.c_str();
};

void DicArrayField::finalizeField() throw (...)
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
			elementTagNeedID = true;
		}


		break;
	default:
		break;
	}



};