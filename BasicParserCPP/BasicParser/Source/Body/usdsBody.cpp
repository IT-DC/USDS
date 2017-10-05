#include "body\usdsBody.h"

#include "dictionary\usdsDictionary.h"

#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryString.h"
#include "dictionary\dataTypes\dictionaryUVarint.h"
#include "dictionary\dataTypes\dictionaryStruct.h"

using namespace usds;

Body::Body() : objectPool(this)
{
	firstTag = 0;
	lastTag = 0;
};

Body::~Body()
{


};

//============================================================================================
// Body construction

UsdsBaseType* Body::addTag(DictionaryBaseType* dict_tag) throw(...)
try
{
	if (dict_tag == 0)
		throw ErrorMessage(BODY__NULL_DICTIONARY_TAG, "Tag can not be NULL");

	if (dict_tag->getRootStatus() == false )
		throw ErrorMessage(BODY__NOT_ROOT_TAG, "Tag '") << dict_tag->getName() << "' is not root";

	UsdsBaseType* tag = objectPool.addObject(dict_tag, 0);
	connectTagToBody(tag);

	return tag;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("Body::addTag") << (void*)dict_tag << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("Body::addTag") << (void*)dict_tag;
	throw;
};

UsdsBaseType* Body::addField(DictionaryBaseType* dict_field, UsdsBaseType* parent_tag) throw(...)
try
{
	if (parent_tag == 0)
		throw ErrorMessage(BODY__NULL_PARENT_TAG, "Parent tag can not be NULL");

	return objectPool.addObject(dict_field, parent_tag);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("Body::addField") << (void*)dict_field << (void*)parent_tag << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("Body::addField") << (void*)dict_field << (void*)parent_tag;
	throw;
};


//============================================================================================

UsdsBaseType* Body::getFirstTag() throw(...)
{
	return firstTag;

};

UsdsBaseType* Body::getFirstTag(int32_t tag_id) throw(...)
try
{
	UsdsBaseType* tag = firstTag;
	while (tag != 0)
	{
		if (tag->getID() == tag_id)
			return tag;
		tag = tag->getNext();
	}

	throw ErrorMessage(BODY__TAG_NOT_FOUND) << "Tag id=" << tag_id << " not found in ROOT level";

	return 0;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("Body::getFirstTag") << tag_id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("Body::getFirstTag") << tag_id;
	throw;
};

//============================================================================================
void Body::clear()
{
	objectPool.clear();
	
	firstTag = 0;
	lastTag = 0;

};

//====================================================================================================================
// private

void Body::connectTagToBody(UsdsBaseType* tag)
{
	if (firstTag == 0)
		firstTag = tag;
	tag->setPrevious(lastTag);
	tag->setNext(0);
	if (lastTag != 0)
		lastTag->setNext(tag);
	lastTag = tag;
};