#include "converters\usdsBodyBinaryCreator.h"

#include "body\usdsBody.h"

using namespace usds;

BodyBinaryCreator::BodyBinaryCreator()
{
	writeIndex[USDS_NO_TYPE] = 0;
	writeIndex[USDS_TAG] = &BodyBinaryCreator::writeTag;
	writeIndex[USDS_BOOLEAN] = &BodyBinaryCreator::writeBoolean;
	writeIndex[USDS_BYTE] = &BodyBinaryCreator::writeByte;
	writeIndex[USDS_UBYTE] = &BodyBinaryCreator::writeUByte;
	writeIndex[USDS_SHORT] = &BodyBinaryCreator::writeShort;
	writeIndex[USDS_USHORT] = &BodyBinaryCreator::writeUShort;
	writeIndex[USDS_INT] = &BodyBinaryCreator::writeInt;
	writeIndex[USDS_UINT] = &BodyBinaryCreator::writeUInt;
	writeIndex[USDS_LONG] = &BodyBinaryCreator::writeLong;
	writeIndex[USDS_ULONG] = &BodyBinaryCreator::writeULong;
	writeIndex[USDS_INT128] = &BodyBinaryCreator::writeInt128;
	writeIndex[USDS_UINT128] = &BodyBinaryCreator::writeUInt128;
	writeIndex[USDS_FLOAT] = &BodyBinaryCreator::writeFloat;
	writeIndex[USDS_DOUBLE] = &BodyBinaryCreator::writeDouble;
	writeIndex[USDS_VARINT] = &BodyBinaryCreator::writeVarint;
	writeIndex[USDS_UVARINT] = &BodyBinaryCreator::writeUVarint;
	writeIndex[USDS_STRING] = &BodyBinaryCreator::writeString;
	writeIndex[USDS_ARRAY] = &BodyBinaryCreator::writeArray;
	writeIndex[USDS_MAP] = &BodyBinaryCreator::writeMap;
	writeIndex[USDS_POLYARRAY] = &BodyBinaryCreator::writePolymorph;
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
	usdsBuff->writeBoolean(((UsdsBoolean*)object)->get());
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

void BodyBinaryCreator::writeLong(UsdsBaseType* object) throw (...)
try
{
	usdsBuff->writeLong(((UsdsLong*)object)->get());
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

void BodyBinaryCreator::writeInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeInt128") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for Binary Creator");
};

void BodyBinaryCreator::writeUInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeUInt128") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for Binary Creator");
};

void BodyBinaryCreator::writeFloat(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeFloat") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type FLOAT for Binary Creator");
};

void BodyBinaryCreator::writeDouble(UsdsBaseType* object) throw (...)
try
{
	usdsBuff->writeDouble(((UsdsDouble*)object)->get());
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryCreator::writeDouble") << (void*)object;
	throw;
};

void BodyBinaryCreator::writeVarint(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyBinaryCreator::writeVarint") << (void*)object << ErrorMessage(BODY_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type VARINT for Binary Creator");
};

void BodyBinaryCreator::writeUVarint(UsdsBaseType* object) throw (...)
try
{
	usdsBuff->writeUVarint(((UsdsUVarint*)object)->get());
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryCreator::writeUVarint") << (void*)object;
	throw;
};

void BodyBinaryCreator::writeString(UsdsBaseType* object) throw (...)
try
{
	size_t size = ((UsdsString*)object)->getByteSize();
	const uint8_t* text = ((UsdsString*)object)->getByteValue();
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
	size_t element_number = ((UsdsArray*)object)->getSize();
	usdsBuff->writeUVarint(element_number);
	/*if (usdsTypeSize(((UsdsArray*)object)->getElementType()) == 0)
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
	}*/
}
catch (ErrorStack& err)
{
	err.addLevel("BodyBinaryCreator::writeArray") << (void*)object;
	throw;
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
	int32_t field_number = ((UsdsStruct*)object)->getFieldsNumber();
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
