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

		DictionaryBaseType* addObject(usdsTypes object_type, Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);

		// Clear pool, it does not release memory
		void clear();

	private:

		DictionaryBaseType* (DictionaryObjectPool::*poolIndex[USDS_LAST_TYPE])(Dictionary*, DictionaryBaseType*, int, const char*, size_t);

		DictionaryBaseType* addTag(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addBoolean(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addByte(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addUByte(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addShort(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addUShort(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addBEShort(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addBEUShort(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addUInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addBEInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addBEUInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addLong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addULong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addBELong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addBEULong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addInt128(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addUInt128(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addBEInt128(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addBEUInt128(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addFloat(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addBEFloat(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addDouble(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addBEDouble(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addVarint(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addUVarint(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addString(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addArray(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addList(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addMap(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addPolymorhp(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addStruct(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addFunction(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);

		// Pool of objects
		TemplateObjectPool<DictionaryBoolean, DictionaryObjectPool> booleanObjects;
		TemplateObjectPool<DictionaryInt, DictionaryObjectPool> intObjects;
		TemplateObjectPool<DictionaryLong, DictionaryObjectPool> longObjects;
		TemplateObjectPool<DictionaryDouble, DictionaryObjectPool> doubleObjects;
		TemplateObjectPool<DictionaryUVarint, DictionaryObjectPool> uVarintObjects;
		TemplateObjectPool<DictionaryArray, DictionaryObjectPool> arrayObjects;
		TemplateObjectPool<DictionaryString, DictionaryObjectPool> stringObjects;
		TemplateObjectPool<DictionaryStruct, DictionaryObjectPool> structObjects;

	};

};
#endif