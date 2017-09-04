#include "dictionary\dataTypes\dictionaryTagLink.h"
#include "dictionary\usdsDictionary.h"

using namespace usds;

DictionaryTagLink::DictionaryTagLink(Dictionary* dict) : DictionaryBaseType(dict)
{

}

void DictionaryTagLink::additionalInitType()
{
	isRoot = false;
	
	tag = 0;
	tagID = -1;
	tagName.clear();

};

void DictionaryTagLink::finalize() throw (...)
try
{
	if (tag != 0)
		throw ErrorMessage(DIC_TAG__ALREADY_FINALIZED, "Tag is finalized already");

	if (!tagName.empty())
	{
		tag = dictionary->findTag(tagName.c_str());
		if (tag == 0)
			throw ErrorMessage(DIC_TAG_LINK__TAG_NOT_FOUND) << "Tag with name '" << tagName << "' not found in dictionary ID=" << dictionary->getDictionaryID() << " v." << int(dictionary->getMajorVersion()) << "." << int(dictionary->getMinorVersion());
	}
	else if (tagID != -1)
	{
		tag = dictionary->getTag(tagID);
	}
	else
		throw ErrorMessage(DIC_TAG_LINK__NOT_INITIALIZED, "Tag's link isn't initialized");

	if (tag->getType() == USDS_TAG)
		throw ErrorMessage(DIC_TAG_LINK__TAG_OF_TAG, "Tag of Tag is not supported");
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryTagLink::finalize") << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryTagLink::finalize");
	throw;
};

void DictionaryTagLink::setTag(const char* tag_name, size_t name_size) throw (...)
try
{
	if (tag_name == 0)
		throw ErrorMessage(DIC_TAG_LINK__ERROR_ELEMENT_NAME, "Tag name for the element can not be NULL");

	if (name_size == 0)
		tagName = tag_name;
	else
		tagName.assign(tag_name, name_size);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryTagLink::setTag") << tag_name << name_size << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryTagLink::setTag") << tag_name << name_size;
	throw;
};

void DictionaryTagLink::setTag(int32_t tag_id) throw (...)
try
{
	if (tag_id <= 0)
		throw ErrorMessage(DIC_TAG_LINK__ERROR_ELEMENT_ID, "Tag ID for the element must be > 1. Current value = ") << tag_id;

	tagID = tag_id;

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryTagLink::setTag") << tag_id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryTagLink::setTag") << tag_id;
	throw;
};

DictionaryBaseType* DictionaryTagLink::getTag() throw (...)
try
{
	if (tag == 0)
		throw ErrorMessage(DIC_TAG_LINK__NOT_INITIALIZED, "Tag's link isn't initialized");

	return tag;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryTagLink::getTag") << msg;
}
