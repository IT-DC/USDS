#include "body\dataTypes\usdsStruct.h"

#include "dictionary\dataTypes\dictionaryStruct.h"
#include "body\usdsBody.h"

using namespace usds;

UsdsStruct::UsdsStruct(Body* parent_body) : UsdsBaseType(parent_body)
{
	fieldsBuffSize = 16;
	fields = new UsdsBaseType*[fieldsBuffSize+1];
	fieldNumber = 0;

};

UsdsStruct::~UsdsStruct()
{
	delete[] fields;

};

//================================================================================================

void UsdsStruct::setFieldValue(const char* name, int32_t value) throw (...)
try
{
	int32_t id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << name << "' is not found in the tag '" << getName() << "'";
	fields[id]->setValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << name << value;
	throw;
};

void UsdsStruct::setFieldValue(const char* name, int64_t value) throw (...)
try
{
	int32_t id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << name << "' is not found in the tag '" << getName() << "'";
	fields[id]->setValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << name << value;
	throw;
};

void UsdsStruct::setFieldValue(const char* name, double value) throw (...)
try
{
	int32_t id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << name << "' is not found in the tag '" << getName() << "'";
	fields[id]->setValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << name << value;
	throw;
};

void UsdsStruct::setFieldValue(const char* name, usdsEncodes encode, const char* value) throw (...)
try
{
	int32_t id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << name << "' is not found in the tag '" << getName() << "'";
	if (fields[id]->getType() != USDS_STRING)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << name << "' is not STRING";

	switch (encode)
	{
	case USDS_UTF8:
	{
		((UsdsString*)fields[id])->setFromUTF8(value);
		return;
	}
	default:
		throw ErrorMessage(BODY_STRING__UNSUPPORTED_ENCODE) << "Unsupported encode for STRING: " << encode;
	}
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << name << encode << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << name << encode << value;
	throw;
};

void UsdsStruct::setFieldValue(const char* name, bool value) throw (...)
try
{
	int32_t id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << name << "' is not found in the tag '" << getName() << "'";
	fields[id]->setValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << name << value;
	throw;
};

//================================================================================================

void UsdsStruct::setFieldValue(int32_t id, int32_t value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
	fields[id]->setValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << id << value;
	throw;
};

void UsdsStruct::setFieldValue(int32_t id, int64_t value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
	fields[id]->setValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << id << value;
	throw;
};

void UsdsStruct::setFieldValue(int32_t id, double value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
	fields[id]->setValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << id << value;
	throw;
};

void UsdsStruct::setFieldValue(int32_t id, usdsEncodes encode, const char* value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
	if (fields[id]->getType() != USDS_STRING)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << id << "' is not STRING";

	switch (encode)
	{
	case USDS_UTF8:
	{
		((UsdsString*)fields[id])->setFromUTF8(value);
		return;
	}
	default:
		throw ErrorMessage(BODY_STRING__UNSUPPORTED_ENCODE) << "Unsupported encode for STRING: " << encode;
	}
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << id << encode << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << id << encode << value;
	throw;
};


void UsdsStruct::setFieldValue(int32_t id, bool value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
	fields[id]->setValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << id << value;
	throw;
};

//================================================================================================

void UsdsStruct::getFieldValue(const char* name, int32_t* value) throw (...)
try
{
	int32_t id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << name << "' is not found in the tag '" << getName() << "'";

	fields[id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << name << value;
	throw;
};

void UsdsStruct::getFieldValue(const char* name, int64_t* value) throw (...)
try
{
	int32_t id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << name << "' is not found in the tag '" << getName() << "'";

	fields[id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << name << value;
	throw;
};

void UsdsStruct::getFieldValue(const char* name, double* value) throw (...)
try
{
	int32_t id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << name << "' is not found in the tag '" << getName() << "'";
	fields[id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << name << value;
	throw;
};

void UsdsStruct::getFieldValue(const char* name, usdsEncodes encode, const char** value) throw (...)
try
{
	int32_t id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << name << "' is not found in the tag '" << getName() << "'";
	if (fields[id]->getType() != USDS_STRING)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << name << "' is not STRING";

	switch (encode)
	{
	case USDS_UTF8:
	{
		*value = ((UsdsString*)fields[id])->getUTF8Value();
		return;
	}
	default:
		throw ErrorMessage(BODY_STRING__UNSUPPORTED_ENCODE) << "Unsupported encode for STRING: " << encode;
	}
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << name << encode << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << name << encode << value;
	throw;
};

void UsdsStruct::getFieldValue(const char* name, bool* value) throw (...)
try
{
	int32_t id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << name << "' is not found in the tag '" << getName() << "'";
	fields[id]->getValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << name << value;
	throw;
};

//================================================================================================

void UsdsStruct::getFieldValue(int32_t id, int32_t* value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
	fields[id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << id << value;
	throw;
};

void UsdsStruct::getFieldValue(int32_t id, int64_t* value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
	fields[id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << id << value;
	throw;
};

void UsdsStruct::getFieldValue(int32_t id, double* value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
	fields[id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << id << value;
	throw;
};

void UsdsStruct::getFieldValue(int32_t id, usdsEncodes encode, const char** value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
	if (fields[id]->getType() != USDS_STRING)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << id << "' is not STRING";

	switch (encode)
	{
	case USDS_UTF8:
	{
		*value = ((UsdsString*)fields[id])->getUTF8Value();
		return;
	}
	default:
		throw ErrorMessage(BODY_STRING__UNSUPPORTED_ENCODE) << "Unsupported encode for STRING: " << encode;
	}
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << id << encode << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << id << encode << value;
	throw;
};

void UsdsStruct::getFieldValue(int32_t id, bool* value) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;
	fields[id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << id << value;
	throw;
};
//================================================================================================

UsdsBaseType* UsdsStruct::getField(int32_t id) throw (...)
try
{
	if (id < 1 || id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << id;

	return fields[id];
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getField") << id << msg;
};

UsdsBaseType* UsdsStruct::getField(const char* name) throw (...)
try
{
	int32_t id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(name);
	if (id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";;
	return fields[id];
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getField") << name << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getField") << name;
	throw;
};

//================================================================================================

int32_t UsdsStruct::getFieldsNumber() throw (...)
{

	return fieldNumber;
};


//================================================================================================

void UsdsStruct::additionalInitObject()
{
	fieldNumber = ((DictionaryStruct*)parentDictionaryObject)->getFieldNumber();
	
	if (fieldNumber > fieldsBuffSize)
	{
		delete[] fields;
		fieldsBuffSize = fieldNumber;
		fields = new UsdsBaseType*[fieldsBuffSize+1];
	}

	// create clear fields
	for (int32_t id = 1; id <= fieldNumber; id++)
	{
		DictionaryBaseType* field = ((DictionaryStruct*)parentDictionaryObject)->getField(id);
		fields[id] = parentBody->addField(field, this);
	}

};