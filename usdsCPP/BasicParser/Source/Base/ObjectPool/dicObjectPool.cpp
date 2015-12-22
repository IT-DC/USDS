#include "base\objectPool\dicObjectPool.h"

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

DictionaryObjectPool::DictionaryObjectPool() :
	booleanObjects(this),
	intObjects(this),
	longObjects(this),
	doubleObjects(this),
	uVarintObjects(this),
	arrayObjects(this),
	stringObjects(this),
	structObjects(this)
{

};

DictionaryObjectPool::~DictionaryObjectPool()
{

};

DictionaryBaseType* DictionaryObjectPool::addObject(usdsTypes object_type, Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	if (object_type <= USDS_NO_TYPE || object_type >= USDS_LAST_TYPE)
		throw ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE) << "Unsupported type " << object_type;

	DictionaryBaseType* object = 0;

	switch (object_type)
	{
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
		throw ErrorMessage(DIC_OBJECT_POOL__UNSUPPORTED_TYPE) << "Unsupported type " << typeName(object_type);
	try
	{
		object->init(dict, parent, id, name, name_size);
	}
	catch (...)
	{
		object->remove();
		throw;
	}
	
	return object;

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryObjectPool::addObject") << (void*)object_type << (void*)dict << (void*)parent << id << name << name_size << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryObjectPool::addObject") << (void*)object_type << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

//========================================================================================================

DictionaryBoolean* DictionaryObjectPool::addBoolean(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryBoolean* object = booleanObjects.addObject();
	try
	{
		object->init(dict, parent, id, name, name_size);
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
	err.addLevel("DictionaryObjectPool::addBoolean") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryInt* DictionaryObjectPool::addInt(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryInt* object = intObjects.addObject();
	try
	{
		object->init(dict, parent, id, name, name_size);
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
	err.addLevel("DictionaryObjectPool::addInt") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryLong* DictionaryObjectPool::addLong(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryLong* object = longObjects.addObject();
	try
	{
		object->init(dict, parent, id, name, name_size);
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
	err.addLevel("DictionaryObjectPool::addLong") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};


DictionaryDouble* DictionaryObjectPool::addDouble(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryDouble* object = doubleObjects.addObject();
	try
	{
		object->init(dict, parent, id, name, name_size);
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
	err.addLevel("DictionaryObjectPool::addDouble") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryUVarint* DictionaryObjectPool::addUVarint(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryUVarint* object = uVarintObjects.addObject();
	try
	{
		object->init(dict, parent, id, name, name_size);
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
	err.addLevel("DictionaryObjectPool::addUVarint") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryString* DictionaryObjectPool::addString(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryString* object = stringObjects.addObject();
	try
	{
		object->init(dict, parent, id, name, name_size);
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
	err.addLevel("DictionaryObjectPool::addString") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryArray* DictionaryObjectPool::addArray(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryArray* object = arrayObjects.addObject();
	try
	{
		object->init(dict, parent, id, name, name_size);
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
	err.addLevel("DictionaryObjectPool::addArray") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

DictionaryStruct* DictionaryObjectPool::addStruct(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
try
{
	DictionaryStruct* object = structObjects.addObject();
	try
	{
		object->init(dict, parent, id, name, name_size);
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
	err.addLevel("DictionaryObjectPool::addStruct") << (void*)dict << (void*)parent << id << name << name_size;
	throw;
};

//========================================================================================================
void DictionaryObjectPool::clear()
{
	booleanObjects.clearPool();
	intObjects.clearPool();
	longObjects.clearPool();
	doubleObjects.clearPool();
	uVarintObjects.clearPool();
	stringObjects.clearPool();
	arrayObjects.clearPool();
	structObjects.clearPool();

};