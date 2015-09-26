#include "usdsBasicParser.h"

#include "converters\usdsDictionaryTextParser.h"
#include "converters\usdsDictionaryTextCreator.h"

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
	
	object = dictionaryPool.dictionaryPool.addObject();
	dictionaries.push_back(object);
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

void BasicParser::encode(bool with_head, bool with_dictionary, bool with_body) throw(...)
{
	clearBody();
	if (currentDictionary == 0)
		throw ErrorMessage(BASIC_PARSER_DICTIONARY_NOT_FOUND, L"Current dictionary not found", L"BasicParser::encode");

	if (with_dictionary)
	{
		addHeadToBinary();
		addDictionaryToBinary();
	}
	else
	{
		if (with_head)
			addHeadToBinary();
	}
	if (with_body)
		addBodyToBinary();

};

const unsigned char* BasicParser::getBinary(size_t* size) throw(...)
{
	const unsigned char* buff = usdsOutput.getBinary(size);
	return buff;
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
	usdsOutput.clear();

};

void BasicParser::clearBody()
{
	usdsInput.clear();
	usdsOutput.clear();
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

// Serialization
void BasicParser::addHeadToBinary() throw(...)
try
{
	if (currentDictionary == 0)
		throw ErrorMessage(BASIC_PARSER_DICTIONARY_NOT_FOUND, L"Current dictionary not found", L"BasicParser::addHeadToBinary");

	unsigned char head[] = { '$', 'S', usdsMajor, usdsMinor };
	usdsOutput.writeByteArray(head, 4);
	usdsOutput.writeInt(currentDictionary->getDictionaryID());
	usdsOutput.writeUByte(currentDictionary->getMajorVersion());
	usdsOutput.writeUByte(currentDictionary->getMinorVersion());
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BasicParser::addHeadToBinary");
	throw msg;
};

void BasicParser::addDictionaryToBinary() throw(...)
try
{
	size_t dict_size = 0;
	const unsigned char* dict_bin = currentDictionary->getBinary(&dict_size);
	usdsOutput.writeUByte('D'); // dictionary signature
	usdsOutput.writeUVarint(dict_size);
	usdsOutput.writeByteArray((void*)dict_bin, dict_size);

}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BasicParser::addDictionaryToBinary");
	throw msg;
};

void BasicParser::addBodyToBinary() throw(...)
{


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
			readDictionaryfromBinary();
		else
		{
			std::wstringstream msg;
			msg << L"Unknown dictionary ID=" << dict_id << L" v." << int(dict_major) << L"." << int(dict_minor);
			throw ErrorMessage(BASIC_PARSER_DICTIONARY_NOT_FOUND, &msg);
		}
	}



}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BasicParser::readHeadfromBinary");
	throw msg;
};

void BasicParser::readDictionaryfromBinary() throw(...)
{


};

void BasicParser::readBodyfromBinary() throw(...)
{


};