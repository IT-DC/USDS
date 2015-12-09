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
	poolIndex[USDS_TAG] = &BodyObjectPool::addTag;
	poolIndex[USDS_BOOLEAN] = &BodyObjectPool::addBoolean;
	poolIndex[USDS_BYTE] = &BodyObjectPool::addByte;
	poolIndex[USDS_UNSIGNED_BYTE] = &BodyObjectPool::addUByte;
	poolIndex[USDS_SHORT] = &BodyObjectPool::addShort;
	poolIndex[USDS_UNSIGNED_SHORT] = &BodyObjectPool::addUShort;
	poolIndex[USDS_BIGENDIAN_SHORT] = &BodyObjectPool::addBEShort;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = &BodyObjectPool::addBEUShort;
	poolIndex[USDS_INT] = &BodyObjectPool::addInt;
	poolIndex[USDS_UNSIGNED_INT] = &BodyObjectPool::addUInt;
	poolIndex[USDS_BIGENDIAN_INT] = &BodyObjectPool::addBEInt;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_INT] = &BodyObjectPool::addBEUInt;
	poolIndex[USDS_LONG] = &BodyObjectPool::addLong;
	poolIndex[USDS_UNSIGNED_LONG] = &BodyObjectPool::addULong;
	poolIndex[USDS_BIGENDIAN_LONG] = &BodyObjectPool::addBELong;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = &BodyObjectPool::addBEULong;
	poolIndex[USDS_INT128] = &BodyObjectPool::addInt128;
	poolIndex[USDS_UNSIGNED_INT128] = &BodyObjectPool::addUInt128;
	poolIndex[USDS_BIGENDIAN_INT128] = &BodyObjectPool::addBEInt128;
	poolIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = &BodyObjectPool::addBEUInt128;
	poolIndex[USDS_FLOAT] = &BodyObjectPool::addFloat;
	poolIndex[USDS_BIGENDIAN_FLOAT] = &BodyObjectPool::addBEFloat;
	poolIndex[USDS_DOUBLE] = &BodyObjectPool::addDouble;
	poolIndex[USDS_USDS_BIGENDIAN_DOUBLE] = &BodyObjectPool::addBEDouble;
	poolIndex[USDS_VARINT] = &BodyObjectPool::addVarint;
	poolIndex[USDS_UNSIGNED_VARINT] = &BodyObjectPool::addUVarint;
	poolIndex[USDS_STRING] = &BodyObjectPool::addString;
	poolIndex[USDS_ARRAY] = &BodyObjectPool::addArray;
	poolIndex[USDS_LIST] = &BodyObjectPool::addList;
	poolIndex[USDS_MAP] = &BodyObjectPool::addMap;
	poolIndex[USDS_POLYMORPH] = &BodyObjectPool::addPolymorhp;
	poolIndex[USDS_STRUCT] = &BodyObjectPool::addStruct;
	poolIndex[USDS_FUNCTION] = &BodyObjectPool::addFunction;

}

BodyObjectPool::~BodyObjectPool()
{

}

UsdsBaseType* BodyObjectPool::addObject(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	return (this->*(poolIndex[dict_parent->getType()]))(dict_parent, body_parent);
}
catch (ErrorStack& err)
{
	err.addLevel("BodyObjectPool::addObject") << (void*)dict_parent << (void*)body_parent;
	throw;
};

//===============================================================================================================================

UsdsBaseType* BodyObjectPool::addTag(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addTag") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type TAG");
};

UsdsBaseType* BodyObjectPool::addBoolean(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsBoolean* object = booleanObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("BodyObjectPool::addBoolean") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsBaseType* BodyObjectPool::addByte(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addByte") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BYTE");
};

UsdsBaseType* BodyObjectPool::addUByte(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addUByte") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED BYTE");
};

UsdsBaseType* BodyObjectPool::addShort(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addShort") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type SHORT");
};

UsdsBaseType* BodyObjectPool::addUShort(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addUShort") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED SHORT");
};

UsdsBaseType* BodyObjectPool::addBEShort(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addBEShort") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN SHORT");
};

UsdsBaseType* BodyObjectPool::addBEUShort(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addBEUShort") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED SHORT");
};

UsdsBaseType* BodyObjectPool::addInt(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsInt* object = intObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;

}
catch (ErrorStack& err)
{
	err.addLevel("BodyObjectPool::addInt") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsBaseType* BodyObjectPool::addUInt(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addUInt") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT");
};

UsdsBaseType* BodyObjectPool::addBEInt(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addBEInt") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN INT");
};

UsdsBaseType* BodyObjectPool::addBEUInt(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addBEUInt") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED INT");
};

UsdsBaseType* BodyObjectPool::addLong(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsLong* object = longObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;

}
catch (ErrorStack& err)
{
	err.addLevel("BodyObjectPool::addLong") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsBaseType* BodyObjectPool::addULong(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addULong") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED LONG");
};

UsdsBaseType* BodyObjectPool::addBELong(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addBELong") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN LONG");
};

UsdsBaseType* BodyObjectPool::addBEULong(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addBEULong") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED LONG");
};

UsdsBaseType* BodyObjectPool::addInt128(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addInt128") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128");
};

UsdsBaseType* BodyObjectPool::addUInt128(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addUInt128") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128");
};

UsdsBaseType* BodyObjectPool::addBEInt128(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addBEInt128") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN INT128");
};

UsdsBaseType* BodyObjectPool::addBEUInt128(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addBEUInt128") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED INT128");
};

UsdsBaseType* BodyObjectPool::addFloat(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addFloat") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type FLOAT");
};

UsdsBaseType* BodyObjectPool::addBEFloat(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addBEFloat") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN FLOAT");
};

UsdsBaseType* BodyObjectPool::addDouble(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsDouble* object = doubleObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("BodyObjectPool::addDouble") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsBaseType* BodyObjectPool::addBEDouble(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addBEDouble") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN DOUBLE");
};

UsdsBaseType* BodyObjectPool::addVarint(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addVarint") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type VARINT");
};

UsdsBaseType* BodyObjectPool::addUVarint(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsUVarint* object = uVarintObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;

}
catch (ErrorStack& err)
{
	err.addLevel("BodyObjectPool::addUVarint") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsBaseType* BodyObjectPool::addString(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsString* object = stringObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;

}
catch (ErrorStack& err)
{
	err.addLevel("BodyObjectPool::addString") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsBaseType* BodyObjectPool::addArray(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsArray* object = arrayObjects.addObject();
	object->init(dict_parent, body_parent);
	return object;

}
catch (ErrorStack& err)
{
	err.addLevel("BodyObjectPool::addArray") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsBaseType* BodyObjectPool::addList(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addList") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type LIST");
};

UsdsBaseType* BodyObjectPool::addMap(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addMap") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type MAP");
};

UsdsBaseType* BodyObjectPool::addPolymorhp(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addPolymorhp") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type POLYMORPH");
};

UsdsBaseType* BodyObjectPool::addStruct(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsStruct* object = structObjects.addObject();
	object->init(dict_parent, body_parent);


	return object;

}
catch (ErrorStack& err)
{
	err.addLevel("BodyObjectPool::addStruct") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsBaseType* BodyObjectPool::addFunction(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	throw ErrorStack("BodyObjectPool::addFunction") << (void*)dict_parent << (void*)body_parent << ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE, "Unsupported type FUNCTION");
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
