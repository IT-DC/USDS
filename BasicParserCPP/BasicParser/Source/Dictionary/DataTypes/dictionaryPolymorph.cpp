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
		firstSubTag = tag;
	else
	{
		tag->setNext(firstSubTag);
		firstSubTag = tag;
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
		firstSubTag = tag;
	else
	{
		tag->setNext(firstSubTag);
		firstSubTag = tag;
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

DictionaryStruct* DictionaryPolymorph::getTag(int32_t tag_id) throw (...)
{
	if (!indexed)
		throw ErrorMessage(DIC_POLYMORPH__NOT_FINALIZED, "Polymorph is not finalized");

	if (tag_id > subTagMaxID)
		throw ErrorMessage(DIC_POLYMORPH__TAG_NOT_FOUND, "Tag with ID ") << tag_id << " is not found in dictionary";

	if (subTagIndex[tag_id] == 0)
		throw ErrorMessage(DIC_POLYMORPH__TAG_NOT_FOUND, "Tag with ID ") << tag_id << " is not found in dictionary";

	return subTagIndex[tag_id];
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

	DictionaryTagLink* tag = firstSubTag;
	while (tag != 0)
	{
		tag->finalize();
		DictionaryBaseType* subtag = tag->getTag();
		usdsType subtag_type = subtag->getType();
		if (subtag_type == USDS_STRUCT)
			subTagIndex[subtag->getID()] = (DictionaryStruct*)subtag;
		else if (subtag_type == USDS_POLYMORPH)
			((DictionaryPolymorph*)subtag)->getTags(subTagIndex);
		else
			throw ErrorMessage(DIC_POLYMORPH__UNSUPPORTED_SUBTAG, "Number of subtags can not be 0");

		tag = (DictionaryTagLink*)tag->getNext();
	}

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
	subTagMaxID = 0;
	
	indexed = false;

}

