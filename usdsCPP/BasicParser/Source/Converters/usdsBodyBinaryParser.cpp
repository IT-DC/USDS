#include "converters\usdsBodyBinaryParser.h"
#include "usdsBinaryInput.h"

#include "body\usdsBody.h"
#include "dictionary\usdsDictionary.h"

using namespace usds;

BodyBinaryParser::BodyBinaryParser()
{
	readIndex[USDS_NO_TYPE] = 0;
	readIndex[USDS_TAG] = &BodyBinaryParser::readTag;
	readIndex[USDS_BOOLEAN] = &BodyBinaryParser::readBoolean;
	readIndex[USDS_BYTE] = &BodyBinaryParser::readByte;
	readIndex[USDS_UBYTE] = &BodyBinaryParser::readUByte;
	readIndex[USDS_SHORT] = &BodyBinaryParser::readShort;
	readIndex[USDS_USHORT] = &BodyBinaryParser::readUShort;
	readIndex[USDS_BIGENDIAN_SHORT] = &BodyBinaryParser::readBEShort;
	readIndex[USDS_BIGENDIAN_USHORT] = &BodyBinaryParser::readBEUShort;
	readIndex[USDS_INT] = &BodyBinaryParser::readInt;
	readIndex[USDS_UINT] = &BodyBinaryParser::readUInt;
	readIndex[USDS_BIGENDIAN_INT] = &BodyBinaryParser::readBEInt;
	readIndex[USDS_BIGENDIAN_UINT] = &BodyBinaryParser::readBEUInt;
	readIndex[USDS_LONG] = &BodyBinaryParser::readLong;
	readIndex[USDS_ULONG] = &BodyBinaryParser::readULong;
	readIndex[USDS_BIGENDIAN_LONG] = &BodyBinaryParser::readBELong;
	readIndex[USDS_BIGENDIAN_ULONG] = &BodyBinaryParser::readBEULong;
	readIndex[USDS_INT128] = &BodyBinaryParser::readInt128;
	readIndex[USDS_UINT128] = &BodyBinaryParser::readUInt128;
	readIndex[USDS_BIGENDIAN_INT128] = &BodyBinaryParser::readBEInt128;
	readIndex[USDS_BIGENDIAN_UINT128] = &BodyBinaryParser::readBEUInt128;
	readIndex[USDS_FLOAT] = &BodyBinaryParser::readFloat;
	readIndex[USDS_BIGENDIAN_FLOAT] = &BodyBinaryParser::readBEFloat;
	readIndex[USDS_DOUBLE] = &BodyBinaryParser::readDouble;
	readIndex[USDS_BIGENDIAN_DOUBLE] = &BodyBinaryParser::readBEDouble;
	readIndex[USDS_VARINT] = &BodyBinaryParser::readVarint;
	readIndex[USDS_UVARINT] = &BodyBinaryParser::readUVarint;
	readIndex[USDS_STRING] = &BodyBinaryParser::readString;
	readIndex[USDS_ARRAY] = &BodyBinaryParser::readArray;
	readIndex[USDS_MAP] = &BodyBinaryParser::readMap;
	readIndex[USDS_POLYARRAY] = &BodyBinaryParser::readPolymorph;
	readIndex[USDS_STRUCT] = &BodyBinaryParser::readStruct;
	readIndex[USDS_FUNCTION] = &BodyBinaryParser::readFunction;

};

BodyBinaryParser::~BodyBinaryParser()
{


};

void BodyBinaryParser::parse(BinaryInput* buff, Dictionary* dict_object, Body* body_object) throw (...)
try
{
	usdsBuff = buff;
	body = body_object;
	dict = dict_object;

	while (!usdsBuff->isEnd())
	{
		int32_t tag_ID;
		usdsBuff->readUVarint(&tag_ID);
		UsdsBaseType* tag = body->addTag(dict->getTag(tag_ID));
		// read specific Tag parameters
		(this->*(readIndex[tag->getType()]))(tag);
		tag = tag->getNext();
	}
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryParser::parse") << (void*)buff << (void*)body_object;
	throw;
};

//=================================================================================================

void BodyBinaryParser::readTag(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readTag") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type TAG for Body Binary Parser");
};

void BodyBinaryParser::readBoolean(UsdsBaseType* object) throw (...)
try
{
	object->setValue(usdsBuff->readBool());
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryParser::readBoolean") << (void*)object;
	throw;
};

void BodyBinaryParser::readByte(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readByte") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type BYTE for Body Binary Parser");
};

void BodyBinaryParser::readUByte(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readUByte") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED BYTE for Body Binary Parser");
};

void BodyBinaryParser::readShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readShort") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type SHORT for Body Binary Parser");
};

void BodyBinaryParser::readUShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readUShort") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED SHORT for Body Binary Parser");
};

void BodyBinaryParser::readBEShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readBEShort") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN SHORT for Body Binary Parser");
};

void BodyBinaryParser::readBEUShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readBEUShort") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED SHORT for Body Binary Parser");
};

void BodyBinaryParser::readInt(UsdsBaseType* object) throw (...)
try
{
	object->setValue(usdsBuff->readInt());
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryParser::readInt") << (void*)object;
	throw;
};

void BodyBinaryParser::readUInt(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readUInt") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT for Body Binary Parser");
};

void BodyBinaryParser::readBEInt(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readBEInt") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN INT for Body Binary Parser");
};

void BodyBinaryParser::readBEUInt(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readBEUInt") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED INT for Body Binary Parser");
};

void BodyBinaryParser::readLong(UsdsBaseType* object) throw (...)
try
{
	object->setValue(usdsBuff->readLong());
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryParser::readLong") << (void*)object;
	throw;
};

void BodyBinaryParser::readULong(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readULong") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED LONG for Body Binary Parser");
};

void BodyBinaryParser::readBELong(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readBELong") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN LONG for Body Binary Parser");
};

void BodyBinaryParser::readBEULong(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readBEULong") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED LONG for Body Binary Parser");
};

void BodyBinaryParser::readInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readInt128") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for Body Binary Parser");
};

void BodyBinaryParser::readUInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readUInt128") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for Body Binary Parser");
};

void BodyBinaryParser::readBEInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readBEInt128") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN INT128 for Body Binary Parser");
};

void BodyBinaryParser::readBEUInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readBEUInt128") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED INT128 for Body Binary Parser");
};

void BodyBinaryParser::readFloat(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readFloat") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type FLOAT for Body Binary Parser");
};

void BodyBinaryParser::readBEFloat(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readBEFloat") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN FLOAT for Body Binary Parser");
};

void BodyBinaryParser::readDouble(UsdsBaseType* object) throw (...)
try
{
	object->setValue(usdsBuff->readDouble());
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryParser::readDouble") << (void*)object;
	throw;
};

void BodyBinaryParser::readBEDouble(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readBEDouble") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN DOUBLE for Body Binary Parser");
};

void BodyBinaryParser::readVarint(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readVarint") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type VARINT for Body Binary Parser");
};

void BodyBinaryParser::readUVarint(UsdsBaseType* object) throw (...)
try
{
	uint64_t value;
	usdsBuff->readUVarint(&value);
	object->setValue(value);
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryParser::readUVarint") << (void*)object;
	throw;
};

void BodyBinaryParser::readString(UsdsBaseType* object) throw (...)
try
{
	size_t size;
	usdsBuff->readUVarint(&size);
	const char* text = (const char*)usdsBuff->readByteArray(size);
	((UsdsString*)object)->setValue(text, size);
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryParser::readString") << (void*)object;
	throw;
};

void BodyBinaryParser::readArray(UsdsBaseType* object) throw (...)
try
{
	size_t element_number;
	usdsBuff->readUVarint(&element_number);
	int32_t element_size = usdsTypeSize(((UsdsArray*)object)->getElementType());
	
	if (element_size == 0)
	{
		for (size_t i = 0; i < element_number; i++)
		{
			UsdsBaseType* element = ((UsdsArray*)object)->pushElementBack();
			// read specific object parameters
			(this->*(readIndex[element->getType()]))(element);
		}
	}
	else
	{
		size_t binary_size = element_number * element_size;
		const void* elements = usdsBuff->readByteArray(binary_size);
		//((UsdsArray*)object)->setArrayBinary(elements, binary_size);
	}
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryParser::readArray") << (void*)object;
	throw;
};

void BodyBinaryParser::readMap(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readMap") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type MAP for Body Binary Parser");
};

void BodyBinaryParser::readPolymorph(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readPolymorph") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type POLYMORPH for Body Binary Parser");
};

void BodyBinaryParser::readStruct(UsdsBaseType* object) throw (...)
try
{
	int32_t field_number = ((UsdsStruct*)object)->getFieldNumber();
	for (int32_t id = 1; id <= field_number; id++)
	{
		UsdsBaseType* field = ((UsdsStruct*)object)->getField(id);
		// read specific Field parameters
		(this->*(readIndex[field->getType()]))(field);
	}
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryParser::readStruct") << (void*)object;
	throw;
};

void BodyBinaryParser::readFunction(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryParser::readFunction") << (void*)object << ErrorMessage(BODY_BINARY_PARSER__UNSUPPORTED_TYPE, "Unsupported type FUNCTION for Body Binary Parser");
};
