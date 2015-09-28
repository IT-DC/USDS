#include "base\usdsObjectPool.h"

#include "tags\dicStructTag.h"
#include "tags\dicStructFields.h"

using namespace usds;

//========================================================================================================

DictionaryObjectPool::DictionaryObjectPool()
{

};

DictionaryObjectPool::~DictionaryObjectPool()
{

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