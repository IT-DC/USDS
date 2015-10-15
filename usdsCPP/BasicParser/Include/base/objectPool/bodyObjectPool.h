#ifndef BODY_OBJECT_POOL
#define BODY_OBJECT_POOL

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"
#include "base\object pool\usdsObjectPool.h"

namespace usds
{
	class BaseField;
	class BaseTag;

	class StructTag;
	class BooleanField;
	class IntField;
	class LongField;
	class DoubleField;
	class UVarintField;
	class ArrayField;
	class StringField;

	class BodyObjectPool
	{
	public:
		BodyObjectPool();
		~BodyObjectPool();

		BaseTag* addTag(usdsTypes tag_type, int id);
		BaseField* addField(usdsTypes field_type, StructTag* tag, int id);

		// Clear pool, it does not release memory
		void clear();

	private:
		BaseTag* (BodyObjectPool::*tagPoolIndex[33])(int);

		BaseTag* addStructTag(int id);


		BaseField* (BodyObjectPool::*fieldPoolIndex[33])(StructTag*, int);

		BaseField* addBooleanField(StructTag* tag, int id);
		BaseField* addIntField(StructTag* tag, int id);
		BaseField* addLongField(StructTag* tag, int id);
		BaseField* addDoubleField(StructTag* tag, int id);
		BaseField* addUVarintField(StructTag* tag, int id);
		BaseField* addArrayField(StructTag* tag, int id);
		BaseField* addStringField(StructTag* tag, int id);

		// Pool of tags
		TemplateObjectPool<StructTag> structTags;

		// Pool of fields
		TemplateObjectPool<BooleanField> booleanFields;
		TemplateObjectPool<IntField> intFields;
		TemplateObjectPool<LongField> longFields;
		TemplateObjectPool<DoubleField> doubleFields;
		TemplateObjectPool<UVarintField> uVarintFields;
		TemplateObjectPool<ArrayField> arrayFields;
		TemplateObjectPool<StringField> stringFields;


	};

}

#endif