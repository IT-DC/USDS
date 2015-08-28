#ifndef USDS_TEXT_DICTIONARY
#define USDS_TEXT_DICTIONARY

#include "base\usdsErrors.h"
#include "base\usdsDictionaryBaseParser.h"

#include "tags\usdsTypes.h"

#include <Windows.h>

namespace usds
{
	class DictionaryTextParser : public DictionaryBaseParser
	{
	public:
		DictionaryTextParser(const char* text, int size, usdsEncodes encode) throw(...);
		~DictionaryTextParser();

		dictionaryTokens readFirstToken() throw(...);
		dictionaryTokens readNextToken() throw(...);
		void getTokenValue(int* value) throw(...);
		void getTokenValue(unsigned char* value) throw(...);


	private:
		std::wstringstream dictionaryText;

		dictionaryTokens lastToken;
			
	};

};
#endif