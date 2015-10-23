#include "converters\usdsBodyBinaryCreator.h"

#include "body\usdsBody.h"

using namespace usds;

BodyBinaryCreator::BodyBinaryCreator()
{
	writeIndex[USDS_NO_TYPE] = 0;
	writeIndex[USDS_BOOLEAN] = &BodyBinaryCreator::writeBoolean;
	writeIndex[USDS_BYTE] = 0;
	writeIndex[USDS_UNSIGNED_BYTE] = 0;
	writeIndex[USDS_SHORT] = 0;
	writeIndex[USDS_UNSIGNED_SHORT] = 0;
	writeIndex[USDS_BIGENDIAN_SHORT] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	writeIndex[USDS_INT] = &BodyBinaryCreator::writeInt;
	writeIndex[USDS_UNSIGNED_INT] = 0;
	writeIndex[USDS_BIGENDIAN_INT] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	writeIndex[USDS_LONG] = &BodyBinaryCreator::writeLong;
	writeIndex[USDS_UNSIGNED_LONG] = 0;
	writeIndex[USDS_BIGENDIAN_LONG] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	writeIndex[USDS_INT128] = 0;
	writeIndex[USDS_UNSIGNED_INT128] = 0;
	writeIndex[USDS_BIGENDIAN_INT128] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	writeIndex[USDS_FLOAT] = 0;
	writeIndex[USDS_BIGENDIAN_FLOAT] = 0;
	writeIndex[USDS_DOUBLE] = &BodyBinaryCreator::writeDouble;
	writeIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	writeIndex[USDS_VARINT] = 0;
	writeIndex[USDS_UNSIGNED_VARINT] = &BodyBinaryCreator::writeUVarint;
	writeIndex[USDS_ARRAY] = &BodyBinaryCreator::writeArray;
	writeIndex[USDS_STRING] = &BodyBinaryCreator::writeString;
	writeIndex[USDS_LIST] = 0;
	writeIndex[USDS_MAP] = 0;
	writeIndex[USDS_POLYMORPH] = 0;
	writeIndex[USDS_STRUCT] = &BodyBinaryCreator::writeStruct;
	writeIndex[USDS_TAG] = 0;

};

BodyBinaryCreator::~BodyBinaryCreator()
{


};

void BodyBinaryCreator::generate(BinaryOutput* buff, Body* body) throw (...)
try
{

	usdsBuff = buff;

	UsdsBaseType* tag = body->getFirstTag();
	while (tag != 0)
	{
		usdsBuff->writeUVarint(tag->getID());
		// write specific Tag parameters
		(this->*(writeIndex[tag->getType()]))(tag);
		tag = tag->getNext();
	}
}
catch (ErrorMessage& err)
{
	err.addPath(L"DictionaryTextCreator::generate");
	throw err;
};

//=================================================================================================

void BodyBinaryCreator::writeBoolean(UsdsBaseType* object) throw (...)
try
{
	usdsBuff->writeBool(((UsdsBoolean*)object)->getBooleanValue());
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeBoolean");
	throw err;
};

void BodyBinaryCreator::writeInt(UsdsBaseType* object) throw (...)
try
{
	usdsBuff->writeInt(((UsdsInt*)object)->getIntValue());
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeInt");
	throw err;
};

void BodyBinaryCreator::writeLong(UsdsBaseType* object) throw (...)
try
{
	usdsBuff->writeLong(((UsdsLong*)object)->getLongValue());
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeLong");
	throw err;
};

void BodyBinaryCreator::writeDouble(UsdsBaseType* object) throw (...)
try
{
	usdsBuff->writeDouble(((UsdsDouble*)object)->getDoubleValue());
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeDouble");
	throw err;
};

void BodyBinaryCreator::writeUVarint(UsdsBaseType* object) throw (...)
try
{
	usdsBuff->writeUVarint(((UsdsUVarint*)object)->getULongValue());
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeUVarint");
	throw err;
};

void BodyBinaryCreator::writeArray(UsdsBaseType* object) throw (...)
try
{
	int element_number = ((UsdsArray*)object)->getElementNumber();
	usdsBuff->writeUVarint(element_number);
	if (typeSize(((UsdsArray*)object)->getElementType()) != 0)
	{
		UsdsBaseType** objects = (UsdsBaseType**)(((UsdsArray*)object)->getArrayBinary());
		for (int i = 0; i < element_number; i++)
		{
			UsdsBaseType* object = objects[i];
			// write specific object parameters
			(this->*(writeIndex[object->getType()]))(object);
		}
	}
	else
	{
		size_t size = ((UsdsArray*)object)->getArrayBinarySize();
		const void* objects = ((UsdsArray*)object)->getArrayBinary();
		usdsBuff->writeByteArray(objects, size);
	}
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeArray");
	throw err;
};

void BodyBinaryCreator::writeString(UsdsBaseType* object) throw (...)
try
{
	size_t size;
	const char* text = ((UsdsString*)object)->getStringValue(&size);
	usdsBuff->writeUVarint(size);
	usdsBuff->writeByteArray(text, size);
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeString");
	throw err;
};

void BodyBinaryCreator::writeStruct(UsdsBaseType* object) throw (...)
try
{
	int field_number = ((UsdsStruct*)object)->getFieldNumber();
	for (int id = 1; id <= field_number; id++)
	{
		UsdsBaseType* field = ((UsdsStruct*)object)->getField(id);
		// write specific Field parameters
		(this->*(writeIndex[field->getType()]))(field);
	}
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeStruct");
	throw err;
};