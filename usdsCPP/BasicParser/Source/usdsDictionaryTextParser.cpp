#include "base\usdsDictionaryTextParser.h"

using namespace usds;

DictionaryTextParser::DictionaryTextParser(const char* text, int size)
{
	dictionaryText = text;
	dictionarySize = size;

	currentPosition = text;
	lastToken = NO_TOKEN;
};

DictionaryTextParser::~DictionaryTextParser()
{
	
};

dictionaryTokens DictionaryTextParser::readFirstToken() throw(...)
try
{
	currentPosition = dictionaryText;
	lastToken = NO_TOKEN;

	return readNextToken();
}
catch (ErrorMessage& msg)
{
	msg.addMessage("DictionaryTextParser::readFirstToken");
	throw msg;
};

dictionaryTokens DictionaryTextParser::readNextToken() throw(...)
{
	switch (lastToken)
	{
		case NO_TOKEN:
			// try to read HEAD



			return DICTIONARY_ID;

		default:
			std::string mess("Unknown Token");
			throw ErrorMessage(DIC_TEXT_PARSER_UNKNOWN_TOKEN, &mess, "DictionaryTextParser::readNextToken");
	}
		
};

void DictionaryTextParser::getTokenValue(int* value) throw(...)
{



};