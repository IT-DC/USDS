#include "converters\usdsDictionaryBinaryParser.h"
#include "base\binary\usdsBinaryInput.h"
#include "dictionary\usdsDictionary.h"
#include "dictionary\tags\dicBaseTag.h"
#include "dictionary\tags\dicStructTag.h"
#include "dictionary\fields\dicBaseField.h"
#include "dictionary\fields\dicStringField.h"
#include "dictionary\fields\dicArrayField.h"


using namespace usds;

BinaryDictionaryParser::BinaryDictionaryParser()
{
	readTagIndex[USDS_NO_TYPE] = 0;
	readTagIndex[USDS_BOOLEAN] = 0;
	readTagIndex[USDS_BYTE] = 0;
	readTagIndex[USDS_UNSIGNED_BYTE] = 0;
	readTagIndex[USDS_SHORT] = 0;
	readTagIndex[USDS_UNSIGNED_SHORT] = 0;
	readTagIndex[USDS_BIGENDIAN_SHORT] = 0;
	readTagIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	readTagIndex[USDS_INT] = 0;
	readTagIndex[USDS_UNSIGNED_INT] = 0;
	readTagIndex[USDS_BIGENDIAN_INT] = 0;
	readTagIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	readTagIndex[USDS_LONG] = 0;
	readTagIndex[USDS_UNSIGNED_LONG] = 0;
	readTagIndex[USDS_BIGENDIAN_LONG] = 0;
	readTagIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	readTagIndex[USDS_INT128] = 0;
	readTagIndex[USDS_UNSIGNED_INT128] = 0;
	readTagIndex[USDS_BIGENDIAN_INT128] = 0;
	readTagIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	readTagIndex[USDS_FLOAT] = 0;
	readTagIndex[USDS_BIGENDIAN_FLOAT] = 0;
	readTagIndex[USDS_DOUBLE] = 0;
	readTagIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	readTagIndex[USDS_VARINT] = 0;
	readTagIndex[USDS_UNSIGNED_VARINT] = 0;
	readTagIndex[USDS_ARRAY] = 0;
	readTagIndex[USDS_STRING] = 0;
	readTagIndex[USDS_LIST] = 0;
	readTagIndex[USDS_MAP] = 0;
	readTagIndex[USDS_POLYMORPH] = 0;
	readTagIndex[USDS_STRUCT] = &BinaryDictionaryParser::readStructTag;
	readTagIndex[USDS_TAG] = 0;


	readFieldIndex[USDS_NO_TYPE] = 0;
	readFieldIndex[USDS_BOOLEAN] = &BinaryDictionaryParser::readBooleanField;
	readFieldIndex[USDS_BYTE] = 0;
	readFieldIndex[USDS_UNSIGNED_BYTE] = 0;
	readFieldIndex[USDS_SHORT] = 0;
	readFieldIndex[USDS_UNSIGNED_SHORT] = 0;
	readFieldIndex[USDS_BIGENDIAN_SHORT] = 0;
	readFieldIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	readFieldIndex[USDS_INT] = &BinaryDictionaryParser::readIntField;
	readFieldIndex[USDS_UNSIGNED_INT] = 0;
	readFieldIndex[USDS_BIGENDIAN_INT] = 0;
	readFieldIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	readFieldIndex[USDS_LONG] = &BinaryDictionaryParser::readLongField;
	readFieldIndex[USDS_UNSIGNED_LONG] = 0;
	readFieldIndex[USDS_BIGENDIAN_LONG] = 0;
	readFieldIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	readFieldIndex[USDS_INT128] = 0;
	readFieldIndex[USDS_UNSIGNED_INT128] = 0;
	readFieldIndex[USDS_BIGENDIAN_INT128] = 0;
	readFieldIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	readFieldIndex[USDS_FLOAT] = 0;
	readFieldIndex[USDS_BIGENDIAN_FLOAT] = 0;
	readFieldIndex[USDS_DOUBLE] = &BinaryDictionaryParser::readDoubleField;
	readFieldIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	readFieldIndex[USDS_VARINT] = 0;
	readFieldIndex[USDS_UNSIGNED_VARINT] = &BinaryDictionaryParser::readUVarintField;
	readFieldIndex[USDS_ARRAY] = &BinaryDictionaryParser::readArrayField;
	readFieldIndex[USDS_STRING] = &BinaryDictionaryParser::readStringField;
	readFieldIndex[USDS_LIST] = 0;
	readFieldIndex[USDS_MAP] = 0;
	readFieldIndex[USDS_POLYMORPH] = 0;
	readFieldIndex[USDS_STRUCT] = 0;
	readFieldIndex[USDS_TAG] = 0;
};

BinaryDictionaryParser::~BinaryDictionaryParser()
{


};

void BinaryDictionaryParser::parse(BinaryInput* buff, Dictionary* dict) throw(...)
try
{
	binary = buff;
	dictionary = dict;

	// read text encode
	int encode = binary->readByte();
	dictionary->setEncode((usdsEncodes)encode);

	// read tags
	while (!binary->isEnd())
	{
		// read signature
		unsigned char signature = binary->readUByte();
		if (signature != USDS_TAG_SIGNATURE)
		{
			std::wstringstream msg;
			msg << L"Unexpected signature '" << signature << L"'";
			throw ErrorMessage(BINARY_DICTIONARY_PARSER_UNKNOWN_FORMAT, &msg);
		}
		// read main attributes
		int tag_id;
		binary->readUVarint(&tag_id);
		size_t name_size;
		binary->readUVarint(&name_size);
		const void* name = binary->readByteArray(name_size);
		int tag_type = binary->readByte();
		DicBaseTag* tag = dictionary->addTag((usdsTypes)tag_type, tag_id, (const char*)name, name_size);
		// read specific Tag parameters
		(this->*(readTagIndex[tag_type]))(tag);
	}

	dictionary->finalizeDictionary();
	dictionary->setBinary(binary->getFirstPosition(), binary->getDataSize(), true, true);
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BinaryDictionaryParser::parse");
	throw msg;
};


//=======================================================================================================
void BinaryDictionaryParser::readStructTag(DicBaseTag* tag) throw (...)
try
{
	unsigned char signature = binary->readUByte();
	if (signature != USDS_FIELD_SIGNATURE)
	{
		std::wstringstream msg;
		msg << L"Unexpected signature '" << signature << L"'";
		throw ErrorMessage(BINARY_DICTIONARY_PARSER_UNKNOWN_FORMAT, &msg);
	}
	while (signature == USDS_FIELD_SIGNATURE)
	{
		// read main attributes
		int field_id;
		binary->readUVarint(&field_id);
		size_t name_size;
		binary->readUVarint(&name_size);
		const void* name = binary->readByteArray(name_size);
		int field_type = binary->readByte();
		DicBaseField* field = dictionary->addField((usdsTypes)field_type, (DicStructTag*)tag, field_id, (const char*)name, name_size);
		// read specific Field parameters
		(this->*(readFieldIndex[field_type]))(field);
		if (binary->isEnd())
			return;
		signature = binary->readUByte();
	}
	// read tag restrictions
	if (signature == USDS_TAG_RESTRICTION_SIGNATURE)
	{
		signature = binary->readUByte();
		if (signature == USDS_TAG_RESTRICTION_ROOT_SIGNATURE)
			tag->setRoot(false);
		else
		{
			std::wstringstream msg;
			msg << L"Unexpected signature for tag restriction '" << signature << L"'";
			throw ErrorMessage(BINARY_DICTIONARY_PARSER_UNKNOWN_FORMAT, &msg);
		}
	}
	else
	{
		// return signature to the buffer
		binary->stepBack(1);
	}
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BinaryDictionaryParser::readStructTag");
	throw msg;
};


void BinaryDictionaryParser::readBooleanField(DicBaseField* field) throw (...)
{


};

void BinaryDictionaryParser::readIntField(DicBaseField* field) throw (...)
{


};

void BinaryDictionaryParser::readLongField(DicBaseField* field) throw (...)
{


};

void BinaryDictionaryParser::readDoubleField(DicBaseField* field) throw (...)
{


};

void BinaryDictionaryParser::readUVarintField(DicBaseField* field) throw (...)
{


};

void BinaryDictionaryParser::readArrayField(DicBaseField* field) throw (...)
{
	int element_type = binary->readByte();
	switch (element_type)
	{
	case USDS_TAG:
		{
			int tag_id;
			binary->readUVarint(&tag_id);
			((DicArrayField*)field)->setElementAsTag(tag_id);
			break;
		}
	default:
		std::wstringstream err;
		err << L"Unsupported type '" << ((DicArrayField*)field)->getElementType() << "'";
		throw ErrorMessage(DIC_BINARY_CREATOR_UNSUPPORTED_TYPE, &err);
	}
};

void BinaryDictionaryParser::readStringField(DicBaseField* field) throw (...)
{
	int encode = binary->readByte();
	((DicStringField*)field)->setEncode((usdsEncodes)encode);

};