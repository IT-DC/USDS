#include "usdsBasicParser.h"

#include "converters\usdsDictionaryTextParser.h"
#include "converters\usdsDictionaryTextCreator.h"

using namespace usds;

BasicParser::BasicParser() : usdsMajor(1), usdsMinor(0)
{
	currentDictionary = 0;
	dictionaries.clear();
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
	
	object = dictionaryPool.addDictionary();
	object->setID(id, major, minor);
	dictionaries.push_back(object);
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

void BasicParser::clear()
{
	dictionaries.clear();
	currentDictionary = 0;
	dictionaryPool.clear();

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