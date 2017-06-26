#ifndef DIC_OBJECT_POOL_H
#define DIC_OBJECT_POOL_H

#include "usdsErrors.h"
#include "usdsTypes.h"
#include "objectPool.h"

namespace usds
{
	class Dictionary;
	class DictionaryBaseType;

	
	class DictionaryObjectPool
	{
	public:
		DictionaryObjectPool(Dictionary* dict);
		~DictionaryObjectPool();

		DictionaryBaseType* addObject(usdsTypes object_type, DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw(...);

		// Clear pool, it does not release memory
		void clear();


	private:

		BasePoolClass* pools[USDS_LAST_TYPE];

		

	};

};
#endif