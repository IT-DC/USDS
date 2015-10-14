#include "converters\usdsDictionaryBinaryCreator.h"
#include "dictionary\usdsDictionary.h"
#include "base\binary\usdsBinaryOutput.h"

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"

#include "dictionary\tags\dicStructTag.h"

#include "dictionary\fields\dicArrayField.h"
#include "dictionary\fields\dicBooleanField.h"
#include "dictionary\fields\dicDoubleField.h"
#include "dictionary\fields\dicIntField.h"
#include "dictionary\fields\dicLongField.h"
#include "dictionary\fields\dicStringField.h"
#include "dictionary\fields\dicUVarintField.h"

using namespace usds;

DictionaryBinaryCreator::DictionaryBinaryCreator() 
{
	writeTagIndex[USDS_NO_TYPE] = 0;
	writeTagIndex[USDS_BOOLEAN] = 0;
	writeTagIndex[USDS_BYTE] = 0;
	writeTagIndex[USDS_UNSIGNED_BYTE] = 0;
	writeTagIndex[USDS_SHORT] = 0;
	writeTagIndex[USDS_UNSIGNED_SHORT] = 0;
	writeTagIndex[USDS_BIGENDIAN_SHORT] = 0;
	writeTagIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	writeTagIndex[USDS_INT] = 0;
	writeTagIndex[USDS_UNSIGNED_INT] = 0;
	writeTagIndex[USDS_BIGENDIAN_INT] = 0;
	writeTagIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	writeTagIndex[USDS_LONG] = 0;
	writeTagIndex[USDS_UNSIGNED_LONG] = 0;
	writeTagIndex[USDS_BIGENDIAN_LONG] = 0;
	writeTagIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	writeTagIndex[USDS_INT128] = 0;
	writeTagIndex[USDS_UNSIGNED_INT128] = 0;
	writeTagIndex[USDS_BIGENDIAN_INT128] = 0;
	writeTagIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	writeTagIndex[USDS_FLOAT] = 0;
	writeTagIndex[USDS_BIGENDIAN_FLOAT] = 0;
	writeTagIndex[USDS_DOUBLE] = 0;
	writeTagIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	writeTagIndex[USDS_VARINT] = 0;
	writeTagIndex[USDS_UNSIGNED_VARINT] = 0;
	writeTagIndex[USDS_ARRAY] = 0;
	writeTagIndex[USDS_STRING] = 0;
	writeTagIndex[USDS_LIST] = 0;
	writeTagIndex[USDS_MAP] = 0;
	writeTagIndex[USDS_POLYMORPH] = 0;
	writeTagIndex[USDS_STRUCT] = &DictionaryBinaryCreator::writeStructTag;
	writeTagIndex[USDS_TAG] = 0;


	writeFieldIndex[USDS_NO_TYPE] = 0;
	writeFieldIndex[USDS_BOOLEAN] = &DictionaryBinaryCreator::writeBooleanField;
	writeFieldIndex[USDS_BYTE] = 0;
	writeFieldIndex[USDS_UNSIGNED_BYTE] = 0;
	writeFieldIndex[USDS_SHORT] = 0;
	writeFieldIndex[USDS_UNSIGNED_SHORT] = 0;
	writeFieldIndex[USDS_BIGENDIAN_SHORT] = 0;
	writeFieldIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	writeFieldIndex[USDS_INT] = &DictionaryBinaryCreator::writeIntField;
	writeFieldIndex[USDS_UNSIGNED_INT] = 0;
	writeFieldIndex[USDS_BIGENDIAN_INT] = 0;
	writeFieldIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	writeFieldIndex[USDS_LONG] = &DictionaryBinaryCreator::writeLongField;
	writeFieldIndex[USDS_UNSIGNED_LONG] = 0;
	writeFieldIndex[USDS_BIGENDIAN_LONG] = 0;
	writeFieldIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	writeFieldIndex[USDS_INT128] = 0;
	writeFieldIndex[USDS_UNSIGNED_INT128] = 0;
	writeFieldIndex[USDS_BIGENDIAN_INT128] = 0;
	writeFieldIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	writeFieldIndex[USDS_FLOAT] = 0;
	writeFieldIndex[USDS_BIGENDIAN_FLOAT] = 0;
	writeFieldIndex[USDS_DOUBLE] = &DictionaryBinaryCreator::writeDoubleField;
	writeFieldIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	writeFieldIndex[USDS_VARINT] = 0;
	writeFieldIndex[USDS_UNSIGNED_VARINT] = &DictionaryBinaryCreator::writeUVarintField;
	writeFieldIndex[USDS_ARRAY] = &DictionaryBinaryCreator::writeArrayField;
	writeFieldIndex[USDS_STRING] = &DictionaryBinaryCreator::writeStringField;
	writeFieldIndex[USDS_LIST] = 0;
	writeFieldIndex[USDS_MAP] = 0;
	writeFieldIndex[USDS_POLYMORPH] = 0;
	writeFieldIndex[USDS_STRUCT] = 0;
	writeFieldIndex[USDS_TAG] = 0;


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
		DicBaseTag* tag = dict->getTag(id);
		outBuffer->writeUVarint(tag->getID());
		size_t size = tag->getNameSize();
		outBuffer->writeUVarint(size);
		outBuffer->writeByteArray((void*)tag->getName(), size);
		outBuffer->writeByte(tag->getType());
		// write specific Tag parameters
		(this->*(writeTagIndex[tag->getType()]))(tag);
	}
	// write Dictionary size and signature
	outBuffer->pushFrontSize();
	outBuffer->pushFrontUByte(USDS_DICTIONARY_SIGNATURE_WITH_SIZE);
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"DictionaryBinaryCreator::generate");
	throw msg;
};

//=======================================================================================================
void DictionaryBinaryCreator::writeStructTag(DicBaseTag* tag) throw (...)
{
	//write fields
	for (int id = 1; id <= ((DicStructTag*)tag)->getFieldNumber() ; id++)
	{
		DicBaseField* field = ((DicStructTag*)tag)->getField(id);
		outBuffer->writeUByte(USDS_FIELD_SIGNATURE);
		outBuffer->writeUVarint(field->getID());
		size_t size = field->getNameSize();
		outBuffer->writeUVarint(size);
		outBuffer->writeByteArray((void*)field->getName(), size);
		outBuffer->writeByte(field->getType());
		// write specific Field parameters
		(this->*(writeFieldIndex[field->getType()]))(field);
	}

	// write tag restrictions
	if (!tag->getRootStatus())
	{
		outBuffer->writeUByte(USDS_TAG_RESTRICTION_SIGNATURE);
		outBuffer->writeUByte(USDS_TAG_RESTRICTION_ROOT_SIGNATURE); // == root is false
	}

};



//=======================================================================================================
void DictionaryBinaryCreator::writeBooleanField(DicBaseField* field) throw (...)
{

	
};

void DictionaryBinaryCreator::writeIntField(DicBaseField* field) throw (...)
{

	
};

void DictionaryBinaryCreator::writeLongField(DicBaseField* field) throw (...)
{

	
};

void DictionaryBinaryCreator::writeDoubleField(DicBaseField* field) throw (...)
{

	
};

void DictionaryBinaryCreator::writeUVarintField(DicBaseField* field) throw (...)
{

	
};

void DictionaryBinaryCreator::writeArrayField(DicBaseField* field) throw (...)
try
{
	switch (((DicArrayField*)field)->getElementType())
	{
	case USDS_TAG:
		outBuffer->writeByte(USDS_TAG);
		outBuffer->writeUVarint(((DicArrayField*)field)->getElementTagID());
		break;
	default:
		std::wstringstream err;
		err << L"Unsupported type '" << ((DicArrayField*)field)->getElementType() << "'";
		throw ErrorMessage(DIC_BINARY_CREATOR_UNSUPPORTED_TYPE, &err);
	}
	
	
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"DictionaryBinaryCreator::writeArrayField");
	throw msg;
};

void DictionaryBinaryCreator::writeStringField(DicBaseField* field) throw (...)
{
	outBuffer->writeByte(((DicStringField*)field)->getEncode());
	
};
