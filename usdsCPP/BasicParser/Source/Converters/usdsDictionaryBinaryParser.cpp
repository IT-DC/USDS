#include "converters\usdsDictionaryBinaryParser.h"
#include "base\binary\usdsBinaryInput.h"
#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryStruct.h"
#include "dictionary\dataTypes\dictionaryString.h"
#include "dictionary\dataTypes\dictionaryArray.h"


using namespace usds;

DictionaryBinaryParser::DictionaryBinaryParser()
{
	readIndex[USDS_NO_TYPE] = 0;
	readIndex[USDS_BOOLEAN] = &DictionaryBinaryParser::readBoolean;
	readIndex[USDS_BYTE] = 0;
	readIndex[USDS_UNSIGNED_BYTE] = 0;
	readIndex[USDS_SHORT] = 0;
	readIndex[USDS_UNSIGNED_SHORT] = 0;
	readIndex[USDS_BIGENDIAN_SHORT] = 0;
	readIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	readIndex[USDS_INT] = &DictionaryBinaryParser::readInt;
	readIndex[USDS_UNSIGNED_INT] = 0;
	readIndex[USDS_BIGENDIAN_INT] = 0;
	readIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	readIndex[USDS_LONG] = &DictionaryBinaryParser::readLong;
	readIndex[USDS_UNSIGNED_LONG] = 0;
	readIndex[USDS_BIGENDIAN_LONG] = 0;
	readIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	readIndex[USDS_INT128] = 0;
	readIndex[USDS_UNSIGNED_INT128] = 0;
	readIndex[USDS_BIGENDIAN_INT128] = 0;
	readIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	readIndex[USDS_FLOAT] = 0;
	readIndex[USDS_BIGENDIAN_FLOAT] = 0;
	readIndex[USDS_DOUBLE] = &DictionaryBinaryParser::readDouble;
	readIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	readIndex[USDS_VARINT] = 0;
	readIndex[USDS_UNSIGNED_VARINT] = &DictionaryBinaryParser::readUVarint;
	readIndex[USDS_ARRAY] = &DictionaryBinaryParser::readArray;
	readIndex[USDS_STRING] = &DictionaryBinaryParser::readString;
	readIndex[USDS_LIST] = 0;
	readIndex[USDS_MAP] = 0;
	readIndex[USDS_POLYMORPH] = 0;
	readIndex[USDS_STRUCT] = &DictionaryBinaryParser::readStruct;
	readIndex[USDS_TAG] = 0;
};

DictionaryBinaryParser::~DictionaryBinaryParser()
{


};

void DictionaryBinaryParser::parse(BinaryInput* buff, Dictionary* dict) throw(...)
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
		DictionaryBaseType* tag = dictionary->addTag((usdsTypes)tag_type, tag_id, (const char*)name, name_size);
		// read specific Tag parameters
		(this->*(readIndex[tag_type]))(tag);
	}

	dictionary->finalizeDictionary();
	dictionary->setBinary(binary->getFirstPosition(), binary->getDataSize());
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"DictionaryBinaryParser::parse");
	throw msg;
};


//=======================================================================================================
void DictionaryBinaryParser::readStruct(DictionaryBaseType* object) throw (...)
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
		DictionaryBaseType* field = ((DictionaryStruct*)object)->addField((usdsTypes)field_type, field_id, (const char*)name, name_size);
		// read specific Field parameters
		(this->*(readIndex[field_type]))(field);
		if (binary->isEnd())
			return;
		signature = binary->readUByte();
	}
	// read tag restrictions
	if (signature == USDS_TAG_RESTRICTION_SIGNATURE)
	{
		signature = binary->readUByte();
		if (signature == USDS_TAG_RESTRICTION_ROOT_SIGNATURE)
			object->setRoot(false);
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
	msg.addPath(L"DictionaryBinaryParser::readStructTag");
	throw msg;
};


void DictionaryBinaryParser::readBoolean(DictionaryBaseType* object) throw (...)
{


};

void DictionaryBinaryParser::readInt(DictionaryBaseType* object) throw (...)
{


};

void DictionaryBinaryParser::readLong(DictionaryBaseType* object) throw (...)
{


};

void DictionaryBinaryParser::readDouble(DictionaryBaseType* object) throw (...)
{


};

void DictionaryBinaryParser::readUVarint(DictionaryBaseType* object) throw (...)
{


};

void DictionaryBinaryParser::readArray(DictionaryBaseType* object) throw (...)
{
	int element_type = binary->readByte();
	switch (element_type)
	{
	case USDS_TAG:
		{
			int tag_id;
			binary->readUVarint(&tag_id);
			((DictionaryArray*)object)->setElementAsTag(tag_id);
			break;
		}
	default:
		std::wstringstream err;
		err << L"Unsupported type '" << ((DictionaryArray*)object)->getElementType() << "'";
		throw ErrorMessage(DIC_BINARY_CREATOR_UNSUPPORTED_TYPE, &err);
	}
};

void DictionaryBinaryParser::readString(DictionaryBaseType* object) throw (...)
{
	int encode = binary->readByte();
	((DictionaryString*)object)->setEncode((usdsEncodes)encode);

};