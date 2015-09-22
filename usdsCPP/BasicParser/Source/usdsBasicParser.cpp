#include "usdsBasicParser.h"

#include "converters\usdsDictionaryTextParser.h"
#include "converters\usdsDictionaryTextCreator.h"

using namespace usds;

BasicParser::BasicParser() : usdsMajor(1), usdsMinor(0)
{
	
}

BasicParser::~BasicParser()
{
	

}

//====================================================================================================================
// Settings
void BasicParser::getDictionaryVersion(unsigned char* major, unsigned char* minor) throw(...)
try
{
	*major = dictionariy.getMajorVersion();
	*minor = dictionariy.getMinorVersion();
}
catch (ErrorMessage& err)
{
	err.addPath(L"BasicParser::getDictionaryVersion");
	throw err;
};

int BasicParser::getDictionaryID() throw(...)
try
{
	return dictionariy.getDictionaryID();
}
catch (ErrorMessage& err)
{
	err.addPath(L"BasicParser::getDictionaryID");
	throw err;
};

//====================================================================================================================
// Dictionary constructors
void BasicParser::initDictionaryFromText(const char* text_dictionary, int size, usdsEncodes encode) throw(...)
try 
{
	DictionaryTextParser dictTextParser;
	dictTextParser.parse(text_dictionary, encode, &dictionariy);
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BasicParser::initDictionaryFromText");
	throw msg;
};

void BasicParser::getTextDictionary(usdsEncodes encode, std::string* text) throw(...)
try
{
	DictionaryTextCreator creator;
	creator.generate(encode, text, &dictionariy);
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BasicParser::getTextDictionary");
	throw msg;
};