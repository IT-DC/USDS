#include "base\usdsObjectPool.h"

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

DicStructTag* DictionaryObjectPool::addStructTag() throw(...)
{
	return structTags.addObject(this);
};

DicBooleanField* DictionaryObjectPool::addBooleanField() throw(...)
{
	return booleanFields.addObject(this);
};

DicIntField* DictionaryObjectPool::addIntField() throw(...)
{
	return intFields.addObject(this);
};

DicLongField* DictionaryObjectPool::addLongField() throw(...)
{
	return longFields.addObject(this);
};

DicDoubleField* DictionaryObjectPool::addDoubleField() throw(...)
{
	return doubleFields.addObject(this);
};

DicArrayField* DictionaryObjectPool::addArrayField() throw(...)
{
	return arrayFields.addObject(this);
};

DicStringField* DictionaryObjectPool::addStringField() throw(...)
{
	return stringFields.addObject(this);
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