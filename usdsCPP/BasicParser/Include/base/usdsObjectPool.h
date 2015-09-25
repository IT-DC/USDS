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
	class Dictionary;

	template<class T_classPool>
	class TemplateClassPool : public std::list<T_classPool*>
	{
	public:
		TemplateClassPool() : std::list<T_classPool*>() { lastElement = begin(); };
		~TemplateClassPool()
		{
			for (typename std::list<T_classPool*>::iterator it = begin(); it != end(); it++)
			{
				T_classPool* object = *it;
				if (object != 0)
					delete object;
			}
		};

		void setParent(DictionaryObjectPool* pool) { parent = pool; };
		T_classPool* addObject() throw(...)
		{
			T_classPool* object = 0;

			if (lastElement == end())
			{
				object = new T_classPool(parent);
				object->clear();
				push_back(object);
				lastElement = end();
			}
			else
			{
				object = *lastElement;
				lastElement++;
			}

			return object;
		};

		void clearPool() throw(...){ lastElement = begin();	};

	private:
		typename std::list<T_classPool*>::iterator lastElement;
		DictionaryObjectPool* parent;
	};

	//==================================================================================================
	// for Tags in Dictionary
	template<class T_tagPool> 
	class TemplateTagPool : public std::list<T_tagPool*>
	{
	public:
		TemplateTagPool() : std::list<T_tagPool*>() { lastElement = begin(); };
		~TemplateTagPool()
		{
			for (typename std::list<T_tagPool*>::iterator it = begin(); it != end(); it++)
			{
				T_tagPool* object = *it;
				if (object != 0)
					delete object;
			}
		};

		T_tagPool* addObject(Dictionary* dict, const char* name, int id, bool root) throw(...)
		{
			T_tagPool* object = 0;

			if (lastElement == end())
			{
				object = new T_tagPool();
				object->init(dict, name, id, root);
				push_back(object);
				lastElement = end();
			}
			else
			{
				object = *lastElement;
				lastElement++;
			}

			return object;
		};

		void clearPool() throw(...){ lastElement = begin();	};

	private:
		typename std::list<T_tagPool*>::iterator lastElement;
	};

	//==================================================================================================
	// for Fields in Dictionary
	template<class T_fieldPool>
	class TemplateFieldPool : public std::list<T_fieldPool*>
	{
	public:
		TemplateFieldPool() : std::list<T_fieldPool*>() { lastElement = begin(); };
		~TemplateFieldPool()
		{
			for (typename std::list<T_fieldPool*>::iterator it = begin(); it != end(); it++)
			{
				T_fieldPool* object = *it;
				if (object != 0)
					delete object;
			}
		};

		T_fieldPool* addObject(Dictionary* dict, const char* name, int id, bool optional) throw(...)
		{
			T_fieldPool* object = 0;

			if (lastElement == end())
			{
				object = new T_fieldPool();
				object->init(dict, name, id, optional);
				push_back(object);
				lastElement = end();
			}
			else
			{
				object = *lastElement;
				lastElement++;
			}

			return object;
		};

		void clearPool() throw(...)
		{
			lastElement = begin();
		};

	private:
		typename std::list<T_fieldPool*>::iterator lastElement;
	};

	//==================================================================================================
	// Memory allocator, pattern "Object Pool"

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

		// Clear pool, it does not release memory
		void clear();

		// Pool of Dictionaries
		TemplateClassPool<Dictionary> dictionaryPool;

		// Pool of tags
		TemplateTagPool<DicStructTag> structTags;
		
		// Pool of fields
		TemplateFieldPool<DicBooleanField> booleanFields;
		TemplateFieldPool<DicIntField> intFields;
		TemplateFieldPool<DicLongField> longFields;
		TemplateFieldPool<DicDoubleField> doubleFields;
		TemplateFieldPool<DicUVarintField> uVarintFields;
		TemplateFieldPool<DicArrayField> arrayFields;
		TemplateFieldPool<DicStringField> stringFields;

	};

};
#endif