#ifndef DIC_OBJECT_POOL_H
#define DIC_OBJECT_POOL_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"
#include "base\objectPool\usdsObjectPool.h"

namespace usds
{
	class Dictionary;
	class DictionaryBaseType;

	class DictionaryBoolean;
	class DictionaryInt;
	class DictionaryLong;
	class DictionaryDouble;
	class DictionaryUVarint;
	class DictionaryArray;
	class DictionaryString;
	class DictionaryStruct;

	class DictionaryObjectPool
	{
	public:
		DictionaryObjectPool();
		~DictionaryObjectPool();

		DictionaryBaseType* addObject(usdsTypes object_type, Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size);

		// Clear pool, it does not release memory
		void clear();

	private:

		DictionaryBaseType* (DictionaryObjectPool::*poolIndex[33])(Dictionary*, DictionaryBaseType*, int, const char*, size_t);

		DictionaryBaseType* addBoolean(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size);
		DictionaryBaseType* addInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size);
		DictionaryBaseType* addLong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size);
		DictionaryBaseType* addDouble(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size);
		DictionaryBaseType* addUVarint(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size);
		DictionaryBaseType* addArray(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size);
		DictionaryBaseType* addString(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size);
		DictionaryBaseType* addStruct(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size);

		// Pool of objects
		TemplateObjectPool<DictionaryBoolean> booleanObjects;
		TemplateObjectPool<DictionaryInt> intObjects;
		TemplateObjectPool<DictionaryLong> longObjects;
		TemplateObjectPool<DictionaryDouble> doubleObjects;
		TemplateObjectPool<DictionaryUVarint> uVarintObjects;
		TemplateObjectPool<DictionaryArray> arrayObjects;
		TemplateObjectPool<DictionaryString> stringObjects;
		TemplateObjectPool<DictionaryStruct> structObjects;

	};

};
#endif