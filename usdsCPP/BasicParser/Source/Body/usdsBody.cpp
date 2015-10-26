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

Body::Body()
{


};

Body::~Body()
{


};

//============================================================================================
// Body construction

UsdsBaseType* Body::addTag(int id) throw(...)
try
{
	DictionaryBaseType* dict_tag = currentDictionary->getTag(id);
	if (dict_tag==0)
	{
		std::stringstream msg;
		msg << L"Tag id=" << id << " is not found";
		throw ErrorMessage(BODY_ERROR_TAG_ROOT, &msg);
	};
	if (!dict_tag->getRootStatus())
	{
		std::stringstream msg;
		msg << L"Tag id=" << id << " is not ROOT";
		throw ErrorMessage(BODY_ERROR_TAG_ROOT, &msg);
	};

	UsdsBaseType* tag = objectPool.addObject(dict_tag, 0);
	connectTagToBody(tag);

	return tag;
}
catch (ErrorMessage & msg)
{
	msg.addPath(L"Body::addTag(int)");
	throw msg;
};

UsdsStruct* Body::addStructTag(const char* name) throw(...)
try
{
	DictionaryBaseType* dict_tag = currentDictionary->findTag(name);
	if (dict_tag == 0)
	{
		std::stringstream msg;
		msg << L"Tag name '" << name << "' is not found";
		throw ErrorMessage(BODY_ERROR_TAG_ROOT, &msg);
	};
	if (dict_tag->getType() != USDS_STRUCT)
	{
		std::stringstream msg;
		msg << L"Type of the tag '" << name << "' is not USDS_STRUCT (" << dict_tag->getTypeName() << ")";
		throw ErrorMessage(BODY_ERROR_TAG_TYPE, &msg);
	};
	if (!dict_tag->getRootStatus())
	{
		std::stringstream msg;
		msg << L"Tag '" << name << "' is not ROOT";
		throw ErrorMessage(BODY_ERROR_TAG_ROOT, &msg);
	};
	
	UsdsStruct* tag = (UsdsStruct*)(objectPool.addObject(dict_tag, 0));
	connectTagToBody(tag);

	return tag;
}
catch (ErrorMessage & msg)
{
	msg.addPath(L"Body::addStructTag(const char*)");
	throw msg;
};

//============================================================================================

UsdsBaseType* Body::getFirstTag() throw(...)
{
	return firstTag;

};

UsdsBaseType* Body::getFirstTag(const char* name) throw(...)
{
	int tag_id = currentDictionary->findTagID(name);
	UsdsBaseType* tag = firstTag;
	while (tag != 0)
	{
		if (tag->getID() == tag_id)
			return tag;
		tag = tag->getNext();
	}

	std::stringstream msg;
	msg << L"Tag '" << name << "' not found in ROOT level";
	throw ErrorMessage(BODY_TAG_NOT_FOUND, &msg);

	return 0;
};

UsdsStruct* Body::getFirstStructTag(const char* name) throw(...)
{
	int tag_id = currentDictionary->findTagID(name);
	UsdsBaseType* tag = firstTag;
	while (tag != 0)
	{
		if (tag->getID() == tag_id)
		{
			if (tag->getType() != USDS_STRUCT)
			{
				std::stringstream msg;
				msg << L"Tag '" << name << "' has type " << tag->getTypeName();
				throw ErrorMessage(BODY_ERROR_TAG_TYPE, &msg);
			}
			return (UsdsStruct*)tag;
		}
		tag = tag->getNext();
	}

	std::stringstream msg;
	msg << L"Tag '" << name << "' not found in ROOT level";
	throw ErrorMessage(BODY_TAG_NOT_FOUND, &msg);

	return 0;
};


//============================================================================================
void Body::clearBody()
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