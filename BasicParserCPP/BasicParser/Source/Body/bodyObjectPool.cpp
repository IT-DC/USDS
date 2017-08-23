#include "body\bodyObjectPool.h"

#include "dictionary\dictionaryBaseType.h"
#include "body\dataTypes\usdsArray.h"
#include "body\dataTypes\usdsBoolean.h"
#include "body\dataTypes\usdsByte.h"
#include "body\dataTypes\usdsUByte.h"
#include "body\dataTypes\usdsShort.h"
#include "body\dataTypes\usdsUShort.h"
#include "body\dataTypes\usdsInt.h"
#include "body\dataTypes\usdsUInt.h"
#include "body\dataTypes\usdsLong.h"
#include "body\dataTypes\usdsULong.h"
#include "body\dataTypes\usdsFloat.h"
#include "body\dataTypes\usdsDouble.h"
#include "body\dataTypes\usdsString.h"
#include "body\dataTypes\usdsStruct.h"
#include "body\dataTypes\usdsVarint.h"
#include "body\dataTypes\usdsUVarint.h"

using namespace usds;


BodyObjectPool::BodyObjectPool(Body* parent_body) 
{
	pools[USDS_TAG] = 0;
	pools[USDS_BOOLEAN] = new TemplateObjectPool<UsdsBoolean, Body>(parent_body);
	pools[USDS_BYTE] = new TemplateObjectPool<UsdsByte, Body>(parent_body);
	pools[USDS_UBYTE] = new TemplateObjectPool<UsdsUByte, Body>(parent_body);
	pools[USDS_SHORT] = new TemplateObjectPool<UsdsShort, Body>(parent_body);
	pools[USDS_USHORT] = new TemplateObjectPool<UsdsUShort, Body>(parent_body);
	pools[USDS_INT] = new TemplateObjectPool<UsdsInt, Body>(parent_body);
	pools[USDS_UINT] = new TemplateObjectPool<UsdsUInt, Body>(parent_body);
	pools[USDS_LONG] = new TemplateObjectPool<UsdsLong, Body>(parent_body);
	pools[USDS_ULONG] = new TemplateObjectPool<UsdsULong, Body>(parent_body);
	pools[USDS_INT128] = 0;
	pools[USDS_UINT128] = 0;
	pools[USDS_FLOAT] = new TemplateObjectPool<UsdsFloat, Body>(parent_body);
	pools[USDS_DOUBLE] = new TemplateObjectPool<UsdsDouble, Body>(parent_body);
	pools[USDS_VARINT] = new TemplateObjectPool<UsdsVarint, Body>(parent_body);
	pools[USDS_UVARINT] = new TemplateObjectPool<UsdsUVarint, Body>(parent_body);
	pools[USDS_STRING] = new TemplateObjectPool<UsdsString, Body>(parent_body);
	pools[USDS_ARRAY] = new TemplateObjectPool<UsdsArray, Body>(parent_body);
	pools[USDS_STRUCT] = new TemplateObjectPool<UsdsStruct, Body>(parent_body);
	pools[USDS_ENUM] = 0;
	pools[USDS_POLYMORPH] = 0;
}

BodyObjectPool::~BodyObjectPool()
{
	for (int32_t i = 0; i < USDS_LAST_TYPE; i++)
	{
		if (pools[i] != 0)
			delete(pools[i]);
	}
}

UsdsBaseType* BodyObjectPool::addObject(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	if (dict_parent==0)
		throw ErrorMessage(BODY_OBJECT_POOL__NULL_DICTIONARY_TAG, "Dictionary parent tag can not be NULL");
	
	usdsType object_type = dict_parent->getType();

	// TODO add TAG
	// TODO: remove it when all type is ready
	if (pools[object_type] == 0)
		throw ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE) << "Unsupported type " << UsdsTypes::typeName(object_type);


	UsdsBaseType*object = (UsdsBaseType*)(pools[object_type])->addObject();
	try
	{
		object->initObject(dict_parent, body_parent);
	}
	catch (ErrorStack)
	{
		object->remove();
		throw;
	}

	return object;
}
catch (ErrorMessage&msg)
{
	throw ErrorStack("BodyObjectPool::addObject") << (void*)dict_parent << (void*)body_parent << msg;

}
catch (ErrorStack& err)
{
	err.addLevel("BodyObjectPool::addObject") << (void*)dict_parent << (void*)body_parent;
	throw;
};


//===============================================================================================================================

void BodyObjectPool::clear()
{
	for (int32_t i = 0; i < USDS_LAST_TYPE; i++)
	{
		if (pools[i] != 0)
			pools[i]->clearPool();
	}

};
