#ifndef BODY_OBJECT_POOL_H
#define BODY_OBJECT_POOL_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"
#include "base\objectPool\usdsObjectPool.h"

namespace usds
{
	class UsdsBaseType;

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

		UsdsBaseType* addObject(usdsTypes object_type, UsdsBaseType* parent, int id);

		// Clear pool, it does not release memory
		void clear();

	private:
		UsdsBaseType* (BodyObjectPool::*poolIndex[33])(UsdsBaseType*, int);

		UsdsBaseType* addBoolean(UsdsBaseType* parent, int id);
		UsdsBaseType* addInt(UsdsBaseType* parent, int id);
		UsdsBaseType* addLong(UsdsBaseType* parent, int id);
		UsdsBaseType* addDouble(UsdsBaseType* parent, int id);
		UsdsBaseType* addUVarint(UsdsBaseType* parent, int id);
		UsdsBaseType* addArray(UsdsBaseType* parent, int id);
		UsdsBaseType* addString(UsdsBaseType* parent, int id);
		UsdsBaseType* addStruct(UsdsBaseType* parent, int id);
		
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