#include "converters\usdsBodyBinaryParser.h"
#include "base\binary\usdsBinaryInput.h"

#include "body\usdsBody.h"

using namespace usds;

BodyBinaryParser::BodyBinaryParser()
{
	readIndex[USDS_NO_TYPE] = 0;
	readIndex[USDS_BOOLEAN] = &BodyBinaryParser::readBoolean;
	readIndex[USDS_BYTE] = 0;
	readIndex[USDS_UNSIGNED_BYTE] = 0;
	readIndex[USDS_SHORT] = 0;
	readIndex[USDS_UNSIGNED_SHORT] = 0;
	readIndex[USDS_BIGENDIAN_SHORT] = 0;
	readIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	readIndex[USDS_INT] = &BodyBinaryParser::readInt;
	readIndex[USDS_UNSIGNED_INT] = 0;
	readIndex[USDS_BIGENDIAN_INT] = 0;
	readIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	readIndex[USDS_LONG] = &BodyBinaryParser::readLong;
	readIndex[USDS_UNSIGNED_LONG] = 0;
	readIndex[USDS_BIGENDIAN_LONG] = 0;
	readIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	readIndex[USDS_INT128] = 0;
	readIndex[USDS_UNSIGNED_INT128] = 0;
	readIndex[USDS_BIGENDIAN_INT128] = 0;
	readIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	readIndex[USDS_FLOAT] = 0;
	readIndex[USDS_BIGENDIAN_FLOAT] = 0;
	readIndex[USDS_DOUBLE] = &BodyBinaryParser::readDouble;
	readIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	readIndex[USDS_VARINT] = 0;
	readIndex[USDS_UNSIGNED_VARINT] = &BodyBinaryParser::readUVarint;
	readIndex[USDS_ARRAY] = &BodyBinaryParser::readArray;
	readIndex[USDS_STRING] = &BodyBinaryParser::readString;
	readIndex[USDS_LIST] = 0;
	readIndex[USDS_MAP] = 0;
	readIndex[USDS_POLYMORPH] = 0;
	readIndex[USDS_STRUCT] = &BodyBinaryParser::readStruct;
	readIndex[USDS_TAG] = 0;

};

BodyBinaryParser::~BodyBinaryParser()
{


};

void BodyBinaryParser::parse(BinaryInput* buff, Body* body_object) throw (...)
try
{
	usdsBuff = buff;
	body = body_object;

	while (!usdsBuff->isEnd())
	{
		int tag_ID;
		usdsBuff->readUVarint(&tag_ID);
		UsdsBaseType* tag = body->addTag(tag_ID);
		// read specific Tag parameters
		(this->*(readIndex[tag_ID]))(tag);
		tag = tag->getNext();
	}
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyBinaryParser::parse");
	throw err;
};

//=================================================================================================

void BodyBinaryParser::readBoolean(UsdsBaseType* object) throw (...)
try
{
	object->setValue(usdsBuff->readBool());
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyBinaryParser::readBoolean");
	throw err;
};

void BodyBinaryParser::readInt(UsdsBaseType* object) throw (...)
try
{
	object->setValue(usdsBuff->readInt());
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyBinaryParser::readInt");
	throw err;
};

void BodyBinaryParser::readLong(UsdsBaseType* object) throw (...)
try
{
	object->setValue(usdsBuff->readLong());
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyBinaryParser::readLong");
	throw err;
};

void BodyBinaryParser::readDouble(UsdsBaseType* object) throw (...)
try
{
	object->setValue(usdsBuff->readDouble());
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyBinaryParser::readDouble");
	throw err;
};

void BodyBinaryParser::readUVarint(UsdsBaseType* object) throw (...)
try
{
	unsigned long long value;
	usdsBuff->readUVarint(&value);
	object->setValue(value);
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyBinaryParser::readUVarint");
	throw err;
};

void BodyBinaryParser::readArray(UsdsBaseType* object) throw (...)
try
{
	int element_number = ((UsdsArray*)object)->getElementNumber();
	usdsBuff->readUVarint(element_number);
	if (typeSize(((UsdsArray*)object)->getElementType()) != 0)
	{
		UsdsBaseType** objects = (UsdsBaseType**)(((UsdsArray*)object)->getArrayBinary());
		for (int i = 0; i < element_number; i++)
		{
			UsdsBaseType* object = objects[i];
			// read specific object parameters
			(this->*(readIndex[object->getType()]))(object);
		}
	}
	else
	{
		size_t size = ((UsdsArray*)object)->getArrayBinarySize();
		const void* objects = ((UsdsArray*)object)->getArrayBinary();
		usdsBuff->readByteArray(objects, size);
	}
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyBinaryParser::readArray");
	throw err;
};

void BodyBinaryParser::readString(UsdsBaseType* object) throw (...)
try
{
	size_t size;
	const char* text = ((UsdsString*)object)->getStringValue(&size);
	usdsBuff->readUVarint(size);
	usdsBuff->readByteArray(text, size);
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyBinaryParser::readString");
	throw err;
};

void BodyBinaryParser::readStruct(UsdsBaseType* object) throw (...)
try
{
	int field_number = ((UsdsStruct*)object)->getFieldNumber();
	for (int id = 1; id <= field_number; id++)
	{
		UsdsBaseType* field = ((UsdsStruct*)object)->getField(id);
		// read specific Field parameters
		(this->*(readIndex[field->getType()]))(field);
	}
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyBinaryParser::readStruct");
	throw err;
};