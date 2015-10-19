#include "base\objectPool\bodyObjectPool.h"

#include "body\dataTypes\usdsArray.h"
#include "body\dataTypes\usdsBoolean.h"
#include "body\dataTypes\usdsDouble.h"
#include "body\dataTypes\usdsInt.h"
#include "body\dataTypes\usdsLong.h"
#include "body\dataTypes\usdsString.h"
#include "body\dataTypes\usdsStruct.h"
#include "body\dataTypes\usdsUVarint.h"

using namespace usds;


BodyObjectPool::BodyObjectPool()
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

UsdsBaseType* BodyObjectPool::addObject(usdsTypes object_type, UsdsBaseType* parent, int id)
{
	return (this->*(poolIndex[object_type]))(parent, id);
	
};

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

UsdsBaseType* BodyObjectPool::addBoolean(UsdsBaseType* parent, int id)
{
	UsdsBoolean* object = booleanObjects.addObject();
	//object->init(parent, id);
	return object;

};

UsdsBaseType* BodyObjectPool::addInt(UsdsBaseType* parent, int id)
{
	UsdsInt* object = intObjects.addObject();
	//object->init(dict, parent, id, name, name_size);
	return object;

};

UsdsBaseType* BodyObjectPool::addLong(UsdsBaseType* parent, int id)
{
	UsdsLong* object = longObjects.addObject();
	//object->init(dict, parent, id, name, name_size);
	return object;

};

UsdsBaseType* BodyObjectPool::addDouble(UsdsBaseType* parent, int id)
{
	UsdsDouble* object = doubleObjects.addObject();
	//object->init(dict, parent, id, name, name_size);
	return object;

};

UsdsBaseType* BodyObjectPool::addUVarint(UsdsBaseType* parent, int id)
{
	UsdsUVarint* object = uVarintObjects.addObject();
	//object->init(dict, parent, id, name, name_size);
	return object;

};

UsdsBaseType* BodyObjectPool::addArray(UsdsBaseType* parent, int id)
{
	UsdsArray* object = arrayObjects.addObject();
	//object->init(dict, parent, id, name, name_size);
	return object;

};

UsdsBaseType* BodyObjectPool::addString(UsdsBaseType* parent, int id)
{
	UsdsString* object = stringObjects.addObject();
	//object->init(dict, parent, id, name, name_size);
	return object;

};

UsdsBaseType* BodyObjectPool::addStruct(UsdsBaseType* parent, int id)
{
	UsdsStruct* object = structObjects.addObject();
	//object->init(dict, parent, id, name, name_size);
	return object;

};

