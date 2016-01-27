#include "base\objectPool\bodyObjectPool.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"
#include "body\dataTypes\usdsArray.h"
#include "body\dataTypes\usdsBoolean.h"
#include "body\dataTypes\usdsDouble.h"
#include "body\dataTypes\usdsInt.h"
#include "body\dataTypes\usdsLong.h"
#include "body\dataTypes\usdsString.h"
#include "body\dataTypes\usdsStruct.h"
#include "body\dataTypes\usdsUVarint.h"

using namespace usds;


BodyObjectPool::BodyObjectPool(Body* parent_body) :
	booleanObjects(parent_body),
	intObjects(parent_body),
	longObjects(parent_body),
	doubleObjects(parent_body),
	uVarintObjects(parent_body),
	arrayObjects(parent_body),
	stringObjects(parent_body),
	structObjects(parent_body)
{
	
}

BodyObjectPool::~BodyObjectPool()
{

}

UsdsBaseType* BodyObjectPool::addObject(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	if (dict_parent==0)
		throw ErrorMessage(BODY_OBJECT_POOL__NULL_DICTIONARY_TAG, "Dictionary parent tag can not be NULL");
	
	usdsTypes object_type = dict_parent->getType();

	UsdsBaseType*object = 0;
	switch (object_type)
	{
	case USDS_BOOLEAN:
		object = (UsdsBaseType*)booleanObjects.addObject();
		break;
	case USDS_INT:
		object = (UsdsBaseType*)intObjects.addObject();
		break;
	case USDS_LONG:
		object = (UsdsBaseType*)longObjects.addObject();
		break;
	case USDS_DOUBLE:
		object = (UsdsBaseType*)doubleObjects.addObject();
		break;
	case USDS_UNSIGNED_VARINT:
		object = (UsdsBaseType*)uVarintObjects.addObject();
		break;
	case USDS_STRING:
		object = (UsdsBaseType*)stringObjects.addObject();
		break;
	case USDS_ARRAY:
		object = (UsdsBaseType*)arrayObjects.addObject();
		break;
	case USDS_STRUCT:
		object = (UsdsBaseType*)structObjects.addObject();
		break;
	}
	if (object == 0)
		throw ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE) << "Unsupported type " << typeName(object_type);

	try
	{
		object->init(dict_parent, body_parent);
	}
	catch (ErrorStack)
	{
		object->remove();
		throw;
	}

	return object;
}
catch (ErrorMessage&msg)
{
	throw ErrorStack("BodyObjectPool::addObject") << (void*)dict_parent << (void*)body_parent << msg;

}
catch (ErrorStack& err)
{
	err.addLevel("BodyObjectPool::addObject") << (void*)dict_parent << (void*)body_parent;
	throw;
};

//===============================================================================================================================

UsdsBoolean* BodyObjectPool::addBoolean(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsBoolean* object = (UsdsBoolean*)booleanObjects.addObject();
	try
	{
		object->init(dict_parent, body_parent);
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
	err.addLevel("BodyObjectPool::addBoolean") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsInt* BodyObjectPool::addInt(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsInt* object = (UsdsInt*)intObjects.addObject();
	try
	{
		object->init(dict_parent, body_parent);
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
	err.addLevel("BodyObjectPool::addInt") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsLong* BodyObjectPool::addLong(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsLong* object = (UsdsLong*)longObjects.addObject();
	try
	{
		object->init(dict_parent, body_parent);
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
	err.addLevel("BodyObjectPool::addLong") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsDouble* BodyObjectPool::addDouble(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsDouble* object = (UsdsDouble*)doubleObjects.addObject();
	try
	{
		object->init(dict_parent, body_parent);
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
	err.addLevel("BodyObjectPool::addDouble") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsUVarint* BodyObjectPool::addUVarint(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsUVarint* object = (UsdsUVarint*)uVarintObjects.addObject();
	try
	{
		object->init(dict_parent, body_parent);
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
	err.addLevel("BodyObjectPool::addUVarint") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsString* BodyObjectPool::addString(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsString* object = (UsdsString*)stringObjects.addObject();
	try
	{
		object->init(dict_parent, body_parent);
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
	err.addLevel("BodyObjectPool::addString") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsArray* BodyObjectPool::addArray(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsArray* object = (UsdsArray*)arrayObjects.addObject();
	try
	{
		object->init(dict_parent, body_parent);
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
	err.addLevel("BodyObjectPool::addArray") << (void*)dict_parent << (void*)body_parent;
	throw;
};

UsdsStruct* BodyObjectPool::addStruct(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	UsdsStruct* object = (UsdsStruct*)structObjects.addObject();
	try
	{
		object->init(dict_parent, body_parent);
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
	err.addLevel("BodyObjectPool::addStruct") << (void*)dict_parent << (void*)body_parent;
	throw;
};

//===============================================================================================================================

void BodyObjectPool::clear()
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
