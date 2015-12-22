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

		DictionaryBoolean* addBoolean(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryByte* addByte(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryUByte* addUByte(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryShort* addShort(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryUShort* addUShort(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEShort* addBEShort(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEUShort* addBEUShort(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryInt* addInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryUInt* addUInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEInt* addBEInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEUInt* addBEUInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryLong* addLong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryULong* addULong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBELong* addBELong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEULong* addBEULong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryInt128* addInt128(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryUInt128* addUInt128(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEInt128* addBEInt128(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEUInt128* addBEUInt128(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryFloat* addFloat(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEFloat* addBEFloat(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryDouble* addDouble(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryBEDouble* addBEDouble(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryVarint* addVarint(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryUVarint* addUVarint(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryString* addString(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryArray* addArray(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryList* addList(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryMap* addMap(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryPolymorph* addPolymorhp(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		DictionaryStruct* addStruct(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		//DictionaryFunction* addFunction(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);

	private:

		// Pool of objects
		TemplateObjectPool<DictionaryBoolean, DictionaryObjectPool> booleanObjects;
		TemplateObjectPool<DictionaryInt, DictionaryObjectPool> intObjects;
		TemplateObjectPool<DictionaryLong, DictionaryObjectPool> longObjects;
		TemplateObjectPool<DictionaryDouble, DictionaryObjectPool> doubleObjects;
		TemplateObjectPool<DictionaryUVarint, DictionaryObjectPool> uVarintObjects;
		TemplateObjectPool<DictionaryString, DictionaryObjectPool> stringObjects;
		TemplateObjectPool<DictionaryArray, DictionaryObjectPool> arrayObjects;
		TemplateObjectPool<DictionaryStruct, DictionaryObjectPool> structObjects;

	};

};
#endif