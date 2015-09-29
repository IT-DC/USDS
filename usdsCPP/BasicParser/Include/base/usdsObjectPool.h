#ifndef USDS_OBJECT_POOL
#define USDS_OBJECT_POOL

#include "base\usdsErrors.h"
#include "tags\usdsTypes.h"

#include <list>

namespace usds
{
	// template for pools
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

	class Dictionary;
	class DicBaseField;
	class DicBaseTag;

	class DicStructTag;
	class DicBooleanField;
	class DicIntField;
	class DicLongField;
	class DicDoubleField;
	class DicUVarintField;
	class DicArrayField;
	class DicStringField;


	//==================================================================================================
	// Object Pool for tags and fields



	class DictionaryObjectPool
	{
	public:
		DictionaryObjectPool();
		~DictionaryObjectPool();

		DicBaseTag* addTag(usdsTypes tag_type, Dictionary* dict, bool root, int id, const char* name, size_t name_size);
		DicBaseField* addField(usdsTypes field_type, Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional);
		
		// Clear pool, it does not release memory
		void clear();

	private:
		DicBaseTag* (DictionaryObjectPool::*tagPoolIndex[33])(Dictionary*, bool, int, const char*, size_t);
		
		DicBaseTag* addStructTag(Dictionary* dict, bool root, int id, const char* name, size_t name_size);


		DicBaseField* (DictionaryObjectPool::*fieldPoolIndex[33])(Dictionary*, DicStructTag*, int, const char*, size_t, bool);

		DicBaseField* addBooleanField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional);
		DicBaseField* addIntField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional);
		DicBaseField* addLongField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional);
		DicBaseField* addDoubleField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional);
		DicBaseField* addUVarintField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional);
		DicBaseField* addArrayField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional);
		DicBaseField* addStringField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional);

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