#include "body\dataTypes\usdsStruct.h"

#include "dictionary\dataTypes\dictionaryStruct.h"
#include "base\objectPool\bodyObjectPool.h"

using namespace usds;

UsdsStruct::UsdsStruct(BodyObjectPool* object_pool) : UsdsBaseType(object_pool)
{
	fieldsBuffSize = 16;
	fields = new UsdsBaseType*[fieldsBuffSize+1];
	fieldNumber = 0;

	objectType = USDS_STRUCT;
};

UsdsStruct::~UsdsStruct()
{
	delete[] fields;

};

//================================================================================================

void UsdsStruct::setFieldValue(const char* name, int value) throw (...)
try
{
	int id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
	{
		std::stringstream msg;
		msg << "Field '" << name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	fields[id]->setValue(value);

}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(const char*,int)");
	throw msg;
};

void UsdsStruct::setFieldValue(const char* name, long long value) throw (...)
try
{
	int id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
	{
		std::stringstream msg;
		msg << "Field '" << name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	fields[id]->setValue(value);

}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(const char*,long long)");
	throw msg;
};

void UsdsStruct::setFieldValue(const char* name, double value) throw (...)
try
{
	int id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
	{
		std::stringstream msg;
		msg << "Field '" << name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	fields[id]->setValue(value);

}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(const char*,double)");
	throw msg;
};

void UsdsStruct::setFieldValue(const char* name, const char* value) throw (...)
try
{
	int id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
	{
		std::stringstream msg;
		msg << "Field '" << name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	fields[id]->setValue(value);

}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(const char*,const char*)");
	throw msg;
};

void UsdsStruct::setFieldValue(const char* name, bool value) throw (...)
try
{
	int id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
	{
		std::stringstream msg;
		msg << "Field '" << name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	fields[id]->setValue(value);

}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(const char*,bool)");
	throw msg;
};

//================================================================================================

void UsdsStruct::setFieldValue(int id, int value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
	{
		std::stringstream msg;
		msg << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	fields[id]->setValue(value);
}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(int,int)");
	throw msg;
};

void UsdsStruct::setFieldValue(int id, long long value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
	{
		std::stringstream msg;
		msg << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	fields[id]->setValue(value);
}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(int,long long)");
	throw msg;
};

void UsdsStruct::setFieldValue(int id, double value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
	{
		std::stringstream msg;
		msg << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	fields[id]->setValue(value);
}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(int,double)");
	throw msg;
};

void UsdsStruct::setFieldValue(int id, const char* value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
	{
		std::stringstream msg;
		msg << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	fields[id]->setValue(value);
}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(int,const char*)");
	throw msg;
};

void UsdsStruct::setFieldValue(int id, bool value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
	{
		std::stringstream msg;
		msg << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	fields[id]->setValue(value);
}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(int,bool)");
	throw msg;
};

//================================================================================================

void UsdsStruct::getFieldValue(const char* name, int* value) throw (...)
try
{
	int id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
	{
		std::stringstream msg;
		msg << "Field '" << name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}

	*value = fields[id]->getIntValue();
}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::getFieldValue(const char*,int*)");
	throw msg;
};

void UsdsStruct::getFieldValue(const char* name, long long* value) throw (...)
try
{
	int id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
	{
		std::stringstream msg;
		msg << "Field '" << name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	*value = fields[id]->getLongValue();

}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(const char*,long long)");
	throw msg;
};

void UsdsStruct::getFieldValue(const char* name, double* value) throw (...)
try
{
	int id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
	{
		std::stringstream msg;
		msg << "Field '" << name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	*value = fields[id]->getDoubleValue();

}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(const char*,double)");
	throw msg;
};

void UsdsStruct::getFieldValue(const char* name, const char** value) throw (...)
try
{
	int id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
	{
		std::stringstream msg;
		msg << "Field '" << name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	*value = fields[id]->getStringValue();

}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(const char*,const char*)");
	throw msg;
};

void UsdsStruct::getFieldValue(const char* name, bool* value) throw (...)
try
{
	int id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
	{
		std::stringstream msg;
		msg << "Field '" << name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	*value = fields[id]->getBooleanValue();

}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(const char*,bool)");
	throw msg;
};

//================================================================================================

void UsdsStruct::getFieldValue(int id, int* value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
	{
		std::stringstream msg;
		msg << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	*value = fields[id]->getIntValue();
}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(int,int)");
	throw msg;
};

void UsdsStruct::getFieldValue(int id, long long* value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
	{
		std::stringstream msg;
		msg << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	*value = fields[id]->getLongValue();
}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(int,long long)");
	throw msg;
};

void UsdsStruct::getFieldValue(int id, double* value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
	{
		std::stringstream msg;
		msg << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	*value = fields[id]->getDoubleValue();
}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(int,double)");
	throw msg;
};

void UsdsStruct::getFieldValue(int id, const char** value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
	{
		std::stringstream msg;
		msg << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	*value = fields[id]->getStringValue();
}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(int,const char*)");
	throw msg;
};

void UsdsStruct::getFieldValue(int id, bool* value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
	{
		std::stringstream msg;
		msg << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	*value = fields[id]->getBooleanValue();
}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(int,bool)");
	throw msg;
};

//================================================================================================

UsdsBaseType* UsdsStruct::getField(int id) throw (...)
{
	if (id < 1 || id > fieldNumber)
	{
		std::stringstream msg;
		msg << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg, L"UsdsStruct::getField");
	}

	return fields[id];
};


UsdsArray* UsdsStruct::getArrayField(const char* name) throw (...)
try
{
	int id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
	{
		std::stringstream msg;
		msg << "Field '" << name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	if (fields[id]->getType() != USDS_ARRAY)
	{
		std::stringstream msg;
		msg << "Field id=" << id << " must be Array. Current type: " << fields[id]->getTypeName();
		throw ErrorMessage(BODY_STRUCT_TAG_ERROR_FIELD_TYPE, &msg);
	}
	return (UsdsArray*)(fields[id]);
}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::getArrayField(int)");
	throw msg;
};

UsdsArray* UsdsStruct::getArrayField(int id) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
	{
		std::stringstream msg;
		msg << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
		throw ErrorMessage(BODY_STRUCT_TAG_FIELD_NOT_FOUND, &msg);
	}
	if (fields[id]->getType() != USDS_ARRAY)
	{
		std::stringstream msg;
		msg << "Field id=" << id << " must be Array. Current type: " << fields[id]->getTypeName();
		throw ErrorMessage(BODY_STRUCT_TAG_ERROR_FIELD_TYPE, &msg);
	}
	return (UsdsArray*)(fields[id]);
}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::getArrayField(int)");
	throw msg;
};

//================================================================================================

int UsdsStruct::getFieldNumber() throw (...)
{

	return fieldNumber;
};


//================================================================================================

void UsdsStruct::clear()
{
	fieldNumber = ((DictionaryStruct*)parentDictionaryObject)->getFieldNumber();
	
	if (fieldNumber > fieldsBuffSize)
	{
		delete[] fields;
		fieldsBuffSize = fieldNumber;
		fields = new UsdsBaseType*[fieldsBuffSize+1];
	}

	// create clear fields
	for (int id = 1; id <= fieldNumber; id++)
	{
		DictionaryBaseType* field = ((DictionaryStruct*)parentDictionaryObject)->getField(id);
		fields[id] = objectPool->addObject(field, this);
	}

};