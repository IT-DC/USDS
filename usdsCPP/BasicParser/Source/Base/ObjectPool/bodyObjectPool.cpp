#include "base\objectPool\bodyObjectPool.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"
#include "body\dataTypes\usdsArray.h"
#include "body\dataTypes\usdsBoolean.h"
#include "body\dataTypes\usdsDouble.h"
#include "body\dataTypes\usdsInt.h"
#include "body\dataTypes\usdsLong.h"
#include "body\dataTypes\usdsString.h"
#include "body\dataTypes\usdsStruct.h"
#include "body\dataTypes\usdsUVarint.h"

using namespace usds;


BodyObjectPool::BodyObjectPool() : 
	booleanObjects(this),
	intObjects(this),
	longObjects(this),
	doubleObjects(this),
	uVarintObjects(this),
	arrayObjects(this),
	stringObjects(this),
	structObjects(this)
{
	poolIndex[USDS_NO_TYPE] = 0;
	poolIndex[USDS_BOOLEAN] = &BodyObjectPool::addBoolean;
	poolIndex[USDS_BYTE] = 0;
	poolIndex[USDS_UNSIGNED_BYTE] = 0;
	poolIndex[USDS_SHORT] = 0;
	poolIndex[USDS_UNSIGNED_SHORT] = 0;
	poolIndex[USDS_BIGENDIAN_SHORT] = 0;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	poolIndex[USDS_INT] = &BodyObjectPool::addInt;
	poolIndex[USDS_UNSIGNED_INT] = 0;
	poolIndex[USDS_BIGENDIAN_INT] = 0;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	poolIndex[USDS_LONG] = &BodyObjectPool::addLong;
	poolIndex[USDS_UNSIGNED_LONG] = 0;
	poolIndex[USDS_BIGENDIAN_LONG] = 0;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	poolIndex[USDS_INT128] = 0;
	poolIndex[USDS_UNSIGNED_INT128] = 0;
	poolIndex[USDS_BIGENDIAN_INT128] = 0;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	poolIndex[USDS_FLOAT] = 0;
	poolIndex[USDS_BIGENDIAN_FLOAT] = 0;
	poolIndex[USDS_DOUBLE] = &BodyObjectPool::addDouble;
	poolIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	poolIndex[USDS_VARINT] = 0;
	poolIndex[USDS_UNSIGNED_VARINT] = &BodyObjectPool::addUVarint;
	poolIndex[USDS_STRUCT] = &BodyObjectPool::addStruct;
	poolIndex[USDS_ARRAY] = &BodyObjectPool::addArray;
	poolIndex[USDS_STRING] = &BodyObjectPool::addString;
	poolIndex[USDS_LIST] = 0;
	poolIndex[USDS_MAP] = 0;
	poolIndex[USDS_POLYMORPH] = 0;
	poolIndex[USDS_TAG] = 0;



}

BodyObjectPool::~BodyObjectPool()
{

}

UsdsBaseType* BodyObjectPool::addObject(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent)
{
	return (this->*(poolIndex[dict_parent->getType()]))(dict_parent, body_parent);
	
};

//===============================================================================================================================

UsdsBaseType* BodyObjectPool::addBoolean(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent)
{
	UsdsBoolean* object = booleanObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;

};

UsdsBaseType* BodyObjectPool::addInt(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent)
{
	UsdsInt* object = intObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;

};

UsdsBaseType* BodyObjectPool::addLong(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent)
{
	UsdsLong* object = longObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;

};

UsdsBaseType* BodyObjectPool::addDouble(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent)
{
	UsdsDouble* object = doubleObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;

};

UsdsBaseType* BodyObjectPool::addUVarint(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent)
{
	UsdsUVarint* object = uVarintObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;

};

UsdsBaseType* BodyObjectPool::addArray(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent)
{
	UsdsArray* object = arrayObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;

};

UsdsBaseType* BodyObjectPool::addString(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent)
{
	UsdsString* object = stringObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;

};

UsdsBaseType* BodyObjectPool::addStruct(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent)
{
	UsdsStruct* object = structObjects.addObject();
	object->init(dict_parent, body_parent);


	return object;

};

//===============================================================================================================================

void BodyObjectPool::clear()
{
	booleanObjects.clearPool();
	intObjects.clearPool();
	longObjects.clearPool();
	doubleObjects.clearPool();
	arrayObjects.clearPool();
	stringObjects.clearPool();
	structObjects.clearPool();

};
