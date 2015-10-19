#include "base\objectPool\dicObjectPool.h"

#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryString.h"
#include "dictionary\dataTypes\dictionaryUVarint.h"
#include "dictionary\dataTypes\dictionaryStruct.h"

using namespace usds;

//========================================================================================================

DictionaryObjectPool::DictionaryObjectPool()
{
	poolIndex[USDS_NO_TYPE] = 0;
	poolIndex[USDS_BOOLEAN] = &DictionaryObjectPool::addBoolean;
	poolIndex[USDS_BYTE] = 0;
	poolIndex[USDS_UNSIGNED_BYTE] = 0;
	poolIndex[USDS_SHORT] = 0;
	poolIndex[USDS_UNSIGNED_SHORT] = 0;
	poolIndex[USDS_BIGENDIAN_SHORT] = 0;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	poolIndex[USDS_INT] = &DictionaryObjectPool::addInt;
	poolIndex[USDS_UNSIGNED_INT] = 0;
	poolIndex[USDS_BIGENDIAN_INT] = 0;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	poolIndex[USDS_LONG] = &DictionaryObjectPool::addLong;
	poolIndex[USDS_UNSIGNED_LONG] = 0;
	poolIndex[USDS_BIGENDIAN_LONG] = 0;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	poolIndex[USDS_INT128] = 0;
	poolIndex[USDS_UNSIGNED_INT128] = 0;
	poolIndex[USDS_BIGENDIAN_INT128] = 0;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	poolIndex[USDS_FLOAT] = 0;
	poolIndex[USDS_BIGENDIAN_FLOAT] = 0;
	poolIndex[USDS_DOUBLE] = &DictionaryObjectPool::addDouble;
	poolIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	poolIndex[USDS_VARINT] = 0;
	poolIndex[USDS_UNSIGNED_VARINT] = &DictionaryObjectPool::addUVarint;
	poolIndex[USDS_STRUCT] = &DictionaryObjectPool::addStruct;
	poolIndex[USDS_ARRAY] = &DictionaryObjectPool::addArray;
	poolIndex[USDS_STRING] = &DictionaryObjectPool::addString;
	poolIndex[USDS_LIST] = 0;
	poolIndex[USDS_MAP] = 0;
	poolIndex[USDS_POLYMORPH] = 0;
	poolIndex[USDS_TAG] = 0;

};

DictionaryObjectPool::~DictionaryObjectPool()
{

};

DictionaryBaseType* DictionaryObjectPool::addObject(usdsTypes object_type, Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size)
{
	return (this->*(poolIndex[object_type]))(dict, parent, id, name, name_size);

};

//========================================================================================================

DictionaryBaseType* DictionaryObjectPool::addStruct(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size)
{
	DictionaryStruct* object = structObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
};

DictionaryBaseType* DictionaryObjectPool::addBoolean(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size)
{
	DictionaryBoolean* object = booleanObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
};

DictionaryBaseType* DictionaryObjectPool::addInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size)
{
	DictionaryInt* object = intObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
};

DictionaryBaseType* DictionaryObjectPool::addLong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size)
{
	DictionaryLong* object = longObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
};

DictionaryBaseType* DictionaryObjectPool::addDouble(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size)
{
	DictionaryDouble* object = doubleObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
};

DictionaryBaseType* DictionaryObjectPool::addUVarint(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size)
{
	DictionaryUVarint* object = uVarintObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
};

DictionaryBaseType* DictionaryObjectPool::addArray(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size)
{
	DictionaryArray* object = arrayObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
};

DictionaryBaseType* DictionaryObjectPool::addString(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size)
{
	DictionaryString* object = stringObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
};

//========================================================================================================
void DictionaryObjectPool::clear()
{
	booleanObjects.clearPool();
	intObjects.clearPool();
	longObjects.clearPool();
	doubleObjects.clearPool();
	arrayObjects.clearPool();
	stringObjects.clearPool();
	structObjects.clearPool();

};