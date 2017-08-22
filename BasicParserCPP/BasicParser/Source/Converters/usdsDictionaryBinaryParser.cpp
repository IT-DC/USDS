#include "converters\usdsDictionaryBinaryParser.h"
#include "binary\usdsBinaryInput.h"
#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryStruct.h"
#include "dictionary\dataTypes\dictionaryString.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"


using namespace usds;

DictionaryBinaryParser::DictionaryBinaryParser()
{
	readIndex[USDS_TAG] = &DictionaryBinaryParser::readTag;
	readIndex[USDS_BOOLEAN] = &DictionaryBinaryParser::readBoolean;
	readIndex[USDS_BYTE] = &DictionaryBinaryParser::readByte;
	readIndex[USDS_UBYTE] = &DictionaryBinaryParser::readUByte;
	readIndex[USDS_SHORT] = &DictionaryBinaryParser::readShort;
	readIndex[USDS_USHORT] = &DictionaryBinaryParser::readUShort;
	readIndex[USDS_INT] = &DictionaryBinaryParser::readInt;
	readIndex[USDS_UINT] = &DictionaryBinaryParser::readUInt;
	readIndex[USDS_LONG] = &DictionaryBinaryParser::readLong;
	readIndex[USDS_ULONG] = &DictionaryBinaryParser::readULong;
	readIndex[USDS_INT128] = &DictionaryBinaryParser::readInt128;
	readIndex[USDS_UINT128] = &DictionaryBinaryParser::readUInt128;
	readIndex[USDS_FLOAT] = &DictionaryBinaryParser::readFloat;
	readIndex[USDS_DOUBLE] = &DictionaryBinaryParser::readDouble;
	readIndex[USDS_VARINT] = &DictionaryBinaryParser::readVarint;
	readIndex[USDS_UVARINT] = &DictionaryBinaryParser::readUVarint;
	readIndex[USDS_STRING] = &DictionaryBinaryParser::readString;
	readIndex[USDS_ARRAY] = &DictionaryBinaryParser::readArray;
	readIndex[USDS_STRUCT] = &DictionaryBinaryParser::readStruct;
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
		uint8_t signature = binary->readUByte();
		if (signature != USDS_TAG_SIGNATURE)
			throw ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT) << "Unexpected signature '" << signature << "'";

		// read main attributes
		int32_t tag_id;
		binary->readUVarint(&tag_id);
		size_t name_size;
		binary->readUVarint(&name_size);
		const void* name = binary->readByteArray(name_size);
		int32_t tag_type = binary->readByte();
		DictionaryBaseType* tag = dictionary->addTag((usdsType)tag_type, tag_id, (const char*)name, name_size);
		// read specific Tag parameters
		(this->*(readIndex[tag_type]))(tag);
	}

	dictionary->finalizeDictionary();
	dictionary->setBinary(binary->getFirstPosition(), binary->getSize());
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

void DictionaryBinaryParser::readTag(DictionaryBaseType* object) throw (...)
{
	int32_t tag_type = 0;
	binary->readUVarint(&tag_type);
	((DictionaryTagLink*)object)->setTag(tag_type);
};

void DictionaryBinaryParser::readBoolean(DictionaryBaseType* object) throw (...)
{


};

void DictionaryBinaryParser::readByte(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryParser::readByte") << (void*)object << ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT, "Unsupported type BYTE for Dictionary Binary Parser");
};

void DictionaryBinaryParser::readUByte(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryParser::readUByte") << (void*)object << ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT, "Unsupported type UNSIGNED BYTE for Dictionary Binary Parser");
};

void DictionaryBinaryParser::readShort(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryParser::readShort") << (void*)object << ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT, "Unsupported type SHORT for Dictionary Binary Parser");
};

void DictionaryBinaryParser::readUShort(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryParser::readUShort") << (void*)object << ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT, "Unsupported type UNSIGNED SHORT for Dictionary Binary Parser");
};

void DictionaryBinaryParser::readInt(DictionaryBaseType* object) throw (...)
{


};

void DictionaryBinaryParser::readUInt(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryParser::readUInt") << (void*)object << ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT, "Unsupported type UNSIGNED INT for Dictionary Binary Parser");
};

void DictionaryBinaryParser::readLong(DictionaryBaseType* object) throw (...)
{


};

void DictionaryBinaryParser::readULong(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryParser::readULong") << (void*)object << ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT, "Unsupported type UNSIGNED LONG for Dictionary Binary Parser");
};

void DictionaryBinaryParser::readInt128(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryParser::readInt128") << (void*)object << ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT, "Unsupported type UNSIGNED INT128 for Dictionary Binary Parser");
};

void DictionaryBinaryParser::readUInt128(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryParser::readUInt128") << (void*)object << ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT, "Unsupported type UNSIGNED INT128 for Dictionary Binary Parser");
};

void DictionaryBinaryParser::readFloat(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryParser::readFloat") << (void*)object << ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT, "Unsupported type FLOAT for Dictionary Binary Parser");
};

void DictionaryBinaryParser::readDouble(DictionaryBaseType* object) throw (...)
{


};

void DictionaryBinaryParser::readVarint(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryBinaryParser::readVarint") << (void*)object << ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT, "Unsupported type VARINT for Dictionary Binary Parser");
};

void DictionaryBinaryParser::readUVarint(DictionaryBaseType* object) throw (...)
{


};

void DictionaryBinaryParser::readString(DictionaryBaseType* object) throw (...)
try
{
	int32_t encode = binary->readByte();
	((DictionaryString*)object)->setDefaultEncode((usdsEncode)encode);

}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryBinaryParser::readString") << (void*)object;
	throw;
};

void DictionaryBinaryParser::readArray(DictionaryBaseType* object) throw (...)
try
{
	usdsType element_type = (usdsType)binary->readByte();
	DictionaryBaseType* element = ((DictionaryArray*)object)->setElementType(element_type);
	(this->*(readIndex[element_type]))(element);
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

void DictionaryBinaryParser::readStruct(DictionaryBaseType* object) throw (...)
try
{
	uint8_t signature = binary->readUByte();
	if (signature != USDS_FIELD_SIGNATURE)
		throw ErrorMessage(DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT) << "Unexpected signature '" << signature << "'";

	while (signature == USDS_FIELD_SIGNATURE)
	{
		// read main attributes
		int32_t field_id;
		binary->readUVarint(&field_id);
		size_t name_size;
		binary->readUVarint(&name_size);
		const void* name = binary->readByteArray(name_size);
		int32_t field_type = binary->readByte();
		DictionaryBaseType* field = ((DictionaryStruct*)object)->addField((usdsType)field_type, field_id, (const char*)name, name_size);
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

