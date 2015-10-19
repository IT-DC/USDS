#include "usdsBasicParser.h"

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
	dictionaryTextParser.parse(text_dictionary, encode, this);
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
	dictionaryTextcreator.generate(encode, text, currentDictionary);
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

	if (with_dictionary && !with_body)
		binaryCreator.generate(buff, currentDictionary);

};

//====================================================================================================================
// Decode

void BasicParser::decode(const unsigned char* data, size_t data_size) throw(...)
try
{
	binaryParser.setBinary(data, data_size);

	if (binaryParser.isHeadIncluded())
	{
		int dict_id = binaryParser.getDictionaryID();
		unsigned char dict_major = binaryParser.getDictionaryMajor();
		unsigned char dict_minor = binaryParser.getDictionaryMinor();
		if (currentDictionary == 0)
		{
			addNewDictionary(dict_id, dict_major, dict_minor);
			binaryParser.initDictionaryFromBinary(currentDictionary);
		}
		else
		{
			if (currentDictionary->getDictionaryID() != dict_id || currentDictionary->getMajorVersion() != dict_major || currentDictionary->getMinorVersion() != dict_minor)
			{
				Dictionary* dict = findDictionary(dict_id, dict_major, dict_minor);
				if (dict == 0)
				{
					if (!binaryParser.isDictionaryIncluded())
					{
						std::wstringstream msg;
						msg << L"Dictionary ID=" << dict_id << L" v." << int(dict_major) << L"." << int(dict_minor) << L" not found";
						throw ErrorMessage(BASIC_PARSER_DICTIONARY_NOT_FOUND, &msg);
					}
					addNewDictionary(dict_id, dict_major, dict_minor);
					binaryParser.initDictionaryFromBinary(currentDictionary);
				}
				else
				{
					currentDictionary = dict;
				}
			}
		}
	}
	
	if (binaryParser.isBodyIncluded())
	{
		
		binaryParser.initBodyFromBinary(currentDictionary);
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
	clearBody();

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

