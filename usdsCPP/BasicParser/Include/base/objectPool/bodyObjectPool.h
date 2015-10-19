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

		UsdsBaseType* addObject(usdsTypes object_type, DictionaryBaseType* dict_parent, UsdsBaseType* body_parent);

		// Clear pool, it does not release memory
		void clear();

	private:
		UsdsBaseType* (BodyObjectPool::*poolIndex[33])(DictionaryBaseType*,UsdsBaseType*);

		UsdsBaseType* addBoolean(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent);
		UsdsBaseType* addInt(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent);
		UsdsBaseType* addLong(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent);
		UsdsBaseType* addDouble(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent);
		UsdsBaseType* addUVarint(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent);
		UsdsBaseType* addArray(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent);
		UsdsBaseType* addString(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent);
		UsdsBaseType* addStruct(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent);
		
		// Pool of objects
		TemplateObjectPool<UsdsBoolean> booleanObjects;
		TemplateObjectPool<UsdsInt> intObjects;
		TemplateObjectPool<UsdsLong> longObjects;
		TemplateObjectPool<UsdsDouble> doubleObjects;
		TemplateObjectPool<UsdsUVarint> uVarintObjects;
		TemplateObjectPool<UsdsArray> arrayObjects;
		TemplateObjectPool<UsdsString> stringObjects;
		TemplateObjectPool<UsdsStruct> structObjects;

	};

}

#endif