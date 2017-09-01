#include "body/dataTypes/usdsPolymorph.h"

#include "dictionary/dataTypes/dictionaryPolymorph.h"

#include "body\usdsBody.h"

using namespace usds;

UsdsPolymorph::UsdsPolymorph(Body* parent_body) : UsdsBaseType(parent_body)
{
	

};

UsdsPolymorph::~UsdsPolymorph()
{
	
};

UsdsStruct* UsdsPolymorph::setSubtagId(int32_t tag_id) throw(...)
try
{
	if (subObject != 0)
		subObject->remove();

	DictionaryStruct* dic_sub_struct = ((DictionaryPolymorph*)parentDictionaryObject)->getSubStruct(tag_id);
	subObject = (UsdsStruct*)parentBody->addField((DictionaryBaseType*)dic_sub_struct, this);

	return subObject;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsPolymorph::setSubtagId") << tag_id;
	throw;
};

UsdsStruct* UsdsPolymorph::getSubtag() throw(...)
try
{
	if (subObject == 0)
		throw ErrorMessage(BODY_POLYMORPH__SUBTAG_IS_NOT_INITIALIZED, "Subtag is not initialized");

	return subObject;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsPolymorph::getSubtag") << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsPolymorph::getSubtag");
	throw;
};

int32_t UsdsPolymorph::getSubtagId() throw(...)
try
{
	if (subObject == 0)
		throw ErrorMessage(BODY_POLYMORPH__SUBTAG_IS_NOT_INITIALIZED, "Subtag is not initialized");

	return subObject->getID();
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsPolymorph::getSubtagId") << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsPolymorph::getSubtagId");
	throw;
};

void UsdsPolymorph::additionalInitObject()
{
	subObject = 0;
}


