#include "converters\usdsDictionaryBinaryCreator.h"
#include "dictionary\usdsDictionary.h"
#include "binary\usdsBinaryOutput.h"

#include "usdsErrors.h"
#include "usdsTypes.h"

#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryString.h"
#include "dictionary\dataTypes\dictionaryUVarint.h"
#include "dictionary\dataTypes\dictionaryStruct.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"

using namespace usds;

DictionaryBinaryCreator::DictionaryBinaryCreator() 
{
	writeIndex[USDS_TAG] = &DictionaryBinaryCreator::writeTag;
	writeIndex[USDS_BOOLEAN] = &DictionaryBinaryCreator::writeBoolean;
	writeIndex[USDS_BYTE] = &DictionaryBinaryCreator::writeByte;
	writeIndex[USDS_UBYTE] = &DictionaryBinaryCreator::writeUByte;
	writeIndex[USDS_SHORT] = &DictionaryBinaryCreator::writeShort;
	writeIndex[USDS_USHORT] = &DictionaryBinaryCreator::writeUShort;
	writeIndex[USDS_INT] = &DictionaryBinaryCreator::writeInt;
	writeIndex[USDS_UINT] = &DictionaryBinaryCreator::writeUInt;
	writeIndex[USDS_LONG] = &DictionaryBinaryCreator::writeLong;
	writeIndex[USDS_ULONG] = &DictionaryBinaryCreator::writeULong;
	writeIndex[USDS_INT128] = &DictionaryBinaryCreator::writeInt128;
	writeIndex[USDS_UINT128] = &DictionaryBinaryCreator::writeUInt128;
	writeIndex[USDS_FLOAT] = &DictionaryBinaryCreator::writeFloat;
	writeIndex[USDS_DOUBLE] = &DictionaryBinaryCreator::writeDouble;
	writeIndex[USDS_VARINT] = &DictionaryBinaryCreator::writeVarint;
	writeIndex[USDS_UVARINT] = &DictionaryBinaryCreator::writeUVarint;
	writeIndex[USDS_STRING] = &DictionaryBinaryCreator::writeString;
	writeIndex[USDS_ARRAY] = &DictionaryBinaryCreator::writeArray;
	writeIndex[USDS_STRUCT] = &DictionaryBinaryCreator::writeStruct;
	writeIndex[USDS_GUID] = &DictionaryBinaryCreator::writeGuid;
	writeIndex[USDS_MAP] = &DictionaryBinaryCreator::writeMap;
	writeIndex[USDS_DATE] = &DictionaryBinaryCreator::writeDate;
	writeIndex[USDS_TIME] = &DictionaryBinaryCreator::writeTime;
	writeIndex[USDS_DATETIME] = &DictionaryBinaryCreator::writeDateTime;
	writeIndex[USDS_FUNCTION] = &DictionaryBinaryCreator::writeFunction;

};

DictionaryBinaryCreator::~DictionaryBinaryCreator() { };

void DictionaryBinaryCreator::generate(BinaryOutput* buff, Dictionary* dict) throw (...)
try
{
	outBuffer = buff;

	// Write tags
	for (int32_t id = 1; id <= dict->getTagNumber(); id++)
	{
		outBuffer->writeSignature(USDS_TAG_SIGNATURE);
		DictionaryBaseType* tag = dict->getTag(id);
		outBuffer->writeUVarint(tag->getID());
		size_t size = tag->getNameSize();
		outBuffer->writeUVarint(size);
		outBuffer->writeByteArray((void*)tag->getName(), size);
		outBuffer->writeType(tag->getType());
		// write specific Tag parameters
		(this->*(writeIndex[tag->getType()]))(tag);
	}
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryBinaryCreator::generate") << (void*)buff << (void*)dict;
	throw;
};

//=======================================================================================================

void DictionaryBinaryCreator::writeTag(DictionaryBaseType* object) throw (...)
{
	outBuffer->writeUVarint(((DictionaryTagLink*)object)->getTag()->getID());
};

void DictionaryBinaryCreator::writeBoolean(DictionaryBaseType* object) throw (...)
{

	
};

void DictionaryBinaryCreator::writeByte(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeByte") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BYTE for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeUByte(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeUByte") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED BYTE for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeShort(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeShort") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type SHORT for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeUShort(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeUShort") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED SHORT for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeInt(DictionaryBaseType* object) throw (...)
{

	
};

void DictionaryBinaryCreator::writeUInt(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeUInt") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeLong(DictionaryBaseType* object) throw (...)
{

	
};

void DictionaryBinaryCreator::writeULong(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeULong") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED LONG for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeInt128(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeInt128") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeUInt128(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeUInt128") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeFloat(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeFloat") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type FLOAT for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeDouble(DictionaryBaseType* object) throw (...)
{

	
};

void DictionaryBinaryCreator::writeVarint(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeVarint") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type VARINT for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeUVarint(DictionaryBaseType* object) throw (...)
{

	
};

void DictionaryBinaryCreator::writeString(DictionaryBaseType* object) throw (...)
try
{
	outBuffer->writeEncode(((DictionaryString*)object)->getDefaultEncode());

}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryBinaryCreator::writeString") << (void*)object;
	throw;
};

void DictionaryBinaryCreator::writeArray(DictionaryBaseType* object) throw (...)
try
{
	DictionaryBaseType* element = ((DictionaryArray*)object)->getElement();
	usdsTypes element_type = element->getType();
	
	outBuffer->writeType(element_type);
	(this->*(writeIndex[element_type]))(element);
	
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryBinaryCreator::writeArray") << (void*)object << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryBinaryCreator::writeArray") << (void*)object;
	throw;
};

void DictionaryBinaryCreator::writeMap(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeMap") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type MAP for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeStruct(DictionaryBaseType* object) throw (...)
try
{
	//write fields
	int32_t fieldNumber = ((DictionaryStruct*)object)->getFieldNumber();
	for (int32_t id = 1; id <= fieldNumber; id++)
	{
		DictionaryBaseType* field = ((DictionaryStruct*)object)->getField(id);
		outBuffer->writeSignature(USDS_FIELD_SIGNATURE);
		outBuffer->writeUVarint(field->getID());
		size_t size = field->getNameSize();
		outBuffer->writeUVarint(size);
		outBuffer->writeByteArray((void*)field->getName(), size);
		outBuffer->writeType(field->getType());
		// write specific Field parameters
		(this->*(writeIndex[field->getType()]))(field);
	}

	// write tag restrictions
	if (!object->getRootStatus())
	{
		outBuffer->writeSignature(USDS_TAG_RESTRICTION_SIGNATURE);
		outBuffer->writeSignature(USDS_TAG_RESTRICTION_NOT_ROOT_SIGNATURE); // == root is false
	}

}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryBinaryCreator::writeStruct") << (void*)object;
	throw;
};

void DictionaryBinaryCreator::writeFunction(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeFunction") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type FUNCTION for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeGuid(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeGuid") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type GUID for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeDate(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeDate") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type DATE for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeTime(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeTime") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type TIME for Dictionary Binary Creator");
};

void DictionaryBinaryCreator::writeDateTime(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryCreator::writeDateTime") << (void*)object << ErrorMessage(DIC_BINARY_CREATOR__UNSUPPORTED_TYPE, "Unsupported type DATETIME for Dictionary Binary Creator");
};

