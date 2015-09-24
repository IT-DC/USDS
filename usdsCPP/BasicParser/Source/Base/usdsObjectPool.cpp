#include "base\usdsObjectPool.h"

#include "base\usdsDictionary.h"
#include "tags\dicStructTag.h"
#include "tags\dicStructFields.h"

using namespace usds;

//========================================================================================================

template<class T_classPool>
T_classPool* TemplateClassPool<T_classPool>::addObject(DictionaryObjectPool* pool) throw(...)
{
	T_classPool* object = 0;

	if (lastElement == end())
	{
		push_back(T_classPool(pool));
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

template<class T_classPool>
void TemplateClassPool<T_classPool>::clearPool() throw(...)
{
	lastElement = begin();
};

//========================================================================================================

template<class T_objectPool>
T_objectPool* TemplateObjectPool<T_objectPool>::addObject() throw(...)
{
	T_objectPool* object = 0;

	if (lastElement == end())
	{
		push_back(T_objectPool());
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

template<class T_objectPool>
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

//========================================================================================================
Dictionary* DictionaryObjectPool::addDictionary()
{
	Dictionary* object = dictionaryPool.addObject(this);
	object->clear();
	return object;

};

//========================================================================================================
DicStructTag* DictionaryObjectPool::addStructTag(Dictionary* dict, const char* name, int id, bool root) throw(...)
{
	DicStructTag* object = structTags.addObject();
	object->init(dict, name, id, root);
	return object;
};

//========================================================================================================

DicBooleanField* DictionaryObjectPool::addBooleanField(Dictionary* dict, const char* name, int id, bool optional) throw(...)
{
	DicBooleanField* object = booleanFields.addObject();
	object->init(dict, name, id, optional);
	return object;
};

DicIntField* DictionaryObjectPool::addIntField(Dictionary* dict, const char* name, int id, bool optional) throw(...)
{
	DicIntField* object = intFields.addObject();
	object->init(dict, name, id, optional);
	return object;
};

DicLongField* DictionaryObjectPool::addLongField(Dictionary* dict, const char* name, int id, bool optional) throw(...)
{
	DicLongField* object = longFields.addObject();
	object->init(dict, name, id, optional);
	return object;
};

DicDoubleField* DictionaryObjectPool::addDoubleField(Dictionary* dict, const char* name, int id, bool optional) throw(...)
{
	DicDoubleField* object = doubleFields.addObject();
	object->init(dict, name, id, optional);
	return object;
};

DicUVarintField* DictionaryObjectPool::addUVarintField(Dictionary* dict, const char* name, int id, bool optional) throw(...)
{
	DicUVarintField* object = uVarintFields.addObject();
	object->init(dict, name, id, optional);
	return object;
};

DicArrayField* DictionaryObjectPool::addArrayField(Dictionary* dict, const char* name, int id, bool optional) throw(...)
{
	DicArrayField* object = arrayFields.addObject();
	object->init(dict, name, id, optional);
	return object;
};

DicStringField* DictionaryObjectPool::addStringField(Dictionary* dict, const char* name, int id, bool optional) throw(...)
{
	DicStringField* object = stringFields.addObject();
	object->init(dict, name, id, optional);
	return object;
};

void DictionaryObjectPool::clear()
{
	dictionaryPool.clearPool();
	
	structTags.clearPool();
	
	booleanFields.clearPool();
	intFields.clearPool();
	longFields.clearPool();
	doubleFields.clearPool();
	arrayFields.clearPool();
	stringFields.clearPool();

};