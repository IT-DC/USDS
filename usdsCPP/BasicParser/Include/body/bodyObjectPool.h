#ifndef BODY_OBJECT_POOL_H
#define BODY_OBJECT_POOL_H

#include "usdsErrors.h"
#include "usdsTypes.h"
#include "objectPool.h"

namespace usds
{
	class UsdsBaseType;
	class DictionaryBaseType;
	class Body;

	class BodyObjectPool
	{
	public:
		BodyObjectPool(Body* parent_body);
		~BodyObjectPool();

		UsdsBaseType* addObject(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);

		// Clear pool, it does not release memory
		void clear();


	private:

		// Pool of objects
		BasePoolClass* pools[USDS_LAST_TYPE];

	};

}

#endif