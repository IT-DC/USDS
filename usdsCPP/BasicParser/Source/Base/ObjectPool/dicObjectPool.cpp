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

DictionaryObjectPool::DictionaryObjectPool() :
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
	poolIndex[USDS_TAG] = &DictionaryObjectPool::addTag;
	poolIndex[USDS_BOOLEAN] = &DictionaryObjectPool::addBoolean;
	poolIndex[USDS_BYTE] = &DictionaryObjectPool::addByte;
	poolIndex[USDS_UNSIGNED_BYTE] = &DictionaryObjectPool::addUByte;
	poolIndex[USDS_SHORT] = &DictionaryObjectPool::addShort;
	poolIndex[USDS_UNSIGNED_SHORT] = &DictionaryObjectPool::addUShort;
	poolIndex[USDS_BIGENDIAN_SHORT] = &DictionaryObjectPool::addBEShort;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = &DictionaryObjectPool::addBEUShort;
	poolIndex[USDS_INT] = &DictionaryObjectPool::addInt;
	poolIndex[USDS_UNSIGNED_INT] = &DictionaryObjectPool::addUInt;
	poolIndex[USDS_BIGENDIAN_INT] = &DictionaryObjectPool::addBEInt;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_INT] = &DictionaryObjectPool::addBEUInt;
	poolIndex[USDS_LONG] = &DictionaryObjectPool::addLong;
	poolIndex[USDS_UNSIGNED_LONG] = &DictionaryObjectPool::addULong;
	poolIndex[USDS_BIGENDIAN_LONG] = &DictionaryObjectPool::addBELong;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = &DictionaryObjectPool::addBEULong;
	poolIndex[USDS_INT128] = &DictionaryObjectPool::addInt128;
	poolIndex[USDS_UNSIGNED_INT128] = &DictionaryObjectPool::addUInt128;
	poolIndex[USDS_BIGENDIAN_INT128] = &DictionaryObjectPool::addBEInt128;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = &DictionaryObjectPool::addBEUInt128;
	poolIndex[USDS_FLOAT] = &DictionaryObjectPool::addFloat;
	poolIndex[USDS_BIGENDIAN_FLOAT] = &DictionaryObjectPool::addBEFloat;
	poolIndex[USDS_DOUBLE] = &DictionaryObjectPool::addDouble;
	poolIndex[USDS_USDS_BIGENDIAN_DOUBLE] = &DictionaryObjectPool::addBEDouble;
	poolIndex[USDS_VARINT] = &DictionaryObjectPool::addVarint;
	poolIndex[USDS_UNSIGNED_VARINT] = &DictionaryObjectPool::addUVarint;
	poolIndex[USDS_STRING] = &DictionaryObjectPool::addString;
	poolIndex[USDS_ARRAY] = &DictionaryObjectPool::addArray;
	poolIndex[USDS_LIST] = &DictionaryObjectPool::addList;
	poolIndex[USDS_MAP] = &DictionaryObjectPool::addMap;
	poolIndex[USDS_POLYMORPH] = &DictionaryObjectPool::addPolymorhp;
	poolIndex[USDS_STRUCT] = &DictionaryObjectPool::addStruct;
	poolIndex[USDS_FUNCTION] = &DictionaryObjectPool::addFunction;

};

DictionaryObjectPool::~DictionaryObjectPool()
{

};

DictionaryBaseType* DictionaryObjectPool::addObject(usdsTypes object_type, Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	if (object_type <= USDS_NO_TYPE || object_type >= USDS_LAST_TYPE)
		throw ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE) << "Unsupported type " << object_type;

	return (this->*(poolIndex[object_type]))(dict, parent, id, name, name_size);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryObjectPool::addObject") << (void*)object_type << (void*)dict << (void*)parent << id << name << name_size << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addObject") << (void*)object_type << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

//========================================================================================================

DictionaryBaseType* DictionaryObjectPool::addTag(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addTag") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type TAG");
};

DictionaryBaseType* DictionaryObjectPool::addBoolean(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryBoolean* object = booleanObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addBoolean") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryBaseType* DictionaryObjectPool::addByte(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addByte") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BYTE");
};

DictionaryBaseType* DictionaryObjectPool::addUByte(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addUByte") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED BYTE");
};

DictionaryBaseType* DictionaryObjectPool::addShort(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addShort") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type SHORT");
};

DictionaryBaseType* DictionaryObjectPool::addUShort(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addUShort") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED SHORT");
};

DictionaryBaseType* DictionaryObjectPool::addBEShort(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addBEShort") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN SHORT");
};

DictionaryBaseType* DictionaryObjectPool::addBEUShort(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addBEUShort") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED SHORT");
};

DictionaryBaseType* DictionaryObjectPool::addInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryInt* object = intObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addInt") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryBaseType* DictionaryObjectPool::addUInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addUInt") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT");
};

DictionaryBaseType* DictionaryObjectPool::addBEInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addBEInt") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN INT");
};

DictionaryBaseType* DictionaryObjectPool::addBEUInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addBEUInt") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED INT");
};

DictionaryBaseType* DictionaryObjectPool::addLong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryLong* object = longObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addLong") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryBaseType* DictionaryObjectPool::addULong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addULong") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED LONG");
};

DictionaryBaseType* DictionaryObjectPool::addBELong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addBELong") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN LONG");
};

DictionaryBaseType* DictionaryObjectPool::addBEULong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addBEULong") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED LONG");
};

DictionaryBaseType* DictionaryObjectPool::addInt128(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addInt128") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type INT128");
};

DictionaryBaseType* DictionaryObjectPool::addUInt128(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addUInt128") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128");
};

DictionaryBaseType* DictionaryObjectPool::addBEInt128(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addBEInt128") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN INT128");
};

DictionaryBaseType* DictionaryObjectPool::addBEUInt128(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addBEUInt128") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED INT128");
};

DictionaryBaseType* DictionaryObjectPool::addFloat(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addFloat") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type FLOAT");
};

DictionaryBaseType* DictionaryObjectPool::addBEFloat(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addBEFloat") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN FLOAT");
};

DictionaryBaseType* DictionaryObjectPool::addDouble(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryDouble* object = doubleObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addDouble") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryBaseType* DictionaryObjectPool::addBEDouble(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addBEDouble") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN DOUBLE");
};

DictionaryBaseType* DictionaryObjectPool::addVarint(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addVarint") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type VARINT");
};

DictionaryBaseType* DictionaryObjectPool::addUVarint(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryUVarint* object = uVarintObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addUVarint") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryBaseType* DictionaryObjectPool::addString(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryString* object = stringObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addString") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryBaseType* DictionaryObjectPool::addArray(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryArray* object = arrayObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addArray") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryBaseType* DictionaryObjectPool::addList(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addList") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type LIST");
};

DictionaryBaseType* DictionaryObjectPool::addMap(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addMap") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type MAP");
};

DictionaryBaseType* DictionaryObjectPool::addPolymorhp(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addPolymorhp") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type POLYMORPH");
};

DictionaryBaseType* DictionaryObjectPool::addStruct(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryStruct* object = structObjects.addObject();
	object->init(dict, parent, id, name, name_size);
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addStruct") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryBaseType* DictionaryObjectPool::addFunction(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	throw ErrorStack("DictionaryObjectPool::addFunction") << (void*)dict << (void*)parent << id << name << name_size << ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type FUNCTION");
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