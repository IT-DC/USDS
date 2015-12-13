#include "converters\usdsBinaryParser.h"
#include "dictionary\usdsDictionary.h"
#include "base\usdsErrors.h"

using namespace usds;

BinaryParser::BinaryParser()
{

};

BinaryParser::~BinaryParser()
{

};

void BinaryParser::setBinary(const unsigned char* data, int data_size) throw(...)
try
{
	headExists = false;
	dictionaryExists = false;
	bodyExists = false;

	binary.setBinary(data, data_size);
	unsigned char signature = binary.readUByte();

	// analize binary
	// try to read Head
	if (signature == USDS_MAJOR_SIGNATURE)
	{
		// read all head
		unsigned char head[3];
		binary.readByteArray(head, 3);
		if (head[0] != USDS_MINOR_SIGNATURE || head[1] != USDS_MAJOR_VERSION || head[2] != USDS_MINOR_VERSION)
			throw ErrorMessage(BINARY_PARSER__UNKNOWN_FORMAT, "Unknown format of the binary, head must be '$S10'");

		// read dictionary version
		dictionaryID = binary.readInt();
		dictionaryMajor = binary.readUByte();
		dictionaryMinor = binary.readUByte();
		binary.readUVarint(&documentSize);

		headExists = true;

		if (binary.isEnd())
			return; // no dictionary and body in binary
		//read next signature
		signature = binary.readUByte();
	}
	// try to read Dictionary
	if (signature == USDS_DICTIONARY_SIGNATURE_WITH_SIZE)
	{
		if (!headExists)
			throw ErrorMessage(BINARY_PARSER__UNKNOWN_FORMAT, "Unknown format of the binary: dictionary without head");

		// read dictionary size
		size_t dict_size;
		binary.readUVarint(&dict_size);
		const unsigned char* dict_data = binary.getCurrentPosition();
		// try to move to the end of the dictionary
		binary.stepForward(dict_size);
		dictionaryBinary.setBinary(dict_data, dict_size);
		dictionaryExists = true;

		if (binary.isEnd())
			return; // no body in binary
		//read next signature
		signature = binary.readUByte();
	}
	// try to read Body
	if (signature == USDS_BODY_SIGNATURE)
	{
		const unsigned char* body_data = binary.getCurrentPosition();
		size_t body_size = data_size - (body_data - data);
		bodyBinary.setBinary(body_data, body_size);
		bodyExists = true;
		return;
	}
	else
		throw ErrorMessage(BINARY_PARSER__UNKNOWN_FORMAT) << "Unexpected signature '" << signature << "' at the binary";;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BinaryParser::setBinary") << data << data_size << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryParser::setBinary") << data << data_size;
	throw;
}

bool BinaryParser::isHeadIncluded()
{
	return headExists;
};

bool BinaryParser::isDictionaryIncluded()
{
	return dictionaryExists;
};

int BinaryParser::getDictionaryID()
{
	return dictionaryID;
};

unsigned char BinaryParser::getDictionaryMajor()
{
	return dictionaryMajor;
};

unsigned char BinaryParser::getDictionaryMinor()
{
	return dictionaryMinor;
};

bool BinaryParser::isBodyIncluded()
{
	return bodyExists;
	
};

void BinaryParser::initDictionaryFromBinary(Dictionary* dict) throw(...)
try
{
	dictionaryParser.parse(&dictionaryBinary, dict);

}
catch (ErrorStack& err)
{
	err.addLevel("BinaryParser::initDictionaryFromBinary") << (void*)dict;
	throw;
};

void BinaryParser::initBodyFromBinary(Body* body) throw(...)
try
{
	bodyParser.parse(&bodyBinary, body);
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryParser::initBodyFromBinary") << (void*)body;
	throw;
};

