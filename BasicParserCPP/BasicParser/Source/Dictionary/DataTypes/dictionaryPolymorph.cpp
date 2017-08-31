#include "dictionary/dataTypes/dictionaryPolymorph.h"
#include "dictionary/usdsDictionary.h"
#include "dictionary/dataTypes/dictionaryTagLink.h"

using namespace usds;

DictionaryPolymorph::DictionaryPolymorph(Dictionary* dict) : DictionaryBaseType(dict)
{
	buffIndexSize = 0;
	subTagIndex = 0;

};

DictionaryPolymorph::~DictionaryPolymorph()
{
	if (subTagIndex != 0)
		delete[] subTagIndex;
}

void DictionaryPolymorph::addTag(const char* tag_name, size_t name_size) throw (...)
try
{
	if (indexed)
		throw ErrorMessage(DIC_POLYMORPH__ALREADY_FINALIZED, "Can not add a tag: the polymorph is finalized already");

	DictionaryTagLink* tag = (DictionaryTagLink*)dictionary->addField(USDS_TAG, this, 1, "subTag", 6);
	tag->setTag(tag_name, name_size);
	if (firstSubTag == 0)
	{
		firstSubTag = tag;
		lastSubTag = tag;
	}
	else
	{
		lastSubTag->setNext(tag);
		lastSubTag = tag;
	}
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryPolymorph::addTag").addStringAndSize(tag_name, name_size) << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryPolymorph::addTag").addStringAndSize(tag_name, name_size);
	throw;
};

void DictionaryPolymorph::addTag(int32_t tag_id) throw (...)
try
{
	if (indexed)
		throw ErrorMessage(DIC_POLYMORPH__ALREADY_FINALIZED, "Can not add a tag: the polymorph is finalized already");

	DictionaryTagLink* tag = (DictionaryTagLink*)dictionary->addField(USDS_TAG, this, 1, "subTag", 6);
	tag->setTag(tag_id);
	if (firstSubTag == 0)
	{
		firstSubTag = tag;
		lastSubTag = tag;
	}
	else
	{
		lastSubTag->setNext(tag);
		lastSubTag = tag;
	}
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryPolymorph::addTag") << tag_id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryPolymorph::addTag") << tag_id;
	throw;
};

DictionaryStruct* DictionaryPolymorph::getSubStruct(int32_t tag_id) throw (...)
try
{
	if (!indexed)
		throw ErrorMessage(DIC_POLYMORPH__NOT_FINALIZED, "Polymorph is not finalized");

	if (tag_id > subTagMaxID || tag_id < 1)
		throw ErrorMessage(DIC_POLYMORPH__TAG_NOT_FOUND, "Tag with ID ") << tag_id << " is not found in dictionary";

	if (subTagIndex[tag_id] == 0)
		throw ErrorMessage(DIC_POLYMORPH__TAG_NOT_FOUND, "Tag with ID ") << tag_id << " is not a subtype of Polymorph '" << objectName << "'";

	return subTagIndex[tag_id];
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryPolymorph::getSubStruct") << tag_id << msg;
}

DictionaryTagLink* DictionaryPolymorph::getFirstTag() throw (...)
try
{
	if (!indexed)
		throw ErrorMessage(DIC_POLYMORPH__NOT_FINALIZED, "Polymorph is not finalized");

	return firstSubTag;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryPolymorph::getFirstTag") << msg;
}

void DictionaryPolymorph::getSubStructs(DictionaryStruct** index) throw (...)
{
	if (checkRecursion)
		throw ErrorMessage(DIC_POLYMORPH__RECURSION_IS_FORBIDDEN, "Recursion for Polymorph is forbidden");

	checkRecursion = true;

	if (!tagsFinalized)
	{
		DictionaryTagLink* tag = firstSubTag;
		while (tag != 0)
		{
			tag->finalize();
			tag = (DictionaryTagLink*)tag->getNext();
		}
		tagsFinalized = true;
	}

	DictionaryTagLink* tag = firstSubTag;
	while (tag != 0)
	{
		DictionaryBaseType* subtag = tag->getTag();
		usdsType subtag_type = subtag->getType();
		if (subtag_type == USDS_STRUCT)
			index[subtag->getID()] = (DictionaryStruct*)subtag;
		else if (subtag_type == USDS_POLYMORPH)
			((DictionaryPolymorph*)subtag)->getSubStructs(index);
		else
			throw ErrorMessage(DIC_POLYMORPH__UNSUPPORTED_SUBTAG, "Unsupported tag '") << UsdsTypes::typeName(subtag_type) << "' for Polymorph. Use STRUCT or POLYMORPH only.";

		tag = (DictionaryTagLink*)tag->getNext();
	}

	checkRecursion = false;
}

void DictionaryPolymorph::finalize() throw (...)
try
{
	if (indexed)
		throw ErrorMessage(DIC_POLYMORPH__ALREADY_FINALIZED, "Polymorph is finalized already");

	if (firstSubTag == 0)
		throw ErrorMessage(DIC_POLYMORPH__ZERO_NUMBERS_OF_SUBTAGS, "Number of subtags can not be 0");

	subTagMaxID = dictionary->getTagNumber();
	if (buffIndexSize < (subTagMaxID + 1))
	{
		if (subTagIndex != 0)
			delete[] subTagIndex;
		buffIndexSize = subTagMaxID + 1;
		subTagIndex = new DictionaryStruct*[buffIndexSize];
	}
	for (int32_t i = 0; i < buffIndexSize; i++)
		subTagIndex[i] = 0;

	if (!tagsFinalized)
	{
		DictionaryTagLink* tag = firstSubTag;
		while (tag != 0)
		{
			tag->finalize();
			tag = (DictionaryTagLink*)tag->getNext();
		}
		tagsFinalized = true;
	}

	DictionaryTagLink* tag = firstSubTag;
	while (tag != 0)
	{
		DictionaryBaseType* subtag = tag->getTag();
		usdsType subtag_type = subtag->getType();
		if (subtag_type == USDS_STRUCT)
			subTagIndex[subtag->getID()] = (DictionaryStruct*)subtag;
		else if (subtag_type == USDS_POLYMORPH)
		{
			checkRecursion = true;
			((DictionaryPolymorph*)subtag)->getSubStructs(subTagIndex);
			checkRecursion = false;
		}
		else
			throw ErrorMessage(DIC_POLYMORPH__UNSUPPORTED_SUBTAG, "Unsupported tag '") << UsdsTypes::typeName(subtag_type) << "' for Polymorph. Use STRUCT or POLYMORPH only.";

		tag = (DictionaryTagLink*)tag->getNext();
	}

	indexed = true;
	tagsFinalized = true;

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryPolymorph::finalize") << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryPolymorph::finalize");
	throw;
};

void DictionaryPolymorph::additionalInitType()
{
	firstSubTag = 0;
	lastSubTag = 0;
	subTagMaxID = 0;
	
	tagsFinalized = false;
	checkRecursion = false;

	indexed = false;

}

