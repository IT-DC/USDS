#ifndef USDS_OBJECT_POOL
#define USDS_OBJECT_POOL

#include "base\usdsErrors.h"
#include "tags\usdsTypes.h"

#include <list>

namespace usds
{
	template<class T_classPool>
	class TemplateObjectPool : public std::list<T_classPool*>
	{
	public:
		TemplateObjectPool() : std::list<T_classPool*>() { lastElement = begin(); };
		~TemplateObjectPool()
		{
			for (typename std::list<T_classPool*>::iterator it = begin(); it != end(); it++)
			{
				T_classPool* object = *it;
				if (object != 0)
					delete object;
			}
		};

		T_classPool* addObject() throw(...)
		{
			T_classPool* object;

			if (lastElement == end())
			{
				object = new T_classPool();
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
	};


	//==================================================================================================
	// Object Pool for tags and fields

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