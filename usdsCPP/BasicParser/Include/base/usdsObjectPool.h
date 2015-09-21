#ifndef USDS_OBJECT_PULL
#define USDS_OBJECT_PULL

#include <list>

#include "tags\dicStructTag.h"
#include "tags\dicStructFields.h"

namespace usds
{
	class DictionaryObjectPool;

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


	// Memory allocator, pattern "Object Pull"
	class DictionaryObjectPool
	{
	public:
		DictionaryObjectPool();
		~DictionaryObjectPool();

		// add tag from pull
		DicStructTag* addStructTag() throw(...);

		// add field from pull
		DicBooleanField* addBooleanField() throw(...);
		DicIntField* addIntField() throw(...);
		DicLongField* addLongField() throw(...);
		DicDoubleField* addDoubleField() throw(...);
		DicArrayField* addArrayField() throw(...);
		DicStringField* addStringField() throw(...);

		// Clear pull, it does not release memory
		void clear();

	private:
		// Pool of tags
		TemplateObjectPool<DicStructTag> structTags;
		
		// Pool of fields
		TemplateObjectPool<DicBooleanField> booleanFields;
		TemplateObjectPool<DicIntField> intFields;
		TemplateObjectPool<DicLongField> longFields;
		TemplateObjectPool<DicDoubleField> doubleFields;
		TemplateObjectPool<DicArrayField> arrayFields;
		TemplateObjectPool<DicStringField> stringFields;

	};

};
#endif