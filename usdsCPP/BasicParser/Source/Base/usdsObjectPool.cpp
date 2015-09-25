#include "base\usdsObjectPool.h"

#include "base\usdsDictionary.h"
#include "tags\dicStructTag.h"
#include "tags\dicStructFields.h"

using namespace usds;

//========================================================================================================

DictionaryObjectPool::DictionaryObjectPool()
{
	dictionaryPool.setParent(this);

};

DictionaryObjectPool::~DictionaryObjectPool()
{

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