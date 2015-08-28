#include "base\usdsDictionaryTextParser.h"

using namespace usds;

DictionaryTextParser::DictionaryTextParser(const char* text, int size, usdsEncodes encode) throw(...)
{
	dictionaryText.clear();

	switch (encode)
	{
	case UTF8:
	{
		int dictionarySize = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS | MB_PRECOMPOSED, text, size, 0, 0);
		if (dictionarySize == 0)
		{
			std::wstringstream mess;
			mess << L"Can't convert Text Dictionary from UTF-8 to WCHAR, error code: " << GetLastError();
			throw ErrorMessage(DIC_TEXT_PARSER_CONVERT_ENCODE, &mess, L"DictionaryTextParser::DictionaryTextParser");
		};
		wchar_t* dictionary_buff = new wchar_t[dictionarySize];
		dictionarySize = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS | MB_PRECOMPOSED, text, size, dictionary_buff, dictionarySize);
		if (dictionarySize == 0)
		{
			std::wstringstream mess;
			mess << L"Can't convert Text Dictionary from UTF-8 to WCHAR, error code: " << GetLastError();
			throw ErrorMessage(DIC_TEXT_PARSER_CONVERT_ENCODE, &mess, L"DictionaryTextParser::DictionaryTextParser");
		};
		dictionaryText << dictionary_buff;
		delete[] dictionary_buff;
		break;
	}
	default:
		throw ErrorMessage(DIC_TEXT_PARSER_UNSUPPORTABLE_ENCODE, L"Unsupportable encode for dictionary", L"DictionaryTextParser::DictionaryTextParser");
	};
	
	lastToken = NO_TOKEN;
};

DictionaryTextParser::~DictionaryTextParser()
{
		
};

dictionaryTokens DictionaryTextParser::readFirstToken() throw(...)
try
{
	//currentPosition = dictionaryText;
	lastToken = NO_TOKEN;

	return readNextToken();
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"DictionaryTextParser::readFirstToken");
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
			throw ErrorMessage(DIC_TEXT_PARSER_UNKNOWN_TOKEN, L"Unknown Token", L"DictionaryTextParser::readNextToken");
	}
		
};

void DictionaryTextParser::getTokenValue(int* value) throw(...)
{



};