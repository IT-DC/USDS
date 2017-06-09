#include "dictionary\dataTypes\dictionaryTagLink.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryString.h"
#include "dictionary\dataTypes\dictionaryUVarint.h"
#include "dictionary\dataTypes\dictionaryStruct.h"

#include "dictionary\dicObjectPool.h"

using namespace usds;

//========================================================================================================

DictionaryObjectPool::DictionaryObjectPool(Dictionary* dict)
{
	pools[USDS_NO_TYPE] = 0;
	pools[USDS_TAG] = new TemplateObjectPool<DictionaryTagLink, Dictionary>(dict);
	pools[USDS_BOOLEAN] = new TemplateObjectPool<DictionaryBoolean, Dictionary>(dict);
	pools[USDS_BYTE] = 0;
	pools[USDS_UBYTE] = 0;
	pools[USDS_SHORT] = 0;
	pools[USDS_USHORT] = 0;
	pools[USDS_BIGENDIAN_SHORT] = 0;
	pools[USDS_BIGENDIAN_USHORT] = 0;
	pools[USDS_INT] = new TemplateObjectPool<DictionaryInt, Dictionary>(dict);
	pools[USDS_UINT] = 0;
	pools[USDS_BIGENDIAN_INT] = 0;
	pools[USDS_BIGENDIAN_UINT] = 0;
	pools[USDS_LONG] = new TemplateObjectPool<DictionaryLong, Dictionary>(dict);
	pools[USDS_ULONG] = 0;
	pools[USDS_BIGENDIAN_LONG] = 0;
	pools[USDS_BIGENDIAN_ULONG] = 0;
	pools[USDS_INT128] = 0;
	pools[USDS_UINT128] = 0;
	pools[USDS_BIGENDIAN_INT128] = 0;
	pools[USDS_BIGENDIAN_UINT128] = 0;
	pools[USDS_FLOAT] = 0;
	pools[USDS_BIGENDIAN_FLOAT] = 0;
	pools[USDS_DOUBLE] = new TemplateObjectPool<DictionaryDouble, Dictionary>(dict);
	pools[USDS_BIGENDIAN_DOUBLE] = 0;
	pools[USDS_VARINT] = 0;
	pools[USDS_UVARINT] = new TemplateObjectPool<DictionaryUVarint, Dictionary>(dict);
	pools[USDS_STRING] = new TemplateObjectPool<DictionaryString, Dictionary>(dict);
	pools[USDS_ARRAY] = new TemplateObjectPool<DictionaryArray, Dictionary>(dict);
	pools[USDS_LIST] = 0;
	pools[USDS_MAP] = 0;
	pools[USDS_POLYMORPH] = 0;
	pools[USDS_STRUCT] = new TemplateObjectPool<DictionaryStruct, Dictionary>(dict);
	pools[USDS_FUNCTION] = 0;
};

DictionaryObjectPool::~DictionaryObjectPool()
{
	for (int32_t i = 0; i < USDS_LAST_TYPE; i++)
	{
		if (pools[i] != 0)
			delete(pools[i]);
	}

};

DictionaryBaseType* DictionaryObjectPool::addObject(usdsTypes object_type, DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw(...)
try
{
	if (object_type <= USDS_NO_TYPE || object_type >= USDS_LAST_TYPE)
		throw ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE) << "Unsupported type " << object_type;
	// TODO: remove it when all type is ready
	if (pools[object_type] == 0)
		throw ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE) << "Unsupported type " << usdsTypeName(object_type);

	DictionaryBaseType* object = (DictionaryBaseType*)(pools[object_type])->addObject();
	try
	{
		object->initType(parent, id, name, name_size);
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
DictionaryTagLink* DictionaryObjectPool::addTagLink(DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw(...)
try
{
	//DictionaryTagLink* object = (DictionaryTagLink*)tagLinkObjects.addObject();
	try
	{
		object->initType(parent, id, name, name_size);
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

DictionaryBoolean* DictionaryObjectPool::addBoolean(DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryBoolean* object = (DictionaryBoolean*)booleanObjects.addObject();
	try
	{
		object->initType(parent, id, name, name_size);
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

DictionaryInt* DictionaryObjectPool::addInt(DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryInt* object = (DictionaryInt*)intObjects.addObject();
	try
	{
		object->initType(parent, id, name, name_size);
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

DictionaryLong* DictionaryObjectPool::addLong(DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryLong* object = (DictionaryLong*)longObjects.addObject();
	try
	{
		object->initType(parent, id, name, name_size);
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


DictionaryDouble* DictionaryObjectPool::addDouble(DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryDouble* object = (DictionaryDouble*)doubleObjects.addObject();
	try
	{
		object->initType(parent, id, name, name_size);
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

DictionaryUVarint* DictionaryObjectPool::addUVarint(DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryUVarint* object = (DictionaryUVarint*)uVarintObjects.addObject();
	try
	{
		object->initType(parent, id, name, name_size);
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

DictionaryString* DictionaryObjectPool::addString(DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryString* object = (DictionaryString*)stringObjects.addObject();
	try
	{
		object->initType(parent, id, name, name_size);
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

DictionaryArray* DictionaryObjectPool::addArray(DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryArray* object = (DictionaryArray*)arrayObjects.addObject();
	try
	{
		object->initType(parent, id, name, name_size);
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

DictionaryStruct* DictionaryObjectPool::addStruct(DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryStruct* object = (DictionaryStruct*)structObjects.addObject();
	try
	{
		object->initType(parent, id, name, name_size);
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
	for (int32_t i = 0; i < USDS_LAST_TYPE; i++)
	{
		if (pools[i] != 0)
			pools[i]->clearPool();
	}

};