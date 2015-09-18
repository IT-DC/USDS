#include "base\usdsObjectPool.h"

using namespace usds;

DictionaryObjectPool::DictionaryObjectPool()
{
	lastStructTag = structTags.begin();
	lastBooleanField = booleanFields.begin();
	lastIntField = intFields.begin();
	lastLongField = longFields.begin();
	lastDoubleField = doubleFields.begin();
	lastArrayField = arrayFields.begin();
	lastStringField = stringFields.begin();


};

DictionaryObjectPool::~DictionaryObjectPool()
{




};

DicStructTag* DictionaryObjectPool::addStructTag() throw(...)
{
	DicStructTag* object = 0;

	if (lastStructTag == structTags.end())
	{
		structTags.push_back(DicStructTag(this));
		lastStructTag = structTags.end();
		object = &(structTags.back());
	}
	else
	{
		object = &(*lastStructTag);
		lastStructTag++;
	}
	
	return object;
};

DicBooleanField* DictionaryObjectPool::addBooleanField() throw(...)
{
	DicBooleanField* object = 0;

	if (lastBooleanField == booleanFields.end())
	{
		booleanFields.push_back(DicBooleanField(this));
		lastBooleanField = booleanFields.end();
		object = &(booleanFields.back());
	}
	else
	{
		object = &(*lastBooleanField);
		lastBooleanField++;
	}

	return object;

};

DicIntField* DictionaryObjectPool::addIntField() throw(...)
{
	DicIntField* object = 0;

	if (lastIntField == intFields.end())
	{
		intFields.push_back(DicIntField(this));
		lastIntField = intFields.end();
		object = &(intFields.back());
	}
	else
	{
		object = &(*lastIntField);
		lastIntField++;
	}

	return object;

};
DicLongField* DictionaryObjectPool::addLongField() throw(...)
{
	DicLongField* object = 0;

	if (lastLongField == longFields.end())
	{
		longFields.push_back(DicLongField(this));
		lastLongField = longFields.end();
		object = &(longFields.back());
	}
	else
	{
		object = &(*lastLongField);
		lastLongField++;
	}

	return object;
};

DicDoubleField* DictionaryObjectPool::addDoubleField() throw(...)
{
	DicDoubleField* object = 0;

	if (lastDoubleField == doubleFields.end())
	{
		doubleFields.push_back(DicDoubleField(this));
		lastDoubleField = doubleFields.end();
		object = &(doubleFields.back());
	}
	else
	{
		object = &(*lastDoubleField);
		lastDoubleField++;
	}

	return object;
};

DicArrayField* DictionaryObjectPool::addArrayField() throw(...)
{
	DicArrayField* object = 0;

	if (lastArrayField == arrayFields.end())
	{
		arrayFields.push_back(DicArrayField(this));
		lastArrayField = arrayFields.end();
		object = &(arrayFields.back());
	}
	else
	{
		object = &(*lastArrayField);
		lastArrayField++;
	}

	return object;
};

DicStringField* DictionaryObjectPool::addStringField() throw(...)
{
	DicStringField* object = 0;

	if (lastStringField == stringFields.end())
	{
		stringFields.push_back(DicStringField(this));
		lastStringField = stringFields.end();
		object = &(stringFields.back());
	}
	else
	{
		object = &(*lastStringField);
		lastStringField++;
	}

	return object;
};

void DictionaryObjectPool::clear()
{
	lastStructTag = structTags.begin();
	lastBooleanField = booleanFields.begin();
	lastIntField = intFields.begin();
	lastLongField = longFields.begin();
	lastDoubleField = doubleFields.begin();
	lastArrayField = arrayFields.begin();
	lastStringField = stringFields.begin();

};