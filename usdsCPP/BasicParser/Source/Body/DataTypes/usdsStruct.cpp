#include "body\dataTypes\usdsStruct.h"

#include "dictionary\dataTypes\dictionaryStruct.h"
#include "base\objectPool\bodyObjectPool.h"

using namespace usds;

UsdsStruct::UsdsStruct(BodyObjectPool* object_pool) : UsdsBaseType(object_pool)
{
	oneValueSize = 16;
	valueBuffSize = 16 * oneValueSize;
	fieldValues = new unsigned char[valueBuffSize];
	fieldNumber = 0;
};

UsdsStruct::~UsdsStruct()
{
	delete[] fieldValues;

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
	setFieldValue(id, value);

}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsStruct::setFieldValue(const char*,int)");
	throw msg;
};

void UsdsStruct::setFieldValue(const char* name, long long value) throw (...)
{


};
void UsdsStruct::setFieldValue(const char* name, double value) throw (...)
{


};
void UsdsStruct::setFieldValue(const char* name, const char* value) throw (...)
{


};
void UsdsStruct::setFieldValue(const char* name, bool value) throw (...)
{


};

//================================================================================================

void UsdsStruct::setFieldValue(int id, int value) throw (...)
{
	


};
void UsdsStruct::setFieldValue(int id, long long value) throw (...)
{


};
void UsdsStruct::setFieldValue(int id, double value) throw (...)
{


};
void UsdsStruct::setFieldValue(int id, const char* value) throw (...)
{


};
void UsdsStruct::setFieldValue(int id, bool value) throw (...)
{


};

//================================================================================================

UsdsArray* UsdsStruct::getArrayField(const char* name) throw (...)
{

	return 0;
};

//================================================================================================

void UsdsStruct::clear()
{
	fieldNumber = ((DictionaryStruct*)parentDictionaryObject)->getFieldNumber();
	
	if ((fieldNumber * oneValueSize) > valueBuffSize)
	{
		delete[] fieldValues;
		valueBuffSize = fieldNumber * oneValueSize;
		fieldValues = new unsigned char[valueBuffSize];
	}

	unsigned char* values = fieldValues;

	// create clear fields
	for (int id = 1; id <= fieldNumber; id++)
	{
		DictionaryBaseType* field = ((DictionaryStruct*)parentDictionaryObject)->getField(id);
		if (typeSize(field->getType())==0)
			*((UsdsBaseType**)(&fieldValues)) = objectPool->addObject(field, this);

		values += oneValueSize;
	}

};