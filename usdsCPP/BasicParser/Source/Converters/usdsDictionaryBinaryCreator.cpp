#include "converters\usdsDictionaryBinaryCreator.h"
#include "dictionary\usdsDictionary.h"
#include "base\binary\usdsBinaryOutput.h"

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"

#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryString.h"
#include "dictionary\dataTypes\dictionaryUVarint.h"
#include "dictionary\dataTypes\dictionaryStruct.h"

using namespace usds;

DictionaryBinaryCreator::DictionaryBinaryCreator() 
{
	writeIndex[USDS_NO_TYPE] = 0;
	writeIndex[USDS_BOOLEAN] = &DictionaryBinaryCreator::writeBoolean;
	writeIndex[USDS_BYTE] = 0;
	writeIndex[USDS_UNSIGNED_BYTE] = 0;
	writeIndex[USDS_SHORT] = 0;
	writeIndex[USDS_UNSIGNED_SHORT] = 0;
	writeIndex[USDS_BIGENDIAN_SHORT] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	writeIndex[USDS_INT] = &DictionaryBinaryCreator::writeInt;
	writeIndex[USDS_UNSIGNED_INT] = 0;
	writeIndex[USDS_BIGENDIAN_INT] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	writeIndex[USDS_LONG] = &DictionaryBinaryCreator::writeLong;
	writeIndex[USDS_UNSIGNED_LONG] = 0;
	writeIndex[USDS_BIGENDIAN_LONG] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	writeIndex[USDS_INT128] = 0;
	writeIndex[USDS_UNSIGNED_INT128] = 0;
	writeIndex[USDS_BIGENDIAN_INT128] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	writeIndex[USDS_FLOAT] = 0;
	writeIndex[USDS_BIGENDIAN_FLOAT] = 0;
	writeIndex[USDS_DOUBLE] = &DictionaryBinaryCreator::writeDouble;
	writeIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	writeIndex[USDS_VARINT] = 0;
	writeIndex[USDS_UNSIGNED_VARINT] = &DictionaryBinaryCreator::writeUVarint;
	writeIndex[USDS_ARRAY] = &DictionaryBinaryCreator::writeArray;
	writeIndex[USDS_STRING] = &DictionaryBinaryCreator::writeString;
	writeIndex[USDS_LIST] = 0;
	writeIndex[USDS_MAP] = 0;
	writeIndex[USDS_POLYMORPH] = 0;
	writeIndex[USDS_STRUCT] = &DictionaryBinaryCreator::writeStruct;
	writeIndex[USDS_TAG] = 0;
};

DictionaryBinaryCreator::~DictionaryBinaryCreator() { };

void DictionaryBinaryCreator::generate(BinaryOutput* buff, Dictionary* dict) throw (...)
try
{
	outBuffer = buff;

	// Write text encode
	outBuffer->writeByte(dict->getEncode());

	// Write tags
	for (int id = 1; id <= dict->getTagNumber(); id++)
	{
		outBuffer->writeUByte(USDS_TAG_SIGNATURE);
		DictionaryBaseType* tag = dict->getTag(id);
		outBuffer->writeUVarint(tag->getID());
		size_t size = tag->getNameSize();
		outBuffer->writeUVarint(size);
		outBuffer->writeByteArray((void*)tag->getName(), size);
		outBuffer->writeByte(tag->getType());
		// write specific Tag parameters
		(this->*(writeIndex[tag->getType()]))(tag);
	}
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"DictionaryBinaryCreator::generate");
	throw msg;
};

//=======================================================================================================
void DictionaryBinaryCreator::writeStruct(DictionaryBaseType* object) throw (...)
{
	//write fields
	int fieldNumber = ((DictionaryStruct*)object)->getFieldNumber();
	for (int id = 1; id <= fieldNumber; id++)
	{
		DictionaryBaseType* field = ((DictionaryStruct*)object)->getField(id);
		outBuffer->writeUByte(USDS_FIELD_SIGNATURE);
		outBuffer->writeUVarint(field->getID());
		size_t size = field->getNameSize();
		outBuffer->writeUVarint(size);
		outBuffer->writeByteArray((void*)field->getName(), size);
		outBuffer->writeByte(field->getType());
		// write specific Field parameters
		(this->*(writeIndex[field->getType()]))(field);
	}

	// write tag restrictions
	if (!object->getRootStatus())
	{
		outBuffer->writeUByte(USDS_TAG_RESTRICTION_SIGNATURE);
		outBuffer->writeUByte(USDS_TAG_RESTRICTION_ROOT_SIGNATURE); // == root is false
	}

};



//=======================================================================================================
void DictionaryBinaryCreator::writeBoolean(DictionaryBaseType* object) throw (...)
{

	
};

void DictionaryBinaryCreator::writeInt(DictionaryBaseType* object) throw (...)
{

	
};

void DictionaryBinaryCreator::writeLong(DictionaryBaseType* object) throw (...)
{

	
};

void DictionaryBinaryCreator::writeDouble(DictionaryBaseType* object) throw (...)
{

	
};

void DictionaryBinaryCreator::writeUVarint(DictionaryBaseType* object) throw (...)
{

	
};

void DictionaryBinaryCreator::writeArray(DictionaryBaseType* object) throw (...)
try
{
	switch (((DictionaryArray*)object)->getElementType())
	{
	case USDS_TAG:
		outBuffer->writeByte(USDS_TAG);
		outBuffer->writeUVarint(((DictionaryArray*)object)->getElementTagID());
		break;
	default:
		std::wstringstream err;
		err << L"Unsupported type '" << ((DictionaryArray*)object)->getElementType() << "'";
		throw ErrorMessage(DIC_BINARY_CREATOR_UNSUPPORTED_TYPE, &err);
	}
	
	
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"DictionaryBinaryCreator::writeArrayField");
	throw msg;
};

void DictionaryBinaryCreator::writeString(DictionaryBaseType* object) throw (...)
{
	outBuffer->writeByte(((DictionaryString*)object)->getEncode());
	
};
