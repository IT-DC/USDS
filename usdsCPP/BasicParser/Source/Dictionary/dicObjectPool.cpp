#include "dictionary\dataTypes\dictionaryTagLink.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryByte.h"
#include "dictionary\dataTypes\dictionaryUByte.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
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
	pools[USDS_BYTE] = new TemplateObjectPool<DictionaryByte, Dictionary>(dict);
	pools[USDS_UBYTE] = new TemplateObjectPool<DictionaryUByte, Dictionary>(dict);
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
	pools[USDS_MAP] = 0;
	pools[USDS_POLYARRAY] = 0;
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
void DictionaryObjectPool::clear()
{
	for (int32_t i = 0; i < USDS_LAST_TYPE; i++)
	{
		if (pools[i] != 0)
			pools[i]->clearPool();
	}

};