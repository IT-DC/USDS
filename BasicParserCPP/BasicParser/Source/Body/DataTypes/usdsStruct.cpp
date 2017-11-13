#include "body\dataTypes\usdsStruct.h"

#include "dictionary\dataTypes\dictionaryStruct.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"
#include "dictionary\dataTypes\dictionaryPolymorph.h"
#include "body\usdsBody.h"

#include "body/dataTypes/usdsEnum.h"

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

void UsdsStruct::setValue(const char* field_name, int32_t value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setValue") << field_name << value;
	throw;
};

void UsdsStruct::setValue(const char* field_name, int64_t value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setValue") << field_name << value;
	throw;
};

void UsdsStruct::setValue(const char* field_name, double value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setValue") << field_name << value;
	throw;
};

void UsdsStruct::setValue(const char* field_name, usdsEncode encode, const char* value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";
	
	if (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->getType() != USDS_STRING)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << field_name << "' is not STRING";
	
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
	throw ErrorStack("UsdsStruct::setValue") << field_name << encode << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setValue") << field_name << encode << value;
	throw;
};

void UsdsStruct::setFromUTF8(const char* field_name, const char* value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	switch (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->getType())
	{
	case USDS_STRING:
		if (fields[field_id] == 0)
			fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

		((UsdsString*)fields[field_id])->setFromUTF8(value);
		break;

	case USDS_ENUM:
		if (fields[field_id] == 0)
			fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

		((UsdsEnum*)fields[field_id])->setFromUTF8(value);
		break;

	default:
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << field_name << "' is not STRING or ENUM";
	};

	return;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFromUTF8") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFromUTF8") << field_name << value;
	throw;
};

void UsdsStruct::setFromUTF8(const char* field_name, const char* value, size_t byte_size) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	switch (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->getType())
	{
	case USDS_STRING:
		if (fields[field_id] == 0)
			fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

		((UsdsString*)fields[field_id])->setFromUTF8(value, byte_size);
		break;
	
	case USDS_ENUM:
		if (fields[field_id] == 0)
			fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

		((UsdsEnum*)fields[field_id])->setFromUTF8(value, byte_size);
		break;

	default:
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << field_name << "' is not STRING or ENUM";
	};

	return;
}
catch (ErrorMessage& msg)
{
	throw (ErrorStack("UsdsStruct::setFromUTF8") << field_name).addStringAndSize(value, byte_size) << msg;
}
catch (ErrorStack& err)
{
	(err.addLevel("UsdsStruct::setFromUTF8") << field_name).addStringAndSize(value, byte_size);
	throw;
};


void UsdsStruct::setValue(const char* field_name, bool value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";
	
	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setValue") << field_name << value;
	throw;
};

//================================================================================================

void UsdsStruct::setValue(int32_t field_id, int32_t value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setValue") << field_id << value;
	throw;
};

void UsdsStruct::setValue(int32_t field_id, int64_t value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setValue") << field_id << value;
	throw;
};

void UsdsStruct::setValue(int32_t field_id, double value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;
	
	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setValue") << field_id << value;
	throw;
};

void UsdsStruct::setValue(int32_t field_id, usdsEncode encode, const char* value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;
	if (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->getType() != USDS_STRING)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << field_id << "' is not STRING";

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
	throw ErrorStack("UsdsStruct::setValue") << field_id << encode << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setValue") << field_id << encode << value;
	throw;
};


void UsdsStruct::setValue(int32_t field_id, bool value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	if (fields[field_id] == 0)
		fields[field_id] = parentBody->addField(((DictionaryStruct*)parentDictionaryObject)->getField(field_id), this);

	fields[field_id]->setValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setValue") << field_id << value;
	throw;
};

//================================================================================================

void UsdsStruct::getValue(const char* field_name, int32_t* value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field '" << field_name << "' is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getValue") << field_name << value;
	throw;
};

void UsdsStruct::getValue(const char* field_name, int64_t* value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field '" << field_name << "' is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getValue") << field_name << value;
	throw;
};

void UsdsStruct::getValue(const char* field_name, double* value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field '" << field_name << "' is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getValue") << field_name << value;
	throw;
};

void UsdsStruct::getValue(const char* field_name, usdsEncode encode, const char** value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	if (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->getType() != USDS_STRING)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << field_name << "' is not STRING";

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
	throw ErrorStack("UsdsStruct::getValue") << field_name << encode << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getValue") << field_name << encode << value;
	throw;
};

void UsdsStruct::getValue(const char* field_name, bool* value) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << getName() << "'";

	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field '" << field_name << "' is NULL";

	fields[field_id]->getValue(value);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getValue") << field_name << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getValue") << field_name << value;
	throw;
};

//================================================================================================

void UsdsStruct::getValue(int32_t field_id, int32_t* value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field " << field_id << " is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getValue") << field_id << value;
	throw;
};

void UsdsStruct::getValue(int32_t field_id, int64_t* value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field " << field_id << " is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getValue") << field_id << value;
	throw;
};

void UsdsStruct::getValue(int32_t field_id, double* value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field " << field_id << " is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getValue") << field_id << value;
	throw;
};

void UsdsStruct::getValue(int32_t field_id, usdsEncode encode, const char** value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;
	if (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->getType() != USDS_STRING)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field '" << field_id << "' is not STRING";

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
	throw ErrorStack("UsdsStruct::getValue") << field_id << encode << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getValue") << field_id << encode << value;
	throw;
};

void UsdsStruct::getValue(int32_t field_id, bool* value) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	if (fields[field_id] == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_IS_NULL) << "Field " << field_id << " is NULL";

	fields[field_id]->getValue(value);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::getValue") << field_id << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::getValue") << field_id << value;
	throw;
};
//================================================================================================

UsdsBaseType* UsdsStruct::getField(int32_t field_id) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

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
	fieldNumber = ((DictionaryStruct*)parentDictionaryObject)->getFieldNumbers();
	
	// All fields initially are NULL
	if (fieldNumber > fieldsBuffSize)
	{
		delete[] fields;
		fieldsBuffSize = fieldNumber;
		fields = new UsdsBaseType*[fieldsBuffSize+1];
	}
	for (int32_t field_id = 1; field_id <= fieldNumber; field_id++)
	{
		DictionaryBaseType* dict_field = ((DictionaryStruct*)parentDictionaryObject)->getField(field_id);
		if (dict_field->hasDefaultValue())
			fields[field_id] = parentBody->addField(dict_field, this);
		else
			fields[field_id] = 0;
	}


};

//================================================================================================

void UsdsStruct::setNull(const char* field_name) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";;
	
	UsdsBaseType* body_field = fields[field_id];

	if (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->isNullable() != true)
		throw ErrorMessage(BODY_STRUCT__NOT_NULLABLE_FIELD) << "Field '" << field_name << "' is not nullable";

	if (body_field == 0)
		return;

	// Maybe it also have to remove struct fields, array element ets
	body_field->remove();
	fields[field_id] = 0;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setNull") << field_name << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setNull") << field_name;
	throw;
};

void UsdsStruct::setNull(int32_t field_id) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;
	
	UsdsBaseType* body_field = fields[field_id];

	if (((DictionaryStruct*)parentDictionaryObject)->getField(field_id)->isNullable() != true)
		throw ErrorMessage(BODY_STRUCT__NOT_NULLABLE_FIELD) << "Field " << field_id << " is not nullable";

	if (body_field == 0)
		return;

	// Maybe it also have to remove struct fields, array element ets
	body_field->remove();
	fields[field_id] = 0;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setNull") << field_id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setNull") << field_id;
	throw;
};

bool UsdsStruct::isNull(const char* field_name) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";;
	return (fields[field_id] == 0);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::isNull") << field_name << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::isNull") << field_name;
	throw;
};

bool UsdsStruct::isNull(int32_t field_id) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;
	return (fields[field_id] == 0);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::isNull") << field_id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::isNull") << field_id;
	throw;
};

//================================================================================================

UsdsArray* UsdsStruct::addArray(int32_t field_id) throw (...)
try
{
	if (field_id < 1 || field_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id must be in range [1, " << fieldNumber << "], current valu: " << field_id;

	DictionaryBaseType* dict_field = ((DictionaryStruct*)parentDictionaryObject)->getField(field_id);
	if (dict_field->getType() == USDS_TAG)
		dict_field = ((DictionaryTagLink*)dict_field)->getTag();

	if (dict_field->getType() != USDS_ARRAY)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field type id=" << field_id << " is not ARRAY";

	if (fields[field_id] != 0)
		// Maybe it also have to remove struct fields, array element ets
		fields[field_id]->remove();

	fields[field_id] = parentBody->addField(dict_field, this);

	return (UsdsArray*)fields[field_id];
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::addArray") << field_id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::addArray") << field_id;
	throw;
};

UsdsArray* UsdsStruct::addArray(const char* field_name) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(field_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << field_name << "' is not found in the tag '" << ((DictionaryStruct*)parentDictionaryObject)->getName() << "'";

	DictionaryBaseType* dict_field = ((DictionaryStruct*)parentDictionaryObject)->getField(field_id);
	if (dict_field->getType() == USDS_TAG)
		dict_field = ((DictionaryTagLink*)dict_field)->getTag();
	
	if (dict_field->getType() != USDS_ARRAY)
		throw ErrorMessage(BODY_STRUCT__ERROR_FIELD_TYPE) << "Field type id=" << field_id << " is not ARRAY";

	if (fields[field_id] != 0)
		// Maybe it also have to remove struct fields, array element ets
		fields[field_id]->remove();

	fields[field_id] = parentBody->addField(dict_field, this);

	return (UsdsArray*)fields[field_id];
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::addArray") << field_name << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::addArray") << field_name;
	throw;
};

UsdsStruct* UsdsStruct::addStruct(int32_t polyfield_id, int32_t tag_id) throw (...)
try
{
	if (polyfield_id < 1 || polyfield_id > fieldNumber)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id=" << polyfield_id << " is not found in the tag '" << getName() << "'";

	DictionaryBaseType* dict_poly_field = ((DictionaryStruct*)parentDictionaryObject)->getField(polyfield_id);
	if (dict_poly_field->getType() != USDS_POLYMORPH)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field id=" << polyfield_id << " is not POLYMORPH";

	DictionaryBaseType* dict_field = ((DictionaryPolymorph*)dict_poly_field)->getSubStruct(tag_id);

	if (fields[polyfield_id] != 0)
		fields[polyfield_id]->remove();

	fields[polyfield_id] = parentBody->addField(dict_field, this);

	return (UsdsStruct*)fields[polyfield_id];

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldSubtag") << polyfield_id << tag_id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldSubtag") << polyfield_id << tag_id;
	throw;
};



UsdsStruct* UsdsStruct::addStruct(const char* polyfield_name, const char* tag_name) throw (...)
try
{
	int32_t field_id = ((DictionaryStruct*)parentDictionaryObject)->findFieldID(polyfield_name);
	if (field_id == 0)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << polyfield_name << "' is not found in the tag '" << getName() << "'";

	DictionaryBaseType* dict_poly_field = ((DictionaryStruct*)parentDictionaryObject)->getField(field_id);
	if (dict_poly_field->getType() != USDS_POLYMORPH)
		throw ErrorMessage(BODY_STRUCT__FIELD_NOT_FOUND) << "Field '" << polyfield_name << "' is not POLYMORPH";

	DictionaryBaseType* dict_field = ((DictionaryPolymorph*)dict_poly_field)->getSubStruct(tag_name);
	
	if (fields[field_id] != 0)
		fields[field_id]->remove();
		
	fields[field_id] = parentBody->addField(dict_field, this);

	return (UsdsStruct*)fields[field_id];

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsStruct::setFieldSubtag") << polyfield_name << tag_name << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsStruct::setFieldSubtag") << polyfield_name << tag_name;
	throw;
};



