#include "usdsBasicParser.h"

#include "converters\usdsDictionaryTextParser.h"
#include "converters\usdsDictionaryTextCreator.h"
#include "converters\usdsBinaryCreator.h"

using namespace usds;

BasicParser::BasicParser() : usdsMajor(1), usdsMinor(0)
{
	currentDictionary = 0;
}

BasicParser::~BasicParser()
{
	

}

//====================================================================================================================
// Dictionary constructors
void BasicParser::addDictionaryFromText(const char* text_dictionary, int size, usdsEncodes encode) throw(...)
try 
{
	DictionaryTextParser dictTextParser;
	dictTextParser.parse(text_dictionary, encode, this);
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BasicParser::initDictionaryFromText");
	throw msg;
};

void BasicParser::CurrentDictionaryToText(usdsEncodes encode, std::string* text) throw(...)
try
{
	if (currentDictionary == 0)
		throw ErrorMessage(BASIC_PARSER_DICTIONARY_NOT_FOUND, L"Current dictionary not set");
	DictionaryTextCreator creator;
	creator.generate(encode, text, currentDictionary);
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BasicParser::getCurrentTextDictionary");
	throw msg;
};

Dictionary* BasicParser::addNewDictionary(int id, unsigned char major, unsigned char minor) throw(...)
{
	Dictionary* object = findDictionary(id, major, minor);
	if (object != 0)
	{
		std::wstringstream mess;
		mess << L"Dictionary ID=" << id << L" v." << int(major) << L"." << int(minor) << L" already exists";
		throw ErrorMessage(BASIC_PARSER_DICTIONARY_NOT_FOUND, &mess, L"BasicParser::addNewDictionary");
	}
	
	object = dictionaryPool.addObject();
	dictionaries.push_back(object);
	object->clear();
	object->setID(id, major, minor);
	currentDictionary = object;

	return object;
};

//====================================================================================================================
// Working with several dictionaries

void BasicParser::selectDictionary(int id, unsigned char major, unsigned char minor) throw(...)
{
	Dictionary* object = findDictionary(id, major, minor);
	if (object == 0)
	{
		std::wstringstream mess;
		mess << L"Dictionary ID=" << id << L" v." << int(major) << L"." << int(minor) << L" not found";
		throw ErrorMessage(BASIC_PARSER_DICTIONARY_NOT_FOUND, &mess, L"BasicParser::selectDictionary");
	}

	currentDictionary = object;
};


//====================================================================================================================
// Settings
int BasicParser::getDictionaryID() throw(...)
try
{
	return currentDictionary->getDictionaryID();
}
catch (ErrorMessage& err)
{
	err.addPath(L"BasicParser::getDictionaryID");
	throw err;
};

unsigned char BasicParser::getDictionaryMajor() throw(...)
try
{
	return currentDictionary->getMajorVersion();
}
catch (ErrorMessage& err)
{
	err.addPath(L"BasicParser::getDictionaryMajor");
	throw err;
};

unsigned char BasicParser::getDictionaryMinor() throw(...)
try
{
	return currentDictionary->getMinorVersion();
}
catch (ErrorMessage& err)
{
	err.addPath(L"BasicParser::getDictionaryMinor");
	throw err;
};

//====================================================================================================================
// Encode

void BasicParser::encode(BinaryOutput* buff, bool with_head, bool with_dictionary, bool with_body) throw(...)
{
	if (currentDictionary == 0)
		throw ErrorMessage(BASIC_PARSER_DICTIONARY_NOT_FOUND, L"Current dictionary not found", L"BasicParser::encode");

	BinaryCreator creator;

	if (with_dictionary && !with_body)
		creator.generate(buff, currentDictionary);

};

//====================================================================================================================
// Decode

void BasicParser::decode(const unsigned char* data, int data_size) throw(...)
try
{
	usdsInput.setBinary(data, data_size);
	
	unsigned char signature = usdsInput.readByte();
	switch (signature)
	{
	case '$':
		// Try to read Head and Dictionary
		readHeadfromBinary();
		break;
	case 'B':
		// Try to read Body
		if (currentDictionary == 0)
			throw ErrorMessage(BASIC_PARSER_DICTIONARY_NOT_FOUND, L"Dictionary not initialized");
		readBodyfromBinary();
		return;
	default:
		std::wstringstream msg;
		msg << L"Unexpected signature '" << signature << L"' at the start of the binary";
		throw ErrorMessage(BASIC_PARSER_UNKNOWN_FORMAT, &msg);
	}
	
	if (usdsInput.isEnd())
		return;

	signature = usdsInput.readByte();
	switch (signature)
	{
	case 'B':
		// Try to read Body
		if (currentDictionary == 0)
			throw ErrorMessage(BASIC_PARSER_DICTIONARY_NOT_FOUND, L"Dictionary not initialized");
		readBodyfromBinary();
		return;
	default:
		std::wstringstream msg;
		msg << L"Unexpected signature '" << signature << L"' at the binary";
		throw ErrorMessage(BASIC_PARSER_UNKNOWN_FORMAT, &msg);
	}

}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BasicParser::decode");
	throw msg;
};



//====================================================================================================================
void BasicParser::clear()
{
	currentDictionary = 0;
	dictionaries.clear();
	dictionaryPool.clear();

	usdsInput.clear();


};

void BasicParser::clearBody()
{

};


//====================================================================================================================
// private

Dictionary* BasicParser::findDictionary(int id, unsigned char major, unsigned char minor) throw(...)
{
	for (std::list<Dictionary*>::iterator it = dictionaries.begin(); it != dictionaries.end(); it++)
	{
		if ((*it)->getDictionaryID() == id && (*it)->getMajorVersion() == major && (*it)->getMinorVersion() == minor)
			return *it;
	}

	// if not found
	return 0;

};

//====================================================================================================================

void BasicParser::readHeadfromBinary() throw(...)
try
{
	// read full signature
	unsigned char head[3];
	usdsInput.readByteArray(head, 3);
	if (head[0] != 'S' || head[1] != usdsMajor || head[2] != usdsMinor)
		ErrorMessage(BASIC_PARSER_UNKNOWN_FORMAT, L"Unknown format of the binary");

	// read dictionary version
	int dict_id = usdsInput.readInt();
	unsigned char dict_major = usdsInput.readByte();
	unsigned char dict_minor = usdsInput.readByte();

	// Is next block a Dictionary or Body?
	unsigned char signature = usdsInput.readByte();

	if (findDictionary(dict_id, dict_major, dict_minor) == 0)
	{
		// try to read dictionary
		if (signature == 'D')
			readDictionaryfromBinary(dict_id, dict_major, dict_minor);
		else
		{
			std::wstringstream msg;
			msg << L"Unknown dictionary ID=" << dict_id << L" v." << int(dict_major) << L"." << int(dict_minor);
			throw ErrorMessage(BASIC_PARSER_DICTIONARY_NOT_FOUND, &msg);
		}
	}
	else
	{
		if (signature == 'D')
		{
			// skip dictionary
			size_t dict_size;
			usdsInput.readUVarint(&dict_size);
			usdsInput.stepForward(dict_size);
		}
		else
		{
			// return signature to the buffer
			usdsInput.stepBack(1);
		}
	}
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BasicParser::readHeadfromBinary");
	throw msg;
};

void BasicParser::readDictionaryfromBinary(int id, unsigned char major, unsigned char minor) throw(...)
try
{
	// read dictionary size
	size_t dict_size;
	usdsInput.readUVarint(&dict_size);
	if (dict_size == 0)
		throw ErrorMessage(BASIC_PARSER_DICTIONARY_NULL_SIZE, L"Dictionary size is null");

	const void* dict_buff = usdsInput.readByteArray(dict_size);

	Dictionary* dict = addNewDictionary(id, major, minor);
	//dict->initFromBinary(dict_buff, dict_size);
	
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BasicParser::readDictionaryfromBinary");
	throw msg;
};

void BasicParser::readBodyfromBinary() throw(...)
{


};