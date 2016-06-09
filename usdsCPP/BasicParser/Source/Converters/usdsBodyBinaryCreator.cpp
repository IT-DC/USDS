#include "converters\usdsBodyBinaryCreator.h"

#include "body\usdsBody.h"

using namespace usds;

BodyBinaryCreator::BodyBinaryCreator()
{
	writeIndex[USDS_NO_TYPE] = 0;
	writeIndex[USDS_TAG] = &BodyBinaryCreator::writeTag;
	writeIndex[USDS_BOOLEAN] = &BodyBinaryCreator::writeBoolean;
	writeIndex[USDS_BYTE] = &BodyBinaryCreator::writeByte;
	writeIndex[USDS_UNSIGNED_BYTE] = &BodyBinaryCreator::writeUByte;
	writeIndex[USDS_SHORT] = &BodyBinaryCreator::writeShort;
	writeIndex[USDS_UNSIGNED_SHORT] = &BodyBinaryCreator::writeUShort;
	writeIndex[USDS_BIGENDIAN_SHORT] = &BodyBinaryCreator::writeBEShort;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = &BodyBinaryCreator::writeBEUShort;
	writeIndex[USDS_INT] = &BodyBinaryCreator::writeInt;
	writeIndex[USDS_UNSIGNED_INT] = &BodyBinaryCreator::writeUInt;
	writeIndex[USDS_BIGENDIAN_INT] = &BodyBinaryCreator::writeBEInt;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT] = &BodyBinaryCreator::writeBEUInt;
	writeIndex[USDS_LONG] = &BodyBinaryCreator::writeLong;
	writeIndex[USDS_UNSIGNED_LONG] = &BodyBinaryCreator::writeULong;
	writeIndex[USDS_BIGENDIAN_LONG] = &BodyBinaryCreator::writeBELong;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = &BodyBinaryCreator::writeBEULong;
	writeIndex[USDS_INT128] = &BodyBinaryCreator::writeInt128;
	writeIndex[USDS_UNSIGNED_INT128] = &BodyBinaryCreator::writeUInt128;
	writeIndex[USDS_BIGENDIAN_INT128] = &BodyBinaryCreator::writeBEInt128;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = &BodyBinaryCreator::writeBEUInt128;
	writeIndex[USDS_FLOAT] = &BodyBinaryCreator::writeFloat;
	writeIndex[USDS_BIGENDIAN_FLOAT] = &BodyBinaryCreator::writeBEFloat;
	writeIndex[USDS_DOUBLE] = &BodyBinaryCreator::writeDouble;
	writeIndex[USDS_USDS_BIGENDIAN_DOUBLE] = &BodyBinaryCreator::writeBEDouble;
	writeIndex[USDS_VARINT] = &BodyBinaryCreator::writeVarint;
	writeIndex[USDS_UNSIGNED_VARINT] = &BodyBinaryCreator::writeUVarint;
	writeIndex[USDS_STRING] = &BodyBinaryCreator::writeString;
	writeIndex[USDS_ARRAY] = &BodyBinaryCreator::writeArray;
	writeIndex[USDS_LIST] = &BodyBinaryCreator::writeList;
	writeIndex[USDS_MAP] = &BodyBinaryCreator::writeMap;
	writeIndex[USDS_POLYMORPH] = &BodyBinaryCreator::writePolymorph;
	writeIndex[USDS_STRUCT] = &BodyBinaryCreator::writeStruct;
	writeIndex[USDS_FUNCTION] = &BodyBinaryCreator::writeFunction;

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
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryCreator::generate") << (void*)buff << (void*)body;
	throw;
};

//=================================================================================================

void BodyBinaryCreator::writeTag(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeTag") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type TAG for Binary Creator");
};

void BodyBinaryCreator::writeBoolean(UsdsBaseType* object) throw (...)
try
{
	usdsBuff->writeBool(((UsdsBoolean*)object)->getBooleanValue());
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryCreator::writeBoolean") << (void*)object;
	throw;
};

void BodyBinaryCreator::writeByte(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeByte") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BYTE for Binary Creator");
};

void BodyBinaryCreator::writeUByte(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeUByte") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED BYTE for Binary Creator");
};

void BodyBinaryCreator::writeShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeShort") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type SHORT for Binary Creator");
};

void BodyBinaryCreator::writeUShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeUShort") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED SHORT for Binary Creator");
};

void BodyBinaryCreator::writeBEShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeBEShort") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN SHORT for Binary Creator");
};

void BodyBinaryCreator::writeBEUShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeBEUShort") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED SHORT for Binary Creator");
};

void BodyBinaryCreator::writeInt(UsdsBaseType* object) throw (...)
try
{
	usdsBuff->writeInt(((UsdsInt*)object)->getValue<int32_t>());
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryCreator::writeInt") << (void*)object;
	throw;
};

void BodyBinaryCreator::writeUInt(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeUInt") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT for Binary Creator");
};

void BodyBinaryCreator::writeBEInt(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeBEInt") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN INT for Binary Creator");
};

void BodyBinaryCreator::writeBEUInt(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeBEUInt") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED INT for Binary Creator");
};

void BodyBinaryCreator::writeLong(UsdsBaseType* object) throw (...)
try
{
	usdsBuff->writeLong(((UsdsLong*)object)->getLongValue());
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryCreator::writeLong") << (void*)object;
	throw;
};

void BodyBinaryCreator::writeULong(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeULong") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED LONG for Binary Creator");
};

void BodyBinaryCreator::writeBELong(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeBELong") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN LONG for Binary Creator");
};

void BodyBinaryCreator::writeBEULong(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeBEULong") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED LONG for Binary Creator");
};

void BodyBinaryCreator::writeInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeInt128") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for Binary Creator");
};

void BodyBinaryCreator::writeUInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeUInt128") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for Binary Creator");
};

void BodyBinaryCreator::writeBEInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeBEInt128") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN INT128 for Binary Creator");
};

void BodyBinaryCreator::writeBEUInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeBEUInt128") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED INT128 for Binary Creator");
};

void BodyBinaryCreator::writeFloat(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeFloat") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type FLOAT for Binary Creator");
};

void BodyBinaryCreator::writeBEFloat(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeBEFloat") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN FLOAT for Binary Creator");
};

void BodyBinaryCreator::writeDouble(UsdsBaseType* object) throw (...)
try
{
	usdsBuff->writeDouble(((UsdsDouble*)object)->getDoubleValue());
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryCreator::writeDouble") << (void*)object;
	throw;
};

void BodyBinaryCreator::writeBEDouble(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeBEDouble") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN DOUBLE for Binary Creator");
};

void BodyBinaryCreator::writeVarint(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeVarint") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type VARINT for Binary Creator");
};

void BodyBinaryCreator::writeUVarint(UsdsBaseType* object) throw (...)
try
{
	usdsBuff->writeUVarint(((UsdsUVarint*)object)->getULongValue());
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryCreator::writeUVarint") << (void*)object;
	throw;
};

void BodyBinaryCreator::writeString(UsdsBaseType* object) throw (...)
try
{
	size_t size;
	const char* text = ((UsdsString*)object)->getStringValue(&size);
	usdsBuff->writeUVarint(size);
	usdsBuff->writeByteArray(text, size);
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryCreator::writeString") << (void*)object;
	throw;
};

void BodyBinaryCreator::writeArray(UsdsBaseType* object) throw (...)
try
{
	int32_t element_number = ((UsdsArray*)object)->size();
	usdsBuff->writeUVarint(element_number);
	if (typeSize(((UsdsArray*)object)->getElementType()) == 0)
	{
		UsdsBaseType** objects = (UsdsBaseType**)(((UsdsArray*)object)->getArrayBinary());
		for (int32_t i = 0; i < element_number; i++)
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
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryCreator::writeArray") << (void*)object;
	throw;
};

void BodyBinaryCreator::writeList(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeList") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type LIST for Binary Creator");
};

void BodyBinaryCreator::writeMap(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeMap") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type MAP for Binary Creator");
};

void BodyBinaryCreator::writePolymorph(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writePolymorph") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type POLYMORPH for Binary Creator");
};

void BodyBinaryCreator::writeStruct(UsdsBaseType* object) throw (...)
try
{
	int32_t field_number = ((UsdsStruct*)object)->getFieldNumber();
	for (int32_t id = 1; id <= field_number; id++)
	{
		UsdsBaseType* field = ((UsdsStruct*)object)->getField(id);
		// write specific Field parameters
		(this->*(writeIndex[field->getType()]))(field);
	}
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryCreator::writeStruct") << (void*)object;
	throw;
};

void BodyBinaryCreator::writeFunction(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeFunction") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type FUNCTION for Binary Creator");
};
