#ifndef DIC_OBJECT_POOL_H
#define DIC_OBJECT_POOL_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"
#include "base\object pool\usdsObjectPool.h"

namespace usds
{
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

	class DictionaryObjectPool
	{
	public:
		DictionaryObjectPool();
		~DictionaryObjectPool();

		DicBaseTag* addTag(usdsTypes tag_type, Dictionary* dict, int id, const char* name, size_t name_size);
		DicBaseField* addField(usdsTypes field_type, Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size);

		// Clear pool, it does not release memory
		void clear();

	private:
		DicBaseTag* (DictionaryObjectPool::*tagPoolIndex[33])(Dictionary*, int, const char*, size_t);

		DicBaseTag* addStructTag(Dictionary* dict, int id, const char* name, size_t name_size);


		DicBaseField* (DictionaryObjectPool::*fieldPoolIndex[33])(Dictionary*, DicStructTag*, int, const char*, size_t);

		DicBaseField* addBooleanField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size);
		DicBaseField* addIntField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size);
		DicBaseField* addLongField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size);
		DicBaseField* addDoubleField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size);
		DicBaseField* addUVarintField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size);
		DicBaseField* addArrayField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size);
		DicBaseField* addStringField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size);

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