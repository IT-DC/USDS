#ifndef USDS_OBJECT_POOL
#define USDS_OBJECT_POOL

#include "base\usdsErrors.h"
#include "tags\usdsTypes.h"

#include <list>

namespace usds
{
	class DictionaryObjectPool;
	class DicStructTag;
	class DicBooleanField;
	class DicIntField;
	class DicLongField;
	class DicDoubleField;
	class DicUVarintField;
	class DicArrayField;
	class DicStringField;

	template<typename T_objectPool> 
	class TemplateObjectPool : public std::list<T_objectPool>
	{
	public:
		TemplateObjectPool() : std::list<T_objectPool>() { lastElement = begin(); };
		~TemplateObjectPool() { };

		T_objectPool* addObject(DictionaryObjectPool* pool) throw(...);
		void clearPool() throw(...);

	private:
		typename std::list<T_objectPool>::iterator lastElement;
	};


	// Memory allocator, pattern "Object Pool"
	class DictionaryObjectPool
	{
	public:
		DictionaryObjectPool();
		~DictionaryObjectPool();

		// add tag from pool
		DicStructTag* addStructTag(const char* name, int id, bool root) throw(...);

		// add field from pool
		DicBooleanField* addBooleanField(const char* name, int id, bool optional) throw(...);
		DicIntField* addIntField(const char* name, int id, bool optional) throw(...);
		DicLongField* addLongField(const char* name, int id, bool optional) throw(...);
		DicDoubleField* addDoubleField(const char* name, int id, bool optional) throw(...);
		DicUVarintField* addUVarintField(const char* name, int id, bool optional) throw(...);
		DicArrayField* addArrayField(const char* name, int id, bool optional, const char* tag_name) throw(...);
		DicStringField* addStringField(const char* name, int id, bool optional, usdsEncodes encode) throw(...);

		// Clear pool, it does not release memory
		void clear();

	private:
		// Pool of tags
		TemplateObjectPool<DicStructTag> structTags;
		
		// Pool of fields
		TemplateObjectPool<DicBooleanField> booleanFields;
		TemplateObjectPool<DicIntField> intFields;
		TemplateObjectPool<DicLongField> longFields;
		TemplateObjectPool<DicDoubleField> doubleFields;
		TemplateObjectPool<DicUVarintField> uVarintFields;
		TemplateObjectPool<DicArrayField> arrayFields;
		TemplateObjectPool<DicStringField> stringFields;

	};

};
#endif