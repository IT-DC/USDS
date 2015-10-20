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
UsdsStruct* Body::addStructTag(const char* name) throw(...)
try
{
	DictionaryBaseType* dict_tag = currentDictionary->findTag(name);
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