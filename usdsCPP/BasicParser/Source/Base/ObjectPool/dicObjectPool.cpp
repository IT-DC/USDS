#include "base\objectPool\dicObjectPool.h"

#include "dictionary\dataTypes\dictionaryTagLink.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryString.h"
#include "dictionary\dataTypes\dictionaryUVarint.h"
#include "dictionary\dataTypes\dictionaryStruct.h"

using namespace usds;

//========================================================================================================

DictionaryObjectPool::DictionaryObjectPool(Dictionary* dict) :
	tagLinkObjects(dict),
	booleanObjects(dict),
	intObjects(dict),
	longObjects(dict),
	doubleObjects(dict),
	uVarintObjects(dict),
	arrayObjects(dict),
	stringObjects(dict),
	structObjects(dict)
{

};

DictionaryObjectPool::~DictionaryObjectPool()
{

};

DictionaryBaseType* DictionaryObjectPool::addObject(usdsTypes object_type, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryBaseType* object = 0;

	switch (object_type)
	{
	case USDS_TAG:
		object = tagLinkObjects.addObject();
		break;
	case USDS_BOOLEAN:
		object = booleanObjects.addObject();
		break;
	case USDS_INT:
		object = intObjects.addObject();
		break;
	case USDS_LONG:
		object = longObjects.addObject();
		break;
	case USDS_DOUBLE:
		object = doubleObjects.addObject();
		break;
	case USDS_UNSIGNED_VARINT:
		object = uVarintObjects.addObject();
		break;
	case USDS_STRING:
		object = stringObjects.addObject();
		break;
	case USDS_ARRAY:
		object = arrayObjects.addObject();
		break;
	case USDS_STRUCT:
		object = structObjects.addObject();
		break;
	}

	if (object == 0)
		throw ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE) << "Unsupported type " << object_type;
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

DictionaryTagLink* DictionaryObjectPool::addTagLink(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryTagLink* object = tagLinkObjects.addObject();
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
	DictionaryBoolean* object = booleanObjects.addObject();
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
	DictionaryInt* object = intObjects.addObject();
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
	DictionaryLong* object = longObjects.addObject();
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
	DictionaryDouble* object = doubleObjects.addObject();
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
	DictionaryUVarint* object = uVarintObjects.addObject();
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
	DictionaryString* object = stringObjects.addObject();
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
	DictionaryArray* object = arrayObjects.addObject();
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
	DictionaryStruct* object = structObjects.addObject();
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

//========================================================================================================
void DictionaryObjectPool::clear()
{
	tagLinkObjects.clearPool();
	booleanObjects.clearPool();
	intObjects.clearPool();
	longObjects.clearPool();
	doubleObjects.clearPool();
	uVarintObjects.clearPool();
	stringObjects.clearPool();
	arrayObjects.clearPool();
	structObjects.clearPool();

};