#ifndef BODY_OBJECT_POOL_H
#define BODY_OBJECT_POOL_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"
#include "base\objectPool\usdsObjectPool.h"

namespace usds
{
	class UsdsBaseType;
	class DictionaryBaseType;

	class UsdsBoolean;
	class UsdsInt;
	class UsdsLong;
	class UsdsDouble;
	class UsdsUVarint;
	class UsdsArray;
	class UsdsString;
	class UsdsStruct;

	class BodyObjectPool
	{
	public:
		BodyObjectPool();
		~BodyObjectPool();

		UsdsBaseType* addObject(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);

		// Clear pool, it does not release memory
		void clear();

		UsdsBoolean* addBoolean(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addByte(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addUByte(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addShort(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addUShort(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addBEShort(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addBEUShort(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		UsdsInt* addInt(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addUInt(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addBEInt(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addBEUInt(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		UsdsLong* addLong(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addULong(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addBELong(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addBEULong(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addInt128(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addUInt128(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addBEInt128(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addBEUInt128(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addFloat(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addBEFloat(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		UsdsDouble* addDouble(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addBEDouble(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addVarint(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		UsdsUVarint* addUVarint(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		UsdsString* addString(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		UsdsArray* addArray(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addList(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addMap(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addPolymorhp(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		UsdsStruct* addStruct(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		//UsdsBaseType* addFunction(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);
		
	private:

		// Pool of objects
		TemplateObjectPool<UsdsBoolean, BodyObjectPool> booleanObjects;
		TemplateObjectPool<UsdsInt, BodyObjectPool> intObjects;
		TemplateObjectPool<UsdsLong, BodyObjectPool> longObjects;
		TemplateObjectPool<UsdsDouble, BodyObjectPool> doubleObjects;
		TemplateObjectPool<UsdsUVarint, BodyObjectPool> uVarintObjects;
		TemplateObjectPool<UsdsString, BodyObjectPool> stringObjects;
		TemplateObjectPool<UsdsArray, BodyObjectPool> arrayObjects;
		TemplateObjectPool<UsdsStruct, BodyObjectPool> structObjects;

	};

}

#endif