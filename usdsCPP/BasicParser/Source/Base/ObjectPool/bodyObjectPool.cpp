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


BodyObjectPool::BodyObjectPool(Body* parent_body) 
{
	pools[USDS_NO_TYPE] = 0;
	pools[USDS_TAG] = 0;
	pools[USDS_BOOLEAN] = new TemplateObjectPool<UsdsBoolean, Body>(parent_body);
	pools[USDS_BYTE] = 0;
	pools[USDS_UNSIGNED_BYTE] = 0;
	pools[USDS_SHORT] = 0;
	pools[USDS_UNSIGNED_SHORT] = 0;
	pools[USDS_BIGENDIAN_SHORT] = 0;
	pools[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	pools[USDS_INT] = new TemplateObjectPool<UsdsInt, Body>(parent_body);
	pools[USDS_UNSIGNED_INT] = 0;
	pools[USDS_BIGENDIAN_INT] = 0;
	pools[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	pools[USDS_LONG] = new TemplateObjectPool<UsdsLong, Body>(parent_body);
	pools[USDS_UNSIGNED_LONG] = 0;
	pools[USDS_BIGENDIAN_LONG] = 0;
	pools[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	pools[USDS_INT128] = 0;
	pools[USDS_UNSIGNED_INT128] = 0;
	pools[USDS_BIGENDIAN_INT128] = 0;
	pools[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	pools[USDS_FLOAT] = 0;
	pools[USDS_BIGENDIAN_FLOAT] = 0;
	pools[USDS_DOUBLE] = new TemplateObjectPool<UsdsDouble, Body>(parent_body);
	pools[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	pools[USDS_VARINT] = 0;
	pools[USDS_UNSIGNED_VARINT] = new TemplateObjectPool<UsdsUVarint, Body>(parent_body);
	pools[USDS_STRING] = new TemplateObjectPool<UsdsString, Body>(parent_body);
	pools[USDS_ARRAY] = new TemplateObjectPool<UsdsArray, Body>(parent_body);
	pools[USDS_LIST] = 0;
	pools[USDS_MAP] = 0;
	pools[USDS_POLYMORPH] = 0;
	pools[USDS_STRUCT] = new TemplateObjectPool<UsdsStruct, Body>(parent_body);
	pools[USDS_FUNCTION] = 0;


}

BodyObjectPool::~BodyObjectPool()
{
	for (int32_t i = 0; i < USDS_LAST_TYPE; i++)
	{
		if (pools[i] != 0)
			delete(pools[i]);
	}
}

UsdsBaseType* BodyObjectPool::addObject(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	if (dict_parent==0)
		throw ErrorMessage(BODY_OBJECT_POOL__NULL_DICTIONARY_TAG, "Dictionary parent tag can not be NULL");
	
	usdsTypes object_type = dict_parent->getType();

	if (object_type <= USDS_NO_TYPE || object_type >= USDS_LAST_TYPE)
		throw ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE) << "Unsupported type " << object_type;
	// TODO: remove it when all type is ready
	if (pools[object_type] == 0)
		throw ErrorMessage(BODY_OBJECT_POOL__UNSUPPORTED_TYPE) << "Unsupported type " << typeName(object_type);


	UsdsBaseType*object = (UsdsBaseType*)(pools[object_type])->addObject();
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

/*
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
*/
//===============================================================================================================================

void BodyObjectPool::clear()
{
	for (int32_t i = 0; i < USDS_LAST_TYPE; i++)
	{
		if (pools[i] != 0)
			pools[i]->clearPool();
	}

};
