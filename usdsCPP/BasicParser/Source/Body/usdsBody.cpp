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
	if (!dict_tag->getRootStatus())
		throw ErrorMessage(BODY__ERROR_TAG_ROOT) << "Tag id=" << id << " is not ROOT";

	UsdsBaseType* tag = objectPool.addObject(dict_tag, 0);
	connectTagToBody(tag);

	return tag;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("Body::addTag") << id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("Body::addTag") << id;
	throw;
};

UsdsBaseType* Body::addTag(DictionaryBaseType* dict_tag) throw(...)
try
{
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


//--------------------------------------------------------------------------------------------
UsdsStruct* Body::addStructTag(const char* name) throw(...)
try
{
	DictionaryBaseType* dict_tag = currentDictionary->findTag(name);
	if (dict_tag == 0)
		throw ErrorMessage(BODY__TAG_NOT_FOUND) << "Tag name '" << name << "' is not found";
	if (dict_tag->getType() != USDS_STRUCT)
		throw ErrorMessage(BODY__ERROR_TAG_TYPE) << "Type of the tag '" << name << "' is not USDS_STRUCT (" << dict_tag->getTypeName() << ")";
	if (!dict_tag->getRootStatus())
		throw ErrorMessage(BODY__ERROR_TAG_ROOT) << "Tag '" << name << "' is not ROOT";
	
	UsdsStruct* tag = (UsdsStruct*)(objectPool.addObject(dict_tag, 0));
	connectTagToBody(tag);

	return tag;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("Body::addStructTag") << name << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("Body::addStructTag") << name;
	throw;
};

UsdsStruct* Body::addStructTag(int id) throw(...)
try
{
	DictionaryBaseType* dict_tag = currentDictionary->getTag(id);
	if (dict_tag->getType() != USDS_STRUCT)
		throw ErrorMessage(BODY__ERROR_TAG_TYPE) << "Type of the tag with id=" << id << " is not USDS_STRUCT (" << dict_tag->getTypeName() << ")";
	if (!dict_tag->getRootStatus())
		throw ErrorMessage(BODY__ERROR_TAG_ROOT) << "Tag with id=" << id << " is not ROOT";

	UsdsStruct* tag = (UsdsStruct*)(objectPool.addObject(dict_tag, 0));
	connectTagToBody(tag);

	return tag;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("Body::addStructTag") << id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("Body::addStructTag") << id;
	throw;
};


//============================================================================================

UsdsBaseType* Body::getFirstTag() throw(...)
{
	return firstTag;

};

UsdsBaseType* Body::getFirstTag(const char* name) throw(...)
try
{
	int tag_id = currentDictionary->findTagID(name);
	if (tag_id == 0)
		throw ErrorMessage(BODY__TAG_NOT_FOUND) << "Tag name '" << name << "' is not found";
	UsdsBaseType* tag = firstTag;
	while (tag != 0)
	{
		if (tag->getID() == tag_id)
			return tag;
		tag = tag->getNext();
	}

	throw ErrorMessage(BODY__TAG_NOT_FOUND) << "Tag '" << name << "' not found in ROOT level";

	return 0;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("Body::getFirstTag") << name << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("Body::getFirstTag") << name;
	throw;
};

UsdsStruct* Body::getFirstStructTag(const char* name) throw(...)
try
{
	int tag_id = currentDictionary->findTagID(name);
	UsdsBaseType* tag = firstTag;
	while (tag != 0)
	{
		if (tag->getID() == tag_id)
		{
			if (tag->getType() != USDS_STRUCT)
				throw ErrorMessage(BODY__ERROR_TAG_TYPE) << "Tag '" << name << "' has type " << tag->getTypeName();;
			return (UsdsStruct*)tag;
		}
		tag = tag->getNext();
	}

	throw ErrorMessage(BODY__TAG_NOT_FOUND) << "Tag '" << name << "' not found in ROOT level";

	return 0;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("Body::getFirstStructTag") << name << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("Body::getFirstStructTag") << name;
	throw;
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