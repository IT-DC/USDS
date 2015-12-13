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
	readIndex[USDS_TAG] = &DictionaryBinaryParser::readTag;
	readIndex[USDS_BOOLEAN] = &DictionaryBinaryParser::readBoolean;
	readIndex[USDS_BYTE] = &DictionaryBinaryParser::readByte;
	readIndex[USDS_UNSIGNED_BYTE] = &DictionaryBinaryParser::readUByte;
	readIndex[USDS_SHORT] = &DictionaryBinaryParser::readShort;
	readIndex[USDS_UNSIGNED_SHORT] = &DictionaryBinaryParser::readUShort;
	readIndex[USDS_BIGENDIAN_SHORT] = &DictionaryBinaryParser::readBEShort;
	readIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = &DictionaryBinaryParser::readBEUShort;
	readIndex[USDS_INT] = &DictionaryBinaryParser::readInt;
	readIndex[USDS_UNSIGNED_INT] = &DictionaryBinaryParser::readUInt;
	readIndex[USDS_BIGENDIAN_INT] = &DictionaryBinaryParser::readBEInt;
	readIndex[USDS_BIGENDIAN_UNSIGNED_INT] = &DictionaryBinaryParser::readBEUInt;
	readIndex[USDS_LONG] = &DictionaryBinaryParser::readLong;
	readIndex[USDS_UNSIGNED_LONG] = &DictionaryBinaryParser::readULong;
	readIndex[USDS_BIGENDIAN_LONG] = &DictionaryBinaryParser::readBELong;
	readIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = &DictionaryBinaryParser::readBEULong;
	readIndex[USDS_INT128] = &DictionaryBinaryParser::readInt128;
	readIndex[USDS_UNSIGNED_INT128] = &DictionaryBinaryParser::readUInt128;
	readIndex[USDS_BIGENDIAN_INT128] = &DictionaryBinaryParser::readBEInt128;
	readIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = &DictionaryBinaryParser::readBEUInt128;
	readIndex[USDS_FLOAT] = &DictionaryBinaryParser::readFloat;
	readIndex[USDS_BIGENDIAN_FLOAT] = &DictionaryBinaryParser::readBEFloat;
	readIndex[USDS_DOUBLE] = &DictionaryBinaryParser::readDouble;
	readIndex[USDS_USDS_BIGENDIAN_DOUBLE] = &DictionaryBinaryParser::readBEDouble;
	readIndex[USDS_VARINT] = &DictionaryBinaryParser::readVarint;
	readIndex[USDS_UNSIGNED_VARINT] = &DictionaryBinaryParser::readUVarint;
	readIndex[USDS_STRING] = &DictionaryBinaryParser::readString;
	readIndex[USDS_ARRAY] = &DictionaryBinaryParser::readArray;
	readIndex[USDS_LIST] = &DictionaryBinaryParser::readList;
	readIndex[USDS_MAP] = &DictionaryBinaryParser::readMap;
	readIndex[USDS_POLYMORPH] = &DictionaryBinaryParser::readPolymorph;
	readIndex[USDS_STRUCT] = &DictionaryBinaryParser::readStruct;
	readIndex[USDS_FUNCTION] = &DictionaryBinaryParser::readFunction;

};

DictionaryBinaryParser::~DictionaryBinaryParser()
{


};

void DictionaryBinaryParser::parse(BinaryInput* buff, Dictionary* dict) throw(...)
try
{
	binary = buff;
	dictionary = dict;

	// read tags
	while (!binary->isEnd())
	{
		// read signature
		unsigned char signature = binary->readUByte();
		if (signature != USDS_TAG_SIGNATURE)
			throw ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT) << "Unexpected signature '" << signature << "'";

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
	throw ErrorStack("DictionaryBinaryParser::parse") << (void*)buff << (void*)dict << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryBinaryParser::parse") << (void*)buff << (void*)dict;
	throw;
}


//=======================================================================================================
void DictionaryBinaryParser::readStruct(DictionaryBaseType* object) throw (...)
try
{
	unsigned char signature = binary->readUByte();
	if (signature != USDS_FIELD_SIGNATURE)
		throw ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT) << "Unexpected signature '" << signature << "'";

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
		if (signature == USDS_TAG_RESTRICTION_NOT_ROOT_SIGNATURE)
			object->setRoot(false);
		else
			throw ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT) << "Unexpected signature for tag restriction '" << signature << "'";;
	}
	else
	{
		// return signature to the buffer
		binary->stepBack(1);
	}
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryBinaryParser::readStruct") << (void*)object << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryBinaryParser::readStruct") << (void*)object;
	throw;
}


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
try
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
		throw ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT) << "Unsupported type '" << ((DictionaryArray*)object)->getElementType() << "'";
	}
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryBinaryParser::readArray") << (void*)object << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryBinaryParser::readArray") << (void*)object;
	throw;
}


void DictionaryBinaryParser::readString(DictionaryBaseType* object) throw (...)
try
{
	int encode = binary->readByte();
	((DictionaryString*)object)->setEncode((usdsEncodes)encode);

}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryBinaryParser::readString") << (void*)object;
	throw;
};