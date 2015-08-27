#ifndef USDS_TEXT_DICTIONARY
#define USDS_TEXT_DICTIONARY

#include "base\usdsErrors.h"
#include "base\usdsDictionaryBaseParser.h"

namespace usds
{
	class DictionaryTextParser : public DictionaryBaseParser
	{
	public:
		DictionaryTextParser(const char* text, int size);
		~DictionaryTextParser();

		dictionaryTokens readFirstToken() throw(...);
		dictionaryTokens readNextToken() throw(...);
		void getTokenValue(int* value) throw(...);
		void getTokenValue(unsigned char* value) throw(...);


	private:
		const char* dictionaryText;
		int dictionarySize;

		const char* currentPosition;
		dictionaryTokens lastToken;
			
	};

};
#endif