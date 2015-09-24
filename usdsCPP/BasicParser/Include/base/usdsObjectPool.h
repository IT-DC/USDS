#ifndef USDS_OBJECT_POOL
#define USDS_OBJECT_POOL

#include "base\usdsErrors.h"
#include "tags\usdsTypes.h"

#include <list>

namespace usds
{
	//==================================================================================================
	// For Dictionary
	class DictionaryObjectPool;

	template<class T_classPool>
	class TemplateClassPool : public std::list<T_classPool>
	{
	public:
		TemplateClassPool() : std::list<T_classPool>() { lastElement = begin(); };
		~TemplateClassPool() { };

		T_classPool* addObject(DictionaryObjectPool* pool) throw(...);
		void clearPool() throw(...);

	private:
		typename std::list<T_classPool>::iterator lastElement;
	};

	//==================================================================================================
	// for Tags and fields
	template<class T_objectPool> 
	class TemplateObjectPool : public std::list<T_objectPool>
	{
	public:
		TemplateObjectPool() : std::list<T_objectPool>() { lastElement = begin(); };
		~TemplateObjectPool() { };

		T_objectPool* addObject() throw(...);
		void clearPool() throw(...);

	private:
		typename std::list<T_objectPool>::iterator lastElement;
	};


	//==================================================================================================
	// Memory allocator, pattern "Object Pool"

	class Dictionary;
	class DicStructTag;
	class DicBooleanField;
	class DicIntField;
	class DicLongField;
	class DicDoubleField;
	class DicUVarintField;
	class DicArrayField;
	class DicStringField;

	class DictionaryObjectPool
	{
	public:
		DictionaryObjectPool();
		~DictionaryObjectPool();

		//add Dictionary from pool
		Dictionary* addDictionary();

		// add tag from pool
		DicStructTag* addStructTag(Dictionary* dict, const char* name, int id, bool root) throw(...);

		// add field from pool
		DicBooleanField* addBooleanField(Dictionary* dict, const char* name, int id, bool optional) throw(...);
		DicIntField* addIntField(Dictionary* dict, const char* name, int id, bool optional) throw(...);
		DicLongField* addLongField(Dictionary* dict, const char* name, int id, bool optional) throw(...);
		DicDoubleField* addDoubleField(Dictionary* dict, const char* name, int id, bool optional) throw(...);
		DicUVarintField* addUVarintField(Dictionary* dict, const char* name, int id, bool optional) throw(...);
		DicArrayField* addArrayField(Dictionary* dict, const char* name, int id, bool optional) throw(...);
		DicStringField* addStringField(Dictionary* dict, const char* name, int id, bool optional) throw(...);

		// Clear pool, it does not release memory
		void clear();

	private:
		// Pool of Dictionaries
		TemplateClassPool<Dictionary> dictionaryPool;

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