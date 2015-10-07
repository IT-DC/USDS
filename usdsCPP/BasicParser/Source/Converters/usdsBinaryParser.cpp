#include "converters\usdsBinaryParser.h"
#include "base\binary\usdsBinaryInput.h"
#include "dictionary\usdsDictionary.h"
#include "base\usdsErrors.h"

using namespace usds;

BinaryParser::BinaryParser(const unsigned char* data, int data_size)
{
	headExists = false;
	dictionaryExists = false;
	bodyExists = false;

	BinaryInput binary;

	binary.setBinary(data, data_size);
	unsigned char signature = binary.readByte();
	switch (signature)
	{
	case '$':
		readHead(&binary);
		if (binary.isEnd())
			break; // no dictionary and body in binary
		
		// try to read next signature
		signature = binary.readByte();
		if (signature == USDS_BODY_SIGNATURE)
		{
			dictionaryExists = false;
			bodyExists = true;
			bodyPosition = binary.getCurrentPosition() - 1;
			bodySize = bodyPosition - data;
			break; // no dictionary in binary
		}
		if (signature == USDS_DICTIONARY_SIGNATURE)
		{
			dictionaryPosition = binary.getCurrentPosition() - 1;
			// read dictionary size
			int step = binary.readUVarint(&dictionarySize);
			// move to the end of the dictionary
			binary.stepForward(dictionarySize);
			// save dictionary suze
			dictionarySize = dictionarySize + step + 1; // add size of "dictionary size" and size of signature
			dictionaryExists = true;
		}
		if (binary.isEnd())
			break; // no body in binary

		// try to read body after dictionary
		signature = binary.readByte();
		if (signature == USDS_BODY_SIGNATURE)
		{
			bodyExists = true;
			bodyPosition = binary.getCurrentPosition() - 1;
			bodySize = bodyPosition - data;
		}
		break;
	case USDS_BODY_SIGNATURE:
		headExists = false;
		dictionaryExists = false;
		bodyExists = true;
		bodyPosition = data;
		bodySize = data_size;
		break;
	default:
		std::wstringstream msg;
		msg << L"Unexpected signature '" << signature << L"' at the start of the binary";
		throw ErrorMessage(BINARY_PARSER_UNKNOWN_FORMAT, &msg, L"BinaryParser::BinaryParser");
	}

};

BinaryParser::~BinaryParser()
{


};

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
{


};

void BinaryParser::initBodyFromBinary(Dictionary* dict) throw(...)
{


};

//=============================================================================================
void BinaryParser::readHead(BinaryInput* binary) throw(...)
try
{
	// read full signature
	unsigned char head[3];
	binary->readByteArray(head, 3);
	if (head[0] != 'S' || head[1] != 1 || head[2] != 0)
		ErrorMessage(BINARY_PARSER_UNKNOWN_FORMAT, L"Unknown format of the binary");

	// read dictionary version
	dictionaryID = binary->readInt();
	dictionaryMajor = binary->readByte();
	dictionaryMinor = binary->readByte();
	binary->readUVarint(&documentSize);
	
	headExists = true;

}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BinaryParser::readHead");
	throw msg;
};