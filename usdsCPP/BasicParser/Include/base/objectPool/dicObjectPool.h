#ifndef DIC_OBJECT_POOL_H
#define DIC_OBJECT_POOL_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"
#include "base\objectPool\usdsObjectPool.h"

namespace usds
{
	class Dictionary;
	class DictionaryBaseType;

	class DictionaryTagLink;
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
		DictionaryObjectPool(Dictionary* dict);
		~DictionaryObjectPool();

		DictionaryBaseType* addObject(usdsTypes object_type, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);

		// Clear pool, it does not release memory
		void clear();
		/*
		DictionaryTagLink* addTagLink(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryBoolean* addBoolean(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryByte* addByte(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryUByte* addUByte(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryShort* addShort(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryUShort* addUShort(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEShort* addBEShort(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEUShort* addBEUShort(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryInt* addInt(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryUInt* addUInt(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEInt* addBEInt(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEUInt* addBEUInt(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryLong* addLong(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryULong* addULong(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBELong* addBELong(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEULong* addBEULong(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryInt128* addInt128(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryUInt128* addUInt128(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEInt128* addBEInt128(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEUInt128* addBEUInt128(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryFloat* addFloat(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEFloat* addBEFloat(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryDouble* addDouble(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEDouble* addBEDouble(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryVarint* addVarint(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryUVarint* addUVarint(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryString* addString(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryArray* addArray(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryList* addList(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryMap* addMap(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryPolymorph* addPolymorhp(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryStruct* addStruct(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryFunction* addFunction(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		*/

	private:

		BasePoolClass* pools[USDS_LAST_TYPE];

		

	};

};
#endif