#include "usdsBasicParser.h"

#include "converters\usdsDictionaryTextParser.h"
#include "converters\usdsDictionaryTextCreator.h"
#include "converters\usdsBinaryCreator.h"
#include "converters\usdsBinaryParser.h"

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

void BasicParser::decode(const unsigned char* data, size_t data_size) throw(...)
try
{
	BinaryParser parser(data, data_size);

	if (parser.isHeadIncluded())
	{
		int dict_id = parser.getDictionaryID();
		unsigned char dict_major = parser.getDictionaryMajor();
		unsigned char dict_minor = parser.getDictionaryMinor();
		Dictionary* dict = findDictionary(dict_id, dict_major, dict_minor);
		if (dict == 0)
		{
			if (!parser.isDictionaryIncluded())
			{
				std::wstringstream msg;
				msg << L"Dictionary ID=" << dict_id << L" v." << int(dict_major) << L"." << int(dict_minor) << L" not found";
				throw ErrorMessage(BASIC_PARSER_DICTIONARY_NOT_FOUND, &msg);
			}
			dict = addNewDictionary(dict_id, dict_major, dict_minor);
			parser.initDictionaryFromBinary(dict);
		}
		currentDictionary = dict;
	}
	
	if (parser.isBodyIncluded())
	{
		
		parser.initBodyFromBinary(currentDictionary);
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

