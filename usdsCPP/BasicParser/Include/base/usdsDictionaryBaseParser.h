#ifndef USDS_DICTIONARY_BASE_PARSER
#define USDS_DICTIONARY_BASE_PARSER

namespace usds
{
	enum dictionaryTokens
	{
		NO_TOKEN = 0,
		DICTIONARY_ID = 1,
		DICTIONARY_MAJOR = 2,
		DICTIONARY_MINOR = 3


	};
	
	class DictionaryBaseParser
	{
	public:
		DictionaryBaseParser() {};
		virtual ~DictionaryBaseParser() {};

		virtual dictionaryTokens readFirstToken() throw(...) = 0;
		virtual dictionaryTokens readNextToken() throw(...) = 0;
		virtual void getTokenValue(int* value) throw(...) = 0;
		virtual void getTokenValue(unsigned char* value) throw(...) = 0;

	};



};

#endif