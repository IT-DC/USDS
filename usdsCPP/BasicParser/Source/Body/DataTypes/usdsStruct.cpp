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

void UsdsStruct::setFieldValue(const char* field_name, int32_t value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	// for nullable fields
	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << field_name << value;
	throw;
};

void UsdsStruct::setFieldValue(const char* field_name, int64_t value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	// for nullable fields
	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << field_name << value;
	throw;
};

void UsdsStruct::setFieldValue(const char* field_name, double value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	// for nullable fields
	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << field_name << value;
	throw;
};

void UsdsStruct::setFieldValue(const char* field_name, usdsEncodes encode, const char* value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";
	
	if (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->getType() != USDS_STRING)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << field_name << "' is not STRING";
	
	// for nullable fields
	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	switch (encode)
	{
	case USDS_UTF8:
	{
		((UsdsString*)fields[field_id])->setFromUTF8(value);
		return;
	}
	default:
		throw ErrorMessage(BODY_STRING__UNSUPPORTED_ENCODE) << "Unsupported encode for STRING: " << encode;
	}
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << field_name << encode << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << field_name << encode << value;
	throw;
};

void UsdsStruct::setFieldValue(const char* field_name, bool value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";
	// for nullable fields
	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << field_name << value;
	throw;
};

//================================================================================================

void UsdsStruct::setFieldValue(int32_t field_id, int32_t value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	// for nullable fields
	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << field_id << value;
	throw;
};

void UsdsStruct::setFieldValue(int32_t field_id, int64_t value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	// for nullable fields
	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << field_id << value;
	throw;
};

void UsdsStruct::setFieldValue(int32_t field_id, double value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;
	
	// for nullable fields
	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << field_id << value;
	throw;
};

void UsdsStruct::setFieldValue(int32_t field_id, usdsEncodes encode, const char* value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;
	if (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->getType() != USDS_STRING)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << field_id << "' is not STRING";

	// for nullable fields
	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	switch (encode)
	{
	case USDS_UTF8:
	{
		((UsdsString*)fields[field_id])->setFromUTF8(value);
		return;
	}
	default:
		throw ErrorMessage(BODY_STRING__UNSUPPORTED_ENCODE) << "Unsupported encode for STRING: " << encode;
	}
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << field_id << encode << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << field_id << encode << value;
	throw;
};


void UsdsStruct::setFieldValue(int32_t field_id, bool value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	// for nullable fields
	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldValue") << field_id << value;
	throw;
};

//================================================================================================

void UsdsStruct::getFieldValue(const char* field_name, int32_t* value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	// for nullable fields
	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field '" << field_name << "' is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << field_name << value;
	throw;
};

void UsdsStruct::getFieldValue(const char* field_name, int64_t* value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	// for nullable fields
	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field '" << field_name << "' is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << field_name << value;
	throw;
};

void UsdsStruct::getFieldValue(const char* field_name, double* value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	// for nullable fields
	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field '" << field_name << "' is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << field_name << value;
	throw;
};

void UsdsStruct::getFieldValue(const char* field_name, usdsEncodes encode, const char** value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	if (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->getType() != USDS_STRING)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << field_name << "' is not STRING";

	// for nullable fields
	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field '" << field_name << "' is NULL";

	switch (encode)
	{
	case USDS_UTF8:
	{
		*value = ((UsdsString*)fields[field_id])->getUTF8Value();
		return;
	}
	default:
		throw ErrorMessage(BODY_STRING__UNSUPPORTED_ENCODE) << "Unsupported encode for STRING: " << encode;
	}
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << field_name << encode << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << field_name << encode << value;
	throw;
};

void UsdsStruct::getFieldValue(const char* field_name, bool* value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	// for nullable fields
	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field '" << field_name << "' is NULL";

	fields[field_id]->getValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << field_name << value;
	throw;
};

//================================================================================================

void UsdsStruct::getFieldValue(int32_t field_id, int32_t* value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	// for nullable fields
	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field " << field_id << " is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << field_id << value;
	throw;
};

void UsdsStruct::getFieldValue(int32_t field_id, int64_t* value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	// for nullable fields
	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field " << field_id << " is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << field_id << value;
	throw;
};

void UsdsStruct::getFieldValue(int32_t field_id, double* value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	// for nullable fields
	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field " << field_id << " is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << field_id << value;
	throw;
};

void UsdsStruct::getFieldValue(int32_t field_id, usdsEncodes encode, const char** value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;
	if (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->getType() != USDS_STRING)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << field_id << "' is not STRING";

	// for nullable fields
	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field " << field_id << " is NULL";

	switch (encode)
	{
	case USDS_UTF8:
	{
		*value = ((UsdsString*)fields[field_id])->getUTF8Value();
		return;
	}
	default:
		throw ErrorMessage(BODY_STRING__UNSUPPORTED_ENCODE) << "Unsupported encode for STRING: " << encode;
	}
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << field_id << encode << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << field_id << encode << value;
	throw;
};

void UsdsStruct::getFieldValue(int32_t field_id, bool* value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	// for nullable fields
	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field " << field_id << " is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getFieldValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getFieldValue") << field_id << value;
	throw;
};
//================================================================================================

UsdsBaseType* UsdsStruct::getField(int32_t field_id) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	// for nullable fields
	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field " << field_id << " is NULL";

	return fields[field_id];
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getField") << field_id << msg;
};

UsdsBaseType* UsdsStruct::getField(const char* field_name) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";

	// for nullable fields
	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field '" << field_name << "' is NULL";

	return fields[field_id];
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getField") << field_name << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getField") << field_name;
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
	for (int32_t field_id = 1; field_id <= fieldNumber; field_id++)
	{
		DictionaryBaseType* dict_field = ((DictionaryStruct*)parentDictionaryObject)->getField(field_id);
		if (dict_field->isNullable() == false)
			fields[field_id] = parentBody->addField(dict_field, this);
		else
			fields[field_id] = 0;
	}

};

//================================================================================================

void UsdsStruct::setFieldAsNull(const char* field_name) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";;
	UsdsBaseType* body_field = fields[field_id];

	if (body_field == 0)
		return;
	if (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->isNullable() != true)
		throw ErrorMessage(BODY_STRUCT__NOT_NULLABLE_FIELD) << "Field '" << field_name << "' is not nullable";

	body_field->remove();
	fields[field_id] = 0;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldAsNull") << field_name << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldAsNull") << field_name;
	throw;
};

void UsdsStruct::setFieldAsNull(int32_t field_id) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;
	UsdsBaseType* body_field = fields[field_id];

	if (body_field == 0)
		return;
	if (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->isNullable() != true)
		throw ErrorMessage(BODY_STRUCT__NOT_NULLABLE_FIELD) << "Field " << field_id << " is not nullable";

	body_field->remove();
	fields[field_id] = 0;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldAsNull") << field_id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldAsNull") << field_id;
	throw;
};

bool UsdsStruct::isNullValue(const char* field_name) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";;
	return (fields[field_id] == 0);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::isNullValue") << field_name << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::isNullValue") << field_name;
	throw;
};

bool UsdsStruct::isNullValue(int32_t field_id) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;
	return (fields[field_id] == 0);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::isNullValue") << field_id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::isNullValue") << field_id;
	throw;
};


