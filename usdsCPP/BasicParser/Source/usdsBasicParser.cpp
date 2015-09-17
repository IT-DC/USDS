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
// Settings
void BasicParser::setDictionaryVersion(unsigned char major, unsigned char minor) throw(...)
{
	if (currentDictionary == 0)
		throw ErrorMessage(BASIC_PARSER_NO_DICTIONARY, L"Dictionaries not found", L"BasicParser::setDictionaryVersion");
	
	for (std::list<Dictionary>::iterator it = dictionaries.begin(); it != dictionaries.end(); it++)
	{
		if (it->majorVersion == major && it->minorVersion == minor)
		{
			currentDictionary = &(*it);
			return;
		};
	};

	std::wstringstream err;
	err << L"Dictionary version" << major << L"." << minor << L" not found";
	throw ErrorMessage(BASIC_PARSER_DICTIONARY_NOT_FOUND, &err, L"BasicParser::setDictionaryVersion");
};

void BasicParser::getDictionaryVersion(int* major, int* minor)
{
	if (currentDictionary == 0)
		throw ErrorMessage(BASIC_PARSER_NO_DICTIONARY, L"Dictionaries not found", L"BasicParser::setDictionaryVersion");

	*major = currentDictionary->majorVersion;
	*minor = currentDictionary->minorVersion;
};

//====================================================================================================================
// Dictionary constructors

void BasicParser::initDictionaryFromText(const char* text_dictionary, int size, usdsEncodes encode) throw(...)
try 
{
	if (encode != UTF8)
		throw ErrorMessage(BASIC_PARSER_UNSUPPORTABLE_ENCODE, L"Unsupportable encode for text dictionary");
	
	DictionaryTextParser dictTextParser;
	dictTextParser.parse(text_dictionary, currentDictionary);
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BasicParser::initDictionaryFromText");
	throw msg;
};