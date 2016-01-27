#include "dictionary\dataTypes\dictionaryTagLink.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryString.h"
#include "dictionary\dataTypes\dictionaryUVarint.h"
#include "dictionary\dataTypes\dictionaryStruct.h"

#include "base\objectPool\dicObjectPool.h"

using namespace usds;

//========================================================================================================

DictionaryObjectPool::DictionaryObjectPool(Dictionary* dict)
{
	pools[USDS_NO_TYPE] = 0;
	pools[USDS_TAG] = new TemplateObjectPool<DictionaryTagLink, Dictionary>(dict);
	pools[USDS_BOOLEAN] = new TemplateObjectPool<DictionaryBoolean, Dictionary>(dict);
	pools[USDS_INT] = new TemplateObjectPool<DictionaryInt, Dictionary>(dict);
	pools[USDS_LONG] = new TemplateObjectPool<DictionaryLong, Dictionary>(dict);
	pools[USDS_DOUBLE] = new TemplateObjectPool<DictionaryDouble, Dictionary>(dict);
	pools[USDS_UNSIGNED_VARINT] = new TemplateObjectPool<DictionaryUVarint, Dictionary>(dict);
	pools[USDS_STRING] = new TemplateObjectPool<DictionaryString, Dictionary>(dict);
	pools[USDS_ARRAY] = new TemplateObjectPool<DictionaryArray, Dictionary>(dict);
	pools[USDS_STRUCT] = new TemplateObjectPool<DictionaryStruct, Dictionary>(dict);
};

DictionaryObjectPool::~DictionaryObjectPool()
{

};

DictionaryBaseType* DictionaryObjectPool::addObject(usdsTypes object_type, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	if (pools[object_type] == 0)
		throw ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE) << "Unsupported type " << object_type;

	DictionaryBaseType* object = (DictionaryBaseType*)(pools[object_type])->addObject();
	try
	{
		object->init(parent, id, name, name_size);
	}
	catch (ErrorStack)
	{
		object->remove();
		throw;
	}
	
	return object;

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryObjectPool::addObject") << (void*)object_type << (void*)parent << id << name << name_size << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addObject") << (void*)object_type << (void*)parent << id << name << name_size;
	throw;
};

//========================================================================================================
/*
DictionaryTagLink* DictionaryObjectPool::addTagLink(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	//DictionaryTagLink* object = (DictionaryTagLink*)tagLinkObjects.addObject();
	try
	{
		object->init(parent, id, name, name_size);
	}
	catch (...)
	{
		object->remove();
		throw;
	}
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addTagLink") << (void*)parent << id << name << name_size;
	throw;
};

DictionaryBoolean* DictionaryObjectPool::addBoolean(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryBoolean* object = (DictionaryBoolean*)booleanObjects.addObject();
	try
	{
		object->init(parent, id, name, name_size);
	}
	catch (...)
	{
		object->remove();
		throw;
	}
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addBoolean") << (void*)parent << id << name << name_size;
	throw;
};

DictionaryInt* DictionaryObjectPool::addInt(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryInt* object = (DictionaryInt*)intObjects.addObject();
	try
	{
		object->init(parent, id, name, name_size);
	}
	catch (...)
	{
		object->remove();
		throw;
	}
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addInt") << (void*)parent << id << name << name_size;
	throw;
};

DictionaryLong* DictionaryObjectPool::addLong(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryLong* object = (DictionaryLong*)longObjects.addObject();
	try
	{
		object->init(parent, id, name, name_size);
	}
	catch (...)
	{
		object->remove();
		throw;
	}
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addLong") << (void*)parent << id << name << name_size;
	throw;
};


DictionaryDouble* DictionaryObjectPool::addDouble(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryDouble* object = (DictionaryDouble*)doubleObjects.addObject();
	try
	{
		object->init(parent, id, name, name_size);
	}
	catch (...)
	{
		object->remove();
		throw;
	}
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addDouble") << (void*)parent << id << name << name_size;
	throw;
};

DictionaryUVarint* DictionaryObjectPool::addUVarint(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryUVarint* object = (DictionaryUVarint*)uVarintObjects.addObject();
	try
	{
		object->init(parent, id, name, name_size);
	}
	catch (...)
	{
		object->remove();
		throw;
	}
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addUVarint") <<(void*)parent << id << name << name_size;
	throw;
};

DictionaryString* DictionaryObjectPool::addString(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryString* object = (DictionaryString*)stringObjects.addObject();
	try
	{
		object->init(parent, id, name, name_size);
	}
	catch (...)
	{
		object->remove();
		throw;
	}
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addString") << (void*)parent << id << name << name_size;
	throw;
};

DictionaryArray* DictionaryObjectPool::addArray(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryArray* object = (DictionaryArray*)arrayObjects.addObject();
	try
	{
		object->init(parent, id, name, name_size);
	}
	catch (...)
	{
		object->remove();
		throw;
	}
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addArray") << (void*)parent << id << name << name_size;
	throw;
};

DictionaryStruct* DictionaryObjectPool::addStruct(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryStruct* object = (DictionaryStruct*)structObjects.addObject();
	try
	{
		object->init(parent, id, name, name_size);
	}
	catch (...)
	{
		object->remove();
		throw;
	}
	return object;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addStruct") << (void*)parent << id << name << name_size;
	throw;
};
*/
//========================================================================================================
void DictionaryObjectPool::clear()
{
	for (int i = 0; i < USDS_LAST_TYPE; i++)
	{
		if (pools[i] != 0)
			pools[i]->clearPool();
	}

};