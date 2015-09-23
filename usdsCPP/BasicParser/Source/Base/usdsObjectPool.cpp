#include "base\usdsObjectPool.h"

#include "tags\dicStructTag.h"
#include "tags\dicStructFields.h"

using namespace usds;

template<typename T_objectPool>
T_objectPool* TemplateObjectPool<T_objectPool>::addObject(DictionaryObjectPool* pool) throw(...)
{
	T_objectPool* object = 0;

	if (lastElement == end())
	{
		push_back(T_objectPool(pool));
		lastElement = end();
		object = &(back());
	}
	else
	{
		object = &(*lastElement);
		lastElement++;
	}

	return object;
};

template<typename T_objectPool>
void TemplateObjectPool<T_objectPool>::clearPool() throw(...)
{
	lastElement = begin();
};

//========================================================================================================

DictionaryObjectPool::DictionaryObjectPool()
{

};

DictionaryObjectPool::~DictionaryObjectPool()
{

};

DicStructTag* DictionaryObjectPool::addStructTag(const char* name, int id, bool root) throw(...)
{
	DicStructTag* object = structTags.addObject(this);
	object->init(name, id, root);
	return object;
};

DicBooleanField* DictionaryObjectPool::addBooleanField(const char* name, int id, bool optional) throw(...)
{
	DicBooleanField* object = booleanFields.addObject(this);
	object->init(name, id, optional);
	return object;
};

DicIntField* DictionaryObjectPool::addIntField(const char* name, int id, bool optional) throw(...)
{
	DicIntField* object = intFields.addObject(this);
	object->init(name, id, optional);
	return object;
};

DicLongField* DictionaryObjectPool::addLongField(const char* name, int id, bool optional) throw(...)
{
	DicLongField* object = longFields.addObject(this);
	object->init(name, id, optional);
	return object;
};

DicDoubleField* DictionaryObjectPool::addDoubleField(const char* name, int id, bool optional) throw(...)
{
	DicDoubleField* object = doubleFields.addObject(this);
	object->init(name, id, optional);
	return object;
};

DicUVarintField* DictionaryObjectPool::addUVarintField(const char* name, int id, bool optional) throw(...)
{
	DicUVarintField* object = uVarintFields.addObject(this);
	object->init(name, id, optional);
	return object;
};

DicArrayField* DictionaryObjectPool::addArrayField(const char* name, int id, bool optional, const char* tag_name) throw(...)
{
	DicArrayField* object = arrayFields.addObject(this);
	object->init(name, id, optional);
	object->setElementType(tag_name);
	return object;
};

DicStringField* DictionaryObjectPool::addStringField(const char* name, int id, bool optional, usdsEncodes encode) throw(...)
{
	DicStringField* object = stringFields.addObject(this);
	object->init(name, id, optional);
	object->setEncode(encode);
	return object;
};

void DictionaryObjectPool::clear()
{
	structTags.clearPool();
	booleanFields.clearPool();
	intFields.clearPool();
	longFields.clearPool();
	doubleFields.clearPool();
	arrayFields.clearPool();
	stringFields.clearPool();

};